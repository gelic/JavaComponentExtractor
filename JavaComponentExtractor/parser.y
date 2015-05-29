%defines
%locations
%error-verbose

%code requires
{
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
}

%{
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
%}

%union
{
    QString *str = nullptr;
    QStringList *strList;
    Method::Param *param;
    QList<Method::Param> *params;
    MethodNameAndParams *methodNameAndParams;
}

%token<str> ABSTRACT FINAL PUBLIC PROTECTED PRIVATE STATIC TRANSIENT VOLATILE NATIVE SYNCHRONIZED
%token<str> YYBOOLEAN YYBYTE YYCHAR YYDOUBLE YYFLOAT YYINT YYLONG YYSHORT YYVOID YYSTRING
%token<str> IDENTIFIER
%token<str> OP_DIM

%token CLASS INTERFACE
%token BREAK
%token CASE CATCH CONTINUE
%token DEFAULT DO
%token ELSE EXTENDS
%token FINALLY FOR
%token IF IMPLEMENTS IMPORT INSTANCEOF
%token NEW JNULL
%token PACKAGE
%token RETURN
%token SUPER SWITCH
%token THIS THROW THROWS TRY
%token WHILE
%token OP_INC OP_DEC
%token OP_SHL OP_SHR OP_SHRR
%token OP_GE OP_LE OP_EQ OP_NE
%token OP_LAND OP_LOR
%token ASS_MUL ASS_DIV ASS_MOD ASS_ADD ASS_SUB
%token ASS_SHL ASS_SHR ASS_SHRR ASS_AND ASS_XOR ASS_OR
%token LITERAL BOOLLIT
%token ENUM

%type<str> QualifiedName Modifier PrimitiveType TypeName TypeSpecifier Dims DeclaratorName VariableDeclarator VariableDeclarators
%type<strList> Modifiers ClassNameList Interfaces Extends Throws
%type<param> Parameter
%type<params> ParameterList
%type<methodNameAndParams> MethodDeclarator ConstructorDeclarator

%destructor {delete $$;} <*>

%start CompilationUnit

%%
TypeSpecifier
    : TypeName  {$$ = $1;}
    | TypeName Dims
        {
            *$$ += *$2;
            delete $2;
            $2 = nullptr;
        }
    ;

TypeName
    : PrimitiveType
    | QualifiedName
    ;

ClassNameList
    : QualifiedName
        {
            $$ = new QStringList(*$1);
            delete $1;
            $1 = nullptr;
        }
    | ClassNameList ',' QualifiedName
        {
            *$$ << *$3;
            delete $3;
            $3 = nullptr;
        }
    ;

PrimitiveType
    : YYBOOLEAN
    | YYCHAR
    | YYBYTE
    | YYSHORT
    | YYINT
    | YYLONG
    | YYFLOAT
    | YYDOUBLE
    | YYVOID
    | YYSTRING
    ;

SemiColons
    : ';'
    | SemiColons ';'
    ;

CompilationUnit
    : {throw QString("Empty file");}
    | ProgramFile
    ;

ProgramFile
    : PackageStatement ImportStatements TypeDeclarations
    | PackageStatement ImportStatements
    | PackageStatement                  TypeDeclarations
    |                  ImportStatements TypeDeclarations
    | PackageStatement
    |                  ImportStatements
    |                                   TypeDeclarations
    ;

PackageStatement
    : PACKAGE QualifiedName SemiColons
        {
            package = Package(*$2);
            COPY_POSITIONS(package.location, @1, @3)
            delete $2;
            $2 = nullptr;
        }
    ;

TypeDeclarations
    : TypeDeclarationOptSemi
    | TypeDeclarations TypeDeclarationOptSemi
    ;

TypeDeclarationOptSemi
    : TypeDeclaration
    | TypeDeclaration SemiColons
    ;

ImportStatements
    : ImportStatement
    | ImportStatements ImportStatement
    ;

