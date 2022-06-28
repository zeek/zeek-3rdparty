#pragma once

#warning "This file is deprecated and will be removed in v6.1. Use zeek_inet_ntop.h instead."
#include "zeek_inet_ntop.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/socket.h>

[[deprecated("Remove in v6.1. Use zeek_inet_ntop.")]]
const char *
bro_inet_ntop(int af, const void * __restrict src, char * __restrict dst,
    socklen_t size);

#ifdef __cplusplus
}
#endif
