#include "Core.h"

namespace kpk{
namespace core{

CoreClass::CoreClass()   
{    
}

CoreClass::~CoreClass()
{}

std::shared_ptr<AuthService> CoreClass::auth() const
{
    return _auth;
}

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

std::shared_ptr<LoanService> CoreClass::loan() const
{
    return _loan;
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
