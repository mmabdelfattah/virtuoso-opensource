--$Id$
registry_set ('WikiV %BR%',	'<BR />')
;
registry_set ('WikiV %YELLOW%',	'<FONT COLOR="#ffff00">')
;
registry_set ('WikiV %ORANGE%',	'<FONT COLOR="#ff6600">')
;
registry_set ('WikiV %RED%',	'<FONT COLOR="#ff0000">')
;
registry_set ('WikiV %PINK%',	'<FONT COLOR="#ff00ff">')
;
registry_set ('WikiV %PURPLE%',	'<FONT COLOR="#800080">')
;
registry_set ('WikiV %TEAL%',	'<FONT COLOR="#008080">')
;
registry_set ('WikiV %NAVY%',	'<FONT COLOR="#000080">')
;
registry_set ('WikiV %BLUE%',	'<FONT COLOR="#0000ff">')
;
registry_set ('WikiV %AQUA%',	'<FONT COLOR="#00ffff">')
;
registry_set ('WikiV %LIME%',	'<FONT COLOR="#00ff00">')
;
registry_set ('WikiV %GREEN%',	'<FONT COLOR="#008000">')
;
registry_set ('WikiV %OLIVE%',	'<FONT COLOR="#808000">')
;
registry_set ('WikiV %MAROON%',	'<FONT COLOR="#800000">')
;
registry_set ('WikiV %BLACK%',	'<FONT COLOR="#000000">')
;
registry_set ('WikiV %GRAY%',	'<FONT COLOR="#808080">')
;
registry_set ('WikiV %SILVER%',	'<FONT COLOR="#c0c0c0">')
;
registry_set ('WikiV %WHITE%',	'<FONT COLOR="#ffffff">')
;
registry_set ('WikiV %ENDCOLOR%',	'</FONT>')
;

registry_set ('WikiV %H%',	'<IMG SRC="%TEXTICONS%/help.gif" border="0" alt=HELP width="16" height="16" />')
;
registry_set ('WikiV %I%',	'<IMG SRC="%TEXTICONS%/tip.gif" border="0" alt="IDEA!" width="16" height="16" />')
;
registry_set ('WikiV %M%',	'<IMG SRC="%TEXTICONS%/arrowright.gif" border="0" alt="MOVED TO..." width="16" height="16" />')
;
registry_set ('WikiV %N%',	'<IMG SRC="%TEXTICONS%/new.gif" border="0" alt=NEW width="28" height="8" />')
;
registry_set ('WikiV %P%',	'<IMG SRC="%TEXTICONS%/pencil.gif" border="0" alt=REFACTOR width="16" height="16" />')
;
registry_set ('WikiV %Q%',	'<IMG SRC="%TEXTICONS%/help.gif" border="0" alt="QUESTION?" width="16" height="16" />')
;
registry_set ('WikiV %S%',	'<IMG SRC="%TEXTICONS%/starred.gif" border="0" alt=PICK width="16" height="16" />')
;
registry_set ('WikiV %T%',	'<IMG SRC="%TEXTICONS%/tip.gif" border="0" alt=TIP width="16" height="16" />')
;
registry_set ('WikiV %U%',	'<IMG SRC="%TEXTICONS%/updated.gif" border="0" alt=UPDATED width="56" height="8" />')
;
registry_set ('WikiV %X%',	'<IMG SRC="%TEXTICONS%/warning.gif" border="0" alt="ALERT!" width="16" height="16" />')
;
registry_set ('WikiV %Y%',	'<IMG SRC="%TEXTICONS%/choice-yes.gif" border="0" alt=DONE width="16" height="16" />')
;

registry_set ('WikiV %HOMETOPIC%',		'WelcomeVisitors')
;
registry_set ('WikiV %NOTIFYTOPIC%',		'RecentChanges')
;
registry_set ('WikiV %WIKIUSERSTOPIC%',		'WikiCommunity')
;
registry_set ('WikiV %STATISTICSTOPIC%',	'WikiStatistics')
;
registry_set ('WikiV %MAILTHISTOPIC%',		'<A HREF="mailto:?subject=%BASETOPIC%&body=%TOPICURL%">%MAILTHISTOPICTEXT%</A>')
;
registry_set ('WikiV %MAILTHISTOPICTEXT%',	'Send a link to this page')
;
registry_set ('WikiV %MAINCLUSTER%',		'Main')
;
registry_set ('WikiV %WIKICLUSTER%',		'Doc')
;
registry_set ('WikiV %MAINWEB%',		'%MAINCLUSTER%')
;
registry_set ('WikiV %WIKIWEB%',		'%WIKICLUSTER%')
;
registry_set ('WikiV %TWIKIWEB%',		'%WIKICLUSTER%')
;
registry_set ('WikiV %PUBURL%',			'.')
;
registry_set ('WikiV %PUBURLPATH%',		'')
;
registry_set ('WikiV %ATTACHURLPATH%',		'%TOPIC%')
;
registry_set ('WikiV %WIKITOOLNAME%',		'WikiV')
;
registry_set ('WikiV %WIKIVERSION%',		'0.3')
;
registry_set ('WikiV %WIKIUSERNAME%',		'%MAINWEB%.%WIKINAME%')
;

registry_set ('WikiV %TEXTICONS%',		'%PUBURL%/%WIKICLUSTER%/TextIcons')
;
registry_set ('WikiV %WIKIWEBMASTER%',		'you@yourdomain.com')
;
registry_set ('WikiV %WEBCOPYRIGHT%',		'&copy; contributing authors.')
;
registry_set ('WikiV %CATEGORY%', 'Category')
;
create function WV.WIKI.MACRO_MAIN_ABSTRACT (inout _data varchar, inout _context any, inout _env any)
{
  return _data;
}
;

