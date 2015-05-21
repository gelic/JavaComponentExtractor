#ifndef ENUM_H
#define ENUM_H

#include <QStringList>
#include "component.h"

// Класс, описывающий компонент перечисления
class Enum : public Component
{
public:
    QStringList modificators;
    QString name;
    QStringList enumList;
};

#endif // ENUM_H