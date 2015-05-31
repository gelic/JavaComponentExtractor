%option noyywrap never-interactive outfile="lexer.cpp" header-file="lexer.hpp" yylineno

%top{
    #pragma warning(disable: 4996)
}

%{
    #include "unistd.h"
    #include "parser.hpp"

    int yycolumn = 1;
    char *filename;

    // Для дополнительного вывода в ошибках номера колонки и файла
    #define YY_USER_ACTION \
        yylloc.filename = filename; \
        yylloc.first_line = yylloc.last_line = yylineno; \
        yylloc.first_column = yycolumn; \
        yylloc.last_column = yycolumn + yyleng - 1; \
        yycolumn += yyleng;

    void yyerror(const char *msg)
    {
        printf("%s:%d.%d: %s\n", yylloc.filename, yylloc.first_line, yylloc.first_column, msg);
    }
%}

%e 1600
%n 800
%p 5000

/***************************************************************/

Separator       [\(\)\{\}\[\]\;\,\.]
Delimiter1      [\=\>\<\!\~\?\:\+\-\*\/\&\|\^\%]
HexDigit        [0-9a-fA-F]
Digit           [0-9]
OctalDigit      [0-7]
TetraDigit      [0-3]
NonZeroDigit    [1-9]
Letter          [a-zA-Z_$]
AnyButSlash     [^\/]
AnyButAstr      [^\*]
BLANK           [ ]
BLK             [\b]
TAB             [\t]
FF              [\f]
ESCCHR          [\\]
CR              [\r]
LF              [\n]
UniEsc          [\1b]

OctEscape1      [\\]{OctalDigit}
OctEscape2      [\\]{OctalDigit}{OctalDigit}
OctEscape3      [\\]{TetraDigit}{OctalDigit}{OctalDigit}
OctEscape       ({OctEscape1}|{OctEscape2}|{OctEscape3})

