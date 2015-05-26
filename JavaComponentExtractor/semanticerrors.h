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

#endif // SEMANTICERRORS_H