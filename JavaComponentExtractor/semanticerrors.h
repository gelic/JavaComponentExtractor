/*!
*\file
*\brief Файл с объявлениями функций для поиска семантических ошибок в программе.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе определения основных функций, необходимых для поиска семантических ошибок в программе.
*/

#ifndef SEMANTICERRORS_H
#define SEMANTICERRORS_H

#include "semanticerror.h"

/*!
* Проверить наличие вложенных интерфейсов и классов в интерфейсе.
*\param[in] interfaces Список интерфейсов.
*\param[in] classes Список классов.
*\return Список семантических ошибок.
*/
QList<SemanticError> checkNestedClassesAndInterfacesInEachInterface(const QList<Interface> &interfaces, const QList<Class> &classes);

/*!
* Проверить наличие дубликатов.
*\param[in] strList Список строк.
*\return признак наличия дубликата.
*/
bool checkDuplicates(const QStringList &strList);

/*!
* Вывести на экран список семантических ошибок.
*\param[in] semanticErrors Список семантических ошибок.
*/
void printSemanticErrors(const QList<SemanticError> semanticErrors);

/*!
* Проверить в перечислениях наличие таких семантических ошибок, как дублирующие модификаторы и поля, одинаковые названия перечислений, а также совпадение имен перечислений с переданным множеством.
*\param[in] enums Список перечислений.
*\param[in|out] ids Множество идентификаторов.
*\return Список семантических ошибок.
*/
QList<SemanticError> checkEnums(const QList<Enum> &enums, QSet<QString> &ids);

/*!
* Проверить в классах наличие таких семантических ошибок, как дублирующие модификаторы, базовые классы, реализуемые интерфейсы, наличие компонентов с одинаковым именем в одной области видимости.
*\param[in] classes Список перечислений.
*\param[in|out] ids Множество идентификаторов.
*\return Список семантических ошибок.
*/
QList<SemanticError> checkClasses(const QList<Class> &classes, QSet<QString> &ids);

/*!
* Проверить в интерфейсах наличие таких семантических ошибок, как дублирующие модификаторы, наличие компонентов с одинаковым именем в одной области видимости.
*\param[in] interfaces Список перечислений.
*\param[in|out] ids Множество идентификаторов.
*\return Список семантических ошибок.
*/
QList<SemanticError> checkInterfaces(const QList<Interface> &interfaces, QSet<QString> &ids);

/*!
* Проверить в полях наличие таких семантических ошибок, как дублирующие модификаторы, а также совпадение имен перечислений с переданным множеством.
*\param[in] fields Список перечислений.
*\param[in|out] ids Множество идентификаторов.
*\return Список семантических ошибок.
*/
QList<SemanticError> checkFields(const QList<Field> &fields, QSet<QString> &ids);

/*!
* Проверить в методах наличие таких семантических ошибок, как дублирующие модификаторы, а также совпадение имен перечислений с переданным множеством.
*\param[in] methods Список перечислений.
*\param[in|out] ids Множество идентификаторов.
*\return Список семантических ошибок.
*/
QList<SemanticError> checkMethods(const QList<Method> &methods, QSet<QString> &ids);

/*!
* Проверить программу на семантические ошибки перед построением дерева.
*\param[in] package Пакет.
*\param[in] imports Импорты.
*\param[in] enums Перечисления.
*\param[in] interfaces Список интерфейсов.
*\param[in] classes Список классов.
*\param[in] fields Поля.
*\param[in] methods Методы.
*\return Список семантических ошибок.
*/
QList<SemanticError> checkSemanticErrorsBeforeTreeWillBeBuilt(const Package &package, const QList<Import> &imports, const QList<Enum> &enums, const QList<Interface> &interfaces, const QList<Class> &classes, const QList<Field> &fields, const QList<Method> &methods);

/*!
* Проверить программу на семантические ошибки после построения дерева.
*\param[in] program Дерево программы.
*\return Список семантических ошибок.
*/
QList<SemanticError> checkSemanticErrorsAfterTreeWasBuilt(const Program &program);

#endif // SEMANTICERRORS_H