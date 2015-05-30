#include "textlocation.h"

TextLocation::TextLocation()
{
}

TextLocation::TextLocation(int firstLine, int lastLine, int firstColumn, int lastColumn)
{
    if (firstLine > lastLine || firstLine < 0 || lastLine < 0)
    {
        firstLine = 0;
        lastLine = 0;
    }

    if (firstLine == lastLine && firstColumn > lastColumn || firstColumn < 0 || lastColumn < 0)
    {
        firstColumn = 0;
        lastColumn = 0;
    }

    this->firstLine = firstLine;
    this->lastLine = lastLine;
    this->firstColumn = firstColumn;
    this->lastColumn = lastColumn;
}

TextLocation::TextLocation(int firstLine, int lastLine, int firstColumn, int lastColumn, const QString &fileName)
{
    *this = TextLocation(firstLine, lastLine, firstColumn, lastColumn);
    this->fileName = fileName;
}


bool TextLocation::operator==(const TextLocation &location)
{
    return
        this->firstLine == location.firstLine &&
        this->lastLine == location.lastLine &&
        this->firstColumn == location.firstColumn &&
        this->lastColumn == location.lastColumn &&
        this->fileName == location.fileName;
}
