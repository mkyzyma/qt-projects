#include <vector>

#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>

#include <odb/database.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/query.hxx>
#include <odb/result.hxx>

#include "kpk-data/Person.h"
#include "kpk-data/Person-odb.hxx"

#include "kpk-data/Member.h"
#include "kpk-data/Member-odb.hxx"


#include <QDecContext.hh>
#include <QDecNumber.hh>
//#include "stdio.h"
//static QTextStream cout(stdout);
//static QTextStream cerr(stderr);

#include "kpk-core/Core.h"

using namespace kpk::data;
using namespace kpk::core;

QTextStream cout(stdout);
QTextStream cerr(stderr);

int main(int argc, char *argv[])
{

    auto p = std::make_shared<Person>(Person());
    p->name().set("Иван", "Иванович", "Пупкин");
    p->passport().series("6714");
    p->passport().number("370364");
    p->passport().date(QDate(2014,05,20));
    p->passport().org("отд. УФМС России по ХМАО-Югре в г. Урае");
    p->passport().orgCode("860028");
    p->inn("123456789010");
    p->snils("123-456-789 01");


    QCoreApplication a(argc, argv);
    //return a.exec();

    system("chcp 1251");


    try{

    Core()->dbService()->connect();
    //Core()->dbService()->createShcema();

    /*Core()->begin();

    Core()->person()->add(p);

    Core()->commit();

    Core()->begin();

    auto p1 = Core()->person()->get(1);

    Core()->commit();

    qDebug() << p1->name().full();*/

    Core()->begin();

    auto r = (Core()->db()->query<Person>(odb::query<Person>::id == 1));



    qDebug() << r.begin().load()->name().full();

    Core()->commit();





    cout << "\r\nOK";

    }
    catch(const std::exception& e){
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }


    return a.exec();

}
