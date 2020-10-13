// A Bison parser, made by GNU Bison 3.7.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hpp"


// Unqualified %code blocks.
#line 24 "parser.ypp"

    // Our program is defined here
    sp<ast::Program> ourProgram;
    
    namespace yy
    {
        parser::symbol_type yylex();
        // no need to override the error function because it is already waiting for our implementation
    }
    void showExpr(const std::string& first, const std::string& op, const std::string& second)
    {
        std::cout<< first << op << second <<"\n";
        std::cout << "I am inside\n";
    }

    // TODO get rid of this function later + all its calls (it is just to print the results and make sure it works fine)
    void dfs(sp<ast::Expression> exp)
    {
        if(exp == nullptr)
        {
            std::cout << "empty\n";
            return;
        }
        std::cout << "node is :";
        exp->print();
        std::cout << "\ngo left\n";
        dfs(exp->l);
        std::cout << "go right\n";
        dfs(exp->r);
        std::cout << "go back\n";
    }

#line 79 "parser.tab.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 152 "parser.tab.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TRU: // TRU
      case symbol_kind::S_FLS: // FLS
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_REAL: // REAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ArrayType: // ArrayType
        value.YY_MOVE_OR_COPY< sp<ast::Array>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Assignment: // Assignment
        value.YY_MOVE_OR_COPY< sp<ast::Assignment>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Body: // Body
        value.YY_MOVE_OR_COPY< sp<ast::Block>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PrimitiveType: // PrimitiveType
        value.YY_MOVE_OR_COPY< sp<ast::BuiltinType>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_VariableAcess: // VariableAcess
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        value.YY_MOVE_OR_COPY< sp<ast::Expression>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RecordType: // RecordType
        value.YY_MOVE_OR_COPY< sp<ast::Record>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ReturnStatement: // ReturnStatement
        value.YY_MOVE_OR_COPY< sp<ast::ReturnStatement>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RoutineDeclaration: // RoutineDeclaration
        value.YY_MOVE_OR_COPY< sp<ast::Routine>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RoutineCall: // RoutineCall
        value.YY_MOVE_OR_COPY< sp<ast::RoutineCall>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SimpleDeclaration: // SimpleDeclaration
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_WhileLoop: // WhileLoop
      case symbol_kind::S_ForLoop: // ForLoop
      case symbol_kind::S_IfStatement: // IfStatement
        value.YY_MOVE_OR_COPY< sp<ast::Statement>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< sp<ast::Type>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParameterDeclaration: // ParameterDeclaration
        value.YY_MOVE_OR_COPY< sp<ast::Variable>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Arguments: // Arguments
        value.YY_MOVE_OR_COPY< std::vector<sp<ast::Expression> >  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Parameters: // Parameters
        value.YY_MOVE_OR_COPY< std::vector<sp<ast::Variable> >  > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TRU: // TRU
      case symbol_kind::S_FLS: // FLS
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_REAL: // REAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ArrayType: // ArrayType
        value.move< sp<ast::Array>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Assignment: // Assignment
        value.move< sp<ast::Assignment>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Body: // Body
        value.move< sp<ast::Block>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PrimitiveType: // PrimitiveType
        value.move< sp<ast::BuiltinType>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_VariableAcess: // VariableAcess
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        value.move< sp<ast::Expression>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RecordType: // RecordType
        value.move< sp<ast::Record>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ReturnStatement: // ReturnStatement
        value.move< sp<ast::ReturnStatement>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RoutineDeclaration: // RoutineDeclaration
        value.move< sp<ast::Routine>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RoutineCall: // RoutineCall
        value.move< sp<ast::RoutineCall>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SimpleDeclaration: // SimpleDeclaration
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_WhileLoop: // WhileLoop
      case symbol_kind::S_ForLoop: // ForLoop
      case symbol_kind::S_IfStatement: // IfStatement
        value.move< sp<ast::Statement>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_type: // type
        value.move< sp<ast::Type>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParameterDeclaration: // ParameterDeclaration
        value.move< sp<ast::Variable>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Arguments: // Arguments
        value.move< std::vector<sp<ast::Expression> >  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Parameters: // Parameters
        value.move< std::vector<sp<ast::Variable> >  > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TRU: // TRU
      case symbol_kind::S_FLS: // FLS
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_REAL: // REAL
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ArrayType: // ArrayType
        value.copy< sp<ast::Array>  > (that.value);
        break;

      case symbol_kind::S_Assignment: // Assignment
        value.copy< sp<ast::Assignment>  > (that.value);
        break;

      case symbol_kind::S_Body: // Body
        value.copy< sp<ast::Block>  > (that.value);
        break;

      case symbol_kind::S_PrimitiveType: // PrimitiveType
        value.copy< sp<ast::BuiltinType>  > (that.value);
        break;

      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_VariableAcess: // VariableAcess
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        value.copy< sp<ast::Expression>  > (that.value);
        break;

      case symbol_kind::S_RecordType: // RecordType
        value.copy< sp<ast::Record>  > (that.value);
        break;

      case symbol_kind::S_ReturnStatement: // ReturnStatement
        value.copy< sp<ast::ReturnStatement>  > (that.value);
        break;

      case symbol_kind::S_RoutineDeclaration: // RoutineDeclaration
        value.copy< sp<ast::Routine>  > (that.value);
        break;

      case symbol_kind::S_RoutineCall: // RoutineCall
        value.copy< sp<ast::RoutineCall>  > (that.value);
        break;

      case symbol_kind::S_SimpleDeclaration: // SimpleDeclaration
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_WhileLoop: // WhileLoop
      case symbol_kind::S_ForLoop: // ForLoop
      case symbol_kind::S_IfStatement: // IfStatement
        value.copy< sp<ast::Statement>  > (that.value);
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_type: // type
        value.copy< sp<ast::Type>  > (that.value);
        break;

      case symbol_kind::S_ParameterDeclaration: // ParameterDeclaration
        value.copy< sp<ast::Variable>  > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_Arguments: // Arguments
        value.copy< std::vector<sp<ast::Expression> >  > (that.value);
        break;

      case symbol_kind::S_Parameters: // Parameters
        value.copy< std::vector<sp<ast::Variable> >  > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TRU: // TRU
      case symbol_kind::S_FLS: // FLS
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_REAL: // REAL
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ArrayType: // ArrayType
        value.move< sp<ast::Array>  > (that.value);
        break;

      case symbol_kind::S_Assignment: // Assignment
        value.move< sp<ast::Assignment>  > (that.value);
        break;

      case symbol_kind::S_Body: // Body
        value.move< sp<ast::Block>  > (that.value);
        break;

      case symbol_kind::S_PrimitiveType: // PrimitiveType
        value.move< sp<ast::BuiltinType>  > (that.value);
        break;

      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_VariableAcess: // VariableAcess
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        value.move< sp<ast::Expression>  > (that.value);
        break;

      case symbol_kind::S_RecordType: // RecordType
        value.move< sp<ast::Record>  > (that.value);
        break;

      case symbol_kind::S_ReturnStatement: // ReturnStatement
        value.move< sp<ast::ReturnStatement>  > (that.value);
        break;

      case symbol_kind::S_RoutineDeclaration: // RoutineDeclaration
        value.move< sp<ast::Routine>  > (that.value);
        break;

      case symbol_kind::S_RoutineCall: // RoutineCall
        value.move< sp<ast::RoutineCall>  > (that.value);
        break;

      case symbol_kind::S_SimpleDeclaration: // SimpleDeclaration
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_WhileLoop: // WhileLoop
      case symbol_kind::S_ForLoop: // ForLoop
      case symbol_kind::S_IfStatement: // IfStatement
        value.move< sp<ast::Statement>  > (that.value);
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_type: // type
        value.move< sp<ast::Type>  > (that.value);
        break;

      case symbol_kind::S_ParameterDeclaration: // ParameterDeclaration
        value.move< sp<ast::Variable>  > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_Arguments: // Arguments
        value.move< std::vector<sp<ast::Expression> >  > (that.value);
        break;

      case symbol_kind::S_Parameters: // Parameters
        value.move< std::vector<sp<ast::Variable> >  > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_TRU: // TRU
      case symbol_kind::S_FLS: // FLS
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_REAL: // REAL
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ArrayType: // ArrayType
        yylhs.value.emplace< sp<ast::Array>  > ();
        break;

      case symbol_kind::S_Assignment: // Assignment
        yylhs.value.emplace< sp<ast::Assignment>  > ();
        break;

      case symbol_kind::S_Body: // Body
        yylhs.value.emplace< sp<ast::Block>  > ();
        break;

      case symbol_kind::S_PrimitiveType: // PrimitiveType
        yylhs.value.emplace< sp<ast::BuiltinType>  > ();
        break;

      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_VariableAcess: // VariableAcess
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        yylhs.value.emplace< sp<ast::Expression>  > ();
        break;

      case symbol_kind::S_RecordType: // RecordType
        yylhs.value.emplace< sp<ast::Record>  > ();
        break;

      case symbol_kind::S_ReturnStatement: // ReturnStatement
        yylhs.value.emplace< sp<ast::ReturnStatement>  > ();
        break;

      case symbol_kind::S_RoutineDeclaration: // RoutineDeclaration
        yylhs.value.emplace< sp<ast::Routine>  > ();
        break;

      case symbol_kind::S_RoutineCall: // RoutineCall
        yylhs.value.emplace< sp<ast::RoutineCall>  > ();
        break;

      case symbol_kind::S_SimpleDeclaration: // SimpleDeclaration
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_WhileLoop: // WhileLoop
      case symbol_kind::S_ForLoop: // ForLoop
      case symbol_kind::S_IfStatement: // IfStatement
        yylhs.value.emplace< sp<ast::Statement>  > ();
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_type: // type
        yylhs.value.emplace< sp<ast::Type>  > ();
        break;

      case symbol_kind::S_ParameterDeclaration: // ParameterDeclaration
        yylhs.value.emplace< sp<ast::Variable>  > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_Arguments: // Arguments
        yylhs.value.emplace< std::vector<sp<ast::Expression> >  > ();
        break;

      case symbol_kind::S_Parameters: // Parameters
        yylhs.value.emplace< std::vector<sp<ast::Variable> >  > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3: // program: program SimpleDeclaration
