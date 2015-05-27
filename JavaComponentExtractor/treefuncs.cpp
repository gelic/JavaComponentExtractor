#include "treefuncs.h"

void findParentsToEnums(QList<Class> &classes, QList<Enum> &enums)
{
    int classesSize = classes.size();
    int enumsSize = enums.size();

    // classes and enums aren`t empty
    if (classesSize > 0 && enumsSize > 0)
    {
        Class **parents = new Class * [enumsSize]{};

        // find enums` parents
        for (int i = 0; i < enumsSize; ++i)
        {
            int minDiffFirstLines = 0;
            int minDiffLastLines = 0;
            int minDiffFirstColumns = 0;
            int minDiffLastColumns = 0;
            bool isMinimumSet = false;

            for (int j = 0; j < classesSize; ++j)
            {
                // enum is nested into class
                if (enums[i].isNested(classes[j]))
                {
                    // count differences between enum and class locations
                    int diffFirstLines = abs(enums[i].location.firstLine - classes[j].location.firstLine);
                    int diffLastLines = abs(enums[i].location.lastLine - classes[j].location.lastLine);
                    int diffFirstColumns = abs(enums[i].location.firstColumn - classes[j].location.firstColumn);
                    int diffLastColumns = abs(enums[i].location.lastColumn - classes[j].location.lastColumn);

                    // difference less than minimum
                    if (!isMinimumSet ||
                        diffFirstLines < minDiffFirstLines && diffLastLines < minDiffLastLines ||
                        diffFirstLines <= minDiffFirstLines && diffLastLines <= minDiffLastLines && diffFirstColumns < minDiffFirstColumns && diffLastColumns < minDiffLastColumns)
                    {
                        isMinimumSet = true;
                        parents[i] = &classes[j];

                        // set minimum to current differences
                        minDiffFirstLines = diffFirstLines;
                        minDiffLastLines = diffLastLines;
                        minDiffFirstColumns = diffFirstColumns;
                        minDiffLastColumns = diffLastColumns;
                    }
                }
            }
        }

        // insert nested enums to their parents
        for (int i = 0; i < enumsSize; ++i)
        {
            if (parents[i] != nullptr)
            {
                for (int j = 0; j < classesSize; ++j)
                {
                    if (&classes[j] == parents[i])
                    {
                        classes[j].enums << enums[i];
                    }
                }
            }
        }

        // delete enums, which have parents
        for (int i = 0; i < enumsSize; ++i)
        {
            if (parents[i] != nullptr)
            {
                enums.removeAt(i);
            }
        }

        delete[] parents;
    }
}

void findParentsToInterfaces(QList<Class> &classes, QList<Interface> &interfaces)
{
    int classesSize = classes.size();
    int interfacesSize = interfaces.size();

    // classes and interfaces aren`t empty
    if (classesSize > 0 && interfacesSize > 0)
    {
        Class **parents = new Class *[interfacesSize]{};

        // find interfaces` parents
        for (int i = 0; i < interfacesSize; ++i)
        {
            int minDiffFirstLines = 0;
            int minDiffLastLines = 0;
            int minDiffFirstColumns = 0;
            int minDiffLastColumns = 0;
            bool isMinimumSet = false;

            for (int j = 0; j < classesSize; ++j)
            {
                // interface is nested into class
                if (interfaces[i].isNested(classes[j]))
                {
                    // count differences between interface and class locations
                    int diffFirstLines = abs(interfaces[i].location.firstLine - classes[j].location.firstLine);
                    int diffLastLines = abs(interfaces[i].location.lastLine - classes[j].location.lastLine);
                    int diffFirstColumns = abs(interfaces[i].location.firstColumn - classes[j].location.firstColumn);
                    int diffLastColumns = abs(interfaces[i].location.lastColumn - classes[j].location.lastColumn);

                    // difference less than minimum
                    if (!isMinimumSet ||
                        diffFirstLines < minDiffFirstLines && diffLastLines < minDiffLastLines ||
                        diffFirstLines <= minDiffFirstLines && diffLastLines <= minDiffLastLines && diffFirstColumns < minDiffFirstColumns && diffLastColumns < minDiffLastColumns)
                    {
                        isMinimumSet = true;
                        parents[i] = &classes[j];

                        // set minimum to current differences
                        minDiffFirstLines = diffFirstLines;
                        minDiffLastLines = diffLastLines;
                        minDiffFirstColumns = diffFirstColumns;
                        minDiffLastColumns = diffLastColumns;
                    }
                }
            }
        }

        // insert nested interfaces to their parents
        for (int i = 0; i < interfacesSize; ++i)
        {
            if (parents[i] != nullptr)
            {
                for (int j = 0; j < classesSize; ++j)
                {
                    if (&classes[j] == parents[i])
                    {
                        classes[j].nestedInterfaces << interfaces[i];
                    }
                }
            }
        }

        // delete interfaces, which have parents
        for (int i = 0; i < interfacesSize; ++i)
        {
            if (parents[i] != nullptr)
            {
                interfaces.removeAt(i);
            }
        }

        delete[] parents;
    }
}

