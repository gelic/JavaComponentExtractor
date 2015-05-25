#ifndef TREENODES_H
#define TREENODES_H

#include <QString>
#include <QList.h>
#include "stringfuncs.h"
#include "program.h"

/*!
* ���������������� ������������ � ������ �� ����������� � ������
*\param[in,out] classes - ������ �������
*\param[in,out] enums - ������ ������������
*/
void findParentsToEnums( QList<Class> &classes, QList<Enum> &enums );

#endif // TREENODES_H