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

    Enum();
    Enum(const QStringList &modificators, const QString &name);
    Enum(const QStringList &modificators, const QString &name, const QStringList &enumList);
    Enum(const QStringList &modificators, const QString &name, const QStringList &enumList, const TextLocation &location);

    bool operator==(const Enum &enumToCompare);
};

#endif // ENUM_H