#line 122 "parser.ypp"
                            {/* TODO maybe use this to add the variables to our vars*/ }
#line 938 "parser.tab.cpp"
    break;

  case 4: // program: program RoutineDeclaration
#line 123 "parser.ypp"
                             {/* TODO use this to add the pointers to our routines*/}
#line 944 "parser.tab.cpp"
    break;

  case 6: // SimpleDeclaration: VariableDeclaration
#line 127 "parser.ypp"
                                        {yylhs.value.as < sp<ast::Statement>  > () = std::make_shared<ast::Statement>(); /* TODO*/ }
#line 950 "parser.tab.cpp"
    break;

  case 7: // SimpleDeclaration: TypeDeclaration
#line 128 "parser.ypp"
                                        {yylhs.value.as < sp<ast::Statement>  > () = std::make_shared<ast::Statement>(); /* TODO*/ }
#line 956 "parser.tab.cpp"
    break;

  case 8: // VariableDeclaration: VAR IDENTIFIER COL type
#line 131 "parser.ypp"
                                             { std::cout << "defined variable " << yystack_[2].value.as < std::string > () << " with type " << (yystack_[0].value.as < sp<ast::Type>  > ())->name << "\n"; }
#line 962 "parser.tab.cpp"
    break;

  case 9: // VariableDeclaration: VAR IDENTIFIER IS Expression
