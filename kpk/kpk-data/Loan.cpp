#include "Loan.h"

namespace kpk {
namespace data {

Loan::
Loan()
{}

Loan::
Loan(MemberPtr member, LoanTypePtr loanType,
     QDate openDate, QDate closeDate,
     const Number &limit, const Number &rate, int length)
    : MemberInfo(member), _openDate(openDate),
      _closeDate(closeDate), _limit(limit), _rate(rate), _length(length),
      _loanType(loanType)
{}

ulong Loan::
id()
{
   return _id;
}

QDate Loan::
openDate()
{
    return _openDate;
}

void Loan::
openDate(const QDate &val)
{
    _openDate = val;
}

QDate Loan::
closeDate()
{
    return _closeDate;
}

void Loan::
closeDate(const QDate &closeDate)
{
    _closeDate = closeDate;
}

LoanStatus Loan::
status() const
{
    return _status;
}

void Loan::
status(LoanStatus isClosed)
{
    _status = isClosed;
}

Number Loan::
rate() const
{
    return _rate;
}

void Loan::
rate(const Number &rate)
{
    _rate = rate;
}

Number Loan::
limit() const
{
    return _limit;
}

void Loan::
limit(const Number &limit)
{
    _limit = limit;
}

int Loan::
length() const
{
    return _length;
}

void Loan::
length(int length)
{
    _length = length;
}

Number Loan::
sum() const
{
    return _sum;
}

void Loan::
sum(const Number &sum)
{
    _sum = sum;
}

Number Loan::
prc() const
{
    return _prc;
}

void Loan::
prc(const Number &prc)
{
    _prc = prc;
}

Number Loan::
remains() const
{
    return _remains;
}

void Loan::
remains(const Number &remains)
{
    _remains = remains;
}

LoanTypePtr Loan::
loanType() const
{
    return _loanType;
}

void Loan::
loanType(const LoanTypePtr &loanType)
{
    _loanType = loanType;
}

std::shared_ptr<LoanState> Loan::state() const
{
    return _state.lock();
}

void Loan::state(const std::shared_ptr<LoanState> &state)
{
    _state = state;
}

}
}
