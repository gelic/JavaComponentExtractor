#ifndef PROGRAM_H
#define PROGRAM_H

#include "package.h"
#include "import.h"
#include "enum.h"
#include "interface.h"
#include "class.h"

/*!
*\brief Класс дерева программы.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный класс описывает дерево компонентов программы.
*/
class Program
{
public:
    Package package; ///< Пакет.
    QList<Import> imports; ///< Импорты.
    QList<Enum> enums; ///< Перечисления.
    QList<Interface> interfaces; ///< Интерфейсы.
    QList<Class> classes; ///< Классы.
};

#endif // PROGRAM_H