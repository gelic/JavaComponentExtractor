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

/*!
* ������� �� ����� ������ ������������� ������
*\param[in] semanticErrors - ������ ������������� ������
*/
void printSemanticErrors(const QList<SemanticError> semanticErrors);

/*!
* ��������� � ������������� ������� ����� ������������� ������, ��� ����������� ������������ � ����, � ����� ���������� �������� ������������
*\param[in] enums - ������ ������������
*/
QList<SemanticError> checkEnums(const QList<Enum> &enums);

/*!
* ��������� � ������� ������� ����� ������������� ������, ��� ����������� ������������, ������� ������, ����������� ����������, ������� ����������� � ���������� ������ � ����� ������� ���������
*\param[in] classes - ������ ������������
*/
QList<SemanticError> checkClasses(const QList<Class> &classes);

/*!
* ��������� � ����������� ������� ����� ������������� ������, ��� ����������� ������������, ������� ����������� � ���������� ������ � ����� ������� ���������
*\param[in] interfaces - ������ ������������
*/
QList<SemanticError> checkInterfaces(const QList<Interface> &interfaces);

/*!
* ��������� � ����� ������� ����� ������������� ������, ��� ����������� ������������
*\param[in] fields - ������ ������������
*/
QList<SemanticError> checkFields(const QList<Field> &fields);

/*!
* ��������� � ������� ������� ����� ������������� ������, ��� ����������� ������������
*\param[in] methods - ������ ������������
*/
QList<SemanticError> checkMethods(const QList<Method> &methods);

#endif // SEMANTICERRORS_H