#ifndef SEMANTICERRORS_H
#define SEMANTICERRORS_H

#include "semanticerror.h"

/*!
* ѕроверить наличие вложенных интерфейсов и классов в интерфейсе
*\param[in] interfaces - список интерфейсов
*\param[in] classes - список классов
*\return список семантических ошибок
*/
QList<SemanticError> checkNestedClassesAndInterfacesInEachInterface(const QList<Interface> &interfaces, const QList<Class> &classes);

/*!
* ѕроверить наличие дубликатов
*\param[in] strList - список строк
*\return признак наличи€ дубликата
*/
bool checkDuplicates(const QStringList &strList);

/*!
* ¬ывести на экран список семантических ошибок
*\param[in] semanticErrors - список семантических ошибок
*/
void printSemanticErrors(const QList<SemanticError> semanticErrors);

/*!
* ѕроверить в перечислени€х наличие таких семантических ошибок, как дублирующие модификаторы и пол€, а также одинаковые названи€ перечислений
*\param[in] enums - список перечислений
*/
QList<SemanticError> checkEnums(const QList<Enum> &enums);

/*!
* ѕроверить в классах наличие таких семантических ошибок, как дублирующие модификаторы, базовые классы, реализуемые интерфейсы, наличие компонентов с одинаковым именем в одной области видимости
*\param[in] classes - список перечислений
*/
QList<SemanticError> checkClasses(const QList<Class> &classes);

/*!
* ѕроверить в интерфейсах наличие таких семантических ошибок, как дублирующие модификаторы, наличие компонентов с одинаковым именем в одной области видимости
*\param[in] interfaces - список перечислений
*/
QList<SemanticError> checkInterfaces(const QList<Interface> &interfaces);

/*!
* ѕроверить в пол€х наличие таких семантических ошибок, как дублирующие модификаторы
*\param[in] fields - список перечислений
*/
QList<SemanticError> checkFields(const QList<Field> &fields);

/*!
* ѕроверить в методах наличие таких семантических ошибок, как дублирующие модификаторы
*\param[in] methods - список перечислений
*/
QList<SemanticError> checkMethods(const QList<Method> &methods);

#endif // SEMANTICERRORS_H