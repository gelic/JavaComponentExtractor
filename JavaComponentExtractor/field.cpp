#include "field.h"

Field::Field(const TextLocation &location /*= TextLocation()*/)
{
    this->location = location;
}

Field::Field(const QStringList &modificators, const QString &type, const QString &name, const TextLocation &location /*= TextLocation()*/)
{
    *this = Field::Field(location);
    this->modificators = modificators;
    this->type = type;
    this->name = name;
}

bool Field::operator==(const Field &field)
{
    return
        this->modificators == field.modificators &&
        this->type == field.type &&
        this->name == field.name &&
        this->location == field.location;
}
