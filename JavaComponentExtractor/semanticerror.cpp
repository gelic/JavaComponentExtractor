#include "semanticerror.h"

SemanticError::SemanticError(const QString &message, const TextLocation &anotherLocaiton)
{
    this->message = message;
    this->location = TextLocation(anotherLocaiton.firstLine, anotherLocaiton.lastLine, anotherLocaiton.firstColumn, anotherLocaiton.lastColumn);
}

QString SemanticError::toString() const
{
    return QString("%2.%3: ").arg(location.firstLine).arg(location.firstColumn) + message;
}

bool SemanticError::operator==(const SemanticError &error)
{
    return
        this->message == error.message &&
        this->location == error.location;
}
