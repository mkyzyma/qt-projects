#ifndef LOANOPER_H
#define LOANOPER_H

#include <memory>

#include <odb/core.hxx>

#include "data_global.h"

#include "DbObject.h"
#include "LoanPaymentValue.h"
#include "Payment.h"



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

class Loan;

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
                const LoanPaymentType &type,
                const PayType &payType = PayType::cash,
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
    std::shared_ptr<Loan> loan() const;

    /*!
     * \brief Установить займ
     * \param loan - займ
     */
    void loan(const std::shared_ptr<Loan> &loan);

    /*!
     * \brief Вид операции
     * \return Вид операции
     */
    LoanPaymentType type() const;
private:
    LoanPayment();
    friend class odb::access;

    #pragma db id auto
    ulong _id;

    LoanPaymentValue _plan;
    LoanPaymentValue _fact;
    LoanPaymentType _type;

    #pragma db not_null
    #pragma db column("idLoan")
    std::shared_ptr<Loan> _loan;
};

/*!
 * \brief Указатель на операцию по займу
 */
using LoanPaymentPtr = std::shared_ptr<LoanPayment>;

}
}

#include "Loan.h"

#endif // LOANOPER_H
