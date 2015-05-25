#include "enum.h"

Enum::Enum()
{
}

Enum::Enum(const TextLocation &location)
{
    this->location = location;
}

Enum::Enum(const QStringList &modificators, const QString &name)
{
    this->modificators = modificators;
    this->name = name;
}

Enum::Enum(const QStringList &modificators, const QString &name, const QStringList &enumList)
{
    *this = Enum::Enum(modificators, name);
    this->enumList = enumList;
}

Enum::Enum(const QStringList &modificators, const QString &name, const QStringList &enumList, const TextLocation &location)
{
    *this = Enum::Enum(modificators, name, enumList);
    this->location = location;
}

bool Enum::operator==(const Enum &enumToCompare)
{
    return
        this->modificators == enumToCompare.modificators &&
        this->name == enumToCompare.name &&
        this->enumList == enumToCompare.enumList &&
        this->location == enumToCompare.location;
}