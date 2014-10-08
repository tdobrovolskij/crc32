//////////////////////////////////////////////////////////////////////////
// CRC32 - C code to calculate CRC32 checksum for some data
// based on Intel's slicing-by-8 algorithm
// Copyright (c) 2014, Tadeus Dobrovolskij
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
/////////////////////////////////////////////////////////////////////////
#include <ruby.h>
#include <crc32.h>

void Init_crc32() {
  Crc32 = rb_define_module("Crc32");
  rb_define_singleton_method(Crc32, "calculate", method_crc32_calculate, 3);
}

VALUE method_crc32_calculate(VALUE self, VALUE data, VALUE length, VALUE previousCrc32) {
  uint32_t datalen;
  uint32_t crc;
  uint32_t one, two;
  char *bindata;
  uint32_t* current;
  unsigned char* currentChar;
  VALUE crc32;

  datalen = NUM2UINT(length);
  bindata = StringValuePtr(data);
  crc = NUM2UINT(previousCrc32) ^ ~ 0U;

  current = (uint32_t*) bindata;
  // process eight bytes at once
  while (datalen >= 8)
  {
    one = *current++ ^ crc;
    two = *current++;
    crc = Crc32Lookup[7][ one  & 0xFF] ^
      Crc32Lookup[6][(one>> 8) & 0xFF] ^
      Crc32Lookup[5][(one>>16) & 0xFF] ^
      Crc32Lookup[4][ one>>24        ] ^
      Crc32Lookup[3][ two      & 0xFF] ^
      Crc32Lookup[2][(two>> 8) & 0xFF] ^
      Crc32Lookup[1][(two>>16) & 0xFF] ^
      Crc32Lookup[0][ two>>24        ];
    datalen -= 8;
  }

  currentChar = (unsigned char*) current;
  // remaining 1 to 7 bytes
  while (datalen--)
    crc = (crc >> 8) ^ Crc32Lookup[0][(crc & 0xFF) ^ *currentChar++];
  crc =  crc ^ ~0U;
  crc32=UINT2NUM(crc);
  return crc32;
}
