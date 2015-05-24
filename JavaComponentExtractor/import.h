#ifndef IMPORT_H
#define IMPORT_H

#include <QString>
#include "component.h"

// �����, ����������� ��������� ����������������� ������
class Import : public Component
{
public:
    bool isStatic = false; // ��� ������� ����������� ������� ������
    QString importedClass;

    Import();
    Import(const QString &importedClass, bool isStatic);
    Import(const QString &importedClass, bool isStatic, const TextLocation &location);

    bool operator==(const Import &import);
};

#endif // IMPORT_H