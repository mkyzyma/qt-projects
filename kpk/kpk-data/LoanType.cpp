#include "LoanType.h"

namespace kpk{
namespace data{

LoanType::LoanType()
{

}

LoanType::LoanType(QString caption, long rate)
{
    _caption = caption;
    _rate = rate;
}

QString LoanType::caption() const
{
    return _caption;
}

void LoanType::caption(const QString &caption)
{
    _caption = caption;
}

long LoanType::rate() const
{
    return _rate;
}

void LoanType::rate(long rate)
{
    _rate = rate;
}

}
}
