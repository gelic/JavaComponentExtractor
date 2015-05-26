#ifndef SEMANTICERRORS_H
#define SEMANTICERRORS_H

#include "semanticerror.h"

/*!
* ��������� ������� ��������� ����������� � ������� � ����������
*\param[in] interfaces - ������ �����������
*\param[in] classes - ������ �������
*\return ������ ������������� ������
*/
QList<SemanticError> checkNestedClassesAndInterfacesInEachInterface(const QList<Interface> &interfaces, const QList<Class> &classes);

#endif // SEMANTICERRORS_H