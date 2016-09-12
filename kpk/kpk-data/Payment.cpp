#include "Payment.h"
namespace kpk{
namespace data{

Payment::
Payment()
{}

Payment::
Payment(const QDate &date,
        const PayType &paymentType,
        const BankPtr &bank)
    :_date(date), _payType(paymentType), _bank(bank)
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

PayType Payment::
payType() const
{
    return _payType;
}

void Payment::
payType(const PayType &paymentType)
{
    _payType = paymentType;
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
