/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER = 259,                 /* INTEGER  */
    REAL = 260,                    /* REAL  */
    ADD = 261,                     /* ADD  */
    SUB = 262,                     /* SUB  */
    MUL = 263,                     /* MUL  */
    DIV = 264,                     /* DIV  */
    MOD = 265,                     /* MOD  */
    GRT = 266,                     /* GRT  */
    GRTE = 267,                    /* GRTE  */
    LES = 268,                     /* LES  */
    LESE = 269,                    /* LESE  */
    EQ = 270,                      /* EQ  */
    NEQ = 271,                     /* NEQ  */
    AND = 272,                     /* AND  */
    OR = 273,                      /* OR  */
    XOR = 274,                     /* XOR  */
    IF = 275,                      /* IF  */
    THEN = 276,                    /* THEN  */
    ELSE = 277,                    /* ELSE  */
    TRU = 278,                     /* TRU  */
    FLS = 279,                     /* FLS  */
    VAR = 280,                     /* VAR  */
    COL = 281,                     /* COL  */
    TKEY = 282,                    /* TKEY  */
    RUT = 283,                     /* RUT  */
    LBR = 284,                     /* LBR  */
    RBR = 285,                     /* RBR  */
    COM = 286,                     /* COM  */
    RTN = 287,                     /* RTN  */
    IS = 288,                      /* IS  */
    RNG = 289,                     /* RNG  */
    IN = 290,                      /* IN  */
    REV = 291,                     /* REV  */
    FOR = 292,                     /* FOR  */
    WHL = 293,                     /* WHL  */
    LOP = 294,                     /* LOP  */
    END = 295,                     /* END  */
    RCRD = 296,                    /* RCRD  */
    ARY = 297,                     /* ARY  */
    LAR = 298,                     /* LAR  */
    RAR = 299,                     /* RAR  */
    DOTN = 300,                    /* DOTN  */
    ASN = 301,                     /* ASN  */
    ITYPE = 302,                   /* ITYPE  */
    RTYPE = 303,                   /* RTYPE  */
    BTYPE = 304,                   /* BTYPE  */
    EOL = 305                      /* EOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.ypp"

int n;
double d;
char s[1025];

#line 120 "parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
