/*
 *  Dkbox.h
 *
 *  $Id$
 *
 *  Boxes
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

#ifndef _DKBOX1_H
#define _DKBOX1_H

#ifdef __cplusplus
typedef char * box_t;
typedef const char * cbox_t;
#else
typedef void * box_t;
typedef const void * cbox_t;
#endif

/*
 * We allow pointer arrays to contain small integers
 * for the sake of convenience. Even is a segmented
 * architecture this would be an invalid pointer.
 *
 * If the configuration has distributed objects they do
 * not get deleted in dk_delete_tree.
 */
#define SMALLEST_POSSIBLE_POINTER 0x10000

/* This is a pointer that will never be equal to any box pointer (alignment...) */
#define BADBEEF_BOX ((box_t)(0xBADBEEF))

/* This is the maximum alowed box length.
We have three bytes in the header to record it. */
#define MAX_BOX_LENGTH ((size_t)0xFFFFFF)
#define MAX_BOX_ELEMENTS (MAX_BOX_LENGTH/sizeof(void *))

/*
 * Test if the item should be boxed when appearing in an array
 */
#define IS_POINTER(n) \
	(((unsigned ptrlong) (n)) >= (unsigned ptrlong) SMALLEST_POSSIBLE_POINTER)

/*
 * IS_BOX_POINTER.  Test if the item is a non null pointer
 */
#define IS_BOX_POINTER(n) \
	(((unsigned ptrlong) (n)) >= (unsigned ptrlong)SMALLEST_POSSIBLE_POINTER)


#define IS_PERSISTENT(x)	0

/*
 *  Box tags
 */
#define TAG_FREE		0
#define TAG_BAD			1
/*#define TAG_BOX			2*/

#ifdef _DEBUG	/* _DEBUG, not DEBUG, is used intentionally */
extern long box_types_alloc[256];	/* implicit zero-fill assumed */
extern long box_types_free[256];	/* implicit zero-fill assumed */
#endif

#define box_tag_aux(box) (*((dtp_t *) &(((unsigned char *)(box))[-1])))
#define box_tag_aux_const(box) (*((const dtp_t *) &(((const unsigned char *)(box))[-1])))

#ifdef _DEBUG
/* This is to prevent us from occasional use of assignments like
   box_tag(smth) = DV_XXX, which breaks counters for types. */
#define box_tag(box) (box_tag_aux_const((box))+0)
#else
#define box_tag(box) box_tag_aux_const((box))
#endif

#ifdef _DEBUG
#define box_tag_modify_impl(box,new_tag) \
 do { \
   box_types_alloc[box_tag_aux((box))] --; \
   box_types_alloc[(dtp_t)(new_tag)] ++; \
   box_tag_aux((box)) = (new_tag); \
   } while (0)
#else
#define box_tag_modify_impl(box,new_tag) (box_tag_aux((box)) = (new_tag))
#endif

#ifdef MALLOC_DEBUG
#define box_tag_modify(box,new_tag) \
 do { \
   if (DV_UNAME == new_tag) \
     GPF_T1 ("Can't make UNAME by box_tag_modify"); \
   if (DV_UNAME == box_tag_aux(box)) \
     GPF_T1 ("Can't alter UNAME by box_tag_modify"); \
   if (DV_REFERENCE == new_tag) \
     GPF_T1 ("Can't make REFERENCE by box_tag_modify"); \
   if (DV_REFERENCE == box_tag_aux(box)) \
     GPF_T1 ("Can't alter REFERENCE by box_tag_modify"); \
   if (TAG_FREE == new_tag) \
     GPF_T1 ("Can't make TAG_FREE box by box_tag_modify"); \
   if (TAG_FREE == box_tag_aux(box)) \
     GPF_T1 ("Can't alter TAG_FREE by box_tag_modify"); \
   if (TAG_BAD == new_tag) \
     GPF_T1 ("Can't make TAG_BAD box by box_tag_modify"); \
   if (TAG_BAD == box_tag_aux(box)) \
     GPF_T1 ("Can't alter TAG_BAD by box_tag_modify"); \
   box_tag_modify_impl(box,new_tag); \
   } while (0);
