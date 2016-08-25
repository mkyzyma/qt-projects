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


MemberPtr LoanOper::member() const
{
    return _member;
}

void LoanOper::member(const MemberPtr &member)
{
    _member = member;
    _person = member->person();
}

std::shared_ptr<Person> LoanOper::person() const
{
    return _person;
}

LoanPtr LoanOper::loan() const
{
    return _loan;
}

void LoanOper::loan(const LoanPtr &loan)
{
    _loan = loan;
}

}
}
