#include "LoanPayment.h"
namespace kpk
{
namespace data
{
LoanPayment::
LoanPayment()
{}

LoanPayment::
LoanPayment(const QDate &date,
            const PaymentType &paymentType,
            const BankPtr &bank)
    : Payment(date, paymentType, bank)
{
    _fact.date(date);
}

LoanPaymentValue& LoanPayment::
plan()
{
    return _plan;
}

LoanPaymentValue& LoanPayment::
fact()
{
    return _fact;
}

LoanPtr LoanPayment::
loan() const
{
    return _loan;
}

void LoanPayment::
loan(const LoanPtr &loan)
{
    _loan = loan;
}

}
}