ImportStatement
    : IMPORT QualifiedName SemiColons
        {
            imports << Import(*$2, false);
            COPY_POSITIONS(imports.last().location, @1, @3)
            delete $2;
            $2 = nullptr;
        }
    | IMPORT QualifiedName '.' '*' SemiColons
        {
            imports << Import(*$2 + ".*", false);
            COPY_POSITIONS(imports.last().location, @1, @5)
            delete $2;
            $2 = nullptr;
        }
    | IMPORT STATIC QualifiedName SemiColons
        {
            imports << Import(*$3, true);
            COPY_POSITIONS(imports.last().location, @1, @4)
            delete $2;
            delete $3;
            $2 = nullptr;
            $3 = nullptr;
        }
    | IMPORT STATIC QualifiedName '.' '*' SemiColons
        {
            imports << Import(*$3 + ".*", true);
            COPY_POSITIONS(imports.last().location, @1, @6)
            delete $2;
            delete $3;
            $2 = nullptr;
            $3 = nullptr;
        }
    | error ';'
    ;

QualifiedName
    : IDENTIFIER    {$$ = $1;}
    | QualifiedName '.' IDENTIFIER
        {
            *$$ += "." + *$3;
            delete $3;
            $3 = nullptr;
        }
    ;

TypeDeclaration
    : ClassHeader '{' FieldDeclarations '}'
        {addEndPositionsToClassComponent(@4);}
    | ClassHeader '{' '}'
        {addEndPositionsToClassComponent(@3);}
    | InterfaceHeader '{' FieldDeclarations '}'
        {addEndPositionsToInterfaceComponent(@4);}
    | InterfaceHeader '{' '}'
        {addEndPositionsToInterfaceComponent(@3);}
    | EnumHeader '{' '}'
        {COPY_END_POSITIONS(enums.last().location, @3)}
    | EnumHeader '{' EnumList '}'
        {COPY_END_POSITIONS(enums.last().location, @4)}
    ;

ClassHeader
    : Modifiers CLASS IDENTIFIER Extends Interfaces
        {
            classes << Class(*$1, *$3, *$4, *$5);
            COPY_START_POSITIONS(classes.last().location, @1)
            delete $1;
            delete $3;
            delete $4;
            delete $5;
            $1 = nullptr;
            $3 = nullptr;
            $4 = nullptr;
            $5 = nullptr;
        }
    | Modifiers CLASS IDENTIFIER Extends
        {
            classes << Class(*$1, *$3, *$4, QStringList());
            COPY_START_POSITIONS(classes.last().location, @1)
            delete $1;
            delete $3;
            delete $4;
            $1 = nullptr;
            $3 = nullptr;
            $4 = nullptr;
        }
    | Modifiers CLASS IDENTIFIER         Interfaces
        {
            classes << Class(*$1, *$3, QStringList(), *$4);
            COPY_START_POSITIONS(classes.last().location, @1)
            delete $1;
            delete $3;
            delete $4;
            $1 = nullptr;
            $3 = nullptr;
            $4 = nullptr;
        }
    |           CLASS IDENTIFIER Extends Interfaces
        {
            classes << Class(QStringList(), *$2, *$3, *$4);
            COPY_START_POSITIONS(classes.last().location, @1)
            delete $2;
            delete $3;
            delete $4;
            $2 = nullptr;
            $3 = nullptr;
            $4 = nullptr;
        }
    | Modifiers CLASS IDENTIFIER
        {
            classes << Class(*$1, *$3, QStringList(), QStringList());
            COPY_START_POSITIONS(classes.last().location, @1)
            delete $1;
            delete $3;
            $1 = nullptr;
            $3 = nullptr;
        }
    |           CLASS IDENTIFIER Extends
        {
            classes << Class(QStringList(), *$2, *$3, QStringList());
            COPY_START_POSITIONS(classes.last().location, @1)
            delete $2;
            delete $3;
            $2 = nullptr;
            $3 = nullptr;
        }
    |           CLASS IDENTIFIER         Interfaces
        {
            classes << Class(QStringList(), *$2, QStringList(), *$3);
            COPY_START_POSITIONS(classes.last().location, @1)
            delete $2;
            delete $3;
            $2 = nullptr;
            $3 = nullptr;
        }
    |           CLASS IDENTIFIER
        {
            classes << Class(QStringList(), *$2, QStringList(), QStringList());
            COPY_START_POSITIONS(classes.last().location, @1)
            delete $2;
            $2 = nullptr;
        }
    ;

