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
#line 21 "parser.ypp"

    namespace yy
    {
        parser::symbol_type yylex();
        // no need to override the error function because it is already waiting for our implementation
    }

#line 54 "parser.tab.cpp"


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
#line 127 "parser.tab.cpp"

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

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_PrimitiveType: // PrimitiveType
      case symbol_kind::S_RecordType: // RecordType
      case symbol_kind::S_ArrayType: // ArrayType
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

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_PrimitiveType: // PrimitiveType
      case symbol_kind::S_RecordType: // RecordType
      case symbol_kind::S_ArrayType: // ArrayType
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

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_PrimitiveType: // PrimitiveType
      case symbol_kind::S_RecordType: // RecordType
      case symbol_kind::S_ArrayType: // ArrayType
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

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_PrimitiveType: // PrimitiveType
      case symbol_kind::S_RecordType: // RecordType
      case symbol_kind::S_ArrayType: // ArrayType
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

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_type: // type
      case symbol_kind::S_PrimitiveType: // PrimitiveType
      case symbol_kind::S_RecordType: // RecordType
      case symbol_kind::S_ArrayType: // ArrayType
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
  case 4: // program: program SimpleDeclaration
#line 72 "parser.ypp"
                            {  }
#line 608 "parser.tab.cpp"
    break;

  case 8: // VariableDeclaration: VAR IDENTIFIER COL type
#line 80 "parser.ypp"
                                             { std::cout << "defined variable " << yystack_[2].value.as < std::string > () << " with type " << yystack_[0].value.as < std::string > (); }
#line 614 "parser.tab.cpp"
    break;

  case 11: // TypeDeclaration: TKEY IDENTIFIER IS type
#line 85 "parser.ypp"
                                         { std::cout << "defined new type " << yystack_[2].value.as < std::string > () << "\n"; }
#line 620 "parser.tab.cpp"
    break;

  case 12: // RoutineDeclaration: RUT IDENTIFIER LBR Parameters RBR IS Body END
#line 88 "parser.ypp"
                                                                  { std::cout << "routine " << yystack_[6].value.as < std::string > () << " was declared\n"; }
#line 626 "parser.tab.cpp"
    break;

  case 13: // RoutineDeclaration: RUT IDENTIFIER LBR Parameters RBR COL type IS Body END
#line 89 "parser.ypp"
                                                         {  std::cout << "routine " << yystack_[8].value.as < std::string > () << " was declared\n";  }
#line 632 "parser.tab.cpp"
    break;

  case 17: // type: IDENTIFIER
#line 99 "parser.ypp"
      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 638 "parser.tab.cpp"
    break;

  case 18: // type: PrimitiveType
#line 100 "parser.ypp"
  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 644 "parser.tab.cpp"
    break;

  case 19: // type: ArrayType
#line 101 "parser.ypp"
  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 650 "parser.tab.cpp"
    break;

  case 20: // type: RecordType
#line 102 "parser.ypp"
  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 656 "parser.tab.cpp"
    break;

  case 21: // PrimitiveType: ITYPE
#line 105 "parser.ypp"
                     { yylhs.value.as < std::string > () =  "int"; }
#line 662 "parser.tab.cpp"
    break;

  case 22: // PrimitiveType: RTYPE
#line 106 "parser.ypp"
        {              yylhs.value.as < std::string > () =  "real"; }
#line 668 "parser.tab.cpp"
    break;

  case 23: // PrimitiveType: BTYPE
#line 107 "parser.ypp"
        {              yylhs.value.as < std::string > () =  "bool"; }
#line 674 "parser.tab.cpp"
    break;

  case 24: // RecordType: RCRD VariableDeclarationBlock END
#line 110 "parser.ypp"
                                              {  yylhs.value.as < std::string > () =  "record"; std::cout << "record was defined\n"; }
#line 680 "parser.tab.cpp"
    break;

  case 25: // ArrayType: ARY LAR Expression RAR type
#line 113 "parser.ypp"
                                       {    yylhs.value.as < std::string > () = "array"; std::cout <<"array was defined\n"; }
