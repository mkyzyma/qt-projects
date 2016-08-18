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


std::shared_ptr<Member> LoanOper::member() const
{
    return _member;
}

void LoanOper::member(const std::shared_ptr<Member> &member)
{
    _member = member;
    _person = member->person();
}

std::shared_ptr<Person> LoanOper::person() const
{
    return _person;
}

std::shared_ptr<Loan> LoanOper::loan() const
{
    return _loan;
}

void LoanOper::loan(const std::shared_ptr<Loan> &loan)
{
    _loan = loan;
}

}
}
