#ifndef LOAN_H
#define LOAN_H

#include <QtCore/QDate>

#include "data_global.h"

namespace kpk {
namespace data {

class DATASHARED_EXPORT Loan
{
public:
    Loan();
private:
    QDate _openDate;
    QDate _closeDate;
    bool _isClosed;
};

}
}

#endif // LOAN_H
