#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>
#include "component.h"

// �����, ����������� ��������� ������.
class Package : public Component
{
public:
    QString packageName;
};

#endif // PACKAGE_H