#include "method.h"

Method::Method()
{
}

Method::Method(const TextLocation &location)
{
    this->location = location;
}

Method::Method(const QStringList &modificators, const QString &returnValue, const QString &name, const QList<Param> &params, const QStringList &threwExceptions)
{
    this->modificators = modificators;
    this->returnValue = returnValue;
    this->name = name;
    this->params = params;
    this->threwExceptions = threwExceptions;
}

Method::Method(const QStringList &modificators, const QString &returnValue, const QString &name, const QList<Param> &params, const QStringList &threwExceptions, const TextLocation &location)
{
    *this = Method::Method(modificators, returnValue, name, params, threwExceptions);
    this->location = location;
}

bool Method::operator==(const Method &method)
{
    return
        this->modificators == method.modificators &&
        this->returnValue == method.returnValue &&
        this->name == method.name &&
        this->params == method.params &&
        this->threwExceptions == method.threwExceptions &&
        this->location == method.location;
}

Method::Param::Param(bool isFinal, const QString &type, const QString &name)
{
    this->isFinal = isFinal;
    this->type = type;
    this->name = name;
}

bool Method::Param::operator==(const Param &param)
{
    return
        this->isFinal == param.isFinal &&
        this->type == param.type &&
        this->name == param.name;
}
