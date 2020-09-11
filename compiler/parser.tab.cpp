/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_REAL = 5,                       /* REAL  */
  YYSYMBOL_ADD = 6,                        /* ADD  */
  YYSYMBOL_SUB = 7,                        /* SUB  */
  YYSYMBOL_MUL = 8,                        /* MUL  */
  YYSYMBOL_DIV = 9,                        /* DIV  */
  YYSYMBOL_MOD = 10,                       /* MOD  */
  YYSYMBOL_GRT = 11,                       /* GRT  */
  YYSYMBOL_GRTE = 12,                      /* GRTE  */
  YYSYMBOL_LES = 13,                       /* LES  */
  YYSYMBOL_LESE = 14,                      /* LESE  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_NEQ = 16,                       /* NEQ  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_XOR = 19,                       /* XOR  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_THEN = 21,                      /* THEN  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_TRU = 23,                       /* TRU  */
  YYSYMBOL_FLS = 24,                       /* FLS  */
  YYSYMBOL_VAR = 25,                       /* VAR  */
  YYSYMBOL_COL = 26,                       /* COL  */
  YYSYMBOL_TKEY = 27,                      /* TKEY  */
  YYSYMBOL_RUT = 28,                       /* RUT  */
  YYSYMBOL_LBR = 29,                       /* LBR  */
  YYSYMBOL_RBR = 30,                       /* RBR  */
  YYSYMBOL_COM = 31,                       /* COM  */
  YYSYMBOL_RTN = 32,                       /* RTN  */
  YYSYMBOL_IS = 33,                        /* IS  */
  YYSYMBOL_RNG = 34,                       /* RNG  */
  YYSYMBOL_IN = 35,                        /* IN  */
  YYSYMBOL_REV = 36,                       /* REV  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_WHL = 38,                       /* WHL  */
  YYSYMBOL_LOP = 39,                       /* LOP  */
  YYSYMBOL_END = 40,                       /* END  */
  YYSYMBOL_RCRD = 41,                      /* RCRD  */
  YYSYMBOL_ARY = 42,                       /* ARY  */
  YYSYMBOL_LAR = 43,                       /* LAR  */
  YYSYMBOL_RAR = 44,                       /* RAR  */
  YYSYMBOL_DOTN = 45,                      /* DOTN  */
  YYSYMBOL_ASN = 46,                       /* ASN  */
  YYSYMBOL_ITYPE = 47,                     /* ITYPE  */
  YYSYMBOL_RTYPE = 48,                     /* RTYPE  */
  YYSYMBOL_BTYPE = 49,                     /* BTYPE  */
  YYSYMBOL_EOL = 50,                       /* EOL  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_SimpleDeclaration = 53,         /* SimpleDeclaration  */
  YYSYMBOL_VariableDeclaration = 54,       /* VariableDeclaration  */
  YYSYMBOL_TypeDeclaration = 55,           /* TypeDeclaration  */
  YYSYMBOL_RoutineDeclaration = 56,        /* RoutineDeclaration  */
  YYSYMBOL_Parameters = 57,                /* Parameters  */
  YYSYMBOL_ParameterDeclaration = 58,      /* ParameterDeclaration  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_PrimitiveType = 60,             /* PrimitiveType  */
  YYSYMBOL_RecordType = 61,                /* RecordType  */
  YYSYMBOL_ArrayType = 62,                 /* ArrayType  */
  YYSYMBOL_Body = 63,                      /* Body  */
  YYSYMBOL_Statement = 64,                 /* Statement  */
  YYSYMBOL_Returntatement = 65,            /* Returntatement  */
  YYSYMBOL_Assignment = 66,                /* Assignment  */
  YYSYMBOL_RoutineCall = 67,               /* RoutineCall  */
  YYSYMBOL_WhileLoop = 68,                 /* WhileLoop  */
  YYSYMBOL_ForLoop = 69,                   /* ForLoop  */
  YYSYMBOL_Range = 70,                     /* Range  */
  YYSYMBOL_IfStatement = 71,               /* IfStatement  */
  YYSYMBOL_VariableDeclarationBlock = 72,  /* VariableDeclarationBlock  */
  YYSYMBOL_Expression = 73,                /* Expression  */
  YYSYMBOL_Arguments = 74,                 /* Arguments  */
  YYSYMBOL_Primary = 75,                   /* Primary  */
  YYSYMBOL_VariableAcess = 76,             /* VariableAcess  */
  YYSYMBOL_ModifiablePrimary = 77          /* ModifiablePrimary  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 6 "parser.ypp"

#include <stdio.h>
#include <string.h>
#include "Scanner.h"
#line 14 "parser.ypp"

    int yylex(YYSTYPE *lvalp);
    #include<iostream>
    #include<string>
    Scanner scanner;
    void yyerror(const char *error);

#line 194 "parser.tab.cpp"

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   453

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    70,    71,    72,    75,    76,    79,    80,
      81,    84,    87,    88,    91,    92,    95,    98,    99,   100,
     101,   104,   105,   106,   109,   112,   113,   116,   117,   118,
     119,   122,   123,   124,   125,   126,   127,   130,   131,   134,
     137,   140,   143,   146,   147,   150,   151,   154,   155,   156,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   178,   179,   182,
     183,   184,   185,   186,   187,   190,   191,   192,   195
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER", "REAL", "ADD", "SUB", "MUL", "DIV", "MOD", "GRT", "GRTE",
  "LES", "LESE", "EQ", "NEQ", "AND", "OR", "XOR", "IF", "THEN", "ELSE",
  "TRU", "FLS", "VAR", "COL", "TKEY", "RUT", "LBR", "RBR", "COM", "RTN",
  "IS", "RNG", "IN", "REV", "FOR", "WHL", "LOP", "END", "RCRD", "ARY",
  "LAR", "RAR", "DOTN", "ASN", "ITYPE", "RTYPE", "BTYPE", "EOL", "$accept",
  "program", "SimpleDeclaration", "VariableDeclaration", "TypeDeclaration",
  "RoutineDeclaration", "Parameters", "ParameterDeclaration", "type",
  "PrimitiveType", "RecordType", "ArrayType", "Body", "Statement",
  "Returntatement", "Assignment", "RoutineCall", "WhileLoop", "ForLoop",
  "Range", "IfStatement", "VariableDeclarationBlock", "Expression",
  "Arguments", "Primary", "VariableAcess", "ModifiablePrimary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
#endif

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -86,     8,   -86,     3,     7,    13,   -86,   -86,   -86,   -86,
     -86,   -22,   -16,    24,    -2,   213,    -2,    54,   -86,   -86,
      16,   -86,   -86,   -86,    28,   -86,   -86,   -86,    40,   -86,
     -86,   213,   -86,   -86,   213,   -86,   409,   -86,   -86,   -86,
      37,    18,   -86,    12,   199,   213,   213,   -36,    33,   368,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,    -2,   -21,    54,   -86,   -86,   -86,
      -2,   238,   409,   409,    34,   213,    67,   -86,    33,    33,
     -86,   -86,   -86,   119,   119,   119,   119,   266,   266,   437,
     423,   354,   -86,    -2,   -86,   -86,   -86,    -2,   -86,   213,
     252,   -86,    39,    70,   -86,   409,   -86,   -86,   213,   190,
      71,   213,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,    29,    84,   393,   -86,   409,    46,   291,   213,
     -86,   -86,   288,    45,   -86,   409,   111,   213,   325,   -86,
     115,   -86,    63,   339,   213,   142,   -86,   -86,   213,   409,
     -86,   151,   409,   -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     3,     4,     6,     7,
       5,     0,     0,     0,     0,     0,     0,     0,    17,    47,
       0,    21,    22,    23,     8,    18,    20,    19,    75,    69,
      70,     0,    71,    72,     0,    74,     9,    65,    73,    11,
       0,     0,    14,     0,     0,     0,     0,    78,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    49,    48,
       0,     0,    10,    67,     0,     0,     0,    66,    50,    51,
      53,    52,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    16,     0,    27,    15,    26,     0,    40,     0,
       0,    76,     0,     0,    25,    68,    77,    27,     0,     0,
       0,     0,    12,    30,    28,    29,    36,    31,    32,    33,
      34,    35,     0,     0,     0,    37,    38,     0,     0,     0,
      13,    27,     0,     0,    27,    39,     0,     0,     0,    27,
       0,    45,    30,     0,     0,     0,    41,    27,     0,    43,
      42,     0,    44,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,    85,    48,   -86,   -86,   -86,    22,   -14,   -86,
     -86,   -86,    25,   -86,   -86,   -86,   -85,   -86,   -86,   -86,
     -86,   -86,   -31,   -86,   -86,   -86,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   114,     8,     9,    10,    41,    42,    24,    25,
      26,    27,   103,   115,   116,   117,    35,   119,   120,   133,
     121,    43,    36,    74,    37,    47,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    18,    39,    49,    14,    93,    11,    75,     2,    76,
      12,    15,    94,    71,    72,    73,    13,    16,   118,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     3,   122,     4,     5,     3,   118,    19,
      20,    52,    53,    54,   100,    21,    22,    23,    65,    66,
      92,   118,    67,    17,   122,   118,    96,    40,     6,    44,
     118,    45,    68,    64,    98,    99,   118,   122,   105,    46,
     101,   122,   107,    28,   127,   129,   122,   124,   126,   102,
     128,   132,   122,   104,   139,   147,     7,    28,    95,     0,
     108,    69,     0,     0,     0,     3,     0,     4,   135,     0,
       0,   138,   109,     0,   108,     0,   143,   110,   111,     3,
     112,     4,     0,   149,    28,     0,   109,   152,    28,     0,
     113,   110,   111,     0,   130,    50,    51,    52,    53,    54,
       0,   108,   123,     0,   113,   108,     3,     0,     4,     0,
       3,     0,     4,   109,     0,    28,     0,   109,   110,   111,
       0,   141,   110,   111,    28,   146,   136,     0,     0,   140,
       0,   142,   108,     0,   145,   113,     0,     3,     0,     4,
       0,   108,   151,     0,   109,     0,     3,     0,     4,   110,
     111,     0,   150,   109,     0,     0,     0,     0,   110,   111,
       0,   153,   113,    28,    29,    30,     0,    31,     0,     0,
       0,   113,    28,    29,    30,     0,    31,     0,     0,     0,
       0,     0,     0,    32,    33,     0,    28,    29,    30,    34,
      31,     0,    32,    33,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,     0,
     125,     0,    34,    70,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,     0,    31,   106,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    32,    33,     0,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,   137,     0,     0,     0,     0,     0,
     134,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   144,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     0,   148,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,   131,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,    63,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60
};

static const yytype_int16 yycheck[] =
{
      31,     3,    16,    34,    26,    26,     3,    43,     0,    45,
       3,    33,    33,    44,    45,    46,     3,    33,   103,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    25,   103,    27,    28,    25,   123,    41,
      42,     8,     9,    10,    75,    47,    48,    49,    30,    31,
      64,   136,    40,    29,   123,   140,    70,     3,    50,    43,
     145,    33,    50,    26,    30,    31,   151,   136,    99,    29,
       3,   140,    33,     3,     3,    46,   145,   108,   109,    93,
     111,    35,   151,    97,    39,    22,     1,     3,    66,    -1,
      20,    43,    -1,    -1,    -1,    25,    -1,    27,   129,    -1,
      -1,   132,    32,    -1,    20,    -1,   137,    37,    38,    25,
      40,    27,    -1,   144,     3,    -1,    32,   148,     3,    -1,
      50,    37,    38,    -1,    40,     6,     7,     8,     9,    10,
      -1,    20,   107,    -1,    50,    20,    25,    -1,    27,    -1,
      25,    -1,    27,    32,    -1,     3,    -1,    32,    37,    38,
      -1,    40,    37,    38,     3,    40,   131,    -1,    -1,   134,
      -1,    50,    20,    -1,   139,    50,    -1,    25,    -1,    27,
      -1,    20,   147,    -1,    32,    -1,    25,    -1,    27,    37,
      38,    -1,    40,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    50,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    50,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    -1,     3,     4,     5,    29,
       7,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      50,    -1,    29,    44,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,    44,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      39,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    34,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    34,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,     0,    25,    27,    28,    50,    53,    54,    55,
      56,     3,     3,     3,    26,    33,    33,    29,     3,    41,
      42,    47,    48,    49,    59,    60,    61,    62,     3,     4,
       5,     7,    23,    24,    29,    67,    73,    75,    77,    59,
       3,    57,    58,    72,    43,    33,    29,    76,    73,    73,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    26,    30,    31,    40,    50,    54,
      44,    73,    73,    73,    74,    43,    45,    30,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    59,    26,    33,    58,    59,    44,    30,    31,
      73,     3,    59,    63,    59,    73,    44,    33,    20,    32,
      37,    38,    40,    50,    53,    64,    65,    66,    67,    68,
      69,    71,    77,    63,    73,    50,    73,     3,    73,    46,
      40,    21,    35,    70,    39,    73,    63,    36,    73,    39,
      63,    40,    50,    73,    34,    63,    40,    22,    34,    73,
      40,    63,    73,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    52,    52,    53,    53,    54,    54,
      54,    55,    56,    56,    57,    57,    58,    59,    59,    59,
      59,    60,    60,    60,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      67,    68,    69,    70,    70,    71,    71,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     1,     1,     4,     4,
       6,     4,     8,    10,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     4,     0,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       4,     5,     6,     4,     5,     5,     8,     0,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     0,     3,     4,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* program: program SimpleDeclaration  */
