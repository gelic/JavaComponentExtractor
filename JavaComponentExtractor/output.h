/*!
*\file
*\brief Файл с объявлениями функций для вывода дерева программы.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе определения основных функций, необходимых для вывода дерева программы в иерархию папок и файлов.
*/

#ifndef OUTPUT_H
#define OUTPUT_H

#include <QDir>
#include <QFile>
#include <QXmlStreamWriter>
#include <QTextStream>
#include "program.h"

/*!
* Вывести информацию о названии пакета и списке импортируемых файлов в XML формате.
*\param[in] filePath Путь до создаваемого файла.
*\param[in] packageName Название пакета.
*\param[in] imports Список импортируемых классов.
*\throw QString Не удалось создать файл для вывода.
*/
void writePackageNameAndImports(const QString &filePath, const QString &packageName, const QList<Import> &imports) throw(const QString &);

/*!
* Вывести информацию о перечислениях в текстовом формате.
*\param[in] filePath Путь до файла.
*\param[in] enums Список структур, описывающих компонент-перечисление.
*\throw QString Не удалось создать файл для вывода.
*/
void writeEnums(const QString &filePath, const QList<Enum> &enums) throw(const QString &);

/*!
* Вывести информацию о методах в текстовом формате.
*\param[in] filePath Путь до файла.
*\param[in] methods Список структур, описывающих компонент-метод.
*\throw QString Не удалось создать файл для вывода.
*/
void writeMethods(const QString &filePath, const QList<Method> &methods) throw(const QString &);

/*!
* Вывести информацию о полях в текстовом формате.
*\param[in] filePath Путь до файла.
*\param[in] fields Список структур, описывающих компонент-поле.
*\throw QString Не удалось создать файл для вывода.
*/
void writeFields(const QString &filePath, const QList<Field> &fields) throw(const QString &);

/*!
* Вывести информацию об интерфейсе в XML формате и всех его вложенных компонентах.
*\param[in] filePath Путь до файла.
*\param[in] interfaceToWrite Структура, описывающая компонент-интерфейс.
*\throw QString Не удалось создать файл для вывода.
*/
void writeInterface(const QString &filePath, const Interface &interfaceToWrite) throw(const QString &);

/*!
* Вывести все интерфейсы
*\param[in|out] outputDir Папка, в которой создастся папка "Interfaces".
*\param[in] interfaces Список интерфейсов.
*\param[in] folderName Название выходной папки.
*\throw QString Не удалось создать папку для вывода.
*/
void writeInterfaces(QDir &outputDir, const QList<Interface> &interfaces, const QString &folderName) throw(const QString &);

/*!
* Вывести информацию о классе в XML формате и всех его вложенных компонентах.
*\param[in] filePath Путь до файла.
*\param[in] classToWrite Структура, описывающая компонент-класса.
*\throw QString Не удалось создать файл для вывода.
*/
void writeClass(const QString &filePath, const Class &classToWrite) throw(const QString &);

/*!
* Вывести все классы.
*\param[in|out] outputDir Папка, в которой создастся папка "Classes".
*\param[in] classes Список классов.
*\param[in] folderName Название выходной папки.
*\throw QString Не удалось создать папку для вывода.
*/
void writeClasses(QDir outputDir, const QList<Class> &classes, const QString &folderName) throw(const QString &);

/*!
* Вывести компоненты программы в иерархию папок и файлов.
*\param[in] folderName Название выходной папки.
*\param[in] program Структура, описывающая компоненты программы.
*\throw QString Не удалось создать папку для вывода.
*/
void writeTreeToFiles(const QString &folderName, const Program &program) throw(const QString &);

#endif // OUTPUT_H