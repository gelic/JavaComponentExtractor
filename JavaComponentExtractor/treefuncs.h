#ifndef TREENODES_H
#define TREENODES_H

#include <QString>
#include <QList.h>
#include "stringfuncs.h"
#include "program.h"

/*!
* Найти родителей перечислений среди классов и переместить их в них
*\param[in,out] classes - список классов
*\param[in,out] enums - список перечислений
*/
void findParentsToEnums( QList<Class> &classes, QList<Enum> &enums );

/*!
* Найти родителей интерфейсов среди классов и переместить их в них
*\param[in,out] classes - список классов
*\param[in,out] interfaces - список интерфейсов
*/
void findParentsToInterfaces(QList<Class> &classes, QList<Interface> &interfaces);

#endif // TREENODES_H