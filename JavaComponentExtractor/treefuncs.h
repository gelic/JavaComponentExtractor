#ifndef TREENODES_H
#define TREENODES_H

#include <QString>
#include <QList.h>
#include "stringfuncs.h"
#include "program.h"

/*!
* ����� ��������� ������������ ����� ������� � ����������� �� � ���
*\param[in,out] classes - ������ �������
*\param[in,out] enums - ������ ������������
*/
void findParentsToEnums(QList<Class> &classes, QList<Enum> &enums);

/*!
* ����� ��������� ����������� ����� ������� � ����������� �� � ���
*\param[in,out] classes - ������ �������
*\param[in,out] interfaces - ������ �����������
*/
void findParentsToInterfaces(QList<Class> &classes, QList<Interface> &interfaces);

/*!
* ����� ��������� ������� ����� ������� � ����������� �� � ���
*\param[in,out] classes - ������ �������
*/
void findParentsToClasses(QList<Class> &classes);

/*!
* ����� ��������� ����� ����� ������� � ����������� � ����������� �� � ���
*\param[in,out] classes - ������ �������
*\param[in,out] interfaces - ������ �����������
*\param[in,out] fields - ������ �����
*/
void findParentsToFields(QList<Class> &classes, QList<Interface> &interfaces, QList<Field> &fields);

/*!
* ����� ��������� ������� ����� ������� � ����������� � ����������� �� � ���
*\param[in,out] classes - ������ �������
*\param[in,out] interfaces - ������ �����������
*\param[in,out] methods - ������ �������
*/
void findParentsToMethods(QList<Class> &classes, QList<Interface> &interfaces, QList<Method> &methods);

/*!
* �������� � ���������� �� �����
*\param[in] buffer - ����� ���������
*\param[in,out] package - �����
*\param[in,out] imports - �������
*\param[in,out] enums - ������������
*\param[in,out] interfaces - ����������
*\param[in,out] classes - ������
*\param[in,out] fields - ����
*\param[in,out] methods - ������
*/
void getComponentsText(const QString &buffer, Package &package, QList<Import> &imports, QList<Enum> &enums, QList<Interface> &interfaces, QList<Class> &classes, QList<Field> &fields, QList<Method> &methods);

/*!
* �������� � ��������� ��������� ������������, ����������, ������, ���� � ������ � ������ �� ��������
*\param[in,out] program - �����, ����������� ���������� ���������
*\param[in,out] package - �����
*\param[in,out] imports - �������
*\param[in,out] enums - ������������
*\param[in,out] interfaces - ����������
*\param[in,out] classes - ������
*\param[in,out] fields - ����
*\param[in,out] methods - ������
*/
void addComponentsToTree(Program &program, const Package &package, const QList<Import> &imports, QList<Enum> &enums, QList<Interface> &interfaces, QList<Class> &classes, QList<Field> &fields, QList<Method> &methods);

#endif // TREENODES_H