#ifndef TEST_SEMANTICERRORS_H
#define TEST_SEMANTICERRORS_H

#include <QObject>
#include <QtTest>
#include "../JavaComponentExtractor/semanticerrors.h"
#include "declarations.h"

class Test_SemanticErrors : public QObject
{
    Q_OBJECT

private slots:
    void test_checkNestedClassesAndInterfacesInEachInterface_data();
    void test_checkNestedClassesAndInterfacesInEachInterface();

    void test_checkDuplicates_data();
    void test_checkDuplicates();
};

#endif // TEST_SEMANTICERRORS_H