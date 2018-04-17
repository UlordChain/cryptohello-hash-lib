#ifndef __MINER_H__
#define __MINER_H__

#include <cpuminer-config.h>

#define USER_AGENT PACKAGE_NAME "/" PACKAGE_VERSION
#define MAX_CPUS 16

#ifdef _MSC_VER

#undef USE_ASM  /* to fix */

#ifdef NOASM
#undef USE_ASM
#endif

/* missing arch defines for msvc */
#if defined(_M_X64)
#define __i386__ 1
#define __x86_64__ 1
#elif defined(_M_X86)
#define __i386__ 1
#endif

#endif /* _MSC_VER */

#ifndef _MSC_VER
#include <sys/param.h>
#else
#define inline __inline
#endif

#include <stdbool.h>
#include <inttypes.h>

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# ifdef HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif


#include "compat.h"


#ifdef HAVE_SYS_ENDIAN_H
#include <sys/endian.h>
#endif

typedef unsigned char uchar;



#endif /* __MINER_H__ */
