#include "stringfuncs.h"

QString contentBetweenPositions(const QString &buffer, const TextLocation &location) throw (const QString &)
{
    if (buffer.isEmpty())
    {
        return QString();
    }

    QRegularExpression rx = QRegularExpression("\\r|\\n");
    int linesCount = buffer.count(rx);

    if (location.firstLine > linesCount + 1 || location.lastLine > linesCount + 1)
    {
        throw QString("Invalid numbers of first and/or last lines");
    }

    QStringList lines = buffer.split("\r\n");
    QString split = "\r\n";
    if (lines.size() == 1)
    {
        lines = buffer.split("\n");
        split = "\n";

        if (lines.size() == 1)
        {
            lines = buffer.split("\r");
            split = "\r";
        }
    }

    int sizeOfStartStr = lines[location.firstLine - 1].length();
    int sizeOfEndStr = lines[location.lastLine - 1].length();

    if (location.firstColumn > sizeOfStartStr || location.lastColumn > sizeOfEndStr)
    {
        throw QString("Invalid numbers of first and/or last columns");
    }

    lines[location.firstLine - 1] = lines[location.firstLine - 1].right(sizeOfStartStr - location.firstColumn + 1);
    lines[location.lastLine - 1] = lines[location.lastLine - 1].left(location.lastColumn);

    QStringList resultLines;
    for (int i = location.firstLine - 1; i < location.lastLine; ++i)
        resultLines += lines[i];

    return resultLines.join(split);
}