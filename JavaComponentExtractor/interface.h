#ifndef INTERFACE_H
#define INTERFACE_H

#include <QStringList>
#include "component.h"
#include "field.h"
#include "method.h"

// Класс, описывающий компонент интерфейса
class Interface : public Component
{
public:
    QStringList modificators;
    QString name;
    QStringList baseInterfaces;
    QList<Field> fields;
    QList<Method> methods;
};

#endif // INTERFACE_H