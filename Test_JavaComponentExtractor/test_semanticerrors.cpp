#include "test_semanticerrors.h"

void Test_SemanticErrors::test_checkNestedClassesAndInterfacesInEachInterface_data()
{
    QTest::addColumn<QList<Class>>("classes");
    QTest::addColumn<QList<Interface>>("interfaces");
    QTest::addColumn<QList<SemanticError>>("expectedErrors");

    QTest::newRow("There are no errors")
        << QList<Class>{Class(TextLocation(1, 2, 3, 4))}
        << QList<Interface>{Interface(TextLocation(3, 4, 5, 6))}
        << QList<SemanticError>{};

    QTest::newRow("Class is nested into interface")
        << QList<Class>{Class(TextLocation(4, 5, 3, 4))}
        << QList<Interface>{Interface(TextLocation(3, 6, 5, 6))}
        << QList<SemanticError>{SemanticError("There is nested class in interface", TextLocation(3, 6, 5, 6))};

    QTest::newRow("Interface is nested into interface")
        << QList<Class>{}
    << QList<Interface>{Interface(TextLocation(3, 6, 5, 6)), Interface(TextLocation(4, 5, 5, 6))}
        << QList<SemanticError>{SemanticError("There is nested interface in interface", TextLocation(3, 6, 5, 6))};
}

void Test_SemanticErrors::test_checkNestedClassesAndInterfacesInEachInterface()
{
    QFETCH(QList<Class>, classes);
    QFETCH(QList<Interface>, interfaces);
    QFETCH(QList<SemanticError>, expectedErrors);

    QVERIFY2(expectedErrors == checkNestedClassesAndInterfacesInEachInterface(interfaces, classes), "Test failed");
}

void Test_SemanticErrors::test_checkDuplicates_data()
{
    QTest::addColumn<QStringList>("strings");
    QTest::addColumn<bool>("expectation");

    QTest::newRow("There are no duplicates")
        << QStringList{"abc", "def"}
        << false;

    QTest::newRow("There are duplicates")
        << QStringList{"abc", "abc"}
        << true;
}

void Test_SemanticErrors::test_checkDuplicates()
{
    QFETCH(QStringList, strings);
    QFETCH(bool, expectation);

    QVERIFY2(expectation == checkDuplicates(strings), "Test failed");
}