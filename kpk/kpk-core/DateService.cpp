#include "DateService.h"

namespace kpk{
namespace core{

DateService::
DateService(QObject *parent)
    : QObject(parent) {}

DateService::
DateService(const QDate &working)
    : _working(working) {}

QDate DateService::
working() const
{
    return _working;
}

void DateService::
working(const QDate &working)
{
    _working = working;
}

QDate DateService::
current() const
{
    return QDate::currentDate();
}

QDateTime DateService::
currentTime() const
{
    return QDateTime::currentDateTime();
}

}
}
