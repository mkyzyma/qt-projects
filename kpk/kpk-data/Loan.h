#ifndef LOAN_H
#define LOAN_H

#include <QtCore/QDate>
#include <QtCore/QSharedPointer>



#include <odb/core.hxx>

#include "data_global.h"

#include "Member.h"
#include "Person.h"

namespace kpk {
namespace data {

#pragma db object
class DATASHARED_EXPORT Loan
{
public:
    Loan();
    Loan(QSharedPointer<Member> member,
         QDate openDate, QDate closeDate, long limit, long rate, long length);
    ulong id();

    QDate openDate();
    void openDate(QDate& openDate);

    QDate closeDate();
    void closeDate(QDate& val);


    QSharedPointer<Member> member() const;
    void member(const QSharedPointer<Member> &val);

    QSharedPointer<Person> person() const;
    void person(const QSharedPointer<Person> &person);

    bool isClosed() const;
    void isClosed(bool isClosed);

    long rate() const;
    void rate(long rate);

    long limit() const;
    void limit(long limit);

    long length() const;
    void length(long length);

    long sum() const;
    void sum(long sum);

    long prc() const;
    void prc(long prc);

    long remains() const;
    void remains(long remains);

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
    QSharedPointer<Member> _member;

    #pragma db not_null
    #pragma db column("idPerson")
    QSharedPointer<Person> _person;
};

}
}

#endif // LOAN_H
