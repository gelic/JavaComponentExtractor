/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 6 "parser.y" /* yacc.c:1909  */

    #include "program.h"

    #define COPY_POSITIONS(a, b, c) \
        { \
            a.firstLine = b.first_line; \
            a.lastLine = c.last_line; \
            a.firstColumn = b.first_column; \
            a.lastColumn = c.last_column; \
            a.fileName = b.filename; \
        }

    #define COPY_START_POSITIONS(a, b) \
        { \
            a.firstLine = b.first_line; \
            a.firstColumn = b.first_column; \
            a.fileName = b.filename; \
        }

    #define COPY_END_POSITIONS(a, b) \
        { \
            a.lastLine = b.last_line; \
            a.lastColumn = b.last_column;\
            a.fileName = b.filename; \
        }

    typedef struct YYLTYPE
    {
        int first_line;
        int first_column;
        int last_line;
        int last_column;
        char *filename;
    } YYLTYPE;

    #define YYLTYPE_IS_DECLARED 1

    #define YYLLOC_DEFAULT(Current, Rhs, N) \
        do \
            if (N) \
            { \
                (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;   \
                (Current).first_column = YYRHSLOC (Rhs, 1).first_column; \
                (Current).last_line    = YYRHSLOC (Rhs, N).last_line;    \
                (Current).last_column  = YYRHSLOC (Rhs, N).last_column;  \
                (Current).filename     = YYRHSLOC (Rhs, 1).filename;     \
            } \
            else \
            {                                                            \
                (Current).first_line   = (Current).last_line   =         \
                YYRHSLOC (Rhs, 0).last_line;                             \
                (Current).first_column = (Current).last_column =         \
                YYRHSLOC (Rhs, 0).last_column;                           \
                (Current).filename  = NULL;                              \
            }                                                            \
        while (0)

    void addEndPositionsToClassComponent(const YYLTYPE &yylocation);
    void addEndPositionsToInterfaceComponent(const YYLTYPE &yylocation);

    struct MethodNameAndParams
    {
        QList<Method::Param> params;
        QString name;
    };

#line 111 "parser.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ABSTRACT = 258,
    FINAL = 259,
    PUBLIC = 260,
    PROTECTED = 261,
    PRIVATE = 262,
    STATIC = 263,
    TRANSIENT = 264,
    VOLATILE = 265,
    NATIVE = 266,
    SYNCHRONIZED = 267,
    YYBOOLEAN = 268,
    YYBYTE = 269,
    YYCHAR = 270,
    YYDOUBLE = 271,
    YYFLOAT = 272,
    YYINT = 273,
    YYLONG = 274,
    YYSHORT = 275,
    YYVOID = 276,
    YYSTRING = 277,
    IDENTIFIER = 278,
    OP_DIM = 279,
    CLASS = 280,
    INTERFACE = 281,
    BREAK = 282,
    CASE = 283,
    CATCH = 284,
    CONTINUE = 285,
    DEFAULT = 286,
    DO = 287,
    ELSE = 288,
    EXTENDS = 289,
    FINALLY = 290,
    FOR = 291,
    IF = 292,
    IMPLEMENTS = 293,
    IMPORT = 294,
    INSTANCEOF = 295,
    NEW = 296,
    JNULL = 297,
    PACKAGE = 298,
    RETURN = 299,
    SUPER = 300,
    SWITCH = 301,
    THIS = 302,
    THROW = 303,
    THROWS = 304,
    TRY = 305,
    WHILE = 306,
    OP_INC = 307,
    OP_DEC = 308,
    OP_SHL = 309,
    OP_SHR = 310,
    OP_SHRR = 311,
    OP_GE = 312,
    OP_LE = 313,
    OP_EQ = 314,
    OP_NE = 315,
    OP_LAND = 316,
    OP_LOR = 317,
    ASS_MUL = 318,
    ASS_DIV = 319,
    ASS_MOD = 320,
    ASS_ADD = 321,
    ASS_SUB = 322,
    ASS_SHL = 323,
    ASS_SHR = 324,
    ASS_SHRR = 325,
    ASS_AND = 326,
    ASS_XOR = 327,
    ASS_OR = 328,
    LITERAL = 329,
    BOOLLIT = 330,
    ENUM = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 90 "parser.y" /* yacc.c:1909  */

    QString *str = nullptr;
    QStringList *strList;
    Method::Param *param;
    QList<Method::Param> *params;
    MethodNameAndParams *methodNameAndParams;

#line 208 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
