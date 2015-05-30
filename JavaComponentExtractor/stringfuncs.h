/*!
*\file
*\brief Файл с объявлениями функций для работы со строками.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе определения основных функций, необходимых для работы со строками.
*/

#ifndef STRINGFUNCS_H
#define STRINGFUNCS_H

#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include "textlocation.h"

/*!
*\brief Возвращает содержимое текста между указанными начальными и конечными номерами строк и колонок.
*\details Распознает концы строк в Windows, Unix и Mac стилях.
*
* Пример:
* \code
* QString result = contentBetweenPositions("Life is amazing", TextLocation(1, 1, 1, 4)); // "Life"
* \endcode
*
*\param[in] buffer Входной текст.
*\param[in] location Структура, содержащая номера начальных и конечных строк и колонок.
*\return Содержимое между указанными позициями. Если переданный текст пуст, то возвращается также пустая строка.
*\throw QString В случае, если в тексте: 
*   - строк меньше, чем переданный номер начальной или конечной строки;
*   - в начальной или конечной строках колонок меньше, чем переданный номер начальной или конечной колонок соответственно.
*/
QString contentBetweenPositions(const QString &buffer, const TextLocation &location) throw(const QString &);

#endif // STRINGFUNCS_H
