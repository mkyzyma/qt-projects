#ifndef LOANSERVICE_H
#define LOANSERVICE_H

#include <QObject>
#include <QDate>
#include <QString>

#include "kpk-data/Loan.h"
#include "kpk-data/Member.h"
#include "kpk-data/LoanType.h"
#include "kpk-data/Payment.h"
#include "kpk-data/LoanState.h"
#include "kpk-data/LoanPayment.h"
#include "kpk-data/Bank.h"

#include "kpk-data/LoanType-odb.hxx"

#include "core_global.h"
namespace kpk{
namespace core{

using LoanTypeResult = odb::result<data::LoanType>;

/*!
 * \brief Служба управления займами
 */
class CORESHARED_EXPORT LoanService : public QObject
{
    Q_OBJECT
public:
    explicit LoanService(QObject *parent = 0);

    data::LoanPtr open(data::MemberPtr member, data::LoanTypePtr loanType,
                       QDate openDate,
                       Number limit, Number rate, int length);

    data::LoanPtr get(ulong id);

    void issue(const data::LoanPtr& loan, QDate date, Number amount,
               data::PayType payType = data::PayType::cash,
               data::BankPtr bank = nullptr);    

    QDate getCloseDate(QDate openDate, long length);

    LoanTypeResult loanTypes();
    data::LoanTypePtr getLoanType(ulong id);
private:
    data::LoanPaymentPtr
    createIssuence(const data::LoanPtr &loan, QDate date, Number amount,
                   data::PayType payType = data::PayType::cash,
                   data::BankPtr bank = nullptr);

    data::LoanStatePtr
    createState(const data::LoanPtr &loan, QDate date,
                Number rate, Number remains, Number sum,
                int length, QDate closeDate,
                const data::StateReason &reason);

    data::LoanStatePtr
    copyLastState(const data::LoanPtr &loan, QDate date,
                  data::StateReason reason);
};

}
}

#endif // LOANSERVICE_H
