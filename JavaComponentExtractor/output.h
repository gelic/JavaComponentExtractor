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

/*!
* Вывести информацию об интерфейсе в XML формате и всех его вложенных компонентах
*\param[in] filePath - путь до файла
*\param[in] interfaceToWrite - структура, описывающая компонент-интерфейс
*/
void writeInterface(const QString &filePath, const Interface &interfaceToWrite) throw(const QString &);

/*!
* Вывести все интерфейсы
*\param[in|out] outputDir - папка, в которой создастся папка "Interfaces"
*\param[in] interfaces - список интерфейсов
*\param[in] folderName - название выходной папки
*/
void writeInterfaces(QDir &outputDir, const QList<Interface> &interfaces, const QString &folderName) throw(const QString &);

/*!
* Вывести информацию о классе в XML формате и всех его вложенных компонентах
*\param[in] filePath - путь до файла
*\param[in] classToWrite - структура, описывающая компонент-класса
*/
void writeClass(const QString &filePath, const Class &classToWrite) throw(const QString &);

/*!
* Вывести все классы
*\param[in|out] outputDir - папка, в которой создастся папка "Classes"
*\param[in] classes - список классов
*\param[in] folderName - название выходной папки
*/
void writeClasses(QDir outputDir, const QList<Class> &classes, const QString &folderName) throw(const QString &);

/*!
* Вывести компоненты программы в иерархию папок и файлов
*\param[in] folderName - название выходной папки
*\param[in] program - структура, описывающая компоненты программы
*/
void writeTreeToFiles(const QString &folderName, const Program &program) throw(const QString &);

#endif // OUTPUT_H