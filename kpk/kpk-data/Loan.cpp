#include "Loan.h"

namespace kpk {
namespace data {

Loan::Loan()
{

}

Loan::Loan(MemberPtr member, LoanTypePtr loanType,
           QDate openDate, QDate closeDate,
           long limit, long rate, long length)
    : _member(member), _person(member->person()), _openDate(openDate),
      _closeDate(closeDate), _limit(limit), _rate(rate), _length(length),
      _loanType(loanType)
{}

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

void Loan::closeDate(QDate &closeDate)
{
    _closeDate = closeDate;
}

MemberPtr Loan::member() const
{
    return _member;
}

void Loan::member(const MemberPtr &member)
{
    _member = member;
    _person = member->person();
}

PersonPtr Loan::person() const
{
    return _person;
}

LoanTypePtr Loan::loanType() const
{
    return _loanType;
}

void Loan::loanType(const LoanTypePtr &loanType)
{
    _loanType = loanType;
}

LoanState Loan::state() const
{
    return _state;
}

void Loan::state(LoanState isClosed)
{
    _state = isClosed;
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
