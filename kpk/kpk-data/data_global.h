#ifndef KPKDATA_GLOBAL_H
#define KPKDATA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KPKDATA_LIBRARY)
#  define DATASHARED_EXPORT Q_DECL_EXPORT
#else
#  define DATASHARED_EXPORT Q_DECL_IMPORT
#endif

#define DB_BASE_VERSION 1

#ifdef ODB_COMPILER
#   pragma db model version(DB_BASE_VERSION, 1, open)
#else
#   pragma warning(disable : 4068)
#endif

#endif // KPKDATA_GLOBAL_H
