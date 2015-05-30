/*!
*\file
*\brief Файл с объявлениями функций для работы с деревом программы.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе определения основных функций, необходимых для работы с деревом программы.
*/

#ifndef TREENODES_H
#define TREENODES_H

#include <QString>
#include <QList.h>
#include "stringfuncs.h"
#include "program.h"

/*!
* Найти родителей перечислений среди классов и переместить их в них
*\param[in,out] classes Список классов.
*\param[in,out] enums Список перечислений.
*/
void findParentsToEnums(QList<Class> &classes, QList<Enum> &enums);

/*!
* Найти родителей интерфейсов среди классов и переместить их в них
*\param[in,out] classes Список классов.
*\param[in,out] interfaces Список интерфейсов.
*/
void findParentsToInterfaces(QList<Class> &classes, QList<Interface> &interfaces);

/*!
* Найти родителей классов среди классов и переместить их в них
*\param[in,out] classes Список классов.
*/
void findParentsToClasses(QList<Class> &classes);

/*!
* Найти родителей полей среди классов и интерфейсов и переместить их в них
*\param[in,out] classes Список классов.
*\param[in,out] interfaces Список интерфейсов.
*\param[in,out] fields Список полей.
*/
void findParentsToFields(QList<Class> &classes, QList<Interface> &interfaces, QList<Field> &fields);

/*!
* Найти родителей методов среди классов и интерфейсов и переместить их в них
*\param[in,out] classes Список классов
*\param[in,out] interfaces Список интерфейсов.
*\param[in,out] methods Список методов.
*/
void findParentsToMethods(QList<Class> &classes, QList<Interface> &interfaces, QList<Method> &methods);

/*!
* Записать в компоненты их текст.
*\param[in] buffer екст программы.
*\param[in,out] package Пакет.
*\param[in,out] imports Импорты.
*\param[in,out] enums Перечисления.
*\param[in,out] interfaces Интерфейсы.
*\param[in,out] classes Классы.
*\param[in,out] fields Поля.
*\param[in,out] methods Методы.
*/
void getComponentsText(const QString &buffer, Package &package, QList<Import> &imports, QList<Enum> &enums, QList<Interface> &interfaces, QList<Class> &classes, QList<Field> &fields, QList<Method> &methods);

/*!
* Добавить в структуру программы перечисления, интерфейсы, классы, поля и методы с учетом их иерархии.
*\param[in,out] program Класс, описывающий компоненты программы.
*\param[in,out] package Пакет.
*\param[in,out] imports Импорты.
*\param[in,out] enums Перечисления.
*\param[in,out] interfaces Интерфейсы.
*\param[in,out] classes Классы.
*\param[in,out] fields Поля.
*\param[in,out] methods Методы.
*/
void addComponentsToTree(Program &program, const Package &package, const QList<Import> &imports, QList<Enum> &enums, QList<Interface> &interfaces, QList<Class> &classes, QList<Field> &fields, QList<Method> &methods);

#endif // TREENODES_H
