#ifndef CRYPTOPP_STDCPP_H
#define CRYPTOPP_STDCPP_H

#if _MSC_VER >= 1500
#define _DO_NOT_DECLARE_INTERLOCKED_INTRINSICS_IN_MEMORY
#include <intrin.h>
#endif

#include <string>
#include <memory>
#include <exception>
#include <typeinfo>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <limits>
#include <deque>
#include <list>
#include <map>
#include <new>

#if defined(_MSC_VER) && (_MSC_VER < 1900) && defined(_HAS_EXCEPTIONS) && (_HAS_EXCEPTIONS == 0)
// Workaround for: https://connect.microsoft.com/VisualStudio/feedback/details/1600701/type-info-does-not-compile-with-has-exceptions-0
namespace std {
  using ::type_info;
}
#endif

#if _MSC_VER >= 1600
// for make_unchecked_array_iterator
#include <iterator>
#endif

#if defined(CRYPTOPP_CXX11_ATOMICS)
#include <atomic>
#endif

#if defined(CRYPTOPP_CXX11_SYNCHRONIZATION)
#include <mutex>
#endif

#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <climits>
#include "trap.h"

#ifdef CRYPTOPP_INCLUDE_VECTOR_CC
// workaround needed on Sun Studio 12u1 Sun C++ 5.10 SunOS_i386 128229-02 2009/09/21
#include <vector.cc>
#endif

// for alloca
#if defined(CRYPTOPP_BSD_AVAILABLE)
#include <stdlib.h>
#elif defined(CRYPTOPP_UNIX_AVAILABLE) || defined(__sun) || defined(QNX)
#include <alloca.h>
#elif defined(CRYPTOPP_WIN32_AVAILABLE) || defined(__MINGW32__) || defined(__BORLANDC__)
#include <malloc.h>
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4231)	// re-disable this
#ifdef _CRTAPI1
#define CRYPTOPP_MSVCRT6
#endif
#endif

#endif
