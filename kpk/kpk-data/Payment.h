#ifndef PAYMENT_H
#define PAYMENT_H

#include <memory>
#include <QtCore/QDateTime>
#include <QtCore/QString>

#include <odb/core.hxx>
#include "DbObject.h"
#include "MemberInfo.h"
#include "Bank.h"

#include "data_global.h"
namespace kpk {
namespace data {

/*!
 * \brief Вид оплаты
 */
enum class PaymentType{
    cash, ///<\brief Наличные
    bank, ///<\brief Банк
    inner ///<\brief Внутренние
};


/*!
 * \brief Платеж
 *
 * Базовый класс для платежей
 */
#pragma db object abstract
class DATASHARED_EXPORT Payment
        : public DbObject, public MemberInfo
{
public:
    Payment(const QDate &date,
            const PaymentType &paymentType,
            const BankPtr &bank = nullptr);

    /*!
     * \brief Получить дату платежа
     * \return Дата платежа
     */
    QDate date() const;

    /*!
     * \brief Установить дату платежа
     * \param date - Дата платежа
     */
    void date(const QDate &date);

    /*!
     * \brief Получить вид оплаты
     * \return Вид оплаты
     */
    PaymentType paymentType() const;

    /*!
     * \brief Установить вид оплаты
     * \param paymentType - вид оплаты
     */
    void paymentType(const PaymentType &paymentType);

    /*!
     * \brief Получить банк
     * \return Банк
     */
    BankPtr bank() const;

    /*!
     * \brief Установить банк
     * \param bank - банк
     */
    void bank(const BankPtr &bank);    
protected:
    Payment();

    QDate _date;
    PaymentType _paymentType;

    #pragma db null
    BankPtr _bank;
};


}
}
#endif // PAYMENT_H
