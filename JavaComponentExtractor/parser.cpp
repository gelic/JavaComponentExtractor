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
#line 62 "parser.y" /* yacc.c:339  */

    #include <QString>

    #pragma warning(disable: 4996)

    extern int yylex();
    extern void yyerror(const char *msg);

#line 75 "parser.cpp" /* yacc.c:339  */

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

#line 161 "parser.cpp" /* yacc.c:355  */

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
typedef int YYSTYPE;
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

#line 275 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   1640

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  299
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  484

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
       0,   102,   102,   103,   107,   108,   112,   113,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   130,   131,
     135,   136,   140,   141,   142,   143,   144,   145,   146,   150,
     154,   155,   159,   160,   164,   165,   169,   170,   171,   172,
     173,   177,   178,   182,   183,   184,   185,   186,   187,   191,
     192,   193,   194,   195,   196,   197,   198,   202,   203,   204,
     205,   206,   207,   208,   209,   213,   214,   218,   219,   223,
     224,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   241,   245,   246,   250,   251,   255,   256,   260,   261,
     262,   263,   264,   265,   266,   270,   271,   275,   276,   280,
     281,   285,   286,   287,   291,   292,   293,   297,   298,   299,
     300,   304,   305,   306,   310,   311,   315,   316,   320,   321,
     325,   329,   330,   334,   335,   336,   337,   341,   342,   346,
     350,   354,   355,   359,   360,   364,   365,   369,   370,   374,
     375,   376,   377,   378,   379,   380,   381,   385,   389,   390,
     391,   395,   399,   400,   401,   405,   406,   407,   408,   412,
     413,   414,   418,   419,   423,   427,   428,   432,   433,   434,
     435,   436,   437,   438,   442,   443,   444,   445,   449,   450,
     454,   458,   459,   463,   467,   468,   472,   473,   474,   478,
     479,   483,   484,   485,   486,   487,   491,   492,   496,   497,
     498,   499,   500,   504,   505,   509,   510,   511,   515,   516,
     517,   521,   522,   526,   527,   531,   532,   533,   534,   535,
     536,   540,   541,   545,   546,   547,   551,   552,   556,   560,
     561,   565,   566,   570,   571,   575,   576,   577,   578,   582,
     583,   587,   588,   592,   593,   597,   598,   599,   600,   604,
     605,   609,   613,   614,   615,   616,   620,   621,   622,   626,
     627,   628,   629,   633,   634,   635,   636,   637,   638,   642,
     643,   644,   648,   649,   653,   654,   658,   659,   663,   664,
     668,   669,   673,   674,   678,   679,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   698,   702
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

#define YYPACT_NINF -304

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-304)))

