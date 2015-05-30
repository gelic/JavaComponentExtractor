#include "import.h"

Import::Import(const TextLocation &location)
{
    this->location = location;
}

Import::Import(const QString &importedClass, bool isStatic, const TextLocation &location /*= TextLocation()*/)
{
    *this = Import::Import(location);
    this->importedClass = importedClass;
    this->isStatic = isStatic;
}

bool Import::operator==(const Import &import)
{
    return
        this->importedClass == import.importedClass &&
        this->isStatic == import.isStatic &&
        this->location == import.location;
}
