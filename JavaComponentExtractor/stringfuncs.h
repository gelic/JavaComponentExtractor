#ifndef STRINGFUNCS_H
#define STRINGFUNCS_H

#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include "textlocation.h"

/*!
* ������� ���������� ������ ����� ���������� ���������� � ��������� �������� ����� � �������
*\param[in] buffer - �����
*\param[in] location - ���������, ���������� ������ ��������� � �������� ����� � �������
*\return ��������� ����������
*/
QString contentBetweenPositions( const QString &buffer, const TextLocation &location ) throw( const char * );

#endif // STRINGFUNCS_H