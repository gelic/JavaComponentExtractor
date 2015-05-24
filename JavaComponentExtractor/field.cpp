#include "field.h"

Field::Field()
{
}

Field::Field(const QStringList &modificators, const QString &type, const QString &name)
{
    this->modificators = modificators;
    this->type = type;
    this->name = name;
}

Field::Field(const QStringList &modificators, const QString &type, const QString &name, const TextLocation &location)
{
    this->modificators = modificators;
    this->type = type;
    this->name = name;
    this->location = location;
}

bool Field::operator==(const Field &field)
{
    return
        this->modificators == field.modificators &&
        this->type == field.type &&
        this->name == field.name &&
        this->location == field.location;
}