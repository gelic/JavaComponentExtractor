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

void Test_SemanticErrors::test_checkEnums_data()
{
    QTest::addColumn<QList<Enum>>("enums");
    QTest::addColumn<QList<SemanticError>>("expectedErrors");

    QTest::newRow("Enum has no errors")
        << QList<Enum>{Enum(QStringList{"public", "static"}, "MyEnum", QStringList{"RED", "GREEN", "BLUE"}, TextLocation(1, 2, 3, 4))}
        << QList<SemanticError>{};

    QTest::newRow("Enum has repeating modificator")
        << QList<Enum>{Enum(QStringList{"public", "public"}, "MyEnum", QStringList{"RED", "GREEN", "BLUE"}, TextLocation(1, 2, 3, 4))}
        << QList<SemanticError>{SemanticError("Enum has repeating modificator", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Enum has repeating field")
        << QList<Enum>{Enum(QStringList{"public", "static"}, "MyEnum", QStringList{"RED", "RED"}, TextLocation(1, 2, 3, 4))}
        << QList<SemanticError>{SemanticError("Enum has repeating field", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Enum with non-unique name")
        << QList<Enum>{Enum(QStringList(), "MyEnum", QStringList(), TextLocation(1, 2, 3, 4)), Enum(QStringList(), "MyEnum", QStringList(), TextLocation(1, 2, 3, 4))}
        << QList<SemanticError>{SemanticError("There is enum with non-unique name", TextLocation(1, 2, 3, 4))};
}

void Test_SemanticErrors::test_checkEnums()
{
    QFETCH(QList<Enum>, enums);
    QFETCH(QList<SemanticError>, expectedErrors);

    QVERIFY2(expectedErrors == checkEnums(enums), "Test failed");
}

void Test_SemanticErrors::test_checkClasses_data()
{
    QTest::addColumn<QList<Class>>("classes");
    QTest::addColumn<QList<SemanticError>>("expectedErrors");

    QTest::newRow("Class has no errors")
        << QList<Class>{Class(QStringList{"public", "static"}, "MyClass", QStringList{"MyBaseClass1", "MyBaseClass2"}, QStringList{"MyInterface1", "MyInterface2"}, TextLocation(1, 2, 3, 4))}
        << QList<SemanticError>{};

    QTest::newRow("Class has repeating modificator")
        << QList<Class>{Class(QStringList{"public", "public"}, "MyClass", QStringList{"MyBaseClass1", "MyBaseClass2"}, QStringList{"MyInterface1", "MyInterface2"}, TextLocation(1, 2, 3, 4))}
        << QList<SemanticError>{SemanticError("Class has repeating modificator", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Class has repeating base class")
        << QList<Class>{Class(QStringList{"public", "static"}, "MyClass", QStringList{"MyBaseClass1", "MyBaseClass1"}, QStringList{"MyInterface1", "MyInterface2"}, TextLocation(1, 2, 3, 4))}
        << QList<SemanticError>{SemanticError("Class has repeating base class", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Class has repeating implemented interface")
        << QList<Class>{Class(QStringList{"public", "static"}, "MyClass", QStringList{"MyBaseClass1", "MyBaseClass2"}, QStringList{"MyInterface1", "MyInterface1"}, TextLocation(1, 2, 3, 4))}
        << QList<SemanticError>{SemanticError("Class has repeating implemented interface", TextLocation(1, 2, 3, 4))};
}

void Test_SemanticErrors::test_checkClasses()
{
    QFETCH(QList<Class>, classes);
    QFETCH(QList<SemanticError>, expectedErrors);

    QVERIFY2(expectedErrors == checkClasses(classes), "Test failed");
}