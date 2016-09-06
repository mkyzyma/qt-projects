#include "DbObject.h"

namespace kpk {
namespace data {

void DbObject::
setCreateInfo(QDateTime time, std::shared_ptr<User> user)
{
    _createTime = time;
    _createdBy = user;
}

QDateTime DbObject::
createTime() const
{
    return _createTime;
}

std::shared_ptr<User> DbObject::
createdBy() const
{
    return _createdBy;
}

DbObject::
DbObject()
{}

}
}