#define YYTABLE_NINF -208

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     762,   -35,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,   163,   167,    70,   171,   197,   164,  -304,  1447,
     943,  -304,  1487,  -304,   118,   -17,   125,   127,  1539,  -304,
    -304,   145,   145,   171,  -304,    69,   146,  -304,  -304,   943,
    1527,  -304,   943,  -304,  -304,   144,   676,   702,    33,   203,
     224,   229,  -304,   595,   171,  -304,    41,  -304,    41,   152,
      52,   144,   235,   144,   943,  -304,   188,   186,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,   189,   419,
    -304,   246,   248,  -304,   191,  -304,  1564,   728,  -304,   118,
     196,  -304,  -304,    88,  -304,  -304,  -304,  -304,   810,  -304,
    -304,   103,   145,   145,  -304,  -304,   198,   191,   595,  -304,
    -304,    59,   144,  -304,   118,  -304,  -304,   360,   595,   192,
     195,    39,  1313,    62,   199,   883,   193,   202,   595,  -304,
    1056,  -304,   204,  -304,  1313,   186,   205,  1354,  1354,  -304,
    -304,  -304,  -304,  1313,  -304,  -304,  -304,  -304,   246,   208,
      47,  -304,   503,  -304,  -304,  -304,  -304,  -304,   212,  -304,
    -304,  -304,  -304,  -304,   215,   209,   211,  -304,  -304,  -304,
     213,   214,  -304,  -304,   201,   218,   187,   221,   416,  -304,
    1354,  1313,  -304,    79,   151,   157,    93,   185,   210,   217,
     184,   240,    28,  -304,  -304,  -304,  -304,   225,  -304,    64,
      36,  -304,   282,   246,    88,  -304,  -304,   144,  -304,   171,
     186,  -304,  -304,   285,  -304,  -304,    41,  -304,    41,   171,
    -304,   118,   144,   595,  -304,   246,    12,  -304,   246,  1313,
    -304,   233,  -304,   208,    91,  -304,  -304,   226,   238,  -304,
    -304,   262,   584,  1313,    23,  -304,   241,  1313,   243,   139,
    1313,  1313,  -304,  -304,    67,    57,   239,   244,   247,   173,
      44,   293,   130,  1313,  -304,  -304,  -304,   302,  1313,  1069,
     836,   963,  -304,  -304,   303,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  1313,  -304,  -304,
    1313,  1313,  1313,  1313,  1313,  1313,  1313,  1313,   595,  1313,
    1313,  1313,  1313,  1313,  1313,  1313,  1313,  1313,  1313,  1313,
    1313,   246,  -304,  -304,   126,  -304,  -304,  -304,  1149,   553,
    -304,   225,    64,   186,  -304,   198,  -304,  -304,  -304,  -304,
     191,   144,   246,   304,   626,  -304,   177,   250,  -304,  -304,
    -304,   249,  -304,  -304,  -304,  1190,   183,   251,  1231,  1313,
      25,  -304,   282,  -304,   252,  -304,   255,   186,   139,  -304,
     186,  -304,   257,   259,   282,   282,  1313,  1313,  1395,  -304,
    -304,  -304,  -304,  -304,   258,  -304,   265,  -304,    24,  -304,
    -304,   862,   976,  -304,  -304,   120,  -304,  -304,  -304,  -304,
    -304,  -304,    79,    79,   151,   151,   151,  -304,   157,   157,
     157,   157,    93,    93,   185,   210,   217,   184,   240,   261,
    -304,  -304,  -304,  -304,    81,   126,  -304,  -304,   304,  -304,
    -304,   883,  1313,  -304,  1272,   267,  1313,  -304,   883,  -304,
     107,   266,  -304,   282,   186,   595,  -304,  -304,  -304,  -304,
     883,  -304,  -304,  -304,  -304,  -304,  -304,  1313,  -304,  -304,
    -304,   121,  1149,  -304,  1313,  -304,  -304,  -304,   270,   883,
     271,   273,  -304,  -304,   327,  -304,  -304,  -304,    31,  -304,
    -304,  -304,  -304,  -304,   283,  -304,   883,   883,   277,  -304,
    -304,  -304,  -304,  -304
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
     192,   147,   132,     0,   241,   242,   243,   244,     0,     4,
     184,   146,     0,   133,   135,   136,   139,   140,     0,   142,
     143,   144,   145,   231,   185,   188,   190,   193,   194,   195,
       0,   186,   187,   213,   216,   215,   239,   232,   245,   238,
       0,     0,   252,   256,   259,   263,   269,   272,   274,   276,
     278,   280,   282,   284,   298,   151,   118,    96,    97,     0,
      99,   229,     3,     0,     0,    43,    85,    87,    88,     0,
       0,   126,    45,     0,    48,    51,    50,    59,    58,     0,
      83,     0,    37,     0,   128,     0,     0,   114,     0,     0,
     148,     0,   168,     0,   184,   245,   299,     0,     0,   170,
     150,     0,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,   235,   236,   249,   184,     0,     0,     0,     0,
      99,     0,     0,     0,   131,   134,   141,     0,     0,     0,
       0,     0,   233,   234,     0,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   286,     0,   240,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   122,     0,   110,   121,   119,     0,     0,
     230,    95,     0,     0,   124,   120,   125,    68,    49,    57,
       7,    39,     0,   116,     0,   127,     0,     0,   167,   149,
     169,     0,   161,   160,   165,     0,     0,     0,     0,     0,
     224,   226,   225,   171,     0,   173,     0,     0,   176,   178,
       0,   175,     0,     0,   250,   251,     0,     0,   189,   137,
     202,   201,   200,   214,     0,   198,     0,   204,     0,   211,
     218,     0,     0,   217,   104,     0,   101,   199,   285,   253,
     254,   255,   257,   258,   260,   261,   262,   268,   267,   266,
     264,   265,   270,   271,   273,   275,   277,   279,   281,     0,
      98,   109,   100,   112,     0,     0,   108,   123,   117,   115,
     138,     0,     0,   163,     0,     0,     0,   159,     0,   222,
       0,     0,   227,   223,     0,     0,   183,   179,   177,   180,
       0,   189,   246,   247,   248,   196,   197,     0,   203,   220,
     102,     0,   106,   219,     0,   111,   107,   174,     0,     0,
       0,   164,   162,   166,   152,   221,   228,   154,     0,   155,
     212,   103,   105,   283,     0,   158,     0,     0,     0,   182,
     156,   157,   153,   181
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -304,   -66,   -28,   154,   -41,    -6,  -304,  -304,  -304,   141,
     123,   346,    26,   -14,   -29,  -304,  -304,  -304,  -304,   -24,
       9,     3,    -4,   -36,   -77,  -304,  -304,  -107,    55,  -303,
     -12,  -304,   165,    65,    37,   -73,  -168,  -280,  -304,   299,
    -304,  -304,   -43,  -304,   234,   147,  -118,  -304,  -304,  -233,
    -304,  -304,  -304,  -304,  -304,   -37,  -304,  -304,  -304,    30,
    -304,    34,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,    45,  -304,   133,  -304,  -304,  -304,    46,  -228,  -304,
    -304,   111,    29,  -304,  -304,  -167,  -304,  -304,   -31,   -79,
     -64,   -39,    94,   116,   102,    92,   115,  -304,  -120,   140,
    -304,    80,  -304
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    81,    82,   106,   233,    45,    17,    18,    19,    20,
      21,    22,    23,   234,    24,    25,    26,    27,   101,    28,
      29,    55,    56,    87,    88,    89,    90,   197,   198,   384,
     385,    91,   199,   226,   227,   260,   210,   315,    92,    93,
      94,    95,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   345,   424,   460,   346,   161,   162,   358,   359,
     360,   361,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   378,   172,   173,   174,   175,   350,   351,   202,   176,
     177,   178,   179,   180,   181,   182,   256,   257,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     287,   195,   237
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    36,   236,    96,    96,    83,    83,   241,   200,   344,
     206,    98,    83,   148,   289,   412,   352,    85,    85,    59,
     203,   206,    86,    86,   116,   105,   364,   365,    58,    61,
      63,   314,    84,    84,   411,    57,   323,    52,   149,    84,
     107,   259,   416,    30,    96,    83,    83,   201,    43,   201,
     211,   225,   228,   112,   478,    96,    99,    83,    85,   109,
     317,   110,   231,    86,    46,   150,    43,    83,   317,    85,
      -5,    -5,    84,    84,    86,   113,    83,    83,    33,    54,
     220,   201,   113,   207,    84,   238,   148,    83,   312,   334,
     309,   201,   249,    34,    84,    52,   321,   335,   216,   218,
     244,   447,   254,    84,    84,   215,   217,   348,   222,   448,
     349,   149,   349,   209,    84,   100,   479,   232,   108,   318,
     319,   336,   433,   389,   390,   391,   262,   318,   310,   255,
     200,  -207,   114,   298,   263,   456,   262,   209,   150,   221,
     239,  -207,   313,    41,   263,    79,   261,    44,    60,   472,
     299,   300,   333,   113,   415,   371,   316,   332,   334,   290,
      39,   324,    41,    42,    38,    41,   455,   326,   356,    79,
     262,   128,   291,   292,   357,  -207,   148,   372,   263,    53,
     213,    64,    83,    54,   447,   214,    31,    41,   301,   302,
      32,   344,   465,   463,    34,   107,    44,   452,   452,   442,
     443,   149,   453,   471,   313,   330,    47,    79,    48,    84,
     246,   295,   296,   297,   248,   331,   394,   395,   396,   328,
      37,   329,    65,   258,    44,    62,   102,    96,   150,    83,
      44,   111,   397,   235,   381,   398,   399,   400,   401,   272,
     273,    85,   293,   294,   303,   304,    86,   103,   252,   253,
     311,   369,   104,   225,   311,   420,    84,    83,   113,   418,
     426,   427,   392,   393,   402,   403,   115,    79,   225,   196,
      62,   316,   201,   117,   208,   219,   229,   242,    83,   316,
     417,   230,   270,   307,    84,   240,   243,   261,   247,   250,
     266,   288,   235,    83,   267,  -205,   268,   269,  -206,   271,
     274,   308,   311,   457,   206,    84,   320,   305,   327,   337,
     464,   338,   339,   341,   436,   306,   340,   439,   370,   353,
      84,   355,   469,   347,   366,   375,   387,   354,   317,   367,
     362,   363,   368,   422,   473,   421,   428,   434,    96,   435,
      83,   475,   440,   374,   441,   462,   445,   454,   376,   379,
     426,   386,    85,   446,   466,   474,   476,    86,   481,   482,
     477,   480,   483,   325,   223,    40,   410,    84,   322,   468,
     451,   419,   316,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    34,   414,   204,   265,   461,   437,   343,
     409,   467,   438,   430,    83,   373,   432,   444,   386,   404,
     407,   235,   235,   235,   235,   235,   235,   235,   235,   406,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,    84,   405,   118,   408,   425,     0,   388,   379,   431,
       0,   119,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,   120,     0,     0,   224,   121,   122,     0,   123,
     124,   125,     0,     0,     0,   126,   127,     0,     0,     0,
     128,   129,   386,   130,   131,   132,   133,   134,     0,   135,
     136,   137,   138,     0,     0,     0,     0,   235,   235,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
       0,     0,     0,   139,   140,     0,     0,   141,     0,   286,
      79,   142,   458,   143,     0,     0,     0,   118,   144,   145,
     146,   147,     0,     0,     0,   119,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,   120,   470,     0,     0,
     121,   122,   386,   123,   124,   125,     0,     0,     0,   126,
     127,     0,     0,     0,   128,   129,     0,   130,   131,   132,
     133,   134,     0,   135,   136,   137,   138,   223,     0,     0,
       0,     0,     0,     0,     0,   235,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    34,   139,   140,     0,
       0,   141,     0,     0,    79,   264,     0,   143,   118,     0,
       0,     0,   144,   145,   146,   147,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    34,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    34,     0,
       0,     0,     0,     0,     0,   128,   129,     0,     0,   131,
     223,   133,     0,     0,     0,     0,   137,   138,   413,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    34,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   140,
       0,     0,   342,     0,     0,     0,     0,     0,   143,     0,
       0,     0,     0,   144,   145,   146,   147,    66,     0,     2,
       3,     4,     5,     6,    67,     8,     9,    10,    11,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,    12,    13,    66,     0,     2,     3,     4,     5,     6,
      67,     8,     9,    10,    11,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,    12,    13,    66,
       0,     2,     3,     4,     5,     6,    67,     8,     9,    10,
      11,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    16,    12,    13,     0,     0,    79,    80,     0,
       0,     0,   -20,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,     0,    16,     0,
       0,     0,     0,    79,    97,     0,     0,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,    16,    15,     0,     0,     0,    79,
     205,    66,     0,     2,     3,     4,     5,     6,    67,     8,
       9,    10,    11,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,    12,    13,    66,    16,     2,
       3,     4,     5,     6,    67,     8,     9,    10,    11,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,    12,    13,    66,     0,     2,     3,     4,     5,     6,
      67,     8,     9,    10,    11,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    16,    12,    13,     0,
       0,    79,   212,     0,     0,   119,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,   120,     0,     0,     0,
     121,   122,    16,   123,   124,   125,     0,    79,   380,   126,
     127,     0,     0,     0,   128,   129,     0,   130,   131,   132,
     133,   134,     0,   135,   136,   137,   138,     0,    16,     0,
       0,     0,     0,    79,   449,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,   139,   140,     0,
       0,   141,     0,     0,    79,     0,     0,   143,    12,    13,
       0,     0,   144,   145,   146,   147,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    34,     0,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    34,
       0,     0,     0,     0,   128,   129,     0,     0,   131,     0,
     133,     0,     0,     0,     0,   137,   138,   128,   129,    16,
       0,   131,     0,   133,     0,     0,     0,     0,   137,   138,
       0,     0,     0,     0,     0,     0,     0,   139,   140,     0,
       0,     0,     0,     0,   382,   383,     0,   143,     0,     0,
     139,   140,   144,   145,   146,   147,     0,   382,   450,     0,
     143,     0,     0,     0,     0,   144,   145,   146,   147,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    34,
       0,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    34,     0,     0,     0,     0,   128,   129,     0,
       0,   131,     0,   133,     0,     0,     0,     0,   137,   138,
     128,   129,     0,     0,   131,     0,   133,     0,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,     0,     0,
     139,   140,     0,     0,   245,     0,     0,     0,     0,     0,
     143,     0,     0,   139,   140,   144,   145,   146,   147,     0,
       0,     0,     0,   143,   377,     0,     0,     0,   144,   145,
     146,   147,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,     0,     0,   131,     0,   133,     0,     0,     0,
       0,   137,   138,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   139,   140,     0,     0,     0,     0,     0,
     382,   128,   129,   143,     0,   131,     0,   133,   144,   145,
     146,   147,   137,   138,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   139,   140,     0,     0,   423,     0,
       0,     0,   128,   129,   143,     0,   131,     0,   133,   144,
     145,   146,   147,   137,   138,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,   140,     0,     0,     0,
       0,     0,     0,   128,   129,   143,   429,   131,     0,   133,
     144,   145,   146,   147,   137,   138,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,   140,     0,     0,
       0,     0,     0,     0,   128,   129,   143,   459,   131,     0,
     133,   144,   145,   146,   147,   137,   138,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   140,     0,
       0,     0,     0,     0,     0,   128,   129,   143,     0,   131,
       0,   133,   144,   145,   146,   147,   137,   138,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   140,
       0,     0,     0,     0,     0,     0,   128,   129,   251,     0,
     131,     0,   133,   144,   145,   146,   147,   -26,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
     140,     0,    12,    13,     0,     0,     0,     0,     0,   251,
       0,     0,     0,     0,   144,   145,    14,   -27,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    14,   -23,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    49,    50,    14,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51
};

