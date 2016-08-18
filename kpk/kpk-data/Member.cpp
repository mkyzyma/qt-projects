#include "Member.h"

namespace kpk{
namespace data{

Member::Member()
{}

Member::Member(std::shared_ptr<Person> person,
               QDate inDate,
               std::shared_ptr<QDate> outDate)
    : _inDate(inDate), _outDate(outDate), _person(person), _exitReason(ER_NONE)
{}

ulong Member::id() const { return _id; }

QDate Member::inDate() const { return _inDate; }
void Member::inDate(const QDate &inDate) { _inDate = inDate; }

std::shared_ptr<QDate> Member::outDate() const { return _outDate; }
void Member::outDate(const std::shared_ptr<QDate> &outDate) { _outDate = outDate; }

std::shared_ptr<Person> Member::person() const
{ return _person; }

void Member::person(const std::shared_ptr<Person> &person){ _person = person; }

ExitReason Member::exitReason() const { return _exitReason; }

void Member::exitReason(const ExitReason &exitReason) { _exitReason = exitReason; }

}
}