#line 132 "parser.ypp"
                               {std::cout << yystack_[2].value.as < std::string > () << " " << (yystack_[0].value.as < sp<ast::Expression>  > ())->name << std::endl; /*dfs($4);*/}
#line 968 "parser.tab.cpp"
    break;

  case 10: // VariableDeclaration: VAR IDENTIFIER COL type IS Expression
#line 133 "parser.ypp"
                                        {std::cout << yystack_[4].value.as < std::string > () << " " << (yystack_[0].value.as < sp<ast::Expression>  > ())->name << "\n"; /*dfs($6);*/}
#line 974 "parser.tab.cpp"
    break;

  case 11: // TypeDeclaration: TKEY IDENTIFIER IS type
#line 136 "parser.ypp"
                                         { std::cout << "defined new type " << yystack_[2].value.as < std::string > () << "\n"; }
#line 980 "parser.tab.cpp"
    break;

  case 12: // RoutineDeclaration: RUT IDENTIFIER LBR Parameters RBR IS Body END
#line 139 "parser.ypp"
                                                                  { yylhs.value.as < sp<ast::Routine>  > () = std::make_shared<ast::Routine>(yystack_[6].value.as < std::string > (), yystack_[4].value.as < std::vector<sp<ast::Variable> >  > (), yystack_[1].value.as < sp<ast::Block>  > (), nullptr); /*TODO delete*/ (yylhs.value.as < sp<ast::Routine>  > ())->print();}
#line 986 "parser.tab.cpp"
    break;

  case 13: // RoutineDeclaration: RUT IDENTIFIER LBR Parameters RBR COL type IS Body END
