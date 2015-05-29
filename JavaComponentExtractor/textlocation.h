/*!
*\file
*\brief Файл объявления класса положения компонента в тексте.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе класс положения компонента в тексте.
*/

#ifndef LOCATION_H
#define LOCATION_H

#include <QString>

/*!
*\brief Класс положения в тексте.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный класс описывает положение компонента в тексте.
*/
class TextLocation
{
public:
    int firstLine = 0; ///< Начальная строка.
    int lastLine = 0; ///< Конечная строка.
    int firstColumn = 0; ///< Начальная колонка.
    int lastColumn = 0; ///< Конечная колонка.
    QString fileName; ///< Файл, в котором расположен компонент.

    /*! Создает объект положения. */
    TextLocation();
    /*! Создает объект положения на основании переданных начальных и конечных строк и колонок. */
    TextLocation(int firstLine, int lastLine, int firstColumn, int lastColumn);
    /*! Создает объект положения на основании переданных начальных и конечных строк и колонок, а также имени файла. */
    TextLocation(int firstLine, int lastLine, int firstColumn, int lastColumn, const QString &fileName);

    /*! Сравнивает два положения друг с другом. */
    bool operator==(const TextLocation &location);
};

#endif // LOCATION_H
