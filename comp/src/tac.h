#ifndef TAC_HEADER
#define TAC_HEADER

#include "hash.h"
#include "astree.h"

#define TAC_SYMBOL   1
#define TAC_ADD      2
#define TAC_SUB      3
#define TAC_MUL      4
#define TAC_DIV      5
#define TAC_MOVE     6
#define TAC_IFZ      7
#define TAC_LABEL    8
#define TAC_GREATER  9
#define TAC_SMALLER  10
#define TAC_AND      11
#define TAC_OR       12
#define TAC_NOT      13
#define TAC_GE       14
#define TAC_LE       15
#define TAC_EQ       16
#define TAC_DIF      17
#define TAC_JUMP     18
#define TAC_PRINT    19
#define TAC_RETURN   20
#define TAC_READ     21
#define TAC_VECEXP   22
#define TAC_VEC      23
#define TAC_BEGINFUN 24
#define TAC_ENDFUN   25
#define TAC_FUNCCALL 26
#define TAC_FOR      29
#define TAC_BREAK    30
#define TAC_JUMPFOR  31
#define TAC_EXP      32

typedef struct tac_node{
    int type;
    HASH_NODE *res;
    HASH_NODE *op1;
    HASH_NODE *op2;

    struct tac_node *prev;
    struct tac_node *next;
} TAC;

TAC* tacCreate(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2);
void tacPrintSingle(TAC *tac);
void tacPrintBackwards(TAC *tac);
TAC* generateCode(AST *ast, HASH_NODE* label, HASH_NODE* labelJump);
TAC* tacJoin(TAC* tac1, TAC* tac2);
void createASM(AST *ast, TAC *tac);
void addData(AST *ast, FILE *out);

#endif
