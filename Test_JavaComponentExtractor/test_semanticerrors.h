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

    void test_checkEnums_data();
    void test_checkEnums();

    void test_checkClasses_data();
    void test_checkClasses();

    void test_checkFields_data();
    void test_checkFields();

    void test_checkMethods_data();
    void test_checkMethods();
};

#endif // TEST_SEMANTICERRORS_H