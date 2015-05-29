/*!
*\file
*\brief Файл объявления класса компонента перечисления.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе класс компонента перечисления.
*/

#ifndef ENUM_H
#define ENUM_H

#include <QStringList>
#include "component.h"

/*!
*\brief Класс перечисления.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный класс описывает компонент перечисления.
*/
class Enum : public Component
{
public:
    QStringList modificators; ///< Модификаторы.
    QString name; ///< Имя перечисления.
    QStringList enumList; ///< Набор именованных констант.

    /*! Создает объект перечисления. */
    Enum();
    /*! Создает объект перечисления на основании переданного положения. */
    Enum(const TextLocation &location);
    /*! Создает объект перечисления на основании переданных модификаторов и имени перечисления. */
    Enum(const QStringList &modificators, const QString &name);
    /*! Создает объект перечисления на основании переданных модификаторов, имени перечисления и набора именованных констант. */
    Enum(const QStringList &modificators, const QString &name, const QStringList &enumList);
    /*! Создает объект перечисления на основании переданных модификаторов, имени перечисления, набора именованных констант и положения. */
    Enum(const QStringList &modificators, const QString &name, const QStringList &enumList, const TextLocation &location);

    /*! Сравнивает два перечисления друг с другом. */
    bool operator==(const Enum &enumToCompare);
};

#endif // ENUM_H