create function WV.WIKI.MACRO_MAIN_TABLEOFCLUSTERS (inout _data varchar, inout _context any, inout _env any)
{
  declare _report any;
  declare _uid int;
  _uid := cast (get_keyword ('uid', _env, '0') as integer);
  _report := (
      select XMLELEMENT ("MACRO_MAIN_TABLEOFCLUSTERS",
        XMLAGG ( 
          XMLELEMENT ('Cluster',
	    XMLATTRIBUTES (c.ClusterName, c.Abstract) ) ) )
      from (
	select coalesce (n2.Abstract, N'') as Abstract, c2.ClusterName
	from 
	WV.WIKI.TOPIC as n2 inner join WV.WIKI.CLUSTERS as c2 
	  on (n2.ClusterId = c2.ClusterId)
	  inner join 
	   (select WAI_NAME, WAI_INST from DB.DBA.WA_INSTANCE where WAI_TYPE_NAME='oWiki' and WAI_IS_PUBLIC=1) W
	   on (n2.ClusterId = (W.WAI_INST as wa_wikiv).cluster_id)
	where 
	  n2.LocalName = WV.WIKI.CLUSTERPARAM (c2.ClusterName, 'index-page', 'WelcomeVisitors')
	union all 
	    select coalesce (n4.Abstract, N'') as Abstract, c4.ClusterName
	      from 
	        WV.WIKI.TOPIC as n4 inner join WV.WIKI.CLUSTERS as c4
	        on (n4.ClusterId = c4.ClusterId)
	        inner join 
		  (select WAI_NAME, WAI_INST from DB.DBA.WA_INSTANCE where WAI_TYPE_NAME='oWiki' and WAI_IS_PUBLIC=0) W2
		  on (n4.ClusterId = (W2.WAI_INST as wa_wikiv).cluster_id)
		  inner join WA_MEMBER 
		    on (W2.WAI_NAME = WAM_INST)
		  where WAM_USER = _uid and  n4.LocalName = WV.WIKI.CLUSTERPARAM (c4.ClusterName, 'index-page', 'WelcomeVisitors')
	) as c );
  return _report;
}
;

create function WV.WIKI.MACRO_MAIN_TABLEOFUSERS (inout _data varchar, inout _context any, inout _env any)
{
  declare _report any;
  _report := coalesce ((
      select XMLELEMENT ("MACRO_MAIN_TABLEOFUSERS",
        XMLAGG ( 
          XMLELEMENT ('User',
	    XMLATTRIBUTES (u.UserName) ) ) )
      from WV.WIKI.USERS as u ) );
  return _report;
}
;

create function WV.WIKI.META_TOPICMOVED (inout _data varchar, inout _context any, inout _env any)
{
  return '';
}
;

create function WV.WIKI.MACRO_META_FILEATTACHMENT (inout _data varchar, inout _context any, inout _env any)
{
  -- return XMLELEMENT('XMP', xtree_doc(concat ('<data ', _data, ' />')));
  return '';
}
;

create function WV.WIKI.MACRO_TOPIC (inout _data varchar, inout _context any, inout _env any)
{
  return get_keyword ('ti_local_name', _env, 'current');
}
;

create function WV.WIKI.MACRO_WEB (inout _data varchar, inout _context any, inout _env any)
{
  return get_keyword ('ti_cluster_name', _env, 'current');
}
;

create function WV.WIKI.MACRO_WIKIUSERNAME (inout _data varchar, inout _context any, inout _env any)
{
  declare _uid integer;
  _uid := cast (get_keyword ('uid', _env, '0') as integer);
  return coalesce ((select UserName from WV.WIKI.USERS where UserId = _uid), 'visitor');
  return _env;
}
;

create function WV.WIKI.MACRO_INCLUDE (inout _data varchar, inout _context any, inout _env any)
{
  declare _args any;
  _args := WV.WIKI.PARSEMACROARGS (_data);
  declare _topic_name varchar;
  _topic_name := WV.WIKI.GETMACROPARAM (_args, 'param', NULL);
  if (_topic_name is null)
    _topic_name := _data;
  _topic_name := WV.WIKI.EXPAND_SIMPLE_MACRO (trim(_topic_name));
  --dbg_obj_print (_topic_name, _data);
  declare _topic WV.WIKI.TOPICINFO;
  _topic := WV.WIKI.TOPICINFO ();
  _topic.ti_raw_title := _topic_name;
  _topic.ti_find_id_by_raw_title ();  
  if (_topic.ti_id = 0)
    return '';
  _topic.ti_find_metadata_by_id ();
  declare exit handler for sqlstate '*' {
    return NULL;
  }
  ;
  return (XMLELEMENT ('MACRO_INCLUDE',
   xpath_eval ('//div[@class=\'topic-text\']',
    WV.WIKI.VSPXSLT ( 'VspTopicView.xslt', _topic.ti_get_entity (null,1), 
	vector_concat (_env, _topic.ti_xslt_vector())))));
}
;

create function WV.WIKI.MACRO_CHANGELOG (inout _data varchar, inout _context any, inout _env any)
{
  declare _ent, params, _args any;
  declare _skip, _rows int;
  params := null;
  _args := WV.WIKI.PARSEMACROARGS (_data);

  _skip := atoi (WV.WIKI.GETMACROPARAM (_args, 'skip', '0'));
  _rows := atoi (WV.WIKI.GETMACROPARAM (_args, 'rows', '20'));
  if (WV.WIKI.GETMACROPARAM (_args, 'local', '0') = '1')
    _ent := WV.WIKI.CHANGELOG(_skip, _rows, get_keyword ('ti_cluster_name', _env, ''));
  else
    _ent := WV.WIKI.CHANGELOG(_skip, _rows);
  return WV.WIKI.VSPXSLT ('VspChangeLog.xslt', 
				_ent,
				params);
}
;


-- categories macros

