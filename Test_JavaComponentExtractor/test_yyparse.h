#ifndef TEST_YYPARSE_H
#define TEST_YYPARSE_H

#include <QObject>
#include <QtTest>
#include "../JavaComponentExtractor/lexer.hpp"
#include "../JavaComponentExtractor/parser.hpp"
#include "../JavaComponentExtractor/program.h"

extern Package package;
extern QList<Import> imports;
extern QList<Enum> enums;
extern QList<Interface> interfaces;
extern QList<Class> classes;
extern QList<Field> fields;
extern QList<Method> methods;
extern int yynerrs;
extern int yycolumn;

Q_DECLARE_METATYPE(Package);
Q_DECLARE_METATYPE(QList<Import>);
Q_DECLARE_METATYPE(QList<Enum>);
Q_DECLARE_METATYPE(QList<Field>);
Q_DECLARE_METATYPE(QList<Method>);
Q_DECLARE_METATYPE(QList<Interface>);
Q_DECLARE_METATYPE(QList<Class>);

class Test_Yyparse : public QObject
{
    Q_OBJECT

private:
    void parse(const QString &text);

private slots:
    void cleanup();

    void test_yyparse_package_data();
    void test_yyparse_package();

    void test_yyparse_imports_data();
    void test_yyparse_imports();

    void test_yyparse_enums_data();
    void test_yyparse_enums();

    void test_yyparse_interfaces_data();
    void test_yyparse_interfaces();

    void test_yyparse_classes_data();
    void test_yyparse_classes();

    void test_yyparse_fields_data();
    void test_yyparse_fields();

    void test_yyparse_methods_data();
    void test_yyparse_methods();
};

#endif // TEST_YYPARSE_H