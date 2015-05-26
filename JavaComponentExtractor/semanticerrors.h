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

/*!
* ��������� ������� ����������
*\param[in] strList - ������ �����
*\return ������� ������� ���������
*/
bool checkDuplicates(const QStringList &strList);

#endif // SEMANTICERRORS_H