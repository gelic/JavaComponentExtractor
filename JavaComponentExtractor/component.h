/*!
*\file
*\brief Файл объявления класса компонента.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе класс компонента.
*/

#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>
#include "textlocation.h"

/*!
*\brief Класс компонента.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный класс является базовым классом для компонентов.
*/
class Component
{
public:
    TextLocation location; ///< Положение компонента в тексте.
    QString text; ///< Текст компонента.

    /*! Создает объект компонента. */
    Component();
    /*! Создает объект компонента на основании переданного положения. */
    Component(const TextLocation &location);

    /*!
    *\brief Проверить, вложен ли компонент в другой компонент.
    *\details Проверка осуществляется на основании положения компонентов.
    *\param[in] component Компонент, в который проверяется вложенность.
    *\return Признак вложенности.
    */
    bool isNested(const Component &component);
};

#endif // COMPONENT_H
