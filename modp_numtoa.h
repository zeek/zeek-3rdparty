/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set expandtab shiftwidth=4 tabstop=4: */

/**
 * \file
 *
 * <pre>
 * Copyright &copy; 2007, Nick Galbreath -- nickg [at] modp [dot] com
 * All rights reserved.
 * http://code.google.com/p/stringencoders/
 * Released under the bsd license.
 * </pre>
 *
 * This defines signed/unsigned integer, and 'double' to char buffer
 * converters.  The standard way of doing this is with "sprintf", however
 * these functions are
 *   * guarenteed maximum size output
 *   * 5-20x faster!
 *   * core-dump safe
 *
 *
 */

#pragma once

#ifdef __cplusplus
#define BEGIN_C extern "C" {
#define END_C }
#else
#define BEGIN_C
#define END_C
#endif

BEGIN_C

#include <stdint.h>
#include <stddef.h>

/** \brief convert an signed integer to char buffer, return # characters added
 *
 * \param[in] value
 * \param[out] buf the output buffer.  Should be 16 chars or more.
 */
size_t modp_itoa10(int32_t value, char* buf);

/** \brief convert an unsigned integer to char buffer, return # characters added
 *
 * \param[in] value
 * \param[out] buf The output buffer, should be 16 chars or more.
 */
size_t modp_uitoa10(uint32_t value, char* buf);

/** \brief convert an signed long integer to char buffer, return # characters added
 *
 * \param[in] value
 * \param[out] buf the output buffer.  Should be 24 chars or more.
 */
size_t modp_litoa10(int64_t value, char* buf);

/** \brief convert an unsigned long integer to char buffer, return # characters added
 *
 * \param[in] value
 * \param[out] buf The output buffer, should be 24 chars or more.
 */
size_t modp_ulitoa10(uint64_t value, char* buf);

/** \brief convert a floating point number to char buffer with
 *         fixed-precision format, return # characters added
 *
 * This is similar to "%.[0-9]f" in the printf style.  It will include
 * trailing zeros
 *
 * If the input value is greater than 1<<31, then the output format
 * will be switched exponential format and include as many precision digits
 * as needed to preserve information.
 *
 * \param[in] value
 * \param[out] buf  The allocated output buffer.  Should be 32 chars or more.
 * \param[in] precision  Number of digits to the right of the decimal point.
 *    Can only be 0-9.
 */
size_t modp_dtoa(double value, char* buf, int precision);

/** \brief convert a floating point number to char buffer with a
 *         variable-precision format, and no trailing zero, return
 *         number of characters added
 *
 * This is similar to "%.[0-9]f" in the printf style, except it will
 * NOT include trailing zeros after the decimal point.  This type
 * of format oddly does not exists with printf.
 *
 * If the input value is greater than 1<<31, then the output format
 * will be switched exponential format and include as many precision digits
 * as needed to preserve information.
 *
 * If a non-zero input value is less than 10^(-precision), the output format
 * will be switched exponential format and include as many precision digits
 * as needed to preserve information.
 *
 * \param[in] value
 * \param[out] buf  The allocated output buffer.  Should be 32 chars or more.
 * \param[in] precision  Number of digits to the right of the decimal point.
 *    Can only be 0-9.
 */
size_t modp_dtoa2(double value, char* buf, int precision);

/** \brief convert a floating point number to char buffer with a
 *         variable-precision format, no trailing zeros, and no
 *   	scientific notation, return number of characters added
 *
 *  Other than avoiding scientific notation, this is the same as mop_dtoa2. It does however
 *  require the max buffer length. The buffer will always be null-terminated.
 */
size_t modp_dtoa3(double value, char* buf, int n, int precision);

END_C
