#include "LoanType.h"

namespace kpk{
namespace data{

LoanType::
LoanType()
{

}

LoanType::
LoanType(QString caption, Number rate)
{
    _caption = caption;
    _rate = rate;
}

QString LoanType::
caption() const
{
    return _caption;
}

void LoanType::
caption(const QString &caption)
{
    _caption = caption;
}

Number LoanType::
rate() const
{
    return _rate;
}

void LoanType::
rate(const Number &rate)
{
    _rate = rate;
}

}
}
