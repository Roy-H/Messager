#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SERVICELIB_LIB)
#  define SERVICELIB_EXPORT Q_DECL_EXPORT
# else
#  define SERVICELIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define SERVICELIB_EXPORT
#endif
