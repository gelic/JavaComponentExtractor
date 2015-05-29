/*!
*\file
*\brief Файл объявления класса компонента метода.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе класс компонента метода.
*/

#ifndef METHOD_H
#define METHOD_H

#include <QStringList>
#include "component.h"

/*!
*\brief Класс метода.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный класс описывает компонент метода.
*/
class Method : public Component
{
public:
    /*!
    *\brief Класс параметра метода.
    *\author Александр Мелихов amelihovv@ya.ru.
    *
    * Данный класс описывает параметр метода.
    */
    class Param
    {
    public:
        bool isFinal = false; ///< Является ли параметр константным.
        QString type; ///< Тип параметра.
        QString name; ///< Имя параметра.

        /*! Создает объект параметра на основании переданных флага, описывающего, является ли параметр константным, типа параметра и его имени. */
        Param(bool isFinal, const QString &type, const QString &name);

        /*! Сравнивает два параметра метода друг с другом. */
        bool operator==(const Param &param);
    };

    QStringList modificators; ///< Модификаторы.
    QString returnValue; ///< Возвращаемое значение.
    QString name; ///< Имя метода.
    QList<Param> params; // Параметры метода.
    QStringList threwExceptions; // Бросаемые исключения.

    /*! Создает объект метода. */
    Method();
    /*! Создает объект метода на основании переданного положения. */
    Method(const TextLocation &location);
    /*! Создает объект метода на основании переданных модификаторов, возвращаемого значения, имени, параметров и бросаемых исключений. */
    Method(const QStringList &modificators, const QString &returnValue, const QString &name, const QList<Param> &params, const QStringList &threwExceptions);
    /*! Создает объект метода на основании переданных модификаторов, возвращаемого значения, имени, параметров, бросаемых исключений и положения. */
    Method(const QStringList &modificators, const QString &returnValue, const QString &name, const QList<Param> &params, const QStringList &threwExceptions, const TextLocation &location);

    /*! Сравнивает два метода друг с другом. */
    bool operator==(const Method &method);
};

#endif // METHOD_H
