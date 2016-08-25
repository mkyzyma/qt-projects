#ifndef LOANSERVICE_H
#define LOANSERVICE_H

#include <QObject>

#include "core_global.h"
namespace kpk{
namespace core{

/*!
 * \brief Служба управления займами
 */
class CORESHARED_EXPORT LoanService : public QObject
{
    Q_OBJECT
public:
    explicit LoanService(QObject *parent = 0);


};

}
}

#endif // LOANSERVICE_H
