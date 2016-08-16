#include "Core.h"

namespace kpk{
namespace core{

CoreClass::CoreClass()
{
    _person = QSharedPointer<PersonService>(new PersonService);
    _dbService = QSharedPointer<DbService>(new DbService);
}

QSharedPointer<DbService> &CoreClass::dbService()
{
    return _dbService;
}

DbPtr CoreClass::db()
{
    return dbService()->get();
}

QSharedPointer<PersonService> &CoreClass::person()
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
