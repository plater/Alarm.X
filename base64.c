/*This code snippet is taken from coreutil's base64.c and adapted for 8 bit
 mips mpu usage davejplater@gmail.com
 */
/* base64.c -- Encode binary data using printable characters.
   Copyright (C) 1999-2001, 2004-2006, 2009-2022 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Written by Simon Josefsson.  Partially adapted from GNU MailUtils
 * (mailbox/filter_trans.c, as of 2004-11-28).  Improved by review
 * from Paul Eggert, Bruno Haible, and Stepan Kasal.
 *
 * See also RFC 4648 <https://www.ietf.org/rfc/rfc4648.txt>.
 *
 */

/* Get prototype. */
#include"buffers.h"

/* Get UCHAR_MAX. */
#include <limits.h>

#include <string.h>

/* Convert 'char' to 'unsigned char' without casting.  */
static unsigned char
to_uchar (char ch)
{
  return ch;
}

static const char b64c[64] =
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/* Base64 encode IN array of size INLEN into OUT array. OUT needs
   to be of length >= BASE64_LENGTH(INLEN), and INLEN needs to be
   a multiple of 3.  */
static void
base64_encode_fast (const char *restrict in, idx_t inlen, char *restrict out)
{
  while (inlen)
    {
      *out++ = b64c[(to_uchar (in[0]) >> 2) & 0x3f];
      *out++ = b64c[((to_uchar (in[0]) << 4) + (to_uchar (in[1]) >> 4)) & 0x3f];
      *out++ = b64c[((to_uchar (in[1]) << 2) + (to_uchar (in[2]) >> 6)) & 0x3f];
      *out++ = b64c[to_uchar (in[2]) & 0x3f];

      inlen -= 3;
      in += 3;
    }
}

/* Base64 encode IN array of size INLEN into OUT array of size OUTLEN.
   If OUTLEN is less than BASE64_LENGTH(INLEN), write as many bytes as
   possible.  If OUTLEN is larger than BASE64_LENGTH(INLEN), also zero
   terminate the output buffer. */
void base64_encode (const uint8_t *in, idx_t inlen, uint8_t *out, idx_t outlen)
{
  /* Note this outlen constraint can be enforced at compile time.
     I.E. that the output buffer is exactly large enough to hold
     the encoded inlen bytes.  The inlen constraints (of corresponding
     to outlen, and being a multiple of 3) can change at runtime
     at the end of input.  However the common case when reading
     large inputs is to have both constraints satisfied, so we depend
     on both in base_encode_fast().  */
  if (outlen % 4 == 0 && inlen == (outlen >> 2) * 3)
    {
      base64_encode_fast (in, inlen, out);
      return;
    }

  while (inlen && outlen)
    {
      *out++ = b64c[(to_uchar (in[0]) >> 2) & 0x3f];
      if (!--outlen)
        break;
      *out++ = b64c[((to_uchar (in[0]) << 4)
                       + (--inlen ? to_uchar (in[1]) >> 4 : 0))
                      & 0x3f];
      if (!--outlen)
        break;
      *out++ =
        (inlen
         ? b64c[((to_uchar (in[1]) << 2)
                   + (--inlen ? to_uchar (in[2]) >> 6 : 0))
                  & 0x3f]
         : '=');
      if (!--outlen)
        break;
      *out++ = inlen ? b64c[to_uchar (in[2]) & 0x3f] : '=';
      if (!--outlen)
        break;
      if (inlen)
        inlen--;
      if (inlen)
        in += 3;
    }

  if (outlen)
    *out = '\0';
}

