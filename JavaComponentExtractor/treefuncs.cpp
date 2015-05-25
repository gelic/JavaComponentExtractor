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