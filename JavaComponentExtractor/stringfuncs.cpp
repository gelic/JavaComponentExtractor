#include "stringfuncs.h"

QString contentBetweenPositions(const QString &buffer, const TextLocation &location) throw (const QString &)
{
    if (buffer.isEmpty())
    {
        return QString();
    }

    static int linesCount = buffer.count(QRegularExpression("\\n|\\r"));

    if (location.firstLine > linesCount + 1 || location.lastLine > linesCount + 1)
    {
        throw QString("Invalid numbers of first and/or last lines");
    }

    // Определение стиля концов строк
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

    // Обрезать символы левее начальной колонки в начальной строке
    lines[location.firstLine - 1] = lines[location.firstLine - 1].right(sizeOfStartStr - location.firstColumn + 1);
    // Обрезать символы правее конечной колонки в конечной строке
    lines[location.lastLine - 1] = lines[location.lastLine - 1].left(location.lastColumn);

    // Склеить строки, начиная от начальной и заканчивая конечной
    QStringList resultLines;
    for (int i = location.firstLine - 1; i < location.lastLine; ++i)
    {
        resultLines += lines[i];
    }

    return resultLines.join(split);
}
