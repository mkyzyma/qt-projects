#include "LoanService.h"

#include "kpk-data/Loan-odb.hxx"

#include "kpk-data/LoanPayment.h"
#include "kpk-data/LoanPayment-odb.hxx"
#include "kpk-data/LoanState-odb.hxx"

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

void LoanService::
issue(const LoanPtr& loan, QDate date, Number amount,
      PayType payType, BankPtr bank)
{
    auto p = createIssuence(loan, date, amount, payType, bank);

    p->setCreateInfo(Core()->date()->currentTime(), Core()->auth()->user());
    Core()->db()->persist(p);

    if(loan->state())
        loan->state()->endDate(date);

    auto state = copyLastState(loan, date.addDays(1),
                               StateReason::issuance);

    state->payment(p);
    state->sum(state->sum() + amount);
    state->remains(state->remains() + amount);

    state->setCreateInfo(Core()->date()->currentTime(), Core()->auth()->user());
    Core()->db()->persist(state);

    loan->sum(state->sum());
    loan->remains(state->remains());

    loan->state(state);
    loan->status(LoanStatus::active);

    Core()->db()->update(loan);
}

LoanPaymentPtr LoanService::
createIssuence(const LoanPtr &loan, QDate date, Number amount,
               PayType payType, BankPtr bank)
{
    auto p = std::make_shared<LoanPayment>(date, LoanPaymentType::issuance,
                                           payType, bank);
    p->plan().date(date);
    p->fact().date(date);
    p->fact().amount(amount);
    p->loan(loan);
    p->member(loan->member());

    return p;
}

LoanStatePtr LoanService::
createState(const LoanPtr &loan, QDate date,
            Number rate, Number remains, Number sum,
            int length, QDate closeDate, const StateReason &reason)
{
    auto s = std::make_shared<LoanState>();

    s->startDate(date);
    s->endDate(QDate(9999,12,31));
    s->rate(rate);
    s->sum(sum);
    s->remains(remains);
    s->length(length);
    s->closeDate(closeDate);
    s->reson(reason);
    s->loan(loan);

    return s;
}

LoanStatePtr LoanService::
copyLastState(const LoanPtr &loan, QDate date, StateReason reason)
{
    auto s = loan->state();

    if(s) return createState(loan, date, s->rate(), s->remains(), s->sum(),
                             s->length(), s->closeDate(), reason);


    return createState(loan, date, loan->rate(), 0, 0,
                       loan->length(), loan->closeDate(), reason);

}

QDate LoanService::
getCloseDate(QDate openDate, long length)
{
    auto closeDate = openDate;
    for(int m = 0; m < length; m++)
    {
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
