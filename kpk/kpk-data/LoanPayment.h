#ifndef LOANOPER_H
#define LOANOPER_H

#include <memory>

#include <odb/core.hxx>

#include "data_global.h"

#include "DbObject.h"
#include "LoanPaymentValue.h"
#include "Payment.h"
#include "Person.h"
#include "Member.h"
#include "Loan.h"

namespace kpk {
namespace data {

/*!
 * \brief Вид операции по займу
 */
enum class LoanPaymentType
{
    payment, ///<\brief Оплата
    issuance, ///<\brief Выдача
};

/*!
 * \brief Операция по займу
 *
 * Операция по займу (оплата или выдача)
 */
#pragma db object
class DATASHARED_EXPORT LoanPayment : public Payment
{
public:
    LoanPayment(const QDate &date,
                const PaymentType &paymentType = PaymentType::cash,
                const BankPtr &bank = nullptr);
    /*!
     * \brief Получить оплату по плану
     * \return Оплата по плану
     */
    LoanPaymentValue& plan();

    /*!
     * \brief Получить оплату по факту
     * \return Оплата по факту
     */
    LoanPaymentValue& fact();

    /*!
     * \brief Получить займ
     * \return Займ
     */
    LoanPtr loan() const;

    /*!
     * \brief Установить займ
     * \param loan - займ
     */
    void loan(const LoanPtr &loan);

private:
    LoanPayment();
    friend class odb::access;

    #pragma db id auto
    ulong _id;

    LoanPaymentValue _plan;
    LoanPaymentValue _fact;

    #pragma db not_null
    #pragma db column("idLoan")
    LoanPtr _loan;
};

/*!
 * \brief Указатель на операцию по займу
 */
using LoanPaymentPtr = std::shared_ptr<LoanPayment>;

}
}
#endif // LOANOPER_H
