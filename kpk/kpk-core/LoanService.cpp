#include "LoanService.h"

#include "kpk-data/Loan-odb.hxx"


#include "Core.h"

namespace kpk{
namespace core{

using namespace data;

using LoanTypeQuery = odb::query<LoanType>;

LoanService::
LoanService(QObject *parent) :
    QObject(parent) {}

LoanPtr LoanService::
open(MemberPtr member, LoanTypePtr loanType, QDate openDate,
     Number limit, Number rate, int length)
{
    /*auto lim = Core()->numberFormString(limit);
    auto r = Core()->numberFormString(rate);*/

    auto closeDate = getCloseDate(openDate, length);
    auto l(std::make_shared<Loan>(member, loanType, openDate, closeDate,
                                  limit, rate, length));

    l->setCreateInfo(Core()->date()->currentTime(), Core()->auth()->user());

    Core()->db()->persist(l);

    return l;
}

LoanPtr LoanService::
get(ulong id)
{
    return Core()->db()->load<Loan>(id);
}



QDate LoanService::
getCloseDate(QDate openDate, long length)
{
    auto closeDate = openDate;
    for(int m = 0; m < length; m++){
        closeDate = closeDate.addMonths(1);
        if (closeDate.dayOfWeek() == 7)
            closeDate.addDays(1);
    }

    return closeDate;
}

LoanTypeResult LoanService::
loanTypes()
{
    auto q(!LoanTypeQuery::isDeleted);
    return Core()->db()->query<LoanType>(q);
}

LoanTypePtr LoanService::
getLoanType(ulong id)
{
    return Core()->db()->load<LoanType>(id);
}



}
}
