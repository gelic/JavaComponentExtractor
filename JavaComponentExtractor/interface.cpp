#include "interface.h"

Interface::Interface()
{
}

Interface::Interface(const TextLocation &location)
{
    this->location = location;
}

Interface::Interface(const QStringList &modificators, const QString &name, const QStringList &baseInterfaces)
{
    this->modificators = modificators;
    this->name = name;
    this->baseInterfaces = baseInterfaces;
}

Interface::Interface(const QStringList &modificators, const QString &name, const QStringList &baseInterfaces, const TextLocation &location)
{
    *this = Interface::Interface(modificators, name, baseInterfaces);
    this->location = location;
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