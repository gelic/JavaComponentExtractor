#include "class.h"

Class::Class()
{
}

Class::Class(const TextLocation &location)
{
    this->location = location;
}

Class::Class(const QList<Enum> &enums, const TextLocation &location)
{
    this->enums = enums;
    this->location = location;
}

Class::Class(const QStringList &modificators, const QString &name, const QStringList &baseClasses, const QStringList &implementedInterfaces)
{
    this->modificators = modificators;
    this->name = name;
    this->baseClasses = baseClasses;
    this->implementedInterfaces = implementedInterfaces;
}

Class::Class(const QStringList &modificators, const QString &name, const QStringList &baseClasses, const QStringList &implementedInterfaces, const TextLocation &location)
{
    this->modificators = modificators;
    this->name = name;
    this->baseClasses = baseClasses;
    this->implementedInterfaces = implementedInterfaces;
    this->location = location;
}

bool Class::operator==(const Class &classToCompare)
{
    return
        this->modificators == classToCompare.modificators &&
        this->name == classToCompare.name &&
        this->baseClasses == classToCompare.baseClasses &&
        this->implementedInterfaces == classToCompare.implementedInterfaces &&
        this->fields == classToCompare.fields &&
        this->methods == classToCompare.methods &&
        this->enums == classToCompare.enums &&
        this->nestedInterfaces == classToCompare.nestedInterfaces &&
        this->nestedClasses == classToCompare.nestedClasses &&
        this->location == classToCompare.location;
}