#line 140 "parser.ypp"
                                                         {  yylhs.value.as < sp<ast::Routine>  > () = std::make_shared<ast::Routine>(yystack_[8].value.as < std::string > (), yystack_[6].value.as < std::vector<sp<ast::Variable> >  > (), yystack_[1].value.as < sp<ast::Block>  > (), yystack_[3].value.as < sp<ast::Type>  > ()); /*TODO delete*/ (yylhs.value.as < sp<ast::Routine>  > ())->print();}
#line 992 "parser.tab.cpp"
    break;

  case 14: // Parameters: ParameterDeclaration
#line 143 "parser.ypp"
                                 {(yylhs.value.as < std::vector<sp<ast::Variable> >  > ()).push_back(yystack_[0].value.as < sp<ast::Variable>  > ()); }
#line 998 "parser.tab.cpp"
    break;

  case 15: // Parameters: Parameters COM ParameterDeclaration
#line 144 "parser.ypp"
                                      {swap(yystack_[2].value.as < std::vector<sp<ast::Variable> >  > (), yylhs.value.as < std::vector<sp<ast::Variable> >  > ());  (yylhs.value.as < std::vector<sp<ast::Variable> >  > ()).push_back(yystack_[0].value.as < sp<ast::Variable>  > ());}
#line 1004 "parser.tab.cpp"
    break;

  case 16: // ParameterDeclaration: IDENTIFIER COL type
#line 147 "parser.ypp"
                                          {yylhs.value.as < sp<ast::Variable>  > () = std::make_shared<ast::Variable>(yystack_[2].value.as < std::string > (), 0, 0, yystack_[0].value.as < sp<ast::Type>  > ());}
#line 1010 "parser.tab.cpp"
    break;

  case 17: // type: IDENTIFIER
#line 150 "parser.ypp"
                 {yylhs.value.as < sp<ast::Type>  > () = std::make_shared<ast::Type>(yystack_[0].value.as < std::string > ());}
#line 1016 "parser.tab.cpp"
    break;

  case 18: // type: PrimitiveType
#line 151 "parser.ypp"
                {yylhs.value.as < sp<ast::Type>  > () = yystack_[0].value.as < sp<ast::BuiltinType>  > (); /* casting from derived to base !!*/}
#line 1022 "parser.tab.cpp"
    break;

  case 19: // type: ArrayType
#line 152 "parser.ypp"
            {yylhs.value.as < sp<ast::Type>  > () = yystack_[0].value.as < sp<ast::Array>  > (); /* casting from derived to base !!*/}
#line 1028 "parser.tab.cpp"
    break;

  case 20: // type: RecordType
#line 153 "parser.ypp"
             {yylhs.value.as < sp<ast::Type>  > () = yystack_[0].value.as < sp<ast::Record>  > (); /* casting from derived to base !!*/}
#line 1034 "parser.tab.cpp"
    break;

  case 21: // PrimitiveType: ITYPE
#line 156 "parser.ypp"
                     { yylhs.value.as < sp<ast::BuiltinType>  > () = std::make_shared<ast::BuiltinType>("integer");}
#line 1040 "parser.tab.cpp"
    break;

  case 22: // PrimitiveType: RTYPE
#line 157 "parser.ypp"
        {              yylhs.value.as < sp<ast::BuiltinType>  > () =  std::make_shared<ast::BuiltinType> ("real"); }
#line 1046 "parser.tab.cpp"
    break;

  case 23: // PrimitiveType: BTYPE
#line 158 "parser.ypp"
        {              yylhs.value.as < sp<ast::BuiltinType>  > () =  std::make_shared<ast::BuiltinType> ("boolean"); }
#line 1052 "parser.tab.cpp"
    break;

  case 24: // RecordType: RCRD VariableDeclarationBlock END
#line 161 "parser.ypp"
                                              {  yylhs.value.as < sp<ast::Record>  > () =  std::make_shared<ast::Record>("Record"); }
#line 1058 "parser.tab.cpp"
    break;

  case 25: // ArrayType: ARY LAR Expression RAR type
#line 164 "parser.ypp"
                                       { yylhs.value.as < sp<ast::Array>  > () = std::make_shared<ast::Array>("Array");}
#line 1064 "parser.tab.cpp"
    break;

  case 26: // ArrayType: ARY LAR RAR type
#line 165 "parser.ypp"
                   {                     yylhs.value.as < sp<ast::Array>  > () = std::make_shared<ast::Array>("Array");}
#line 1070 "parser.tab.cpp"
    break;

  case 27: // Body: %empty
