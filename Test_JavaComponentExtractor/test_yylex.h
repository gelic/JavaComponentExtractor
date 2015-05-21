#ifndef TEST_YYPARSE_H
#define TEST_YYPARSE_H

#include <QObject>
#include <QtTest>
#include "../JavaComponentExtractor/lexer.hpp"
#include "../JavaComponentExtractor/parser.hpp"

class Test_Yylex : public QObject
{
    Q_OBJECT

private slots:
    void cleanup();
    void test_yyflex_data();
    void test_yyflex();
};

#endif // TEST_YYPARSE_H