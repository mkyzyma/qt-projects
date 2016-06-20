#include "Person.h"

namespace kpk{
namespace data{

Person::Person()
{}

ulong Person::id() const
{
    return _id;
}

Name &Person::name()
{
    return _name;
}

Passport &Person::passport()
{
    return _passport;
}

QString Person::inn() const
{
    return _inn;
}

void Person::inn(const QString &inn)
{
    _inn = inn;
}

QString Person::snils() const
{
    return _snils;
}

void Person::snils(const QString &snils)
{
    _snils = snils;
}

}
}
