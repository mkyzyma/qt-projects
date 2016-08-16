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

#pragma db object
class DATASHARED_EXPORT LoanOper
{
public:
    LoanOper();
    LoanOperValue& plan();
    LoanOperValue& fact();

    QSharedPointer<Person> person() const;
    void person(const QSharedPointer<Person> &person);

    QSharedPointer<Member> member() const;
    void member(const QSharedPointer<Member> &member);

    QSharedPointer<Loan> loan() const;
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
