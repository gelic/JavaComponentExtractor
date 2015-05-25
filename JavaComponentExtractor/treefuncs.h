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

#endif // TREENODES_H