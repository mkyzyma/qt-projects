#include <QString>
#include <QtTest>
#include <memory>

#include <odb/database.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/schema-catalog.hxx>

#include "kpk-data/Person.h"
#include "kpk-data/Person-odb.hxx"

#include "kpk-data/Member.h"
#include "kpk-data/Member-odb.hxx"

#include "kpk-data/LoanType.h"
#include "kpk-data/LoanType-odb.hxx"

#include "kpk-data/Loan.h"
#include "kpk-data/Loan-odb.hxx"

#include "kpk-data/LoanPayment.h"
#include "kpk-data/LoanPayment-odb.hxx"

namespace kpk {
namespace test {

using namespace kpk::data;

class kpkDataTest : public QObject
{
    Q_OBJECT
public:
    kpkDataTest();
private:    
    std::shared_ptr<odb::database> _db;
    ulong _id;
    std::shared_ptr<Person> _p;
    const QString PERSON_NAME = "";
    void verifyPerson(Person& p);
    std::shared_ptr<Person> createPerson();
    const std::shared_ptr<Person> getPerson();
    std::shared_ptr<Member> getMember();
    std::shared_ptr<Loan> getLoan();
private Q_SLOTS:
    void initTestCase();

    void personCanPersist();
    void personPersisted();
    void memberCanPersist();
    void memberPersisted();

    void loanCanPersist();
    void loanPersisted();
    void loanOperCanPersist();
    void loanOperPersisted();
};

kpkDataTest::kpkDataTest()
{
    _p = std::make_shared<Person>();
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

std::shared_ptr<Person> kpkDataTest::createPerson()
{
    auto p(std::make_shared<Person>());

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

const std::shared_ptr<Person> kpkDataTest::getPerson()
{
   return _db->load<Person>(_id);
}

std::shared_ptr<Member> kpkDataTest::getMember()
{
    odb::result<Member> r (_db->query<Member> (odb::query<Member>::person == _id));
    return r.begin().load();
}

std::shared_ptr<Loan> kpkDataTest::getLoan()
{
    odb::result<Loan> r (_db->query<Loan> (odb::query<Loan>::person == _id));
    return r.begin().load();
}

void kpkDataTest::initTestCase()
{
    //system("chcp 65001");
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
        std::shared_ptr<Person> p(_p);

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

       std::shared_ptr<Person> p(getPerson());

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
       std::shared_ptr<Member> m(new Member());

       _id = _db->persist(m);

       t.commit();

       QVERIFY2(false, "Can save null person");
    }catch(const std::exception&){
       //ignore
    }
    try{
       odb::transaction t (_db->begin ());

       std::shared_ptr<Person> p (_db->load<Person>(_id));
       std::shared_ptr<Member> m(new Member(p, QDate::currentDate()));

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

       std::shared_ptr<Member> m(getMember());

       QVERIFY2(m->id() == _id, "Wrong id");
       QVERIFY2(m->person(), "Person is null");

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

       auto p (getPerson());
       auto m (getMember());

       std::shared_ptr<Loan> l(new Loan(m, std::shared_ptr<LoanType>(),
                                       QDate::currentDate(),
                                       QDate::currentDate().addMonths(12),
                                       100000, 21, 12));

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

       auto l(getLoan());

       QVERIFY2(l->person()->id() == _id, "Wrong person id");

       t.commit();
    }catch(const std::exception& e){
       QVERIFY2(false, e.what());
    }
}

void kpkDataTest::loanOperCanPersist()
{
    try{
//       odb::transaction t (_db->begin ());

//       auto p (getPerson());

//       std::shared_ptr<LoanPayment> o(new LoanPayment(QDate::currentDate()));

//       o->fact().date(QDate::currentDate());
//       o->plan().date(QDate::currentDate().addDays(10));
//       o->member(getMember());
//       o->loan(getLoan());

//       _db->persist(o);

//       t.commit();
    }catch(const std::exception& e){
       QVERIFY2(false, e.what());
    }
}

void kpkDataTest::loanOperPersisted()
{
    try{
       odb::transaction t (_db->begin ());

       odb::result<LoanPayment>
       r (_db->query<LoanPayment> (odb::query<LoanPayment>::loan == getLoan()->id()));

       auto o(r.begin().load());

       QVERIFY2(o->person()->id() == _id, "Wrong person id");

       t.commit();
    }catch(const std::exception& e){
       QVERIFY2(false, e.what());
    }
}

}
}



QTEST_APPLESS_MAIN(kpk::test::kpkDataTest)

#include "tst_kpkDataTest.moc"
