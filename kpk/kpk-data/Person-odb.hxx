// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PERSON_ODB_HXX
#define PERSON_ODB_HXX

// Begin prologue.
//
#include <odb/qt/version.hxx>
#if ODB_QT_VERSION != 2040000 // 2.4.0
#  error ODB and C++ compilers see different libodb-qt interface versions
#endif
#include <odb/qt/basic/pgsql/qstring-traits.hxx>
#include <odb/qt/basic/pgsql/qbyte-array-traits.hxx>
#include <odb/qt/basic/pgsql/quuid-traits.hxx>
#include <odb/qt/date-time/pgsql/qdate-traits.hxx>
#include <odb/qt/date-time/pgsql/qtime-traits.hxx>
#include <odb/qt/date-time/pgsql/qdate-time-traits.hxx>
#include "traits-pgsql.h"
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "Person.h"

#include "DbObject-odb.hxx"
#include "IsDeleted-odb.hxx"
#include "Name-odb.hxx"
#include "Passport-odb.hxx"
#include "User-odb.hxx"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // Person
  //
  template <>
  struct class_traits< ::kpk::data::Person >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::kpk::data::Person >
  {
    public:
    typedef ::kpk::data::Person object_type;
    typedef ::std::shared_ptr< ::kpk::data::Person > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::ulong id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // Person
  //
  template <typename A>
  struct pointer_query_columns< ::kpk::data::Person, id_pgsql, A >:
    pointer_query_columns< ::kpk::data::DbObject, id_pgsql, A >
  {
    // DbObject
    //
    typedef pointer_query_columns< ::kpk::data::DbObject, id_pgsql, A > DbObject;

    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // name
    //
    struct name_class_
    {
      name_class_ ()
      {
      }

      // first
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      first_type_;

      static const first_type_ first;

      // middle
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      middle_type_;

      static const middle_type_ middle;

      // last
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      last_type_;

      static const last_type_ last;

      // full
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      full_type_;

      static const full_type_ full;
    };

    static const name_class_ name;

    // passport
    //
    struct passport_class_
    {
      passport_class_ ()
      {
      }

      // series
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      series_type_;

      static const series_type_ series;

      // number
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      number_type_;

      static const number_type_ number;

      // date
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QDate,
          pgsql::id_date >::query_type,
        pgsql::id_date >
      date_type_;

      static const date_type_ date;

      // org
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      org_type_;

      static const org_type_ org;

      // orgCode
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      orgCode_type_;

      static const orgCode_type_ orgCode;
    };

    static const passport_class_ passport;

    // inn
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    inn_type_;

    static const inn_type_ inn;

    // snils
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    snils_type_;

    static const snils_type_ snils;

    // member
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    member_type_;

    static const member_type_ member;
  };

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::id_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::first_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::
  first (A::table_name, "\"name_first\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::middle_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::
  middle (A::table_name, "\"name_middle\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::last_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::
  last (A::table_name, "\"name_last\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::full_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::
  full (A::table_name, "\"name_full\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::name;

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::series_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  series (A::table_name, "\"pass_series\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::number_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  number (A::table_name, "\"pass_number\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::date_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  date (A::table_name, "\"pass_date\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::org_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  org (A::table_name, "\"pass_org\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::orgCode_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  orgCode (A::table_name, "\"pass_orgCode\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::passport;

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::inn_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::
  inn (A::table_name, "\"inn\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::snils_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::
  snils (A::table_name, "\"snils\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::member_type_
  pointer_query_columns< ::kpk::data::Person, id_pgsql, A >::
  member (A::table_name, "\"idMember\"", 0);

  template <>
  class access::object_traits_impl< ::kpk::data::Person, id_pgsql >:
    public access::object_traits< ::kpk::data::Person >
  {
    public:
    struct id_image_type
    {
      long long id_value;
      bool id_null;

      std::size_t version;
    };

    struct image_type: object_traits_impl< ::kpk::data::DbObject, id_pgsql >::image_type
    {
      // _id
      //
      long long _id_value;
      bool _id_null;

      // _name
      //
      composite_value_traits< ::kpk::data::Name, id_pgsql >::image_type _name_value;

      // _passport
      //
      composite_value_traits< ::kpk::data::Passport, id_pgsql >::image_type _passport_value;

      // _inn
      //
      details::buffer _inn_value;
      std::size_t _inn_size;
      bool _inn_null;

      // _snils
      //
      details::buffer _snils_value;
      std::size_t _snils_size;
      bool _snils_null;

      // _member
      //
      long long _member_value;
      bool _member_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct member_tag;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 18UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::kpk::data::Person, id_common >:
    public access::object_traits_impl< ::kpk::data::Person, id_pgsql >
  {
  };

  // Person
  //
  template <>
  struct alias_traits<
    ::kpk::data::Member,
    id_pgsql,
    access::object_traits_impl< ::kpk::data::Person, id_pgsql >::member_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::kpk::data::Person, id_pgsql >
  {
    // member
    //
    typedef
    odb::alias_traits<
      ::kpk::data::Member,
      id_pgsql,
      access::object_traits_impl< ::kpk::data::Person, id_pgsql >::member_tag>
    member_alias_;
  };

  template <typename A>
  struct query_columns< ::kpk::data::Person, id_pgsql, A >:
    query_columns_base< ::kpk::data::Person, id_pgsql >,
    query_columns< ::kpk::data::DbObject, id_pgsql, A >
  {
    // DbObject
    //
    typedef query_columns< ::kpk::data::DbObject, id_pgsql, A > DbObject;

    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // name
    //
    struct name_class_
    {
      name_class_ ()
      {
      }

      // first
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      first_type_;

      static const first_type_ first;

      // middle
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      middle_type_;

      static const middle_type_ middle;

      // last
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      last_type_;

      static const last_type_ last;

      // full
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      full_type_;

      static const full_type_ full;
    };

    static const name_class_ name;

    // passport
    //
    struct passport_class_
    {
      passport_class_ ()
      {
      }

      // series
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      series_type_;

      static const series_type_ series;

      // number
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      number_type_;

      static const number_type_ number;

      // date
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QDate,
          pgsql::id_date >::query_type,
        pgsql::id_date >
      date_type_;

      static const date_type_ date;

      // org
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      org_type_;

      static const org_type_ org;

      // orgCode
      //
      typedef
      pgsql::query_column<
        pgsql::value_traits<
          ::QString,
          pgsql::id_string >::query_type,
        pgsql::id_string >
      orgCode_type_;

      static const orgCode_type_ orgCode;
    };

    static const passport_class_ passport;

    // inn
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    inn_type_;

    static const inn_type_ inn;

    // snils
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    snils_type_;

    static const snils_type_ snils;

    // member
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    member_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::kpk::data::Member,
        id_pgsql,
        member_alias_ > >
    member_pointer_type_;

    struct member_type_: member_pointer_type_, member_column_type_
    {
      member_type_ (const char* t, const char* c, const char* conv)
        : member_column_type_ (t, c, conv)
      {
      }
    };

    static const member_type_ member;
  };

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::id_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::first_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::
  first (A::table_name, "\"name_first\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::middle_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::
  middle (A::table_name, "\"name_middle\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::last_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::
  last (A::table_name, "\"name_last\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::full_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_::
  full (A::table_name, "\"name_full\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::name_class_
  query_columns< ::kpk::data::Person, id_pgsql, A >::name;

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::series_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  series (A::table_name, "\"pass_series\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::number_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  number (A::table_name, "\"pass_number\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::date_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  date (A::table_name, "\"pass_date\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::org_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  org (A::table_name, "\"pass_org\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::orgCode_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_::
  orgCode (A::table_name, "\"pass_orgCode\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::passport_class_
  query_columns< ::kpk::data::Person, id_pgsql, A >::passport;

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::inn_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::
  inn (A::table_name, "\"inn\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::snils_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::
  snils (A::table_name, "\"snils\"", 0);

  template <typename A>
  const typename query_columns< ::kpk::data::Person, id_pgsql, A >::member_type_
  query_columns< ::kpk::data::Person, id_pgsql, A >::
  member (A::table_name, "\"idMember\"", 0);
}

#include "Person-odb.ixx"

#include <odb/post.hxx>

#endif // PERSON_ODB_HXX
