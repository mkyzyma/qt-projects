#ifndef LOAN_H
#define LOAN_H

#include <QtCore/QDate>
#include <memory>



#include <odb/core.hxx>

#include "data_global.h"

#include "DbObject.h"
#include "Member.h"
#include "Person.h"
#include "LoanType.h"

namespace kpk {
namespace data {

/*!
 * \brief Займ
 */
#pragma db object
class DATASHARED_EXPORT Loan : public DbObject
{
public:
    Loan();

    /*!
     * \brief Конструктор
     * \param member - пайщик
     * \param loanType - вид займа
     * \param openDate - дата открытия
     * \param closeDate - дата завершения
     * \param limit - лимит кредитования
     * \param rate - ставка
     * \param length - срок
     * \param sum - выданная сумма
     */
    Loan(MemberPtr member, LoanTypePtr loanType,
         QDate openDate, QDate closeDate,
         long limit, long rate, long length, long sum = 0);

    /*!
     * \brief Получить идентификатор
     * \return Идентификатор
     */
    ulong id();

    /*!
     * \brief Получить дату открытия
     * \return Дата открытия
     */
    QDate openDate();

    /*!
     * \brief Установить дату открытия
     * \param openDate - дата открытия
     */
    void openDate(QDate& openDate);

    /*!
     * \brief Получить дату завершения
     * \return Дата завершения
     */
    QDate closeDate();

    /*!
     * \brief Установить дату завершения
     * \param closeDate - дата завершения
     */
    void closeDate(QDate& closeDate);    

    /*!
     * \brief Закрыт ли займ
     * \return Признак закрытия
     */
    bool isClosed() const;

    /*!
     * \brief Установить признак закрытия
     * \param isClosed - признак закрытия
     */
    void isClosed(bool isClosed);

    /*!
     * \brief Получить процентную ставку
     * \return Процентная ставка
     */
    long rate() const;

    /*!
     * \brief Установить процентную ставку
     * \param rate - процентная ставка
     */
    void rate(long rate);

    /*!
     * \brief Получить лимит кредитования
     *
     * Максимальная сумма займа
     * \return Лимит кредитования
     */
    long limit() const;

    /*!
     * \brief Установить лимит кредитования
     *
     * Максимальная сумма займа
     * \param limit - Лимит кредитования
     */
    void limit(long limit);

    /*!
     * \brief Получить срок займа
     * \return Срок займа
     */
    long length() const;

    /*!
     * \brief Установить срок займа
     * \param length - срок займа
     */
    void length(long length);

    /*!
     * \brief Получить выданную сумма
     * \return Выданная сумма
     */
    long sum() const;

    /*!
     * \brief Установить выданную сумму
     * \param sum - выданная сумма
     */
    void sum(long sum);

    /*!
     * \brief Получить начисленную компенсация
     * \return Начисленная компенсация
     */
    long prc() const;

    /*!
     * \brief Установить начисленную компенсация
     * \param prc - начисленная компенсация
     */
    void prc(long prc);

    /*!
     * \brief Получить остаток займа
     * \return остаток займа
     */
    long remains() const;

    /*!
     * \brief Установить остаток займа
     * \param remains - остаток займа
     */
    void remains(long remains);

    /*!
     * \brief Получить пайщика
     * \return Пайщик
     */
    MemberPtr member() const;

    /*!
     * \brief Установить пайщика
     * \param member - пайщик
     */
    void member(const MemberPtr &member);

    /*!
     * \brief Получить личные данные
     * \return личные данные
     */
    PersonPtr person() const;

    /*!
     * \brief Получить вид займа
     * \return Вид займа
     */
    LoanTypePtr loanType() const;

    /*!
     * \brief Установить вид займа
     * \param loanType - вид займа
     */
    void loanType(const LoanTypePtr &loanType);

private:
    friend class  odb::access;

#pragma db id auto
    ulong _id;

    QDate _openDate;
    QDate _closeDate;
    bool _isClosed;
    long _rate;
    long _limit;
    long _length;
    long _sum;
    long _remains;
    long _prc;

    #pragma db not_null
    #pragma db column("idMember")
    MemberPtr _member;

    #pragma db not_null
    #pragma db column("idPerson")
    PersonPtr _person;

    #pragma db not_null
    #pragma db column("idLoanType")
    LoanTypePtr _loanType;
};

/*!
 * \brief Указатель на займ
 */
using LoanPtr = std::shared_ptr<Loan>;

}
}

#endif // LOAN_H
