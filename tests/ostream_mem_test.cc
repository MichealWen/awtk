﻿#include "streams/ostream_mem.h"
#include "gtest/gtest.h"

TEST(OStreamMem, basic) {
  uint8_t buff[12];

  tk_ostream_t* is = tk_ostream_mem_create(buff, sizeof(buff), 0, FALSE);

  ASSERT_EQ(tk_ostream_write(is, (uint8_t*)"1111", 4), 4);
  ASSERT_EQ(memcmp(buff, (uint8_t*)"1111", 4), 0);

  ASSERT_EQ(tk_ostream_write(is, (uint8_t*)"2222", 4), 4);
  ASSERT_EQ(memcmp(buff, (uint8_t*)"11112222", 8), 0);

  ASSERT_EQ(tk_ostream_write(is, (uint8_t*)"3333", 4), 4);
  ASSERT_EQ(memcmp(buff, (uint8_t*)"111122223333", 12), 0);

  ASSERT_EQ(tk_ostream_write(is, (uint8_t*)"4444", 4), 0);

  object_unref(OBJECT(is));
}

TEST(OStreamMem, packet_size) {
  uint8_t buff[12];
  tk_ostream_t* is = tk_ostream_mem_create(buff, sizeof(buff), 4, FALSE);

  ASSERT_EQ(tk_ostream_write(is, (uint8_t*)"11111", 5), 4);
  ASSERT_EQ(memcmp(buff, (uint8_t*)"1111", 4), 0);

  ASSERT_EQ(tk_ostream_write(is, (uint8_t*)"22222", 5), 4);
  ASSERT_EQ(memcmp(buff, (uint8_t*)"11112222", 8), 0);

  ASSERT_EQ(tk_ostream_write(is, (uint8_t*)"33333", 5), 4);
  ASSERT_EQ(memcmp(buff, (uint8_t*)"111122223333", 12), 0);

  ASSERT_EQ(tk_ostream_write(is, (uint8_t*)"4444", 4), 0);

  ASSERT_EQ(tk_ostream_seek(is, 0), RET_OK);
  ASSERT_EQ(tk_ostream_write(is, (uint8_t*)"4444", 4), 4);
  ASSERT_EQ(memcmp(buff, (uint8_t*)"4444", 4), 0);

  object_unref(OBJECT(is));
}

TEST(OStreamMem, write_len) {
  uint8_t buff[12];
  tk_ostream_t* is = tk_ostream_mem_create(buff, sizeof(buff), 4, FALSE);

  ASSERT_EQ(tk_ostream_write_len(is, (uint8_t*)"1111122223333", 12), 12);
  ASSERT_EQ(memcmp(buff, (uint8_t*)"1111122223333", 12), 0);

  object_unref(OBJECT(is));
}
