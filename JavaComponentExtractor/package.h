#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>
#include "component.h"

// Класс, описывающий компонент пакета.
class Package : public Component
{
public:
    QString packageName;
};

#endif // PACKAGE_H