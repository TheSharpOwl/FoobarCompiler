/* simplest version of calculator */
%{
    int yylex(void);
    void yyerror(const char *);
    #include <stdio.h>
%}
/* declare tokens */
%token NUMBER
%token ADD SUB MUL DIV ABS
%token EOL

%%

calclist: /* nothing */
    | calclist exp EOL { printf("= %d\n", $1); }
    ;
 
exp: factor       /*default $$ = $1*/
    | exp ADD factor { $$ = $1 + $3; }
    | exp SUB factor { $$ = $1 - $3; }
    ;

factor: term  /*default $$ = $1 */ 
    | factor MUL term { $$ = $1 * $3; }
    | factor DIV term { $$ = $1 / $3; }
    ;
    
term: NUMBER  /*default $$ = $1*/
    | ABS term   { $$ = $2 >= 0 ? $2 : - $2; }
    ;

%%
//main(int argc, char **argv)
//{
//    yyparse();
//}
//yyerror(char *s)
//{ 
//    fprintf(stderr, "error: %s\n", s);
//}