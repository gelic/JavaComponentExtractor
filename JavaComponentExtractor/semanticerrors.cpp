#include "semanticerrors.h"

QList<SemanticError> checkNestedClassesAndInterfacesInEachInterface(const QList<Interface> &interfaces, const QList<Class> &classes)
{
    QList<SemanticError> errors;

    for (auto interface : interfaces)
    {
        for (auto checkingClass : classes)
        {
            if (checkingClass.isNested(interface))
            {
                errors << SemanticError("There is nested class in interface", interface.location);
            }
        }

        for (auto anotherInterface : interfaces)
        {
            if (anotherInterface.isNested(interface))
            {
                errors << SemanticError("There is nested interface in interface", interface.location);
            }
        }
    }

    return errors;
}

bool checkDuplicates(const QStringList &strList)
{
    if (strList.size() != strList.toSet().size())
    {
        return true;
    }
    return false;
}

void printSemanticErrors(const QList<SemanticError> semanticErrors)
{
    for (auto semanticError : semanticErrors)
    {
        QTextStream out(stderr);
        out << semanticError.toString();
    }
}

QList<SemanticError> checkEnums(const QList<Enum> &enums)
{
    QSet<QString> names;
    QList<SemanticError> errors;

    for (auto enumToCheck : enums)
    {
        if (checkDuplicates(enumToCheck.modificators))
        {
            errors << SemanticError("Enum has repeating modificator", enumToCheck.location);
        }

        if (checkDuplicates(enumToCheck.enumList) || enumToCheck.enumList.contains(enumToCheck.name))
        {
            errors << SemanticError("Enum has repeating field", enumToCheck.location);
        }

        if (!names.contains(enumToCheck.name))
        {
            names.insert(enumToCheck.name);
        }
        else
        {
            errors << SemanticError("There is enum with non-unique name", enumToCheck.location);
        }
    }

    return errors;
}