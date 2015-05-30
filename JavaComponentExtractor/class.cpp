#include "class.h"

Class::Class(const TextLocation &location /*= TextLocation()*/)
{
    this->location = location;
}

Class::Class(const QList<Class> &nestedClasses, const TextLocation &location)
{
    *this = Class::Class(location);
    this->nestedClasses = nestedClasses;
}

Class::Class(const QList<Enum> &enums, const TextLocation &location)
{
    *this = Class::Class(location);
    this->enums = enums;
}

Class::Class(const QList<Interface> &interfaces, const TextLocation &location)
{
    *this = Class::Class(location);
    this->nestedInterfaces = interfaces;
}

Class::Class(const QList<Field> &fields, const TextLocation &location)
{
    *this = Class::Class(location);
    this->fields = fields;
}

Class::Class(const QList<Method> &methods, const TextLocation &location)
{
    *this = Class::Class(location);
    this->methods = methods;
}

Class::Class(const QStringList &modificators, const QString &name, const QStringList &baseClasses, const QStringList &implementedInterfaces, const TextLocation &location /*= TextLocation()*/)
{
    *this = Class::Class(location);
    this->modificators = modificators;
    this->name = name;
    this->baseClasses = baseClasses;
    this->implementedInterfaces = implementedInterfaces;
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
