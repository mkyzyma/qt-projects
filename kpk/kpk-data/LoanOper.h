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
    std::shared_ptr<Member> member() const;

    /*!
     * \brief Установить пайщика
     * \param member - пайщик
     */
    void member(const std::shared_ptr<Member> &member);

    /*!
     * \brief Получить личные данные
     * \return Личные данные
     */
    std::shared_ptr<Person> person() const;

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

private:
    friend class odb::access;

#pragma db id auto
    ulong _id;

    LoanOperValue _plan;
    LoanOperValue _fact;

    #pragma db not_null
    #pragma db column("idPerson")
    std::shared_ptr<Person> _person;

    #pragma db not_null
    #pragma db column("idMember")
    std::shared_ptr<Member> _member;

    #pragma db not_null
    #pragma db column("idLoan")
    std::shared_ptr<Loan> _loan;
};

}
}
#endif // LOANOPER_H
