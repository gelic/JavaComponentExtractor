#ifndef TESTSTRINGFUNCS_H
#define TESTSTRINGFUNCS_H

#include <QObject>
#include <QtTest>
#include "../JavaComponentExtractor/textlocation.h"
#include "../JavaComponentExtractor/stringfuncs.h"
#include "declarations.h"

class Test_StringFuncs : public QObject
{
    Q_OBJECT

private slots:
    void test_contentBetweenPositions_data();
    void test_contentBetweenPositions();
};

#endif // TESTSTRINGFUNCS_H
