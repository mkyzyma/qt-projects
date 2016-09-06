#include <vector>
#include <iostream>

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

#include "kpk-data/DecTest.h"
#include "kpk-data/DecTest-odb.hxx"

#include <QDecContext.hh>
#include <QDecNumber.hh>
#include <QDecSingle.hh>
#include <QDecDouble.hh>



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


     QCoreApplication a(argc, argv);
//    auto p = std::make_shared<Person>();
//    p->name().set("Иван", "Иванович", "Пупкин");
//    p->passport().series("6714");
//    p->passport().number("370364");
//    p->passport().date(QDate(2014,05,20));
//    p->passport().org("отд. УФМС России по ХМАО-Югре в г. Урае");
//    p->passport().orgCode("860028");
//    p->inn("123456789010");
//    p->snils("123-456-789 01");



//    //return a.exec();

//    system("chcp 1251");


    try{

    Core()->dbService()->connect();
//    Core()->dbService()->createShcema();
    Core()->begin();

    auto d(std::make_shared<DecTest>());

    d->num(QDecNumber("12345.12345"));

    Core()->db()->persist(d);
//    auto r = (Core()->db()->query<Person>(odb::query<Person>::id == 1));

//    PersonPtr p = r.begin().load();

//    qDebug() << p->name().full();

//    Core()->commit();


//    Core()->begin();

//    auto t = Core()->loan()->getLoanType(1);
//    auto date = Core()->date()->working();
//    auto m = p->member().lock();

//    Core()->loan()->open(m, t, date, "1000000", "20", 12);

    Core()->commit();

    Core()->begin();

    d = Core()->db()->load<DecTest>(1);

    qDebug() << d->num().toString();

    Core()->commit();
    qDebug() << "\r\nOK";

    }
    catch(const std::exception& e){
        cerr << e.exception::what() << endl;
        return EXIT_FAILURE;
    }


  int result = a.exec();

  return result;

}
