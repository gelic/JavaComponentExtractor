#ifndef SEMANTICERRORS_H
#define SEMANTICERRORS_H

#include "semanticerror.h"

/*!
* Проверить наличие вложенных интерфейсов и классов в интерфейсе
*\param[in] interfaces - список интерфейсов
*\param[in] classes - список классов
*\return список семантических ошибок
*/
QList<SemanticError> checkNestedClassesAndInterfacesInEachInterface(const QList<Interface> &interfaces, const QList<Class> &classes);

/*!
* Проверить наличие дубликатов
*\param[in] strList - список строк
*\return признак наличия дубликата
*/
bool checkDuplicates(const QStringList &strList);

/*!
* Вывести на экран список семантических ошибок
*\param[in] semanticErrors - список семантических ошибок
*/
void printSemanticErrors(const QList<SemanticError> semanticErrors);

/*!
* Проверить в перечислениях наличие таких семантических ошибок, как дублирующие модификаторы и поля, одинаковые названия перечислений, а также совпадение имен перечислений с переданным множеством
*\param[in] enums - список перечислений
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkEnums(const QList<Enum> &enums, QSet<QString> &ids);

/*!
* Проверить в классах наличие таких семантических ошибок, как дублирующие модификаторы, базовые классы, реализуемые интерфейсы, наличие компонентов с одинаковым именем в одной области видимости
*\param[in] classes - список перечислений
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkClasses(const QList<Class> &classes, QSet<QString> &ids);

/*!
* Проверить в интерфейсах наличие таких семантических ошибок, как дублирующие модификаторы, наличие компонентов с одинаковым именем в одной области видимости
*\param[in] interfaces - список перечислений
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkInterfaces(const QList<Interface> &interfaces, QSet<QString> &ids);

/*!
* Проверить в полях наличие таких семантических ошибок, как дублирующие модификаторы, а также совпадение имен перечислений с переданным множеством
*\param[in] fields - список перечислений
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkFields(const QList<Field> &fields, QSet<QString> &ids);

/*!
* Проверить в методах наличие таких семантических ошибок, как дублирующие модификаторы, а также совпадение имен перечислений с переданным множеством
*\param[in] methods - список перечислений
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkMethods(const QList<Method> &methods, QSet<QString> &ids);

/*!
* Проверить программу на семантические ошибки перед построением дерева
*\param[in] interfaces - список интерфейсов
*\param[in] classes - список классов
*/
QList<SemanticError> checkSemanticErrorsBeforeTreeWillBeBuilt(const Package &package, const QList<Import> &imports, const QList<Enum> &enums, const QList<Interface> &interfaces, const QList<Class> &classes, const QList<Field> &fields, const QList<Method> &methods);

/*!
* Проверить программу на семантические ошибки после построения дерева
*\param[in] program - дерево программы
*/
QList<SemanticError> checkSemanticErrorsAfterTreeWasBuilt(const Program &program);

#endif // SEMANTICERRORS_H