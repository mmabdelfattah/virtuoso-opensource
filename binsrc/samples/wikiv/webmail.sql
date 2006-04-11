--  
--  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
--  project.
--  
--  Copyright (C) 1998-2006 OpenLink Software
--  
--  This project is free software; you can redistribute it and/or modify it
--  under the terms of the GNU General Public License as published by the
--  Free Software Foundation; only version 2 of the License, dated June 1991.
--  
--  This program is distributed in the hope that it will be useful, but
--  WITHOUT ANY WARRANTY; without even the implied warranty of
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
--  General Public License for more details.
--  
--  You should have received a copy of the GNU General Public License along
--  with this program; if not, write to the Free Software Foundation, Inc.,
--  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
--  
--  
--$Id$

create procedure WV.WIKI.WEBMAILNEW ()
{
  declare inst wa_mail;
  declare ty varchar;
  for select WAT_TYPE from WA_TYPES where WAT_NAME = 'oMail'
  do  {
      inst := __udt_instantiate_class (fix_identifier_case (WAT_TYPE), 0);
      return inst;
    }
  return null;
}
;
  

create function WV.WIKI.MAILBOXNEW (in box_owner varchar, 
					       in box_name varchar, 
					       in domain_name varchar,
					       in wiki_page varchar) returns varchar
{
  declare e_mail varchar;
  e_mail := box_name || '@' || domain_name;
  dbg_obj_princ (box_owner);
  declare exit handler for sqlstate '*' {
    --dbg_obj_princ ('error: ', __SQL_STATE, __SQL_MESSAGE);
    return e_mail;
  }
  ;
  declare inst wa_mail;

  inst := WV.WIKI.WEBMAILNEW ();
  if (inst is null)
	return null;
  
  
  inst := inst.wa_name := e_mail;
  inst := inst.wa_member_model := 0; -- closed

  declare h, id any;
  h := udt_implements_method (inst, 'wa_new_inst');
  id := call (h) (inst, box_owner);
  --dbg_obj_princ ('3>', h, id, e_mail);

  update WA_INSTANCE
    set WAI_MEMBER_MODEL = 1,
      WAI_IS_PUBLIC = 0,
      WAI_MEMBERS_VISIBLE = 0,
      WAI_NAME = e_mail,
      WAI_DESCRIPTION = 'Autogenerated e-mail for Wiki page ' || wiki_page
    where
      WAI_ID = id;


  commit work;
  return e_mail;
}
;

create procedure WV.WIKI.MAILNAME (in cluster varchar, in topic varchar)
{
  return lcase (cluster || '.' || topic || '+' || cast ((100000000 + rand (899999999)) as varchar));
}
;

create procedure WV.WIKI.DEFAULTDOMAIN (in _cluster int)
{
  return WV.WIKI.CLUSTERPARAM (_cluster, 'webmail_domain', 'unset.null');
}
;

create function WV.WIKI.MAILBOX_OWNER (in _cluster varchar)
{
  return WV.WIKI.CLUSTERPARAM (_cluster, 'creator', 'Wiki');
}
;

create function WV.WIKI.MAILBOX_OWNER_BY_TOPIC (in _topic_id int)
{
  declare _cluster varchar;
  _cluster := (select ClusterName from  WV.WIKI.CLUSTERS natural join WV.WIKI.TOPIC
	where TopicId = _topic_id);
  return WV.WIKI.MAILBOX_OWNER (_cluster);
}
;
  

create procedure WV.WIKI.MAILBOXFORTOPICNEW (in topic_id int, in cluster_name varchar, in topic_name varchar)
{
  if (WV.WIKI.CLUSTERPARAM (cluster_name, 'webmail_enabled', 2) = 2)
    return null;  
  return  WV.WIKI.MAILBOXNEW ( WV.WIKI.CLUSTERPARAM (cluster_name, 'creator', 'Wiki'),
				      WV.WIKI.MAILNAME (cluster_name, topic_name),
				      WV.WIKI.DEFAULTDOMAIN (cluster_name),
				      cluster_name || '.' || topic_name);
}
;

create function WV.WIKI.MAILBOXLIST (in topic_id int) returns any
{
  declare exit handler for sqlstate '*' {
    -- dbg_obj_princ (__SQL_STATE, __SQL_MESSAGE);
    resignal;
  }
  ;
  declare _doc, _ent any;
  declare wiki_id int;
  declare cluster_owner, mail_box varchar;
  declare _cluster varchar;
  _cluster := connection_get ('WIKIV Cluster');
  cluster_owner := WV.WIKI.MAILBOX_OWNER (_cluster);
  wiki_id := (select u_id from DB.DBA.SYS_USERS where U_NAME = cluster_owner and U_IS_ROLE = 0);
  mail_box := (select MailBox from WV.WIKI.TOPIC where TopicId = topic_id);
  if (mail_box is null)
    return null;
  

  _doc := _ent := XMLELEMENT ('MailList');
  _ent := xpath_eval ('/MailList', _doc);
  XMLAppendChildren (_ent, XMLELEMENT ('InMail', mail_box));

  XMLAppendChildren (_ent, XMLELEMENT ('UserId', wiki_id));

  declare _mails any;
  _mails := OMAIL.WA.omail_msg_search(1, wiki_id, vector ('q', mail_box));
  if (_mails is not null)
    XMLAppendChildren (_ent, xtree_doc (_mails));
  return _doc;
}
;

create function WV.WIKI.MAIL_EXCERPT (in _user_id int, in _mail_id int)
{
  declare message any;	
  message := OMAIL.WA.omail_get_message (1, _user_id, _mail_id, 1);

  if (message is not null)
    return search_excerpt (vector (), get_keyword ('message', message));
  return '';
}
;