#line 71 "parser.ypp"
                            {  }
#line 1315 "parser.tab.cpp"
    break;

  case 8: /* VariableDeclaration: VAR IDENTIFIER COL type  */
#line 79 "parser.ypp"
                                             { printf("defined variable \"%s\" with type %s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1321 "parser.tab.cpp"
    break;

  case 11: /* TypeDeclaration: TKEY IDENTIFIER IS type  */
#line 84 "parser.ypp"
                                         { printf("defined new type %s \n", (yyvsp[-2].s)); }
#line 1327 "parser.tab.cpp"
    break;

  case 12: /* RoutineDeclaration: RUT IDENTIFIER LBR Parameters RBR IS Body END  */
#line 87 "parser.ypp"
                                                                  { printf("routine %s was declared\n", (yyvsp[-6].s)); }
#line 1333 "parser.tab.cpp"
    break;

  case 13: /* RoutineDeclaration: RUT IDENTIFIER LBR Parameters RBR COL type IS Body END  */
#line 88 "parser.ypp"
                                                         { printf("routine %s was declared\n", (yyvsp[-8].s)); }
#line 1339 "parser.tab.cpp"
    break;

  case 21: /* PrimitiveType: ITYPE  */
#line 104 "parser.ypp"
                     { strcpy((yyval.s), "int"); }
#line 1345 "parser.tab.cpp"
    break;

  case 22: /* PrimitiveType: RTYPE  */
#line 105 "parser.ypp"
        { strcpy((yyval.s), "real"); }
#line 1351 "parser.tab.cpp"
    break;

  case 23: /* PrimitiveType: BTYPE  */
#line 106 "parser.ypp"
        { strcpy((yyval.s), "bool"); }
#line 1357 "parser.tab.cpp"
    break;

  case 24: /* RecordType: RCRD VariableDeclarationBlock END  */
#line 109 "parser.ypp"
                                              {  strcpy((yyval.s), "record"); printf("record was defined\n"); }
#line 1363 "parser.tab.cpp"
    break;

  case 25: /* ArrayType: ARY LAR Expression RAR type  */
#line 112 "parser.ypp"
                                       {  strcpy((yyval.s), "array"); printf("array was defined\n"); }
#line 1369 "parser.tab.cpp"
    break;

  case 26: /* ArrayType: ARY LAR RAR type  */
#line 113 "parser.ypp"
                   {  strcpy((yyval.s), "array"); printf("array was defined\n"); }
#line 1375 "parser.tab.cpp"
    break;

  case 36: /* Statement: Returntatement  */
#line 127 "parser.ypp"
                 { printf("return\n"); }
#line 1381 "parser.tab.cpp"
    break;

  case 40: /* RoutineCall: IDENTIFIER LBR Arguments RBR  */
#line 137 "parser.ypp"
                                          { printf("routine %s was called\n", (yyvsp[-3].s)); }
#line 1387 "parser.tab.cpp"
    break;

  case 41: /* WhileLoop: WHL Expression LOP Body END  */
#line 140 "parser.ypp"
                                       { printf("while loop\n"); }
#line 1393 "parser.tab.cpp"
    break;

  case 42: /* ForLoop: FOR IDENTIFIER Range LOP Body END  */
#line 143 "parser.ypp"
                                           { printf("for loop\n"); }
#line 1399 "parser.tab.cpp"
    break;

  case 50: /* Expression: Expression ADD Expression  */
#line 159 "parser.ypp"
                                      { sprintf((yyval.s), "[%s+%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s+%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1405 "parser.tab.cpp"
    break;

  case 51: /* Expression: Expression SUB Expression  */
#line 160 "parser.ypp"
                             { sprintf((yyval.s), "[%s-%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s-%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1411 "parser.tab.cpp"
    break;

  case 52: /* Expression: Expression DIV Expression  */
#line 161 "parser.ypp"
                            { sprintf((yyval.s), "[%s/%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s/%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1417 "parser.tab.cpp"
    break;

  case 53: /* Expression: Expression MUL Expression  */
#line 162 "parser.ypp"
                            { sprintf((yyval.s), "[%s*%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s*%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1423 "parser.tab.cpp"
    break;

  case 54: /* Expression: Expression MOD Expression  */
#line 163 "parser.ypp"
                            { sprintf((yyval.s), "[%s%%%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s%%%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1429 "parser.tab.cpp"
    break;

  case 55: /* Expression: Expression GRT Expression  */
#line 164 "parser.ypp"
                            { sprintf((yyval.s), "[%s>%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s>%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1435 "parser.tab.cpp"
    break;

  case 56: /* Expression: Expression GRTE Expression  */
#line 165 "parser.ypp"
                             { sprintf((yyval.s), "[%s>=%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s>=%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1441 "parser.tab.cpp"
    break;

  case 57: /* Expression: Expression LES Expression  */
#line 166 "parser.ypp"
                            { sprintf((yyval.s), "[%s<%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s<%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1447 "parser.tab.cpp"
    break;

  case 58: /* Expression: Expression LESE Expression  */
#line 167 "parser.ypp"
                             { sprintf((yyval.s), "[%s<=%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s<=>%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1453 "parser.tab.cpp"
    break;

  case 59: /* Expression: Expression EQ Expression  */
#line 168 "parser.ypp"
                           { sprintf((yyval.s), "[%s=%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s=%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1459 "parser.tab.cpp"
    break;

  case 60: /* Expression: Expression NEQ Expression  */
#line 169 "parser.ypp"
                            { sprintf((yyval.s), "[%s/=%s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s/=%s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1465 "parser.tab.cpp"
    break;

  case 61: /* Expression: Expression AND Expression  */
#line 170 "parser.ypp"
                            { sprintf((yyval.s), "[%s and %s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s and %s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1471 "parser.tab.cpp"
    break;

  case 62: /* Expression: Expression OR Expression  */
#line 171 "parser.ypp"
                           { sprintf((yyval.s), "[%s or %s]", (yyvsp[-2].s), (yyvsp[0].s)); printf("%s or %s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1477 "parser.tab.cpp"
    break;

  case 63: /* Expression: Expression XOR Expression  */
#line 172 "parser.ypp"
                            { sprintf((yyval.s), "[%s xor %s]", (yyvsp[-2].s), (yyvsp[0].s));  printf("%s xor %s\n", (yyvsp[-2].s), (yyvsp[0].s)); }
#line 1483 "parser.tab.cpp"
    break;

  case 64: /* Expression: SUB Expression  */
#line 173 "parser.ypp"
                 { strcpy((yyval.s), (yyvsp[0].s));  printf("unary minus\n"); }
#line 1489 "parser.tab.cpp"
    break;

  case 65: /* Expression: Primary  */
#line 174 "parser.ypp"
          {  }
#line 1495 "parser.tab.cpp"
    break;

  case 66: /* Expression: LBR Expression RBR  */
#line 175 "parser.ypp"
                     { strcpy((yyval.s), (yyvsp[-1].s)); printf("braces around %s\n", (yyvsp[-1].s)); }
#line 1501 "parser.tab.cpp"
    break;

  case 69: /* Primary: INTEGER  */
#line 182 "parser.ypp"
                 { strcpy((yyval.s), "integer"); }
#line 1507 "parser.tab.cpp"
    break;

  case 70: /* Primary: REAL  */
#line 183 "parser.ypp"
       { strcpy((yyval.s), "real"); }
#line 1513 "parser.tab.cpp"
    break;

  case 71: /* Primary: TRU  */
#line 184 "parser.ypp"
      { strcpy((yyval.s), "true"); }
#line 1519 "parser.tab.cpp"
    break;

  case 72: /* Primary: FLS  */
#line 185 "parser.ypp"
      { strcpy((yyval.s), "false"); }
#line 1525 "parser.tab.cpp"
    break;

  case 73: /* Primary: ModifiablePrimary  */
#line 186 "parser.ypp"
                    { strcpy((yyval.s), "modifiablePrimary"); }
#line 1531 "parser.tab.cpp"
    break;

  case 74: /* Primary: RoutineCall  */
#line 187 "parser.ypp"
              { strcpy((yyval.s), "routineCall"); }
#line 1537 "parser.tab.cpp"
    break;


#line 1541 "parser.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 197 "parser.ypp"

int main()
{
    scanner.set_file("inp.txt");
    std::cout<<"I'm in main\n";
    return yyparse();
}

void yyerror(const char *error)
{
    std::cout << error << std::endl;
}

int yylex(YYSTYPE *lvalp)
{
	return scanner.get_next_token(lvalp);
}
