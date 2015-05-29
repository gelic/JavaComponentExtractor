/*!
*\file
*\brief Файл объявления класса семантической ошибки.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный файл содержит в себе класс семантической ошибки.
*/

#ifndef SEMANTICERROR_H
#define SEMANTICERROR_H

#include <QStringList>
#include <QString>
#include <QTextStream>
#include <QSet>
#include "program.h"

/*!
*\brief Класс семантической ошибки.
*\author Александр Мелихов amelihovv@ya.ru.
*
* Данный класс описывает семантическую ошибку.
*/
class SemanticError
{
public:
    /*! Создает объект семантической ошибки на основании переданных сообщения и положения. */
    SemanticError(const QString &message, const TextLocation &anotherLocaiton);

    /*! Возвращает строковое представление семантической ошибки в формате: "строка.колонка: сообщение об ошибке". */
    QString toString() const;
    /*! Сравнивает две семантические ошибки между собой. */
    bool operator==(const SemanticError &error);

private:
    QString message; ///< Сообщение о семантической ошибке.
    TextLocation location; ///< Положение ошибки.
};

#endif // SEMANTICERROR_H