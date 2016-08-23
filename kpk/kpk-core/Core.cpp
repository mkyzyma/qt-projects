#include "Core.h"

namespace kpk{
namespace core{

CoreClass::CoreClass()
    : _person(std::make_shared<PersonService>()),
      _dbService(std::make_shared<DbService>()),
      _date(std::make_shared<DateService>(QDate::currentDate()))
{    
}

CoreClass::~CoreClass()
{}

std::shared_ptr<DbService> CoreClass::dbService() const
{
    return _dbService;
}

DbPtr CoreClass::db()
{
    return dbService()->get();
}

std::shared_ptr<DateService> CoreClass::date() const
{
    return _date;
}

std::shared_ptr<PersonService> CoreClass::person() const
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

CoreClass *CoreClass::instance()
{
    static CoreClass instance;
    return &instance;
}



}
}
