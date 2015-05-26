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

#endif // SEMANTICERRORS_H