#line 168 "parser.ypp"
      {yylhs.value.as < sp<ast::Block>  > () = std::make_shared<ast::Block>(); /* create an empty body */}
#line 1076 "parser.tab.cpp"
    break;

  case 28: // Body: Body SimpleDeclaration
#line 169 "parser.ypp"
                         {(yystack_[1].value.as < sp<ast::Block>  > ())->addStatement(yystack_[0].value.as < sp<ast::Statement>  > ()); yylhs.value.as < sp<ast::Block>  > () = yystack_[1].value.as < sp<ast::Block>  > ();}
#line 1082 "parser.tab.cpp"
    break;

  case 29: // Body: Body Statement
#line 170 "parser.ypp"
                 {(yystack_[1].value.as < sp<ast::Block>  > ())->addStatement(yystack_[0].value.as < sp<ast::Statement>  > ()); yylhs.value.as < sp<ast::Block>  > () = yystack_[1].value.as < sp<ast::Block>  > ();}
#line 1088 "parser.tab.cpp"
    break;

  case 30: // Body: Body EOL
#line 171 "parser.ypp"
  { yylhs.value.as < sp<ast::Block>  > () = yystack_[1].value.as < sp<ast::Block>  > (); }
#line 1094 "parser.tab.cpp"
    break;

  case 31: // Statement: Assignment
#line 174 "parser.ypp"
                        {yylhs.value.as < sp<ast::Statement>  > () = yystack_[0].value.as < sp<ast::Assignment>  > ();}
#line 1100 "parser.tab.cpp"
    break;

  case 32: // Statement: RoutineCall
#line 175 "parser.ypp"
                        {yylhs.value.as < sp<ast::Statement>  > () = yystack_[0].value.as < sp<ast::RoutineCall>  > ();}
#line 1106 "parser.tab.cpp"
    break;

  case 33: // Statement: WhileLoop
#line 176 "parser.ypp"
                        {yylhs.value.as < sp<ast::Statement>  > () = yystack_[0].value.as < sp<ast::Statement>  > ();}
#line 1112 "parser.tab.cpp"
    break;

  case 34: // Statement: ForLoop
#line 177 "parser.ypp"
                        {yylhs.value.as < sp<ast::Statement>  > () = yystack_[0].value.as < sp<ast::Statement>  > ();}
#line 1118 "parser.tab.cpp"
    break;

  case 35: // Statement: IfStatement
#line 178 "parser.ypp"
                        {yylhs.value.as < sp<ast::Statement>  > () = yystack_[0].value.as < sp<ast::Statement>  > ();}
#line 1124 "parser.tab.cpp"
    break;

  case 36: // Statement: ReturnStatement
#line 179 "parser.ypp"
                         {yylhs.value.as < sp<ast::Statement>  > () = yystack_[0].value.as < sp<ast::ReturnStatement>  > ();}
#line 1130 "parser.tab.cpp"
    break;

  case 37: // ReturnStatement: RTN EOL
#line 182 "parser.ypp"
                         {   yylhs.value.as < sp<ast::ReturnStatement>  > () = std::make_shared<ast::ReturnStatement>(nullptr);}
#line 1136 "parser.tab.cpp"
    break;

  case 38: // ReturnStatement: RTN Expression
#line 183 "parser.ypp"
                 {          yylhs.value.as < sp<ast::ReturnStatement>  > () = std::make_shared<ast::ReturnStatement>(yystack_[0].value.as < sp<ast::Expression>  > ());}
#line 1142 "parser.tab.cpp"
    break;

  case 39: // Assignment: ModifiablePrimary ASN Expression
#line 186 "parser.ypp"
                                             {yylhs.value.as < sp<ast::Assignment>  > () = std::make_shared<ast::Assignment>(std::get<0>((yystack_[2].value.as < sp<ast::Expression>  > ())->value), yystack_[0].value.as < sp<ast::Expression>  > ());}
#line 1148 "parser.tab.cpp"
    break;

  case 40: // RoutineCall: IDENTIFIER LBR Arguments RBR
#line 189 "parser.ypp"
                                          { yylhs.value.as < sp<ast::RoutineCall>  > () = std::make_shared<ast::RoutineCall>(); (yylhs.value.as < sp<ast::RoutineCall>  > ())->args = std::move(yystack_[1].value.as < std::vector<sp<ast::Expression> >  > ());}
#line 1154 "parser.tab.cpp"
    break;

  case 41: // WhileLoop: WHL Expression LOP Body END
