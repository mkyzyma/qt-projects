#include "LoanGarantor.h"

namespace kpk {
namespace data {

LoanGarantor::
LoanGarantor()
{

}

LoanGarantor::
LoanGarantor(QDate addDate,
             LoanPtr loan,
             PersonPtr person)
    : _addDate(addDate), _person(person), _loan(loan)
{}

ulong LoanGarantor::
id() const
{
    return _id;
}

QDate LoanGarantor::
addDate() const
{
    return _addDate;
}

PersonPtr LoanGarantor::
person() const
{
    return _person;
}

LoanPtr LoanGarantor::
loan() const
{
    return _loan;
}

}
}
