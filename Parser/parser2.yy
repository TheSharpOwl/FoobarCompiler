%{
#include<iostream>
#include<string>
#include<vector>
#include<stack>

void yyerror(const char *error);
int yylex();

%}


/* not sure of those lines yet */
%token IDENTIFIER NUMBER
%token ADD 
%token SUB 
%token DIV 
%token MUL 
%token MOD 
%token OR 
%token XOR 
%token AND 
%token GRT 
%token GRTE
%token LES 
%token LESE
%token EQ 
%token NEQ 
%token IS
%token LBR
%token RBR
%token VAR
%token SEMIC
%token TYPE
%token ASN
%token INTEGER
%token REAL

%type <int> INTEGER
%type <float> REAL

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