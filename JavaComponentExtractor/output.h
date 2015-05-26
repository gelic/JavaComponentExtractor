#ifndef OUTPUT_H
#define OUTPUT_H

#include <QDir>
#include <QFile>
#include <QXmlStreamWriter>
#include <QTextStream>
#include "program.h"

/*!
* ������� ���������� � �������� ������ � ������ ������������� ������ � XML �������
*\param[in] filePath - ���� �� ������������ �����
*\param[in] packageName - �������� ������
*\param[in] imports - ������ ������������� �������
*/
void writePackageNameAndImports(const QString &filePath, const QString &packageName, const QList<Import> &imports) throw(const QString &);

/*!
* ������� ���������� � ������������� � ��������� �������
*\param[in] filePath - ���� �� �����
*\param[in] enums - ������ ��������, ����������� ���������-������������
*/
void writeEnums(const QString &filePath, const QList<Enum> &enums) throw(const QString &);

#endif // OUTPUT_H