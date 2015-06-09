#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <vld.h>
#include "lexer.hpp"
#include "parser.hpp"
#include "stringfuncs.h"
#include "treefuncs.h"
#include "semanticerrors.h"
#include "output.h"

extern Package package;
extern QList<Import> imports;
extern QList<Enum> enums;
extern QList<Interface> interfaces;
extern QList<Class> classes;
extern QList<Field> fields;
extern QList<Method> methods;
extern char *filename;
extern int yynerrs;

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            throw QString("Invalid number of parameters");
        }

        QFile file(argv[1]);
        if (!file.open(QIODevice::ReadOnly))
        {
            throw QString("Couldn`t open file");
        }

        QTextStream in(&file);
        const QString fileContent = in.readAll();

        filename = argv[1]; // Для вывода синтаксических ошибок
        yy_scan_string(fileContent.toStdString().c_str()); // Чтобы флекс брал символы из строки

        int parseResult = yyparse();
        yylex_destroy(); // Освобождение памяти

        switch (parseResult)
        {
            case 0: break;
            case 1: throw QString("There are syntax errors"); break;
            case 2: throw QString("Bison: error while freeing memory"); break;
        }

        if (yynerrs)
        { // Есть ошибки, после которых удалось восстановиться и продолжить разбор
            throw QString("Couldn`t parse file");
        }

        QList<SemanticError> semanticErrors;
        semanticErrors = checkSemanticErrorsBeforeTreeWillBeBuilt(package, imports, enums, interfaces, classes, fields, methods);

        getComponentsText(fileContent, package, imports, enums, interfaces, classes, fields, methods);

        Program program;
        addComponentsToTree(program, package, imports, enums, interfaces, classes, fields, methods);
        semanticErrors << checkSemanticErrorsAfterTreeWasBuilt(program);

        if (!semanticErrors.length())
        {
            QString contentBetweenTwoLastPoints = QString(argv[1]).split('.')[QString(argv[1]).count('.') - 1];
            QString fileName = contentBetweenTwoLastPoints.section(QRegularExpression("[\\\\/]"), -1);
            writeTreeToFiles(fileName, program);
        }
        else
        {
            printSemanticErrors(semanticErrors);
        }
    }
    catch (const QString &e)
    {
        QTextStream out(stderr);
        out << e << endl;
    }

    return 0;
}
