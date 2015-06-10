/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 74 "parser.y" /* yacc.c:339  */

    #include "program.h"
    #pragma warning(disable: 4996)

    Package package;
    QList<Import> imports;
    QList<Enum> enums;
    QList<Interface> interfaces;
    QList<Class> classes;
    QList<Field> fields;
    QList<Method> methods;

    extern int yylex();
    extern void yyerror(const char *msg);

#line 82 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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
#line 6 "parser.y" /* yacc.c:355  */

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

    // Этот макрос будет выполняться при разборе каждого нетокена
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

    void addEndPositionsToClassComponent(const YYLTYPE &yylocation); // Для добавления конечных позиций класса
    void addEndPositionsToInterfaceComponent(const YYLTYPE &yylocation); // Для добавления конечных позиций интерфейса

    struct MethodNameAndParams
    {
        QList<Method::Param> params;
        QString name;
    };

#line 180 "parser.cpp" /* yacc.c:355  */

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
#line 91 "parser.y" /* yacc.c:355  */

    QString *str = nullptr;
    QStringList *strList;
    Method::Param *param;
    QList<Method::Param> *params;
    MethodNameAndParams *methodNameAndParams;

#line 277 "parser.cpp" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 308 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1700

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  301
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  491

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,     2,     2,     2,    94,    97,     2,
      84,    85,    80,    91,    77,    92,    79,    93,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    78,
      95,    83,    96,   100,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    87,     2,    88,    98,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,    99,    82,    89,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   139,   148,   149,   153,   159,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   181,   182,
     186,   187,   191,   192,   193,   194,   195,   196,   197,   201,
     211,   212,   216,   217,   221,   222,   226,   233,   240,   249,
     258,   262,   263,   272,   274,   276,   278,   280,   282,   287,
     300,   311,   322,   333,   342,   351,   360,   370,   388,   399,
     415,   431,   440,   449,   463,   473,   482,   492,   498,   507,
     513,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   535,   539,   545,   554,   555,   559,   560,   564,   565,
     566,   567,   568,   569,   570,   574,   586,   598,   599,   603,
     604,   608,   609,   610,   614,   615,   616,   620,   633,   644,
     655,   667,   677,   685,   693,   700,   709,   717,   728,   729,
     738,   742,   743,   747,   758,   767,   776,   786,   796,   807,
     811,   815,   816,   820,   821,   825,   826,   830,   835,   843,
     844,   845,   846,   847,   848,   849,   850,   854,   858,   863,
     864,   868,   872,   873,   874,   878,   879,   880,   881,   885,
     886,   887,   891,   892,   896,   900,   901,   905,   910,   911,
     916,   917,   918,   919,   923,   924,   925,   926,   930,   931,
     935,   939,   946,   954,   958,   963,   967,   968,   969,   973,
     974,   978,   979,   980,   981,   982,   986,   991,   995,  1000,
    1005,  1010,  1015,  1023,  1024,  1028,  1029,  1030,  1038,  1039,
    1040,  1044,  1045,  1049,  1050,  1058,  1059,  1060,  1061,  1062,
    1063,  1067,  1072,  1077,  1082,  1090,  1097,  1102,  1112,  1113,
    1117,  1121,  1122,  1131,  1132,  1136,  1137,  1141,  1142,  1143,
    1144,  1148,  1149,  1153,  1154,  1158,  1159,  1163,  1164,  1165,
    1166,  1170,  1175,  1185,  1195,  1196,  1197,  1198,  1202,  1203,
    1204,  1208,  1209,  1210,  1211,  1215,  1216,  1217,  1218,  1219,
    1220,  1228,  1229,  1230,  1234,  1235,  1239,  1240,  1244,  1245,
    1249,  1250,  1254,  1255,  1259,  1260,  1264,  1265,  1269,  1270,
    1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,  1280,
    1284,  1288
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABSTRACT", "FINAL", "PUBLIC",
  "PROTECTED", "PRIVATE", "STATIC", "TRANSIENT", "VOLATILE", "NATIVE",
  "SYNCHRONIZED", "YYBOOLEAN", "YYBYTE", "YYCHAR", "YYDOUBLE", "YYFLOAT",
  "YYINT", "YYLONG", "YYSHORT", "YYVOID", "YYSTRING", "IDENTIFIER",
  "OP_DIM", "CLASS", "INTERFACE", "BREAK", "CASE", "CATCH", "CONTINUE",
  "DEFAULT", "DO", "ELSE", "EXTENDS", "FINALLY", "FOR", "IF", "IMPLEMENTS",
  "IMPORT", "INSTANCEOF", "NEW", "JNULL", "PACKAGE", "RETURN", "SUPER",
  "SWITCH", "THIS", "THROW", "THROWS", "TRY", "WHILE", "OP_INC", "OP_DEC",
  "OP_SHL", "OP_SHR", "OP_SHRR", "OP_GE", "OP_LE", "OP_EQ", "OP_NE",
  "OP_LAND", "OP_LOR", "ASS_MUL", "ASS_DIV", "ASS_MOD", "ASS_ADD",
  "ASS_SUB", "ASS_SHL", "ASS_SHR", "ASS_SHRR", "ASS_AND", "ASS_XOR",
  "ASS_OR", "LITERAL", "BOOLLIT", "ENUM", "','", "';'", "'.'", "'*'",
  "'{'", "'}'", "'='", "'('", "')'", "':'", "'['", "']'", "'~'", "'!'",
  "'+'", "'-'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'", "'?'",
  "$accept", "TypeSpecifier", "TypeName", "ClassNameList", "PrimitiveType",
  "SemiColons", "CompilationUnit", "ProgramFile", "PackageStatement",
  "TypeDeclarations", "TypeDeclarationOptSemi", "ImportStatements",
  "ImportStatement", "QualifiedName", "TypeDeclaration", "ClassHeader",
  "InterfaceHeader", "EnumHeader", "EnumList", "Modifiers", "Modifier",
  "Interfaces", "Extends", "FieldDeclarations", "FieldDeclarationOptSemi",
  "FieldDeclaration", "FieldVariableDeclaration", "VariableDeclarators",
  "VariableDeclarator", "VariableInitializer", "ArrayInitializers",
  "MethodDeclaration", "MethodDeclarator", "ParameterList", "Parameter",
  "DeclaratorName", "Throws", "MethodBody", "ConstructorDeclaration",
  "ConstructorDeclarator", "StaticInitializer", "NonStaticInitializer",
  "Block", "LocalVariableDeclarationsAndStatements",
  "LocalVariableDeclarationOrStatement",
  "LocalVariableDeclarationStatement", "Statement", "EmptyStatement",
  "LabelStatement", "ExpressionStatement", "SelectionStatement",
  "IterationStatement", "ForInit", "ForExpr", "ForIncr",
  "ExpressionStatements", "JumpStatement", "GuardingStatement", "Catches",
  "Catch", "CatchHeader", "Finally", "PrimaryExpression", "NotJustName",
  "ComplexPrimary", "ComplexPrimaryNoParenthesis", "ArrayAccess",
  "FieldAccess", "MethodCall", "MethodAccess", "SpecialName",
  "ArgumentList", "NewAllocationExpression",
  "PlainNewAllocationExpression", "ClassAllocationExpression",
  "ArrayAllocationExpression", "DimExprs", "DimExpr", "Dims",
  "PostfixExpression", "RealPostfixExpression", "UnaryExpression",
  "LogicalUnaryExpression", "LogicalUnaryOperator",
  "ArithmeticUnaryOperator", "CastExpression", "PrimitiveTypeExpression",
  "ClassTypeExpression", "MultiplicativeExpression", "AdditiveExpression",
  "ShiftExpression", "RelationalExpression", "EqualityExpression",
  "AndExpression", "ExclusiveOrExpression", "InclusiveOrExpression",
  "ConditionalAndExpression", "ConditionalOrExpression",
  "ConditionalExpression", "AssignmentExpression", "AssignmentOperator",
  "Expression", "ConstantExpression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,    44,    59,    46,
      42,   123,   125,    61,    40,    41,    58,    91,    93,   126,
      33,    43,    45,    47,    37,    60,    62,    38,    94,   124,
      63
};
# endif

#define YYPACT_NINF -342

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-342)))