InterfaceHeader
    : Modifiers INTERFACE IDENTIFIER Extends Interfaces
        {
            if (!$5->isEmpty())
            {
                ++yynerrs;
                printf("%s:%d.%d: %s\n", @5.filename, @5.first_line, @5.first_column, "syntax error");
            }
            interfaces << Interface(*$1, *$3, *$4);
            COPY_START_POSITIONS(interfaces.last().location, @1)
            delete $1;
            delete $3;
            delete $4;
            delete $5;
            $1 = nullptr;
            $3 = nullptr;
            $4 = nullptr;
            $5 = nullptr;
        }
    | Modifiers INTERFACE IDENTIFIER Extends
        {
            interfaces << Interface(*$1, *$3, *$4);
            COPY_START_POSITIONS(interfaces.last().location, @1)
            delete $1;
            delete $3;
            delete $4;
            $1 = nullptr;
            $3 = nullptr;
            $4 = nullptr;
        }
    | Modifiers INTERFACE IDENTIFIER         Interfaces
        {
            if (!$4->isEmpty())
            {
                ++yynerrs;
                printf("%s:%d.%d: %s\n", @4.filename, @4.first_line, @4.first_column, "syntax error");
            }
            interfaces << Interface(*$1, *$3, QStringList());
            COPY_START_POSITIONS(interfaces.last().location, @1)
            delete $1;
            delete $3;
            delete $4;
            $1 = nullptr;
            $3 = nullptr;
            $4 = nullptr;
        }
    |           INTERFACE IDENTIFIER Extends Interfaces
        {
            if (!$4->isEmpty())
            {
                ++yynerrs;
                printf("%s:%d.%d: %s\n", @4.filename, @4.first_line, @4.first_column, "syntax error");
            }
            interfaces << Interface(QStringList(), *$2, *$3);
            COPY_START_POSITIONS(interfaces.last().location, @1)
            delete $2;
            delete $3;
            delete $4;
            $2 = nullptr;
            $3 = nullptr;
            $4 = nullptr;
        }
    | Modifiers INTERFACE IDENTIFIER
        {
            interfaces << Interface(*$1, *$3, QStringList());
            COPY_START_POSITIONS(interfaces.last().location, @1)
            delete $1;
            delete $3;
            $1 = nullptr;
            $3 = nullptr;
        }
    |           INTERFACE IDENTIFIER Extends
        {
            interfaces << Interface(QStringList(), *$2, *$3);
            COPY_START_POSITIONS(interfaces.last().location, @1)
            delete $2;
            delete $3;
            $2 = nullptr;
            $3 = nullptr;
        }
    |           INTERFACE IDENTIFIER         Interfaces
        {
            if (!$3->isEmpty())
            {
                ++yynerrs;
                printf("%s:%d.%d: %s\n", @3.filename, @3.first_line, @3.first_column, "syntax error");
            }
            interfaces << Interface(QStringList(), *$2, QStringList());
            COPY_START_POSITIONS(interfaces.last().location, @1)
            delete $2;
            delete $3;
            $2 = nullptr;
            $3 = nullptr;
        }
    |           INTERFACE IDENTIFIER
        {
            interfaces << Interface(QStringList(), *$2, QStringList());
            COPY_START_POSITIONS(interfaces.last().location, @1)
            delete $2;
            $2 = nullptr;
        }
    ;

EnumHeader
    : Modifiers ENUM IDENTIFIER
        {
            enums << Enum(*$1, *$3);
            COPY_START_POSITIONS(enums.last().location, @1)
            delete $1;
            delete $3;
            $1 = nullptr;
            $3 = nullptr;
        }
    | ENUM IDENTIFIER
        {
            enums << Enum(QStringList(), *$2);
            COPY_START_POSITIONS(enums.last().location, @1)
            delete $2;
            $2 = nullptr;
        }
    ;

EnumList
    : IDENTIFIER
        {
            enums.last().enumList << *$1;
            delete $1;
            $1 = nullptr;
        }
    | EnumList ',' IDENTIFIER
        {
            enums.last().enumList << *$3;
            delete $3;
            $3 = nullptr;
        }
    ;

Modifiers
    : Modifier
        {
            $$ = new QStringList(*$1);
            delete $1;
            $1 = nullptr;
        }
    | Modifiers Modifier
        {
            *$$ << *$2;
            delete $2;
            $2 = nullptr;
        }
    ;

Modifier
    : ABSTRACT
    | FINAL
    | PUBLIC
    | PROTECTED
    | PRIVATE
    | STATIC
    | TRANSIENT
    | VOLATILE
    | NATIVE
    | SYNCHRONIZED
    ;

