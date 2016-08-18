#include "Core.h"

namespace kpk{
namespace core{

CoreClass::CoreClass()
{
    _person = std::shared_ptr<PersonService>(new PersonService);
    _dbService = std::shared_ptr<DbService>(new DbService);
}

std::shared_ptr<DbService> &CoreClass::dbService()
{
    return _dbService;
}

DbPtr CoreClass::db()
{
    return dbService()->get();
}

std::shared_ptr<PersonService> &CoreClass::person()
{
    return _person;
}

void CoreClass::begin()
{
    dbService()->begin();
}

void CoreClass::commit()
{
    dbService()->commit();
}

void CoreClass::rollback()
{
    dbService()->rollback();
}



}
}