void findParentsToClasses(QList<Class> &classes)
{
    int classesSize = classes.size();

    // classes` size is more than one
    if (classesSize > 1)
    {
        Class **parents = new Class *[classesSize]{};

        // find classes` parents
        for (int i = 0; i < classesSize; ++i)
        {
            int minDiffFirstLines = 0;
            int minDiffLastLines = 0;
            int minDiffFirstColumns = 0;
            int minDiffLastColumns = 0;
            bool isMinimumSet = false;

            if (i != 0)
            {
                minDiffFirstLines = abs(classes[i].location.firstLine - classes[0].location.firstLine);
                minDiffLastLines = abs(classes[i].location.lastLine - classes[0].location.lastLine);
                minDiffFirstColumns = abs(classes[i].location.firstColumn - classes[0].location.firstColumn);
                minDiffLastColumns = abs(classes[i].location.lastColumn - classes[0].location.lastColumn);
            }
            else
            {
                minDiffFirstLines = abs(classes[i].location.firstLine - classes[1].location.firstLine);
                minDiffLastLines = abs(classes[i].location.lastLine - classes[1].location.lastLine);
                minDiffFirstColumns = abs(classes[i].location.firstColumn - classes[1].location.firstColumn);
                minDiffLastColumns = abs(classes[i].location.lastColumn - classes[1].location.lastColumn);
            }

            for (int j = 0; j < classesSize; ++j)
            {
                // class is nested into class
                if (classes[i].isNested(classes[j]))
                {
                    int diffFirstLines = abs(classes[i].location.firstLine - classes[j].location.firstLine);
                    int diffLastLines = abs(classes[i].location.lastLine - classes[j].location.lastLine);
                    int diffFirstColumns = abs(classes[i].location.firstColumn - classes[j].location.firstColumn);
                    int diffLastColumns = abs(classes[i].location.lastColumn - classes[j].location.lastColumn);

                    // difference less than minimum
                    if (!isMinimumSet ||
                        diffFirstLines < minDiffFirstLines && diffLastLines < minDiffLastLines ||
                        diffFirstLines <= minDiffFirstLines && diffLastLines <= minDiffLastLines && diffFirstColumns < minDiffFirstColumns && diffLastColumns < minDiffLastColumns)
                    {
                        isMinimumSet = true;
                        parents[i] = &classes[j];

                        // set minimum to current differences
                        minDiffFirstLines = diffFirstLines;
                        minDiffLastLines = diffLastLines;
                        minDiffFirstColumns = diffFirstColumns;
                        minDiffLastColumns = diffLastColumns;
                    }
                }
            }
        }

        // insert nested classes to their parents
        for (int i = 0; i < classesSize; ++i)
        {
            if (parents[i] != nullptr)
            {
                for (int j = 0; j < classesSize; ++j)
                {
                    if (&classes[j] == parents[i])
                    {
                        classes[j].nestedClasses << classes[i];
                    }
                }
            }
        }

        // delete classes, which have parents
        for (int i = 0; i < classesSize; ++i)
        {
            if (parents[i] != nullptr)
            {
                classes.removeAt(i);
            }
        }

        delete[] parents;
    }
}