Interfaces
    : IMPLEMENTS ClassNameList  {$$ = $2;}
    ;

Extends
    : EXTENDS TypeName
        {
            $$ = new QStringList(*$2);
            delete $2;
            $2 = nullptr;
        }
    | Extends ',' TypeName
        {
            *$$ << *$3;
            delete $3;
            $3 = nullptr;
        }
    ;

FieldDeclarations
    : FieldDeclarationOptSemi
    | FieldDeclarations FieldDeclarationOptSemi
    ;

FieldDeclarationOptSemi
    : FieldDeclaration
    | FieldDeclaration SemiColons
    ;

FieldDeclaration
    : FieldVariableDeclaration ';'  {COPY_END_POSITIONS(fields.last().location, @2);}
    | MethodDeclaration
    | ConstructorDeclaration
    | StaticInitializer
    | NonStaticInitializer
    | TypeDeclaration
    | error ';'
    ;

FieldVariableDeclaration
    : Modifiers TypeSpecifier VariableDeclarators
        {
            fields << Field(*$1, *$2, *$3);
            COPY_START_POSITIONS(fields.last().location, @1);
            delete $1;
            delete $2;
            delete $3;
            $1 = nullptr;
            $2 = nullptr;
            $3 = nullptr;

        }
    |           TypeSpecifier VariableDeclarators
        {
            fields << Field(QStringList(), *$1, *$2);
            COPY_START_POSITIONS(fields.last().location, @1);
            delete $1;
            delete $2;
            $1 = nullptr;
            $2 = nullptr;
        }
    ;

VariableDeclarators
    : VariableDeclarator                            {$$ = $1;}
    | VariableDeclarators ',' VariableDeclarator    {$$ = $3;}
    ;

VariableDeclarator
    : DeclaratorName                            {$$ = $1;}
    | DeclaratorName '=' VariableInitializer    {$$ = $1;}
    ;

VariableInitializer
    : Expression
    | '{' '}'
    | '{' ArrayInitializers '}'
    ;

ArrayInitializers
    : VariableInitializer
    | ArrayInitializers ',' VariableInitializer
    | ArrayInitializers ','
    ;

MethodDeclaration
    : Modifiers TypeSpecifier MethodDeclarator Throws MethodBody
        {
            methods << Method(*$1, *$2, $3->name, $3->params, *$4);
            COPY_POSITIONS(methods.last().location, @1, @5)
            delete $1;
            delete $2;
            delete $3;
            delete $4;
            $1 = nullptr;
            $2 = nullptr;
            $3 = nullptr;
            $4 = nullptr;
        }
    | Modifiers TypeSpecifier MethodDeclarator        MethodBody
        {
            methods << Method(*$1, *$2, $3->name, $3->params, QStringList());
            COPY_POSITIONS(methods.last().location, @1, @4)
            delete $1;
            delete $2;
            delete $3;
            $1 = nullptr;
            $2 = nullptr;
            $3 = nullptr;
        }
    |           TypeSpecifier MethodDeclarator Throws MethodBody
        {
            methods << Method(QStringList(), *$1, $2->name, $2->params, *$3);
            COPY_POSITIONS(methods.last().location, @1, @4)
            delete $1;
            delete $2;
            delete $3;
            $1 = nullptr;
            $2 = nullptr;
            $3 = nullptr;
        }
    |           TypeSpecifier MethodDeclarator        MethodBody
        {
            methods << Method(QStringList(), *$1, $2->name, $2->params, QStringList());
            COPY_POSITIONS(methods.last().location, @1, @3)
            delete $1;
            delete $2;
            $1 = nullptr;
            $2 = nullptr;
        }
    ;

MethodDeclarator
    : DeclaratorName '(' ParameterList ')'
        {
            $$ = new MethodNameAndParams();
            $$->name = *$1;
            $$->params = *$3;
            delete $1;
            delete $3;
            $1 = nullptr;
            $3 = nullptr;
        }
    | DeclaratorName '(' ')'
        {
            $$ = new MethodNameAndParams();
            $$->name = *$1;
            $$->params = QList<Method::Param>();
            delete $1;
            $1 = nullptr;
        }
    | MethodDeclarator OP_DIM
        {
            delete $2;
            $2 = nullptr;
        }
    ;

