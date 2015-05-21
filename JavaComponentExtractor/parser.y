%defines
%locations
%error-verbose

%code requires
{
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
}

%{
    #include <QString>

    #pragma warning(disable: 4996)

    extern int yylex();
    extern void yyerror(const char *msg);
%}

%token ABSTRACT FINAL PUBLIC PROTECTED PRIVATE STATIC TRANSIENT VOLATILE NATIVE SYNCHRONIZED
%token YYBOOLEAN YYBYTE YYCHAR YYDOUBLE YYFLOAT YYINT YYLONG YYSHORT YYVOID YYSTRING
%token IDENTIFIER
%token OP_DIM

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

%start CompilationUnit

%%
TypeSpecifier
    : TypeName
    | TypeName Dims
    ;

TypeName
    : PrimitiveType
    | QualifiedName
    ;

ClassNameList
    : QualifiedName
    | ClassNameList ',' QualifiedName
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
    | IMPORT QualifiedName '.' '*' SemiColons
    | IMPORT STATIC QualifiedName SemiColons
    | IMPORT STATIC QualifiedName '.' '*' SemiColons
    | error ';'
    ;

QualifiedName
    : IDENTIFIER
    | QualifiedName '.' IDENTIFIER
    ;

TypeDeclaration
    : ClassHeader '{' FieldDeclarations '}'
    | ClassHeader '{' '}'
    | InterfaceHeader '{' FieldDeclarations '}'
    | InterfaceHeader '{' '}'
    | EnumHeader '{' '}'
    | EnumHeader '{' EnumList '}'
    ;

ClassHeader
    : Modifiers CLASS IDENTIFIER Extends Interfaces
    | Modifiers CLASS IDENTIFIER Extends
    | Modifiers CLASS IDENTIFIER         Interfaces
    |           CLASS IDENTIFIER Extends Interfaces
    | Modifiers CLASS IDENTIFIER
    |           CLASS IDENTIFIER Extends
    |           CLASS IDENTIFIER         Interfaces
    |           CLASS IDENTIFIER
    ;

InterfaceHeader
    : Modifiers INTERFACE IDENTIFIER Extends Interfaces
    | Modifiers INTERFACE IDENTIFIER Extends
    | Modifiers INTERFACE IDENTIFIER         Interfaces
    |           INTERFACE IDENTIFIER Extends Interfaces
    | Modifiers INTERFACE IDENTIFIER
    |           INTERFACE IDENTIFIER Extends
    |           INTERFACE IDENTIFIER         Interfaces
    |           INTERFACE IDENTIFIER
    ;

EnumHeader
    : Modifiers ENUM IDENTIFIER
    | ENUM IDENTIFIER
    ;

EnumList
    : IDENTIFIER
    | EnumList ',' IDENTIFIER
    ;

Modifiers
    : Modifier
    | Modifiers Modifier
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
    : IMPLEMENTS ClassNameList
    ;

Extends
    : EXTENDS TypeName
    | Extends ',' TypeName
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
    : FieldVariableDeclaration ';'
    | MethodDeclaration
    | ConstructorDeclaration
    | StaticInitializer
    | NonStaticInitializer
    | TypeDeclaration
    | error ';'
    ;

FieldVariableDeclaration
    : Modifiers TypeSpecifier VariableDeclarators
    |           TypeSpecifier VariableDeclarators
    ;

VariableDeclarators
    : VariableDeclarator
    | VariableDeclarators ',' VariableDeclarator
    ;

VariableDeclarator
    : DeclaratorName
    | DeclaratorName '=' VariableInitializer
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
    | Modifiers TypeSpecifier MethodDeclarator        MethodBody
    |           TypeSpecifier MethodDeclarator Throws MethodBody
    |           TypeSpecifier MethodDeclarator        MethodBody
    ;

MethodDeclarator
    : DeclaratorName '(' ParameterList ')'
    | DeclaratorName '(' ')'
    | MethodDeclarator OP_DIM
    ;

ParameterList
    : Parameter
    | ParameterList ',' Parameter
    ;

Parameter
    : TypeSpecifier DeclaratorName
    | FINAL TypeSpecifier DeclaratorName
    ;

DeclaratorName
    : IDENTIFIER
    | DeclaratorName OP_DIM
    ;

Throws
    : THROWS ClassNameList
    ;

MethodBody
    : Block
    | ';'
    ;

ConstructorDeclaration
    : Modifiers ConstructorDeclarator Throws Block
    | Modifiers ConstructorDeclarator        Block
    |           ConstructorDeclarator Throws Block
    |           ConstructorDeclarator        Block
    ;

ConstructorDeclarator
    : IDENTIFIER '(' ParameterList ')'
    | IDENTIFIER '(' ')'
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
    | FINAL TypeSpecifier VariableDeclarators ';'
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
    | BREAK            ';'
    | CONTINUE IDENTIFIER ';'
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
    | CATCH '(' TypeSpecifier ')'
    ;

Finally
    : FINALLY Block
    ;

PrimaryExpression
    : QualifiedName
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
    | ComplexPrimary '[' Expression ']'
    ;

FieldAccess
    : NotJustName '.' IDENTIFIER
    | RealPostfixExpression '.' IDENTIFIER
    | QualifiedName '.' THIS
    | QualifiedName '.' CLASS
    | PrimitiveType '.' CLASS
    ;

MethodCall
    : MethodAccess '(' ArgumentList ')'
    | MethodAccess '(' ')'
    ;

MethodAccess
    : ComplexPrimaryNoParenthesis
    | SpecialName
    | QualifiedName
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
    | NEW TypeName '('              ')'
    ;

ArrayAllocationExpression
    : NEW TypeName DimExprs Dims
    | NEW TypeName DimExprs
    | NEW TypeName Dims
    ;

DimExprs
    : DimExpr
    | DimExprs DimExpr
    ;

DimExpr
    : '[' Expression ']'
    ;

Dims
    : OP_DIM
    | Dims OP_DIM
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
    | PrimitiveType Dims
    ;

ClassTypeExpression
    : QualifiedName Dims
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