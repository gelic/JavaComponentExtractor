#ifndef FIELD_H
#define FIELD_H

#include <QStringList>
#include "component.h"

// Класс, описывающий компонент поля
class Field : public Component
{
public:
    QStringList modificators;
    QString type;
    QString name;

    Field();
    Field(const QStringList &modificators, const QString &type, const QString &name);
    Field(const QStringList &modificators, const QString &type, const QString &name, const TextLocation &location);

    bool operator==(const Field &field);
};

#endif // FIELD_H