ParameterList
    : Parameter
        {
            $$ = new QList<Method::Param>;
            $$->append(*$1);
            delete $1;
            $1 = nullptr;
        }
    | ParameterList ',' Parameter
        {
            $$->append(*$3);
            delete $3;
            $3 = nullptr;
        }
    ;

Parameter
    : TypeSpecifier DeclaratorName
        {
            $$ = new Method::Param(false, *$1, *$2);
            delete $1;
            delete $2;
            $1 = nullptr;
            $2 = nullptr;
        }
    | FINAL TypeSpecifier DeclaratorName
        {
            $$ = new Method::Param(true, *$2, *$3);
            delete $2;
            delete $3;
            $2 = nullptr;
            $3 = nullptr;
        }
    ;

DeclaratorName
    : IDENTIFIER                {$$ = $1;}
    | DeclaratorName OP_DIM
        {
            *$$ += *$2;
            delete $2;
            $2 = nullptr;
        }
    ;

Throws
    : THROWS ClassNameList  {$$ = $2;}
    ;

MethodBody
    : Block
    | ';'
    ;

ConstructorDeclaration
    : Modifiers ConstructorDeclarator Throws Block
        {
            methods << Method(*$1, QString(), $2->name, $2->params, *$3);
            COPY_POSITIONS(methods.last().location, @1, @4)
            delete $1;
            delete $2;
            delete $3;
            $1 = nullptr;
            $2 = nullptr;
            $3 = nullptr;
        }
    | Modifiers ConstructorDeclarator        Block
        {
            methods << Method(*$1, QString(), $2->name, $2->params, QStringList());
            COPY_POSITIONS(methods.last().location, @1, @3)
            delete $1;
            delete $2;
            $1 = nullptr;
            $2 = nullptr;
        }
    |           ConstructorDeclarator Throws Block
        {
            methods << Method(QStringList(), QString(), $1->name, $1->params, *$2);
            COPY_POSITIONS(methods.last().location, @1, @3)
            delete $1;
            delete $2;
            $1 = nullptr;
            $2 = nullptr;
        }
    |           ConstructorDeclarator        Block
        {
            methods << Method(QStringList(), QString(), $1->name, $1->params, QStringList());
            COPY_POSITIONS(methods.last().location, @1, @2)
            delete $1;
            $1 = nullptr;
        }
    ;

ConstructorDeclarator
    : IDENTIFIER '(' ParameterList ')'
        {
            $$ = new MethodNameAndParams();
            $$->name = *$1;
            $$->params = *$3;
            delete $1;
            delete $3;
            $1 = nullptr;
            $3 = nullptr;
        }
    | IDENTIFIER '(' ')'
        {
            $$ = new MethodNameAndParams();
            $$->name = *$1;
            $$->params = QList<Method::Param>();
            delete $1;
            $1 = nullptr;
        }
    ;

StaticInitializer
    : STATIC Block
    ;

NonStaticInitializer
    : Block
    ;

Block
    : '{' LocalVariableDeclarationsAndStatements '}'
    | '{' '}'
    ;

LocalVariableDeclarationsAndStatements
    : LocalVariableDeclarationOrStatement
    | LocalVariableDeclarationsAndStatements LocalVariableDeclarationOrStatement
    ;

LocalVariableDeclarationOrStatement
    : LocalVariableDeclarationStatement
    | Statement
    ;

LocalVariableDeclarationStatement
    : TypeSpecifier VariableDeclarators ';'
        {
            delete $1;
            $1 = nullptr;
        }
    | FINAL TypeSpecifier VariableDeclarators ';'
        {
            delete $2;
            $2 = nullptr;
        }
    ;

Statement
    : EmptyStatement
    | LabelStatement
    | ExpressionStatement ';'
    | SelectionStatement
    | IterationStatement
    | JumpStatement
    | GuardingStatement
    | Block
    ;

EmptyStatement
    : ';'
    ;

LabelStatement
    : IDENTIFIER ':'
        {
            delete $1;
            $1 = nullptr;
        }
    | CASE ConstantExpression ':'
    | DEFAULT ':'
    ;

ExpressionStatement
    : Expression
    ;

SelectionStatement
    : IF '(' Expression ')' Statement
    | IF '(' Expression ')' Statement ELSE Statement
    | SWITCH '(' Expression ')' Block
    ;

