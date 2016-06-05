#ifndef KPKLIB_GLOBAL_H
#define KPKLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KPKLIB_LIBRARY)
#  define LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // KPKLIB_GLOBAL_H