#line 192 "parser.ypp"
                                       { yylhs.value.as < sp<ast::Statement>  > () = std::make_shared<ast::WhileLoop>(); /*TODO*/}
#line 1160 "parser.tab.cpp"
    break;

  case 42: // ForLoop: FOR IDENTIFIER Range LOP Body END
#line 195 "parser.ypp"
                                           {yylhs.value.as < sp<ast::Statement>  > () = std::make_shared<ast::ForLoop>(); /*TODO*/ }
#line 1166 "parser.tab.cpp"
    break;

  case 45: // IfStatement: IF Expression THEN Body END
#line 202 "parser.ypp"
                                         {  yylhs.value.as < sp<ast::Statement>  > () = std::make_shared<ast::IfStatement>(yystack_[3].value.as < sp<ast::Expression>  > (), yystack_[1].value.as < sp<ast::Block>  > (), nullptr);}
#line 1172 "parser.tab.cpp"
    break;

  case 46: // IfStatement: IF Expression THEN Body EOL ELSE Body END
#line 203 "parser.ypp"
                                           {yylhs.value.as < sp<ast::Statement>  > () = std::make_shared<ast::IfStatement>(yystack_[6].value.as < sp<ast::Expression>  > (), yystack_[4].value.as < sp<ast::Block>  > (), yystack_[1].value.as < sp<ast::Block>  > ());}
#line 1178 "parser.tab.cpp"
    break;

  case 50: // Expression: Primary
#line 211 "parser.ypp"
                    { yylhs.value.as < sp<ast::Expression>  > () = yystack_[0].value.as < sp<ast::Expression>  > (); }
#line 1184 "parser.tab.cpp"
    break;

  case 51: // Expression: Expression ADD Expression
