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
void findParentsToEnums(QList<Class> &classes, QList<Enum> &enums);

/*!
* Найти родителей интерфейсов среди классов и переместить их в них
*\param[in,out] classes - список классов
*\param[in,out] interfaces - список интерфейсов
*/
void findParentsToInterfaces(QList<Class> &classes, QList<Interface> &interfaces);

/*!
* Найти родителей классов среди классов и переместить их в них
*\param[in,out] classes - список классов
*/
void findParentsToClasses(QList<Class> &classes);

/*!
* Найти родителей полей среди классов и интерфейсов и переместить их в них
*\param[in,out] classes - список классов
*\param[in,out] interfaces - список интерфейсов
*\param[in,out] fields - список полей
*/
void findParentsToFields(QList<Class> &classes, QList<Interface> &interfaces, QList<Field> &fields);

/*!
* Найти родителей методов среди классов и интерфейсов и переместить их в них
*\param[in,out] classes - список классов
*\param[in,out] interfaces - список интерфейсов
*\param[in,out] methods - список методов
*/
void findParentsToMethods(QList<Class> &classes, QList<Interface> &interfaces, QList<Method> &methods);

/*!
* Записать в компоненты их текст
*\param[in] buffer - текст программы
*\param[in,out] package - пакет
*\param[in,out] imports - импорты
*\param[in,out] enums - перечисления
*\param[in,out] interfaces - интерфейсы
*\param[in,out] classes - классы
*\param[in,out] fields - поля
*\param[in,out] methods - методы
*/
void getComponentsText(const QString &buffer, Package &package, QList<Import> &imports, QList<Enum> &enums, QList<Interface> &interfaces, QList<Class> &classes, QList<Field> &fields, QList<Method> &methods);

/*!
* Добавить в структуру программы перечисления, интерфейсы, классы, поля и методы с учетом их иерархии
*\param[in,out] program - класс, описывающий компоненты программы
*\param[in,out] package - пакет
*\param[in,out] imports - импорты
*\param[in,out] enums - перечисления
*\param[in,out] interfaces - интерфейсы
*\param[in,out] classes - классы
*\param[in,out] fields - поля
*\param[in,out] methods - методы
*/
void addComponentsToTree(Program &program, const Package &package, const QList<Import> &imports, QList<Enum> &enums, QList<Interface> &interfaces, QList<Class> &classes, QList<Field> &fields, QList<Method> &methods);

#endif // TREENODES_H