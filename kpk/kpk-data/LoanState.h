#ifndef LOANSTATE_H
#define LOANSTATE_H

#include <odb/core.hxx>

#include "data_global.h"

#include "type.h"
#include "DbObject.h"
#include "Loan.h"
#include "LoanPayment.h"

namespace kpk {
namespace data {

enum class StateReason {
    payment, ///<\brief Оплата
    issuance, ///<\brief Выдача
    rateChange, ///<\brief Смена процентной ставки
    extend ///<\brief Продление
};

#pragma db object
class DATASHARED_EXPORT LoanState : public DbObject
{
public:
    LoanState();

    ulong id() const;

    QDate startDate() const;
    void startDate(const QDate &startDate);

    QDate endDate() const;
    void endDate(const QDate &endDate);

    Number rate() const;
    void rate(const Number &rate);

    Number sum() const;
    void sum(const Number &sum);

    Number remains() const;
    void remains(const Number &remains);

    int length() const;
    void length(int length);

    QDate closeDate() const;
    void closeDate(const QDate &closeDate);

    StateReason reson() const;
    void reson(const StateReason &reason);

    LoanPtr loan() const;
    void loan(const LoanPtr &loan);

    LoanPaymentPtr payment() const;
    void payment(const LoanPaymentPtr &payment);

private:
    friend class  odb::access;

#pragma db id auto
    ulong _id;

    QDate _startDate;
    QDate _endDate;

    Number _rate = 0.0;
    Number _remains = 0.0;
    Number _sum = 0.0;

    int _length = 0;
    QDate _closeDate;

    StateReason _reason;

    #pragma db not_null
    #pragma db column("idLoan")
    LoanPtr _loan;

    #pragma db not_null
    #pragma db column("idLoanPayment")
    LoanPaymentPtr _payment;
};

using LoanStatePtr = std::shared_ptr<LoanState>;

}
}

#endif // LOANSTATE_H
