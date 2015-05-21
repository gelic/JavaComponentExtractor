#ifndef TEST_YYPARSE_H
#define TEST_YYPARSE_H

#include <QObject>
#include <QtTest>
#include "../JavaComponentExtractor/lexer.hpp"
#include "../JavaComponentExtractor/parser.hpp"

class Test_Yyparse : public QObject
{
    Q_OBJECT

private slots:
    void test_yyparse_data();
    void test_yyparse();
};

#endif // TEST_YYPARSE_H