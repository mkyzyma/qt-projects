#include "Loan.h"

namespace kpk {
namespace data {

Loan::Loan()
{

}

Loan::Loan(QSharedPointer<Member> member,
           QDate openDate, QDate closeDate,
           long limit, long rate, long length)
{
    _member = member;
    _person = member->person();
    _openDate = openDate;
    _closeDate = closeDate;
    _limit = limit;
    _rate = rate;
    _length = length;
    _sum = 0;
    _prc = 0;
}

ulong Loan::id()
{
   return _id;
}

QDate Loan::openDate()
{
    return _openDate;
}

void Loan::openDate(QDate &val)
{
    _openDate = val;
}

QDate Loan::closeDate()
{
    return _closeDate;
}

void Loan::closeDate(QDate &val)
{
    _closeDate = val;
}

QSharedPointer<Member> Loan::member() const
{
    return _member;
}

void Loan::member(const QSharedPointer<Member> &val)
{
    _member = val;
}

QSharedPointer<Person> Loan::person() const
{
    return _person;
}

void Loan::person(const QSharedPointer<Person> &val)
{
    _person = val;
}

bool Loan::isClosed() const
{
    return _isClosed;
}

void Loan::isClosed(bool isClosed)
{
    _isClosed = isClosed;
}

long Loan::rate() const
{
    return _rate;
}

void Loan::rate(long rate)
{
    _rate = rate;
}

long Loan::limit() const
{
    return _limit;
}

void Loan::limit(long limit)
{
    _limit = limit;
}

long Loan::length() const
{
    return _length;
}

void Loan::length(long length)
{
    _length = length;
}

long Loan::sum() const
{
    return _sum;
}

void Loan::sum(long sum)
{
    _sum = sum;
}

long Loan::prc() const
{
    return _prc;
}

void Loan::prc(long prc)
{
    _prc = prc;
}

long Loan::remains() const
{
    return _remains;
}

void Loan::remains(long remains)
{
    _remains = remains;
}

}
}
