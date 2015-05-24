#include "test_yyparse.h"

void Test_Yyparse::parse(const QString &text)
{
    yycolumn = 1;
    yy_scan_string(text.toStdString().c_str());
    yyparse();
    yylex_destroy();
}

void Test_Yyparse::cleanup()
{
    package.packageName = "";
    package.location = TextLocation();

    imports.clear();
    enums.clear();
    fields.clear();
    methods.clear();
    interfaces.clear();
    classes.clear();
}

void Test_Yyparse::test_yyparse_package_data()
{
    QTest::addColumn<QString>("text");
    QTest::addColumn<Package>("expectedPackage");

    QTest::newRow("Package")
        << "package com.company;"
        << Package("com.company", TextLocation(1, 1, 1, 20));

    QTest::newRow("Package with comments")
        << "package /*comment*/ com.company;"
        << Package("com.company", TextLocation(1, 1, 1, 32));
}

void Test_Yyparse::test_yyparse_package()
{
    QFETCH(QString, text);
    QFETCH(Package, expectedPackage);

    parse(text);
    QVERIFY2(package == expectedPackage, "Test failed");
}

void Test_Yyparse::test_yyparse_imports_data()
{
    QTest::addColumn<QString>("text");
    QTest::addColumn<QList<Import>>("expectedImports");

    QTest::newRow("Imports")
        << "import java.com;\nimport static java.utils.Date;"
        << QList<Import>
        {
            Import("java.com", false, TextLocation(1, 1, 1, 16)), 
            Import("java.utils.Date", true, TextLocation(2, 2, 1, 30))
        };
}

void Test_Yyparse::test_yyparse_imports()
{
    QFETCH(QString, text);
    QFETCH(QList<Import>, expectedImports);

    parse(text);
    QVERIFY2(imports == expectedImports, "Test failed");
}

void Test_Yyparse::test_yyparse_enums_data()
{
    QTest::addColumn<QString>("text");
    QTest::addColumn<QList<Enum>>("expectedEnums");

    QTest::newRow("Enums")
        << "public enum MyEnum {MONDAY, TUESDAY, WENSDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY}"
        << QList<Enum>
        {
            Enum(QStringList{"public"}, "MyEnum", QStringList{"MONDAY", "TUESDAY", "WENSDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"}, TextLocation(1, 1, 1, 81))
        };
}

void Test_Yyparse::test_yyparse_enums()
{
    QFETCH(QString, text);
    QFETCH(QList<Enum>, expectedEnums);

    parse(text);
    QVERIFY2(enums == expectedEnums, "Test failed");
}

void Test_Yyparse::test_yyparse_interfaces_data()
{
    QTest::addColumn<QString>("text");
    QTest::addColumn<QList<Interface>>("expectedInterfaces");

    QTest::newRow("Interfaces")
        << "interface MyInterface extends MyBaseInterface {\nString field;\npublic void hello();\n}"
        << QList<Interface>
        {
            Interface(QStringList(), "MyInterface", QStringList("MyBaseInterface"), TextLocation(1, 4, 1, 1))
        };
}

void Test_Yyparse::test_yyparse_interfaces()
{
    QFETCH(QString, text);
    QFETCH(QList<Interface>, expectedInterfaces);

    parse(text);
    QVERIFY2(interfaces == expectedInterfaces, "Test failed");
}

void Test_Yyparse::test_yyparse_classes_data()
{
    QTest::addColumn<QString>("text");
    QTest::addColumn<QList<Class>>("expectedClasses");

    QTest::newRow("Classes")
        << "class MyClass extends MyBaseClass implements MyInterface {\nString field;\npublic void hello() {System.out.println(\"Hello, world!\");}\n}"
        << QList<Class>
        {
            Class(QStringList(), "MyClass", QStringList("MyBaseClass"), QStringList("MyInterface"), TextLocation(1, 4, 1, 1))
        };
}

void Test_Yyparse::test_yyparse_classes()
{
    QFETCH(QString, text);
    QFETCH(QList<Class>, expectedClasses);

    parse(text);
    QVERIFY2(classes == expectedClasses, "Test failed");

}

void Test_Yyparse::test_yyparse_fields_data()
{
    QTest::addColumn<QString>("text");
    QTest::addColumn<QList<Field>>("expectedFields");

    QTest::newRow("Fields")
        << "class MyClass{\npublic int field;\n}"
        << QList<Field>
        {
            Field(QStringList{"public"}, "int", "field", TextLocation(2, 2, 1, 17))
        };
}

void Test_Yyparse::test_yyparse_fields()
{
    QFETCH(QString, text);
    QFETCH(QList<Field>, expectedFields);

    parse(text);
    QVERIFY2(fields == expectedFields, "Test failed");
}

void Test_Yyparse::test_yyparse_methods_data()
{
    QTest::addColumn<QString>("text");
    QTest::addColumn<QList<Method>>("expectedMethods");

    QTest::newRow("Methods")
        << "class MyClass{\npublic int method(bool flag) throws Exception {\nSystem.out.println(\"Hello, world!\");\n}\n}"
        << QList<Method>
        {
            Method(QStringList{"public"}, "int", "method", QList<Method::Param>{Method::Param(false, "bool", "flag")}, QStringList{"Exception"}, TextLocation(2, 4, 1, 1))
        };
}

void Test_Yyparse::test_yyparse_methods()
{
    QFETCH(QString, text);
    QFETCH(QList<Method>, expectedMethods);

    parse(text);
    QVERIFY2(methods == expectedMethods, "Test failed");
}