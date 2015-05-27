#include "output.h"

void writePackageNameAndImports(const QString &filePath, const QString &packageName, const QList<Import> &imports) throw(const QString &)
{
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly))
    {
        throw QString("Cannot create file for package name and import`s list output");
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
        throw QString("Cannot create file for enums output");
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
        throw QString("Cannot create file for methods output");
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
        throw QString("Cannot create file for fields output");
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
        throw QString("Cannot create file for interface output");
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
        throw QString("Cannot create folder Interfaces");
    }

    outputDir.cd("Interfaces");

    for (auto interface : interfaces)
    {
        if (!outputDir.mkdir(interface.name))
        {
            throw QString("Cannot create folder for interface with name: " + interface.name);
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
        throw QString("Cannot create file for class output");
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
        throw QString("Cannot create folder Classes");
    }

    outputDir.cd("Classes");

    for (auto classToWrite : classes)
    {
        if (!outputDir.mkdir(classToWrite.name))
        {
            throw QString("Cannot create folder for class with name: " + classToWrite.name);
        }

        writeClass("./" + folderName + "/Classes/" + classToWrite.name + "/", classToWrite);
    }

    outputDir.cd("..");
}

void writeTreeToFiles(const QString &folderName, const Program &program) throw(const QString &)
{
    QDir outputDir;

    if (folderName.isEmpty())
    {
        throw QString("Folder name cannot be empty");
    }

    if (!outputDir.exists(folderName) && !outputDir.mkdir(folderName))
    {
        throw QString("Cannot create folder for output files");
    }

    if (!program.package.packageName.isEmpty() || !program.imports.isEmpty())
    {
        writePackageNameAndImports("./" + folderName + "/packageNameAndImports.xml", program.package.packageName, program.imports);
    }

    if (!program.enums.isEmpty())
    {
        writeEnums("./" + folderName + "/enums.txt", program.enums);
    }

    outputDir.cd(folderName);

    if (!program.interfaces.isEmpty())
    {
        writeInterfaces(outputDir, program.interfaces, folderName);
    }

    if (!program.classes.isEmpty())
    {
        writeClasses(outputDir, program.classes, folderName);
    }
}