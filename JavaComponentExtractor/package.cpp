#include "package.h"

Package::Package(const TextLocation &location /*= TextLocation()*/)
{
    this->location = location;
}

Package::Package(const QString &packageName, const TextLocation &location /*= TextLocation()*/)
{
    *this = Package::Package(location);
    this->packageName = packageName;
}

bool Package::operator==(const Package &package)
{
    return
        this->packageName == package.packageName &&
        this->location == package.location;
}
