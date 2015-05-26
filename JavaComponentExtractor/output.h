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

/*!
* ������� ���������� � ������� � ��������� �������
*\param[in] filePath - ���� �� �����
*\param[in] methods - ������ ��������, ����������� ���������-�����
*/
void writeMethods(const QString &filePath, const QList<Method> &methods) throw(const QString &);

/*!
* ������� ���������� � ����� � ��������� �������
*\param[in] filePath - ���� �� �����
*\param[in] fields - ������ ��������, ����������� ���������-����
*/
void writeFields(const QString &filePath, const QList<Field> &fields) throw(const QString &);

#endif // OUTPUT_H