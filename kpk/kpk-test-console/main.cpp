#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>

#include <odb/database.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/schema-catalog.hxx>

#include "kpk-data/Person.h"
#include "kpk-data/Person-odb.hxx"

#include "kpk-data/Member.h"
#include "kpk-data/Member-odb.hxx"

#include <QDecContext.hh>
#include <QDecNumber.hh>
//#include "stdio.h"
//static QTextStream cout(stdout);
//static QTextStream cerr(stderr);



using namespace kpk::data;

int main(int argc, char *argv[])
{

    {
        QDecContext ctx;

        QDecNumber a, b;

        a = 10;
        b = 100;

        qDebug() << (a / b).toString();
    }



    QCoreApplication a(argc, argv);
    return a.exec();

    system("chcp 1251");


    try{

        qint64 a = 25000, b = 3000, c;

        c = a / b;

        qDebug() << c << "\r\n";

        QSharedPointer<odb::database> db (
                            new odb::pgsql::database (
                                "postgres",
                                "7895123",
                                "kpk",
                                "",
                                5433
                                )
                            );
        db->tracer(odb::stderr_tracer);


        odb::transaction t (db->begin ());
        odb::schema_catalog::create_schema(*db);

        /*odb::schema_version v (db->schema_version());
        if(!v)
            odb::schema_catalog::create_schema(*db);
        else
            odb::schema_catalog::migrate (*db);*/

        t.commit();

        QSharedPointer<Person> miha(new Person());

        miha->name().first("Михаил");
        miha->name().middle("Васильевич");
        miha->name().last("Кызыма");

        miha->passport().series("6714");
        miha->passport().number("370364");
        miha->passport().date(QDate(2014,05,20));
        miha->passport().org("отд. УФМС России по ХМАО-Югре в г. Урае");
        miha->passport().orgCode("860028");

        /*qDebug() << miha->name().toString();
        qDebug() << miha->passport().toString();*/

        t.reset(db->begin());

        db->persist(miha);

        t.commit();

        Member member(miha, QDate::currentDate());

        t.reset(db->begin());

        db->persist(member);

        t.commit();

    }
    catch(const odb::pgsql::database_exception e){
        qDebug() << QString(e.message().c_str());
        return EXIT_FAILURE;
    }

    return a.exec();

}
