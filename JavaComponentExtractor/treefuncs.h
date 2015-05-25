#ifndef TREENODES_H
#define TREENODES_H

#include <QString>
#include <QList.h>
#include "stringfuncs.h"
#include "program.h"

/*!
* Перераспределить перечисления с учетом их вложенности в классы
*\param[in,out] classes - список классов
*\param[in,out] enums - список перечислений
*/
void findParentsToEnums( QList<Class> &classes, QList<Enum> &enums );

#endif // TREENODES_H