#define YYTABLE_NINF -208

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     781,   -50,  -342,  -342,  -342,  -342,  -342,  -342,  -342,  -342,
    -342,  -342,    18,    55,   155,   109,   157,    91,  -342,  1507,
     576,  -342,  1547,  -342,    40,   -33,    60,   105,   962,  -342,
    -342,   200,   200,   109,  -342,   118,   154,  -342,  -342,   576,
    1587,  -342,   576,  -342,  -342,   146,   695,   721,    19,   184,
     212,   220,  -342,   614,   109,  -342,    59,  -342,    59,   201,
     -13,   146,   239,   146,   576,  -342,   162,   202,  -342,  -342,
    -342,  -342,  -342,  -342,  -342,  -342,  -342,  -342,   203,   441,
    -342,   242,   278,  -342,   225,  -342,  1624,   747,  -342,    40,
     233,  -342,  -342,    -6,  -342,  -342,  -342,  -342,   829,  -342,
    -342,   126,   200,   200,  -342,  -342,   236,   225,   614,  -342,
    -342,    51,   146,  -342,    40,  -342,  -342,   394,   614,   234,
     237,    14,  1373,    96,   240,   902,   235,   238,   614,  -342,
    1075,  -342,   244,   250,  1373,   202,   246,  1414,  1414,  -342,
    -342,  -342,  -342,  1373,  -342,  -342,  -342,  -342,   242,   253,
      64,  -342,   522,  -342,  -342,  -342,  -342,  -342,   255,  -342,
    -342,  -342,  -342,  -342,   256,   247,   252,  -342,  -342,  -342,
     254,   259,  -342,  -342,   258,   264,   174,   261,   181,  -342,
    1414,  1373,  -342,    95,   198,   205,    77,   232,   249,   251,
     248,   289,    53,  -342,  -342,  -342,  -342,   275,  -342,    74,
      -1,  -342,   330,   242,    -6,  -342,  -342,   146,  -342,   109,
     202,  -342,  -342,   332,  -342,  -342,    59,  -342,    59,   109,
    -342,    40,   146,   614,  -342,   242,    73,  -342,   242,  1373,
    -342,   279,  -342,   253,   100,  -342,  -342,   270,   280,  -342,
    -342,   308,   603,  1373,    25,  -342,   282,  1373,   320,   286,
     148,  1373,  1373,  -342,  -342,   103,    29,   281,   283,   285,
     217,    38,   340,   190,  1373,  -342,  -342,  -342,   344,  1373,
    1088,   855,   982,  -342,  -342,   349,  -342,  -342,  -342,  -342,
    -342,  -342,  -342,  -342,  -342,  -342,  -342,  -342,  1373,  -342,
    -342,  1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,   614,
    1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,
    1373,  1373,   242,  -342,  -342,    86,  -342,  -342,  -342,  1168,
     491,  -342,   275,    74,   202,  -342,   236,  -342,  -342,  -342,
    -342,   225,   146,   242,   350,   369,  -342,   221,   291,  -342,
    -342,  -342,   293,  -342,  -342,  -342,  1209,   223,   294,  1250,
    1373,    35,  -342,   330,  -342,   295,   614,  -342,   309,   202,
     148,  -342,   202,  -342,   310,   311,   330,   330,  1373,  1373,
    1455,  -342,  -342,  -342,   250,  -342,   290,  -342,   312,  -342,
      84,  -342,  -342,   881,   995,  -342,  -342,   141,  -342,  -342,
    -342,  -342,  -342,  -342,    95,    95,   198,   198,   198,  -342,
     205,   205,   205,   205,    77,    77,   232,   249,   251,   248,
     289,   313,  -342,  -342,  -342,  -342,   115,    86,  -342,  -342,
     350,  -342,  -342,   902,  1373,  -342,  1291,   323,  1373,  -342,
     902,  -342,   116,   315,  -342,   330,   202,   321,   614,  -342,
    -342,  -342,  -342,   902,  -342,  -342,  -342,  -342,  -342,  -342,
    1373,  -342,  -342,  -342,   143,  1168,  -342,  1373,  -342,  -342,
    -342,   319,   902,   334,   343,  -342,  -342,   388,  -342,  -342,
    -342,  1332,    48,  -342,  -342,  -342,  -342,  -342,   345,  -342,
     902,   902,  -342,   129,   337,  -342,  -342,  -342,  -342,  -342,
    -342
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,     0,     0,     0,     0,     0,    21,     0,
      28,    30,     0,    34,    32,     0,     0,     0,     0,    69,
      40,    56,    64,     0,    41,     0,     0,    66,     1,    24,
       0,    31,    25,    35,    18,    33,     0,     0,     0,     0,
       0,     0,    70,     0,     0,    55,    54,    63,    62,     0,
       0,    36,     0,    29,    22,    19,     0,    76,     8,    10,
       9,    15,    14,    12,    13,    11,    16,    17,    41,     0,
      44,     0,     2,     4,     5,    93,     0,     0,    84,    86,
       0,    89,    90,     0,    91,    92,   130,    46,     0,    67,
      47,     0,    53,    61,    65,    82,    81,     6,     0,    52,
      60,     0,    38,    42,     0,    94,   129,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,   210,
       0,   209,     0,   208,     0,     0,     0,     0,     0,   191,
     192,   147,   132,     0,   243,   244,   245,   246,     0,     4,
     184,   146,     0,   133,   135,   136,   139,   140,     0,   142,
     143,   144,   145,   233,   185,   188,   190,   193,   194,   195,
       0,   186,   187,   213,   216,   215,   241,   234,   247,   240,
       0,     0,   254,   258,   261,   265,   271,   274,   276,   278,
     280,   282,   284,   286,   300,   151,   118,    96,    97,     0,
      99,   231,     3,     0,     0,    43,    85,    87,    88,     0,
       0,   126,    45,     0,    48,    51,    50,    59,    58,     0,
      83,     0,    37,     0,   128,     0,     0,   114,     0,     0,
     148,     0,   168,     0,   184,   247,   301,     0,     0,   170,
     150,     0,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   251,   184,     0,     0,     0,
       0,    99,     0,     0,     0,   131,   134,   141,     0,     0,
       0,     0,     0,   235,   236,     0,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   288,     0,   242,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   122,     0,   110,   121,   119,     0,
       0,   232,    95,     0,     0,   124,   120,   125,    68,    49,
      57,     7,    39,     0,   116,     0,   127,     0,     0,   167,
     149,   169,     0,   161,   160,   165,     0,     0,     0,     0,
       0,   226,   228,   227,   171,     0,     0,   173,     0,     0,
     176,   178,     0,   175,     0,     0,   252,   253,     0,     0,
     189,   137,   202,   201,   200,   214,     0,   198,     0,   204,
       0,   211,   218,     0,     0,   217,   104,     0,   101,   199,
     287,   255,   256,   257,   259,   260,   262,   263,   264,   270,
     269,   268,   266,   267,   272,   273,   275,   277,   279,   281,
     283,     0,    98,   109,   100,   112,     0,     0,   108,   123,
     117,   115,   138,     0,     0,   163,     0,     0,     0,   159,
       0,   223,     0,     0,   229,   225,     0,     0,     0,   183,
     179,   177,   180,     0,   189,   248,   249,   250,   196,   197,
       0,   203,   220,   102,     0,   106,   219,     0,   111,   107,
     174,     0,     0,     0,   164,   162,   166,   152,   221,   230,
     154,     0,     0,   155,   212,   103,   105,   285,     0,   158,
       0,     0,   224,     0,     0,   182,   156,   157,   153,   222,
     181
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -342,   -57,   -29,   224,   -32,    -9,  -342,  -342,  -342,   120,
     117,   427,    88,   -14,   -35,  -342,  -342,  -342,  -342,   -30,
      16,    68,     4,   -41,   -67,  -342,  -342,  -139,   135,  -306,
      65,  -342,   245,   130,   131,   -78,  -169,  -277,  -342,   365,
    -342,  -342,   -42,  -342,   300,   228,  -118,  -342,  -342,  -224,
    -342,  -342,  -342,  -342,  -342,    39,  -342,  -342,  -342,   107,
    -342,   114,  -342,  -342,  -342,  -342,  -342,  -342,  -342,  -342,
    -342,  -341,  -342,   213,  -342,  -342,  -342,   124,  -186,  -342,
    -342,   134,   110,  -342,  -342,  -147,  -342,  -342,    13,   -28,
     -26,     5,   175,   177,   182,   187,   188,  -342,  -120,   209,
    -342,   -53,  -342
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    81,    82,   106,   233,    45,    17,    18,    19,    20,
      21,    22,    23,   234,    24,    25,    26,    27,   101,    28,
      29,    55,    56,    87,    88,    89,    90,   197,   198,   386,
     387,    91,   199,   226,   227,   261,   210,   316,    92,    93,
      94,    95,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   346,   426,   463,   347,   161,   162,   360,   361,
     362,   363,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   380,   172,   173,   174,   175,   351,   352,   202,   176,
     177,   178,   179,   180,   181,   182,   257,   258,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     288,   195,   237
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    36,   236,   200,    96,    96,    98,   241,   432,   260,
     113,    85,    85,   414,    83,    83,    86,    86,   345,    59,
     206,    83,   148,   318,   105,   116,    61,    63,    30,   203,
     315,   206,    84,    84,   290,   324,    58,   231,   413,    84,
     107,    31,    99,   209,    52,    96,   418,   149,    46,   201,
     112,   211,    85,   201,    83,    83,    96,    86,   353,   201,
     225,   228,   318,    85,   322,   150,    83,   114,    86,   366,
     367,   484,    84,    84,   113,    79,    83,   246,    32,   220,
     207,   249,   319,   320,    84,    83,    83,    -5,    -5,   337,
     259,    38,   232,   250,    84,   148,    83,    54,   313,   244,
      57,   100,    52,    84,    84,   222,   216,   218,   263,   349,
      43,   255,   350,  -207,    84,   310,   264,   299,    44,   238,
     149,   319,   350,   209,   109,   200,   110,   201,    43,   256,
     483,   221,    34,   485,   300,   301,   108,    41,   150,    39,
     459,    47,    42,   263,   391,   392,   393,   334,  -207,   476,
     335,   264,   314,   311,   417,    79,    41,   317,   336,    41,
      64,   450,   325,    33,   314,   435,   333,    79,   327,   451,
     215,   217,   302,   303,   239,   291,   338,   358,    34,   263,
      37,    41,   262,   359,  -207,   148,    48,   264,   292,   293,
     348,    83,   335,   450,   355,   107,    44,    60,   364,   365,
     458,   468,   345,   213,   466,   331,   450,   102,   214,    84,
     149,   376,   332,   113,   489,   373,   378,   381,   455,   388,
     455,   445,   446,   456,    65,   475,   273,   274,   150,    96,
     383,   128,    44,    62,    53,   103,    85,   374,    54,    83,
     115,    86,   399,   104,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   420,   235,    84,   411,   296,
     297,   298,   113,   225,   287,   196,   388,    83,   396,   397,
     398,   253,   254,   317,   400,   401,   402,   403,   225,    44,
     111,   317,   419,    79,   329,    84,   330,   117,    83,   294,
     295,   304,   305,   427,   312,   371,   381,   433,   312,   422,
     428,   429,   201,    83,    62,   460,    84,   394,   395,   404,
     405,   208,   467,   219,   289,   235,   206,   439,   229,   242,
     442,    84,   243,   230,    83,   473,   240,   437,   247,   248,
     251,   388,   262,   267,   269,   268,  -205,   477,   270,   271,
     275,    96,    84,  -206,   479,   272,   306,   308,    85,   307,
     309,    83,   312,    86,   321,   328,   340,   339,   341,   342,
     354,   356,   487,   488,   357,   372,   368,   377,   369,    84,
     370,   461,   389,   223,   318,   317,   423,   424,   448,   430,
     436,   472,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    34,   438,   470,   443,   444,   474,   223,   457,
     449,   465,   388,   469,   478,   471,    83,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    34,   381,   480,
     428,   481,   490,   486,    84,   235,   235,   235,   235,   235,
     235,   235,   235,   326,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   118,    40,   412,   323,   454,
     416,   204,   266,   119,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   120,   464,   421,   440,   121,   122,
     344,   123,   124,   125,   441,   434,   375,   126,   127,   224,
     447,   406,   128,   129,   407,   130,   131,   132,   133,   134,
     408,   135,   136,   137,   138,   223,   409,   390,   410,     0,
       0,     0,   235,   235,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    34,   139,   140,     0,     0,   141,
       0,     0,    79,   142,     0,   143,   118,     0,     0,     0,
     144,   145,   146,   147,   119,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   120,     0,     0,     0,   121,
     122,     0,   123,   124,   125,     0,     0,     0,   126,   127,
       0,     0,     0,   128,   129,     0,   130,   131,   132,   133,
     134,     0,   135,   136,   137,   138,   415,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,   235,     0,     0,     0,     0,   139,   140,     0,     0,
     141,    12,    13,    79,   265,     0,   143,   118,     0,     0,
       0,   144,   145,   146,   147,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    34,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    34,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,   131,     0,
     133,     0,    16,     0,     0,   137,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   140,     0,
       0,   343,     0,     0,     0,     0,     0,   143,     0,     0,
       0,     0,   144,   145,   146,   147,    66,     0,     2,     3,
       4,     5,     6,    67,     8,     9,    10,    11,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
      12,    13,    66,     0,     2,     3,     4,     5,     6,    67,
       8,     9,    10,    11,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,    12,    13,    66,     0,
       2,     3,     4,     5,     6,    67,     8,     9,    10,    11,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    16,    12,    13,     0,     0,    79,    80,     0,     0,
       0,   -20,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,    16,     0,     0,
       0,     0,    79,    97,     0,     0,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,    16,    15,     0,     0,     0,    79,   205,
      66,     0,     2,     3,     4,     5,     6,    67,     8,     9,
      10,    11,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,    12,    13,    66,    16,     2,     3,
       4,     5,     6,    67,     8,     9,    10,    11,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
      12,    13,    66,     0,     2,     3,     4,     5,     6,    67,
       8,     9,    10,    11,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    16,    12,    13,     0,     0,
      79,   212,     0,     0,   119,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   120,     0,     0,     0,   121,
     122,    16,   123,   124,   125,     0,    79,   382,   126,   127,
       0,     0,     0,   128,   129,     0,   130,   131,   132,   133,
     134,     0,   135,   136,   137,   138,     0,    16,     0,     0,
       0,     0,    79,   452,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,   139,   140,     0,     0,
     141,     0,     0,    79,     0,     0,   143,    49,    50,     0,
       0,   144,   145,   146,   147,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    34,     0,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    34,     0,
       0,     0,     0,   128,   129,     0,     0,   131,     0,   133,
       0,     0,     0,     0,   137,   138,   128,   129,    51,     0,
     131,     0,   133,     0,     0,     0,     0,   137,   138,     0,
       0,     0,     0,     0,     0,     0,   139,   140,     0,     0,
       0,     0,     0,   384,   385,     0,   143,     0,     0,   139,
     140,   144,   145,   146,   147,     0,   384,   453,     0,   143,
       0,     0,     0,     0,   144,   145,   146,   147,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    34,     0,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    34,     0,     0,     0,     0,   128,   129,     0,     0,
     131,     0,   133,     0,     0,     0,     0,   137,   138,   128,
     129,     0,     0,   131,     0,   133,     0,     0,     0,     0,
     137,   138,     0,     0,     0,     0,     0,     0,     0,   139,
     140,     0,     0,   245,     0,     0,     0,     0,     0,   143,
       0,     0,   139,   140,   144,   145,   146,   147,     0,     0,
       0,     0,   143,   379,     0,     0,     0,   144,   145,   146,
     147,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
     129,     0,     0,   131,     0,   133,     0,     0,     0,     0,
     137,   138,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,   140,     0,     0,     0,     0,     0,   384,
     128,   129,   143,     0,   131,     0,   133,   144,   145,   146,
     147,   137,   138,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   139,   140,     0,     0,   425,     0,     0,
       0,   128,   129,   143,     0,   131,     0,   133,   144,   145,
     146,   147,   137,   138,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   139,   140,     0,     0,     0,     0,
       0,     0,   128,   129,   143,   431,   131,     0,   133,   144,
     145,   146,   147,   137,   138,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,   140,     0,     0,     0,
       0,     0,     0,   128,   129,   143,   462,   131,     0,   133,
     144,   145,   146,   147,   137,   138,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,   140,     0,     0,
       0,     0,     0,     0,   128,   129,   143,   482,   131,     0,
     133,   144,   145,   146,   147,   137,   138,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   140,     0,
       0,     0,     0,     0,     0,   128,   129,   143,     0,   131,
       0,   133,   144,   145,   146,   147,   137,   138,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   140,
       0,     0,     0,     0,     0,     0,   128,   129,   252,     0,
     131,     0,   133,   144,   145,   146,   147,   -26,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
     140,     0,    12,    13,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,   144,   145,    14,   -27,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    14,   -23,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    14,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51
};

