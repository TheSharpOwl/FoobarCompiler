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


#line 63 "parser.tab.cpp"


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
#line 136 "parser.tab.cpp"

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
      case symbol_kind::S_REAL: // REAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_PrimitiveType: // PrimitiveType
        value.YY_MOVE_OR_COPY< sp<ast::Type>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_RoutineCall: // RoutineCall
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_REAL: // REAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_PrimitiveType: // PrimitiveType
        value.move< sp<ast::Type>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_RoutineCall: // RoutineCall
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        value.move< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_REAL: // REAL
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_PrimitiveType: // PrimitiveType
        value.copy< sp<ast::Type>  > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_RoutineCall: // RoutineCall
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        value.copy< std::string > (that.value);
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
      case symbol_kind::S_REAL: // REAL
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (that.value);
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_PrimitiveType: // PrimitiveType
        value.move< sp<ast::Type>  > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_RoutineCall: // RoutineCall
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        value.move< std::string > (that.value);
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
      case symbol_kind::S_REAL: // REAL
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_temp: // temp
      case symbol_kind::S_PrimitiveType: // PrimitiveType
        yylhs.value.emplace< sp<ast::Type>  > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_RoutineCall: // RoutineCall
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Primary: // Primary
      case symbol_kind::S_ModifiablePrimary: // ModifiablePrimary
        yylhs.value.emplace< std::string > ();
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
  case 2: // program: %empty
#line 87 "parser.ypp"
         {ourProgram = std::make_shared<ast::Program>(); std::cout << "made a program\n"; }
#line 627 "parser.tab.cpp"
    break;

  case 4: // program: program SimpleDeclaration
#line 89 "parser.ypp"
                            {/* TODO maybe use this to add the variables to our vars*/ }
#line 633 "parser.tab.cpp"
    break;

  case 5: // program: program RoutineDeclaration
#line 90 "parser.ypp"
                             {/* TODO use this to add the pointers to our routines*/}
#line 639 "parser.tab.cpp"
    break;

  case 8: // VariableDeclaration: VAR IDENTIFIER COL type
#line 97 "parser.ypp"
                                             { std::cout << "defined variable " << yystack_[2].value.as < std::string > () << " with type " << "TODO" << "\n"; }
#line 645 "parser.tab.cpp"
    break;

  case 9: // VariableDeclaration: VAR IDENTIFIER IS Expression
#line 98 "parser.ypp"
                               {}
#line 651 "parser.tab.cpp"
    break;

  case 10: // VariableDeclaration: VAR IDENTIFIER COL type IS Expression
#line 99 "parser.ypp"
                                        {}
#line 657 "parser.tab.cpp"
    break;

  case 11: // TypeDeclaration: TKEY IDENTIFIER IS type
#line 102 "parser.ypp"
                                         { std::cout << "defined new type " << yystack_[2].value.as < std::string > () << "\n"; }
#line 663 "parser.tab.cpp"
    break;

  case 12: // RoutineDeclaration: RUT IDENTIFIER LBR Parameters RBR IS Body END
#line 105 "parser.ypp"
                                                                  { std::cout << "routine " << yystack_[6].value.as < std::string > () << " was declared\n"; }
#line 669 "parser.tab.cpp"
    break;

  case 13: // RoutineDeclaration: RUT IDENTIFIER LBR Parameters RBR COL type IS Body END
#line 106 "parser.ypp"
                                                         {  std::cout << "routine " << yystack_[8].value.as < std::string > () << " was declared\n";  }
#line 675 "parser.tab.cpp"
    break;

  case 19: // PrimitiveType: ITYPE
#line 122 "parser.ypp"
                     { yylhs.value.as < sp<ast::Type>  > () = std::make_shared<ast::BuiltinType>("integer");}
#line 681 "parser.tab.cpp"
    break;

  case 20: // PrimitiveType: RTYPE
#line 123 "parser.ypp"
        {              yylhs.value.as < sp<ast::Type>  > () =  std::make_shared<ast::BuiltinType> ("real"); }
#line 687 "parser.tab.cpp"
    break;

  case 21: // PrimitiveType: BTYPE
#line 124 "parser.ypp"
        {              yylhs.value.as < sp<ast::Type>  > () =  std::make_shared<ast::BuiltinType> ("boolean"); }
#line 693 "parser.tab.cpp"
    break;

  case 31: // Statement: Returntatement
#line 145 "parser.ypp"
                 {std::cout << "return\n";}
