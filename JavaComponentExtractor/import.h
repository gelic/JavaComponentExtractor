/*!
*\file
*\brief Файл объявления класса компонента импорта.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе класс компонента импорта.
*/

#ifndef IMPORT_H
#define IMPORT_H

#include <QString>
#include "component.h"

/*!
*\brief Класс импорта.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный класс описывает компонент импортируемого класса.
*/
class Import : public Component
{
public:
    bool isStatic = false; ///< Импортировать ли только статические методы класса.
    QString importedClass; ///< Импортируемый класс.

    /*! Создает объект импорта. */
    Import(const TextLocation &location);
    /*! Создает объект импорта на основании переданных импортируемого класса, флага, отвечающего за статический импорт, и положения. */
    Import(const QString &importedClass, bool isStatic, const TextLocation &location = TextLocation());

    /*! Сравнивает два импорта друг с другом. */
    bool operator==(const Import &import);
};

#endif // IMPORT_H
