#ifndef CLASS_H
#define CLASS_H

#include <QStringList>
#include "component.h"
#include "field.h"
#include "method.h"
#include "enum.h"
#include "interface.h"

// Класс, описывающий компонент класса
class Class : public Component
{
    QStringList modificators;
    QString name;
    QStringList baseClasses;
    QStringList implementedInterfaces;
    QList<Enum> enums;
    QList<Field> fields;
    QList<Method> methods;
    QList<Class> nestedClasses;
    QList<Interface> nestedInterfaces;
};

#endif // CLASS_H