static const yytype_int16 yycheck[] =
{
      14,    15,   122,    81,    46,    47,    47,   125,   349,   148,
      23,    46,    47,   319,    46,    47,    46,    47,   242,    33,
      87,    53,    79,    24,    53,    67,    35,    36,    78,    86,
     199,    98,    46,    47,   181,   204,    32,    23,   315,    53,
      54,    23,    23,    49,    28,    87,   323,    79,    81,    24,
      59,    93,    87,    24,    86,    87,    98,    87,   244,    24,
     117,   118,    24,    98,   203,    79,    98,    80,    98,   255,
     256,    23,    86,    87,    23,    81,   108,   130,    23,   108,
      89,   134,    83,    84,    98,   117,   118,    23,    24,   228,
     143,     0,    78,   135,   108,   152,   128,    38,    24,   128,
      32,    82,    86,   117,   118,   114,   102,   103,    79,    84,
      22,   143,    87,    84,   128,    62,    87,    40,    78,    23,
     152,    83,    87,    49,    56,   203,    58,    24,    40,   143,
     471,    80,    23,    85,    57,    58,    77,    20,   152,    19,
     417,    81,    22,    79,   291,   292,   293,   225,    84,   455,
      77,    87,    78,   100,   323,    81,    39,   199,    85,    42,
      40,    77,   204,     8,    78,   351,   223,    81,   210,    85,
     102,   103,    95,    96,    78,    80,   229,    29,    23,    79,
      23,    64,    79,    35,    84,   242,    81,    87,    93,    94,
     243,   223,    77,    77,   247,   209,    78,    79,   251,   252,
      85,    85,   426,    77,   428,   219,    77,    23,    82,   223,
     242,   264,   221,    23,    85,    25,   269,   270,    77,   272,
      77,   368,   369,    82,    78,    82,    52,    53,   242,   271,
     271,    41,    78,    79,    34,    23,   271,    47,    38,   271,
      78,   271,   299,    23,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,   333,   122,   271,   311,    54,
      55,    56,    23,   320,    83,    23,   319,   299,   296,   297,
     298,   137,   138,   315,   300,   301,   302,   303,   335,    78,
      79,   323,   324,    81,   216,   299,   218,    84,   320,    91,
      92,    59,    60,   346,    77,    78,   349,   350,    77,    78,
      77,    78,    24,   335,    79,   423,   320,   294,   295,   304,
     305,    78,   430,    77,   180,   181,   383,   359,    84,    84,
     362,   335,    84,    86,   356,   443,    86,   356,    84,    79,
      84,   384,    79,    78,    87,    79,    84,   457,    84,    81,
      79,   383,   356,    84,   462,    81,    97,    99,   383,    98,
      61,   383,    77,   383,    24,    23,    86,    78,    78,    51,
      78,    41,   480,   481,    78,    25,    85,    23,    85,   383,
      85,   424,    23,     4,    24,   417,    85,    84,    88,    85,
      85,   438,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    84,   436,    85,    85,   450,     4,    86,
      88,    78,   455,    88,    85,    84,   438,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   471,    85,
      77,    33,    85,    78,   438,   291,   292,   293,   294,   295,
     296,   297,   298,   209,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,     4,    19,   312,   203,   384,
     320,    86,   152,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   426,   335,   360,    27,    28,
     242,    30,    31,    32,   360,   351,   263,    36,    37,    85,
     370,   306,    41,    42,   307,    44,    45,    46,    47,    48,
     308,    50,    51,    52,    53,     4,   309,   288,   310,    -1,
      -1,    -1,   368,   369,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    74,    75,    -1,    -1,    78,
      -1,    -1,    81,    82,    -1,    84,     4,    -1,    -1,    -1,
      89,    90,    91,    92,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      28,    -1,    30,    31,    32,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    41,    42,    -1,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    85,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,   457,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      78,    25,    26,    81,    82,    -1,    84,     4,    -1,    -1,
      -1,    89,    90,    91,    92,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    45,    -1,
      47,    -1,    76,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    76,    25,    26,    -1,    -1,    81,    82,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    76,    43,    -1,    -1,    -1,    81,    82,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,     1,    76,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    76,    25,    26,    -1,    -1,
      81,    82,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      28,    76,    30,    31,    32,    -1,    81,    82,    36,    37,
      -1,    -1,    -1,    41,    42,    -1,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    74,    75,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,    25,    26,    -1,
      -1,    89,    90,    91,    92,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    45,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    41,    42,    76,    -1,
      45,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    84,    -1,    -1,    74,
      75,    89,    90,    91,    92,    -1,    81,    82,    -1,    84,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,
      45,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    41,
      42,    -1,    -1,    45,    -1,    47,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    74,    75,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    89,    90,    91,
      92,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    -1,    45,    -1,    47,    -1,    -1,    -1,    -1,
      52,    53,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      41,    42,    84,    -1,    45,    -1,    47,    89,    90,    91,
      92,    52,    53,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,
      -1,    41,    42,    84,    -1,    45,    -1,    47,    89,    90,
      91,    92,    52,    53,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    84,    85,    45,    -1,    47,    89,
      90,    91,    92,    52,    53,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    84,    85,    45,    -1,    47,
      89,    90,    91,    92,    52,    53,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    84,    85,    45,    -1,
      47,    89,    90,    91,    92,    52,    53,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    84,    -1,    45,
      -1,    47,    89,    90,    91,    92,    52,    53,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    84,    -1,
      45,    -1,    47,    89,    90,    91,    92,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    90,    39,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    39,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    39,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    25,    26,    39,    43,    76,   107,   108,   109,
     110,   111,   112,   113,   115,   116,   117,   118,   120,   121,
      78,    23,    23,     8,    23,   114,   114,    23,     0,   110,
     112,   111,   110,   113,    78,   106,    81,    81,    81,    25,
      26,    76,   121,    34,    38,   122,   123,   122,   123,   114,
      79,   106,    79,   106,   110,    78,     1,     8,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    81,
      82,   102,   103,   105,   114,   115,   120,   124,   125,   126,
     127,   132,   139,   140,   141,   142,   143,    82,   124,    23,
      82,   119,    23,    23,    23,   103,   104,   114,    77,   122,
     122,    79,   106,    23,    80,    78,   143,    84,     4,    12,
      23,    27,    28,    30,    31,    32,    36,    37,    41,    42,
      44,    45,    46,    47,    48,    50,    51,    52,    53,    74,
      75,    78,    82,    84,    89,    90,    91,    92,   102,   105,
     114,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   157,   158,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   173,   174,   175,   176,   180,   181,   182,   183,
     184,   185,   186,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   202,    23,   128,   129,   133,
     136,    24,   179,   102,   140,    82,   125,   106,    78,    49,
     137,   143,    82,    77,    82,   122,   123,   122,   123,    77,
     103,    80,   106,     4,    85,   102,   134,   135,   102,    84,
      86,    23,    78,   105,   114,   182,   199,   203,    23,    78,
      86,   147,    84,    84,   103,    78,   202,    84,    79,   202,
     143,    84,    84,   182,   182,   105,   114,   187,   188,   202,
     128,   136,    79,    79,    87,    82,   145,    78,    79,    87,
      84,    81,    81,    52,    53,    79,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    83,   201,   182,
     186,    80,    93,    94,    91,    92,    54,    55,    56,    40,
      57,    58,    95,    96,    59,    60,    97,    98,    99,    61,
      62,   100,    77,    24,    78,   137,   138,   143,    24,    83,
      84,    24,   128,   133,   137,   143,   104,   143,    23,   122,
     122,   114,   106,   102,   136,    77,    85,   128,   202,    78,
      86,    78,    51,    78,   146,   150,   153,   156,   202,    84,
      87,   177,   178,   179,    78,   202,    41,    78,    29,    35,
     159,   160,   161,   162,   202,   202,   179,   179,    85,    85,
      85,    78,    25,    25,    47,   174,   202,    23,   202,    85,
     172,   202,    82,   124,    81,    82,   130,   131,   202,    23,
     200,   186,   186,   186,   189,   189,   190,   190,   190,   102,
     191,   191,   191,   191,   192,   192,   193,   194,   195,   196,
     197,   202,   129,   138,   130,    85,   134,   137,   138,   143,
     136,   135,    78,    85,    84,    78,   154,   202,    77,    78,
      85,    85,   172,   202,   178,   179,    85,   103,    84,   143,
     160,   162,   143,    85,    85,   186,   186,   183,    88,    88,
      77,    85,    82,    82,   131,    77,    82,    86,    85,   138,
     147,   202,    85,   155,   156,    78,   150,   147,    85,    88,
     143,    84,   102,   147,   202,    82,   130,   199,    85,   147,
      85,    33,    85,   172,    23,    85,    78,   147,   147,    85,
      85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   113,   113,
     113,   114,   114,   115,   115,   115,   115,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     126,   126,   126,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   131,   131,   131,   132,   132,   132,
     132,   133,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   138,   138,   139,   139,   139,   139,   140,   140,   141,
     142,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     147,   147,   147,   147,   147,   147,   147,   148,   149,   149,
     149,   150,   151,   151,   151,   152,   152,   152,   152,   153,
     153,   153,   154,   154,   155,   156,   156,   157,   157,   157,
     157,   157,   157,   157,   158,   158,   158,   158,   159,   159,
     160,   161,   161,   162,   163,   163,   164,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   167,   167,   168,   168,
     168,   168,   168,   169,   169,   170,   170,   170,   171,   171,
     171,   172,   172,   173,   173,   174,   174,   174,   174,   174,
     174,   175,   175,   175,   175,   176,   176,   176,   177,   177,
     178,   179,   179,   180,   180,   181,   181,   182,   182,   182,
     182,   183,   183,   184,   184,   185,   185,   186,   186,   186,
     186,   187,   187,   188,   189,   189,   189,   189,   190,   190,
     190,   191,   191,   191,   191,   192,   192,   192,   192,   192,
     192,   193,   193,   193,   194,   194,   195,   195,   196,   196,
     197,   197,   198,   198,   199,   199,   200,   200,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     202,   203
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     1,     3,     2,     2,     2,     1,     1,     1,     3,
       1,     2,     1,     2,     1,     2,     3,     5,     4,     6,
       2,     1,     3,     4,     3,     4,     3,     3,     4,     5,
       4,     4,     4,     3,     3,     3,     2,     5,     4,     4,
       4,     3,     3,     3,     2,     3,     2,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     2,     3,     2,     1,     3,     1,
       3,     1,     2,     3,     1,     3,     2,     5,     4,     4,
       3,     4,     3,     2,     1,     3,     2,     3,     1,     2,
       2,     1,     1,     4,     3,     3,     2,     4,     3,     2,
       1,     3,     2,     1,     2,     1,     1,     3,     4,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     1,     5,     7,     5,     5,     7,     7,     6,     2,
       1,     1,     2,     1,     1,     1,     3,     3,     2,     3,
       2,     3,     2,     3,     5,     3,     3,     4,     1,     2,
       2,     5,     4,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     3,
       3,     3,     3,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     3,     3,     4,
       4,     5,     7,     4,     6,     4,     3,     3,     1,     2,
       3,     1,     2,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     4,     4,
       4,     1,     2,     2,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* ABSTRACT  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1850 "parser.cpp" /* yacc.c:1257  */
        break;

    case 4: /* FINAL  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1856 "parser.cpp" /* yacc.c:1257  */
        break;

    case 5: /* PUBLIC  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1862 "parser.cpp" /* yacc.c:1257  */
        break;

    case 6: /* PROTECTED  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1868 "parser.cpp" /* yacc.c:1257  */
        break;

    case 7: /* PRIVATE  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1874 "parser.cpp" /* yacc.c:1257  */
        break;

    case 8: /* STATIC  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1880 "parser.cpp" /* yacc.c:1257  */
        break;

    case 9: /* TRANSIENT  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1886 "parser.cpp" /* yacc.c:1257  */
        break;

    case 10: /* VOLATILE  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1892 "parser.cpp" /* yacc.c:1257  */
        break;

    case 11: /* NATIVE  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1898 "parser.cpp" /* yacc.c:1257  */
        break;

    case 12: /* SYNCHRONIZED  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1904 "parser.cpp" /* yacc.c:1257  */
        break;

    case 13: /* YYBOOLEAN  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1910 "parser.cpp" /* yacc.c:1257  */
        break;

    case 14: /* YYBYTE  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1916 "parser.cpp" /* yacc.c:1257  */
        break;

    case 15: /* YYCHAR  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1922 "parser.cpp" /* yacc.c:1257  */
        break;

    case 16: /* YYDOUBLE  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1928 "parser.cpp" /* yacc.c:1257  */
        break;

    case 17: /* YYFLOAT  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1934 "parser.cpp" /* yacc.c:1257  */
        break;

    case 18: /* YYINT  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1940 "parser.cpp" /* yacc.c:1257  */
        break;

    case 19: /* YYLONG  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1946 "parser.cpp" /* yacc.c:1257  */
        break;

    case 20: /* YYSHORT  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1952 "parser.cpp" /* yacc.c:1257  */
        break;

    case 21: /* YYVOID  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1958 "parser.cpp" /* yacc.c:1257  */
        break;

    case 22: /* YYSTRING  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1964 "parser.cpp" /* yacc.c:1257  */
        break;

    case 23: /* IDENTIFIER  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1970 "parser.cpp" /* yacc.c:1257  */
        break;

    case 24: /* OP_DIM  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1976 "parser.cpp" /* yacc.c:1257  */
        break;

    case 102: /* TypeSpecifier  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1982 "parser.cpp" /* yacc.c:1257  */
        break;

    case 103: /* TypeName  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 1988 "parser.cpp" /* yacc.c:1257  */
        break;

    case 104: /* ClassNameList  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).strList);}
#line 1994 "parser.cpp" /* yacc.c:1257  */
        break;

    case 105: /* PrimitiveType  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 2000 "parser.cpp" /* yacc.c:1257  */
        break;

    case 114: /* QualifiedName  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 2006 "parser.cpp" /* yacc.c:1257  */
        break;

    case 120: /* Modifiers  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).strList);}
#line 2012 "parser.cpp" /* yacc.c:1257  */
        break;

    case 121: /* Modifier  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 2018 "parser.cpp" /* yacc.c:1257  */
        break;

    case 122: /* Interfaces  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).strList);}
#line 2024 "parser.cpp" /* yacc.c:1257  */
        break;

    case 123: /* Extends  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).strList);}
#line 2030 "parser.cpp" /* yacc.c:1257  */
        break;

    case 128: /* VariableDeclarators  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 2036 "parser.cpp" /* yacc.c:1257  */
        break;

    case 129: /* VariableDeclarator  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 2042 "parser.cpp" /* yacc.c:1257  */
        break;

    case 133: /* MethodDeclarator  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).methodNameAndParams);}
#line 2048 "parser.cpp" /* yacc.c:1257  */
        break;

    case 134: /* ParameterList  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).params);}
#line 2054 "parser.cpp" /* yacc.c:1257  */
        break;

    case 135: /* Parameter  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).param);}
#line 2060 "parser.cpp" /* yacc.c:1257  */
        break;

    case 136: /* DeclaratorName  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 2066 "parser.cpp" /* yacc.c:1257  */
        break;

    case 137: /* Throws  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).strList);}
#line 2072 "parser.cpp" /* yacc.c:1257  */
        break;

    case 140: /* ConstructorDeclarator  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).methodNameAndParams);}
#line 2078 "parser.cpp" /* yacc.c:1257  */
        break;

    case 179: /* Dims  */
#line 132 "parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).str);}
#line 2084 "parser.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2372 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 140 "parser.y" /* yacc.c:1646  */
    {
            *(yyval.str) += *(yyvsp[0].str);
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2382 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 154 "parser.y" /* yacc.c:1646  */
    {
            (yyval.strList) = new QStringList(*(yyvsp[0].str));
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2392 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 160 "parser.y" /* yacc.c:1646  */
    {
            *(yyval.strList) << *(yyvsp[0].str);
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2402 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 186 "parser.y" /* yacc.c:1646  */
    {throw QString("Empty file");}
#line 2408 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 202 "parser.y" /* yacc.c:1646  */
    {
            package = Package(*(yyvsp[-1].str));
            COPY_POSITIONS(package.location, (yylsp[-2]), (yylsp[0]))
            delete (yyvsp[-1].str);
            (yyvsp[-1].str) = nullptr;
        }
#line 2419 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 227 "parser.y" /* yacc.c:1646  */
    {
            imports << Import(*(yyvsp[-1].str), false);
            COPY_POSITIONS(imports.last().location, (yylsp[-2]), (yylsp[0]))
            delete (yyvsp[-1].str);
            (yyvsp[-1].str) = nullptr;
        }
#line 2430 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 234 "parser.y" /* yacc.c:1646  */
    {
            imports << Import(*(yyvsp[-3].str) + ".*", false);
            COPY_POSITIONS(imports.last().location, (yylsp[-4]), (yylsp[0]))
            delete (yyvsp[-3].str);
            (yyvsp[-3].str) = nullptr;
        }
#line 2441 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 241 "parser.y" /* yacc.c:1646  */
    {
            imports << Import(*(yyvsp[-1].str), true);
            COPY_POSITIONS(imports.last().location, (yylsp[-3]), (yylsp[0]))
            delete (yyvsp[-2].str);
            delete (yyvsp[-1].str);
            (yyvsp[-2].str) = nullptr;
            (yyvsp[-1].str) = nullptr;
        }
#line 2454 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 250 "parser.y" /* yacc.c:1646  */
    {
            imports << Import(*(yyvsp[-3].str) + ".*", true);
            COPY_POSITIONS(imports.last().location, (yylsp[-5]), (yylsp[0]))
            delete (yyvsp[-4].str);
            delete (yyvsp[-3].str);
            (yyvsp[-4].str) = nullptr;
            (yyvsp[-3].str) = nullptr;
        }
#line 2467 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2473 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 264 "parser.y" /* yacc.c:1646  */
    {
            *(yyval.str) += "." + *(yyvsp[0].str);
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2483 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 273 "parser.y" /* yacc.c:1646  */
    {addEndPositionsToClassComponent((yylsp[0]));}
#line 2489 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 275 "parser.y" /* yacc.c:1646  */
    {addEndPositionsToClassComponent((yylsp[0]));}
#line 2495 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 277 "parser.y" /* yacc.c:1646  */
    {addEndPositionsToInterfaceComponent((yylsp[0]));}
#line 2501 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 279 "parser.y" /* yacc.c:1646  */
    {addEndPositionsToInterfaceComponent((yylsp[0]));}
#line 2507 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 281 "parser.y" /* yacc.c:1646  */
    {COPY_END_POSITIONS(enums.last().location, (yylsp[0]))}
#line 2513 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 283 "parser.y" /* yacc.c:1646  */
    {COPY_END_POSITIONS(enums.last().location, (yylsp[0]))}
#line 2519 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 288 "parser.y" /* yacc.c:1646  */
    {
            classes << Class(*(yyvsp[-4].strList), *(yyvsp[-2].str), *(yyvsp[-1].strList), *(yyvsp[0].strList));
            COPY_START_POSITIONS(classes.last().location, (yylsp[-4]))
            delete (yyvsp[-4].strList);
            delete (yyvsp[-2].str);
            delete (yyvsp[-1].strList);
            delete (yyvsp[0].strList);
            (yyvsp[-4].strList) = nullptr;
            (yyvsp[-2].str) = nullptr;
            (yyvsp[-1].strList) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2536 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 301 "parser.y" /* yacc.c:1646  */
    {
            classes << Class(*(yyvsp[-3].strList), *(yyvsp[-1].str), *(yyvsp[0].strList), QStringList());
            COPY_START_POSITIONS(classes.last().location, (yylsp[-3]))
            delete (yyvsp[-3].strList);
            delete (yyvsp[-1].str);
            delete (yyvsp[0].strList);
            (yyvsp[-3].strList) = nullptr;
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2551 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 312 "parser.y" /* yacc.c:1646  */
    {
            classes << Class(*(yyvsp[-3].strList), *(yyvsp[-1].str), QStringList(), *(yyvsp[0].strList));
            COPY_START_POSITIONS(classes.last().location, (yylsp[-3]))
            delete (yyvsp[-3].strList);
            delete (yyvsp[-1].str);
            delete (yyvsp[0].strList);
            (yyvsp[-3].strList) = nullptr;
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2566 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 323 "parser.y" /* yacc.c:1646  */
    {
            classes << Class(QStringList(), *(yyvsp[-2].str), *(yyvsp[-1].strList), *(yyvsp[0].strList));
            COPY_START_POSITIONS(classes.last().location, (yylsp[-3]))
            delete (yyvsp[-2].str);
            delete (yyvsp[-1].strList);
            delete (yyvsp[0].strList);
            (yyvsp[-2].str) = nullptr;
            (yyvsp[-1].strList) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2581 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 334 "parser.y" /* yacc.c:1646  */
    {
            classes << Class(*(yyvsp[-2].strList), *(yyvsp[0].str), QStringList(), QStringList());
            COPY_START_POSITIONS(classes.last().location, (yylsp[-2]))
            delete (yyvsp[-2].strList);
            delete (yyvsp[0].str);
            (yyvsp[-2].strList) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 2594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 343 "parser.y" /* yacc.c:1646  */
    {
            classes << Class(QStringList(), *(yyvsp[-1].str), *(yyvsp[0].strList), QStringList());
            COPY_START_POSITIONS(classes.last().location, (yylsp[-2]))
            delete (yyvsp[-1].str);
            delete (yyvsp[0].strList);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2607 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 352 "parser.y" /* yacc.c:1646  */
    {
            classes << Class(QStringList(), *(yyvsp[-1].str), QStringList(), *(yyvsp[0].strList));
            COPY_START_POSITIONS(classes.last().location, (yylsp[-2]))
            delete (yyvsp[-1].str);
            delete (yyvsp[0].strList);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 361 "parser.y" /* yacc.c:1646  */
    {
            classes << Class(QStringList(), *(yyvsp[0].str), QStringList(), QStringList());
            COPY_START_POSITIONS(classes.last().location, (yylsp[-1]))
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2631 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 371 "parser.y" /* yacc.c:1646  */
    {
            if (!(yyvsp[0].strList)->isEmpty())
            {
                ++yynerrs;
                printf("%s:%d.%d: %s\n", (yylsp[0]).filename, (yylsp[0]).first_line, (yylsp[0]).first_column, "syntax error");
            }
            interfaces << Interface(*(yyvsp[-4].strList), *(yyvsp[-2].str), *(yyvsp[-1].strList));
            COPY_START_POSITIONS(interfaces.last().location, (yylsp[-4]))
            delete (yyvsp[-4].strList);
            delete (yyvsp[-2].str);
            delete (yyvsp[-1].strList);
            delete (yyvsp[0].strList);
            (yyvsp[-4].strList) = nullptr;
            (yyvsp[-2].str) = nullptr;
            (yyvsp[-1].strList) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2653 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 389 "parser.y" /* yacc.c:1646  */
    {
            interfaces << Interface(*(yyvsp[-3].strList), *(yyvsp[-1].str), *(yyvsp[0].strList));
            COPY_START_POSITIONS(interfaces.last().location, (yylsp[-3]))
            delete (yyvsp[-3].strList);
            delete (yyvsp[-1].str);
            delete (yyvsp[0].strList);
            (yyvsp[-3].strList) = nullptr;
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2668 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 400 "parser.y" /* yacc.c:1646  */
    {
            if (!(yyvsp[0].strList)->isEmpty())
            {
                ++yynerrs;
                printf("%s:%d.%d: %s\n", (yylsp[0]).filename, (yylsp[0]).first_line, (yylsp[0]).first_column, "syntax error");
            }
            interfaces << Interface(*(yyvsp[-3].strList), *(yyvsp[-1].str), QStringList());
            COPY_START_POSITIONS(interfaces.last().location, (yylsp[-3]))
            delete (yyvsp[-3].strList);
            delete (yyvsp[-1].str);
            delete (yyvsp[0].strList);
            (yyvsp[-3].strList) = nullptr;
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2688 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 416 "parser.y" /* yacc.c:1646  */
    {
            if (!(yyvsp[0].strList)->isEmpty())
            {
                ++yynerrs;
                printf("%s:%d.%d: %s\n", (yylsp[0]).filename, (yylsp[0]).first_line, (yylsp[0]).first_column, "syntax error");
            }
            interfaces << Interface(QStringList(), *(yyvsp[-2].str), *(yyvsp[-1].strList));
            COPY_START_POSITIONS(interfaces.last().location, (yylsp[-3]))
            delete (yyvsp[-2].str);
            delete (yyvsp[-1].strList);
            delete (yyvsp[0].strList);
            (yyvsp[-2].str) = nullptr;
            (yyvsp[-1].strList) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 432 "parser.y" /* yacc.c:1646  */
    {
            interfaces << Interface(*(yyvsp[-2].strList), *(yyvsp[0].str), QStringList());
            COPY_START_POSITIONS(interfaces.last().location, (yylsp[-2]))
            delete (yyvsp[-2].strList);
            delete (yyvsp[0].str);
            (yyvsp[-2].strList) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 2721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 441 "parser.y" /* yacc.c:1646  */
    {
            interfaces << Interface(QStringList(), *(yyvsp[-1].str), *(yyvsp[0].strList));
            COPY_START_POSITIONS(interfaces.last().location, (yylsp[-2]))
            delete (yyvsp[-1].str);
            delete (yyvsp[0].strList);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 450 "parser.y" /* yacc.c:1646  */
    {
            if (!(yyvsp[0].strList)->isEmpty())
            {
                ++yynerrs;
                printf("%s:%d.%d: %s\n", (yylsp[0]).filename, (yylsp[0]).first_line, (yylsp[0]).first_column, "syntax error");
            }
            interfaces << Interface(QStringList(), *(yyvsp[-1].str), QStringList());
            COPY_START_POSITIONS(interfaces.last().location, (yylsp[-2]))
            delete (yyvsp[-1].str);
            delete (yyvsp[0].strList);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].strList) = nullptr;
        }
#line 2752 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 464 "parser.y" /* yacc.c:1646  */
    {
            interfaces << Interface(QStringList(), *(yyvsp[0].str), QStringList());
            COPY_START_POSITIONS(interfaces.last().location, (yylsp[-1]))
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2763 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 474 "parser.y" /* yacc.c:1646  */
    {
            enums << Enum(*(yyvsp[-2].strList), *(yyvsp[0].str));
            COPY_START_POSITIONS(enums.last().location, (yylsp[-2]))
            delete (yyvsp[-2].strList);
            delete (yyvsp[0].str);
            (yyvsp[-2].strList) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 2776 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 483 "parser.y" /* yacc.c:1646  */
    {
            enums << Enum(QStringList(), *(yyvsp[0].str));
            COPY_START_POSITIONS(enums.last().location, (yylsp[-1]))
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2787 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 493 "parser.y" /* yacc.c:1646  */
    {
            enums.last().enumList << *(yyvsp[0].str);
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2797 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 499 "parser.y" /* yacc.c:1646  */
    {
            enums.last().enumList << *(yyvsp[0].str);
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2807 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 508 "parser.y" /* yacc.c:1646  */
    {
            (yyval.strList) = new QStringList(*(yyvsp[0].str));
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2817 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 514 "parser.y" /* yacc.c:1646  */
    {
            *(yyval.strList) << *(yyvsp[0].str);
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2827 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 535 "parser.y" /* yacc.c:1646  */
    {(yyval.strList) = (yyvsp[0].strList);}
#line 2833 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 540 "parser.y" /* yacc.c:1646  */
    {
            (yyval.strList) = new QStringList(*(yyvsp[0].str));
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2843 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 546 "parser.y" /* yacc.c:1646  */
    {
            *(yyval.strList) << *(yyvsp[0].str);
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 2853 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 564 "parser.y" /* yacc.c:1646  */
    {COPY_END_POSITIONS(fields.last().location, (yylsp[0]));}
#line 2859 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 575 "parser.y" /* yacc.c:1646  */
    {
            fields << Field(*(yyvsp[-2].strList), *(yyvsp[-1].str), *(yyvsp[0].str));
            COPY_START_POSITIONS(fields.last().location, (yylsp[-2]));
            delete (yyvsp[-2].strList);
            delete (yyvsp[-1].str);
            delete (yyvsp[0].str);
            (yyvsp[-2].strList) = nullptr;
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].str) = nullptr;

        }
#line 2875 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 587 "parser.y" /* yacc.c:1646  */
    {
            fields << Field(QStringList(), *(yyvsp[-1].str), *(yyvsp[0].str));
            COPY_START_POSITIONS(fields.last().location, (yylsp[-1]));
            delete (yyvsp[-1].str);
            delete (yyvsp[0].str);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 2888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 598 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2894 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 599 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 603 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2906 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 604 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[-2].str);}
#line 2912 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 621 "parser.y" /* yacc.c:1646  */
    {
            methods << Method(*(yyvsp[-4].strList), *(yyvsp[-3].str), (yyvsp[-2].methodNameAndParams)->name, (yyvsp[-2].methodNameAndParams)->params, *(yyvsp[-1].strList));
            COPY_POSITIONS(methods.last().location, (yylsp[-4]), (yylsp[0]))
            delete (yyvsp[-4].strList);
            delete (yyvsp[-3].str);
            delete (yyvsp[-2].methodNameAndParams);
            delete (yyvsp[-1].strList);
            (yyvsp[-4].strList) = nullptr;
            (yyvsp[-3].str) = nullptr;
            (yyvsp[-2].methodNameAndParams) = nullptr;
            (yyvsp[-1].strList) = nullptr;
        }
#line 2929 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 634 "parser.y" /* yacc.c:1646  */
    {
            methods << Method(*(yyvsp[-3].strList), *(yyvsp[-2].str), (yyvsp[-1].methodNameAndParams)->name, (yyvsp[-1].methodNameAndParams)->params, QStringList());
            COPY_POSITIONS(methods.last().location, (yylsp[-3]), (yylsp[0]))
            delete (yyvsp[-3].strList);
            delete (yyvsp[-2].str);
            delete (yyvsp[-1].methodNameAndParams);
            (yyvsp[-3].strList) = nullptr;
            (yyvsp[-2].str) = nullptr;
            (yyvsp[-1].methodNameAndParams) = nullptr;
        }
#line 2944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 645 "parser.y" /* yacc.c:1646  */
    {
            methods << Method(QStringList(), *(yyvsp[-3].str), (yyvsp[-2].methodNameAndParams)->name, (yyvsp[-2].methodNameAndParams)->params, *(yyvsp[-1].strList));
            COPY_POSITIONS(methods.last().location, (yylsp[-3]), (yylsp[0]))
            delete (yyvsp[-3].str);
            delete (yyvsp[-2].methodNameAndParams);
            delete (yyvsp[-1].strList);
            (yyvsp[-3].str) = nullptr;
            (yyvsp[-2].methodNameAndParams) = nullptr;
            (yyvsp[-1].strList) = nullptr;
        }
#line 2959 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 656 "parser.y" /* yacc.c:1646  */
    {
            methods << Method(QStringList(), *(yyvsp[-2].str), (yyvsp[-1].methodNameAndParams)->name, (yyvsp[-1].methodNameAndParams)->params, QStringList());
            COPY_POSITIONS(methods.last().location, (yylsp[-2]), (yylsp[0]))
            delete (yyvsp[-2].str);
            delete (yyvsp[-1].methodNameAndParams);
            (yyvsp[-2].str) = nullptr;
            (yyvsp[-1].methodNameAndParams) = nullptr;
        }
#line 2972 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 668 "parser.y" /* yacc.c:1646  */
    {
            (yyval.methodNameAndParams) = new MethodNameAndParams();
            (yyval.methodNameAndParams)->name = *(yyvsp[-3].str);
            (yyval.methodNameAndParams)->params = *(yyvsp[-1].params);
            delete (yyvsp[-3].str);
            delete (yyvsp[-1].params);
            (yyvsp[-3].str) = nullptr;
            (yyvsp[-1].params) = nullptr;
        }
#line 2986 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 678 "parser.y" /* yacc.c:1646  */
    {
            (yyval.methodNameAndParams) = new MethodNameAndParams();
            (yyval.methodNameAndParams)->name = *(yyvsp[-2].str);
            (yyval.methodNameAndParams)->params = QList<Method::Param>();
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr;
        }
#line 2998 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 686 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 3007 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 694 "parser.y" /* yacc.c:1646  */
    {
            (yyval.params) = new QList<Method::Param>;
            (yyval.params)->append(*(yyvsp[0].param));
            delete (yyvsp[0].param);
            (yyvsp[0].param) = nullptr;
        }
#line 3018 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 701 "parser.y" /* yacc.c:1646  */
    {
            (yyval.params)->append(*(yyvsp[0].param));
            delete (yyvsp[0].param);
            (yyvsp[0].param) = nullptr;
        }
#line 3028 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 710 "parser.y" /* yacc.c:1646  */
    {
            (yyval.param) = new Method::Param(false, *(yyvsp[-1].str), *(yyvsp[0].str));
            delete (yyvsp[-1].str);
            delete (yyvsp[0].str);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 3040 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 718 "parser.y" /* yacc.c:1646  */
    {
            (yyval.param) = new Method::Param(true, *(yyvsp[-1].str), *(yyvsp[0].str));
            delete (yyvsp[-1].str);
            delete (yyvsp[0].str);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 3052 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 728 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 3058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 730 "parser.y" /* yacc.c:1646  */
    {
            *(yyval.str) += *(yyvsp[0].str);
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 3068 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 738 "parser.y" /* yacc.c:1646  */
    {(yyval.strList) = (yyvsp[0].strList);}
#line 3074 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 748 "parser.y" /* yacc.c:1646  */
    {
            methods << Method(*(yyvsp[-3].strList), QString(), (yyvsp[-2].methodNameAndParams)->name, (yyvsp[-2].methodNameAndParams)->params, *(yyvsp[-1].strList));
            COPY_POSITIONS(methods.last().location, (yylsp[-3]), (yylsp[0]))
            delete (yyvsp[-3].strList);
            delete (yyvsp[-2].methodNameAndParams);
            delete (yyvsp[-1].strList);
            (yyvsp[-3].strList) = nullptr;
            (yyvsp[-2].methodNameAndParams) = nullptr;
            (yyvsp[-1].strList) = nullptr;
        }
#line 3089 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 759 "parser.y" /* yacc.c:1646  */
    {
            methods << Method(*(yyvsp[-2].strList), QString(), (yyvsp[-1].methodNameAndParams)->name, (yyvsp[-1].methodNameAndParams)->params, QStringList());
            COPY_POSITIONS(methods.last().location, (yylsp[-2]), (yylsp[0]))
            delete (yyvsp[-2].strList);
            delete (yyvsp[-1].methodNameAndParams);
            (yyvsp[-2].strList) = nullptr;
            (yyvsp[-1].methodNameAndParams) = nullptr;
        }
#line 3102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 768 "parser.y" /* yacc.c:1646  */
    {
            methods << Method(QStringList(), QString(), (yyvsp[-2].methodNameAndParams)->name, (yyvsp[-2].methodNameAndParams)->params, *(yyvsp[-1].strList));
            COPY_POSITIONS(methods.last().location, (yylsp[-2]), (yylsp[0]))
            delete (yyvsp[-2].methodNameAndParams);
            delete (yyvsp[-1].strList);
            (yyvsp[-2].methodNameAndParams) = nullptr;
            (yyvsp[-1].strList) = nullptr;
        }
#line 3115 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 777 "parser.y" /* yacc.c:1646  */
    {
            methods << Method(QStringList(), QString(), (yyvsp[-1].methodNameAndParams)->name, (yyvsp[-1].methodNameAndParams)->params, QStringList());
            COPY_POSITIONS(methods.last().location, (yylsp[-1]), (yylsp[0]))
            delete (yyvsp[-1].methodNameAndParams);
            (yyvsp[-1].methodNameAndParams) = nullptr;
        }
#line 3126 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 787 "parser.y" /* yacc.c:1646  */
    {
            (yyval.methodNameAndParams) = new MethodNameAndParams();
            (yyval.methodNameAndParams)->name = *(yyvsp[-3].str);
            (yyval.methodNameAndParams)->params = *(yyvsp[-1].params);
            delete (yyvsp[-3].str);
            delete (yyvsp[-1].params);
            (yyvsp[-3].str) = nullptr;
            (yyvsp[-1].params) = nullptr;
        }
#line 3140 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 797 "parser.y" /* yacc.c:1646  */
    {
            (yyval.methodNameAndParams) = new MethodNameAndParams();
            (yyval.methodNameAndParams)->name = *(yyvsp[-2].str);
            (yyval.methodNameAndParams)->params = QList<Method::Param>();
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr;
        }
#line 3152 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 831 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr;
        }
#line 3161 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 836 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr;
        }
#line 3170 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 859 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-1].str);
            (yyvsp[-1].str) = nullptr;
        }
#line 3179 "parser.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 906 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-1].str);
            (yyvsp[-1].str) = nullptr;
        }
#line 3188 "parser.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 912 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-1].str);
            (yyvsp[-1].str) = nullptr;
        }
#line 3197 "parser.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 940 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-2].str);
            delete (yyvsp[-1].str);
            (yyvsp[-2].str) = nullptr;
            (yyvsp[-1].str) = nullptr;
        }
#line 3208 "parser.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 947 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-1].str);
            (yyvsp[-1].str) = nullptr;
        }
#line 3217 "parser.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 959 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 3226 "parser.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 987 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-3].str);
            (yyvsp[-3].str) = nullptr;
        }
#line 3235 "parser.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 996 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 3244 "parser.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1001 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 3253 "parser.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1006 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr;
        }
#line 3262 "parser.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1011 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr;
        }
#line 3271 "parser.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1016 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr;
        }
#line 3280 "parser.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1031 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 3289 "parser.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1051 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr;
        }
#line 3298 "parser.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1068 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-3].str);
            (yyvsp[-3].str) = nullptr;
        }
#line 3307 "parser.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1073 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-3].str);
            (yyvsp[-3].str) = nullptr; 
        }
#line 3316 "parser.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1078 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr;
        }
#line 3325 "parser.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1083 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-2].str);
            (yyvsp[-2].str) = nullptr; 
        }
#line 3334 "parser.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1091 "parser.y" /* yacc.c:1646  */
    {   
            delete (yyvsp[-2].str);
            delete (yyvsp[0].str);
            (yyvsp[-2].str) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 3345 "parser.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1098 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-1].str);
            (yyvsp[-1].str) = nullptr;
        }
#line 3354 "parser.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1103 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-1].str);
            delete (yyvsp[0].str);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 3365 "parser.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1121 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 3371 "parser.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1123 "parser.y" /* yacc.c:1646  */
    {
            *(yyval.str) += *(yyvsp[0].str);
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 3381 "parser.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1171 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 3390 "parser.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1176 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-1].str);
            delete (yyvsp[0].str);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 3401 "parser.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1186 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-1].str);
            delete (yyvsp[0].str);
            (yyvsp[-1].str) = nullptr;
            (yyvsp[0].str) = nullptr;
        }
#line 3412 "parser.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1221 "parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[0].str);
            (yyvsp[0].str) = nullptr;
        }
#line 3421 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3425 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1290 "parser.y" /* yacc.c:1906  */


// Функция для правильного добавления положения класса
void addEndPositionsToClassComponent(const YYLTYPE &yylocation)
{
    QMutableListIterator<Class> classComponent(classes);
    classComponent.toBack();
    bool isClassFound = false;

    // С конца списка классов...
    while (classComponent.hasPrevious())
    {
        // Если класс имеет не заполненную конечную строку
        if (classComponent.previous().location.lastLine == 0)
        {
            COPY_END_POSITIONS(classComponent.value().location, yylocation)
            isClassFound = true;
            break;
        }
    }

    // У всех классов есть заполнненая конечная строка
    if (!isClassFound)
    {
        COPY_END_POSITIONS(classes.last().location, yylocation)
    }
}

// Функция для правильного добавления положения интерфейса
void addEndPositionsToInterfaceComponent(const YYLTYPE &yylocation)
{
    QMutableListIterator<Interface> interfaceComponent(interfaces);
    interfaceComponent.toBack();
    bool isInterfaceFound = false;

    // С конца списка интерфейсов...
    while (interfaceComponent.hasPrevious())
    {
        // Если интерфейс имеет не заполненную конечную строку
        if (interfaceComponent.previous().location.lastLine == 0)
        {
            COPY_END_POSITIONS(interfaceComponent.value().location, yylocation)
            isInterfaceFound = true;
            break;
        }
    }

    // У всех интерфейсов есть заполнненая конечная строка
    if (!isInterfaceFound)
    {
        COPY_END_POSITIONS(interfaces.last().location, yylocation)
    }
}
