#ifndef LOANOPER_H
#define LOANOPER_H

#include <memory>

#include <odb/core.hxx>

#include "data_global.h"

#include "DbObject.h"
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
class DATASHARED_EXPORT LoanOper : public DbObject
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
    MemberPtr member() const;

    /*!
     * \brief Установить пайщика
     * \param member - пайщик
     */
    void member(const MemberPtr &member);

    /*!
     * \brief Получить личные данные
     * \return Личные данные
     */
    PersonPtr person() const;

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
    friend class odb::access;

#pragma db id auto
    ulong _id;

    LoanOperValue _plan;
    LoanOperValue _fact;

    #pragma db not_null
    #pragma db column("idPerson")
    PersonPtr _person;

    #pragma db not_null
    #pragma db column("idMember")
    MemberPtr _member;

    #pragma db not_null
    #pragma db column("idLoan")
    LoanPtr _loan;
};

/*!
 * \brief Указатель на операцию по займу
 */
using LoanOperPtr = std::shared_ptr<LoanOper>;

}
}
#endif // LOANOPER_H
