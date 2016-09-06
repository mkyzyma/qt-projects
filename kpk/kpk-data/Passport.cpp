#include "Passport.h"
namespace kpk
{
namespace data
{
Passport::
Passport()
{ }

QString Passport::
series() const
{
    return _series;
}

void Passport::
series(const QString &series)
{
    _series = series;
}

QString Passport::
number() const
{
    return _number;
}

void Passport::
number(const QString &number)
{
    _number = number;
}

QDate Passport::
date() const
{
    return _date;
}
void Passport::
date(const QDate &date)
{
    _date = date;
}

QString Passport::
org() const
{
    return _org;
}
void Passport::
org(const QString &org)
{
    _org = org;
}

QString Passport::
orgCode() const
{
    return _orgCode;
}
void Passport::
orgCode(const QString &orgCode)
{
    _orgCode = orgCode;
}

QString Passport::
set(QString series, QString number, QDate date, QString org, QString orgCode)
{
    this->series(series);
    this->number(number);
    this->date(date);
    this->org(org);
    this->orgCode(orgCode);
    return full();
}

QString Passport::
full()
{
    return QString("%1 %2 выдан %3 %4 код отд. %5")
            .arg(series())
            .arg(number())
            .arg(date().toString("dd.MM.yyyy"))
            .arg(org())
            .arg(orgCode());
}

QString Passport::
toString()
{
   return full();
}

}
}
