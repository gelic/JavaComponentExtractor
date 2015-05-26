#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include "../JavaComponentExtractor/program.h"
#include "../JavaComponentExtractor/semanticerror.h"

Q_DECLARE_METATYPE(TextLocation)
Q_DECLARE_METATYPE(Component);
Q_DECLARE_METATYPE(Package);
Q_DECLARE_METATYPE(QList<Import>);
Q_DECLARE_METATYPE(QList<Enum>);
Q_DECLARE_METATYPE(QList<Field>);
Q_DECLARE_METATYPE(QList<Method>);
Q_DECLARE_METATYPE(QList<Interface>);
Q_DECLARE_METATYPE(QList<Class>);
Q_DECLARE_METATYPE(QList<SemanticError>);

#endif // !DECLARATIONS_H