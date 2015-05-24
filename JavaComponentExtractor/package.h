#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>
#include "component.h"

// �����, ����������� ��������� ������.
class Package : public Component
{
public:
    QString packageName;

    Package();
    Package(const QString &packageName);
    Package(const QString &packageName, const TextLocation &location);

    bool operator==(const Package &package);
};

#endif // PACKAGE_H