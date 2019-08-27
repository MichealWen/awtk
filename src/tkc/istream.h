﻿/**
 * File:   tk_istream.h
 * Author: AWTK Develop Team
 * Brief:  input stream interface
 *
 * Copyright (c) 2019 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2019-08-27 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_TK_ISTREAM_H
#define TK_TK_ISTREAM_H

#include "tkc/object.h"

BEGIN_C_DECLS

struct _tk_istream_t;
typedef struct _tk_istream_t tk_istream_t;

typedef int32_t (*tk_istream_read_t)(tk_istream_t* stream, uint8_t* buff, uint32_t max_size);
typedef ret_t (*tk_istream_seek_t)(tk_istream_t* stream, uint32_t offset);

/**
 * @class tk_istream_t
 * @parent object_t
 *
 * input stream interface
 *
 */
typedef struct _tk_istream_t {
  object_t object;

  tk_istream_read_t read;
  tk_istream_seek_t seek;
} tk_istream_t;

/**
 * @method tk_istream_read
 *
 * 读取数据。
 *
 * @param {tk_istream_t*} stream istream对象。
 * @param {uint8_t*} buff 返回数据的缓冲区。
 * @param {uint32_t} max_size 缓冲区的大小。
 *
 * @return {int32_t} 返回负数表示读取失败，否则返回实际读取数据的长度。
 *
 */
int32_t tk_istream_read(tk_istream_t* stream, uint8_t* buff, uint32_t max_size);

/**
 * @method tk_istream_seek
 *
 * 设置偏移量。
 *
 * @param {tk_istream_t*} stream istream对象。
 * @param {uint32_t} offset 偏移量。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 *
 */
ret_t tk_istream_seek(tk_istream_t* stream, uint32_t offset);

/**
 * @method tk_istream_read_len
 *
 * 读取指定长度的数据。
 *
 * @param {tk_istream_t*} stream istream对象。
 * @param {uint8_t*} buff 返回数据的缓冲区。
 * @param {uint32_t} max_size 缓冲区的大小。
 *
 * @return {int32_t} 返回负数表示读取失败，否则返回实际读取数据的长度。
 *
 */
int32_t tk_istream_read_len(tk_istream_t* stream, uint8_t* buff, uint32_t max_size);

#define TK_ISTREAM_PROP_FD "fd"

#define TK_ISTREAM(obj) ((tk_istream_t*)(obj))

END_C_DECLS

#endif /*TK_TK_ISTREAM_H*/
