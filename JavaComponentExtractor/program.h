#ifndef PROGRAM_H
#define PROGRAM_H

#include "package.h"
#include "import.h"
#include "enum.h"
#include "interface.h"
#include "class.h"

// �����, ���������� ���������� � ����������� ��������� � �� �������������
class Program
{
public:
    Package package;
    QList<Import> imports;
    QList<Enum> enums;
    QList<Interface> interfaces;
    QList<Class> classes;
};

#endif // PROGRAM_H