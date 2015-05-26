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