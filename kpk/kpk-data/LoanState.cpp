#include "LoanState.h"

namespace kpk {
namespace data {

LoanState::
LoanState()
{}

ulong LoanState::
id() const
{ return _id; }

QDate LoanState::
startDate() const
{ return _startDate; }

void LoanState::
startDate(const QDate &startDate)
{ _startDate = startDate; }

QDate LoanState::
endDate() const
{ return _endDate; }

void LoanState::
endDate(const QDate &endDate)
{ _endDate = endDate; }

Number LoanState::
rate() const
{ return _rate; }

void LoanState::
rate(const Number &rate)
{ _rate = rate; }

Number LoanState::
sum() const
{ return _sum; }

void LoanState::
sum(const Number &sum)
{ _sum = sum; }

Number LoanState::
remains() const
{ return _remains; }

void LoanState::
remains(const Number &remains)
{ _remains = remains; }

int LoanState::
length() const
{ return _length; }

void LoanState::
length(int length)
{ _length = length; }

QDate LoanState::
closeDate() const
{ return _closeDate; }

void LoanState::
closeDate(const QDate &closeDate)
{ _closeDate = closeDate; }

StateReason LoanState::
reson() const
{ return _reason; }

void LoanState::
reson(const StateReason &reason)
{ _reason = reason; }

LoanPtr LoanState::
loan() const
{ return _loan; }

void LoanState::
loan(const LoanPtr &loan)
{ _loan = loan; }

LoanPaymentPtr LoanState::payment() const
{
    return _payment;
}

void LoanState::payment(const LoanPaymentPtr &payment)
{
    _payment = payment;
}

}
}
