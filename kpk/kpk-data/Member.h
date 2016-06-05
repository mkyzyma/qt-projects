#ifndef MEMBER_H
#define MEMBER_H

#include <QtCore/QObject>
#include <QtCore/QSharedPointer>

#include <odb/core.hxx>

#include "data_global.h"
#include "Person.h"

namespace kpk{
namespace data{


#pragma db object
class DATASHARED_EXPORT Member : public QObject
{
    Q_OBJECT
public:
    explicit Member(QObject *parent = 0);
    explicit Member(QSharedPointer<Person> person,
                    QDate inDate,
                    QSharedPointer<QDate> outDate = QSharedPointer<QDate>(),
                    QObject *parent = 0);
    ulong id() const;

    QDate inDate() const;
    void inDate(const QDate &inDate);

    QSharedPointer<QDate> outDate() const;
    void outDate(const QSharedPointer<QDate> &outDate);

    QSharedPointer<Person> person() const;
    void person(const QSharedPointer<Person> &person);
private:
    friend class odb::access;

    #pragma db id auto
    ulong _id;

    QDate _inDate;

    #pragma db null
    QSharedPointer<QDate> _outDate;

    #pragma db not_null
    #pragma db column("idPerson")
    QSharedPointer<Person> _person;
};


}
}
#endif // MEMBER_H
