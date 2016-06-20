#ifndef NAME_H
#define NAME_H

#include <QtCore/QObject>
#include <QtCore/QString>

#include <odb/core.hxx>

/*#ifdef ODB_COMPILER
#   include "../../common/ToString.h"
#else
#   include "../../common/ToString.h"
#endif*/

#include "data_global.h"
namespace kpk
{
namespace data
{

#pragma db value
class DATASHARED_EXPORT Name : public QObject//, common::ToString
{
    Q_OBJECT
public:
    explicit Name(QObject *parent = 0)
        : QObject(parent){}

    explicit Name(QString first, QString middle, QString last, QObject *parent = 0)
        : QObject(parent), _first(first), _middle(middle), _last(last)
    {}

    QString first() const;
    void first(const QString &first);
    QString last() const;
    void last(const QString &last);
    QString middle() const;
    void middle(const QString &middle);
    QString set(const QString &first, const QString &middle, const QString &last);
    QString full() const;
    QString toString();

private:
    friend class odb::access;

    QString combine();

    QString _first;
    QString _middle;
    QString _last;
    QString _full;
};

}
}
#endif // NAME_H
