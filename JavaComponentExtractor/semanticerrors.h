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
*\param[in|out] ids - ��������� ���������������
*/
QList<SemanticError> checkEnums(const QList<Enum> &enums, QSet<QString> &ids);

/*!
* ��������� � ������� ������� ����� ������������� ������, ��� ����������� ������������, ������� ������, ����������� ����������, ������� ����������� � ���������� ������ � ����� ������� ���������
*\param[in] classes - ������ ������������
*\param[in|out] ids - ��������� ���������������
*/
QList<SemanticError> checkClasses(const QList<Class> &classes, QSet<QString> &ids);

/*!
* ��������� � ����������� ������� ����� ������������� ������, ��� ����������� ������������, ������� ����������� � ���������� ������ � ����� ������� ���������
*\param[in] interfaces - ������ ������������
*\param[in|out] ids - ��������� ���������������
*/
QList<SemanticError> checkInterfaces(const QList<Interface> &interfaces, QSet<QString> &ids);

/*!
* ��������� � ����� ������� ����� ������������� ������, ��� ����������� ������������
*\param[in] fields - ������ ������������
*\param[in|out] ids - ��������� ���������������
*/
QList<SemanticError> checkFields(const QList<Field> &fields, QSet<QString> &ids);

/*!
* ��������� � ������� ������� ����� ������������� ������, ��� ����������� ������������
*\param[in] methods - ������ ������������
*\param[in|out] ids - ��������� ���������������
*/
QList<SemanticError> checkMethods(const QList<Method> &methods, QSet<QString> &ids);

#endif // SEMANTICERRORS_H