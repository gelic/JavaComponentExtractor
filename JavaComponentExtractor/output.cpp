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

void writeFields(const QString &filePath, const QList<Field> &fields) throw(const QString &)
{
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly))
    {
        throw "Невозможно создать файл для вывода полей";
    }

    QTextStream out(&file);

    for (auto field : fields)
    {
        out << field.text << endl;
    }
}

void writeInterface(const QString &filePath, const Interface &interfaceToWrite) throw(const QString &)
{
    QFile file(filePath + interfaceToWrite.name + ".xml");

    if (!file.open(QIODevice::WriteOnly))
    {
        throw "Невозможно создать файл для вывода интерфейса";
    }

    QXmlStreamWriter xmlWriter;
    xmlWriter.setDevice(&file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("interface");
    xmlWriter.writeAttribute("name", interfaceToWrite.name);

    if (!interfaceToWrite.modificators.isEmpty())
    {
        xmlWriter.writeAttribute("modificators", interfaceToWrite.modificators.join(' '));
    }

    if (!interfaceToWrite.baseInterfaces.isEmpty())
    {
        xmlWriter.writeAttribute("baseInterfaces", interfaceToWrite.baseInterfaces.join(' '));
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    if (!interfaceToWrite.fields.isEmpty())
    {
        writeFields(filePath + "fields.txt", interfaceToWrite.fields);
    }

    if (!interfaceToWrite.methods.isEmpty())
    {
        writeMethods(filePath + "methods.txt", interfaceToWrite.methods);
    }
}

void writeInterfaces(QDir &outputDir, const QList<Interface> &interfaces, const QString &folderName) throw(const QString &)
{
    if (!outputDir.mkdir("Interfaces"))
    {
        throw "Невозможно создать папку Classes";
    }

    outputDir.cd("Interfaces");

    for (auto interface : interfaces)
    {
        if (!outputDir.mkdir(interface.name))
        {
            throw "Невозможно создать папку для интерфейса: " + interface.name;
        }

        writeInterface(folderName + "/Interfaces/" + interface.name + "/", interface);
    }

    outputDir.cd("..");
}

void writeClass(const QString &filePath, const Class &classToWrite) throw(const QString &)
{
    QFile file(filePath + classToWrite.name + ".xml");

    if (!file.open(QIODevice::WriteOnly))
    {
        throw "Невозможно создать файл для вывода класса";
    }

    QXmlStreamWriter xmlWriter;
    xmlWriter.setDevice(&file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("class");
    xmlWriter.writeAttribute("name", classToWrite.name);

    if (!classToWrite.modificators.isEmpty())
    {
        xmlWriter.writeAttribute("modificators", classToWrite.modificators.join(' '));
    }

    if (!classToWrite.baseClasses.isEmpty())
    {
        xmlWriter.writeAttribute("baseClasses", classToWrite.baseClasses.join(' '));
    }

    if (!classToWrite.implementedInterfaces.isEmpty())
    {
        xmlWriter.writeAttribute("implementedInterfaces", classToWrite.implementedInterfaces.join(' '));
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    if (!classToWrite.enums.isEmpty())
    {
        writeEnums(filePath + "enums.txt", classToWrite.enums);
    }

    if (!classToWrite.fields.isEmpty())
    {
        writeFields(filePath + "fields.txt", classToWrite.fields);
    }

    if (!classToWrite.methods.isEmpty())
    {
        writeMethods(filePath + "methods.txt", classToWrite.methods);
    }

    if (!classToWrite.nestedInterfaces.isEmpty())
    {
        writeInterfaces(QDir(filePath), classToWrite.nestedInterfaces, filePath);
    }

    if (!classToWrite.nestedClasses.isEmpty())
    {
        writeClasses(QDir(filePath), classToWrite.nestedClasses, filePath);
    }
}

void writeClasses(QDir outputDir, const QList<Class> &classes, const QString &folderName) throw(const QString &)
{
    if (!outputDir.mkdir("Classes"))
    {
        throw "Невозможно создать папку Classes";
    }

    outputDir.cd("Classes");

    for (auto classToWrite : classes)
    {
        if (!outputDir.mkdir(classToWrite.name))
        {
            throw "Невозможно создать папку для класса: " + classToWrite.name;
        }

        writeClass("./" + folderName + "/Classes/" + classToWrite.name + "/", classToWrite);
    }

    outputDir.cd("..");
}