#line 699 "parser.tab.cpp"
    break;

  case 35: // RoutineCall: IDENTIFIER LBR Arguments RBR
#line 155 "parser.ypp"
                                          { std::cout << "routine " << yystack_[3].value.as < std::string > () << " was called\n"; }
#line 705 "parser.tab.cpp"
    break;

  case 36: // WhileLoop: WHL Expression LOP Body END
#line 158 "parser.ypp"
                                       { std::cout << "while loop\n"; }
#line 711 "parser.tab.cpp"
    break;

  case 37: // ForLoop: FOR IDENTIFIER Range LOP Body END
#line 161 "parser.ypp"
                                           { std::cout << "for loop\n"; }
#line 717 "parser.tab.cpp"
    break;

  case 42: // Expression: Expression ADD Expression
#line 177 "parser.ypp"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "+" + yystack_[0].value.as < std::string > ();   showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 723 "parser.tab.cpp"
    break;

  case 43: // Expression: Expression SUB Expression
#line 178 "parser.ypp"
                             {          yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "-" + yystack_[0].value.as < std::string > ();   showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 729 "parser.tab.cpp"
    break;

  case 44: // Expression: Expression DIV Expression
#line 179 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "/" + yystack_[0].value.as < std::string > ();   showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 735 "parser.tab.cpp"
    break;

  case 45: // Expression: Expression MUL Expression
#line 180 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "*" + yystack_[0].value.as < std::string > ();   showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 741 "parser.tab.cpp"
    break;

  case 46: // Expression: Expression MOD Expression
#line 181 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "%" + yystack_[0].value.as < std::string > ();   showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 747 "parser.tab.cpp"
    break;

  case 47: // Expression: Expression GRT Expression
#line 182 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + ">" + yystack_[0].value.as < std::string > ();   showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 753 "parser.tab.cpp"
    break;

  case 48: // Expression: Expression GRTE Expression
#line 183 "parser.ypp"
                             {          yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + ">=" + yystack_[0].value.as < std::string > ();  showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 759 "parser.tab.cpp"
    break;

  case 49: // Expression: Expression LES Expression
#line 184 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "<" + yystack_[0].value.as < std::string > ();   showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 765 "parser.tab.cpp"
    break;

  case 50: // Expression: Expression LESE Expression
#line 185 "parser.ypp"
                             {          yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "<=" + yystack_[0].value.as < std::string > ();  showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 771 "parser.tab.cpp"
    break;

  case 51: // Expression: Expression EQ Expression
#line 186 "parser.ypp"
                           {            yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "=" + yystack_[0].value.as < std::string > ();   showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 777 "parser.tab.cpp"
    break;

  case 52: // Expression: Expression NEQ Expression
#line 187 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "/=" + yystack_[0].value.as < std::string > ();  showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 783 "parser.tab.cpp"
    break;

  case 53: // Expression: Expression AND Expression
#line 188 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "and" + yystack_[0].value.as < std::string > (); showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 789 "parser.tab.cpp"
    break;

  case 54: // Expression: Expression OR Expression
#line 189 "parser.ypp"
                           {            yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "or" + yystack_[0].value.as < std::string > ();  showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 795 "parser.tab.cpp"
    break;

  case 55: // Expression: Expression XOR Expression
#line 190 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "xor" + yystack_[0].value.as < std::string > (); showExpr(yylhs.value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ());}
#line 801 "parser.tab.cpp"
    break;

  case 56: // Expression: SUB Expression
#line 191 "parser.ypp"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();                                 std::cout << "unary minus\n"; }
#line 807 "parser.tab.cpp"
    break;

  case 57: // Expression: Primary
#line 192 "parser.ypp"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 813 "parser.tab.cpp"
    break;

  case 58: // Expression: LBR Expression RBR
#line 193 "parser.ypp"
                     { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); std::cout  << "braces around " << yylhs.value.as < std::string > () << "\n"; }
#line 819 "parser.tab.cpp"
    break;

  case 61: // Primary: INTEGER
#line 200 "parser.ypp"
                 {      yylhs.value.as < std::string > () = "integer"; }
#line 825 "parser.tab.cpp"
    break;

  case 62: // Primary: REAL
#line 201 "parser.ypp"
       {                yylhs.value.as < std::string > () = "real"; }
#line 831 "parser.tab.cpp"
    break;

  case 63: // Primary: TRU
#line 202 "parser.ypp"
      {                 yylhs.value.as < std::string > () = "true";}
#line 837 "parser.tab.cpp"
    break;

  case 64: // Primary: FLS
#line 203 "parser.ypp"
      {                 yylhs.value.as < std::string > () = "false"; }
#line 843 "parser.tab.cpp"
    break;

  case 65: // Primary: ModifiablePrimary
#line 204 "parser.ypp"
                   {    yylhs.value.as < std::string > () = "modifiablePrimary"; }
#line 849 "parser.tab.cpp"
    break;

  case 66: // Primary: RoutineCall
#line 205 "parser.ypp"
              {         yylhs.value.as < std::string > () = "routineCall"; }
#line 855 "parser.tab.cpp"
    break;

  case 70: // ModifiablePrimary: IDENTIFIER VariableAcess
#line 213 "parser.ypp"
                   { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 861 "parser.tab.cpp"
    break;


#line 865 "parser.tab.cpp"

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





  const signed char parser::yypact_ninf_ = -82;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -82,     6,   -82,     1,     2,     5,   -82,   -82,   -82,   -82,
     -82,   -24,   -23,   -14,    34,   285,    34,    13,   -82,   -82,
     -82,    -1,   -82,     7,   -82,   -82,   285,   -82,   -82,   285,
     -82,   350,   -82,   -82,   -82,    29,    19,   -82,   285,   285,
      -4,   110,   309,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,    34,   -19,    13,
     350,   350,    22,   285,    55,   -82,   110,   110,   -82,   -82,
     -82,    38,    38,    38,    38,   323,   323,   390,   364,   378,
     -82,    34,   -82,   -82,   -82,   285,   198,   -82,    27,    37,
     350,   -82,   -82,   285,   174,    58,   285,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,    17,    73,   334,
     -82,   350,    30,   219,   285,   -82,   -82,   216,    32,   -82,
     350,    77,   285,   253,   -82,   105,   -82,    50,   267,   285,
     109,   -82,   -82,   285,   350,   -82,   136,   350,   -82
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     3,     4,     6,     7,
       5,     0,     0,     0,    17,     0,    17,     0,    19,    20,
      21,     8,    18,    67,    61,    62,     0,    63,    64,     0,
      66,     9,    57,    65,    11,     0,     0,    14,     0,     0,
      70,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,     0,
      10,    59,     0,     0,     0,    58,    42,    43,    45,    44,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      16,    17,    22,    15,    35,     0,     0,    68,     0,     0,
      60,    69,    22,     0,     0,     0,     0,    12,    25,    23,
      24,    31,    26,    27,    28,    29,    30,     0,     0,     0,
      32,    33,     0,     0,     0,    13,    22,     0,     0,    22,
      34,     0,     0,     0,    22,     0,    40,    25,     0,     0,
       0,    36,    22,     0,    38,    37,     0,    39,    41
  };

  const signed char
  parser::yypgoto_[] =
  {
     -82,   -82,    78,   -82,   -82,   -82,   -82,    25,   -15,   -82,
     -81,   -82,   -82,   -82,   -35,   -82,   -82,   -82,   -82,   -26,
     -82,   -82,   -82,    59
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    99,     8,     9,    10,    36,    37,    21,    22,
      89,   100,   101,   102,    30,   104,   105,   118,   106,    31,
      62,    32,    40,    33
  };

  const unsigned char
  parser::yytable_[] =
  {
      41,    34,    14,    42,    11,    12,     2,    81,    13,    15,
      16,   108,    60,    61,    82,    17,    35,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     3,    38,     4,     5,   121,    39,    86,   125,    63,
      23,    64,    80,   130,    43,    44,    45,    46,    47,    58,
      59,   136,    84,    85,   103,    57,     6,    93,    87,    90,
      92,   112,     3,   114,     4,   117,    88,   109,   111,    94,
     113,   124,   132,   103,    95,    96,    23,    97,     0,     7,
      23,    18,    19,    20,    83,     0,   103,    98,   120,     0,
     103,   123,     0,    93,     0,   103,   128,    93,     3,     0,
       4,   103,     3,   134,     4,    94,     0,   137,    23,    94,
      95,    96,    23,   115,    95,    96,     0,   126,    45,    46,
      47,     0,     0,    98,     0,    93,     0,   127,     0,    93,
       3,     0,     4,     0,     3,     0,     4,    94,     0,    23,
       0,    94,    95,    96,     0,   131,    95,    96,   107,   135,
       0,     0,     0,     0,     0,    98,    93,     0,     0,    98,
       0,     3,     0,     4,     0,     0,     0,   107,    94,     0,
       0,     0,     0,    95,    96,     0,   138,    23,    24,    25,
     107,    26,     0,     0,   107,     0,    98,     0,     0,   107,
       0,     0,     0,     0,     0,   107,     0,    27,    28,     0,
       0,     0,     0,    29,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,    23,
      24,    25,     0,    26,   110,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    27,
      28,     0,    91,     0,     0,    29,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,     0,     0,   119,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,   129,    23,    24,
      25,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    29,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     0,    65,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,   116,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     0,    56,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53
  };

  const short
  parser::yycheck_[] =
  {
      26,    16,    26,    29,     3,     3,     0,    26,     3,    33,
      33,    92,    38,    39,    33,    29,     3,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    25,    33,    27,    28,   116,    29,    63,   119,    43,
       3,    45,    57,   124,     6,     7,     8,     9,    10,    30,
      31,   132,    30,    31,    89,    26,    50,    20,     3,    85,
      33,     3,    25,    46,    27,    35,    81,    93,    94,    32,
      96,    39,    22,   108,    37,    38,     3,    40,    -1,     1,
       3,    47,    48,    49,    59,    -1,   121,    50,   114,    -1,
     125,   117,    -1,    20,    -1,   130,   122,    20,    25,    -1,
      27,   136,    25,   129,    27,    32,    -1,   133,     3,    32,
      37,    38,     3,    40,    37,    38,    -1,    40,     8,     9,
      10,    -1,    -1,    50,    -1,    20,    -1,    50,    -1,    20,
      25,    -1,    27,    -1,    25,    -1,    27,    32,    -1,     3,
      -1,    32,    37,    38,    -1,    40,    37,    38,    89,    40,
      -1,    -1,    -1,    -1,    -1,    50,    20,    -1,    -1,    50,
      -1,    25,    -1,    27,    -1,    -1,    -1,   108,    32,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,     3,     4,     5,
     121,     7,    -1,    -1,   125,    -1,    50,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,   136,    -1,    23,    24,    -1,
      -1,    -1,    -1,    29,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,     3,
       4,     5,    -1,     7,    50,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    23,
      24,    -1,    44,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    39,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    34,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16
  };

  const signed char
  parser::yystos_[] =
  {
       0,    53,     0,    25,    27,    28,    50,    54,    55,    56,
      57,     3,     3,     3,    26,    33,    33,    29,    47,    48,
      49,    60,    61,     3,     4,     5,     7,    23,    24,    29,
      66,    71,    73,    75,    60,     3,    58,    59,    33,    29,
      74,    71,    71,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    26,    30,    31,
      71,    71,    72,    43,    45,    30,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      60,    26,    33,    59,    30,    31,    71,     3,    60,    62,
      71,    44,    33,    20,    32,    37,    38,    40,    50,    54,
      63,    64,    65,    66,    67,    68,    70,    75,    62,    71,
      50,    71,     3,    71,    46,    40,    21,    35,    69,    39,
      71,    62,    36,    71,    39,    62,    40,    50,    71,    34,
      62,    40,    22,    34,    71,    40,    62,    71,    40
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    52,    53,    53,    53,    53,    54,    54,    55,    55,
      55,    56,    57,    57,    58,    58,    59,    60,    60,    61,
      61,    61,    62,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    65,    66,    67,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    74,    74,    74,
      75
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     2,     1,     1,     4,     4,
       6,     4,     8,    10,     1,     3,     3,     0,     1,     1,
       1,     1,     0,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     4,     5,     6,     4,     5,
       5,     8,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     0,     3,     4,
       2
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
  "ParameterDeclaration", "type", "PrimitiveType", "Body", "Statement",
  "Returntatement", "Assignment", "RoutineCall", "WhileLoop", "ForLoop",
  "Range", "IfStatement", "Expression", "Arguments", "Primary",
  "VariableAcess", "ModifiablePrimary", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    87,    87,    88,    89,    90,    93,    94,    97,    98,
      99,   102,   105,   106,   109,   110,   113,   116,   117,   122,
     123,   124,   134,   135,   136,   137,   140,   141,   142,   143,
     144,   145,   148,   149,   152,   155,   158,   161,   164,   165,
     168,   169,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   196,
     197,   200,   201,   202,   203,   204,   205,   208,   209,   210,
     213
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
#line 1311 "parser.tab.cpp"

#line 215 "parser.ypp"

namespace yy
{
    //overriding yylex in main.cpp

    void parser::error(const std::string& msg)
    {
        std::cout<<"syntax error!\n";
    }
}
