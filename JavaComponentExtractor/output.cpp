#include "output.h"

void writePackageNameAndImports(const QString &filePath, const QString &packageName, const QList<Import> &imports) throw(const QString &)
{
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly))
    {
        throw "Невозможно создать файл для вывода названия пакета и списка импорта";
    }

    QXmlStreamWriter xmlWriter;
    xmlWriter.setDevice(&file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("program");

    if (!packageName.isEmpty())
    {
        xmlWriter.writeStartElement("package");
        xmlWriter.writeAttribute("name", packageName);
        xmlWriter.writeEndElement();
    }

    if (!imports.isEmpty())
    {
        xmlWriter.writeStartElement("imports");
        for (auto import : imports)
        {
            xmlWriter.writeStartElement("import");
            xmlWriter.writeAttribute("name", import.importedClass);
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
}

void writeEnums(const QString &filePath, const QList<Enum> &enums) throw (const QString &)
{
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly))
    {
        throw "Невозможно создать файл для вывода перечислений";
    }

    QTextStream out(&file);

    for (auto enumToOut : enums)
    {
        out << enumToOut.text << endl << endl;
    }
}

void writeMethods(const QString &filePath, const QList<Method> &methods) throw (const QString &)
{
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly))
    {
        throw "Невозможно создать файл для вывода методов";
    }

    QTextStream out(&file);

    for (auto method : methods)
    {
        out << method.text << endl << endl;
    }
}