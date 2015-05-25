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
void findParentsToEnums( QList<Class> &classes, QList<Enum> &enums );

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

#endif // TREENODES_H