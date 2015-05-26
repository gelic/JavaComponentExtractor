#ifndef OUTPUT_H
#define OUTPUT_H

#include <QDir>
#include <QFile>
#include <QXmlStreamWriter>
#include <QTextStream>
#include "program.h"

/*!
* Вывести информацию о названии пакета и списке импортируемых файлов в XML формате
*\param[in] filePath - путь до создаваемого файла
*\param[in] packageName - название пакета
*\param[in] imports - список импортируемых классов
*/
void writePackageNameAndImports(const QString &filePath, const QString &packageName, const QList<Import> &imports) throw(const QString &);

/*!
* Вывести информацию о перечислениях в текстовом формате
*\param[in] filePath - путь до файла
*\param[in] enums - список структур, описывающих компонент-перечисление
*/
void writeEnums(const QString &filePath, const QList<Enum> &enums) throw(const QString &);

/*!
* Вывести информацию о методах в текстовом формате
*\param[in] filePath - путь до файла
*\param[in] methods - список структур, описывающих компонент-метод
*/
void writeMethods(const QString &filePath, const QList<Method> &methods) throw(const QString &);

/*!
* Вывести информацию о полях в текстовом формате
*\param[in] filePath - путь до файла
*\param[in] fields - список структур, описывающих компонент-поле
*/
void writeFields(const QString &filePath, const QList<Field> &fields) throw(const QString &);

#endif // OUTPUT_H