#line 212 "parser.ypp"
                            {           yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("+", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1190 "parser.tab.cpp"
    break;

  case 52: // Expression: Expression SUB Expression
#line 213 "parser.ypp"
                             {          yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("-", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1196 "parser.tab.cpp"
    break;

  case 53: // Expression: Expression DIV Expression
#line 214 "parser.ypp"
                            {           yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("/", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1202 "parser.tab.cpp"
    break;

  case 54: // Expression: Expression MUL Expression
#line 215 "parser.ypp"
                            {           yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("*", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1208 "parser.tab.cpp"
    break;

  case 55: // Expression: Expression MOD Expression
#line 216 "parser.ypp"
                            {           yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("%", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1214 "parser.tab.cpp"
    break;

  case 56: // Expression: Expression GRT Expression
#line 217 "parser.ypp"
                            {           yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>(">", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1220 "parser.tab.cpp"
    break;

  case 57: // Expression: Expression GRTE Expression
#line 218 "parser.ypp"
                             {          yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>(">=", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1226 "parser.tab.cpp"
    break;

  case 58: // Expression: Expression LES Expression
#line 219 "parser.ypp"
                            {           yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("<", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1232 "parser.tab.cpp"
    break;

  case 59: // Expression: Expression LESE Expression
#line 220 "parser.ypp"
                             {          yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("<=", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1238 "parser.tab.cpp"
    break;

  case 60: // Expression: Expression EQ Expression
#line 221 "parser.ypp"
                           {            yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("=", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1244 "parser.tab.cpp"
    break;

  case 61: // Expression: Expression NEQ Expression
#line 222 "parser.ypp"
                            {           yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("/=", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1250 "parser.tab.cpp"
    break;

  case 62: // Expression: Expression AND Expression
#line 223 "parser.ypp"
                            {           yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("and", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1256 "parser.tab.cpp"
    break;

  case 63: // Expression: Expression OR Expression
#line 224 "parser.ypp"
                           {            yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("or", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1262 "parser.tab.cpp"
    break;

  case 64: // Expression: Expression XOR Expression
#line 225 "parser.ypp"
                            {           yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("xor", yystack_[2].value.as < sp<ast::Expression>  > (), yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1268 "parser.tab.cpp"
    break;

  case 65: // Expression: SUB Expression
#line 226 "parser.ypp"
                 { sp<ast::Expression> temp = std::make_shared<ast::Expression>(-1, false); yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("*", temp, yystack_[0].value.as < sp<ast::Expression>  > ()); }
#line 1274 "parser.tab.cpp"
    break;

  case 66: // Expression: LBR Expression RBR
#line 227 "parser.ypp"
                     { yylhs.value.as < sp<ast::Expression>  > () = yystack_[1].value.as < sp<ast::Expression>  > ();}
#line 1280 "parser.tab.cpp"
    break;

  case 67: // Arguments: Expression
#line 230 "parser.ypp"
                      {(yylhs.value.as < std::vector<sp<ast::Expression> >  > ()).push_back(yystack_[0].value.as < sp<ast::Expression>  > ()); std::cout << (yylhs.value.as < std::vector<sp<ast::Expression> >  > ()).size() << "\n";}
#line 1286 "parser.tab.cpp"
    break;

  case 68: // Arguments: Arguments COM Expression
#line 231 "parser.ypp"
                           {swap(yylhs.value.as < std::vector<sp<ast::Expression> >  > (),yystack_[2].value.as < std::vector<sp<ast::Expression> >  > ()); (yylhs.value.as < std::vector<sp<ast::Expression> >  > ()).push_back(yystack_[0].value.as < sp<ast::Expression>  > ()); std::cout << (yylhs.value.as < std::vector<sp<ast::Expression> >  > ()).size() << "\n";}
#line 1292 "parser.tab.cpp"
    break;

  case 69: // Primary: INTEGER
#line 234 "parser.ypp"
                 {                      yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>(yystack_[0].value.as < int > (), false); }
#line 1298 "parser.tab.cpp"
    break;

  case 70: // Primary: REAL
#line 235 "parser.ypp"
       {                                yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>(yystack_[0].value.as < double > ()); }
#line 1304 "parser.tab.cpp"
    break;

  case 71: // Primary: TRU
#line 236 "parser.ypp"
      {                                 yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>(yystack_[0].value.as < bool > ()); }
#line 1310 "parser.tab.cpp"
    break;

  case 72: // Primary: FLS
#line 237 "parser.ypp"
      {                                 yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>(yystack_[0].value.as < bool > ()); }
#line 1316 "parser.tab.cpp"
    break;

  case 73: // Primary: ModifiablePrimary
#line 238 "parser.ypp"
                   {    yylhs.value.as < sp<ast::Expression>  > () = yystack_[0].value.as < sp<ast::Expression>  > (); }
#line 1322 "parser.tab.cpp"
    break;

  case 74: // Primary: RoutineCall
#line 239 "parser.ypp"
              {      /*TODO change */   yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>("RoutineCall"); }
#line 1328 "parser.tab.cpp"
    break;

  case 75: // VariableAcess: %empty
#line 242 "parser.ypp"
               {yylhs.value.as < sp<ast::Expression>  > () = nullptr;}
#line 1334 "parser.tab.cpp"
    break;

  case 76: // VariableAcess: VariableAcess DOTN IDENTIFIER
#line 243 "parser.ypp"
                                    {sp<ast::Expression> temp = std::make_shared<ast::Expression>(yystack_[0].value.as < std::string > ());
                                            yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>(".",temp, yystack_[2].value.as < sp<ast::Expression>  > ());}
#line 1341 "parser.tab.cpp"
    break;

  case 77: // VariableAcess: VariableAcess LAR Expression RAR
#line 245 "parser.ypp"
                                    {yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>(".",yystack_[1].value.as < sp<ast::Expression>  > (), yystack_[3].value.as < sp<ast::Expression>  > (), true);}
#line 1347 "parser.tab.cpp"
    break;

  case 78: // ModifiablePrimary: IDENTIFIER VariableAcess
#line 248 "parser.ypp"
                                            {
                                            sp<ast::Expression> temp = std::make_shared<ast::Expression>(yystack_[1].value.as < std::string > ());
                                            if(yystack_[0].value.as < sp<ast::Expression>  > () != nullptr)
                                                yylhs.value.as < sp<ast::Expression>  > () = std::make_shared<ast::Expression>(".",temp, yystack_[0].value.as < sp<ast::Expression>  > ());
                                            else
                                                yylhs.value.as < sp<ast::Expression>  > () = temp;
                                            }
#line 1359 "parser.tab.cpp"
    break;


#line 1363 "parser.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char parser::yypact_ninf_ = -86;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
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

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     5,     3,     6,     7,
       4,     0,     0,     0,     0,     0,     0,     0,    17,    47,
       0,    21,    22,    23,     8,    18,    20,    19,    75,    69,
      70,     0,    71,    72,     0,    74,     9,    50,    73,    11,
       0,     0,    14,     0,     0,     0,     0,    78,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    49,    48,
       0,     0,    10,    67,     0,     0,     0,    66,    51,    52,
      54,    53,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    16,     0,    27,    15,    26,     0,    40,     0,
       0,    76,     0,     0,    25,    68,    77,    27,     0,     0,
       0,     0,    12,    30,    28,    29,    36,    31,    32,    33,
      34,    35,     0,     0,     0,    37,    38,     0,     0,     0,
      13,    27,     0,     0,    27,    39,     0,     0,     0,    27,
       0,    45,    30,     0,     0,     0,    41,    27,     0,    43,
      42,     0,    44,    46
  };

  const signed char
  parser::yypgoto_[] =
  {
     -86,   -86,    85,    48,   -86,   -86,   -86,    22,   -14,   -86,
     -86,   -86,    25,   -86,   -86,   -86,   -85,   -86,   -86,   -86,
     -86,   -86,   -31,   -86,   -86,   -86,   -69
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     1,   114,     8,     9,    10,    41,    42,    24,    25,
      26,    27,   103,   115,   116,   117,    35,   119,   120,   133,
     121,    43,    36,    74,    37,    47,    38
  };

  const unsigned char
  parser::yytable_[] =
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

  const short
  parser::yycheck_[] =
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

  const signed char
  parser::yystos_[] =
  {
       0,    53,     0,    25,    27,    28,    50,    54,    55,    56,
      57,     3,     3,     3,    26,    33,    33,    29,     3,    41,
      42,    47,    48,    49,    60,    61,    62,    63,     3,     4,
       5,     7,    23,    24,    29,    68,    74,    76,    78,    60,
       3,    58,    59,    73,    43,    33,    29,    77,    74,    74,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    26,    30,    31,    40,    50,    55,
      44,    74,    74,    74,    75,    43,    45,    30,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    60,    26,    33,    59,    60,    44,    30,    31,
      74,     3,    60,    64,    60,    74,    44,    33,    20,    32,
      37,    38,    40,    50,    54,    65,    66,    67,    68,    69,
      70,    72,    78,    64,    74,    50,    74,     3,    74,    46,
      40,    21,    35,    71,    39,    74,    64,    36,    74,    39,
      64,    40,    50,    74,    34,    64,    40,    22,    34,    74,
      40,    64,    74,    40
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    52,    53,    53,    53,    53,    54,    54,    55,    55,
      55,    56,    57,    57,    58,    58,    59,    60,    60,    60,
      60,    61,    61,    61,    62,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      68,    69,    70,    71,    71,    72,    72,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    78
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     2,     1,     1,     4,     4,
       6,     4,     8,    10,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     4,     0,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       4,     5,     6,     4,     5,     5,     8,     0,     2,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     0,     3,     4,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER", "REAL", "ADD", "SUB", "MUL", "DIV", "MOD", "GRT", "GRTE",
  "LES", "LESE", "EQ", "NEQ", "AND", "OR", "XOR", "IF", "THEN", "ELSE",
  "TRU", "FLS", "VAR", "COL", "TKEY", "RUT", "LBR", "RBR", "COM", "RTN",
  "IS", "RNG", "IN", "REV", "FOR", "WHL", "LOP", "END", "RCRD", "ARY",
  "LAR", "RAR", "DOTN", "ASN", "ITYPE", "RTYPE", "BTYPE", "EOL", "temp",
  "$accept", "program", "SimpleDeclaration", "VariableDeclaration",
  "TypeDeclaration", "RoutineDeclaration", "Parameters",
  "ParameterDeclaration", "type", "PrimitiveType", "RecordType",
  "ArrayType", "Body", "Statement", "ReturnStatement", "Assignment",
  "RoutineCall", "WhileLoop", "ForLoop", "Range", "IfStatement",
  "VariableDeclarationBlock", "Expression", "Arguments", "Primary",
  "VariableAcess", "ModifiablePrimary", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   121,   121,   122,   123,   124,   127,   128,   131,   132,
     133,   136,   139,   140,   143,   144,   147,   150,   151,   152,
     153,   156,   157,   158,   161,   164,   165,   168,   169,   170,
     171,   174,   175,   176,   177,   178,   179,   182,   183,   186,
     189,   192,   195,   198,   199,   202,   203,   206,   207,   208,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   230,   231,   234,
     235,   236,   237,   238,   239,   242,   243,   245,   248
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1826 "parser.tab.cpp"

#line 256 "parser.ypp"

namespace yy
{
    //overriding yylex in main.cpp

    void parser::error(const std::string& msg)
    {
        std::cout<<"syntax error!\n";
    }
}
