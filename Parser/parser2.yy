%{
#include<iostream>
#include<string>
#include<vector>
#include<stack>

void yyerror(const char *error);
int yylex();

%}


/* not sure of those lines yet */
%token GRT
%token GRTE
%token LES
%token LESE
%token EQ
%token NEQ
%token DIV
%token LAR
%token RAR
%token LBR
%token RBR
%token ADD
%token SUB
%token MUL
%token MOD
%token COM
%token SEMIC
%token ASN
%token AND
%token OR
%token XOR
%token IF
%token THEN
%token ELSE
%token TRU
%token FLS
%token VAR
%token TKEY
%token RUT
%token RTN
%token IS
%token IN
%token REV
%token FOR
%token WHL
%token LOP
%token END
%token RCRD
%token ARR

/* TODO : not sure of these two exactly */
%token RNG
%token DOTN

%token ITYPE
%token RTYPE
%token BTYPE

%token REAL
%token INTEGER

%token IDENTIFIER

%type <int> ITYPE
%type <float> RTYPE /* might be changed to double */
%type <bool> BTYPE
/* TODO find a way to store the array or another alternative method to deal with it */
/* %type <std::vector> ARRAY */


/* should be ADD instead of '+' and so on */
%left '+'
%left '*'

%%
/* might need to change TYPE to type (define in the grammar)*/
decleration: VAR IDENTIFIER SEMIC TYPE
            ;

exp:    exp ADD exp {}
    |   exp SUB exp {}
    |   exp DIV exp {}
    |   exp MUL exp {}
    |   exp MOD exp {}
    |   exp OR exp {}
    |   exp XOR exp {}
    |   exp AND exp {}
    |   exp GRT exp {}
    |   exp GRTE exp {}
    |   exp LES exp {}
    |   exp LESE exp {}
    |   exp EQ exp {}
    |   exp NEQ exp {}
    |   decleration IS exp {}
    |   IDENTIFIER ASN exp {}
    |   LBR exp RBR {}
    |   INTEGER {}
    |   REAL {}
    |   IDENTIFIER {}
    ;

%%

int main ()
{
    return yyparse();
}

int yylex()
{
    return 0;
}