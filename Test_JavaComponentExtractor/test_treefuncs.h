#ifndef TESTTREEFUNCS_H
#define TESTTREEFUNCS_H

#include <QObject>
#include <QtTest/QtTest>
#include "../JavaComponentExtractor/treefuncs.h"
#include "declarations.h"

class Test_TreeFuncs : public QObject
{
    Q_OBJECT

private slots:
    void test_findParentsToEnums_data();
    void test_findParentsToEnums();
};

#endif // TESTTREEFUNCS_H