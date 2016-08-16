#ifndef MEMBER_H
#define MEMBER_H

#include <QtCore/QSharedPointer>

#include <odb/core.hxx>

#include "data_global.h"
#include "Person.h"

namespace kpk{
namespace data{


enum ExitReason
{
    ER_NONE,
    ER_EXIT,
    ER_KICK,
    ER_DEATH
};

#pragma db object
class DATASHARED_EXPORT Member
{
public:    
    Member();
    Member(QSharedPointer<Person> person,
           QDate inDate,
           QSharedPointer<QDate> outDate = QSharedPointer<QDate>());
    ulong id() const;

    QDate inDate() const;
    void inDate(const QDate &inDate);

    QSharedPointer<QDate> outDate() const;
    void outDate(const QSharedPointer<QDate> &outDate);

    QSharedPointer<Person> person() const;
    void person(const QSharedPointer<Person> &person);

    ExitReason exitReason() const;
    void exitReason(const ExitReason &exitReason);
private:
    friend class odb::access;

#pragma db id auto
    ulong _id;

    QDate _inDate;

    #pragma db null
    QSharedPointer<QDate> _outDate;

    ExitReason _exitReason;

    #pragma db not_null
    #pragma db column("idPerson")
    QSharedPointer<Person> _person;
};


}
}
#endif // MEMBER_H
