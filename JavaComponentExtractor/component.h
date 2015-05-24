#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>
#include "textlocation.h"

// �����, ����������� ��������� ���������
class Component
{
public:
    TextLocation location;
    QString text;

    Component();
    Component(const TextLocation &location);

    /*!
    * ���������, ������ �� ��������� � ������ ���������
    *\param[in] anotherComponent - ���������, � ������� ����������� �����������
    *\return ������� �����������
    */
    bool isNested(const Component &component);
};

#endif // COMPONENT_H