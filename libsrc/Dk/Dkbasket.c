/*
 *  Dkbasket.c
 *
 *  $Id$
 *
 *  Baskets
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

#include "Dk.h"

void
basket_init (basket_t *bsk)
{
  LISTINIT (bsk, bsk_next, bsk_prev);
  bsk->bsk_count = 0;
}


void
basket_add (basket_t *bsk, void *token)
{
  NEW_VAR (basket_t, newn);

  if (bsk->bsk_count == 0)
    basket_init (bsk);

  newn->bsk_pointer = token;
  LISTPUTBEFORE (bsk, newn, bsk_next, bsk_prev);
  bsk->bsk_count++;
}


void *
basket_peek (basket_t *bsk)
{
  return (bsk->bsk_count == 0) ? NULL : bsk->bsk_next->bsk_pointer;
}


void *
basket_get (basket_t *bsk)
{
  void *data;

  if (bsk->bsk_count == 0)
    return NULL;

  bsk->bsk_count--;
  bsk = bsk->bsk_next;

  LISTDELETE (bsk, bsk_next, bsk_prev);

  data = bsk->bsk_pointer;
  dk_free (bsk, sizeof (basket_t));

  return data;
}


int
basket_is_empty (basket_t *bsk)
{
  return bsk->bsk_count == 0;
}
