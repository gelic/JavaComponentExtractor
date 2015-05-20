#ifndef TEST_COMPONENT_H
#define TEST_COMPONENT_H

#include <QObject>
#include <QtTest>
#include "../JavaComponentExtractor/component.h"

Q_DECLARE_METATYPE(Component)

class Test_Component : public QObject
{
    Q_OBJECT

private slots:
    void test_isNested_data();
    void test_isNested();
};

#endif // TEST_COMPONENT_H