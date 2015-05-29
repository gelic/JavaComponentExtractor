#include "test_component.h"

void Test_Component::test_isNested_data()
{
    QTest::addColumn<Component>("component1");
    QTest::addColumn<Component>("component2");
    QTest::addColumn<bool>("expectation");

    QTest::newRow("The first component is nested into the second one")
        << Component(TextLocation(2, 5, 1, 1))
        << Component(TextLocation(1, 6, 1, 1))
        << true;

    QTest::newRow("The first component isn`t nested into the second one")
        << Component(TextLocation(2, 5, 1, 1))
        << Component(TextLocation(3, 6, 1, 1))
        << false;

    QTest::newRow("The first component is nested into the second one, they are both on the same line")
        << Component(TextLocation(2, 2, 4, 5))
        << Component(TextLocation(2, 2, 3, 6))
        << true;

    QTest::newRow("The first component isn`t nested into the second one, they are both on the same line")
        << Component(TextLocation(2, 2, 2, 5))
        << Component(TextLocation(2, 2, 3, 6))
        << false;

    QTest::newRow("Comparasion of the equal components")
        << Component(TextLocation(2, 2, 2, 5))
        << Component(TextLocation(2, 2, 2, 5))
        << false;
}

void Test_Component::test_isNested()
{
    QFETCH(Component, component1);
    QFETCH(Component, component2);
    QFETCH(bool, expectation);

    QVERIFY2(component1.isNested(component2) == expectation, "Test failed");
}
