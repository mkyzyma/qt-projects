#include "LoanService.h"

#include "kpk-data/Loan-odb.hxx"


#include "Core.h"

namespace kpk{
namespace core{

using namespace data;

using LoanTypeQuery = odb::query<LoanType>;

LoanService::LoanService(QObject *parent) : QObject(parent)
{

}

LoanPtr LoanService::open(MemberPtr member, LoanTypePtr loanType, QDate openDate,
                          long limit, long rate, long length)
{
    auto closeDate = getCloseDate(openDate, length);
    auto l(std::make_shared<Loan>(member, loanType, openDate, closeDate,
                                  limit, rate, length));

    Core()->db()->persist(l);

    return l;
}

LoanPtr LoanService::get(long id)
{
    return Core()->db()->load<Loan>(id);
}



QDate LoanService::getCloseDate(QDate openDate, long length)
{
    auto closeDate = openDate;
    for(int m = 0; m < length; m++){
        closeDate = closeDate.addMonths(1);
        if (closeDate.dayOfWeek() == 7)
            closeDate.addDays(1);
    }

    return closeDate;
}



}
}