void findParentsToFields(QList<Class> &classes, QList<Interface> &interfaces, QList<Field> &fields)
{
    int classesSize = classes.size();
    int interfacesSize = interfaces.size();
    int fieldsSize = fields.size();

    // fields and classes or interfaces aren`t empty
    if (fieldsSize > 0 && (classesSize > 0 || interfacesSize > 0))
    {
        Component **parents = new Component *[fieldsSize]{};
        int minDiffFirstLines = 0;
        int minDiffLastLines = 0;
        int minDiffFirstColumns = 0;
        int minDiffLastColumns = 0;
        bool isMinimumSet = false;

        // find fields` parents among classes and interfaces
        for (int i = 0; i < fieldsSize; ++i)
        {
            // find field`s parents among classes
            for (int j = 0; j < classesSize; ++j)
            {
                // field is nested into class
                if (fields[i].isNested(classes[j]))
                {
                    int diffFirstLines = abs(fields[i].location.firstLine - classes[j].location.firstLine);
                    int diffLastLines = abs(fields[i].location.lastLine - classes[j].location.lastLine);
                    int diffFirstColumns = abs(fields[i].location.firstColumn - classes[j].location.firstColumn);
                    int diffLastColumns = abs(fields[i].location.lastColumn - classes[j].location.lastColumn);

                    // difference less than minimum
                    if (!isMinimumSet ||
                        diffFirstLines < minDiffFirstLines && diffLastLines < minDiffLastLines ||
                        diffFirstLines <= minDiffFirstLines && diffLastLines <= minDiffLastLines && diffFirstColumns < minDiffFirstColumns && diffLastColumns < minDiffLastColumns)
                    {
                        isMinimumSet = true;
                        parents[i] = &classes[j];

                        // set minimum to current differences
                        minDiffFirstLines = diffFirstLines;
                        minDiffLastLines = diffLastLines;
                        minDiffFirstColumns = diffFirstColumns;
                        minDiffLastColumns = diffLastColumns;
                    }
                }
            }

            // find field`s parent among interfaces
            for (int j = 0; j < interfacesSize; ++j)
            {
                // field is nested into interface
                if (fields[i].isNested(interfaces[j]))
                {
                    int diffFirstLines = abs(fields[i].location.firstLine - interfaces[j].location.firstLine);
                    int diffLastLines = abs(fields[i].location.lastLine - interfaces[j].location.lastLine);
                    int diffFirstColumns = abs(fields[i].location.firstColumn - interfaces[j].location.firstColumn);
                    int diffLastColumns = abs(fields[i].location.lastColumn - interfaces[j].location.lastColumn);

                    // difference less than minimum
                    if (!isMinimumSet ||
                        diffFirstLines < minDiffFirstLines && diffLastLines < minDiffLastLines ||
                        diffFirstLines <= minDiffFirstLines && diffLastLines <= minDiffLastLines && diffFirstColumns < minDiffFirstColumns && diffLastColumns < minDiffLastColumns)
                    {
                        isMinimumSet = true;
                        parents[i] = &interfaces[j];

                        // set minimum to current differences
                        minDiffFirstLines = diffFirstLines;
                        minDiffLastLines = diffLastLines;
                        minDiffFirstColumns = diffFirstColumns;
                        minDiffLastColumns = diffLastColumns;
                    }
                }
            }

            isMinimumSet = false;
        }

        // insert fields into their parents
        for (int i = 0; i < fieldsSize; ++i)
        {
            if (parents[i] != nullptr)
            {
                for (int j = 0; j < classesSize; ++j)
                {
                    if (&classes[j] == parents[i])
                    {
                        classes[j].fields << fields[i];
                    }
                    else if (&interfaces[j] == parents[i])
                    {
                        interfaces[j].fields << fields[i];
                    }
                }
            }
        }

        // delete fields, which have parents
        for (int i = fieldsSize - 1; i >= 0; --i)
        {
            if (parents[i] != nullptr)
            {
                fields.removeAt(i);
            }
        }

        delete[] parents;
    }
}

