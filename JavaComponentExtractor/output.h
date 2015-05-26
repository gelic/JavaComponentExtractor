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

/*!
* ������� ���������� �� ���������� � XML ������� � ���� ��� ��������� �����������
*\param[in] filePath - ���� �� �����
*\param[in] interfaceToWrite - ���������, ����������� ���������-���������
*/
void writeInterface(const QString &filePath, const Interface &interfaceToWrite) throw(const QString &);

/*!
* ������� ��� ����������
*\param[in|out] outputDir - �����, � ������� ��������� ����� "Interfaces"
*\param[in] interfaces - ������ �����������
*\param[in] folderName - �������� �������� �����
*/
void writeInterfaces(QDir &outputDir, const QList<Interface> &interfaces, const QString &folderName) throw(const QString &);

/*!
* ������� ���������� � ������ � XML ������� � ���� ��� ��������� �����������
*\param[in] filePath - ���� �� �����
*\param[in] classToWrite - ���������, ����������� ���������-������
*/
void writeClass(const QString &filePath, const Class &classToWrite) throw(const QString &);

/*!
* ������� ��� ������
*\param[in|out] outputDir - �����, � ������� ��������� ����� "Classes"
*\param[in] classes - ������ �������
*\param[in] folderName - �������� �������� �����
*/
void writeClasses(QDir outputDir, const QList<Class> &classes, const QString &folderName) throw(const QString &);

/*!
* ������� ���������� ��������� � �������� ����� � ������
*\param[in] folderName - �������� �������� �����
*\param[in] program - ���������, ����������� ���������� ���������
*/
void writeTreeToFiles(const QString &folderName, const Program &program) throw(const QString &);

#endif // OUTPUT_H