static const yytype_int16 yycheck[] =
{
      14,    15,   122,    46,    47,    46,    47,   125,    81,   242,
      87,    47,    53,    79,   181,   318,   244,    46,    47,    33,
      86,    98,    46,    47,    67,    53,   254,   255,    32,    35,
      36,   199,    46,    47,   314,    32,   204,    28,    79,    53,
      54,   148,   322,    78,    87,    86,    87,    24,    22,    24,
      93,   117,   118,    59,    23,    98,    23,    98,    87,    56,
      24,    58,    23,    87,    81,    79,    40,   108,    24,    98,
      23,    24,    86,    87,    98,    23,   117,   118,     8,    38,
     108,    24,    23,    89,    98,    23,   152,   128,    24,    77,
      62,    24,   135,    23,   108,    86,   203,    85,   102,   103,
     128,    77,   143,   117,   118,   102,   103,    84,   114,    85,
      87,   152,    87,    49,   128,    82,    85,    78,    77,    83,
      84,   228,   350,   290,   291,   292,    79,    83,   100,   143,
     203,    84,    80,    40,    87,   415,    79,    49,   152,    80,
      78,    84,    78,    20,    87,    81,    79,    78,    79,   452,
      57,    58,   225,    23,   322,    25,   199,   223,    77,    80,
      19,   204,    39,    22,     0,    42,    85,   210,    29,    81,
      79,    41,    93,    94,    35,    84,   242,    47,    87,    34,
      77,    40,   223,    38,    77,    82,    23,    64,    95,    96,
      23,   424,    85,   426,    23,   209,    78,    77,    77,   366,
     367,   242,    82,    82,    78,   219,    81,    81,    81,   223,
     130,    54,    55,    56,   134,   221,   295,   296,   297,   216,
      23,   218,    78,   143,    78,    79,    23,   270,   242,   270,
      78,    79,   298,   122,   270,   299,   300,   301,   302,    52,
      53,   270,    91,    92,    59,    60,   270,    23,   137,   138,
      77,    78,    23,   319,    77,    78,   270,   298,    23,   332,
      77,    78,   293,   294,   303,   304,    78,    81,   334,    23,
      79,   314,    24,    84,    78,    77,    84,    84,   319,   322,
     323,    86,    81,    99,   298,    86,    84,    79,    84,    84,
      78,   180,   181,   334,    79,    84,    87,    84,    84,    81,
      79,    61,    77,   421,   381,   319,    24,    97,    23,   229,
     428,    78,    86,    51,   357,    98,    78,   360,    25,    78,
     334,    78,   440,   243,    85,    23,    23,   247,    24,    85,
     250,   251,    85,    84,   454,    85,    85,    85,   381,    84,
     381,   459,    85,   263,    85,    78,    88,    86,   268,   269,
      77,   271,   381,    88,    88,    85,    85,   381,   476,   477,
      33,    78,    85,   209,     4,    19,   311,   381,   203,   435,
     382,   334,   415,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   319,    86,   152,   424,   358,   242,
     310,   434,   358,   348,   435,   262,   350,   368,   318,   305,
     308,   290,   291,   292,   293,   294,   295,   296,   297,   307,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   435,   306,     4,   309,   345,    -1,   287,   348,   349,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    85,    27,    28,    -1,    30,
      31,    32,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,
      41,    42,   382,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,   366,   367,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    74,    75,    -1,    -1,    78,    -1,    83,
      81,    82,   422,    84,    -1,    -1,    -1,     4,    89,    90,
      91,    92,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   447,    -1,    -1,
      27,    28,   452,    30,    31,    32,    -1,    -1,    -1,    36,
      37,    -1,    -1,    -1,    41,    42,    -1,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   454,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    74,    75,    -1,
      -1,    78,    -1,    -1,    81,    82,    -1,    84,     4,    -1,
      -1,    -1,    89,    90,    91,    92,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    45,
       4,    47,    -1,    -1,    -1,    -1,    52,    53,    85,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    76,    25,    26,    -1,    -1,    81,    82,    -1,
      -1,    -1,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    76,    43,    -1,    -1,    -1,    81,
      82,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,     1,    76,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    76,    25,    26,    -1,
      -1,    81,    82,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      27,    28,    76,    30,    31,    32,    -1,    81,    82,    36,
      37,    -1,    -1,    -1,    41,    42,    -1,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    74,    75,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    25,    26,
      -1,    -1,    89,    90,    91,    92,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    45,    -1,
      47,    -1,    -1,    -1,    -1,    52,    53,    41,    42,    76,
      -1,    45,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,    -1,
      74,    75,    89,    90,    91,    92,    -1,    81,    82,    -1,
      84,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    41,    42,    -1,
      -1,    45,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,
      41,    42,    -1,    -1,    45,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    74,    75,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    89,    90,
      91,    92,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    -1,    -1,    45,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    41,    42,    84,    -1,    45,    -1,    47,    89,    90,
      91,    92,    52,    53,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    78,    -1,
      -1,    -1,    41,    42,    84,    -1,    45,    -1,    47,    89,
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
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    25,    26,    39,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
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
      86,   147,    84,    84,   103,    78,   202,    84,   202,   143,
      84,    84,   182,   182,   105,   114,   187,   188,   202,   128,
     136,    79,    79,    87,    82,   145,    78,    79,    87,    84,
      81,    81,    52,    53,    79,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    83,   201,   182,   186,
      80,    93,    94,    91,    92,    54,    55,    56,    40,    57,
      58,    95,    96,    59,    60,    97,    98,    99,    61,    62,
     100,    77,    24,    78,   137,   138,   143,    24,    83,    84,
      24,   128,   133,   137,   143,   104,   143,    23,   122,   122,
     114,   106,   102,   136,    77,    85,   128,   202,    78,    86,
      78,    51,    78,   146,   150,   153,   156,   202,    84,    87,
     177,   178,   179,    78,   202,    78,    29,    35,   159,   160,
     161,   162,   202,   202,   179,   179,    85,    85,    85,    78,
      25,    25,    47,   174,   202,    23,   202,    85,   172,   202,
      82,   124,    81,    82,   130,   131,   202,    23,   200,   186,
     186,   186,   189,   189,   190,   190,   190,   102,   191,   191,
     191,   191,   192,   192,   193,   194,   195,   196,   197,   202,
     129,   138,   130,    85,   134,   137,   138,   143,   136,   135,
      78,    85,    84,    78,   154,   202,    77,    78,    85,    85,
     172,   202,   178,   179,    85,    84,   143,   160,   162,   143,
      85,    85,   186,   186,   183,    88,    88,    77,    85,    82,
      82,   131,    77,    82,    86,    85,   138,   147,   202,    85,
     155,   156,    78,   150,   147,    85,    88,   143,   102,   147,
     202,    82,   130,   199,    85,   147,    85,    33,    23,    85,
      78,   147,   147,    85
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
     174,   175,   175,   176,   176,   176,   177,   177,   178,   179,
     179,   180,   180,   181,   181,   182,   182,   182,   182,   183,
     183,   184,   184,   185,   185,   186,   186,   186,   186,   187,
     187,   188,   189,   189,   189,   189,   190,   190,   190,   191,
     191,   191,   191,   192,   192,   192,   192,   192,   192,   193,
     193,   193,   194,   194,   195,   195,   196,   196,   197,   197,
     198,   198,   199,   199,   200,   200,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   202,   203
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
       4,     5,     4,     4,     3,     3,     1,     2,     3,     1,
       2,     1,     1,     2,     2,     2,     2,     2,     1,     1,
       2,     1,     1,     1,     1,     1,     4,     4,     4,     1,
       2,     2,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  YYUSE (yytype);
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
        case 20:
#line 135 "parser.y" /* yacc.c:1646  */
    {throw QString("Empty file");}
#line 2076 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2080 "parser.cpp" /* yacc.c:1646  */
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
#line 704 "parser.y" /* yacc.c:1906  */
