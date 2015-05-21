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
};

#endif // FIELD_H