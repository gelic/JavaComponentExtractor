#include "textlocation.h"

TextLocation::TextLocation()
{
}

TextLocation::TextLocation(int firstLine, int lastLine, int firstColumn, int lastColumn, const QString &fileName) throw (const QString &)
{
    TextLocation(firstLine, lastLine, firstColumn, lastColumn);
    this->fileName = fileName;
}

TextLocation::TextLocation(int firstLine, int lastLine, int firstColumn, int lastColumn) throw (const QString &)
{
    if (firstLine > lastLine || firstLine < 0 || lastLine < 0)
    {
        throw QString("Переданы неправильные номера начальной и/или конечной строк: %1 %2").arg(firstLine).arg(lastLine);
    }

    if (firstLine == lastLine && firstColumn > lastColumn || firstColumn < 0 || lastColumn < 0)
    {
        throw QString("Переданы неправильные номера начальной и/или конечной колонок: %1 %2").arg(firstLine).arg(lastLine);
    }

    this->firstLine = firstLine;
    this->lastLine = lastLine;
    this->firstColumn = firstColumn;
    this->lastColumn = lastColumn;
}