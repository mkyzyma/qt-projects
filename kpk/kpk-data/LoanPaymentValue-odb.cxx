// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "LoanPaymentValue-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/pgsql/traits.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/transaction.hxx>
#include <odb/pgsql/connection.hxx>
#include <odb/pgsql/statement.hxx>
#include <odb/pgsql/statement-cache.hxx>
#include <odb/pgsql/container-statements.hxx>
#include <odb/pgsql/exceptions.hxx>

namespace odb
{
  // LoanPaymentValue
  //

  bool access::composite_value_traits< ::kpk::data::LoanPaymentValue, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // _date
    //
    t[0UL] = 0;

    // _amount
    //
    t[1UL] = 0;

    // _loan
    //
    t[2UL] = 0;

    // _loanDept
    //
    t[3UL] = 0;

    // _prc
    //
    t[4UL] = 0;

    // _prcDept
    //
    t[5UL] = 0;

    // _peni
    //
    t[6UL] = 0;

    return grew;
  }

  void access::composite_value_traits< ::kpk::data::LoanPaymentValue, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (b);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);
    ODB_POTENTIALLY_UNUSED (n);

    // _date
    //
    b[n].type = pgsql::bind::date;
    b[n].buffer = &i._date_value;
    b[n].is_null = &i._date_null;
    n++;

    // _amount
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._amount_value;
    b[n].is_null = &i._amount_null;
    n++;

    // _loan
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._loan_value;
    b[n].is_null = &i._loan_null;
    n++;

    // _loanDept
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._loanDept_value;
    b[n].is_null = &i._loanDept_null;
    n++;

    // _prc
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._prc_value;
    b[n].is_null = &i._prc_null;
    n++;

    // _prcDept
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._prcDept_value;
    b[n].is_null = &i._prcDept_null;
    n++;

    // _peni
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i._peni_value;
    b[n].is_null = &i._peni_null;
    n++;
  }

  bool access::composite_value_traits< ::kpk::data::LoanPaymentValue, id_pgsql >::
  init (image_type& i,
        const value_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // _date
    //
    {
      ::QDate const& v =
        o._date;

      bool is_null (true);
      pgsql::value_traits<
          ::QDate,
          pgsql::id_date >::set_image (
        i._date_value, is_null, v);
      i._date_null = is_null;
    }

    // _amount
    //
    {
      ::Number const& v =
        o._amount;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._amount_value, is_null, v);
      i._amount_null = is_null;
    }

    // _loan
    //
    {
      ::Number const& v =
        o._loan;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._loan_value, is_null, v);
      i._loan_null = is_null;
    }

    // _loanDept
    //
    {
      ::Number const& v =
        o._loanDept;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._loanDept_value, is_null, v);
      i._loanDept_null = is_null;
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

    // _prcDept
    //
    {
      ::Number const& v =
        o._prcDept;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._prcDept_value, is_null, v);
      i._prcDept_null = is_null;
    }

    // _peni
    //
    {
      ::Number const& v =
        o._peni;

      bool is_null (false);
      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_image (
        i._peni_value, is_null, v);
      i._peni_null = is_null;
    }

    return grew;
  }

  void access::composite_value_traits< ::kpk::data::LoanPaymentValue, id_pgsql >::
  init (value_type& o,
        const image_type&  i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // _date
    //
    {
      ::QDate& v =
        o._date;

      pgsql::value_traits<
          ::QDate,
          pgsql::id_date >::set_value (
        v,
        i._date_value,
        i._date_null);
    }

    // _amount
    //
    {
      ::Number& v =
        o._amount;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._amount_value,
        i._amount_null);
    }

    // _loan
    //
    {
      ::Number& v =
        o._loan;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._loan_value,
        i._loan_null);
    }

    // _loanDept
    //
    {
      ::Number& v =
        o._loanDept;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._loanDept_value,
        i._loanDept_null);
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

    // _prcDept
    //
    {
      ::Number& v =
        o._prcDept;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._prcDept_value,
        i._prcDept_null);
    }

    // _peni
    //
    {
      ::Number& v =
        o._peni;

      pgsql::value_traits<
          ::Number,
          pgsql::id_bigint >::set_value (
        v,
        i._peni_value,
        i._peni_null);
    }
  }
}

#include <odb/post.hxx>