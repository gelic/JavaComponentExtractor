#include "test_yylex.h"

void Test_Yylex::cleanup()
{
    yylex_destroy();
}

void Test_Yylex::test_yyflex_data()
{
    QTest::addColumn<QString>("buffer");
    QTest::addColumn<int>("expectation");

    QTest::newRow("true")
        << QString("true")
        << (int) BOOLLIT;

    QTest::newRow("false")
        << QString("false")
        << (int) BOOLLIT;

    QTest::newRow("Separator - (")
        << QString("(")
        << (int) '(';

    QTest::newRow("Separator - )")
        << QString(")")
        << (int) ')';

    QTest::newRow("Separator - {")
        << QString("{")
        << (int) '{';

    QTest::newRow("Separator - }")
        << QString("}")
        << (int) '}';

    QTest::newRow("Separator - [")
        << QString("[")
        << (int) '[';

    QTest::newRow("Separator - ]")
        << QString("]")
        << (int) ']';

    QTest::newRow("Separator - ;")
        << QString(";")
        << (int) ';';

    QTest::newRow("Separator - ,")
        << QString(",")
        << (int) ',';

    QTest::newRow("Separator - .")
        << QString(".")
        << (int) '.';

    QTest::newRow("Delimiter - =")
        << QString("=")
        << (int) '=';

    QTest::newRow("Delimiter - >")
        << QString(">")
        << (int) '>';

    QTest::newRow("Delimiter - <")
        << QString("<")
        << (int) '<';

    QTest::newRow("Delimiter - !")
        << QString("!")
        << (int) '!';

    QTest::newRow("Delimiter - ~")
        << QString("~")
        << (int) '~';

    QTest::newRow("Delimiter - ?")
        << QString("?")
        << (int) '?';

    QTest::newRow("Delimiter - :")
        << QString(":")
        << (int) ':';

    QTest::newRow("Delimiter - +")
        << QString("+")
        << (int) '+';

    QTest::newRow("Delimiter - -")
        << QString("-")
        << (int) '-';

    QTest::newRow("Delimiter - *")
        << QString("*")
        << (int) '*';

    QTest::newRow("Delimiter - /")
        << QString("/")
        << (int) '/';

    QTest::newRow("Delimiter - &")
        << QString("&")
        << (int) '&';

    QTest::newRow("Delimiter - |")
        << QString("|")
        << (int) '|';

    QTest::newRow("Delimiter - ^")
        << QString("^")
        << (int) '^';

    QTest::newRow("Delimiter - %")
        << QString("%")
        << (int) '%';

    QTest::newRow("Dimension")
        << QString("[]")
        << (int) OP_DIM;

    QTest::newRow("Dimension - with white spaces between")
        << QString("[  \n\t]")
        << (int) OP_DIM;

    QTest::newRow("Dimension - with multiline comment between")
        << QString("[/*comment*/]")
        << (int) OP_DIM;

    QTest::newRow("Dimension - with oneline comment between, unix line endings")
        << QString("[//comment\n]")
        << (int) OP_DIM;

    QTest::newRow("Dimension - with oneline comment between, windows line endings")
        << QString("[//comment\r\n]")
        << (int) OP_DIM;

    QTest::newRow("Dimension - with oneline comment between, mac line endings")
        << QString("[//comment\r]")
        << (int) OP_DIM;

    QTest::newRow("==")
        << QString("==")
        << (int) OP_EQ;

    QTest::newRow("<=")
        << QString("<=")
        << (int) OP_LE;

    QTest::newRow(">=")
        << QString(">=")
        << (int) OP_GE;

    QTest::newRow("!=")
        << QString("!=")
        << (int) OP_NE;

    QTest::newRow("||")
        << QString("||")
        << (int) OP_LOR;

    QTest::newRow("&&")
        << QString("&&")
        << (int) OP_LAND;

    QTest::newRow("++")
        << QString("++")
        << (int) OP_INC;

    QTest::newRow("--")
        << QString("--")
        << (int) OP_DEC;

    QTest::newRow(">>")
        << QString(">>")
        << (int) OP_SHR;

    QTest::newRow("<<")
        << QString("<<")
        << (int) OP_SHL;

    QTest::newRow(">>>")
        << QString(">>>")
        << (int) OP_SHRR;

    QTest::newRow("+=")
        << QString("+=")
        << (int) ASS_ADD;

    QTest::newRow("-=")
        << QString("-=")
        << (int) ASS_SUB;

    QTest::newRow("*=")
        << QString("*=")
        << (int) ASS_MUL;

    QTest::newRow("/=")
        << QString("/=")
        << (int) ASS_DIV;

    QTest::newRow("&=")
        << QString("&=")
        << (int) ASS_AND;

    QTest::newRow("|=")
        << QString("|=")
        << (int) ASS_OR;

    QTest::newRow("^=")
        << QString("^=")
        << (int) ASS_XOR;

    QTest::newRow("%=")
        << QString("%=")
        << (int) ASS_MOD;

    QTest::newRow("<<=")
        << QString("<<=")
        << (int) ASS_SHL;

    QTest::newRow(">>=")
        << QString(">>=")
        << (int) ASS_SHR;

    QTest::newRow(">>>=")
        << QString(">>>=")
        << (int) ASS_SHRR;

    QTest::newRow("abstract")
        << QString("abstract")
        << (int) ABSTRACT;

    QTest::newRow("public")
        << QString("public")
        << (int) PUBLIC;

    QTest::newRow("private")
        << QString("private")
        << (int) PRIVATE;

    QTest::newRow("protected")
        << QString("protected")
        << (int) PROTECTED;

    QTest::newRow("transient")
        << QString("transient")
        << (int) TRANSIENT;

    QTest::newRow("final")
        << QString("final")
        << (int) FINAL;

    QTest::newRow("volatile")
        << QString("volatile")
        << (int) VOLATILE;

    QTest::newRow("native")
        << QString("native")
        << (int) NATIVE;

    QTest::newRow("static")
        << QString("static")
        << (int) STATIC;

    QTest::newRow("synchronized")
        << QString("synchronized")
        << (int) SYNCHRONIZED;

    QTest::newRow("boolean")
        << QString("boolean")
        << (int) YYBOOLEAN;

    QTest::newRow("double")
        << QString("double")
        << (int) YYDOUBLE;

    QTest::newRow("byte")
        << QString("byte")
        << (int) YYBYTE;

    QTest::newRow("int")
        << QString("int")
        << (int) YYINT;

    QTest::newRow("void")
        << QString("void")
        << (int) YYVOID;

    QTest::newRow("float")
        << QString("float")
        << (int) YYFLOAT;

    QTest::newRow("long")
        << QString("long")
        << (int) YYLONG;

    QTest::newRow("short")
        << QString("short")
        << (int) YYSHORT;

    QTest::newRow("char")
        << QString("char")
        << (int) YYCHAR;

    QTest::newRow("String")
        << QString("String")
        << (int) YYSTRING;

    QTest::newRow("enum")
        << QString("enum")
        << (int) ENUM;

    QTest::newRow("implements")
        << QString("implements")
        << (int) IMPLEMENTS;

    QTest::newRow("package")
        << QString("package")
        << (int) PACKAGE;

    QTest::newRow("import")
        << QString("import")
        << (int) IMPORT;

    QTest::newRow("extends")
        << QString("extends")
        << (int) EXTENDS;

    QTest::newRow("interface")
        << QString("interface")
        << (int) INTERFACE;

    QTest::newRow("class")
        << QString("class")
        << (int) CLASS;

    QTest::newRow("do")
        << QString("do")
        << (int) DO;

    QTest::newRow("throw")
        << QString("throw")
        << (int) THROW;

    QTest::newRow("throws")
        << QString("throws")
        << (int) THROWS;

    QTest::newRow("break")
        << QString("break")
        << (int) BREAK;

    QTest::newRow("else")
        << QString("else")
        << (int) ELSE;

    QTest::newRow("instanceof")
        << QString("instanceof")
        << (int) INSTANCEOF;

    QTest::newRow("try")
        << QString("try")
        << (int) TRY;

    QTest::newRow("case")
        << QString("case")
        << (int) CASE;

    QTest::newRow("finally")
        << QString("finally")
        << (int) FINALLY;

    QTest::newRow("return")
        << QString("return")
        << (int) RETURN;

    QTest::newRow("catch")
        << QString("catch")
        << (int) CATCH;

    QTest::newRow("for")
        << QString("for")
        << (int) FOR;

    QTest::newRow("while")
        << QString("while")
        << (int) WHILE;

    QTest::newRow("new")
        << QString("new")
        << (int) NEW;

    QTest::newRow("super")
        << QString("super")
        << (int) SUPER;

    QTest::newRow("null")
        << QString("null")
        << (int) JNULL;

    QTest::newRow("switch")
        << QString("switch")
        << (int) SWITCH;

    QTest::newRow("continue")
        << QString("continue")
        << (int) CONTINUE;

    QTest::newRow("default")
        << QString("default")
        << (int) DEFAULT;

    QTest::newRow("if")
        << QString("if")
        << (int) IF;

    QTest::newRow("this")
        << QString("this")
        << (int) THIS;

    QTest::newRow("Identifier")
        << QString("_someId$0")
        << (int) IDENTIFIER;

    QTest::newRow("Decimal number")
        << QString("123l")
        << (int) LITERAL;

    QTest::newRow("Octal number")
        << QString("01237L")
        << (int) LITERAL;

    QTest::newRow("Hexical number")
        << QString("0XABC2")
        << (int) LITERAL;

    QTest::newRow("Float number in e notation")
        << QString("0.1e-10F")
        << (int) LITERAL;

    QTest::newRow("Float number in e notation without integer part")
        << QString(".1e-10F")
        << (int) LITERAL;

    QTest::newRow("Float number in e notation without fractional part")
        << QString("1e-10F")
        << (int) LITERAL;

    QTest::newRow("Float number")
        << QString("0.11")
        << (int) LITERAL;

    QTest::newRow("Float number without fractional part")
        << QString("11")
        << (int) LITERAL;

    QTest::newRow("Char")
        << QString("'c'")
        << (int) LITERAL;

    QTest::newRow("Escaped char")
        << QString("'\n'")
        << (int) LITERAL;

    QTest::newRow("String")
        << QString("\"some string\"")
        << (int) LITERAL;

    QTest::newRow("String with escaped chars")
        << QString("\"some string\r\n\"")
        << (int) LITERAL;
}

void Test_Yylex::test_yyflex()
{
    QFETCH(QString, buffer);
    QFETCH(int, expectation);

    yy_scan_string(buffer.toStdString().c_str());
    QVERIFY2(yylex() == expectation, "Test failed");

    if (yylval.str != nullptr)
    {
        delete yylval.str;
        yylval.str = nullptr;
    }
}