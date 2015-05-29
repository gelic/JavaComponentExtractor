#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <vld.h>
#include "test_component.h"
#include "test_yylex.h"
#include "test_yyparse.h"
#include "test_stringfuncs.h"
#include "test_treefuncs.h"
#include "test_semanticerrors.h"

int main(int argc, char *argv[])
{
    try
    {
        QTest::qExec(&Test_Component(), argc, argv);
        QTest::qExec(&Test_Yylex(), argc, argv);
        QTest::qExec(&Test_Yyparse(), argc, argv);
        QTest::qExec(&Test_StringFuncs(), argc, argv);
        QTest::qExec(&Test_TreeFuncs(), argc, argv);
        QTest::qExec(&Test_SemanticErrors(), argc, argv);
    }
    catch (const QString &e)
    {
        QTextStream out(stderr);
        out << e;
    }

    return 0;
}
