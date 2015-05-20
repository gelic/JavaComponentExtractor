#include <QtCore/QCoreApplication>
#include <QTextStream>
#include "test_component.h"

int main(int argc, char *argv[])
{
    try
    {
        QTest::qExec(new Test_Component, argc, argv);
    }
    catch (const QString &e)
    {
        QTextStream out(stderr);
        out << e;
    }

    return 0;
}