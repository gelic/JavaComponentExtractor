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