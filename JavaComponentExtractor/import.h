#ifndef IMPORT_H
#define IMPORT_H

#include <QString>
#include "component.h"

// Класс, описывающий компонент импортиртируемого класса
class Import : public Component
{
public:
    bool isStatic = false; // Можно импортировать статические члены класса
    QString importedClass;
};

#endif // IMPORT_H