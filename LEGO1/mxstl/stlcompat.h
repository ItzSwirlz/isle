#ifndef STLCOMPAT_H
#define STLCOMPAT_H

#include "compat.h"

#if defined(_MSC_VER) && _MSC_VER <= MSVC420_VERSION
// Disable "nonstandard extension used : 'bool'" warning spam
#pragma warning(disable : 4237)
#include "mxstl.h"
#else
#include <algorithm>
#include <list>
#include <set>
using std::list;
using std::set;
#endif

#endif // STLCOMPAT_H