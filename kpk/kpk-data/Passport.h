#ifndef PASSPORT_H
#define PASSPORT_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QDate>

#include <odb/core.hxx>

#ifdef ODB_COMPILER
#   include "../kpk-lib/ToString.h"
#else
#   include "kpk-lib/ToString.h"
#endif

#include "data_global.h"

namespace kpk
{
namespace data
{

#pragma db value
class DATASHARED_EXPORT Passport : ToString
{    
public:
    explicit Passport();

    QString series() const;
    void series(const QString &series);

    QString number() const;
    void number(const QString &number);

    QDate date() const;
    void date(const QDate &date);

    QString org() const;
    void org(const QString &org);

    QString orgCode() const;
    void orgCode(const QString &orgCode);

    QString set(QString series, QString number, QDate date,
                QString org, QString orgCode);

    QString full();
private:
    friend class odb::access;

    #pragma db type("char(4)")
    QString _series;
    #pragma db type("char(6)")
    QString _number;
    QDate _date;
    QString _org;
    #pragma db type("char(6)")
    QString _orgCode;


public:
    QString toString();
};

}
}

#endif // PASSPORT_H
