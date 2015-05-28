#ifndef METHOD_H
#define METHOD_H

#include <QStringList>
#include "component.h"

// Класс, описывающий компонент метода
class Method : public Component
{
public:
    // Класс, описывающий параметр метода
    class Param
    {
    public:
        bool isFinal = false;
        QString type;
        QString name;

        Param(bool isFinal, const QString &type, const QString &name);

        bool operator==(const Param &param);
    };

    QStringList modificators;
    QString returnValue;
    QString name;
    QList<Param> params;
    QStringList threwExceptions;

    Method();
    Method(const TextLocation &location);
    Method(const QStringList &modificators, const QString &returnValue, const QString &name, const QList<Param> &params, const QStringList &threwExceptions);
    Method(const QStringList &modificators, const QString &returnValue, const QString &name, const QList<Param> &params, const QStringList &threwExceptions, const TextLocation &location);

    bool operator==(const Method &method);
};

#endif // METHOD_H