IterationStatement
    : WHILE '(' Expression ')' Statement
    | DO Statement WHILE '(' Expression ')' ';'
    | FOR '(' ForInit ForExpr ForIncr ')' Statement
    | FOR '(' ForInit ForExpr         ')' Statement
    ;

ForInit
    : ExpressionStatements ';'
    | LocalVariableDeclarationStatement
    | ';'
    ;

ForExpr
    : Expression ';'
    | ';'
    ;

ForIncr
    : ExpressionStatements
    ;

ExpressionStatements
    : ExpressionStatement
    | ExpressionStatements ',' ExpressionStatement
    ;

JumpStatement
    : BREAK IDENTIFIER ';'
        {
            delete $2;
            $2 = nullptr;
        }
    | BREAK            ';'
    | CONTINUE IDENTIFIER ';'
        {
            delete $2;
            $2 = nullptr;
        }
    | CONTINUE            ';'
    | RETURN Expression ';'
    | RETURN            ';'
    | THROW Expression ';'
    ;

GuardingStatement
    : SYNCHRONIZED '(' Expression ')' Statement
    | TRY Block Finally
    | TRY Block Catches
    | TRY Block Catches Finally
    ;

Catches
    : Catch
    | Catches Catch
    ;

Catch
    : CatchHeader Block
    ;

CatchHeader
    : CATCH '(' TypeSpecifier IDENTIFIER ')'
        {
            delete $3;
            delete $4;
            $3 = nullptr;
            $4 = nullptr;
        }
    | CATCH '(' TypeSpecifier ')'
        {
            delete $3;
            $3 = nullptr;
        }
    ;

Finally
    : FINALLY Block
    ;

PrimaryExpression
    : QualifiedName
        {
            delete $1;
            $1 = nullptr;
        }
    | NotJustName
    ;

NotJustName
    : SpecialName
    | NewAllocationExpression
    | ComplexPrimary
    ;

ComplexPrimary
    : '(' Expression ')'
    | ComplexPrimaryNoParenthesis
    ;

ComplexPrimaryNoParenthesis
    : LITERAL
    | BOOLLIT
    | ArrayAccess
    | FieldAccess
    | MethodCall
    ;

ArrayAccess
    : QualifiedName '[' Expression ']'
        {
            delete $1;
            $1 = nullptr;
        }
    | ComplexPrimary '[' Expression ']'
    ;

FieldAccess
    : NotJustName '.' IDENTIFIER
        {
            delete $3;
            $3 = nullptr;
        }
    | RealPostfixExpression '.' IDENTIFIER
        {
            delete $3;
            $3 = nullptr;
        }
    | QualifiedName '.' THIS
        {
            delete $1;
            $1 = nullptr;
        }
    | QualifiedName '.' CLASS
        {
            delete $1;
            $1 = nullptr;
        }
    | PrimitiveType '.' CLASS
        {
            delete $1;
            $1 = nullptr;
        }
    ;

MethodCall
    : MethodAccess '(' ArgumentList ')'
    | MethodAccess '(' ')'
    ;

MethodAccess
    : ComplexPrimaryNoParenthesis
    | SpecialName
    | QualifiedName
        {
            delete $1;
            $1 = nullptr;
        }
    ;

SpecialName
    : THIS
    | SUPER
    | JNULL
    ;

ArgumentList
    : Expression
    | ArgumentList ',' Expression
    ;

NewAllocationExpression
    : PlainNewAllocationExpression
    | QualifiedName '.' PlainNewAllocationExpression
        {
            delete $1;
            $1 = nullptr;
        }
    ;

PlainNewAllocationExpression
    : ArrayAllocationExpression
    | ClassAllocationExpression
    | ArrayAllocationExpression '{' '}'
    | ClassAllocationExpression '{' '}'
    | ArrayAllocationExpression '{' ArrayInitializers '}'
    | ClassAllocationExpression '{' FieldDeclarations '}'
    ;

ClassAllocationExpression
    : NEW TypeName '(' ArgumentList ')'
        {
            delete $2;
            $2 = nullptr;
        }
    | NEW TypeName '('              ')'
        {
            delete $2;
            $2 = nullptr;
        }
    ;

ArrayAllocationExpression
    : NEW TypeName DimExprs Dims
        {   
            delete $2;
            delete $4;
            $2 = nullptr;
            $4 = nullptr;
        }
    | NEW TypeName DimExprs
        {
            delete $2;
            $2 = nullptr;
        }
    | NEW TypeName Dims
        {
            delete $2;
            delete $3;
            $2 = nullptr;
            $3 = nullptr;
        }
    ;