create function WV.WIKI.MACRO_CATEGORIES (inout _data varchar, inout _context any, inout _env any)
{
  declare _cl_id int;
  _cl_id := cast (get_keyword ('ti_cluster_id', _env, 'current') as int);
  declare _user varchar;
  _user := WV.WIKI.CLUSTERPARAM (_cl_id , 'delicious_user', '');
    
  return (select XMLELEMENT ("MACRO_CATEGORIES",
     XMLELEMENT("table",
       XMLAGG(XMLELEMENT("tr",
               XMLELEMENT("td",	
		WV.WIKI.A(c.ClusterName || '.' || t.LocalName, c.ClusterName || '.' || t.LocalName, 'wikiword'))))))
	from WV.WIKI.TOPIC t inner join WV.WIKI.CLUSTERS c on (c.ClusterId = t.ClusterId) 
	  where c.ClusterId = _cl_id and LocalName like 'Category%'
	  order by LocalName);
}
;

create function WV.WIKI.DELICIOUSMAKECONT (in _doc any, in _params any)
{
  return '';
}
;
  

create function WV.WIKI.MACRO_DELICIOUSCATEGORIES (inout _data varchar, inout _context any, inout _env any)
{
  return '';
}
;

-- dash board

create function WV.WIKI.MACRO_MAIN_DASHBOARD (inout _data varchar, inout _context any, inout _env any)
{
  declare _report any;
  _report := (
      select XMLELEMENT ("MACRO_MAIN_DASHBOARD",
         XMLAGG(
            XMLELEMENT ('Cluster',
                      XMLATTRIBUTES (cl_name as "Key"),
                      XMLELEMENT (Name,
                        case
                          when (instance is null)
                          then
                            cl_name
                          else
                            (instance as wa_wikiv).wa_name
                        end),
                      XMLELEMENT ('Description', name ) ) ) )
      from 
        (select c.ClusterName as cl_name, WAI_INST as instance, WAI_NAME as name
	  from WV.WIKI.CLUSTERS c INNER JOIN
	    (select WAI_INST, WAI_NAME from WA_INSTANCE where WAI_TYPE_NAME = 'oWiki') inst
          on ((inst.WAI_INST as wa_wikiv).cluster_id = c.ClusterId) ) a );
  return _report;
}
;

create function WV.WIKI.MACRO_CLUSTER_NAME (inout _data varchar, inout _context any, inout _env any)
{
  declare _cl_id int;
  _cl_id := cast (get_keyword ('ti_cluster_id', _env, 'current') as int);
  return coalesce ((select WAI_NAME from (select WAI_NAME, WAI_INST from WA_INSTANCE where WAI_TYPE_NAME = 'oWiki') a where (a.WAI_INST as wa_wikiv).cluster_id = _cl_id),
		   'default main area');
}
;

create function WV.WIKI.MACRO_CLUSTER_DESCRIPTION (inout _data varchar, inout _context any, inout _env any)
{
  declare _cl_id int;
  _cl_id := cast (get_keyword ('ti_cluster_id', _env, 'current') as int);
  return coalesce ((select WAI_DESCRIPTION from (select WAI_DESCRIPTION, WAI_INST from WA_INSTANCE where WAI_TYPE_NAME = 'oWiki') a where (a.WAI_INST as wa_wikiv).cluster_id = _cl_id),
		   'default main area');
}
;

create function WV.WIKI.MACRO_CLUSTER_OWNER (inout _data varchar, inout _context any, inout _env any)
{
  declare _col_id int;
  _col_id := cast (get_keyword ('ti_col_id', _env, 'current') as int);
  return (select concat (U_NAME, ' (', UserName, ')') from WS.WS.SYS_DAV_COL, WV.WIKI.USERS, DB.DBA.SYS_USERS
	  where COL_ID = _col_id
	  and COL_OWNER = U_ID
	  and COL_OWNER = UserId);
}
;

create function WV.WIKI.MACRO_CLUSTER_MEMBERS (inout _data varchar, inout _context any, inout _env any)
{
  declare _cl_id int;
  declare _inst_name varchar;
  _cl_id := cast (get_keyword ('ti_cluster_id', _env, 'current') as int);
  _inst_name := (select WAI_NAME  from (select WAI_NAME, WAI_INST from WA_INSTANCE where WAI_TYPE_NAME = 'oWiki') a where (a.WAI_INST as wa_wikiv).cluster_id = _cl_id);
  return (
      select XMLELEMENT ("MACRO_CLUSTER_MEMBERS",
	 XMLAGG(			
            XMLELEMENT ("div",
			U_NAME)))
      from  WA_MEMBER, DB.DBA.SYS_USERS
        where WAM_INST = _inst_name
      and U_ID = WAM_USER);
}
;

create function WV.WIKI.MACRO_RSS_FEED (inout _data varchar, inout _context any, inout _env any)
{
  return WV.WIKI.MACRO_FEED_RSS (_data, _context, _env);
}
;

create function WV.WIKI.MACRO_ATOM_FEED (inout _data varchar, inout _context any, inout _env any)
{
  return WV.WIKI.MACRO_FEED_ATOM (_data, _context, _env);
}
;


create function WV.WIKI.MACRO_FEED_RSS (inout _data varchar, inout _context any, inout _env any)
{
  return WV.WIKI.FEED (_env, _data, 'rss20', 'rss20.gif');
}
;

create function WV.WIKI.MACRO_FEED_ATOM (inout _data varchar, inout _context any, inout _env any)
{
  return WV.WIKI.FEED (_env, _data, 'atom', 'atom03.gif');
}
;


create function WV.WIKI.FEED (inout _env any, inout _data varchar, in _type varchar, in _icon varchar)
{
  declare cluster_name varchar;
  declare _home varchar;
  cluster_name := get_keyword ('ti_cluster_name', _env, 'current');
  declare _content, _search_area varchar;
  declare _args varchar;
  _args := WV.WIKI.PARSEMACROARGS (_data);
  _content := WV.WIKI.GETMACROPARAM (_args, 'content', _type || ' feed');
  _search_area := WV.WIKI.GETMACROPARAM (_args, 'area', 'cluster');

  declare _base_adjust varchar;
  _base_adjust := coalesce (connection_get ('WIKIV BaseAdjust'), '');
  _home := _base_adjust || '../resources/';
  


  return XMLELEMENT ('div',
		     XMLATTRIBUTES ('MACRO_' || ucase (_type) || '_FEED_LINK' as "class"),
		     XMLELEMENT ('img',
			 	 XMLATTRIBUTES (_home || 'images/' || _icon as "src")),
		     XMLELEMENT ('a', 
				 XMLATTRIBUTES (_home || 'gems.vsp?type=' || _type || 
					case when _search_area = 'cluster' then '&cluster=' || cluster_name
					     else '' end
 				        as "href"),
				 _content));
}
;

