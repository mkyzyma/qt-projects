#ifndef LOANOPERVALUE_H
#define LOANOPERVALUE_H

#include <QtCore/QDate>
#include <odb/core.hxx>

#include "data_global.h"
#include "type.h"
namespace kpk
{
namespace data
{

/*!
 * \brief Данные операции по займу
 */
#pragma db value
class DATASHARED_EXPORT LoanPaymentValue
{
public:
    LoanPaymentValue();

    /*!
     * \brief Получить дату
     * \return дата
     */
    QDate date() const;

    /*!
     * \brief Установить дату
     * \param date дата
     */
    void date(const QDate &date);

    /*!
     * \brief Получить плную сумму оплаты
     * \return Полная сумма оплаты
     */
    Number amount() const;

    /*!
     * \brief Установить полную сумму оплаты
     * \param amount - полная сумма оплаты
     */
    void amount(const Number &amount);

    /*!
     * \brief Получить основной долг
     * \details Получить сумму оплаты основного долга
     * \return Сумма оплаты основного долга
     */
    Number loan() const;

    /*!
     * \brief Установить основной долг
     * \details Установить сумму оплаты основного долга
     * \param loan - cумма оплаты основного долга
     */
    void loan(const Number &loan);

    /*!
     * \brief Получить задолженность по осноному долгу
     * \details Получить сумму оплаты задолженности по осноному долгу
     * \return Задолженность по осноному долгу
     */
    Number loanDept() const;

    /*!
     * \brief Установить задолженность по осноному долгу
     * \details Установить сумму оплаты задолженности по осноному долгу
     * \param loanDept - задолженность по осноному долгу
     */
    void loanDept(const Number &loanDept);

    /*!
     * \brief Получить компенсацию
     * \details Получить сумму оплаты компенсации
     * \return Сумма оплаты компенсации
     */
    Number prc() const;

    /*!
     * \brief Установить компенсацию
     * \details Установить сумму оплаты компенсации
     * \param prc - сумма оплаты компенсации
     */
    void prc(const Number &prc);

    /*!
     * \brief Получить задолженностиь по компенсации
     * \details Получить сумму оплаты задолженности по компенсации
     * \return Задолженность по компенсации
     */
    Number prcDept() const;

    /*!
     * \brief Установить задолженность по компенсации
     * \details Установить сумму оплаты задолженности по компенсации
     * \param prcDept - задолженность по компенсации
     */
    void prcDept(const Number &prcDept);

    /*!
     * \brief Получить неустойку
     * \return неустойка
     */
    Number peni() const;

    /*!
     * \brief Установить неустойку
     * \param peni - неустойка
     */
    void peni(const Number &peni);


private:
    friend class odb::access;

    QDate _date;
    Number _amount;

    Number _loan;
    Number _loanDept;

    Number _prc;
    Number _prcDept;

    Number _peni;
};

}
}

#endif // LOANOPERVALUE_H