#line 686 "parser.tab.cpp"
    break;

  case 26: // ArrayType: ARY LAR RAR type
#line 114 "parser.ypp"
                   {                        yylhs.value.as < std::string > () = "array"; std::cout << "array was defined\n"; }
#line 692 "parser.tab.cpp"
    break;

  case 36: // Statement: Returntatement
#line 128 "parser.ypp"
                 {std::cout << "return\n";}
#line 698 "parser.tab.cpp"
    break;

  case 40: // RoutineCall: IDENTIFIER LBR Arguments RBR
#line 138 "parser.ypp"
                                          { std::cout << "routine " << yystack_[3].value.as < std::string > () << " was called\n"; }
#line 704 "parser.tab.cpp"
    break;

  case 41: // WhileLoop: WHL Expression LOP Body END
#line 141 "parser.ypp"
                                       { std::cout << "while loop\n"; }
#line 710 "parser.tab.cpp"
    break;

  case 42: // ForLoop: FOR IDENTIFIER Range LOP Body END
#line 144 "parser.ypp"
                                           { std::cout << "for loop\n"; }
#line 716 "parser.tab.cpp"
    break;

  case 50: // Expression: Expression ADD Expression
#line 160 "parser.ypp"
                                      { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "+" + yystack_[0].value.as < std::string > ();  std::cout << yylhs.value.as < std::string > () << "\n";}
#line 722 "parser.tab.cpp"
    break;

  case 51: // Expression: Expression SUB Expression
#line 161 "parser.ypp"
                             {          yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "-" + yystack_[0].value.as < std::string > ();  std::cout << yylhs.value.as < std::string > () << "\n";}
#line 728 "parser.tab.cpp"
    break;

  case 52: // Expression: Expression DIV Expression
#line 162 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "/" + yystack_[0].value.as < std::string > ();  std::cout << yylhs.value.as < std::string > () << "\n";}
#line 734 "parser.tab.cpp"
    break;

  case 53: // Expression: Expression MUL Expression
#line 163 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "*" + yystack_[0].value.as < std::string > ();  std::cout << yylhs.value.as < std::string > () << "\n";}
#line 740 "parser.tab.cpp"
    break;

  case 54: // Expression: Expression MOD Expression
#line 164 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "%" + yystack_[0].value.as < std::string > ();  std::cout << yylhs.value.as < std::string > () << "\n";}
#line 746 "parser.tab.cpp"
    break;

  case 55: // Expression: Expression GRT Expression
#line 165 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + ">" + yystack_[0].value.as < std::string > ();  std::cout << yylhs.value.as < std::string > () << "\n";}
#line 752 "parser.tab.cpp"
    break;

  case 56: // Expression: Expression GRTE Expression
#line 166 "parser.ypp"
                             {          yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + ">=" + yystack_[0].value.as < std::string > (); std::cout << yylhs.value.as < std::string > () << "\n";}
#line 758 "parser.tab.cpp"
    break;

  case 57: // Expression: Expression LES Expression
#line 167 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "<" + yystack_[0].value.as < std::string > ();  std::cout << yylhs.value.as < std::string > () << "\n";}
#line 764 "parser.tab.cpp"
    break;

  case 58: // Expression: Expression LESE Expression
#line 168 "parser.ypp"
                             {          yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "<=" + yystack_[0].value.as < std::string > (); std::cout << yylhs.value.as < std::string > () << "\n";}
#line 770 "parser.tab.cpp"
    break;

  case 59: // Expression: Expression EQ Expression
#line 169 "parser.ypp"
                           {            yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "=" + yystack_[0].value.as < std::string > ();  std::cout << yylhs.value.as < std::string > () << "\n";}
#line 776 "parser.tab.cpp"
    break;

  case 60: // Expression: Expression NEQ Expression
#line 170 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "/=" + yystack_[0].value.as < std::string > (); std::cout << yylhs.value.as < std::string > () << "\n";}
#line 782 "parser.tab.cpp"
    break;

  case 61: // Expression: Expression AND Expression
