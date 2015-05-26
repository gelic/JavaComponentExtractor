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

#endif // SEMANTICERRORS_H