#ifndef METHOD_H
#define METHOD_H

#include <QStringList>
#include "component.h"

// �����, ����������� ��������� ������
class Method : public Component
{
public:
    // �����, ����������� �������� ������
    class Param
    {
    public:
        bool isFinal = false;
        QString type;
        QString name;
    };

    QStringList modificators;
    QString returnValue;
    QString name;
    QList<Param> params;
    QStringList threwExceptions;
};

#endif // METHOD_H