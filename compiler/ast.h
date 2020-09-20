#pragma once

#include <string>
#include<memory>

enum class NodeType {
    NUMBER,
    ADD,
    SUB,
    MULT,
    DIV,
    EQ,
    NEQ,
    MOD,
    GRT,
    GRTE,
    LES,
    LESE,
    AND,
    OR,
    XOR
};


struct ast {
    NodeType nodetype;
    struct ast *l;
    struct ast *r;
};

struct numval {
    NodeType nodetype;
    double number;
};

ast *make_ast_list();
ast *new_args();

/* build an AST */
struct ast *newast(NodeType nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);
struct ast *newfunc(int functype, struct ast *l);
struct ast *newcall(std::string *s, struct ast *l);
struct ast *newref(std::string *s);
struct ast *newac(std::string *s);
struct ast *newarr(struct ast *exp, struct ast *type);
struct ast *newp(std::string param_name, struct ast *type);
struct ast *new_var(struct ast *type, struct ast *exp);
struct ast *newasgn(std::string *s, struct ast *v);
struct ast *newtype(std::string *name, struct ast *type);
struct ast *new_routine(std::string *name, ast *parameters, struct ast *type, struct ast *body);
struct ast *newflow(NodeType nodetype, struct ast *cond, struct ast *tl, struct ast *tr);
struct ast *forloop(std::string variable, struct ast *range, struct ast *body);
struct ast *range(bool is_reverse, struct ast *start, struct ast *end);
void add_ast(ast *list, struct ast *new_node);
void add_args(ast *list, struct ast *new_node);
/* evaluate an AST */ double eval(struct ast *);

