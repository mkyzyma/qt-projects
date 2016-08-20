#ifndef KPKDATA_GLOBAL_H
#define KPKDATA_GLOBAL_H

#include <QtCore/qglobal.h>
/*!
 * \file
 * \brief Необходимые директивы препроцессора
 * \note Строка \code #define DB_BASE_VERSION 1 \endcode устанавливает версию БД
 * \note Строка \code #pragma db namespace() pointer(std::shared_ptr) \endcode
 *  указывает но то что в odb для указателей используются std::shared_ptr
 * \note Строка \code #pragma db namespace() session \endcode
 *  указывает на то что должна использоваться сессия для всех объектов БД
 */

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

#pragma db namespace() pointer(std::shared_ptr)
#pragma db namespace() session



#endif // KPKDATA_GLOBAL_H
