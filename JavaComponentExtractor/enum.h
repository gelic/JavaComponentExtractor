#ifndef ENUM_H
#define ENUM_H

#include <QStringList>
#include "component.h"

// �����, ����������� ��������� ������������
class Enum : public Component
{
public:
    QStringList modificators;
    QString name;
    QStringList enumList;
};

#endif // ENUM_H