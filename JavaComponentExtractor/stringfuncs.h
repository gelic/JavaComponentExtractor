#ifndef STRINGFUNCS_H
#define STRINGFUNCS_H

#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include "textlocation.h"

/*!
* Вернуть содержимое текста между указанными начальными и конечными номерами строк и колонок
*\param[in] buffer - текст
*\param[in] location - структура, содержащая номера начальных и конечных строк и колонок
*\return требуемое содержимое
*/
QString contentBetweenPositions(const QString &buffer, const TextLocation &location) throw(const QString &);

#endif // STRINGFUNCS_H