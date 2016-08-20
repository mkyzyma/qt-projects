// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "LoanOper-odb.hxx"

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
  // LoanOper
  //

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  persist_statement_name[] = "persist_kpk_data_LoanOper";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  find_statement_name[] = "find_kpk_data_LoanOper";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  update_statement_name[] = "update_kpk_data_LoanOper";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  erase_statement_name[] = "erase_kpk_data_LoanOper";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  query_statement_name[] = "query_kpk_data_LoanOper";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  erase_query_statement_name[] = "erase_query_kpk_data_LoanOper";

  const unsigned int access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  persist_statement_types[] =
  {
    pgsql::bool_oid,
    pgsql::date_oid,
    pgsql::date_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::date_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid
  };

  const unsigned int access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  find_statement_types[] =
  {
    pgsql::int8_oid
  };

  const unsigned int access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  update_statement_types[] =
  {
    pgsql::bool_oid,
    pgsql::date_oid,
    pgsql::date_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::date_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid
  };

  const char alias_traits<  ::kpk::data::Person,
    id_pgsql,
    access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::person_tag>::
  table_name[] = "\"idPerson\"";

  const char alias_traits<  ::kpk::data::Member,
    id_pgsql,
    access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::member_tag>::
  table_name[] = "\"idMember\"";

  const char alias_traits<  ::kpk::data::Loan,
    id_pgsql,
    access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::loan_tag>::
  table_name[] = "\"idLoan\"";

  struct access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::extra_statement_cache_type
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

  access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::id_type
  access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::id_type
  access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  bool access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // IsDeleted base
    //
    if (object_traits_impl< ::kpk::data::IsDeleted, id_pgsql >::grow (
          i, t + 0UL))
      grew = true;

    // _id
    //
    t[2UL] = 0;

    // _plan
    //
    if (composite_value_traits< ::kpk::data::LoanOperValue, id_pgsql >::grow (
          i._plan_value, t + 3UL))
      grew = true;

    // _fact
    //
    if (composite_value_traits< ::kpk::data::LoanOperValue, id_pgsql >::grow (
          i._fact_value, t + 10UL))
      grew = true;

    // _person
    //
    t[17UL] = 0;

    // _member
    //
    t[18UL] = 0;

    // _loan
    //
    t[19UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // IsDeleted base
    //
    object_traits_impl< ::kpk::data::IsDeleted, id_pgsql >::bind (b + n, i, sk);
    n += 2UL;

    // _id
    //
    if (sk != statement_insert && sk != statement_update)
    {
      b[n].type = pgsql::bind::bigint;
      b[n].buffer = &i._id_value;
      b[n].is_null = &i._id_null;
      n++;
    }

    // _plan
    //
    composite_value_traits< ::kpk::data::LoanOperValue, id_pgsql >::bind (
      b + n, i._plan_value, sk);
    n += 7UL;

    // _fact
    //
    composite_value_traits< ::kpk::data::LoanOperValue, id_pgsql >::bind (
      b + n, i._fact_value, sk);
    n += 7UL;

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

    // _loan
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._loan_value;
    b[n].is_null = &i._loan_null;
    n++;
  }

  void access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  bind (pgsql::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // IsDeleted base
    //
    if (object_traits_impl< ::kpk::data::IsDeleted, id_pgsql >::init (i, o, sk))
      grew = true;

    // _plan
    //
    {
      ::kpk::data::LoanOperValue const& v =
        o._plan;

      composite_value_traits< ::kpk::data::LoanOperValue, id_pgsql >::init (
        i._plan_value,
        v,
        sk);
    }

    // _fact
    //
    {
      ::kpk::data::LoanOperValue const& v =
        o._fact;

      composite_value_traits< ::kpk::data::LoanOperValue, id_pgsql >::init (
        i._fact_value,
        v,
        sk);
    }

    // _person
    //
    {
      ::std::shared_ptr< ::kpk::data::Person > const& v =
        o._person;

      typedef object_traits< ::kpk::data::Person > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::kpk::data::Person > > ptr_traits;

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
      ::std::shared_ptr< ::kpk::data::Member > const& v =
        o._member;

      typedef object_traits< ::kpk::data::Member > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::kpk::data::Member > > ptr_traits;

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

    // _loan
    //
    {
      ::std::shared_ptr< ::kpk::data::Loan > const& v =
        o._loan;

      typedef object_traits< ::kpk::data::Loan > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::kpk::data::Loan > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_image (
          i._loan_value, is_null, id);
        i._loan_null = is_null;
      }
      else
        throw null_pointer ();
    }

    return grew;
  }

  void access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // IsDeleted base
    //
    object_traits_impl< ::kpk::data::IsDeleted, id_pgsql >::init (o, i, db);

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

    // _plan
    //
    {
      ::kpk::data::LoanOperValue& v =
        o._plan;

      composite_value_traits< ::kpk::data::LoanOperValue, id_pgsql >::init (
        v,
        i._plan_value,
        db);
    }

    // _fact
    //
    {
      ::kpk::data::LoanOperValue& v =
        o._fact;

      composite_value_traits< ::kpk::data::LoanOperValue, id_pgsql >::init (
        v,
        i._fact_value,
        db);
    }

    // _person
    //
    {
      ::std::shared_ptr< ::kpk::data::Person >& v =
        o._person;

      typedef object_traits< ::kpk::data::Person > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::kpk::data::Person > > ptr_traits;

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
      ::std::shared_ptr< ::kpk::data::Member >& v =
        o._member;

      typedef object_traits< ::kpk::data::Member > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::kpk::data::Member > > ptr_traits;

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

    // _loan
    //
    {
      ::std::shared_ptr< ::kpk::data::Loan >& v =
        o._loan;

      typedef object_traits< ::kpk::data::Loan > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::kpk::data::Loan > > ptr_traits;

      if (i._loan_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        pgsql::value_traits<
            obj_traits::id_type,
            pgsql::id_bigint >::set_value (
          id,
          i._loan_value,
          i._loan_null);

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

  void access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::persist_statement[] =
  "INSERT INTO \"LoanOper\" "
  "(\"isDeleted\", "
  "\"deleteDate\", "
  "\"id\", "
  "\"plan_date\", "
  "\"plan_amount\", "
  "\"plan_loan\", "
  "\"plan_loanDept\", "
  "\"plan_prc\", "
  "\"plan_prcDept\", "
  "\"plan_peni\", "
  "\"fact_date\", "
  "\"fact_amount\", "
  "\"fact_loan\", "
  "\"fact_loanDept\", "
  "\"fact_prc\", "
  "\"fact_prcDept\", "
  "\"fact_peni\", "
  "\"idPerson\", "
  "\"idMember\", "
  "\"idLoan\") "
  "VALUES "
  "($1, $2, DEFAULT, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15, $16, $17, $18, $19) "
  "RETURNING \"id\"";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::find_statement[] =
  "SELECT "
  "\"LoanOper\".\"isDeleted\", "
  "\"LoanOper\".\"deleteDate\", "
  "\"LoanOper\".\"id\", "
  "\"LoanOper\".\"plan_date\", "
  "\"LoanOper\".\"plan_amount\", "
  "\"LoanOper\".\"plan_loan\", "
  "\"LoanOper\".\"plan_loanDept\", "
  "\"LoanOper\".\"plan_prc\", "
  "\"LoanOper\".\"plan_prcDept\", "
  "\"LoanOper\".\"plan_peni\", "
  "\"LoanOper\".\"fact_date\", "
  "\"LoanOper\".\"fact_amount\", "
  "\"LoanOper\".\"fact_loan\", "
  "\"LoanOper\".\"fact_loanDept\", "
  "\"LoanOper\".\"fact_prc\", "
  "\"LoanOper\".\"fact_prcDept\", "
  "\"LoanOper\".\"fact_peni\", "
  "\"LoanOper\".\"idPerson\", "
  "\"LoanOper\".\"idMember\", "
  "\"LoanOper\".\"idLoan\" "
  "FROM \"LoanOper\" "
  "WHERE \"LoanOper\".\"id\"=$1";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::update_statement[] =
  "UPDATE \"LoanOper\" "
  "SET "
  "\"isDeleted\"=$1, "
  "\"deleteDate\"=$2, "
  "\"plan_date\"=$3, "
  "\"plan_amount\"=$4, "
  "\"plan_loan\"=$5, "
  "\"plan_loanDept\"=$6, "
  "\"plan_prc\"=$7, "
  "\"plan_prcDept\"=$8, "
  "\"plan_peni\"=$9, "
  "\"fact_date\"=$10, "
  "\"fact_amount\"=$11, "
  "\"fact_loan\"=$12, "
  "\"fact_loanDept\"=$13, "
  "\"fact_prc\"=$14, "
  "\"fact_prcDept\"=$15, "
  "\"fact_peni\"=$16, "
  "\"idPerson\"=$17, "
  "\"idMember\"=$18, "
  "\"idLoan\"=$19 "
  "WHERE \"id\"=$20";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::erase_statement[] =
  "DELETE FROM \"LoanOper\" "
  "WHERE \"id\"=$1";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::query_statement[] =
  "SELECT\n"
  "\"LoanOper\".\"isDeleted\",\n"
  "\"LoanOper\".\"deleteDate\",\n"
  "\"LoanOper\".\"id\",\n"
  "\"LoanOper\".\"plan_date\",\n"
  "\"LoanOper\".\"plan_amount\",\n"
  "\"LoanOper\".\"plan_loan\",\n"
  "\"LoanOper\".\"plan_loanDept\",\n"
  "\"LoanOper\".\"plan_prc\",\n"
  "\"LoanOper\".\"plan_prcDept\",\n"
  "\"LoanOper\".\"plan_peni\",\n"
  "\"LoanOper\".\"fact_date\",\n"
  "\"LoanOper\".\"fact_amount\",\n"
  "\"LoanOper\".\"fact_loan\",\n"
  "\"LoanOper\".\"fact_loanDept\",\n"
  "\"LoanOper\".\"fact_prc\",\n"
  "\"LoanOper\".\"fact_prcDept\",\n"
  "\"LoanOper\".\"fact_peni\",\n"
  "\"LoanOper\".\"idPerson\",\n"
  "\"LoanOper\".\"idMember\",\n"
  "\"LoanOper\".\"idLoan\"\n"
  "FROM \"LoanOper\"\n"
  "LEFT JOIN \"Person\" AS \"idPerson\" ON \"idPerson\".\"id\"=\"LoanOper\".\"idPerson\"\n"
  "LEFT JOIN \"Member\" AS \"idMember\" ON \"idMember\".\"id\"=\"LoanOper\".\"idMember\"\n"
  "LEFT JOIN \"Loan\" AS \"idLoan\" ON \"idLoan\".\"id\"=\"LoanOper\".\"idLoan\"";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::erase_query_statement[] =
  "DELETE FROM \"LoanOper\"";

  const char access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::table_name[] =
  "\"LoanOper\"";

  void access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  void access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  void access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::pointer_type
  access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  bool access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  bool access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  bool access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  result< access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::object_type >
  access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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

  unsigned long long access::object_traits_impl< ::kpk::data::LoanOper, id_pgsql >::
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