DimExprs
    : DimExpr
    | DimExprs DimExpr
    ;

DimExpr
    : '[' Expression ']'
    ;

Dims
    : OP_DIM    {$$ = $1;}
    | Dims OP_DIM
        {
            *$$ += *$2;
            delete $2;
            $2 = nullptr;
        }
    ;

PostfixExpression
    : PrimaryExpression
    | RealPostfixExpression
    ;

RealPostfixExpression
    : PostfixExpression OP_INC
    | PostfixExpression OP_DEC
    ;

UnaryExpression
    : OP_INC UnaryExpression
    | OP_DEC UnaryExpression
    | ArithmeticUnaryOperator CastExpression
    | LogicalUnaryExpression
    ;

LogicalUnaryExpression
    : PostfixExpression
    | LogicalUnaryOperator UnaryExpression
    ;

LogicalUnaryOperator
    : '~'
    | '!'
    ;

ArithmeticUnaryOperator
    : '+'
    | '-'
    ;

CastExpression
    : UnaryExpression
    | '(' PrimitiveTypeExpression ')' CastExpression
    | '(' ClassTypeExpression ')' CastExpression
    | '(' Expression ')' LogicalUnaryExpression
    ;

PrimitiveTypeExpression
    : PrimitiveType
        {
            delete $1;
            $1 = nullptr;
        }
    | PrimitiveType Dims
        {
            delete $1;
            delete $2;
            $1 = nullptr;
            $2 = nullptr;
        }
    ;

ClassTypeExpression
    : QualifiedName Dims
        {
            delete $1;
            delete $2;
            $1 = nullptr;
            $2 = nullptr;
        }
    ;

MultiplicativeExpression
    : CastExpression
    | MultiplicativeExpression '*' CastExpression
    | MultiplicativeExpression '/' CastExpression
    | MultiplicativeExpression '%' CastExpression
    ;

AdditiveExpression
    : MultiplicativeExpression
    | AdditiveExpression '+' MultiplicativeExpression
    | AdditiveExpression '-' MultiplicativeExpression
    ;

ShiftExpression
    : AdditiveExpression
    | ShiftExpression OP_SHL AdditiveExpression
    | ShiftExpression OP_SHR AdditiveExpression
    | ShiftExpression OP_SHRR AdditiveExpression
    ;

RelationalExpression
    : ShiftExpression
    | RelationalExpression '<' ShiftExpression
    | RelationalExpression '>' ShiftExpression
    | RelationalExpression OP_LE ShiftExpression
    | RelationalExpression OP_GE ShiftExpression
    | RelationalExpression INSTANCEOF TypeSpecifier
        {
            delete $3;
            $3 = nullptr;
        }
    ;

EqualityExpression
    : RelationalExpression
    | EqualityExpression OP_EQ RelationalExpression
    | EqualityExpression OP_NE RelationalExpression
    ;

AndExpression
    : EqualityExpression
    | AndExpression '&' EqualityExpression
    ;

ExclusiveOrExpression
    : AndExpression
    | ExclusiveOrExpression '^' AndExpression
    ;

InclusiveOrExpression
    : ExclusiveOrExpression
    | InclusiveOrExpression '|' ExclusiveOrExpression
    ;

ConditionalAndExpression
    : InclusiveOrExpression
    | ConditionalAndExpression OP_LAND InclusiveOrExpression
    ;

ConditionalOrExpression
    : ConditionalAndExpression
    | ConditionalOrExpression OP_LOR ConditionalAndExpression
    ;

ConditionalExpression
    : ConditionalOrExpression
    | ConditionalOrExpression '?' Expression ':' ConditionalExpression
    ;

AssignmentExpression
    : ConditionalExpression
    | UnaryExpression AssignmentOperator AssignmentExpression
    ;

AssignmentOperator
    : '='
    | ASS_MUL
    | ASS_DIV
    | ASS_MOD
    | ASS_ADD
    | ASS_SUB
    | ASS_SHL
    | ASS_SHR
    | ASS_SHRR
    | ASS_AND
    | ASS_XOR
    | ASS_OR
    ;

Expression
    : AssignmentExpression
    ;

ConstantExpression
    : ConditionalExpression
    ;
%%

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
