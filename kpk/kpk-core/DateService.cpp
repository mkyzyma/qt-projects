#include "DateService.h"

namespace kpk{
namespace core{

DateService::DateService()
{

}

DateService::DateService(const QDate &current)
    : _current(current)
{

}

QDate DateService::current() const
{
    return _current;
}

void DateService::current(const QDate &current)
{
    _current = current;
}

QDate DateService::system() const
{
    return QDate::currentDate();
}



}
}
