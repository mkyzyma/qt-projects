// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "Loan-odb.hxx"

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
  // Loan
  //

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  persist_statement_name[] = "persist_kpk_data_Loan";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  find_statement_name[] = "find_kpk_data_Loan";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  update_statement_name[] = "update_kpk_data_Loan";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  erase_statement_name[] = "erase_kpk_data_Loan";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  query_statement_name[] = "query_kpk_data_Loan";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  erase_query_statement_name[] = "erase_query_kpk_data_Loan";

  const unsigned int access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  persist_statement_types[] =
  {
    pgsql::bool_oid,
    pgsql::timestamp_oid,
    pgsql::int8_oid,
    pgsql::timestamp_oid,
    pgsql::int8_oid,
    pgsql::date_oid,
    pgsql::date_oid,
    pgsql::int4_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int4_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid
  };

  const unsigned int access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  find_statement_types[] =
  {
    pgsql::int8_oid
  };

  const unsigned int access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  update_statement_types[] =
  {
    pgsql::bool_oid,
    pgsql::timestamp_oid,
    pgsql::int8_oid,
    pgsql::timestamp_oid,
    pgsql::int8_oid,
    pgsql::date_oid,
    pgsql::date_oid,
    pgsql::int4_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int4_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid
  };

  const char alias_traits<  ::kpk::data::Member,
    id_pgsql,
    access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::member_tag>::
  table_name[] = "\"idMember\"";

  const char alias_traits<  ::kpk::data::Person,
    id_pgsql,
    access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::person_tag>::
  table_name[] = "\"idPerson\"";

  const char alias_traits<  ::kpk::data::LoanType,
    id_pgsql,
    access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::loanType_tag>::
  table_name[] = "\"idLoanType\"";

  struct access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      pgsql::connection&,
      image_type&,
      id_image_type&,
      pgsql::binding&,
      pgsql::binding&,
      pgsql::native_binding&,
      const unsigned int*)
    {
    }
  };

  access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::id_type
  access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  id (const id_image_type& i)
  {
    pgsql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      pgsql::value_traits<
          ::ulong,
          pgsql::id_bigint >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::id_type
  access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  id (const image_type& i)
  {
    pgsql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      pgsql::value_traits<
          ::ulong,
          pgsql::id_bigint >::set_value (
        id,
        i._id_value,
        i._id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // DbObject base
    //
    if (object_traits_impl< ::kpk::data::DbObject, id_pgsql >::grow (
          i, t + 0UL))
      grew = true;

    // _id
    //
    t[5UL] = 0;

    // _openDate
    //
    t[6UL] = 0;

    // _closeDate
    //
    t[7UL] = 0;

    // _state
    //
    t[8UL] = 0;

    // _rate
    //
    t[9UL] = 0;

    // _limit
    //
    t[10UL] = 0;

    // _length
    //
    t[11UL] = 0;

    // _sum
    //
    t[12UL] = 0;

    // _remains
    //
    t[13UL] = 0;

    // _prc
    //
    t[14UL] = 0;

    // _member
    //
    t[15UL] = 0;

    // _person
    //
    t[16UL] = 0;

    // _loanType
    //
    t[17UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // DbObject base
    //
    object_traits_impl< ::kpk::data::DbObject, id_pgsql >::bind (b + n, i, sk);
    n += 5UL;

    // _id
    //
    if (sk != statement_insert && sk != statement_update)
    {
      b[n].type = pgsql::bind::bigint;
      b[n].buffer = &i._id_value;
      b[n].is_null = &i._id_null;
      n++;
    }

    // _openDate
    //
    b[n].type = pgsql::bind::date;
    b[n].buffer = &i._openDate_value;
    b[n].is_null = &i._openDate_null;
    n++;

    // _closeDate
    //
    b[n].type = pgsql::bind::date;
    b[n].buffer = &i._closeDate_value;
    b[n].is_null = &i._closeDate_null;
    n++;

    // _state
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._state_value;
    b[n].is_null = &i._state_null;
    n++;

    // _rate
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._rate_value;
    b[n].is_null = &i._rate_null;
    n++;

    // _limit
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._limit_value;
    b[n].is_null = &i._limit_null;
    n++;

    // _length
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i._length_value;
    b[n].is_null = &i._length_null;
    n++;

    // _sum
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._sum_value;
    b[n].is_null = &i._sum_null;
    n++;

    // _remains
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._remains_value;
    b[n].is_null = &i._remains_null;
    n++;

    // _prc
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._prc_value;
    b[n].is_null = &i._prc_null;
    n++;

    // _member
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._member_value;
    b[n].is_null = &i._member_null;
    n++;

    // _person
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._person_value;
    b[n].is_null = &i._person_null;
    n++;

    // _loanType
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._loanType_value;
    b[n].is_null = &i._loanType_null;
    n++;
  }

  void access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  bind (pgsql::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // DbObject base
    //
    if (object_traits_impl< ::kpk::data::DbObject, id_pgsql >::init (i, o, sk))
      grew = true;

    // _openDate
    //
    {
      ::QDate const& v =
        o._openDate;

      bool is_null (true);
      pgsql::value_traits<
          ::QDate,
          pgsql::id_date >::set_image (
        i._openDate_value, is_null, v);
      i._openDate_null = is_null;
    }

    // _closeDate
    //
    {
      ::QDate const& v =
        o._closeDate;

      bool is_null (true);
      pgsql::value_traits<
          ::QDate,
          pgsql::id_date >::set_image (
        i._closeDate_value, is_null, v);
      i._closeDate_null = is_null;
    }

    // _state
    //
    {
      ::kpk::data::LoanState const& v =
        o._state;

      bool is_null (false);
      pgsql::value_traits<
          ::kpk::data::LoanState,
          pgsql::id_integer >::set_image (
        i._state_value, is_null, v);
      i._state_null = is_null;
    }

    // _rate
    //
    {
      ::Number const& v =
        o._rate;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._rate_value, is_null, v);
      i._rate_null = is_null;
    }

    // _limit
    //
    {
      ::Number const& v =
        o._limit;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._limit_value, is_null, v);
      i._limit_null = is_null;
    }

    // _length
    //
    {
      int const& v =
        o._length;

      bool is_null (false);
      pgsql::value_traits<
          int,
          pgsql::id_integer >::set_image (
        i._length_value, is_null, v);
      i._length_null = is_null;
    }

    // _sum
    //
    {
      ::Number const& v =
        o._sum;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._sum_value, is_null, v);
      i._sum_null = is_null;
    }

    // _remains
    //
    {
      ::Number const& v =
        o._remains;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._remains_value, is_null, v);
      i._remains_null = is_null;
    }

    // _prc
    //
    {
      ::Number const& v =
        o._prc;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._prc_value, is_null, v);
      i._prc_null = is_null;
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

    // _loanType
    //
    {
      ::kpk::data::LoanTypePtr const& v =
        o._loanType;

      typedef object_traits< ::kpk::data::LoanType > obj_traits;
      typedef odb::pointer_traits< ::kpk::data::LoanTypePtr > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_image (
          i._loanType_value, is_null, id);
        i._loanType_null = is_null;
      }
      else
        throw null_pointer ();
    }

    return grew;
  }

  void access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // DbObject base
    //
    object_traits_impl< ::kpk::data::DbObject, id_pgsql >::init (o, i, db);

    // _id
    //
    {
      ::ulong& v =
        o._id;

      pgsql::value_traits<
          ::ulong,
          pgsql::id_bigint >::set_value (
        v,
        i._id_value,
        i._id_null);
    }

    // _openDate
    //
    {
      ::QDate& v =
        o._openDate;

      pgsql::value_traits<
          ::QDate,
          pgsql::id_date >::set_value (
        v,
        i._openDate_value,
        i._openDate_null);
    }

    // _closeDate
    //
    {
      ::QDate& v =
        o._closeDate;

      pgsql::value_traits<
          ::QDate,
          pgsql::id_date >::set_value (
        v,
        i._closeDate_value,
        i._closeDate_null);
    }

    // _state
    //
    {
      ::kpk::data::LoanState& v =
        o._state;

      pgsql::value_traits<
          ::kpk::data::LoanState,
          pgsql::id_integer >::set_value (
        v,
        i._state_value,
        i._state_null);
    }

    // _rate
    //
    {
      ::Number& v =
        o._rate;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._rate_value,
        i._rate_null);
    }

    // _limit
    //
    {
      ::Number& v =
        o._limit;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._limit_value,
        i._limit_null);
    }

    // _length
    //
    {
      int& v =
        o._length;

      pgsql::value_traits<
          int,
          pgsql::id_integer >::set_value (
        v,
        i._length_value,
        i._length_null);
    }

    // _sum
    //
    {
      ::Number& v =
        o._sum;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._sum_value,
        i._sum_null);
    }

    // _remains
    //
    {
      ::Number& v =
        o._remains;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._remains_value,
        i._remains_null);
    }

    // _prc
    //
    {
      ::Number& v =
        o._prc;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._prc_value,
        i._prc_null);
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

    // _loanType
    //
    {
      ::kpk::data::LoanTypePtr& v =
        o._loanType;

      typedef object_traits< ::kpk::data::LoanType > obj_traits;
      typedef odb::pointer_traits< ::kpk::data::LoanTypePtr > ptr_traits;

      if (i._loanType_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_value (
          id,
          i._loanType_value,
          i._loanType_null);

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

  void access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      pgsql::value_traits<
          ::ulong,
          pgsql::id_bigint >::set_image (
        i.id_value, is_null, id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::persist_statement[] =
  "INSERT INTO \"Loan\" "
  "(\"isDeleted\", "
  "\"deleteTime\", "
  "\"deletedBy\", "
  "\"createTime\", "
  "\"idUser\", "
  "\"id\", "
  "\"openDate\", "
  "\"closeDate\", "
  "\"state\", "
  "\"rate\", "
  "\"limit\", "
  "\"length\", "
  "\"sum\", "
  "\"remains\", "
  "\"prc\", "
  "\"idMember\", "
  "\"idPerson\", "
  "\"idLoanType\") "
  "VALUES "
  "($1, $2, $3, $4, $5, DEFAULT, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15, $16, $17) "
  "RETURNING \"id\"";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::find_statement[] =
  "SELECT "
  "\"Loan\".\"isDeleted\", "
  "\"Loan\".\"deleteTime\", "
  "\"Loan\".\"deletedBy\", "
  "\"Loan\".\"createTime\", "
  "\"Loan\".\"idUser\", "
  "\"Loan\".\"id\", "
  "\"Loan\".\"openDate\", "
  "\"Loan\".\"closeDate\", "
  "\"Loan\".\"state\", "
  "\"Loan\".\"rate\", "
  "\"Loan\".\"limit\", "
  "\"Loan\".\"length\", "
  "\"Loan\".\"sum\", "
  "\"Loan\".\"remains\", "
  "\"Loan\".\"prc\", "
  "\"Loan\".\"idMember\", "
  "\"Loan\".\"idPerson\", "
  "\"Loan\".\"idLoanType\" "
  "FROM \"Loan\" "
  "WHERE \"Loan\".\"id\"=$1";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::update_statement[] =
  "UPDATE \"Loan\" "
  "SET "
  "\"isDeleted\"=$1, "
  "\"deleteTime\"=$2, "
  "\"deletedBy\"=$3, "
  "\"createTime\"=$4, "
  "\"idUser\"=$5, "
  "\"openDate\"=$6, "
  "\"closeDate\"=$7, "
  "\"state\"=$8, "
  "\"rate\"=$9, "
  "\"limit\"=$10, "
  "\"length\"=$11, "
  "\"sum\"=$12, "
  "\"remains\"=$13, "
  "\"prc\"=$14, "
  "\"idMember\"=$15, "
  "\"idPerson\"=$16, "
  "\"idLoanType\"=$17 "
  "WHERE \"id\"=$18";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::erase_statement[] =
  "DELETE FROM \"Loan\" "
  "WHERE \"id\"=$1";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::query_statement[] =
  "SELECT\n"
  "\"Loan\".\"isDeleted\",\n"
  "\"Loan\".\"deleteTime\",\n"
  "\"Loan\".\"deletedBy\",\n"
  "\"Loan\".\"createTime\",\n"
  "\"Loan\".\"idUser\",\n"
  "\"Loan\".\"id\",\n"
  "\"Loan\".\"openDate\",\n"
  "\"Loan\".\"closeDate\",\n"
  "\"Loan\".\"state\",\n"
  "\"Loan\".\"rate\",\n"
  "\"Loan\".\"limit\",\n"
  "\"Loan\".\"length\",\n"
  "\"Loan\".\"sum\",\n"
  "\"Loan\".\"remains\",\n"
  "\"Loan\".\"prc\",\n"
  "\"Loan\".\"idMember\",\n"
  "\"Loan\".\"idPerson\",\n"
  "\"Loan\".\"idLoanType\"\n"
  "FROM \"Loan\"\n"
  "LEFT JOIN \"User\" AS \"deletedBy\" ON \"deletedBy\".\"id\"=\"Loan\".\"deletedBy\"\n"
  "LEFT JOIN \"User\" AS \"idUser\" ON \"idUser\".\"id\"=\"Loan\".\"idUser\"\n"
  "LEFT JOIN \"Member\" AS \"idMember\" ON \"idMember\".\"id\"=\"Loan\".\"idMember\"\n"
  "LEFT JOIN \"Person\" AS \"idPerson\" ON \"idPerson\".\"id\"=\"Loan\".\"idPerson\"\n"
  "LEFT JOIN \"LoanType\" AS \"idLoanType\" ON \"idLoanType\".\"id\"=\"Loan\".\"idLoanType\"";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::erase_query_statement[] =
  "DELETE FROM \"Loan\"";

  const char access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::table_name[] =
  "\"Loan\"";

  void access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj._id = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;
    using pgsql::update_statement;

    callback (db, obj, callback_event::pre_update);

    pgsql::transaction& tr (pgsql::transaction::current ());
    pgsql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj._id);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  erase (database& db, const id_type& id)
  {
    using namespace pgsql;

    ODB_POTENTIALLY_UNUSED (db);

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::pointer_type
  access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  find (database& db, const id_type& id)
  {
    using namespace pgsql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  reload (database& db, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj._id);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace pgsql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::object_type >
  access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  query (database&, const query_base_type& q)
  {
    using namespace pgsql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += "\n";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        sts.connection (),
        query_statement_name,
        text,
        true,
        true,
        q.parameter_types (),
        q.parameter_count (),
        q.parameters_binding (),
        imb));

    st->execute ();
    st->deallocate ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) pgsql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::kpk::data::Loan, id_pgsql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      erase_query_statement_name,
      text,
      q.parameter_types (),
      q.parameter_count (),
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
