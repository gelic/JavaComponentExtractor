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
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkEnums(const QList<Enum> &enums, QSet<QString> &ids);

/*!
* ѕроверить в классах наличие таких семантических ошибок, как дублирующие модификаторы, базовые классы, реализуемые интерфейсы, наличие компонентов с одинаковым именем в одной области видимости
*\param[in] classes - список перечислений
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkClasses(const QList<Class> &classes, QSet<QString> &ids);

/*!
* ѕроверить в интерфейсах наличие таких семантических ошибок, как дублирующие модификаторы, наличие компонентов с одинаковым именем в одной области видимости
*\param[in] interfaces - список перечислений
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkInterfaces(const QList<Interface> &interfaces, QSet<QString> &ids);

/*!
* ѕроверить в пол€х наличие таких семантических ошибок, как дублирующие модификаторы
*\param[in] fields - список перечислений
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkFields(const QList<Field> &fields, QSet<QString> &ids);

/*!
* ѕроверить в методах наличие таких семантических ошибок, как дублирующие модификаторы
*\param[in] methods - список перечислений
*\param[in|out] ids - множество идентификаторов
*/
QList<SemanticError> checkMethods(const QList<Method> &methods, QSet<QString> &ids);

#endif // SEMANTICERRORS_H