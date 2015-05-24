#include "package.h"

Package::Package()
{
}

Package::Package(const QString &packageName)
{
    this->packageName = packageName;
}

Package::Package(const QString &packageName, const TextLocation &location)
{
    this->packageName = packageName;
    this->location = location;
}

bool Package::operator==(const Package &package)
{
    return
        this->packageName == package.packageName &&
        this->location == package.location;
}