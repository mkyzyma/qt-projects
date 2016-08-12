#ifndef LOANOPERVALUE_H
#define LOANOPERVALUE_H

#include <QtCore/QDate>
#include <odb/core.hxx>

#include "data_global.h"
namespace kpk
{
namespace data
{

#pragma db value
class DATASHARED_EXPORT LoanOperValue
{
public:
    LoanOperValue();
    QDate date() const;
    void date(const QDate &date);

    long amount() const;
    void amount(long amount);

    long loan() const;
    void loan(long loan);

    long loanDept() const;
    void loanDept(long loanDept);

    long prc() const;
    void prc(long prc);

    long prcDept() const;
    void prcDept(long prcDept);

    long peni() const;
    void peni(long peni);

private:
    friend class odb::access;

    QDate _date;
    long _amount;

    long _loan;
    long _loanDept;

    long _prc;
    long _prcDept;

    long _peni;
};

}
}

#endif // LOANOPERVALUE_H