void findParentsToMethods(QList<Class> &classes, QList<Interface> &interfaces, QList<Method> &methods)
{
    int classesSize = classes.size();
    int interfacesSize = interfaces.size();
    int methodsSize = methods.size();

    // methods and classes or interfaces aren`t empty
    if (methodsSize > 0 && (classesSize > 0 || interfacesSize > 0))
    {
        Component **parents = new Component *[methodsSize]{};
        int minDiffFirstLines = 0;
        int minDiffLastLines = 0;
        int minDiffFirstColumns = 0;
        int minDiffLastColumns = 0;
        bool isMinimumSet = false;

        // find methods` parents among classes and interfaces
        for (int i = 0; i < methodsSize; ++i)
        {
            // find methods`s parents among classes
            for (int j = 0; j < classesSize; ++j)
            {
                // field is nested into class
                if (methods[i].isNested(classes[j]))
                {
                    int diffFirstLines = abs(methods[i].location.firstLine - classes[j].location.firstLine);
                    int diffLastLines = abs(methods[i].location.lastLine - classes[j].location.lastLine);
                    int diffFirstColumns = abs(methods[i].location.firstColumn - classes[j].location.firstColumn);
                    int diffLastColumns = abs(methods[i].location.lastColumn - classes[j].location.lastColumn);

                    // difference less than minimum
                    if (!isMinimumSet ||
                        diffFirstLines < minDiffFirstLines && diffLastLines < minDiffLastLines ||
                        diffFirstLines <= minDiffFirstLines && diffLastLines <= minDiffLastLines && diffFirstColumns < minDiffFirstColumns && diffLastColumns < minDiffLastColumns)
                    {
                        isMinimumSet = true;
                        parents[i] = &classes[j];

                        // set minimum to current differences
                        minDiffFirstLines = diffFirstLines;
                        minDiffLastLines = diffLastLines;
                        minDiffFirstColumns = diffFirstColumns;
                        minDiffLastColumns = diffLastColumns;
                    }
                }
            }

            // find field`s parent among interfaces
            for (int j = 0; j < interfacesSize; ++j)
            {
                // field is nested into interface
                if (methods[i].isNested(interfaces[j]))
                {
                    int diffFirstLines = abs(methods[i].location.firstLine - interfaces[j].location.firstLine);
                    int diffLastLines = abs(methods[i].location.lastLine - interfaces[j].location.lastLine);
                    int diffFirstColumns = abs(methods[i].location.firstColumn - interfaces[j].location.firstColumn);
                    int diffLastColumns = abs(methods[i].location.lastColumn - interfaces[j].location.lastColumn);

                    // difference less than minimum
                    if (!isMinimumSet ||
                        diffFirstLines < minDiffFirstLines && diffLastLines < minDiffLastLines ||
                        diffFirstLines <= minDiffFirstLines && diffLastLines <= minDiffLastLines && diffFirstColumns < minDiffFirstColumns && diffLastColumns < minDiffLastColumns)
                    {
                        isMinimumSet = true;
                        parents[i] = &interfaces[j];

                        // set minimum to current differences
                        minDiffFirstLines = diffFirstLines;
                        minDiffLastLines = diffLastLines;
                        minDiffFirstColumns = diffFirstColumns;
                        minDiffLastColumns = diffLastColumns;
                    }
                }
            }

            isMinimumSet = false;
        }

        // insert methods into their parents
        for (int i = 0; i < methodsSize; ++i)
        {
            if (parents[i] != nullptr)
            {
                for (int j = 0; j < classesSize; ++j)
                {
                    if (&classes[j] == parents[i])
                    {
                        classes[j].methods << methods[i];
                    }
                    else if (&interfaces[j] == parents[i])
                    {
                        interfaces[j].methods << methods[i];
                    }
                }
            }
        }

        // delete methods, which have parents
        for (int i = methodsSize - 1; i >= 0; --i)
        {
            if (parents[i] != nullptr)
            {
                methods.removeAt(i);
            }
        }

        delete[] parents;
    }
}

void getComponentsText(const QString &buffer, Package &package, QList<Import> &imports, QList<Enum> &enums, QList<Interface> &interfaces, QList<Class> &classes, QList<Field> &fields, QList<Method> &methods)
{
    int importsSize = imports.size();
    int enumsSize = enums.size();
    int interfacesSize = interfaces.size();
    int classesSize = classes.size();
    int methodsSize = methods.size();
    int fieldsSize = fields.size();

    package.text = contentBetweenPositions(buffer, package.location);

    for (int i = 0; i < importsSize; ++i)
    {
        imports[i].text = contentBetweenPositions(buffer, imports[i].location);
    }

    for (int i = 0; i < enumsSize; ++i)
    {
        enums[i].text = contentBetweenPositions(buffer, enums[i].location);
    }

    for (int i = 0; i < interfacesSize; ++i)
    {
        interfaces[i].text = contentBetweenPositions(buffer, interfaces[i].location);
    }

    for (int i = 0; i < classesSize; ++i)
    {
        classes[i].text = contentBetweenPositions(buffer, classes[i].location);
    }

    for (int i = 0; i < methodsSize; ++i)
    {
        methods[i].text = contentBetweenPositions(buffer, methods[i].location);
    }

    for (int i = 0; i < fieldsSize; ++i)
    {
        fields[i].text = contentBetweenPositions(buffer, fields[i].location);
    }
}

void addComponentsToTree(Program &program, const Package &package, const QList<Import> &imports, QList<Enum> &enums, QList<Interface> &interfaces, QList<Class> &classes, QList<Field> &fields, QList<Method> &methods)
{
    findParentsToFields(classes, interfaces, fields);
    findParentsToMethods(classes, interfaces, methods);
    findParentsToEnums(classes, enums);
    findParentsToInterfaces(classes, interfaces);
    findParentsToClasses(classes);

    program.package = package;
    program.imports = imports;
    program.enums = enums;
    program.interfaces = interfaces;
    program.classes = classes;

    enums.clear();
    interfaces.clear();
    classes.clear();
}