#line 171 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "and" + yystack_[0].value.as < std::string > ();std::cout << yylhs.value.as < std::string > () << "\n";}
#line 788 "parser.tab.cpp"
    break;

  case 62: // Expression: Expression OR Expression
#line 172 "parser.ypp"
                           {            yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "or" + yystack_[0].value.as < std::string > (); std::cout << yylhs.value.as < std::string > () << "\n";}
#line 794 "parser.tab.cpp"
    break;

  case 63: // Expression: Expression XOR Expression
#line 173 "parser.ypp"
                            {           yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "xor" + yystack_[0].value.as < std::string > ();std::cout << yylhs.value.as < std::string > () << "\n";}
#line 800 "parser.tab.cpp"
    break;

  case 64: // Expression: SUB Expression
#line 174 "parser.ypp"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();                                 std::cout << "unary minus\n"; }
#line 806 "parser.tab.cpp"
    break;

  case 65: // Expression: Primary
#line 175 "parser.ypp"
          {  }
#line 812 "parser.tab.cpp"
    break;

  case 66: // Expression: LBR Expression RBR
#line 176 "parser.ypp"
                     { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); std::cout  << "braces around " << yylhs.value.as < std::string > () << "\n"; }
#line 818 "parser.tab.cpp"
    break;

  case 69: // Primary: INTEGER
#line 183 "parser.ypp"
                 {      yylhs.value.as < std::string > () = "integer"; }
#line 824 "parser.tab.cpp"
    break;

  case 70: // Primary: REAL
#line 184 "parser.ypp"
       {                yylhs.value.as < std::string > () = "real"; }
#line 830 "parser.tab.cpp"
    break;

  case 71: // Primary: TRU
#line 185 "parser.ypp"
      {                 yylhs.value.as < std::string > () = "true";}
#line 836 "parser.tab.cpp"
    break;

  case 72: // Primary: FLS
#line 186 "parser.ypp"
      {                 yylhs.value.as < std::string > () = "false"; }
#line 842 "parser.tab.cpp"
    break;

  case 73: // Primary: ModifiablePrimary
#line 187 "parser.ypp"
                   {    yylhs.value.as < std::string > () = "modifiablePrimary"; }
#line 848 "parser.tab.cpp"
    break;

  case 74: // Primary: RoutineCall
#line 188 "parser.ypp"
              {         yylhs.value.as < std::string > () = "routineCall"; }
#line 854 "parser.tab.cpp"
    break;

  case 78: // ModifiablePrimary: IDENTIFIER VariableAcess
#line 196 "parser.ypp"
                   { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 860 "parser.tab.cpp"
    break;


#line 864 "parser.tab.cpp"

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

  const signed char
  parser::yyr1_[] =
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

  const signed char
  parser::yyr2_[] =
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
  "LAR", "RAR", "DOTN", "ASN", "ITYPE", "RTYPE", "BTYPE", "EOL", "$accept",
  "program", "SimpleDeclaration", "VariableDeclaration", "TypeDeclaration",
  "RoutineDeclaration", "Parameters", "ParameterDeclaration", "type",
  "PrimitiveType", "RecordType", "ArrayType", "Body", "Statement",
  "Returntatement", "Assignment", "RoutineCall", "WhileLoop", "ForLoop",
  "Range", "IfStatement", "VariableDeclarationBlock", "Expression",
  "Arguments", "Primary", "VariableAcess", "ModifiablePrimary", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    70,    70,    71,    72,    73,    76,    77,    80,    81,
      82,    85,    88,    89,    92,    93,    96,    99,   100,   101,
     102,   105,   106,   107,   110,   113,   114,   117,   118,   119,
     120,   123,   124,   125,   126,   127,   128,   131,   132,   135,
     138,   141,   144,   147,   148,   151,   152,   155,   156,   157,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   179,   180,   183,
     184,   185,   186,   187,   188,   191,   192,   193,   196
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
#line 1326 "parser.tab.cpp"

#line 198 "parser.ypp"

namespace yy
{
    //overriding yylex in main.cpp

    void parser::error(const std::string& msg)
    {
        std::cout<<"syntax error!\n";
    }
}
