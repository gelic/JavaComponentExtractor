#ifndef SEMANTICERROR_H
#define SEMANTICERROR_H

#include <QStringList>
#include <QString>
#include <QTextStream>
#include <QSet>
#include "program.h"

// Класс, содержащий информацию о семантической ошибке
class SemanticError
{
public:
    SemanticError(const QString &message, const TextLocation &anotherLocaiton);

    QString toString() const;
    bool operator==(const SemanticError &error);

private:
    QString message;
    TextLocation location;
};

#endif // SEMANTICERROR_H