#else
#define box_tag_modify(box,new_tag) box_tag_modify_impl(box,new_tag)
#endif

#define BOX_ELEMENTS(b) \
	(box_length ((box_t) (b)) / sizeof (box_t))

#define BOX_ELEMENTS_0(b) \
	((NULL != (b)) ? BOX_ELEMENTS(b) : (size_t)0)

#define BOX_ELEMENTS_INT(b) \
	((int) (box_length ((box_t) (b)) / sizeof (box_t)))

#define BOX_ELEMENTS_INT_0(b) \
	((NULL != (b)) ? BOX_ELEMENTS_INT(b) : 0)


#define DV_TYPE_OF(x) \
	(IS_BOX_POINTER (x) \
		? (dtp_t) box_tag(x) \
		: ((dtp_t)(DV_LONG_INT)) )

#ifdef _MSC_VER

#define _DO_BOX(inx, arr) \
	for (inx = 0; inx < (long)((arr) ? BOX_ELEMENTS(arr) : 0); inx ++) \
	  {

#define _DO_BOX_FAST(inx, arr) \
	do { \
	    long __max_##inx = (long)((arr) ? BOX_ELEMENTS(arr) : 0); \
	    for (inx = 0; inx < __max_##inx; inx ++) \
	      {

#else

#define _DO_BOX(inx, arr) \
	for (inx = 0; inx < ((arr) ? BOX_ELEMENTS(arr) : 0); inx ++) \
	  {

#define _DO_BOX_FAST(inx, arr) \
	do { \
	    uint32 __max_##inx = ((arr) ? BOX_ELEMENTS(arr) : 0); \
	    for (inx = 0; inx < __max_##inx; inx ++) \
	      {

#endif

#define DO_BOX(dtp, v, inx, arr) \
	_DO_BOX(inx, (arr)) \
	    dtp v = (dtp) (((void **)(arr)) [inx]);

#define END_DO_BOX \
}


#define DO_BOX_FAST(dtp, v, inx, arr) \
	_DO_BOX_FAST(inx, (arr)) \
	    dtp v = (dtp) (((void **)(arr)) [inx]);

#define END_DO_BOX_FAST \
	  }} while (0)


#ifdef DOUBLE_ALIGN

#define STATIC_DV_NULL {0,0,0,0,0,0,0,(char)DV_DB_NULL}
#define BOX_AUTO_OVERHEAD 8

# define BOX_AUTO(ptr, area, n, dtp) \
    do { \
	if (sizeof (area) - BOX_AUTO_OVERHEAD >= (n)) \
	  { \
	    ptr = (void *)(((char *) area) + BOX_AUTO_OVERHEAD); \
	    ((dtp_t *) &(area))[4] = (dtp_t) ((n) & 0xff); \
	    ((dtp_t *) &(area))[5] = (dtp_t) ((n) >> 8); \
	    ((dtp_t *) &(area))[6] = 0; \
	    ((dtp_t *) &(area))[7] = (dtp_t) (dtp); \
	  } \
	else \
	  ptr = (void *)(dk_alloc_box (n, dtp)); \
      } while (0)

#else /* DOUBLE_ALIGN */

#define STATIC_DV_NULL {0,0,0,(char)DV_DB_NULL}
#define BOX_AUTO_OVERHEAD 4

# define BOX_AUTO(ptr, area, n, dtp) \
    do { \
	if (sizeof (area) - BOX_AUTO_OVERHEAD >= (n)) \
	  { \
	    ptr = (void *)(((char *) area) + BOX_AUTO_OVERHEAD); \
	    ((dtp_t *) &(area))[0] = (dtp_t) ((n) & 0xff); \
	    ((dtp_t *) &(area))[1] = (dtp_t) ((n) >> 8); \
	    ((dtp_t *) &(area))[2] = 0; \
	    ((dtp_t *) &(area))[3] = (dtp_t) (dtp); \
	  } \
	else \
	  ptr = (void *)dk_alloc_box (n, dtp); \
      } while (0)

#endif

# define BOX_IS_AUTO(ptr, area) ((char *)(ptr) != ((char *) &(area)) + BOX_AUTO_OVERHEAD)

# define BOX_DONE(ptr, area) \
	if (BOX_IS_AUTO(ptr, area)) \
	  dk_free_box ((box_t) ptr);

/* This is used as the return type of the
   service if the service is not to send ANY automatic
   message to the client. NO DA_FUTURE_ANSWER MESSAGE WILL BE
   SENT IF THIS IS THE RETURN_TYPE OF THE SERVICE. The service still
   may itself  compose and send  a DA_FUTURE_ANSWER message.

   Otherwise this may be one of the DV_<xxx> constants whereupon
   the appropriate return message is built and sent as part of
   the DA_FUTURE_ANSWER message.
*/
#define DV_SEND_NO_ANSWER 1

/*
  This indicates that the future returns an array
  of pointers that is considered as multiple values by a client.
  This array is deallocated after sending.
*/
#define DV_MULTIPLE_VALUES 2


#define FIRST_DV_DTP 180

/* Data types */

/* NIL, false, the NULL pointer */
#define DV_NULL 180

/* Binary string with 1 byte length prefix */
#define DV_SHORT_STRING_SERIAL 181

/* Binary string with 4 byte length prefix */
#define DV_LONG_STRING 182
#define DV_SHORT_STRING 182
#define DV_STRING 182
/* C string with trailing 0 */
#define DV_C_STRING 183

#define DV_SYMBOL	127 /* moved from Dkbox.h */

	    /* DV_STRING is represented serialized as DV_SHORT_STRING_SERIAL for < 156 length, excl trailing 0 */

/* The short is transmitted as a DV_SHORT_INT or DV_LONG_INT depending on
 * its value.
 */
#define DV_C_SHORT 184

/*
 * Internally used in DB client to send string output sessions
 * as DV_<xx>_CONT_STRING's.
 */
#define DV_STRING_SESSION 185

#define DV_SHORT_CONT_STRING 186

#define DV_LONG_CONT_STRING 187

/* signed 1 byte integer */
#define DV_SHORT_INT 188

/* signed 4 byte integer. Sent low order first */
/* NOTE: a box holding a DV_LONG_INT has enough room to store a native
 * long data type, even if that's 8 bytes (Paul)
 * For transport, only 4 bytes are used
 */
#define DV_LONG_INT 189

#define DV_LONG_PACKED		DV_LONG_INT

/* 4 byte float */
#define DV_SINGLE_FLOAT 190

/* 8 byte float */
#define DV_DOUBLE_FLOAT 191

/* 1 byte character */
#define DV_CHARACTER 192

/*
 * Record with 4 byte element count. The number
 * of items follow (mostly OBJECT_AND_CLASS records)
 *
 * The size of the object constructed from this is 4 times the length
 * at the head of the message
 */
#define DV_ARRAY_OF_POINTER 193

/* len as DV-<xx>-INT, data as DV_xx_INT. */
#define DV_ARRAY_OF_LONG_PACKED 194

#define DV_ARRAY_OF_FLOAT 202

#define DV_ARRAY_OF_DOUBLE 195

/* len as DV-<xx>-INT, data as 4 byte blocks. */
#define DV_ARRAY_OF_LONG 209


/* Interpreted as ARRAY_OF_POINTER by C or C++ client */
#define DV_LIST_OF_POINTER 196

/*
 * The message contain an object id and a class id, both 4 byte ints.
 * This is interpreted as a reference to the object with the id in the
 * session. If no object with that id is found in the receiving party a
 * non present object is constructed. The class allows knowing the length
 * of the object so that a memory address can be reserved for eventually
 * bringing in the object.
 */
#define DV_OBJECT_AND_CLASS 197

/*
 * 4 bytes of object id follow. This may appear in slot values inside
 * clusters or in other places where the message sender knows that he receiver
 * has previously been informed of the class of the referenced object.
 * When this is not certain the sender uses DV_OBJECT_AND_CLASS.
 */
#define DV_OBJECT_REFERENCE 198

/*
 * Appears in a cluster delta as predicate value if the predicate has
 * been deleted. Does not really apply to C based Dis Kit
 * Interpreted as a NULL.
 */
#define DV_DELETED 199

/* pointer into a structure. object id, class id, member id, count */
#define DV_MEMBER_POINTER 200

/* C integer, whatever length it be. 16/32 */
#define DV_C_INT 201

/*
 * Identifies a custom serialization member. The reading function
 * will be in the dk_member_t for the member in question.
 * Only for use with DO
 */
#define DV_CUSTOM 203

#define DV_DB_NULL 204

#ifndef O12
#define O12 /* always define O12 in main branch */
#endif

#ifndef O12
#define DV_G_REF_CLASS 205

#define DV_G_REF 206
#endif

/* struct with first dp, current dp, current byte and length */
#define DV_BLOB_HEAD 207

#define DV_ARRAY_OF_XQVAL 212	/*!< List of XQuery values results */
#define DV_DICT_HASHTABLE 213	/*!< Copyable dictionary with keys of type "box", values of type "box or tree" and by-byte tree compare on keys. */
#define DV_DICT_ITERATOR 214	/*!< Copyable forward-and-reset iterator for underlying refcounted DV_DICT_HASHTABLE, with versioning. */
#define DV_XTREE_HEAD 215	/*!< Element name, attribute names and values */
#define DV_XTREE_NODE 216	/*!< Element head and content */

#define DV_UNAME 217		/*!< Unique name, whose single instance is saved in system-wide registry */
#define DV_REFERENCE 206	/*!< Reference to an 'self as ref' object, this is a read-only thing with do-nothing copy and free semantics */
#define DV_XPATH_QUERY 232	/*!< Query object, this is a read-only thing with reference counting */


/* Special box for wrapping memory for user-specific objects. */
typedef void (* dk_free_box_trap_cbk_t)(void *obj);
typedef struct dk_mem_wrapper_s * (* box_copy_trap_cbk_t)(void *obj);

typedef struct dk_mem_wrapper_s
{
  dk_free_box_trap_cbk_t	dmw_free;
  box_copy_trap_cbk_t		dmw_copy;
  void *			dmw_data[1];
} dk_mem_wrapper_t;

#define DV_MEM_WRAPPER 218

#define DV_SYMBOL	127 /* moved from widv.h */

#define DV_WIDE 225	/* wchar_t */
#define DV_LONG_WIDE 226   /* wchar_t with 32 bit length */

#define IS_STRING_DTP(dtp)	((DV_STRING == (dtp)) || (DV_UNAME == (dtp)))
#define IS_STRING_ALIGN_DTP(dtp) (IS_STRING_DTP(dtp) || (DV_C_STRING == (dtp)) || (DV_SYMBOL == (dtp)) || (DV_SHORT_STRING_SERIAL == (dtp)))

#define LAST_DV_DTP 220


#define unbox_num(n) unbox(n)
#define unbox_float(f) (*((float *)f))
#define unbox_double(f) (*((double *)f))
#define unbox_string(s) ((char *)s)

#define IS_NONLEAF_DTP(dtp) \
	(((dtp) == DV_ARRAY_OF_POINTER) || \
	 ((dtp) == DV_LIST_OF_POINTER) || \
	 ((dtp) == DV_ARRAY_OF_XQVAL) || \
	 ((dtp) == DV_XTREE_HEAD) || \
	 ((dtp) == DV_XTREE_NODE) )

#ifndef __LITTLE_ENDIAN
#define __LITTLE_ENDIAN  4321
#endif

#ifndef __BIG_ENDIAN
#define __BIG_ENDIAN 1234
#endif

#ifndef __BYTE_ORDER
#ifdef WORDS_BIGENDIAN
#define __BYTE_ORDER __BIG_ENDIAN
#else
#define __BYTE_ORDER __LITTLE_ENDIAN
#endif
#endif

/* Dkbox.c */
#if (__BYTE_ORDER == __LITTLE_ENDIAN)
#define box_length(box) ((uint32)(0x00ffffff & ((const uint32 *)(box))[-1]))
#define box_length_inline(box) box_length(box)
#else
#ifndef WIN32
#if (__BYTE_ORDER != __BIG_ENDIAN)
!! You have gluck in the configuration !!
!! Some value should be assigned to __BYTE_ORDER on any UNIX !!
#endif
#endif
extern uint32 big_endian_box_length (const void *box);
#define box_length_inline(ptr) \
  ( ((uint32) (((const unsigned char *)(ptr))[-4])) + \
    (((uint32) (((const unsigned char *)(ptr))[-3])) << 8) + \
    (((uint32) (((const unsigned char *)(ptr))[-2])) << 16) )
#define box_length(box) box_length_inline(box)
#endif


/* This must be a uniform hash for all sorts of strings. */
#define BYTE_BUFFER_HASH(hash,text,len) \
  do { \
    uint32 byte_buffer_hash_res = (len); \
    const unsigned char *byte_buffer_hash_text = ((const unsigned char *)(text)); \
    const unsigned char *byte_buffer_hash_tail = byte_buffer_hash_text + byte_buffer_hash_res /* == (len)*/; \
    while (byte_buffer_hash_tail > byte_buffer_hash_text) \
      { \
	byte_buffer_hash_res = (byte_buffer_hash_res * 0x41010021) + (--byte_buffer_hash_tail)[0]; \
      } \
    (hash) = byte_buffer_hash_res; \
    } while (0)

#define UNB_HDR_HASH	0
#define UNB_HDR_REFCTR	1
#define UNB_HDR_BOXHEAD	3

typedef struct uname_blk_s
{
  struct uname_blk_s *	unb_next;
  uint32		unb_hdr[4];
#ifdef MALLOC_DEBUG
  caddr_t		unb_data_ptr;
#else
  char			unb_data[sizeof(ptrlong)]; /* can be more than sizeof(ptrlong), past the end of struct. */
#endif
} uname_blk_t;


#ifdef MALLOC_DEBUG
#define DV_UNAME_BOX_HASH(hash,box) \
  do { \
    caddr_t dv_uname_box_hash_box = (box); \
    BYTE_BUFFER_HASH((hash),dv_uname_box_hash_box,box_length(dv_uname_box_hash_box)-1); \
    } while (0)
#else
#define UNAME_TO_UNAME_BLK(uname) ((uname_blk_t *)(((char *)(uname)) - (((uname_blk_t *)NULL)->unb_data - ((char *)NULL))))
#define DV_UNAME_BOX_HASH(hash,box) (hash) = UNAME_TO_UNAME_BLK(box)->unb_hdr[UNB_HDR_HASH]
#endif


EXE_EXPORT (box_t, dk_alloc_box, (size_t bytes, dtp_t tag));
EXE_EXPORT (box_t, dk_try_alloc_box, (size_t bytes, dtp_t tag));
EXE_EXPORT (box_t, dk_alloc_box_zero, (size_t bytes, dtp_t tag));

#ifdef MALLOC_DEBUG
void dk_alloc_box_assert (box_t box);
#else
#define dk_alloc_box_assert(box) ;
#endif

EXE_EXPORT (int, dk_free_box, (box_t box));
#ifdef DEBUG
extern void dk_check_tree (box_t box);
#else
#define dk_check_tree(box) ;
#endif
EXE_EXPORT (int, dk_free_tree, (box_t box));
EXE_EXPORT (int, dk_free_box_and_numbers, (box_t box));
EXE_EXPORT (int, dk_free_box_and_int_boxes, (box_t pbox));
EXE_EXPORT (ptrlong, unbox, (box_t  n));
EXE_EXPORT (box_t, box_num, (ptrlong n));
EXE_EXPORT (box_t, box_num_nonull, (ptrlong n));
EXE_EXPORT (box_t, box_string, (const char *string));
EXE_EXPORT (box_t, box_dv_short_string, (const char *string));
EXE_EXPORT (box_t, box_dv_short_nchars, (const char *buf, size_t buf_len));
EXE_EXPORT (box_t, box_dv_short_nchars_reuse, (const char *buf, size_t buf_len, box_t replace));
EXE_EXPORT (box_t, box_dv_short_substr, (ccaddr_t box, int n1, int n2));
EXE_EXPORT (box_t, box_dv_short_concat, (ccaddr_t box1, ccaddr_t box2));
EXE_EXPORT (char *, box_dv_ubuf, (size_t buf_strlen));
EXE_EXPORT (box_t, box_dv_uname_from_ubuf, (char *ubuf));
EXE_EXPORT (box_t, box_dv_uname_string, (const char *string));
EXE_EXPORT (box_t, box_dv_uname_nchars, (const char *buf, size_t buf_len));
EXE_EXPORT (box_t, box_dv_uname_substr, (ccaddr_t box, int n1, int n2));
EXE_EXPORT (box_t, box_double, (double d));
EXE_EXPORT (box_t, box_float, (float d));
#ifdef _DKSYSTEM_H
EXE_EXPORT (caddr_t, box_vsprintf, (size_t buflen_eval, const char *format, va_list tail));
#endif

EXE_EXPORT (box_t, box_copy, (cbox_t box));
EXE_EXPORT (box_t, box_copy_tree, (cbox_t box));
EXE_EXPORT (int, box_equal, (cbox_t b1, cbox_t b2));

extern box_t box_try_copy (cbox_t box, box_t stub);
extern box_t box_try_copy_tree (cbox_t box, box_t stub);

void dk_debug_dump_box (FILE *outfd, void *box, int lvl);

void box_dv_uname_make_immortal (caddr_t tree);
void box_dv_uname_make_immortal_all (void);

typedef void (*box_free_f) (caddr_t box);
typedef caddr_t (*box_copy_f) (caddr_t box);
caddr_t box_non_copiable (caddr_t b);
void dk_mem_hooks (dtp_t dtp, box_copy_f, box_free_f);

void box_reuse (caddr_t box, ccaddr_t data, size_t len, dtp_t dtp);

#ifdef MALLOC_DEBUG
box_t dbg_dk_alloc_box (const char *file, int line, size_t bytes, dtp_t tag);
box_t dbg_dk_try_alloc_box (const char *file, int line, size_t bytes, dtp_t tag);
box_t dbg_dk_alloc_box_zero (const char *file, int line, size_t bytes, dtp_t tag);
box_t dbg_box_string (const char *file, int line, const char *str);
box_t dbg_box_dv_short_string (const char *file, int line, const char *str);
box_t dbg_box_dv_short_nchars (const char *file, int line, const char *buf, size_t buf_len);
box_t dbg_box_dv_short_nchars_reuse (const char *file, int line, const char *buf, size_t buf_len, box_t replace);
box_t dbg_box_dv_short_substr (const char *file, int line, ccaddr_t str, int n1, int n2);
box_t dbg_box_dv_short_concat (const char *file, int line, ccaddr_t box1, ccaddr_t box2);
box_t dbg_box_copy (const char *file, int line, cbox_t box);
box_t dbg_box_try_copy (const char *file, int line, cbox_t box, box_t stub);
box_t dbg_box_copy_tree (const char *file, int line, cbox_t box);
box_t dbg_box_try_copy_tree (const char *file, int line, cbox_t box, box_t stub);
box_t dbg_box_num (const char *file, int line, ptrlong n);
box_t dbg_box_num_nonull (const char *file, int line, ptrlong n);
char *dbg_box_dv_ubuf (const char *file, int line, size_t buf_strlen);
box_t dbg_box_dv_uname_from_ubuf (const char *file, int line, char *ubuf);
box_t dbg_box_dv_uname_string (const char *file, int line, const char *string);
box_t dbg_box_dv_uname_nchars (const char *file, int line, const char *buf, size_t buf_len);
box_t dbg_box_dv_uname_substr (const char *file, int line, ccaddr_t box, int n1, int n2);
box_t dbg_box_double (const char *file, int line, double d);
box_t dbg_box_float (const char *file, int line, float d);
#ifdef _DKSYSTEM_H
caddr_t dbg_box_vsprintf (const char *file, int line, size_t buflen_eval, const char *format, va_list tail);
#endif

#ifndef _USRDLL
#ifndef EXPORT_GATE
#define dk_alloc_box(B,T)		dbg_dk_alloc_box (__FILE__, __LINE__, (B), (T))
#define dk_try_alloc_box(B,T)		dbg_dk_try_alloc_box (__FILE__, __LINE__, (B), (T))
#define dk_alloc_box_zero(B,T)		dbg_dk_alloc_box_zero (__FILE__, __LINE__, (B), (T))
#define box_string(S)			dbg_box_string (__FILE__, __LINE__, (S))
#define box_dv_short_string(S)		dbg_box_dv_short_string (__FILE__, __LINE__, (S))
#define box_dv_short_nchars(B,SZ)	dbg_box_dv_short_nchars (__FILE__, __LINE__, (B), (SZ))
#define box_dv_short_nchars_reuse(B,SZ,R)	dbg_box_dv_short_nchars_reuse (__FILE__, __LINE__, (B), (SZ), (R))
#define box_dv_short_substr(S,N1,N2)	dbg_box_dv_short_substr (__FILE__, __LINE__, (S), (N1), (N2))
#define box_dv_short_concat(S1,S2)	dbg_box_dv_short_concat (__FILE__, __LINE__, (S1), (S2))
#define box_copy(S)			dbg_box_copy (__FILE__, __LINE__, (S))
#define box_try_copy(S,STUB)		dbg_box_try_copy (__FILE__, __LINE__, (S), (STUB))
#define box_copy_tree(S)		dbg_box_copy_tree (__FILE__, __LINE__, (S))
#define box_try_copy_tree(S,STUB)	dbg_box_try_copy_tree (__FILE__, __LINE__, (S), (STUB))
#define box_num(S)			dbg_box_num (__FILE__, __LINE__, (S))
#define box_num_nonull(S)		dbg_box_num_nonull (__FILE__, __LINE__, (S))
#define box_dv_ubuf(B)			dbg_box_dv_ubuf (__FILE__, __LINE__, (B))
#define box_dv_uname_from_ubuf(U)	dbg_box_dv_uname_from_ubuf (__FILE__, __LINE__, (U))
#define box_dv_uname_string(S)		dbg_box_dv_uname_string (__FILE__, __LINE__, (S))
#define box_dv_uname_nchars(B,SZ)	dbg_box_dv_uname_nchars (__FILE__, __LINE__, (B), (SZ))
#define box_dv_uname_substr(S,N1,N2)	dbg_box_dv_uname_substr (__FILE__, __LINE__, (S), (N1), (N2))
#define box_double(D)			dbg_box_double (__FILE__, __LINE__, (D))
#define box_float(D)			dbg_box_float (__FILE__, __LINE__, (D))
#define box_vsprintf(L,F,T)		dbg_box_vsprintf (__FILE__, __LINE__, (L), (F), (T))

#endif
#endif

#endif

#ifdef _DKSYSTEM_H
#ifndef BOX_SPRINTF_DECLARED
#define BOX_SPRINTF_DECLARED

EXE_EXPORT (caddr_t, box_sprintf, (size_t buflen_eval, const char *format, ...));

#ifdef MALLOC_DEBUG
typedef caddr_t box_sprintf_impl_t (size_t buflen_eval, const char *format, ...);
typedef struct box_sprintf_track_s
  {
    box_sprintf_impl_t *box_sprintf_ptr;
  } box_sprintf_track_t;

box_sprintf_track_t *box_sprintf_track (const char *file, int line);
#ifndef _USRDLL
#ifndef EXPORT_GATE
#define box_sprintf box_sprintf_track (__FILE__, __LINE__)->box_sprintf_ptr
#endif
#endif
#else
#define box_sprintf_impl box_sprintf
#endif

#endif
#endif

union memspy_u
{
  char ms_chr[64];
  ptrlong ms_ptrlong[16];
  wchar_t ms_wchr[32];
  union memspy_u *ms_spys[16];
};

typedef union memspy_u memspy_t;

extern caddr_t uname___empty;

#endif
