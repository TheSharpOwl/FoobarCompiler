/* just like Unix wc */ 
%{

/* We use enum in order to reduces amount of changes needed after connecting it to bison */
enum yytokentype {
	NUMBER = 258, /* this avoids collisions with literal character tokens */
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	GRT,
	LES,
	GRTE,
	LESE,
	EQ,
	NEQ,
	AND,
	OR,
	XOR,
	IF,
	THEN,
	ELSE,
	TRU,
	FLS,
	VAR,
	SEMIC,
	TKEY,
	RUT,
	LBR,
	RBR,
	COM,
	RTN,
	IS,
	RNG,
	IN,
	REV,
	FOR,
	WHL,
	LOP,
	END,
	RCRD,
	ARY,
	LAR,
	RAR,
	ASN,
	ITYPE,
	RTYPE,
	BTYPE,
	IDENTIFIER,
	INTEGER,
	REAL,
	DOTN,
	EOL
};
int yylval;

%}
%%

"+"		{ return ADD; } 
"-"		{ return SUB; }
"*"		{ return MUL; }
"/"		{ return DIV; }
"%"		{ return MOD; }

">"		{ return GRT; }
">="	{ return GRT; }
"<" 	{ return LES; }
"<="	{ return LESE; }
"="		{ return EQ; }
"/=" 	{ return NEQ; }

"and"	{ return AND; }
"or"	{ return OR; }
"xor"	{ return XOR; }

"if"	{ return IF; }
"then"	{ return THEN; }
"else"	{ return ELSE; }

"true"	{ return TRU; }
"false"	{ return FLS; }

"var"	{ return VAR; }
":"		{ return SEMIC; }

"type"	{ return TKEY; }

"routine" {return RUT; }
"("		{ return LBR; }
")"		{ return RBR; }
","		{ return COM; }
"return" { return RTN; }
"is"	{ return IS; }

".."	{ return RNG; }
"in"	{ return IN; }
"reverse" {return REV; }

"for"	{ return FOR; }
"while"	{ return WHL; }
"loop"	{ return LOP; }
"end"	{ return END; }

"record" { return RCRD; }
"array" { return ARY; }
"["		{ return LAR; }
"]"		{ return RAR; }

":="	{ return ASN; }

"integer" {return ITYPE; }
"real"	{ return RTYPE; }
"boolean" {return BTYPE; }

[a-zA-Z_][a-zA-Z0-9_]* 	{ return IDENTIFIER; }
-?[0-9]+  				{ return INTEGER; }
-?[0-9]+\.[0-9]+ 		{ return REAL; }

"."		{ return DOTN; }

\n 		{ return EOL; }

[ \t]  {/* Ignore whitespaces and tabular signs */}
. { }

%%

const char * tok_to_string(int tok) {
		switch(tok) {
		case NUMBER: return "NUMBER";
		case ADD: return "ADD";
		case SUB: return "SUB";
		case MUL: return "MUL";
		case DIV: return "DIV";
		case MOD: return "MOD";
		case GRT: return "GRT";
		case LES: return "LES";
		case GRTE: return "GRTE";
		case LESE: return "LESE";
		case EQ: return "EQ";
		case NEQ: return "NEQ";
		case AND: return "AND";
		case OR: return "OR";
		case XOR: return "XOR";
		case IF: return "IF";
		case THEN: return "THEN";
		case ELSE: return "ELSE";
		case TRU: return "TRU";
		case FLS: return "FLS";
		case VAR: return "VAR";
		case SEMIC: return "SEMIC";
		case TKEY: return "TKEY";
		case RUT: return "RUT";
		case LBR: return "LBR";
		case RBR: return "RBR";
		case COM: return "COM";
		case RTN: return "RTN";
		case IS: return "IS";
		case RNG: return "RNG";
		case IN: return "IN";
		case REV: return "REV";
		case FOR: return "FOR";
		case WHL: return "WHL";
		case LOP: return "LOP";
		case END: return "END";
		case RCRD: return "RCRD";
		case ARY: return "ARY";
		case LAR: return "LAR";
		case RAR: return "RAR";
		case ASN: return "ASN";
		case ITYPE: return "ITYPE";
		case RTYPE: return "RTYPE";
		case BTYPE: return "BTYPE";
		case IDENTIFIER: return "IDENTIFIER";
		case INTEGER: return "INTEGER";
		case REAL: return "REAL";
		case DOTN: return "DOTN";
		case EOL: return "\n";
		default: return "UNKNOWN CHARACTER"; break;
	}
}

int main(int argc, char **argv) {
	if(argc > 1) {
		if(!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return (1);
		}
	}
	int tok;
	while((tok = yylex())) {
		printf("%s ", tok_to_string(tok));
	}
	printf("\n");
}

