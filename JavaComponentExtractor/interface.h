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

    Interface();
    Interface(const TextLocation &location);
    Interface(const QList<Field> fields, const TextLocation &location);
    Interface(const QStringList &modificators, const QString &name, const QStringList &baseInterfaces);
    Interface(const QStringList &modificators, const QString &name, const QStringList &baseInterfaces, const TextLocation &location);

    bool operator==(const Interface &interface);
};

#endif // INTERFACE_H