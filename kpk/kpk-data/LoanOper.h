#ifndef LOANOPER_H
#define LOANOPER_H

#include <QtCore/QSharedPointer>

#include <odb/core.hxx>

#include "data_global.h"

#include "LoanOperValue.h"
#include "Person.h"
#include "Member.h"
#include "Loan.h"

namespace kpk
{
namespace data
{
/*!
 * \brief Операция по займу
 *
 * Операция по займу (оплата или выдача)
 */
#pragma db object
class DATASHARED_EXPORT LoanOper
{
public:
    LoanOper();

    /*!
     * \brief Получить оплату по плану
     * \return Оплата по плану
     */
    LoanOperValue& plan();

    /*!
     * \brief Получить оплату по факту
     * \return Оплата по факту
     */
    LoanOperValue& fact();    

    /*!
     * \brief Получить пайщика
     * \return Пайщик
     */
    QSharedPointer<Member> member() const;    

    /*!
     * \brief Установить пайщика
     * \param member - пайщик
     */
    void member(const QSharedPointer<Member> &member);

    /*!
     * \brief Получить личные данные
     * \return Личные данные
     */
    QSharedPointer<Person> person() const;

    /*!
     * \brief Получить займ
     * \return Займ
     */
    QSharedPointer<Loan> loan() const;

    /*!
     * \brief Установить займ
     * \param loan - займ
     */
    void loan(const QSharedPointer<Loan> &loan);

private:
    friend class odb::access;

#pragma db id auto
    ulong _id;

    LoanOperValue _plan;
    LoanOperValue _fact;

    #pragma db not_null
    #pragma db column("idPerson")
    QSharedPointer<Person> _person;

    #pragma db not_null
    #pragma db column("idMember")
    QSharedPointer<Member> _member;

    #pragma db not_null
    #pragma db column("idLoan")
    QSharedPointer<Loan> _loan;
};

}
}
#endif // LOANOPER_H
