#ifndef CLASS_H
#define CLASS_H

#include <QStringList>
#include "component.h"
#include "field.h"
#include "method.h"
#include "enum.h"
#include "interface.h"

/*!
*\brief Класс компонента класса.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный класс описывает компонент класса.
*/
class Class : public Component
{
public:
    QStringList modificators; ///< Модификаторы.
    QString name; ///< Имя класса.
    QStringList baseClasses; ///< Базовые классы.
    QStringList implementedInterfaces; ///< Реализуемые интерфейсы.
    QList<Enum> enums; ///< Перечисления класса.
    QList<Field> fields; ///< Поля класса.
    QList<Method> methods; ///< Методы класса.
    QList<Class> nestedClasses; ///< Вложенные классы.
    QList<Interface> nestedInterfaces; ///< Вложенные интерфейсы.

    /*! Создает объект класса. */
    Class();
    /*! Создает объект класса на основании переданного положения. */
    Class(const TextLocation &location);
    /*! Создает объект класса на основании переданных вложенных классов и положения. */
    Class(const QList<Class> &nestedClasses, const TextLocation &location);
    /*! Создает объект класса на основании переданных вложенных перечислений и положения. */
    Class(const QList<Enum> &enums, const TextLocation &location);
    /*! Создает объект класса на основании переданных вложенных интерфейсов и положения. */
    Class(const QList<Interface> &interfaces, const TextLocation &location);
    /*! Создает объект класса на основании переданных вложенных полей и положения. */
    Class(const QList<Field> &fields, const TextLocation &location);
    /*! Создает объект класса на основании переданных вложенных методов и положения. */
    Class(const QList<Method> &methods, const TextLocation &location);
    /*! Создает объект класса на основании переданных модификаторов, имя, базовых классов и реализуемых интерфейсов. */
    Class(const QStringList &modificators, const QString &name, const QStringList &baseClasses, const QStringList &implementedInterfaces);
    /*! Создает объект класса на основании переданных модификаторов, имя, базовых классов, реализуемых интерфейсов и положения. */
    Class(const QStringList &modificators, const QString &name, const QStringList &baseClasses, const QStringList &implementedInterfaces, const TextLocation &location);

    /*! Сравнивает два класса друг с другом. */
    bool operator==(const Class &classToCompare);
};

#endif // CLASS_H