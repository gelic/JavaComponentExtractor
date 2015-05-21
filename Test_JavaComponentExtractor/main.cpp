#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <vld.h>
#include "test_component.h"
#include "test_yylex.h"

int main(int argc, char *argv[])
{
    try
    {
        QTest::qExec(&Test_Component(), argc, argv);
        QTest::qExec(&Test_Yylex(), argc, argv);
    }
    catch (const QString &e)
    {
        QTextStream out(stderr);
        out << e;
    }

    return 0;
}