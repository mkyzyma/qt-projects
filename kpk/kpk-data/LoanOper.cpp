#include "LoanOper.h"
namespace kpk
{
namespace data
{

LoanOper::LoanOper()
{

}

LoanOperValue& LoanOper::plan()
{
    return _plan;
}

LoanOperValue& LoanOper::fact()
{
    return _fact;
}

QSharedPointer<Person> LoanOper::person() const
{
    return _person;
}

void LoanOper::person(const QSharedPointer<Person> &person)
{
    _person = person;
}

QSharedPointer<Member> LoanOper::member() const
{
    return _member;
}

void LoanOper::member(const QSharedPointer<Member> &member)
{
    _member = member;
}

QSharedPointer<Loan> LoanOper::loan() const
{
    return _loan;
}

void LoanOper::loan(const QSharedPointer<Loan> &loan)
{
    _loan = loan;
}

}
}
