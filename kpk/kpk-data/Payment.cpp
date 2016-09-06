#include "Payment.h"
namespace kpk{
namespace data{

Payment::
Payment()
{}

Payment::
Payment(const QDate &date,
        const PaymentType &paymentType,
        const BankPtr &bank)
    :_date(date), _paymentType(paymentType), _bank(bank)
{}

QDate Payment::
date() const
{
    return _date;
}

void Payment::
date(const QDate &date)
{
    _date = date;
}

PaymentType Payment::
paymentType() const
{
    return _paymentType;
}

void Payment::
paymentType(const PaymentType &paymentType)
{
    _paymentType = paymentType;
}

BankPtr Payment::
bank() const
{
    return _bank;
}

void Payment::
bank(const BankPtr &bank)
{
    _bank = bank;
}

}
}
