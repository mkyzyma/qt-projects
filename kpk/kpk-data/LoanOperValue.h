#ifndef LOANOPERVALUE_H
#define LOANOPERVALUE_H

#include <QtCore/QDate>
#include <odb/core.hxx>

#include "data_global.h"
namespace kpk
{
namespace data
{
/*!
 * \brief Данные операции по займу
 */
#pragma db value
class DATASHARED_EXPORT LoanOperValue
{
public:
    LoanOperValue();

    /*!
     * \brief Получить дату
     * \return дата
     */
    QDate date() const;

    /*!
     * \brief Установить дату
     * \param дата
     */
    void date(const QDate &date);

    /*!
     * \brief Получить плную сумму оплаты
     * \return Полная сумма оплаты
     */
    long amount() const;

    /*!
     * \brief Установить полную сумму оплаты
     * \param amount - полная сумма оплаты
     */
    void amount(long amount);

    /*!
     * \brief Получить основной долг
     * \details Получить сумму оплаты основного долга
     * \return Сумма оплаты основного долга
     */
    long loan() const;

    /*!
     * \brief Установить основной долг
     * \details Установить сумму оплаты основного долга
     * \param loan - cумма оплаты основного долга
     */
    void loan(long loan);

    /*!
     * \brief Получить задолженность по осноному долгу
     * \details Получить сумму оплаты задолженности по осноному долгу
     * \return Задолженность по осноному долгу
     */
    long loanDept() const;

    /*!
     * \brief Установить задолженность по осноному долгу
     * \details Установить сумму оплаты задолженности по осноному долгу
     * \param loanDept - задолженность по осноному долгу
     */
    void loanDept(long loanDept);

    /*!
     * \brief Получить компенсацию
     * \details Получить сумму оплаты компенсации
     * \return Сумма оплаты компенсации
     */
    long prc() const;

    /*!
     * \brief Установить компенсацию
     * \details Установить сумму оплаты компенсации
     * \param prc - сумма оплаты компенсации
     */
    void prc(long prc);

    /*!
     * \brief Получить задолженностиь по компенсации
     * \details Получить сумму оплаты задолженности по компенсации
     * \return Задолженность по компенсации
     */
    long prcDept() const;

    /*!
     * \brief Установить задолженность по компенсации
     * \details Установить сумму оплаты задолженности по компенсации
     * \param prcDept - задолженность по компенсации
     */
    void prcDept(long prcDept);

    /*!
     * \brief Получить неустойку
     * \return неустойка
     */
    long peni() const;

    /*!
     * \brief Установить неустойку
     * \param peni - неустойка
     */
    void peni(long peni);

private:
    friend class odb::access;

    QDate _date;
    long _amount;

    long _loan;
    long _loanDept;

    long _prc;
    long _prcDept;

    long _peni;
};

}
}

#endif // LOANOPERVALUE_H
