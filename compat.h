#ifndef __COMPAT_H__
#define __COMPAT_H__

#ifdef WIN32

#include <windows.h>

#define sleep(secs) Sleep((secs) * 1000)

enum {
	PRIO_PROCESS		= 0,
};

extern int opt_priority;
static __inline int setpriority(int which, int who, int prio)
{
	switch (opt_priority) {
		case 5:
			prio = THREAD_PRIORITY_TIME_CRITICAL;
			break;
		case 4:
			prio = THREAD_PRIORITY_HIGHEST;
			break;
		case 3:
			prio = THREAD_PRIORITY_ABOVE_NORMAL;
			break;
		case 2:
			prio = THREAD_PRIORITY_NORMAL;
			break;
		case 1:
			prio = THREAD_PRIORITY_BELOW_NORMAL;
			break;
		case 0:
		default:
			prio = THREAD_PRIORITY_IDLE;
	}
	return -!SetThreadPriority(GetCurrentThread(), prio);
}

#ifdef _MSC_VER
#define snprintf(...) _snprintf(__VA_ARGS__)
#define strdup(...) _strdup(__VA_ARGS__)
#define strncasecmp(x,y,z) _strnicmp(x,y,z)
#define strcasecmp(x,y) _stricmp(x,y)
#define __func__ __FUNCTION__
#define __thread __declspec(thread)
#define _ALIGN(x) __declspec(align(x))
typedef int ssize_t;

#include <stdlib.h>

#endif

#endif /* WIN32 */

#ifndef _MSC_VER
#define _ALIGN(x) __attribute__ ((aligned(x)))
#endif

#undef unlikely
#undef likely
#if defined(__GNUC__) && (__GNUC__ > 2) && defined(__OPTIMIZE__)
#define unlikely(expr) (__builtin_expect(!!(expr), 0))
#define likely(expr) (__builtin_expect(!!(expr), 1))
#else
#define unlikely(expr) (expr)
#define likely(expr) (expr)
#endif

#ifndef WIN32
#define MAX_PATH PATH_MAX
#endif

#endif /* __COMPAT_H__ */
