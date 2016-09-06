#include "DecTest.h"

namespace kpk{
namespace data{

DecTest::
DecTest()
{

}

QDecNumber DecTest::
num() const
{
    return _num;
}

void DecTest::
num(const QDecNumber &num)
{
    _num = num;
}

}
}
