/*!
*\file
*\brief Файл объявления класса компонента интерфейса.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе класс компонента интерфейса.
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <QStringList>
#include "component.h"
#include "field.h"
#include "method.h"

/*!
*\brief Класс интерфейса.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный класс описывает компонент интерфейса.
*/
class Interface : public Component
{
public:
    QStringList modificators; ///< Модификаторы.
    QString name; ///< Имя интерфейса.
    QStringList baseInterfaces; ///< Базовые интерфейсы.
    QList<Field> fields; ///< Поля интерфейса.
    QList<Method> methods; ///< Методы интерфейса.

    /*! Создает объект интерфейса на основании переданного положения. */
    Interface(const TextLocation &location = TextLocation());
    /*! Создает объект интерфейса на основании переданных полей и положения. */
    Interface(const QList<Field> &fields, const TextLocation &location);
    /*! Создает объект интерфейса на основании переданных методов и положения. */
    Interface(const QList<Method> &methods, const TextLocation &location);
    /*! Создает объект интерфейса на основании переданных модификаторов, имени, базовых интерфейсов и положения. */
    Interface(const QStringList &modificators, const QString &name, const QStringList &baseInterfaces, const TextLocation &location = TextLocation());

    /*! Сравнивает два интерфейса друг с другом. */
    bool operator==(const Interface &interface);
};

#endif // INTERFACE_H
