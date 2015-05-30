#include "test_stringfuncs.h"

void Test_StringFuncs::test_contentBetweenPositions_data()
{
    QTest::addColumn<QString>("buffer");
    QTest::addColumn<TextLocation>("location");
    QTest::addColumn<QString>("expectation");

    QTest::newRow("Windows line endings")
        << "My name is Bond.\r\nJames Bond.\r\nAgent 007."
        << TextLocation(2, 3, 7, 5)
        << "Bond.\r\nAgent";

    QTest::newRow("Unix line endings")
        << "My name is Bond.\nJames Bond.\nAgent 007."
        << TextLocation(2, 3, 7, 5)
        << "Bond.\nAgent";

    QTest::newRow("Mac line endings")
        << "My name is Bond.\rJames Bond.\rAgent 007."
        << TextLocation(2, 3, 7, 5)
        << "Bond.\rAgent";

    QTest::newRow("One full first string to return")
        << "My name is Bond.\r\nJames Bond.\r\nAgent 007."
        << TextLocation(1, 1, 0, 16)
        << "My name is Bond.";

    QTest::newRow("One full middle string to return")
        << "My name is Bond.\r\nJames Bond.\r\nAgent 007."
        << TextLocation(2, 2, 0, 11)
        << "James Bond.";

    QTest::newRow("One full last string to return")
        << "My name is Bond.\r\nJames Bond.\r\nAgent 007."
        << TextLocation(3, 3, 0, 10)
        << "Agent 007.";

    QTest::newRow("One char to return")
        << "My name is Bond.\r\nJames Bond.\r\nAgent 007."
        << TextLocation(2, 2, 1, 1)
        << "J";

    QTest::newRow("Empty buffer")
        << ""
        << TextLocation(0, 0, 0, 0)
        << "";
}

void Test_StringFuncs::test_contentBetweenPositions()
{
    QFETCH(QString, buffer);
    QFETCH(TextLocation, location);
    QFETCH(QString, expectation);

    QString result = contentBetweenPositions(buffer, location);
    QVERIFY2(result == expectation, QString("\nFunction returns:\n%1\nWas expected:\n%2\n").arg(result).arg(expectation).toStdString().c_str());
}
