
#include "ast.h"

struct ast * newast(NodeType nodetype, struct ast *l, struct ast *r)
{
    auto *a = static_cast<ast *>(malloc(sizeof(struct ast)));
    if(!a) {
        exit(0); }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}


struct ast * newnum(double d) {
    auto *a = static_cast<numval *>(malloc(sizeof(struct numval)));
    if(!a) {
        exit(0); }
    a->nodetype = NodeType::NUMBER;
    a->number = d;
    return (struct ast *)a;
}


double eval(struct ast *a) {
    double v = 0;
    switch(a->nodetype) {
        case NodeType::NUMBER: v = ((struct numval *)a)->number; break;
        case NodeType::ADD: v = eval(a->l) + eval(a->r); break;
        case NodeType::SUB: v = eval(a->l) - eval(a->r); break;
        case NodeType::MULT: v = eval(a->l) * eval(a->r); break;
        case NodeType::DIV: v = eval(a->l) / eval(a->r); break;
        case NodeType::MOD: v = (int)eval(a->l) % (int)eval(a->r); break;
        case NodeType::EQ: v = (int)eval(a->l) == (int)eval(a->r); break;
        case NodeType::NEQ: v = (int)eval(a->l) != (int)eval(a->r); break;
        case NodeType::GRT: v = (int)eval(a->l) > (int)eval(a->r); break;
        case NodeType::GRTE: v = (int)eval(a->l) >= (int)eval(a->r); break;
        case NodeType::LES: v = (int)eval(a->l) < (int)eval(a->r); break;
        case NodeType::LESE: v = (int)eval(a->l) <= (int)eval(a->r); break;
        case NodeType::AND: v = (int)eval(a->l) && (int)eval(a->r); break;
        case NodeType::OR: v = (int)eval(a->l) || (int)eval(a->r); break;
        case NodeType::XOR: v = (unsigned int)eval(a->l) ^ (unsigned int)eval(a->r); break;
        default: printf("internal error: bad node %d\n", a->nodetype); }
    return v;
}