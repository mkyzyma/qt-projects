#include "Name.h"

namespace kpk
{
namespace data
{



QString Name::first() const { return _first; }

void Name::first(const QString &first)
{
    _first = first;
    _full = combine();
}

QString Name::last() const { return _last; }

void Name::last(const QString &last)
{
    _last = last;
    _full = combine();
}

QString Name::middle() const { return _middle; }

void Name::middle(const QString &middle)
{
    _middle = middle;
    _full = combine();
}

QString Name::set(const QString &first, const QString &middle, const QString &last)
{
    _first = first; _last = last; _middle = middle;
    _full = combine();
    return _full;
}

QString Name::full() const { return _full; }

QString Name::combine()
{
    QString name = _last;

    if (!_first.isEmpty()){
        name += QString(" %1").arg(_first);
    }
    if (!_middle.isEmpty()){
        name += QString(" %1").arg(_middle);
    }
    return name;
}

QString Name::toString()
{
    return full();
}



}
}
