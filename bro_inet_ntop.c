// Remove in v6.1. This file is deprecated along with bro_inet_ntop.h.

#include "zeek_inet_ntop.h"

const char *
bro_inet_ntop(int af, const void * __restrict src, char * __restrict dst,
    socklen_t size)
	{
	return zeek_inet_ntop(af, src, dst, size);
	}
