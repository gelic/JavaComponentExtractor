#include "test_treefuncs.h"

void Test_TreeFuncs::test_findParentsToEnums_data()
{
    QTest::addColumn<QList<Class>>("classes");
    QTest::addColumn<QList<Class>>("expectedClasses");
    QTest::addColumn<QList<Enum>>("enums");
    QTest::addColumn<QList<Enum>>("expectedEnums");

    QTest::newRow("Class hasn`t nested enum")
        << QList<Class>{Class(TextLocation(1, 5, 1, 1))}
        << QList<Class>{Class(TextLocation(1, 5, 1, 1))}
        << QList<Enum>{Enum(TextLocation(6, 8, 1, 1))}
        << QList<Enum>{Enum(TextLocation(6, 8, 1, 1))};

    QTest::newRow("Class hasn`t nested enum, they are both on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 100))}
        << QList<Class>{Class(TextLocation(1, 1, 1, 100))}
        << QList<Enum>{Enum(TextLocation(1, 1, 101, 200))}
        << QList<Enum>{Enum(TextLocation(1, 1, 101, 200))};

    QTest::newRow("There are two classes and one enum. Noone class has nested enum")
        << QList<Class>{Class(TextLocation(1, 5, 1, 1)), Class(TextLocation(6, 9, 1, 1))}
        << QList<Class>{Class(TextLocation(1, 5, 1, 1)), Class(TextLocation(6, 9, 1, 1))}
        << QList<Enum>{Enum(TextLocation(10, 11, 1, 1))}
        << QList<Enum>{Enum(TextLocation(10, 11, 1, 1))};
    
    QTest::newRow("There are two classes and one enum. Noone class has nested enum, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 10)), Class(TextLocation(1, 1, 20, 30))}
        << QList<Class>{Class(TextLocation(1, 1, 1, 10)), Class(TextLocation(1, 1, 20, 30))}
        << QList<Enum>{Enum(TextLocation(1, 1, 100, 120))}
        << QList<Enum>{Enum(TextLocation(1, 1, 100, 120))};

    QTest::newRow("Class has nested enum")
        << QList<Class>{Class(TextLocation(1, 5, 1, 1))}
        << QList<Class>{Class(QList<Enum>{Enum(TextLocation(2, 4, 1, 1))}, TextLocation(1, 5, 1, 1))}
        << QList<Enum>{Enum(TextLocation(2, 4, 1, 1))}
        << QList<Enum>{};

    QTest::newRow("Class has nested enum, they are both on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 100))}
        << QList<Class>{Class(QList<Enum>{Enum(TextLocation(1, 1, 2, 50))}, TextLocation(1, 1, 1, 100))}
        << QList<Enum>{Enum(TextLocation(1, 1, 2, 50))}
        << QList<Enum>{};

    QTest::newRow("There are two classes, the second one is nested into the first one, and one enum, which is nested into the second class")
        << QList<Class>{Class(TextLocation(1, 50, 1, 1)), Class(TextLocation(6, 10, 1, 1))}
        << QList<Class>{Class(TextLocation(1, 50, 1, 1)), Class(QList<Enum>{TextLocation(7, 9, 1, 1)}, TextLocation(6, 10, 1, 1))}
        << QList<Enum>{Enum(TextLocation(7, 9, 1, 1))}
        << QList<Enum>{};

    QTest::newRow("There are two classes, the first one is nested into the second one, and one enum, which is nested into the first class")
        << QList<Class>{Class(TextLocation(6, 10, 1, 1)), Class(TextLocation(1, 50, 1, 1))}
        << QList<Class>{Class(QList<Enum>{TextLocation(7, 9, 1, 1)}, TextLocation(6, 10, 1, 1)), Class(TextLocation(1, 50, 1, 1))}
        << QList<Enum>{Enum(TextLocation(7, 9, 1, 1))}
        << QList<Enum>{};

    QTest::newRow("There are two classes, the second one is nested into the first one, and one enum, which is nested into the second class, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 100)), Class(TextLocation(1, 1, 10, 20))}
        << QList<Class>{Class(TextLocation(1, 1, 1, 100)), Class(QList<Enum>{TextLocation(1, 1, 15, 17)}, TextLocation(1, 1, 10, 20))}
        << QList<Enum>{Enum(TextLocation(1, 1, 15, 17))}
        << QList<Enum>{};

    QTest::newRow("There are two classes, the first one is nested into the second one, and one enum, which is nested into the first class, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 10, 20)), Class(TextLocation(1, 1, 1, 100))}
        << QList<Class>{Class(QList<Enum>{TextLocation(1, 1, 15, 17)}, TextLocation(1, 1, 10, 20)), Class(TextLocation(1, 1, 1, 100))}
        << QList<Enum>{Enum(TextLocation(1, 1, 15, 17))}
        << QList<Enum>{};

    QTest::newRow("Class has nested class and nested enum")
        << QList<Class>{Class(TextLocation(1, 50, 1, 1)), Class(TextLocation(2, 40, 1, 1))}
        << QList<Class>{Class(QList<Enum>{TextLocation(41, 49, 1, 1)}, TextLocation(1, 50, 1, 1)), Class(TextLocation(2, 40, 1, 1))}
        << QList<Enum>{Enum(TextLocation(41, 49, 1, 1))}
        << QList<Enum>{};

    QTest::newRow("Class has nested class and nested enum, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 100)), Class(TextLocation(1, 1, 30, 40))}
        << QList<Class>{Class(QList<Enum>{TextLocation(1, 1, 10, 20)}, TextLocation(1, 1, 1, 100)), Class(TextLocation(1, 1, 30, 40))}
        << QList<Enum>{Enum(TextLocation(1, 1, 10, 20))}
        << QList<Enum>{};
}

void Test_TreeFuncs::test_findParentsToEnums()
{
    QFETCH(QList<Class>, classes);
    QFETCH(QList<Class>, expectedClasses);
    QFETCH(QList<Enum>, enums);
    QFETCH(QList<Enum>, expectedEnums);

    findParentsToEnums(classes, enums);
    QVERIFY2(classes == expectedClasses, "Classes are not equal");
    QVERIFY2(enums == expectedEnums, "Enums are not equal");
}

void Test_TreeFuncs::test_findParentsToInterfaces_data()
{
    QTest::addColumn<QList<Class>>("classes");
    QTest::addColumn<QList<Class>>("expectedClasses");
    QTest::addColumn<QList<Interface>>("interfaces");
    QTest::addColumn<QList<Interface>>("expectedInterfaces");

    QTest::newRow("Class hasn`t nested interface")
        << QList<Class>{Class(TextLocation(1, 5, 1, 1))}
        << QList<Class>{Class(TextLocation(1, 5, 1, 1))}
        << QList<Interface>{Interface(TextLocation(6, 8, 1, 1))}
        << QList<Interface>{Interface(TextLocation(6, 8, 1, 1))};

    QTest::newRow("Class hasn`t nested interface, they are both on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 100))}
        << QList<Class>{Class(TextLocation(1, 1, 1, 100))}
        << QList<Interface>{Interface(TextLocation(1, 1, 101, 200))}
        << QList<Interface>{Interface(TextLocation(1, 1, 101, 200))};

    QTest::newRow("There are two classes and one interface. Noone class has nested interface")
        << QList<Class>{Class(TextLocation(1, 5, 1, 1)), Class(TextLocation(6, 9, 1, 1))}
        << QList<Class>{Class(TextLocation(1, 5, 1, 1)), Class(TextLocation(6, 9, 1, 1))}
        << QList<Interface>{Interface(TextLocation(10, 11, 1, 1))}
        << QList<Interface>{Interface(TextLocation(10, 11, 1, 1))};

    QTest::newRow("There are two classes and one interface. Noone class has nested interfaceex, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 10)), Class(TextLocation(1, 1, 20, 30))}
        << QList<Class>{Class(TextLocation(1, 1, 1, 10)), Class(TextLocation(1, 1, 20, 30))}
        << QList<Interface>{Interface(TextLocation(1, 1, 100, 120))}
        << QList<Interface>{Interface(TextLocation(1, 1, 100, 120))};

    QTest::newRow("Class has nested interface")
        << QList<Class>{Class(TextLocation(1, 5, 1, 1))}
        << QList<Class>{Class(QList<Interface>{Interface(TextLocation(2, 4, 1, 1))}, TextLocation(1, 5, 1, 1))}
        << QList<Interface>{Interface(TextLocation(2, 4, 1, 1))}
        << QList<Interface>{};

    QTest::newRow("Class has nested interface, they are both on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 100))}
        << QList<Class>{Class(QList<Interface>{Interface(TextLocation(1, 1, 2, 50))}, TextLocation(1, 1, 1, 100))}
        << QList<Interface>{Interface(TextLocation(1, 1, 2, 50))}
        << QList<Interface>{};

    QTest::newRow("There are two classes, the second one is nested into the first one, and one interface, which is nested into the second class")
        << QList<Class>{Class(TextLocation(1, 50, 1, 1)), Class(TextLocation(6, 10, 1, 1))}
        << QList<Class>{Class(TextLocation(1, 50, 1, 1)), Class(QList<Interface>{TextLocation(7, 9, 1, 1)}, TextLocation(6, 10, 1, 1))}
        << QList<Interface>{Interface(TextLocation(7, 9, 1, 1))}
        << QList<Interface>{};

    QTest::newRow("There are two classes, the first one is nested into the second one, and one interface, which is nested into the first class")
        << QList<Class>{Class(TextLocation(6, 10, 1, 1)), Class(TextLocation(1, 50, 1, 1))}
        << QList<Class>{Class(QList<Interface>{TextLocation(7, 9, 1, 1)}, TextLocation(6, 10, 1, 1)), Class(TextLocation(1, 50, 1, 1))}
        << QList<Interface>{Interface(TextLocation(7, 9, 1, 1))}
        << QList<Interface>{};

    QTest::newRow("There are two classes, the second one is nested into the first one, and one interface, which is nested into the second class, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 100)), Class(TextLocation(1, 1, 10, 20))}
        << QList<Class>{Class(TextLocation(1, 1, 1, 100)), Class(QList<Interface>{TextLocation(1, 1, 15, 17)}, TextLocation(1, 1, 10, 20))}
        << QList<Interface>{Interface(TextLocation(1, 1, 15, 17))}
        << QList<Interface>{};

    QTest::newRow("There are two classes, the first one is nested into the second one, and one interface, which is nested into the first class, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 10, 20)), Class(TextLocation(1, 1, 1, 100))}
        << QList<Class>{Class(QList<Interface>{TextLocation(1, 1, 15, 17)}, TextLocation(1, 1, 10, 20)), Class(TextLocation(1, 1, 1, 100))}
        << QList<Interface>{Interface(TextLocation(1, 1, 15, 17))}
        << QList<Interface>{};

    QTest::newRow("Class has nested class and nested interface")
        << QList<Class>{Class(TextLocation(1, 50, 1, 1)), Class(TextLocation(2, 40, 1, 1))}
        << QList<Class>{Class(QList<Interface>{TextLocation(41, 49, 1, 1)}, TextLocation(1, 50, 1, 1)), Class(TextLocation(2, 40, 1, 1))}
        << QList<Interface>{Interface(TextLocation(41, 49, 1, 1))}
        << QList<Interface>{};

    QTest::newRow("Class has nested class and nested interface, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 100)), Class(TextLocation(1, 1, 30, 40))}
        << QList<Class>{Class(QList<Interface>{TextLocation(1, 1, 10, 20)}, TextLocation(1, 1, 1, 100)), Class(TextLocation(1, 1, 30, 40))}
        << QList<Interface>{Interface(TextLocation(1, 1, 10, 20))}
        << QList<Interface>{};
}

void Test_TreeFuncs::test_findParentsToInterfaces()
{
    QFETCH(QList<Class>, classes);
    QFETCH(QList<Class>, expectedClasses);
    QFETCH(QList<Interface>, interfaces);
    QFETCH(QList<Interface>, expectedInterfaces);

    findParentsToInterfaces(classes, interfaces);
    QVERIFY2(classes == expectedClasses, "Classes are not equal");
    QVERIFY2(interfaces == expectedInterfaces, "Interfaces are not equal");
}

void Test_TreeFuncs::test_findParentsToClasses_data()
{
    QTest::addColumn<QList<Class>>("classes");
    QTest::addColumn<QList<Class>>("expectedClasses");

    QTest::newRow("Class hasn`t nested class")
        << QList<Class>{Class(TextLocation(1, 5, 1, 1)), Class(TextLocation(6, 8, 1, 1))}
        << QList<Class>{Class(TextLocation(1, 5, 1, 1)), Class(TextLocation(6, 8, 1, 1))};

    QTest::newRow("Class hasn`t nested class, they are both on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 2)), Class(TextLocation(1, 1, 3, 4))}
        << QList<Class>{Class(TextLocation(1, 1, 1, 2)), Class(TextLocation(1, 1, 3, 4))};

    QTest::newRow("The first class has nested class")
        << QList<Class>{Class(TextLocation(1, 10, 1, 1)), Class(TextLocation(2, 3, 1, 1))}
        << QList<Class>{Class(QList<Class>{Class(TextLocation(2, 3, 1, 1))}, TextLocation(1, 10, 1, 1))};

    QTest::newRow("The first class has nested class, they are both on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 100)), Class(TextLocation(1, 1, 2, 3))}
        << QList<Class>{Class(QList<Class>{Class(TextLocation(1, 1, 2, 3))}, TextLocation(1, 1, 1, 100))};

    QTest::newRow("The second class has nested class")
        << QList<Class>{Class(TextLocation(2, 3, 1, 1)), Class(TextLocation(1, 10, 1, 1))}
        << QList<Class>{Class(QList<Class>{Class(TextLocation(2, 3, 1, 1))}, TextLocation(1, 10, 1, 1))};

    QTest::newRow("The second class has nested class, they are both on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 2, 3)), Class(TextLocation(1, 1, 1, 100))}
        << QList<Class>{Class(QList<Class>{Class(TextLocation(1, 1, 2, 3))}, TextLocation(1, 1, 1, 100))};
}

void Test_TreeFuncs::test_findParentsToClasses()
{
    QFETCH(QList<Class>, classes);
    QFETCH(QList<Class>, expectedClasses);

    findParentsToClasses(classes);
    QVERIFY2(classes == expectedClasses, "Classes are not equal");
}

void Test_TreeFuncs::test_findParentsToFields_data()
{
    QTest::addColumn<QList<Class>>("classes");
    QTest::addColumn<QList<Class>>("expectedClasses");
    QTest::addColumn<QList<Interface>>("interfaces");
    QTest::addColumn<QList<Interface>>("expectedInterfaces");
    QTest::addColumn<QList<Field>>("fields");
    QTest::addColumn<QList<Field>>("expectedFields");

    QTest::newRow("Class and interface haven`t nested field")
        << QList<Class>{Class(TextLocation(1, 2, 3, 4))}
        << QList<Class>{Class(TextLocation(1, 2, 3, 4))}
        << QList<Interface>{Interface(TextLocation(3, 4, 5, 6))}
        << QList<Interface>{Interface(TextLocation(3, 4, 5, 6))}
        << QList<Field>{Field(TextLocation(5, 6, 7, 8))}
        << QList<Field>{Field(TextLocation(5, 6, 7, 8))};

    QTest::newRow("Class has nested field and interface hasn`t")
        << QList<Class>{Class(TextLocation(1, 20, 3, 4))}
        << QList<Class>{Class(QList<Field>{Field(TextLocation(5, 6, 7, 8))}, TextLocation(1, 20, 3, 4))}
        << QList<Interface>{Interface(TextLocation(3, 4, 5, 6))}
        << QList<Interface>{Interface(TextLocation(3, 4, 5, 6))}
        << QList<Field>{Field(TextLocation(5, 6, 7, 8))}
        << QList<Field>{};

    QTest::newRow("Class has nested field and interface has nested field")
        << QList<Class>{Class(TextLocation(1, 20, 3, 4))}
        << QList<Class>{Class(QList<Field>{Field(TextLocation(5, 6, 7, 8))}, TextLocation(1, 20, 3, 4))}
        << QList<Interface>{Interface(TextLocation(30, 40, 5, 6))}
        << QList<Interface>{Interface(QList<Field>{Field(TextLocation(31, 32, 7, 8))}, TextLocation(30, 40, 5, 6))}
        << QList<Field>{Field(TextLocation(5, 6, 7, 8)), Field(TextLocation(31, 32, 7, 8))}
        << QList<Field>{};

    QTest::newRow("Class has nested field and interface has nested field, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 20))}
        << QList<Class>{Class(QList<Field>{Field(TextLocation(1, 1, 7, 8))}, TextLocation(1, 1, 1, 20))}
        << QList<Interface>{Interface(TextLocation(1, 1, 21, 30))}
        << QList<Interface>{Interface(QList<Field>{Field(TextLocation(1, 1, 25, 26))}, TextLocation(1, 1, 21, 30))}
        << QList<Field>{Field(TextLocation(1, 1, 7, 8)), Field(TextLocation(1, 1, 25, 26))}
        << QList<Field>{};

    QTest::newRow("Class has two fields and interface hasn`t any fields")
        << QList<Class>{Class(TextLocation(1, 100, 1, 20))}
        << QList<Class>{Class(QList<Field>{Field(TextLocation(10, 11, 7, 8)), Field(TextLocation(20, 21, 25, 26))}, TextLocation(1, 100, 1, 20))}
        << QList<Interface>{Interface(TextLocation(101, 200, 1, 1))}
        << QList<Interface>{Interface(TextLocation(101, 200, 1, 1))}
        << QList<Field>{Field(TextLocation(10, 11, 7, 8)), Field(TextLocation(20, 21, 25, 26))}
        << QList<Field>{};
}

void Test_TreeFuncs::test_findParentsToFields()
{
    QFETCH(QList<Class>, classes);
    QFETCH(QList<Class>, expectedClasses);
    QFETCH(QList<Interface>, interfaces);
    QFETCH(QList<Interface>, expectedInterfaces);
    QFETCH(QList<Field>, fields);
    QFETCH(QList<Field>, expectedFields);

    findParentsToFields(classes, interfaces, fields);
    QVERIFY2(classes == expectedClasses, "Classes are not equal");
    QVERIFY2(interfaces == expectedInterfaces, "Interfaces are not equal");
    QVERIFY2(fields == expectedFields, "Fields are not equal");
}

void Test_TreeFuncs::test_findParentsToMethods_data()
{
    QTest::addColumn<QList<Class>>("classes");
    QTest::addColumn<QList<Class>>("expectedClasses");
    QTest::addColumn<QList<Interface>>("interfaces");
    QTest::addColumn<QList<Interface>>("expectedInterfaces");
    QTest::addColumn<QList<Method>>("methods");
    QTest::addColumn<QList<Method>>("expectedMethods");

    QTest::newRow("Class and interface haven`t nested field")
        << QList<Class>{Class(TextLocation(1, 2, 3, 4))}
        << QList<Class>{Class(TextLocation(1, 2, 3, 4))}
        << QList<Interface>{Interface(TextLocation(3, 4, 5, 6))}
        << QList<Interface>{Interface(TextLocation(3, 4, 5, 6))}
        << QList<Method>{Method(TextLocation(5, 6, 7, 8))}
        << QList<Method>{Method(TextLocation(5, 6, 7, 8))};

    QTest::newRow("Class has nested method and interface hasn`t")
        << QList<Class>{Class(TextLocation(1, 20, 3, 4))}
        << QList<Class>{Class(QList<Method>{Method(TextLocation(5, 6, 7, 8))}, TextLocation(1, 20, 3, 4))}
        << QList<Interface>{Interface(TextLocation(3, 4, 5, 6))}
        << QList<Interface>{Interface(TextLocation(3, 4, 5, 6))}
        << QList<Method>{Method(TextLocation(5, 6, 7, 8))}
        << QList<Method>{};

    QTest::newRow("Class has nested method and interface has nested method")
        << QList<Class>{Class(TextLocation(1, 20, 3, 4))}
        << QList<Class>{Class(QList<Method>{Method(TextLocation(5, 6, 7, 8))}, TextLocation(1, 20, 3, 4))}
        << QList<Interface>{Interface(TextLocation(30, 40, 5, 6))}
        << QList<Interface>{Interface(QList<Method>{Method(TextLocation(31, 32, 7, 8))}, TextLocation(30, 40, 5, 6))}
        << QList<Method>{Method(TextLocation(5, 6, 7, 8)), Method(TextLocation(31, 32, 7, 8))}
        << QList<Method>{};

    QTest::newRow("Class has nested method and interface has nested method, they are all on the same line")
        << QList<Class>{Class(TextLocation(1, 1, 1, 20))}
        << QList<Class>{Class(QList<Method>{Method(TextLocation(1, 1, 7, 8))}, TextLocation(1, 1, 1, 20))}
        << QList<Interface>{Interface(TextLocation(1, 1, 21, 30))}
        << QList<Interface>{Interface(QList<Method>{Method(TextLocation(1, 1, 25, 26))}, TextLocation(1, 1, 21, 30))}
        << QList<Method>{Method(TextLocation(1, 1, 7, 8)), Method(TextLocation(1, 1, 25, 26))}
        << QList<Method>{};

    QTest::newRow("Class has two methods and interface hasn`t any methods")
        << QList<Class>{Class(TextLocation(1, 100, 1, 20))}
        << QList<Class>{Class(QList<Method>{Method(TextLocation(10, 11, 7, 8)), Method(TextLocation(20, 21, 25, 26))}, TextLocation(1, 100, 1, 20))}
        << QList<Interface>{Interface(TextLocation(101, 200, 1, 1))}
        << QList<Interface>{Interface(TextLocation(101, 200, 1, 1))}
        << QList<Method>{Method(TextLocation(10, 11, 7, 8)), Method(TextLocation(20, 21, 25, 26))}
        << QList<Method>{};
}

void Test_TreeFuncs::test_findParentsToMethods()
{
    QFETCH(QList<Class>, classes);
    QFETCH(QList<Class>, expectedClasses);
    QFETCH(QList<Interface>, interfaces);
    QFETCH(QList<Interface>, expectedInterfaces);
    QFETCH(QList<Method>, methods);
    QFETCH(QList<Method>, expectedMethods);

    findParentsToMethods(classes, interfaces, methods);
    QVERIFY2(classes == expectedClasses, "Classes are not equal");
    QVERIFY2(interfaces == expectedInterfaces, "Interfaces are not equal");
    QVERIFY2(methods == expectedMethods, "Methods are not equal");
}
