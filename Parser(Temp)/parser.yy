%require  "3.0"
%define api.pure full

%code{
    int yylex(YYSTYPE *lvalp);
    #include<iostream>
    #include<string>
    void yyerror(const char *error);
}

%token IDENTEFIER

%%

anything:
        |IDENTEFIER
        ;

%%
int main()
{
    std::cout<<"I'm in main\n";
    return yyparse();
}

void yyerror(const char *error)
{
    std::cout << error << std::endl;
}

int yylex(YYSTYPE *lvalp)
{
    std::cout<<"I'm in yylex\n";

    return IDENTEFIER;
}