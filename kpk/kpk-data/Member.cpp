#include "Member.h"

namespace kpk{
namespace data{

Member::Member(QObject *parent) : QObject(parent)
{

}

Member::Member(QSharedPointer<Person> person,
               QDate inDate,
               QSharedPointer<QDate> outDate,
               QObject *parent)
    : QObject(parent), _inDate(inDate), _outDate(outDate), _person(person)
{}

ulong Member::id() const { return _id; }

QDate Member::inDate() const { return _inDate; }
void Member::inDate(const QDate &inDate) { _inDate = inDate; }

QSharedPointer<QDate> Member::outDate() const { return _outDate; }
void Member::outDate(const QSharedPointer<QDate> &outDate) { _outDate = outDate; }

QSharedPointer<Person>
Member::person() const { return _person; }

void Member::person(const QSharedPointer<Person> &person){ _person = person; }


}
}
