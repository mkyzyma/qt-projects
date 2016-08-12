#include <QString>
#include <QtTest>
#include <QSharedPointer>

#include <odb/database.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/schema-catalog.hxx>

#include "kpk-data/Person.h"
#include "kpk-data/Person-odb.hxx"

#include "kpk-data/Member.h"
#include "kpk-data/Member-odb.hxx"

#include "kpk-data/Loan.h"
#include "kpk-data/Loan-odb.hxx"

namespace kpk {
namespace test {

using namespace kpk::data;

class kpkDataTest : public QObject
{
    Q_OBJECT
public:
    kpkDataTest();
private:    
    QSharedPointer<odb::database> _db;
    ulong _id;
    QSharedPointer<Person> _p;
    const QString PERSON_NAME = "";
    void verifyPerson(Person& p);
    QSharedPointer<Person> createPerson();
private Q_SLOTS:
    void initTestCase();
    void personCanPersist();
    void personPersisted();
    void memberCanPersist();
    void memberPersisted();
    void loanCanPersist();
    void loanPersisted();
};

kpkDataTest::kpkDataTest()
{
    _p = QSharedPointer<Person>(new Person());
    _p->name().set("Иван", "Иванович", "Пупкин");
    _p->passport().series("6714");
    _p->passport().number("370364");
    _p->passport().date(QDate(2014,05,20));
    _p->passport().org("отд. УФМС России по ХМАО-Югре в г. Урае");
    _p->passport().orgCode("860028");
    _p->inn("123456789010");
    _p->snils("123-456-789 01");
}

void kpkDataTest::verifyPerson(Person& p)
{
    QVERIFY2(p.id() == _p->id(), "Wrong id");
    QVERIFY2(p.name().full() == _p->name().full(), "Wrong name");
    QVERIFY2(p.passport().full() == _p->passport().full(), "Wrong passport");
    QVERIFY2(p.inn() == _p->inn(), "Wrong inn");
    QVERIFY2(p.snils() == _p->snils(), "Wrong snils");

}

QSharedPointer<Person> kpkDataTest::createPerson()
{
    QSharedPointer<Person> p(new Person());

    p->name().set(_p->name().first(), _p->name().middle(), _p->name().last());
    p->passport().series(_p->passport().series());
    p->passport().number(_p->passport().number());
    p->passport().date(_p->passport().date());
    p->passport().org(_p->passport().org());
    p->passport().orgCode(_p->passport().orgCode());
    p->inn(_p->inn());
    p->snils(_p->snils());

    return p;
}

void kpkDataTest::initTestCase()
{
    //system("chcp 65001");
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


        odb::transaction t (_db->begin ());
        odb::schema_catalog::create_schema(*_db);


        t.commit();
    }
    catch(const odb::pgsql::database_exception e){
        QVERIFY2(false, e.message().c_str());
    }
}

void kpkDataTest::personCanPersist()
{
     try{
        QSharedPointer<Person> p(_p);

        odb::transaction t (_db->begin ());

        _id = _db->persist(p);

        t.commit();
    }catch(const odb::pgsql::database_exception e){
        QVERIFY2(false, e.message().c_str());
    }
}

void kpkDataTest::personPersisted()
{
    try{
       odb::transaction t (_db->begin ());

       QSharedPointer<Person> p(_db->load<Person>(_id));

       verifyPerson(*p);

       t.commit();
   }catch(const odb::pgsql::database_exception e){
       QVERIFY2(false, e.message().c_str());
   }
}

void kpkDataTest::memberCanPersist()
{
    try{
       odb::transaction t (_db->begin ());
       QSharedPointer<Member> m(new Member());

       _id = _db->persist(m);

       t.commit();

       QVERIFY2(false, "Can save null person");
    }catch(const std::exception&){
       //ignore
    }
    try{
       odb::transaction t (_db->begin ());

       QSharedPointer<Person> p (_db->load<Person>(_id));
       QSharedPointer<Member> m(new Member(p, QDate::currentDate()));

       _id = _db->persist(m);

       t.commit();
    }catch(const std::exception& e){
       QVERIFY2(false, e.what());
    }
}

void kpkDataTest::memberPersisted()
{
    try{
       odb::transaction t (_db->begin ());

       QSharedPointer<Member> m(_db->load<Member>(_id));

       QVERIFY2(m->id() == _id, "Wrong id");
       QVERIFY2(!m->person().isNull(), "Person is null");

       verifyPerson(*m->person());

       t.commit();
   }catch(const odb::pgsql::database_exception e){
       QVERIFY2(false, e.message().c_str());
   }
}

void kpkDataTest::loanCanPersist()
{
    try{
       odb::transaction t (_db->begin ());

       QSharedPointer<Person> p (_db->load<Person>(_id));

       typedef odb::query<Member> MemberQuery;
       typedef odb::result<Member> MemberResult;

       MemberResult r (_db->query<Member> (MemberQuery::person.equal(p->id())));

       QSharedPointer<Member> m(r.begin().load());

       QSharedPointer<Loan> l(new Loan(m, QDate::currentDate(), QDate::currentDate().addMonths(12),
                                       100000, 21, 12));


       l->person(p);
       l->member(r.begin().load());

       _db->persist(l);

       t.commit();
    }catch(const std::exception& e){
       QVERIFY2(false, e.what());
    }
}

void kpkDataTest::loanPersisted()
{
    try{
       odb::transaction t (_db->begin ());



       typedef odb::query<Loan> Query;
       typedef odb::result<Loan> Result;

       Result r (_db->query<Loan> (Query::person.equal(_id)));

       QSharedPointer<Loan> l(r.begin().load());

       QVERIFY2(l->person()->id() == _id, "Wrong person id");

       t.commit();
    }catch(const std::exception& e){
       QVERIFY2(false, e.what());
    }
}

}
}



QTEST_APPLESS_MAIN(kpk::test::kpkDataTest)

#include "tst_kpkDataTest.moc"