Escape          [\\]([r]|[n]|[b]|[f]|[t]|[\\]|[\']|[\"])
ULetter         ({Letter}|{UniEsc})
Identifier      {ULetter}({ULetter}|{Digit})*

Comment1        [\/][\*]({AnyButAstr}|[\*]{AnyButSlash})*[\*][\/]
Comment2        [\/][\/].*
Comment         ({Comment1}|{Comment2})
Dimension       [\[]({CR}|{LF}|{FF}|{TAB}|{BLK}|{BLANK}|{Comment1}|{Comment2}[\n\r])*[\]]

IntSuffix       ([l]|[L])
DecimalNum      {NonZeroDigit}{Digit}*{IntSuffix}?
OctalNum        [0]{OctalDigit}*{IntSuffix}?
HexNum          [0]([x]|[X]){HexDigit}{HexDigit}*{IntSuffix}?
IntegerLiteral  ({DecimalNum}|{OctalNum}|{HexNum})

Sign            ([\+]|[\-])
FlSuffix        ([f]|[F]|[d]|[D])
SignedInt       {Sign}?{Digit}+
Expo            ([e]|[E])
ExponentPart    {Expo}{SignedInt}?
Float1          {Digit}+[\.]{Digit}+?{ExponentPart}?{FlSuffix}?
Float2          [\.]{Digit}+{ExponentPart}?{FlSuffix}?
Float3          {Digit}+{ExponentPart}{FlSuffix}?
Float4          {Digit}+{FlSuffix}
FloatingPoint   ({Float1}|{Float2}|{Float3}|{Float4})

AnyChrChr       [^\\']
AnyStrChr       [^\\"]
Character       [\']({Escape}|{OctEscape}|{AnyChrChr})[\']
String          [\"]({Escape}|{OctEscape}|{AnyStrChr})*[\"]
Numeric         ({IntegerLiteral}|{FloatingPoint})
Literal         ({Numeric}|{Character}|{String})

%%
"true"          {return BOOLLIT;}
"false"         {return BOOLLIT;}

{Separator}     {return yytext[0];}
{Delimiter1}    {return yytext[0];}
{Dimension}     {yylval.str = new QString(yytext); return OP_DIM;}

"=="            {return OP_EQ;}
"<="            {return OP_LE;}
">="            {return OP_GE;}
"!="            {return OP_NE;}
"||"            {return OP_LOR;}
"&&"            {return OP_LAND;}
"++"            {return OP_INC;}
"--"            {return OP_DEC;}
">>"            {return OP_SHR;}
"<<"            {return OP_SHL;}
">>>"           {return OP_SHRR;}
"+="            {return ASS_ADD;}
"-="            {return ASS_SUB;}
"*="            {return ASS_MUL;}
"/="            {return ASS_DIV;}
"&="            {return ASS_AND;}
"|="            {return ASS_OR;}
"^="            {return ASS_XOR;}
"%="            {return ASS_MOD;}
"<<="           {return ASS_SHL;}
">>="           {return ASS_SHR;}
">>>="          {return ASS_SHRR;}

"abstract"      {yylval.str = new QString(yytext); return ABSTRACT;}
"public"        {yylval.str = new QString(yytext); return PUBLIC;}
"private"       {yylval.str = new QString(yytext); return PRIVATE;}
"protected"     {yylval.str = new QString(yytext); return PROTECTED;}
"transient"     {yylval.str = new QString(yytext); return TRANSIENT;}
"final"         {yylval.str = new QString(yytext); return FINAL;}
"volatile"      {yylval.str = new QString(yytext); return VOLATILE;}
"native"        {yylval.str = new QString(yytext); return NATIVE;}
"static"        {yylval.str = new QString(yytext); return STATIC;}
"synchronized"  {yylval.str = new QString(yytext); return SYNCHRONIZED;}

"boolean"       {yylval.str = new QString(yytext); return YYBOOLEAN;}
"double"        {yylval.str = new QString(yytext); return YYDOUBLE;}
"byte"          {yylval.str = new QString(yytext); return YYBYTE;}
"int"           {yylval.str = new QString(yytext); return YYINT;}
"void"          {yylval.str = new QString(yytext); return YYVOID;}
"float"         {yylval.str = new QString(yytext); return YYFLOAT;}
"long"          {yylval.str = new QString(yytext); return YYLONG;}
"short"         {yylval.str = new QString(yytext); return YYSHORT;}
"char"          {yylval.str = new QString(yytext); return YYCHAR;}
"String"        {yylval.str = new QString(yytext); return YYSTRING;}

"enum"          {return ENUM;}
"implements"    {return IMPLEMENTS;}
"package"       {return PACKAGE;}
"import"        {return IMPORT;}
"extends"       {return EXTENDS;}
"interface"     {return INTERFACE;}
"class"         {return CLASS;}

"do"            {return DO;}
"throw"         {return THROW;}
"throws"        {return THROWS;}
"break"         {return BREAK;}
"else"          {return ELSE;}
"instanceof"    {return INSTANCEOF;}
"try"           {return TRY;}
"case"          {return CASE;}
"finally"       {return FINALLY;}
"return"        {return RETURN;}
"catch"         {return CATCH;}
"for"           {return FOR;}
"while"         {return WHILE;}
"new"           {return NEW;}
"super"         {return SUPER;}
"null"          {return JNULL;}
"switch"        {return SWITCH;}
"continue"      {return CONTINUE;}
"default"       {return DEFAULT;}
"if"            {return IF;}
"this"          {return THIS;}

{Identifier}    {yylval.str = new QString(yytext); return IDENTIFIER;}

{DecimalNum}    {return LITERAL;}
{OctalNum}      {return LITERAL;}
{HexNum}        {return LITERAL;}

{Float1}        {return LITERAL;}
{Float2}        {return LITERAL;}
{Float3}        {return LITERAL;}
{Float4}        {return LITERAL;}

{Character}     {return LITERAL;}
{String}        {return LITERAL;}

{CR}            {}
{LF}            {yycolumn = 1;}
{FF}            {}
{TAB}           {}
{BLK}           {}
{BLANK}         {}

{Comment}       {}
%%
