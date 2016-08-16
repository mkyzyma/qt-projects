#include "DbService.h"

#include <odb/core.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/schema-catalog.hxx>

#include <kpk-data/Person.h>
namespace kpk{
namespace core{

DbService::DbService()
{

}

DbPtr& DbService::connect()
{
    try{

        _db =  QSharedPointer<odb::database> (
                    new odb::pgsql::database (
                        "postgres",
                        "7895123",
                        "kpk-test",
                        "localhost",
                        5432
                        )
                    );

    // _db->tracer(odb::stderr_tracer);
    }
    catch(const odb::pgsql::database_exception e){
        throw std::exception(e.what());
    }

    return _db;
}

DbPtr& DbService::get()
{
    return _db;
}

DbPtr &DbService::createShcema()
{
    try {
        odb::transaction t (_db->begin ());
        odb::schema_catalog::create_schema(*_db);
        t.commit();
    }
    catch(const odb::pgsql::database_exception e){
        throw std::exception(e.what());
    }

    return _db;
}

void DbService::begin()
{
    _tr = TrPtr(new odb::transaction(_db->begin()));
}

void DbService::commit()
{
    _tr->commit();
}

void DbService::rollback()
{
    _tr->rollback();
}



}
}
