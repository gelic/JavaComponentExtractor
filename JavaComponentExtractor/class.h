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
public:
    QStringList modificators;
    QString name;
    QStringList baseClasses;
    QStringList implementedInterfaces;
    QList<Enum> enums;
    QList<Field> fields;
    QList<Method> methods;
    QList<Class> nestedClasses;
    QList<Interface> nestedInterfaces;

    Class();
    Class(const TextLocation &location);
    Class(const QList<Enum> &enums, const TextLocation &location);
    Class(const QList<Interface> &interfaces, const TextLocation &location);
    Class(const QStringList &modificators, const QString &name, const QStringList &baseClasses, const QStringList &implementedInterfaces);
    Class(const QStringList &modificators, const QString &name, const QStringList &baseClasses, const QStringList &implementedInterfaces, const TextLocation &location);

    bool operator==(const Class &classToCompare);
};

#endif // CLASS_H