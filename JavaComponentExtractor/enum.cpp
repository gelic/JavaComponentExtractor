#include "enum.h"

Enum::Enum(const TextLocation &location /*= TextLocation()*/)
{
    this->location = location;
}

Enum::Enum(const QStringList &modificators, const QString &name, const QStringList &enumList /*= QStringList()*/, const TextLocation &location /*= TextLocation()*/)
{
    *this = Enum::Enum(location);
    this->modificators = modificators;
    this->name = name;
    this->enumList = enumList;
}

bool Enum::operator==(const Enum &enumToCompare)
{
    return
        this->modificators == enumToCompare.modificators &&
        this->name == enumToCompare.name &&
        this->enumList == enumToCompare.enumList &&
        this->location == enumToCompare.location;
}
