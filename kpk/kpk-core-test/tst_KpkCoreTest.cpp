#include <QString>
#include <QtTest>

#include "kpk-core/Core.h"
#include "kpk-data/Person.h"

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
    QSharedPointer<Person> _p;
    void verifyPerson(Person& p);
    QSharedPointer<Person> createPerson();
private Q_SLOTS:
    void canConnect();
    void canCreateSchema();
    void canAddPerson();
};

KpkCoreTest::KpkCoreTest()
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
void KpkCoreTest::verifyPerson(Person& p)
{
    QVERIFY2(p.id() == _p->id(), "Wrong id");
    QVERIFY2(p.name().full() == _p->name().full(), "Wrong name");
    QVERIFY2(p.passport().full() == _p->passport().full(), "Wrong passport");
    QVERIFY2(p.inn() == _p->inn(), "Wrong inn");
    QVERIFY2(p.snils() == _p->snils(), "Wrong snils");

}

QSharedPointer<Person> KpkCoreTest::createPerson()
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

        PersonPtr p(createPerson());

        Core()->begin();
        Core()->person()->add(p);
        Core()->commit();

        Core()->begin();
        p = Core()->person()->get(p->id());
        QVERIFY2(p->name().full() == _p->name().full(), "Wrong name");
        Core()->commit();

    }catch(const std::exception e){
        Core()->rollback();
        QVERIFY2(false, e.what());
    }
}


}
}
QTEST_APPLESS_MAIN(kpk::test::KpkCoreTest)

#include "tst_KpkCoreTest.moc"
