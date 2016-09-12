#include <QtTest>

#include <odb/core.hxx>


#include "kpk-core/Core.h"
#include "kpk-data/Person.h"
#include "kpk-core/Exceptions.h"
#include <odb/pgsql/exceptions.hxx>

namespace kpk{
namespace test {

using namespace kpk::data;
using namespace kpk::core;


class KpkCoreTest : public QObject
{
    Q_OBJECT

public:
    KpkCoreTest();
private:
    std::shared_ptr<Person> _p;
    void verifyPerson(Person& p);
    std::shared_ptr<Person> createPerson();
private Q_SLOTS:
    void canConnect();
    void canCreateSchema();
    void canAddPerson();
    void canEnter();
    void canExit();
    void canEnterAgain();
    void canOpenLoan();
    void canIssueLoan();
};

KpkCoreTest::KpkCoreTest()
{


}
void KpkCoreTest::verifyPerson(Person& p)
{
    QVERIFY2(p.id() == _p->id(), "Wrong id");
    QVERIFY2(p.name().full() == _p->name().full(), "Wrong name");
    QVERIFY2(p.passport().full() == _p->passport().full(), "Wrong passport");
    QVERIFY2(p.inn() == _p->inn(), "Wrong inn");
    QVERIFY2(p.snils() == _p->snils(), "Wrong snils");

}

std::shared_ptr<Person> KpkCoreTest::createPerson()
{
   auto p(Core()->person()->create());

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
void KpkCoreTest::canConnect()
{
    try{
        Core()->dbService()->connect();
    }
    catch(const std::exception e){
        QVERIFY2(false, e.what());
    }
}

void KpkCoreTest::canCreateSchema()
{
    try{
        Core()->dbService()->createShcema();
    }
    catch(const std::exception e){
        QVERIFY2(false, e.what());
    }

}

void KpkCoreTest::canAddPerson()
{
    try{
        _p = Core()->person()->create();
        _p->name().set("Иван", "Иванович", "Пупкин");
        _p->passport().series("6714");
        _p->passport().number("370364");
        _p->passport().date(QDate(2014,05,20));
        _p->passport().org("отд. УФМС России по ХМАО-Югре в г. Урае");
        _p->passport().orgCode("860028");
        _p->inn("123456789010");
        _p->snils("123-456-789 01");

        Core()->begin();
        Core()->person()->add(_p);
        Core()->commit();

        Core()->begin();
        auto p = Core()->person()->get(_p->id());
        Core()->commit();

        verifyPerson(*p);

    }catch(const std::exception e){
        Core()->rollback();
        QVERIFY2(false, e.what());
    }
}

void KpkCoreTest::canEnter()
{
    try{
        Core()->begin();
        Core()->person()->enter(_p, Core()->date()->working().addYears(-1));
        Core()->commit();

        bool throws(false);

        try{
            Core()->begin();
            Core()->person()->enter(_p, Core()->date()->working());
            Core()->commit();
        }catch(const exception::AlreadyMemberException e){
            Core()->rollback();
            throws = true;
        }

        QVERIFY2(throws, "Already member");
    }

    catch(const std::exception e){
        Core()->rollback();
        QVERIFY2(false, e.what());
    }
}

void KpkCoreTest::canExit()
{
    try{
        Core()->begin();
        QDate date = Core()->date()->working().addMonths(-6);
        Core()->person()->exit(_p, date, ExitReason::exit);
        Core()->commit();

        Core()->begin();
        auto p(Core()->person()->get(_p->id()));
        Core()->commit();

        QVERIFY2(!p->isMember(), "Must be not member, but stil a member");
        QVERIFY2(p->member()->exitReason() == ExitReason::exit, "Wrong exit reason");
    }

    catch(const odb::pgsql::database_exception e){
        Core()->rollback();
        QVERIFY2(false, e.what());
    }
}

void KpkCoreTest::canEnterAgain()
{
    try{
        Core()->begin();
        Core()->person()->enter(_p, Core()->date()->working());
        Core()->commit();

        Core()->begin();
        auto p(Core()->person()->get(_p->id()));
        Core()->commit();

        QVERIFY2(p->isMember(), "Must be a member, but is not");

        auto m = p->member();
        QVERIFY2(m->inDate() == QDate::currentDate(), "Wrong enter date");
        Core()->begin();
        auto r = Core()->person()->membership(p->id());
        QVERIFY2(r.size() == 2, "Membership size must be 2");

        verifyPerson(*(r.begin().load()->person()));

        Core()->commit();

    }

    catch(const std::exception e){
        Core()->rollback();
        QVERIFY2(false, e.what());
    }
}

void KpkCoreTest::canOpenLoan()
{
    try{
        Core()->begin();

        auto t = Core()->loan()->getLoanType(1);
        auto date = Core()->date()->working().addYears(-1);
        auto l = Core()->loan()->open(_p->member(), t, date, "1000000", "20", 12);

        Core()->commit();

        Core()->begin();

        l = Core()->loan()->get(l->id());

        QVERIFY2(l->limit() == 1000000, "Wrong limit");

        Core()->commit();
    }

    catch(const std::exception e){
        Core()->rollback();
        QVERIFY2(false, e.what());
    }
}

void KpkCoreTest::canIssueLoan()
{
    try{
        Core()->begin();

        auto l = Core()->loan()->get(1);

        auto dt = Core()->date()->working().addYears(-1);

        Core()->loan()->issue(l, dt, 555000);

        Core()->commit();

        Core()->begin();

         l = Core()->loan()->get(l->id());
        qDebug() << l->sum().toString();
        QVERIFY2(l->sum() == 555000, "Wrong loan sum");
        QVERIFY2(l->state(), "State is null");
        QVERIFY2(l->state()->sum() == 555000, "Wrong state sum");

        Core()->commit();

        Core()->begin();

        l = Core()->loan()->get(1);

        dt = Core()->date()->working().addMonths(-6);

        Core()->loan()->issue(l, dt, 555000);

        Core()->commit();

        Core()->begin();

         l = Core()->loan()->get(l->id());
        qDebug() << l->sum().toString();
        QVERIFY2(l->sum() == 2*555000, "Wrong loan sum");
        QVERIFY2(l->state(), "State is null");
        QVERIFY2(l->state()->sum() == 2*555000, "Wrong state sum");

        Core()->commit();
    }

    catch(const std::exception e){
        Core()->rollback();
        QVERIFY2(false, e.what());
    }
}


}
}
QTEST_APPLESS_MAIN(kpk::test::KpkCoreTest)

#include "tst_KpkCoreTest.moc"
