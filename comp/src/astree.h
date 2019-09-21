#ifndef AST_HEADER
#define AST_HEADER

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_MUL 3
#define AST_BOOL 4
#define AST_BYTE 5
#define AST_INT 6 
#define AST_LONG 7
#define AST_FLOAT 8
#define AST_FUNC 9
#define AST_PARAM 10
#define AST_ATRIB 11
#define AST_VEC 12
#define AST_LIT 13 // um elemento do vector
#define AST_LLIT 14 // lista de elementos do vector
#define AST_LPARAM 15
#define AST_BLOCK 16
#define AST_LPRINT 17
#define AST_ID 18
#define AST_VECEXP 19
#define AST_READID 20
#define AST_READINIT 21
#define AST_PRINT 22
#define AST_RET 23
#define AST_IFELSE 24
#define AST_IF 25
#define AST_WHILE 26
#define AST_FOR 27
#define AST_BREAK 28
#define AST_CMDS 29
#define AST_CFLUXO 30
#define AST_CBLOCK 31
#define AST_LCMD 32
#define AST_CRESTO 33
#define AST_LEXPPARAM 34
#define AST_EXPPARAM 35
#define AST_EXP 36
#define AST_EXPARRAY 37
#define AST_EXPEXP 38
#define AST_SUB 39
#define AST_DIV 40
#define AST_GREATER 41
#define AST_SMALLER 42
#define AST_OR 43
#define AST_AND 44
#define AST_NOT 45
#define AST_LE 46
#define AST_GE 47
#define AST_EQ 48
#define AST_DIF 49

#define MAX_SONS 4

typedef struct astree_node{
    int type;
    HASH_NODE *symbol;
    struct astree_node *son[MAX_SONS];
} AST;

AST *astreeCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3);
void astreePrint(AST *node, int level);
void nodePrint(AST *node);

#endif
