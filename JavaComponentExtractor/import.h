#ifndef IMPORT_H
#define IMPORT_H

#include <QString>
#include "component.h"

// �����, ����������� ��������� ����������������� ������
class Import : public Component
{
public:
    bool isStatic = false; // ����� ������������� ����������� ����� ������
    QString importedClass;
};

#endif // IMPORT_H