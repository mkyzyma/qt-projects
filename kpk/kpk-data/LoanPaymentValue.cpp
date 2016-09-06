#include "LoanPaymentValue.h"
namespace kpk
{
namespace data
{

LoanPaymentValue::
LoanPaymentValue()
{}

QDate LoanPaymentValue::
date() const
{
    return _date;
}

void LoanPaymentValue::
date(const QDate &date)
{
    _date = date;
}

Number LoanPaymentValue::
amount() const
{
    return _amount;
}

void LoanPaymentValue::
amount(const Number &amount)
{
    _amount = amount;
}

Number LoanPaymentValue::
loan() const
{
    return _loan;
}

void LoanPaymentValue::
loan(const Number &loan)
{
    _loan = loan;
}

Number LoanPaymentValue::
loanDept() const
{
    return _loanDept;
}

void LoanPaymentValue::
loanDept(const Number &loanDept)
{
    _loanDept = loanDept;
}

Number LoanPaymentValue::
prc() const
{
    return _prc;
}

void LoanPaymentValue::
prc(const Number &prc)
{
    _prc = prc;
}

Number LoanPaymentValue::
prcDept() const
{
    return _prcDept;
}

void LoanPaymentValue::
prcDept(const Number &prcDept)
{
    _prcDept = prcDept;
}

Number LoanPaymentValue::
peni() const
{
    return _peni;
}

void LoanPaymentValue::
peni(const Number &peni)
{
    _peni = peni;
}



}
}
