#include "import.h"

Import::Import()
{
}

Import::Import(const QString &importedClass, bool isStatic)
{
    this->importedClass = importedClass;
    this->isStatic = isStatic;
}

Import::Import(const QString &importedClass, bool isStatic, const TextLocation &location)
{
    this->importedClass = importedClass;
    this->isStatic = isStatic;
    this->location = location;
}

bool Import::operator==(const Import &import)
{
    return
        this->importedClass == import.importedClass &&
        this->isStatic == import.isStatic &&
        this->location == import.location;
}