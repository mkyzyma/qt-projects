#include "Bank.h"

namespace kpk{
namespace data{

Bank::
Bank()
{}

Bank::
Bank(const QString &bik, const QString &name)
    : _bik(bik), _name(name)
{}

ulong Bank::
id() const
{
    return _id;
}

QString Bank::
bik() const
{
    return _bik;
}

void Bank::
bik(const QString &bik)
{
    _bik = bik;
}

QString Bank::
name() const
{
    return _name;
}

void Bank::
name(const QString &name)
{
    _name = name;
}

ulong Bank::
cnt() const
{
    return _cnt;
}

void Bank::
incCnt()
{
    _cnt += 1;
}

}
}
