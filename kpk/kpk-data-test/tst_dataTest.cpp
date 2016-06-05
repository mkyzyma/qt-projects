#include <QString>
#include <QtTest>

class dataTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void test();
};



void dataTest::test()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(dataTest)

#include "tst_dataTest.moc"
