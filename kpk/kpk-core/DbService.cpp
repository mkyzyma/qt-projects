#include "DbService.h"

#include <memory>

#include <odb/core.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/session.hxx>

#include <kpk-data/LoanType.h>
#include <kpk-data/LoanType-odb.hxx>

namespace kpk{
namespace core{

odb::session s;

DbService::DbService()
{

}

DbPtr& DbService::connect()
{
    try{

        _db =  std::shared_ptr<odb::database> (
                    new odb::pgsql::database (
                        "postgres",
                        "7895123",
                        "kpk-test",
                        "localhost",
                        5432
                        )
                    );

        _db->tracer(odb::stderr_tracer);
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
        begin();
        odb::schema_catalog::create_schema(*_db);
        commit();

        begin();

        using namespace data;

        auto t = LoanType(QString("Неотложные нужды"), 205000);
        _db->persist<LoanType>(t);

        t = LoanType(QString("Покупка автомобиля"), 180000);
        _db->persist<LoanType>(t);

        t = LoanType(QString("Приобретение жилья (недвижимости)"), 200000);
        _db->persist<LoanType>(t);

        t = LoanType(QString("Товарный заем"), 200000);
        _db->persist<LoanType>(t);

        t = LoanType(QString("Ипотека"), 160000);
        _db->persist<LoanType>(t);
        commit();
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
