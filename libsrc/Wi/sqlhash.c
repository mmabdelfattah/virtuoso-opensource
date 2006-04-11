/*
 *  sqlhash.c
 *
 *  $Id$
 *
 *  Dynamic SQL Compiler, part 2
 *  
 *  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
 *  project.
 *  
 *  Copyright (C) 1998-2006 OpenLink Software
 *  
 *  This project is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; only version 2 of the License, dated June 1991.
 *  
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *  
 *  
*/

#include "libutil.h"
#include "sqlnode.h"
#include "sqlcomp.h"
#include "eqlcomp.h"
#include "lisprdr.h"
#include "xmlnode.h"
#include "sqlpar.h"
#include "sqlpfn.h"
#include "sqlcmps.h"
#include "sqlfn.h"
#include "security.h"
#include "sqlofn.h"



int dtp_is_fixed (dtp_t dtp);
int dtp_is_var (dtp_t dtp);


void
key_col_from_ssl (dbe_key_t * key, state_slot_t * ssl)
{
  NEW_VARZ (dbe_column_t, col);
  col->col_name = box_dv_short_string (SSL_HAS_NAME (ssl) ? ssl->ssl_name : "const");
  col->col_sqt = ssl->ssl_sqt;
  col->col_sqt.sqt_non_null = 0;
  if (DV_UNKNOWN == col->col_sqt.sqt_dtp
      ||  (!dtp_is_fixed (col->col_sqt.sqt_dtp) && !dtp_is_var (col->col_sqt.sqt_dtp)))
    {
      col->col_sqt.sqt_dtp = DV_LONG_STRING;
      col->col_sqt.sqt_precision = 0;
    }
  /* turn off length checking for temp cols for now */
  if (col->col_sqt.sqt_dtp == DV_LONG_STRING ||
      col->col_sqt.sqt_dtp == DV_ANY)
    col->col_sqt.sqt_precision = 0;
  col->col_id = dk_set_length (key->key_parts) + 1;

  col->col_options = box_copy_tree (ssl->ssl_sqt.sqt_tree);
  NCONCF1 (key->key_parts, col);
}


long
sqt_row_data_length (sql_type_t *sqt)
{
  long len = sqt_fixed_length (sqt);
  if (len == -1)
    {
      switch (sqt->sqt_dtp)
	{
	  case DV_STRING:
	      len = sqt->sqt_precision;
	      if (!len)
		len = 200;
	      break;
	  default:
	      len = 200;
	      break;
	}
    }
  return len;
}


dbe_key_t *
setp_temp_key (setp_node_t * setp, long *row_len_ptr)
{
  NEW_VARZ (dbe_key_t, key);

  key->key_n_significant = dk_set_length (setp->setp_keys);

  key->key_id = KI_TEMP;
  key->key_is_primary = 0;
  key->key_super_id = KI_TEMP;
  DO_SET (state_slot_t *, ssl, &setp->setp_keys)
    {
      if (row_len_ptr)
	*row_len_ptr += sqt_row_data_length (& ssl->ssl_sqt);
      key_col_from_ssl (key, ssl);
    }
  END_DO_SET();
  DO_SET (state_slot_t *, ssl, &setp->setp_dependent)
    {
      if (row_len_ptr)
	*row_len_ptr += sqt_row_data_length (& ssl->ssl_sqt);
      key_col_from_ssl (key, ssl);
    }
  END_DO_SET();

  dbe_key_layout (key);
  dk_set_push (&setp->src_gen.src_query->qr_temp_keys, (void*) key);
  return key;
}


int
key_cl_count (dbe_col_loc_t * cls)
{
  int inx;
  for (inx = 0; cls[inx].cl_col_id; inx++);
  return inx;
}


void
setp_distinct_hash (sql_comp_t * sc, setp_node_t * setp, long n_rows)
{
  int inx;
  int n_keys = dk_set_length (setp->setp_keys);
  int n_deps = dk_set_length (setp->setp_dependent);
  NEW_VARZ (hash_area_t, ha);
  DO_SET (state_slot_t *, ssl, &setp->setp_keys)
    {
      if (IS_BLOB_DTP (ssl->ssl_sqt.sqt_dtp))
	sqlc_new_error (sc->sc_cc, "42000", "SQ186",
	    "Long data types not allowed for distinct, order, "
	    "group or join condition columns (%s)", ssl->ssl_name);
      else if (DV_OBJECT == ssl->ssl_sqt.sqt_dtp)
	sqlc_new_error (sc->sc_cc, "42000", "SQ187",
	    "user defined data types not allowed for distinct, order, "
	    "group or join condition columns (%s)", ssl->ssl_name);
    }
  END_DO_SET();
  ha->ha_row_size = 0;
  ha->ha_key = setp_temp_key (setp, &ha->ha_row_size);
  setp->setp_ha = setp->setp_reserve_ha = ha;
  ha->ha_tree = ssl_new_tree (sc->sc_cc, "DISTINCT HASH");
  ha->ha_ref_itc = ssl_new_itc (sc->sc_cc);
  ha->ha_insert_itc = ssl_new_itc (sc->sc_cc);
#ifdef NEW_HASH
  ha->ha_bp_ref_itc = ssl_new_itc (sc->sc_cc);
#endif
  ha->ha_n_keys = n_keys;
  ha->ha_n_deps = n_deps;
  if (n_rows < 0)
    n_rows = 100000; /* count probably overflowed.- Large amount */
  else if (n_rows < 1000)
    n_rows = 1000; /* no less than 1000 if overflows memcache, must be at least this much */
  else if (n_rows > 1000000)
    n_rows = 1000000; /* have a cap on hash size */
  ha->ha_row_count = n_rows;
  ha->ha_key_cols = (dbe_col_loc_t *) dk_alloc_box_zero ((n_deps + n_keys + 1) * sizeof (dbe_col_loc_t), DV_CUSTOM);
  for (inx = 0; inx < n_keys + n_deps; inx++)
    {
      dbe_col_loc_t * cl = key_find_cl (ha->ha_key, inx +1);
      ha->ha_key_cols[inx] = cl[0];
      if ((inx >= n_keys) && (cl->cl_fixed_len < 0))
	ha->ha_memcache_only = 1;
    }
  ha->ha_slots = (state_slot_t **)
    list_to_array (dk_set_conc (dk_set_copy (setp->setp_keys),
				dk_set_copy (setp->setp_dependent)));
  ha->ha_allow_nulls = 1;
  ha->ha_op = HA_DISTINCT;
  if (setp->setp_any_user_aggregate_gos)
    ha->ha_memcache_only = 1;
}