create function WV.WIKI.MACRO_HIT_COUNTER (inout _data varchar, inout _context any, inout _env any)
{
  declare _topic_id int;
  _topic_id := cast (get_keyword ('ti_id', _env, -1) as int);
  return XMLELEMENT ('MACRO_HIT_COUNTER', 
    coalesce ( (select Cnt from WV.WIKI.HITCOUNTER where TopicId = _topic_id), 0 ));
}
;

create trigger "HitCounter_Delete" after delete on WV.WIKI.TOPIC referencing old as O
{
  delete from WV.WIKI.HITCOUNTER where TopicId = O.TopicId;
}
;

create function WV.WIKI.STRJOIN (in _del varchar,
  in _words any)
{
  declare idx int;
  declare ss any;
  if (length (_words) = 0)
    return '';
  ss := string_output();
  for (idx :=0; idx < (length (_words) - 1); idx:=idx+1)
    {
      http (cast (_words[idx] as varchar), ss);
      http (cast (_del as varchar), ss);
    }
  http (cast (_words[idx] as varchar), ss);
  return string_output_string (ss);
}
;

create function WV.WIKI.ZIP (in _v1 any, in _v2 any)
{
  declare res any;
  vectorbld_init(res);
  declare i int;
  declare len int;
  if (isarray(_v1) and (not isstring (_v1)))
    {
      len := case when length (_v1) < length(_v2) then length (_v1) else length (_v2) end;
      for (i:=0; i < len; i:=i+1)
        vectorbld_acc (res, vector (_v1[i], _v2[i]));
    }
  else
    {
      len := length (_v2);
      for (i:=0;i < len; i:=i+1)
        vectorbld_acc (res, vector (_v1, _v2[i]));
    }	
  vectorbld_final (res);
  return res;
}
;

create function WV.WIKI.FLATTEN (in _v any)
{
  if (not isarray (_v))
    return _v;
  declare _res any;
  _res := vector();
  foreach (any item in _v) do 
    {
      if (isarray (item) and (not isstring (item)))
        _res := vector_concat (_res, WV.WIKI.FLATTEN (item));
      else
        _res := vector_concat (_res, vector (item));
    }
  return _res;
}
;

create function WV.WIKI.MAP (in funcname varchar, in v any, in result_type varchar:='vector')
{
  if (not isarray (v))
    signal ('WV700', 'WV.WIKI.MAP needs vector as first argument');
  if (not __proc_exists (funcname))
    signal ('WV701', 'WV.WIKI.MAP needs name of existing procedure as second argument');
  declare res any;
  if (result_type = 'vector')
  vectorbld_init(res);
  declare idx int;
  for (idx:=0; idx < length (v); idx:=idx+1)
    {
      if (result_type = 'vector')
	vectorbld_acc (res, call (funcname)(v[idx]));
      else
	call (funcname) (v[idx]);
    }
  vectorbld_final(res);
  return res;
}
;
  
      

