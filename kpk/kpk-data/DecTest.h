#ifndef DECTEST_H
#define DECTEST_H

#include <odb/core.hxx>
#include <QtCore/QString>

#include <QDecNumber.hh>

#include "data_global.h"

namespace kpk{
namespace data{

#pragma db object
class DATASHARED_EXPORT DecTest
{
public:
    DecTest();        

    QDecNumber num() const;
    void num(const QDecNumber &num);

private:
    friend class odb::access;

    #pragma db id auto
    ulong _id;

    QDecNumber _num;
};

}
}
#endif // DECTEST_H
