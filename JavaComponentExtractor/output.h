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

#endif // OUTPUT_H