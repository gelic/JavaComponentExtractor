#ifndef TREENODES_H
#define TREENODES_H

#include <QString>
#include <QList.h>
#include "stringfuncs.h"
#include "program.h"

/*!
* Ќайти родителей перечислений среди классов и переместить их в них
*\param[in,out] classes - список классов
*\param[in,out] enums - список перечислений
*/
void findParentsToEnums( QList<Class> &classes, QList<Enum> &enums );

/*!
* Ќайти родителей интерфейсов среди классов и переместить их в них
*\param[in,out] classes - список классов
*\param[in,out] interfaces - список интерфейсов
*/
void findParentsToInterfaces(QList<Class> &classes, QList<Interface> &interfaces);

/*!
* Ќайти родителей классов среди классов и переместить их в них
*\param[in,out] classes - список классов
*/
void findParentsToClasses(QList<Class> &classes);

/*!
* Ќайти родителей полей среди классов и интерфейсов и переместить их в них
*\param[in,out] classes - список классов
*\param[in,out] interfaces - список интерфейсов
*\param[in,out] fields - список полей
*/
void findParentsToFields(QList<Class> &classes, QList<Interface> &interfaces, QList<Field> &fields);

/*!
* Ќайти родителей методов среди классов и интерфейсов и переместить их в них
*\param[in,out] classes - список классов
*\param[in,out] interfaces - список интерфейсов
*\param[in,out] methods - список методов
*/
void findParentsToMethods(QList<Class> &classes, QList<Interface> &interfaces, QList<Method> &methods);

#endif // TREENODES_H