#include "LoanOperValue.h"
namespace kpk
{
namespace data
{

LoanOperValue::LoanOperValue()
{

}

QDate LoanOperValue::date() const
{
    return _date;
}

void LoanOperValue::date(const QDate &date)
{
    _date = date;
}

long LoanOperValue::amount() const
{
    return _amount;
}

void LoanOperValue::amount(long amount)
{
    _amount = amount;
}

long LoanOperValue::loan() const
{
    return _loan;
}

void LoanOperValue::loan(long loan)
{
    _loan = loan;
}

long LoanOperValue::loanDept() const
{
    return _loanDept;
}

void LoanOperValue::loanDept(long loanDept)
{
    _loanDept = loanDept;
}

long LoanOperValue::prc() const
{
    return _prc;
}

void LoanOperValue::prc(long prc)
{
    _prc = prc;
}

long LoanOperValue::prcDept() const
{
    return _prcDept;
}

void LoanOperValue::prcDept(long prcDept)
{
    _prcDept = prcDept;
}

long LoanOperValue::peni() const
{
    return _peni;
}

void LoanOperValue::peni(long peni)
{
    _peni = peni;
}

}
}
