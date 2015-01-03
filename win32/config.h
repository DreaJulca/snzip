/*
 * Definitions for snappy
 */
#pragma warning(disable: 4267 4244 4334)

#define inline __inline

#if defined WIN64 || defined _WIN64
#define ssize_t __int64
#else
#define ssize_t long
#endif

#define HAVE_BUILTIN_CTZ
#include <intrin.h>

static __inline int __builtin_ctz(unsigned long n)
{
	unsigned long idx;
	_BitScanForward(&idx, n);
	return idx;
}

#if defined WIN64 || defined _WIN64
static __inline int __builtin_ctzll(unsigned __int64 n)
{
	unsigned long idx;
	_BitScanForward64(&idx, n);
	return idx;
}
#else
static __inline int __builtin_ctzll(unsigned __int64 n)
{
	unsigned long idx;
	unsigned long lower32 = (unsigned long)n;

	if (lower32) {
		_BitScanForward(&idx, lower32);
		return idx;
	} else {
		_BitScanForward(&idx, n >> 32);
		return idx + 32;
	}
}
#endif

static __inline int __builtin_clz(unsigned long n)
{
	unsigned long idx;
	_BitScanReverse(&idx, n);
	return 31 ^ idx;
}


/*
 * Definitions for snzip
 */
#define PACKAGE_STRING "snzip"
#define DEFAULT_FORMAT framing2_format
#define HAVE_SSE4_2
#define stat _stati64
#define fstat _fstati64
#include "ya_getopt.h"
