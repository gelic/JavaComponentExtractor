#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>
#include "textlocation.h"

// Класс, описывающий компонент программы
class Component
{
public:
    TextLocation location;
    QString text;

    Component();
    Component(const TextLocation &location);

    /*!
    * Проверить, вложен ли компонент в другой компонент
    *\param[in] anotherComponent - компонент, в который проверяется вложенность
    *\return признак вложенности
    */
    bool isNested(const Component &component);
};

#endif // COMPONENT_H