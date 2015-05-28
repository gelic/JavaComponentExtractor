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
    QTest::addColumn<QSet<QString>>("ids");
    QTest::addColumn<QList<SemanticError>>("expectedErrors");

    QTest::newRow("Enum has no errors")
        << QList<Enum>{Enum(QStringList{"public", "static"}, "MyEnum", QStringList{"RED", "GREEN", "BLUE"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{};

    QTest::newRow("Enum has repeating modificator")
        << QList<Enum>{Enum(QStringList{"public", "public"}, "MyEnum", QStringList{"RED", "GREEN", "BLUE"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Enum has repeating modificator", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Enum has repeating field")
        << QList<Enum>{Enum(QStringList{"public", "static"}, "MyEnum", QStringList{"RED", "RED"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Enum has repeating field", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Enum has non-unique name")
        << QList<Enum>{Enum(QStringList{"public", "static"}, "MyEnum", QStringList{"RED", "GREEN", "BLUE"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{"MyEnum"}
        << QList<SemanticError>{SemanticError("Enum with non-unique name", TextLocation(1, 2, 3, 4))};
}

void Test_SemanticErrors::test_checkEnums()
{
    QFETCH(QList<Enum>, enums);
    QFETCH(QSet<QString>, ids);
    QFETCH(QList<SemanticError>, expectedErrors);

    QVERIFY2(expectedErrors == checkEnums(enums, ids), "Test failed");
}

void Test_SemanticErrors::test_checkClasses_data()
{
    QTest::addColumn<QList<Class>>("classes");
    QTest::addColumn<QSet<QString>>("ids");
    QTest::addColumn<QList<SemanticError>>("expectedErrors");

    QTest::newRow("Class has no errors")
        << QList<Class>{Class(QStringList{"public", "static"}, "MyClass", QStringList{"MyBaseClass1", "MyBaseClass2"}, QStringList{"MyInterface1", "MyInterface2"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{};

    QTest::newRow("Class has repeating modificator")
        << QList<Class>{Class(QStringList{"public", "public"}, "MyClass", QStringList{"MyBaseClass1", "MyBaseClass2"}, QStringList{"MyInterface1", "MyInterface2"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Class has repeating modificator", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Class has repeating base class")
        << QList<Class>{Class(QStringList{"public", "static"}, "MyClass", QStringList{"MyBaseClass1", "MyBaseClass1"}, QStringList{"MyInterface1", "MyInterface2"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Class has repeating base class", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Class has repeating implemented interface")
        << QList<Class>{Class(QStringList{"public", "static"}, "MyClass", QStringList{"MyBaseClass1", "MyBaseClass2"}, QStringList{"MyInterface1", "MyInterface1"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Class has repeating implemented interface", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Class with non-unique name")
        << QList<Class>{Class(QStringList{"public", "static"}, "MyClass", QStringList{"MyBaseClass"}, QStringList{"MyInterface"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{"MyClass"}
        << QList<SemanticError>{SemanticError("Class with non-unique name", TextLocation(1, 2, 3, 4))};

    Class classExample(QStringList{"public", "static"}, "MyClass", QStringList{"MyBaseClass"}, QStringList{"MyInterface"}, TextLocation(1, 2, 3, 4));
    classExample.methods = {Method(QStringList(), "int", "MyClass", QList<Method::Param>{Method::Param(false, "int", "param")}, QStringList(), TextLocation(2, 3, 4, 5))};
    QTest::newRow("Method with non-unique name inside class")
        << QList<Class>{classExample}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Method with non-unique name", TextLocation(2, 3, 4, 5))};
}

void Test_SemanticErrors::test_checkClasses()
{
    QFETCH(QList<Class>, classes);
    QFETCH(QSet<QString>, ids);
    QFETCH(QList<SemanticError>, expectedErrors);

    QVERIFY2(expectedErrors == checkClasses(classes, ids), "Test failed");
}

void Test_SemanticErrors::test_checkInterfaces_data()
{
    QTest::addColumn<QList<Interface>>("interfaces");
    QTest::addColumn<QSet<QString>>("ids");
    QTest::addColumn<QList<SemanticError>>("expectedErrors");

    QTest::newRow("Interface has no errors")
        << QList<Interface>{Interface(QStringList{"public", "static"}, "MyInterface", QStringList{"MyBaseInterface"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{};

    QTest::newRow("Interface has repeating modificator")
        << QList<Interface>{Interface(QStringList{"public", "public"}, "MyInterface", QStringList{"MyBaseInterface"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Interface has repeating modificator", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Interface with non-unique name")
        << QList<Interface>{Interface(QStringList{"public", "static"}, "MyInterface", QStringList{"MyBaseInterface"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{"MyInterface"}
        << QList<SemanticError>{SemanticError("Interface with non-unique name", TextLocation(1, 2, 3, 4))};

    Interface interface(QStringList{"public", "static"}, "MyInterface", QStringList{"MyBaseInterface"}, TextLocation(1, 2, 3, 4));
    interface.methods = {Method(QStringList(), "int", "MyInterface", QList<Method::Param>{Method::Param(false, "int", "param")}, QStringList(), TextLocation(2, 3, 4, 5))};
    QTest::newRow("Method with non-unique name inside interface")
        << QList<Interface>{interface}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Method with non-unique name", TextLocation(2, 3, 4, 5))};
}

void Test_SemanticErrors::test_checkInterfaces()
{
    QFETCH(QList<Interface>, interfaces);
    QFETCH(QSet<QString>, ids);
    QFETCH(QList<SemanticError>, expectedErrors);

    QVERIFY2(expectedErrors == checkInterfaces(interfaces, ids), "Test failed");
}

void Test_SemanticErrors::test_checkFields_data()
{
    QTest::addColumn<QList<Field>>("fields");
    QTest::addColumn<QSet<QString>>("ids");
    QTest::addColumn<QList<SemanticError>>("expectedErrors");

    QTest::newRow("Field has no errors")
        << QList<Field>{Field(QStringList{"public", "static"}, "int", "field", TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{};

    QTest::newRow("Field has repeating modificator")
        << QList<Field>{Field(QStringList{"public", "public"}, "int", "field", TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Field has repeating modificator", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Field has non-unique name")
        << QList<Field>{Field(QStringList{"public", "static"}, "int", "field", TextLocation(1, 2, 3, 4))}
        << QSet<QString>{"field"}
        << QList<SemanticError>{SemanticError("Field with non-unique name", TextLocation(1, 2, 3, 4))};
}

void Test_SemanticErrors::test_checkFields()
{
    QFETCH(QList<Field>, fields);
    QFETCH(QSet<QString>, ids);
    QFETCH(QList<SemanticError>, expectedErrors);

    QVERIFY2(expectedErrors == checkFields(fields, ids), "Test failed");
}

void Test_SemanticErrors::test_checkMethods_data()
{
    QTest::addColumn<QList<Method>>("methods");
    QTest::addColumn<QSet<QString>>("ids");
    QTest::addColumn<QList<SemanticError>>("expectedErrors");

    QTest::newRow("Method has no errors")
        << QList<Method>{Method(QStringList{"public", "static"}, "void", "method", QList<Method::Param>{Method::Param(false, "int", "param")}, QStringList{"Exception"})}
        << QSet<QString>{}
        << QList<SemanticError>{};

    QTest::newRow("Method has repeating modificator")
        << QList<Method>{Method(QStringList{"public", "public"}, "void", "method", QList<Method::Param>{Method::Param(false, "int", "param")}, QStringList{"Exception"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{}
        << QList<SemanticError>{SemanticError("Method has repeating modificator", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Method with non-unique name")
        << QList<Method>{Method(QStringList{"public", "static"}, "void", "method", QList<Method::Param>{Method::Param(false, "int", "param")}, QStringList{"Exception"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{"method"}
        << QList<SemanticError>{SemanticError("Method with non-unique name", TextLocation(1, 2, 3, 4))};

    QTest::newRow("Constructor")
        << QList<Method>{Method(QStringList{"public", "static"}, "", "method", QList<Method::Param>{Method::Param(false, "int", "param")}, QStringList{"Exception"}, TextLocation(1, 2, 3, 4))}
        << QSet<QString>{"method"}
        << QList<SemanticError>{};
}

void Test_SemanticErrors::test_checkMethods()
{
    QFETCH(QList<Method>, methods);
    QFETCH(QSet<QString>, ids);
    QFETCH(QList<SemanticError>, expectedErrors);

    QVERIFY2(expectedErrors == checkMethods(methods, ids), "Test failed");
}