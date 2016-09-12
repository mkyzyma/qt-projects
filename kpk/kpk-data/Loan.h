#ifndef LOAN_H
#define LOAN_H

#include <QtCore/QDate>
#include <memory>

#include <odb/core.hxx>

#include "data_global.h"

#include "type.h"
#include "DbObject.h"
#include "MemberInfo.h"
#include "LoanType.h"

namespace kpk {
namespace data {

/*!
 * \brief Состояние займа
 */
enum class LoanStatus
{
    inactive,   ///<\brief В ожидании
    active,     ///<\brief Выдан
    closed,     ///<\brief Закрыт
    order       ///<\brief Исполнительный лист
};


class LoanState;
/*!
 * \brief Займ
 */
#pragma db object
class DATASHARED_EXPORT Loan :
        public DbObject, public MemberInfo
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
     */
    Loan(MemberPtr member, LoanTypePtr loanType,
         QDate openDate, QDate closeDate,
         const Number &limit, const Number &rate, int length);

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
    void openDate(const QDate &openDate);

    /*!
     * \brief Получить дату завершения
     * \return Дата завершения
     */
    QDate closeDate();

    /*!
     * \brief Установить дату завершения
     * \param closeDate - дата завершения
     */
    void closeDate(const QDate &closeDate);

    /*!
     * \brief Получить состояние
     * \return Состояние
     */
    LoanStatus status() const;

    /*!
     * \brief Установить состояние
     * \param state - состояние
     */
    void status(LoanStatus status);

    /*!
     * \brief Получить процентную ставку
     * \return Процентная ставка
     */
    Number rate() const;

    /*!
     * \brief Установить процентную ставку
     * \param rate - процентная ставка
     */
    void rate(const Number &rate);

    /*!
     * \brief Получить лимит кредитования
     *
     * Максимальная сумма займа
     * \return Лимит кредитования
     */
    Number limit() const;

    /*!
     * \brief Установить лимит кредитования
     *
     * Максимальная сумма займа
     * \param limit - Лимит кредитования
     */
    void limit(const  Number &limit);

    /*!
     * \brief Получить срок займа
     * \return Срок займа
     */
    int length() const;

    /*!
     * \brief Установить срок займа
     * \param length - срок займа
     */
    void length(int length);

    /*!
     * \brief Получить выданную сумма
     * \return Выданная сумма
     */
    Number sum() const;

    /*!
     * \brief Установить выданную сумму
     * \param sum - выданная сумма
     */
    void sum(const Number &sum);

    /*!
     * \brief Получить начисленную компенсация
     * \return Начисленная компенсация
     */
    Number prc() const;

    /*!
     * \brief Установить начисленную компенсация
     * \param prc - начисленная компенсация
     */
    void prc(const Number &prc);

    /*!
     * \brief Получить остаток займа
     * \return остаток займа
     */
    Number remains() const;

    /*!
     * \brief Установить остаток займа
     * \param remains - остаток займа
     */
    void remains(const Number &remains);    

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

    std::shared_ptr<LoanState> state() const;
    void state(const std::shared_ptr<LoanState> &state);

private:
    friend class  odb::access;

    #pragma db id auto
    ulong _id;

    QDate _openDate;
    QDate _closeDate;
    LoanStatus _status = LoanStatus::inactive;
    Number _rate;
    Number _limit;
    int _length;
    Number _sum = 0;
    Number _remains = 0;
    Number _prc = 0;    

    #pragma db not_null
    #pragma db column("idLoanType")
    LoanTypePtr _loanType;

    #pragma db null
    #pragma db column("idState")
    std::weak_ptr<LoanState> _state;
};

/*!
 * \brief Указатель на займ
 */
using LoanPtr = std::shared_ptr<Loan>;

}
}

#include "LoanState.h"

#endif // LOAN_H
