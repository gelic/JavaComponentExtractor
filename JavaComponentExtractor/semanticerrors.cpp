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
        out << semanticError.toString() << endl;
    }
}

QList<SemanticError> checkEnums(const QList<Enum> &enums, QSet<QString> &ids)
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

        if (!ids.contains(enumToCheck.name))
        {
            ids.insert(enumToCheck.name);
        }
        else
        {
            errors << SemanticError("Enum with non-unique name", enumToCheck.location);
        }
    }

    return errors;
}

QList<SemanticError> checkClasses(const QList<Class> &classes, QSet<QString> &ids)
{
    QList<SemanticError> errors;

    for (auto classToCheck : classes)
    {
        if (checkDuplicates(classToCheck.modificators))
        {
            errors << SemanticError("Class has repeating modificator", classToCheck.location);
        }

        if (checkDuplicates(classToCheck.baseClasses))
        {
            errors << SemanticError("Class has repeating base class", classToCheck.location);
        }

        if (checkDuplicates(classToCheck.implementedInterfaces))
        {
            errors << SemanticError("Class has repeating implemented interface", classToCheck.location);
        }

        if (!ids.contains(classToCheck.name))
        {
            ids.insert(classToCheck.name);
        }
        else
        {
            errors << SemanticError("Class with non-unique name", classToCheck.location);
        }

        QSet<QString> localIds;
        localIds.insert(classToCheck.name);
        errors << checkFields(classToCheck.fields, localIds);
        errors << checkMethods(classToCheck.methods, localIds);
        errors << checkInterfaces(classToCheck.nestedInterfaces, localIds);
        if (classToCheck.nestedClasses.size() != 0)
        {
            errors << checkClasses(classToCheck.nestedClasses, localIds);
        }
        localIds.clear();
    }

    return errors;
}

QList<SemanticError> checkInterfaces(const QList<Interface> &interfaces, QSet<QString> &ids)
{
    QList<SemanticError> errors;

    for (auto interface : interfaces)
    {
        if (checkDuplicates(interface.modificators))
        {
            errors << SemanticError("Interface has repeating modificator", interface.location);
        }

        if (!ids.contains(interface.name))
        {
            ids.insert(interface.name);
        }
        else
        {
            errors << SemanticError("Interface with non-unique name", interface.location);
        }

        QSet<QString> localIds;
        localIds.insert(interface.name);
        errors << checkFields(interface.fields, localIds);
        errors << checkMethods(interface.methods, localIds);
        localIds.clear();
    }

    return errors;
}

QList<SemanticError> checkFields(const QList<Field> &fields, QSet<QString> &ids)
{
    QList<SemanticError> errors;

    for (auto field : fields)
    {
        if (checkDuplicates(field.modificators))
        {
            errors << SemanticError("Field has repeating modificator", field.location);
        }

        if (!ids.contains(field.name))
        {
            ids.insert(field.name);
        }
        else
        {
            errors << SemanticError("Field with non-unique name", field.location);
        }
    }

    return errors;
}

QList<SemanticError> checkMethods(const QList<Method> &methods, QSet<QString> &ids)
{
    QList<SemanticError> errors;

    for (auto method : methods)
    {
        if (checkDuplicates(method.modificators))
        {
            errors << SemanticError("Method has repeating modificator", method.location);
        }

        if (!ids.contains(method.name) || method.returnValue.isEmpty())
        {
            ids.insert(method.name);
        }
        else
        {
            errors << SemanticError("Method with non-unique name", method.location);
        }
    }

    return errors;
}

QList<SemanticError> checkSemanticErrorsBeforeTreeWillBeBuilt(const Package &package, const QList<Import> &imports, const QList<Enum> &enums, const QList<Interface> &interfaces, const QList<Class> &classes, const QList<Field> &fields, const QList<Method> &methods)
{
    return checkNestedClassesAndInterfacesInEachInterface(interfaces, classes);
}

QList<SemanticError> checkSemanticErrorsAfterTreeWasBuilt(const Program &program)
{
    QList<SemanticError> errors;
    QSet<QString> ids;

    errors << checkEnums(program.enums, ids);
    errors << checkInterfaces(program.interfaces, ids);
    errors << checkClasses(program.classes, ids);

    return errors;
}