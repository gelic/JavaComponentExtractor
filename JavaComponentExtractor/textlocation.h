#ifndef LOCATION_H
#define LOCATION_H

#include <QString>

// Класс, описывающий начальное и конечное положения компонента в файле
class TextLocation
{
public:
    int firstLine = 0;
    int lastLine = 0;
    int firstColumn = 0;
    int lastColumn = 0;
    QString fileName = "";

    TextLocation();
    TextLocation(int firstLine, int lastLine, int firstColumn, int lastColumn, const QString &fileName) throw (const QString &);
    TextLocation(int firstLine, int lastLine, int firstColumn, int lastColumn) throw (const QString &);
};

#endif // LOCATION_H