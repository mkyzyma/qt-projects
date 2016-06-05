// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PASSPORT_ODB_HXX
#define PASSPORT_ODB_HXX

// Begin prologue.
//
#include <odb/qt/version.hxx>
#if ODB_QT_VERSION != 2040000 // 2.4.0
#  error ODB and C++ compilers see different libodb-qt interface versions
#endif
#include <odb/qt/basic/pgsql/qstring-traits.hxx>
#include <odb/qt/basic/pgsql/qbyte-array-traits.hxx>
#include <odb/qt/basic/pgsql/quuid-traits.hxx>
#include <odb/qt/containers/qhash-traits.hxx>
#include <odb/qt/containers/qlist-traits.hxx>
#include <odb/qt/containers/qlinked-list-traits.hxx>
#include <odb/qt/containers/qmap-traits.hxx>
#include <odb/qt/containers/qset-traits.hxx>
#include <odb/qt/containers/qvector-traits.hxx>
#include <odb/qt/date-time/pgsql/qdate-traits.hxx>
#include <odb/qt/date-time/pgsql/qtime-traits.hxx>
#include <odb/qt/date-time/pgsql/qdate-time-traits.hxx>
#include <QtCore/QSharedPointer>
#include <odb/qt/smart-ptr/pointer-traits.hxx>
#include <odb/qt/smart-ptr/wrapper-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "Passport.h"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
}

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // Passport
  //
  template <>
  class access::composite_value_traits< ::kpk::data::Passport, id_pgsql >
  {
    public:
    typedef ::kpk::data::Passport value_type;

    struct image_type
    {
      // _series
      //
      details::buffer _series_value;
      std::size_t _series_size;
      bool _series_null;

      // _number
      //
      details::buffer _number_value;
      std::size_t _number_size;
      bool _number_null;

      // _date
      //
      int _date_value;
      bool _date_null;

      // _org
      //
      details::buffer _org_value;
      std::size_t _org_size;
      bool _org_null;

      // _orgCode
      //
      details::buffer _orgCode_value;
      std::size_t _orgCode_size;
      bool _orgCode_null;
    };

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static bool
    init (image_type&,
          const value_type&,
          pgsql::statement_kind);

    static void
    init (value_type&,
          const image_type&,
          database*);

    static bool
    get_null (const image_type&);

    static void
    set_null (image_type&,
              pgsql::statement_kind);

    static const std::size_t column_count = 5UL;
  };
}

#include "Passport-odb.ixx"

#include <odb/post.hxx>

#endif // PASSPORT_ODB_HXX
