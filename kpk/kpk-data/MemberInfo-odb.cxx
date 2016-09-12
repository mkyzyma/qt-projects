// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "MemberInfo-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/pgsql/traits.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/transaction.hxx>
#include <odb/pgsql/connection.hxx>
#include <odb/pgsql/statement.hxx>
#include <odb/pgsql/statement-cache.hxx>
#include <odb/pgsql/simple-object-statements.hxx>
#include <odb/pgsql/container-statements.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/pgsql/simple-object-result.hxx>

namespace odb
{
  // MemberInfo
  //

  const char alias_traits<  ::kpk::data::Person,
    id_pgsql,
    access::object_traits_impl< ::kpk::data::MemberInfo, id_pgsql >::person_tag>::
  table_name[] = "\"idPerson\"";

  const char alias_traits<  ::kpk::data::Member,
    id_pgsql,
    access::object_traits_impl< ::kpk::data::MemberInfo, id_pgsql >::member_tag>::
  table_name[] = "\"idMember\"";

  bool access::object_traits_impl< ::kpk::data::MemberInfo, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // _person
    //
    t[0UL] = 0;

    // _member
    //
    t[1UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::kpk::data::MemberInfo, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // _person
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._person_value;
    b[n].is_null = &i._person_null;
    n++;

    // _member
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._member_value;
    b[n].is_null = &i._member_null;
    n++;
  }

  bool access::object_traits_impl< ::kpk::data::MemberInfo, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // _person
    //
    {
      ::kpk::data::PersonPtr const& v =
        o._person;

      typedef object_traits< ::kpk::data::Person > obj_traits;
      typedef odb::pointer_traits< ::kpk::data::PersonPtr > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_image (
          i._person_value, is_null, id);
        i._person_null = is_null;
      }
      else
        throw null_pointer ();
    }

    // _member
    //
    {
      ::kpk::data::MemberPtr const& v =
        o._member;

      typedef object_traits< ::kpk::data::Member > obj_traits;
      typedef odb::pointer_traits< ::kpk::data::MemberPtr > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_image (
          i._member_value, is_null, id);
        i._member_null = is_null;
      }
      else
        throw null_pointer ();
    }

    return grew;
  }

  void access::object_traits_impl< ::kpk::data::MemberInfo, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // _person
    //
    {
      ::kpk::data::PersonPtr& v =
        o._person;

      typedef object_traits< ::kpk::data::Person > obj_traits;
      typedef odb::pointer_traits< ::kpk::data::PersonPtr > ptr_traits;

      if (i._person_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_value (
          id,
          i._person_value,
          i._person_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<pgsql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }

    // _member
    //
    {
      ::kpk::data::MemberPtr& v =
        o._member;

      typedef object_traits< ::kpk::data::Member > obj_traits;
      typedef odb::pointer_traits< ::kpk::data::MemberPtr > ptr_traits;

      if (i._member_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_value (
          id,
          i._member_value,
          i._member_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<pgsql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }
  }
}

#include <odb/post.hxx>