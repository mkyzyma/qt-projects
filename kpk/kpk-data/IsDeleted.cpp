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

std::shared_ptr<QDate> IsDeleted::deleteDate() const
{
    return _deleteDate;
}

void IsDeleted::setDeleted(QDate deleteDate)
{
    _isDeleted = true;
    _deleteDate = std::make_shared<QDate>(deleteDate);
}

void IsDeleted::resetDeleted()
{
    _isDeleted = false;
    _deleteDate = nullptr;
}


}
}
