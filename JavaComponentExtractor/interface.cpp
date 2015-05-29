#include "interface.h"

Interface::Interface(const TextLocation &location /*= TextLocation()*/)
{
    this->location = location;
}

Interface::Interface(const QList<Field> &fields, const TextLocation &location)
{
    *this = Interface::Interface(location);
    this->fields = fields;
}

Interface::Interface(const QList<Method> &methods, const TextLocation &location)
{
    *this = Interface::Interface(location);
    this->methods = methods;
}

Interface::Interface(const QStringList &modificators, const QString &name, const QStringList &baseInterfaces, const TextLocation &location /*= TextLocation()*/)
{
    *this = Interface::Interface(location);
    this->modificators = modificators;
    this->name = name;
    this->baseInterfaces = baseInterfaces;
}

bool Interface::operator==(const Interface &interface)
{
    return
        this->modificators == interface.modificators &&
        this->name == interface.name &&
        this->baseInterfaces == interface.baseInterfaces &&
        this->fields == interface.fields &&
        this->methods == interface.methods &&
        this->location == interface.location;
}
