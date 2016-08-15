#include "IsDeleted.h"

namespace kpk{
namespace data{

IsDeleted::IsDeleted()
{

}

bool IsDeleted::isDeleted() const
{
    return _isDeleted;
}

std::shared_ptr<QDateTime> IsDeleted::deleteTime() const
{
    return _deleteTime;
}

void IsDeleted::setDeleted(QDateTime deleteDate, std::shared_ptr<User> user)
{
    _isDeleted = true;
    _deleteTime = std::make_shared<QDateTime>(deleteDate);
    _deletedBy = user;
}

void IsDeleted::resetDeleted()
{
    _isDeleted = false;
    _deleteTime = nullptr;
}

std::shared_ptr<User> IsDeleted::deletedBy() const
{
    return _deletedBy;
}


}
}
