/*
 * Tlog tlog_stream_enc_* function test module.
 *
 * Copyright (C) 2015 Red Hat
 *
 * This file is part of tlog.
 *
 * Tlog is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Tlog is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tlog; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _TLOG_STREAM_ENC_TEST_H
#define _TLOG_STREAM_ENC_TEST_H

#include <stdbool.h>
#include <stdint.h>

#define TLOG_STREAM_ENC_TEST_BUF_SIZE    32

typedef bool (*tlog_stream_enc_test_func)(uint8_t *obuf,
                                          size_t *porem,
                                          size_t *polen,
                                          size_t *pirun,
                                          size_t *pidig,
                                          const uint8_t *ibuf,
                                          size_t ilen);

struct tlog_stream_enc_test {
    tlog_stream_enc_test_func   func;
    const uint8_t               ibuf_in[TLOG_STREAM_ENC_TEST_BUF_SIZE];
    size_t                      ilen_in;
    const uint8_t               obuf_out[TLOG_STREAM_ENC_TEST_BUF_SIZE];
    size_t                      orem_in;
    size_t                      orem_out;
    size_t                      olen_in;
    size_t                      olen_out;
    size_t                      irun_in;
    size_t                      irun_out;
    size_t                      idig_in;
    size_t                      idig_out;
    bool                        fit_out;
};

/**
 * Run a tlog_stream_enc_* function test.
 *
 * @param n     Test name.
 * @param t     Test structure.
 *
 * @return True if test passed, false otherwise.
 */
extern bool tlog_stream_enc_test(const char *n,
                                 const struct tlog_stream_enc_test t);

#endif /* _TLOG_STREAM_ENC_TEST_H */