create function WV.WIKI.MACRO_SEARCH (inout _data varchar, inout _context any, inout _env any)
{
  declare cluster, search_word varchar;
  declare _res varchar; 
  declare _args any;
  declare _cluster_col_id int;
  declare sid, realm varchar;
  _data := WV.WIKI.EXPAND_SIMPLE_MACRO (_data);
  _args := WV.WIKI.PARSEMACROARGS (_data);
  search_word := WV.WIKI.GETMACROPARAM (_args, 'search', NULL);
  if (search_word is null)
    {
      search_word := WV.WIKI.GETMACROPARAM (_args, 'param', NULL);
      if (search_word is not null)
        {
	  declare swords any;
	  swords := split_and_decode (search_word, 0, '\0\0;');
	  search_word := WV.WIKI.STRJOIN (' OR ', swords);
	}
    }
  sid := WV.WIKI.GETMACROPARAM (_args, 'sid', NULL);
  realm := WV.WIKI.GETMACROPARAM (_args, 'realm', NULL);
  cluster := WV.WIKI.GETMACROPARAM (_args, 'cluster');
  --dbg_obj_princ ('Search: ', _args);
  if (cluster is not null)
    {
      _cluster_col_id := (select ColId from WV.WIKI.CLUSTERS where ClusterId = cluster);
      if (_cluster_col_id IS NULL)
        cluster := NULL;
    }
  if (search_word <> '')
    {
      declare exp1,exp varchar;
      declare hit_words, vt, war any;
      declare n,m int;

      exp1 := trim (search_word);
      exp := exp1;
      hit_words := vector();
      vt := vt_batch ();
      vt_batch_feed (vt, exp, 0, 0, 'x-ViDoc');
      war := vt_batch_strings_array (vt);
      m := length (war);
      n := 0;
      while (n < m)
        {
	  declare word1 varchar;
	  if (war[n] <> 'AND' and war[n] <> 'NOT' and war[n] <> 'NEAR' and war[n] <> 'OR' and length (war[n]) > 1 and not vt_is_noise (war[n], 'utf-8', 'x-ViDoc'))
	    {
	      word1 := war[n];
	      hit_words := vector_concat (hit_words, vector (word1));
	    }
	  n := n + 2;
	}
end_parse:
      declare site_cr cursor for select RES_ID, U_NAME, RES_NAME, length (RES_CONTENT) as RES_LEN, WV.WIKI.DATEFORMAT(RES_CR_TIME) as RES_CR_TIME_STR,RES_PERMS, RES_FULL_PATH
                            from WS.WS.SYS_DAV_RES, DB.DBA.SYS_USERS
                            where
                             contains (RES_CONTENT, concat ('[__lang ''x-ViDoc''] ',exp1))
                             and RES_FULL_PATH like '/DAV/VAD/wiki/%.txt'
			     and U_ID = RES_OWNER;
      declare cluster_cr cursor for select RES_ID, U_NAME, RES_NAME, length (RES_CONTENT) as RES_LEN, WV.WIKI.DATEFORMAT(RES_CR_TIME) as RES_CR_TIME_STR,RES_PERMS, RES_FULL_PATH
                            from WS.WS.SYS_DAV_RES, DB.DBA.SYS_USERS
                            where
                             contains (RES_CONTENT, concat ('[__lang ''x-ViDoc''] ',exp1))
                             and RES_FULL_PATH like '/DAV/VAD/wiki/%.txt'
			     and U_ID = RES_OWNER
			     and RES_COL = _cluster_col_id;
whenever sqlstate '37000' goto failed;
	declare _ctx, _idx any;
	_ctx := string_output ();
	_idx := 0;
	declare _res_id, _u_name, _res_name, _res_len, _cr_time, _perms, _full_path any;
	declare _cluster_search int;
	_cluster_search := case when cluster is not null then 1 else 0 end;
	if (_cluster_search = 1)
	  open cluster_cr;
	else
	  open site_cr;
	whenever not found goto endf;
	http ('<div><![CDATA[Search result for "' || exp1 || '":]]></div> <table class="wikitable"><tr>
			<th align="left" width="20%">Name</th>
			<th align="left" width="10%">Size</th>
			<th align="left" width="10%">Owner</th>
			<th align="left" width="10%">Date</th></tr>', _ctx);
 	while (1=1) {
	  if (_cluster_search = 1)
		fetch cluster_cr into _res_id, _u_name, _res_name, _res_len, _cr_time, _perms, _full_path;
	  else
		fetch site_cr into _res_id, _u_name, _res_name, _res_len, _cr_time, _perms, _full_path;
	  _idx := _idx + 1;
	  http ('<tr>
			<td align="left" width="20%">' || WV.WIKI.MAKEHREFFROMRES (_res_id, _res_name, sid, realm) || '</td>
			<td align="left" width="10%">' || WV.WIKI.PRINTLENGTH(_res_len) || '</td>
			<td align="left" width="10%">' || _u_name || '</td>
			<td align="left" width="10%">' || _cr_time || '</td></tr>', _ctx);
	  http ('<tr><td colspan="4">', _ctx);
	  http (coalesce (search_excerpt (hit_words,  blob_to_string ( (select RES_CONTENT from WS.WS.SYS_DAV_RES where RES_ID = _res_id ) ), 200000, 90, 200, 'b', 1), ''), _ctx);
	  http ('</td></tr>', _ctx);

	}
endf:
	if (_cluster_search = 1)
	  close cluster_cr;
	else
	  close site_cr;
	http ('</table>', _ctx);
   	if (_idx = 0) {
	failed:
		_res := '<div class="error"><![CDATA[No articles found for "' || exp1 || '"]]></div>';
	}
	if (_idx <> 0)
		_res :=  string_output_string (_ctx);
   }
   return XMLELEMENT ('MACRO_SEARCH', xtree_doc (_res));
}
;


create function WV.WIKI.MACRO_TOC  (inout _data varchar, inout _context any, inout _env any)
{
  declare _xml_doc any;
  declare _cluster_name varchar;
  _cluster_name := get_keyword ('ti_cluster_name', _env, 'Main');
  _xml_doc :=  xtree_doc("WikiV lexer" (get_keyword ('ti_text', _env, '') || '\r\n', 
	_cluster_name,
	get_keyword ('ti_local_name', _env, WV.WIKI.CLUSTERPARAM (_cluster_name, 'index-page', 'WelcomeVisitors')),
	get_keyword ('ti_curuser_wikiname', _env, 'WikiGuest'),
	null), 2);

  return xquery_eval ('
<div class="MACRO_TOC" xmlns:wv="http://www.openlinksw.com/Virtuoso/WikiV/">
 <div class="wikitoc">
  <ul>
  {
    for \$t in //h1 | //h2 | //h3 | //h4 | //h5 | //h6
    return
	<li> { for \044nb in wv:nnbsps(\$t/local-name())//y return <span width="10%">.</span> } <img src="{\044baseadjust}../resources/images/d.gif"/> <a href="#{wv:trim(\$t/text())}"> { \$t/text() } </a>  </li>
  }
  </ul>
 </div>
</div>', _xml_doc, 1, vector('baseadjust', connection_get ('WIKIV BaseAdjust')));
	
}
;


create function WV.WIKI.NNBSPS (in header_class varchar)
{
  declare n, i int;
  n := cast (subseq (header_class, 1) as int);

  declare ss any;
  ss := string_output();
  http ('<x>',ss);
  for ( i:=0 ; i < 2*n ; i := i+1)
    {
      http ('<y/>', ss);
    }
  http ('</x>', ss);
  return xtree_doc (string_output_string (ss), 2);
}
;

grant execute on WV.WIKI.NNBSPS to public
;

xpf_extension ('http://www.openlinksw.com/Virtuoso/WikiV/:nnbsps', 'WV.WIKI.NNBSPS')
;


create function WV.WIKI.TRIM (in str varchar)
{
  return trim (str, ' \t\n\r');
}
;

grant execute on WV.WIKI.TRIM to public
;

xpf_extension ('http://www.openlinksw.com/Virtuoso/WikiV/:trim', 'WV.WIKI.TRIM')
;


create function WV.WIKI.MACRO_META_TOPICPARENT (inout _data varchar, inout _context any, inout _env any)
{
  if (get_keyword ('is_new', _env, NULL) is not null)
    return '((will be processed later))';
  declare _args any;
  declare _name, _signal varchar;
  _args := WV.WIKI.PARSEMACROARGS (_data);
  _name := WV.WIKI.GETMACROPARAM (_args, 'name', NULL);
  _signal := WV.WIKI.GETMACROPARAM (_args, 'signal', '0');
  declare _parent int;
  declare _cluster int;
  declare _topic int;

  _cluster := get_keyword ('ti_cluster_id', _env, NULL);
  _topic := get_keyword ('ti_id', _env, NULL);

  if (_name is null)
    {
      if (exists (select * from WV.WIKI.TOPIC where TopicId = _topic
			and ClusterId = _cluster
			and ParentId <> 0))
 	update WV.WIKI.TOPIC set ParentId = 0
		where TopicId = _topic
		and ClusterId = _cluster;
      return '';
    }
		

  _parent := (select TopicId from WV.WIKI.TOPIC where LocalName = _name and ClusterId = _cluster);
  if (_parent is null)
    {
      if (lcase (_signal) = 't')
        signal ('WV100', 'META:TOPICPARENT needs valid topic name as "name" argument');
      else
        return '';
    }
  if (exists (select * from WV.WIKI.TOPIC 
	where TopicId = _topic
	and ClusterId = _cluster
	and ParentId = _parent))
    return '';
  
  update WV.WIKI.TOPIC set ParentId = _parent 
	where TopicId = _topic
	and ClusterId = _cluster;
  return '';

}
;

create function WV.WIKI.MACRO_META_TOPICINFO (inout _data varchar, inout _context any, inout _env any)
{
  if (get_keyword ('import', _env, NULL) is null)
    return '';
  if (connection_get ('WikiV macro TOPICINFO') is not null)
    return '';
  connection_set ('WikiV macro TOPICINFO', 1);
  declare _args any;
  declare _name varchar;
  declare _crdt int;
  _args := WV.WIKI.PARSEMACROARGS (_data);
  _name := WV.WIKI.GETMACROPARAM (_args, 'author', NULL);
  _crdt := atoi (WV.WIKI.GETMACROPARAM (_args, 'date', '0'));
  declare _uid int;
  declare _cluster int;
  declare _topic, _res_id int;

  _cluster := get_keyword ('ti_cluster_id', _env, NULL);
  _topic := get_keyword ('ti_id', _env, NULL);
  _res_id := get_keyword ('ti_res_id', _env, NULL);

  if (_name is null)
    return '';
  _name := trim (_name);

  if (length (_name) = 0)
    signal ('WV100', 'META:TOPICINFO needs valid user name as "author" argument');

  update WV.WIKI.TOPIC set AuthorName = _name
	where TopicId = _topic
	and ClusterId = _cluster;
  set triggers off;
  update WS.WS.SYS_DAV_RES set RES_MOD_TIME = dateadd ('second', _crdt,  stringdate ('1970.01.01'))
  	where RES_ID = _res_id;
  set triggers on;
  
  return '';

}
;

create function WV.WIKI.EXPAND_SIMPLE_MACRO (in _str varchar)
{
  return "WikiV macroexpander" (_str, 'test', 'test2', 'test3', null);
}
;

create function WV.WIKI.MACRO_REFBY (inout _data varchar, inout _context any, inout _env any)
{
  declare _topic_id int;
  _topic_id := get_keyword ('ti_id', _env, null);
  if (_topic_id is null)
    return '';
  declare _ent any;

  _ent := XMLELEMENT ('MACRO_REF_BY',
   	   (select XMLELEMENT ('ul',
	     XMLAGG (
	     	XMLELEMENT ('li',
		  XMLELEMENT ('a', 
		    XMLATTRIBUTES (ClusterName || '.' || LocalName as "href",
		    		   'wikiword' as "style"),
		    ClusterName || '.' || LocalName ) ) ) )
		    from WV.WIKI.LINK inner join WV.WIKI.TOPIC 
		     on (OrigId = TopicId)
		     natural join WV.WIKI.CLUSTERS
		    where DestId = _topic_id));
  return _ent;
}
;

create function WV.WIKI.MACRO_CATEGORY (inout _data varchar, inout _context any, inout _env any)
{
  return 'Category';
}
;
  

create function WV.WIKI.EXPAND_WIKI_TEXT (in _text varchar, in _env any)
{
  declare _entity any;
  _entity := xtree_doc (
    "WikiV lexer" (_text || '\r\n',
      get_keyword ('ti_cluster_name', _env),
      get_keyword ('ti_local_name', _env),
      get_keyword ('ti_curuser_wikiname', _env),
      NULL), 2);
  return  xpath_eval ('//div[@class=\'topic-text\']',
    WV.WIKI.VSPXSLT ( 'VspTopicView.xslt',_entity, _env));
}
;

grant execute on WV.WIKI.EXPAND_WIKI_TEXT to public
;

xpf_extension ('http://www.openlinksw.com/Virtuoso/WikiV/:expandWikiText', 'WV.WIKI.EXPAND_WIKI_TEXT')
;

create function WV.WIKI.MACRO_COMMENTS (inout _data varchar, inout _context any, inout _env any)
{
 declare sid, realm varchar;
 sid := get_keyword ('sid', _env, '');
 realm := get_keyword ('realm', _env, '');
 declare _pwd varchar;
 select PWD_MAGIC_CALC (U_NAME, U_PASSWORD) into _pwd from DB.DBA.SYS_USERS 
   where U_NAME = get_keyword ('user', _env, 'WikiGuest');
 declare _write_is_allowed int;
 if (DAV_HIDE_ERROR (DAV_AUTHENTICATE (cast (get_keyword ('ti_res_id', _env) as int), 'R', '_1_', get_keyword ('user', _env), _pwd)) is not null)
   _write_is_allowed := 1;
 else
   _write_is_allowed := 0;
   
 declare params varchar;
 params := coalesce (connection_get ('WIKI params'), vector ()); 
 declare _comment, _op varchar;
 _comment := trim (get_keyword ('comment', params));  
 _op := trim (get_keyword ('CommentPost', params));
 
 declare _topic_id int;
 _topic_id := atoi (get_keyword ('ti_id', _env));
 if (_op = 'Post' and _comment is not null and _comment <> '')
   {
     insert into WV.WIKI.COMMENT (C_TOPIC_ID,C_AUTHOR,C_EMAIL,C_TEXT,C_DATE)
       values (
         _topic_id,
	 get_keyword ('author', params),
	 get_keyword ('email', params),
	 _comment,
	 now());
     signal ('WVRLD', 'selected=talks'); 
    }
  else if (_op = 'Delete')
    {
      declare _id int;
      _id :=  trim (get_keyword ('CommentId', params));
      delete from WV.WIKI.COMMENT 
        where C_TOPIC_ID = _topic_id
	and C_ID = _id;
    }
  declare _user_comments any;
  _user_comments := (select XMLELEMENT ('COMMENTS',
    XMLAGG(
     XMLELEMENT('COMMENT',
      XMLATTRIBUTES(
        C_AUTHOR as "author",
	C_ID as "id",
	C_EMAIL as "email",
	WV.WIKI.DATEFORMAT(C_DATE) as "date"),
      C_TEXT)))
    from WV.WIKI.COMMENT where C_TOPIC_ID = _topic_id order by C_DATE);
  declare _user, _email varchar;
  _user := get_keyword ('user', _env, 'WikiGuest');
  _email := coalesce ((select U_E_MAIL from DB.DBA.SYS_USERS where U_NAME = _user), '');
  
  declare _xquery_script varchar;
  _xquery_script := 
'<div xmlns:wv="http://www.openlinksw.com/Virtuoso/WikiV/">
  <table>   
  { 
    for \044comment in //COMMENT
    return 
      <tr>
       <td id="wiki{\044comment/@id/string()}">
         <table width="100%" class="wikitable">
	  <tr>
	   <td colspan="3">
	    { wv:expandWikiText(\044comment/text(), \044env) }
	   </td>
	  </tr>
	  <tr>
	   <th> <a href="{\044comment/@author/string()}" style="wikiword">{\044comment/@author/string()}</a></th>
	   <th> { \044comment/@email/string() } </th>
	   <th> { \044comment/@date/string() } </th>
	  </tr>
	  {
	    if (\044write_is_allowed) 
	    then
	      <tr> 
	        <th colspan="3">
		  <form method="POST">
		    <input name="sid" type="hidden" value="{\044sid}"/>
		    <input name="realm" type="hidden" value="{\044realm}"/>
		    <input name="topic" type="hidden" value="{\044ti_cluster_name}.{\044ti_local_name}"/>
		    <input name="CommentId" type="hidden" value="{\044comment/@id/string()}"/>
		    <input name="CommentPost" type="submit" value="Delete"/>
		  </form>
	        </th> 
	      </tr>
	    else
	      <tr/>
	  }
	</table>
       </td>
      </tr>
  }
  </table>
  Post your comment:
  <table class="wikitable">
   <form method="POST" action="{concat (\044baseadjust, ''../main/'', wv:ReadOnlyWikiWordLink (\044ti_cluster_name, \044ti_local_name))}">
   <input name="sid" type="hidden" value="{\044sid}"/>
   <input name="realm" type="hidden" value="{\044realm}"/>
   <input name="selected" type="hidden" value="talks"/>
   <tr>
    <th>Author</th>
    <td><input name="author" type="text" value="{\044auth}" size="100%"/></td>
   </tr>
   <tr>
    <th>e-mail</th>
    <td><input name="email" type="text" value="{\044email}" size="100%"/></td>
   </tr>
   <tr>
    <td colspan="2">
      <textarea name="comment" rows="6" cols="80"/>  
    </td>
   </tr>
   <tr>
    <td colspan="2">
     <input type="submit" name="CommentPost" value="Post"/>
    </td>
   </tr>
   </form>
  </table>
 </div>';
  
  return xquery_eval(_xquery_script, _user_comments, 1,
  vector_concat (_env,
   vector (
   	'write_is_allowed', _write_is_allowed,
    	'env', _env,
   	'auth', _user,
	'email', _email,
	-- when sid and realm are not specified
	'sid', sid,
	'realm', realm)));
}
;
   
create function WV.WIKI.MACRO_TECHNORATI_COSMOS (inout _data varchar, inout _context any, inout _env any)
{
  declare api_key varchar;
  api_key := WV.WIKI.CLUSTERPARAM (get_keyword ('ti_cluster_name', _env),
  	'technorati_api_key', NULL);
  if (api_key is null)
    return '((API Key is not set))';
  declare _args any;
  _args := WV.WIKI.PARSEMACROARGS (_data);
  declare url, api_url varchar;
  url := trim (WV.WIKI.GETMACROPARAM (_args, 'param', NULL));
  api_url := sprintf ('http://api.technorati.com/cosmos?key=%V&url=%V', api_key, url);
  
  declare _doc varchar;
  _doc := http_get (api_url);
  --dbg_obj_print (api_url, _doc);
  

  return xquery_eval (
  '<div class="macro-technorati-cosmos">
   <table class="wikitable">
    { 
      for \044item in //item 
      return
        <tr>
	  <th> <a href="{\044item//url}">{ \044item//name/text() }</a> </th>
	  <td> { \044item//excerpt/text() } <br/>
	    { for \044link in \044item//nearestpermalink/text()
	        where \044link != ""
	        return <a href="{\044link}">Permanent Link</a>
	    }
	  </td>
	</tr>
    }
   </table>
   </div>'
   , xtree_doc (_doc, 2));
}
;

create function WV.WIKI.MACRO_TECHNORATI_TAG (inout _data varchar, inout _context any, inout _env any)
{
  declare api_key varchar;
  api_key := WV.WIKI.CLUSTERPARAM (get_keyword ('ti_cluster_name', _env),
  	'technorati_api_key', NULL);
  if (api_key is null)
    return '((API Key is not set))';
  declare _args any;
  _args := WV.WIKI.PARSEMACROARGS (_data);
  declare tag, api_url varchar;
  tag := trim (WV.WIKI.GETMACROPARAM (_args, 'param', NULL));
  api_url := sprintf ('http://api.technorati.com/tag?key=%V&tag=%V', api_key, tag);
  
  declare _doc varchar;
  _doc := http_get (api_url);
  --dbg_obj_print (api_url, _doc);
  

  return xquery_eval (
  '<div class="macro-technorati-tag">
   <table class="wikitable">
    { 
      for \044item in //item 
      return
        <tr>
	  <th> 
	    {
	      for \044img in \044item//thumbnailpicture/text()
	        where \044img != ""
		return
		  <img src="{\044img}"/>
	    }	  
	    <a href="{\044item//url}">{ \044item//name/text() }</a></th>
	  <td> <b> { \044item//title/text() }. </b> 
	    { \044item//excerpt/text() } <br/>
	    { for \044link in \044item//permalink/text()
	        where \044link != ""
	        return <a href="{\044link}">Permanent Link</a>
	    }
	  </td>
	</tr>
    }
   </table>
   </div>'
   , xtree_doc (_doc, 2));
}
;


create function WV.WIKI.MACRO_UNUSEDPAGES (inout _data varchar, inout _context any, inout _env any)
{
  declare _args any;
  _args := WV.WIKI.PARSEMACROARGS (_data);
  declare _cluster_name varchar;
  _cluster_name := WV.WIKI.GETMACROPARAM (_args, 'param', get_keyword ('ti_cluster_name', _env));
  
  declare _index_page varchar;
  _index_page := WV.WIKI.CLUSTERPARAM (_cluster_name, 'index-page', 'WelcomeVisitors');

  return (select XMLELEMENT ("MACRO_UNUSEDPAGES",
    	   XMLELEMENT("ul",
	     XMLAGG(
	       XMLELEMENT("li",
		  WV.WIKI.A(t.LocalName, t.LocalName, 'wikiword')))))
	   from WV.WIKI.TOPIC t inner join WV.WIKI.CLUSTERS c
	    on (t.ClusterId = c.ClusterId)
	    where c.ClusterName = _cluster_name
	    and t.LocalName not in (_index_page, 'ClusterSummary', WV.WIKI.DASHBOARD (), 'NoWhere')
	    and not exists (select * from WV.WIKI.LINK where DestId = t.TopicId));
}
;

create function WV.WIKI.A(in _href varchar, in _content varchar, in _class varchar)
{
  return XMLELEMENT ("a", 
  	XMLATTRIBUTES (
	 _href as "href", 
	 _class as "style"), _content);
}
;

create function WV.WIKI.MACRO_STATISTICS_POPULARTOPICS (inout _data varchar, inout _context any, inout _env any)
{
  declare _cluster_id int;
  _cluster_id := atoi (get_keyword ('ti_cluster_id', _env));
  return (select XMLELEMENT("MACRO_STATISTICS_POPULARTOPICS",
  	 	  XMLELEMENT ("table", XMLATTRIBUTES ('wikitable' as "class"),
		   XMLAGG(
		    XMLELEMENT("tr",
		     XMLELEMENT("td", WV.WIKI.A(LocalName, LocalName, 'wikiword')),
		     XMLELEMENT("td", Cnt)))))
		 from (select top 10 * from WV.WIKI.HITCOUNTER natural join WV.WIKI.TOPIC
		 	where ClusterId = _cluster_id
			order by Cnt desc) a);
}
;

create function WV.WIKI.MACRO_STATISTICS_TOPAUTHORS (inout _data varchar, inout _context any, inout _env any)
{
  return (select XMLELEMENT("MACRO_STATISTICS_TOPAUTHORS",
  	 	  XMLELEMENT ("table", XMLATTRIBUTES ('wikitable' as "class"),
		   XMLAGG(
		    XMLELEMENT("tr",
		     XMLELEMENT("td", WV.WIKI.A(U_NAME, U_NAME, 'wikiword')),
		     XMLELEMENT("td", Cnt)))))
		 from (select top 10 * from WV.WIKI.COMMITCOUNTER inner join DB.DBA.SYS_USERS 
		 	on (AuthorId = U_ID)
			order by Cnt desc) a);
}
;

		      
create function WV.WIKI.MACRO_SEMANTIC_FACTS (inout _data varchar, inout _context any, inout _env any)
{
  declare _topic_id, _cluster_id int;
  declare _local_name varchar;
  declare _args any;
  _args := WV.WIKI.PARSEMACROARGS (_data);
  _local_name := trim (WV.WIKI.GETMACROPARAM (_args, 'param', get_keyword ('ti_local_name', _env)));
  _cluster_id := atoi (get_keyword ('ti_cluster_id', _env));	
  _topic_id := (select TopicId from WV.WIKI.TOPIC where LocalName = _local_name and ClusterId = _cluster_id);
  declare _res any;
  _res := (select XMLELEMENT ("MACRO_SEMANTIC_FACTS",
  	 	  XMLELEMENT ("table", XMLATTRIBUTES ('wikitable' as "class"),
		   XMLAGG(
		    XMLELEMENT("tr",
		     XMLELEMENT("td",
		      PRED_DESCR || ':'),
		     XMLELEMENT("td",
		      case when SO_TYPE = ':VALUE' then SO_SUBJECT else 
		        WV.WIKI.A (SO_SUBJECT, SO_SUBJECT, 'forcedwikiword') end)))))
	   from WV.WIKI.SEMANTIC_OBJ, WV.WIKI.PREDICATE
	     where PRED_ID = SO_PRED
	     and SO_OBJECT_ID = _topic_id);
  declare _ent any;
  _ent := xpath_eval ('//tr', _res);
  if (_res is not null and _ent is not null)	     
   XMLInsertBefore (_ent,
   	XMLELEMENT ('tr', 
	 XMLELEMENT ('th',
	  XMLATTRIBUTES(2 as "COLSPAN"),
	  'Facts about ', WV.WIKI.A (_local_name, _local_name, 'wikiword'))));
  else
    _res := '';
  return _res;	 
}
;


create function WV.WIKI.MACRO_NOW (inout _data varchar, inout _context any, inout _env any)
{
  return WV.WIKI.DATEFORMAT(now());
}
;

		      



  
		      



  
