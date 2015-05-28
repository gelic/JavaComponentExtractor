#ifndef IMPORT_H
#define IMPORT_H

#include <QString>
#include "component.h"

// Класс, описывающий компонент импортиртируемого класса
class Import : public Component
{
public:
    bool isStatic = false; // Для импорта статических методов класса
    QString importedClass;

    Import();
    Import(const QString &importedClass, bool isStatic);
    Import(const QString &importedClass, bool isStatic, const TextLocation &location);

    bool operator==(const Import &import);
};

#endif // IMPORT_H