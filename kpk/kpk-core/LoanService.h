#ifndef LOANSERVICE_H
#define LOANSERVICE_H

#include <QObject>
#include <QDate>
#include <QString>

#include "kpk-data/Loan.h"
#include "kpk-data/Member.h"
#include "kpk-data/LoanType.h"

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



    QDate getCloseDate(QDate openDate, long length);

    LoanTypeResult loanTypes();
    data::LoanTypePtr getLoanType(ulong id);
};

}
}

#endif // LOANSERVICE_H
