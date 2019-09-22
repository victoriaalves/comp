
#include "astree.h"

AST *astreeCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3){
    AST *newNode = 0;
    newNode = (AST*) calloc(1, sizeof(AST));
    newNode->symbol = symbol;
    newNode->type = type;
    newNode->son[0] = s0;
    newNode->son[1] = s1;
    newNode->son[2] = s2;
    newNode->son[3] = s3;
    return newNode;
}

void astreePrint(AST *node, int level){
    if(!node) return;

    for(int i = 0; i < level; ++i){
        fprintf(stderr, "  ");
    }

    fprintf(stderr, "AST: (");

    switch(node->type){
      // TODO definir todos os tipos aqui (que vão ser passados como param)
        case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL, \n"); break;
        case AST_ADD: fprintf(stderr, "AST_ADD, \n"); break;
        case AST_MUL: fprintf(stderr, "AST_MUL, \n"); break;
        case AST_DIV: fprintf(stderr, "AST_DIV, \n"); break;
        case AST_BOOL: fprintf(stderr, "AST_BOOL, \n"); break;
        case AST_BYTE: fprintf(stderr, "AST_BYTE, \n"); break;
        case AST_INT: fprintf(stderr, "AST_INT, \n"); break;
        case AST_LONG: fprintf(stderr, "AST_LONG, \n"); break;
        case AST_FLOAT: fprintf(stderr, "AST_FLOAT, \n"); break;
        case AST_FUNC: fprintf(stderr, "AST_FUNC, \n"); break;
        case AST_PARAM: fprintf(stderr, "AST_PARAM, \n"); break;
        case AST_ATRIB: fprintf(stderr, "AST_ATRIB, \n"); break;
        case AST_VEC: fprintf(stderr, "AST_VEC, \n"); break;
        case AST_LIT: fprintf(stderr, "AST_LIT, \n"); break;
        case AST_LLIT: fprintf(stderr, "AST_LLIT, \n"); break;
        case AST_LPARAM: fprintf(stderr, "AST_LPARAM, \n"); break;
        case AST_BLOCK: fprintf(stderr, "AST_BLOCK, \n"); break;
        case AST_LPRINT: fprintf(stderr, "AST_LPRINT, \n"); break;
        case AST_ID: fprintf(stderr, "AST_ID, \n"); break;
        case AST_VECEXP: fprintf(stderr, "AST_VECEXP, \n"); break;
        case AST_READID: fprintf(stderr, "AST_READID, \n"); break;
        case AST_READINIT: fprintf(stderr, "AST_READINIT, \n"); break;
        case AST_PRINT: fprintf(stderr, "AST_PRINT, \n"); break;
        case AST_RET: fprintf(stderr, "AST_RET, \n"); break;
        case AST_IFELSE: fprintf(stderr, "AST_IFELSE, \n"); break;
        case AST_IF: fprintf(stderr, "AST_IF, \n"); break;
        case AST_WHILE: fprintf(stderr, "AST_WHILE, \n"); break;
        case AST_FOR: fprintf(stderr, "AST_FOR, \n"); break;
        case AST_BREAK: fprintf(stderr, "AST_BREAK, \n"); break;
        case AST_CMDS: fprintf(stderr, "AST_CMDS, \n"); break;
        case AST_CFLUXO: fprintf(stderr, "AST_CFLUXO, \n"); break;
        case AST_CBLOCK: fprintf(stderr, "AST_CBLOCK, \n"); break;
        case AST_LCMD: fprintf(stderr, "AST_LCMD, \n"); break;
        case AST_CRESTO: fprintf(stderr, "AST_CRESTO, \n"); break;
        case AST_LEXPPARAM: fprintf(stderr, "AST_LEXPPARAM, \n"); break;
        case AST_EXPPARAM: fprintf(stderr, "AST_EXPPARAM, \n"); break;
        case AST_EXP: fprintf(stderr, "AST_EXP, \n"); break;
        case AST_EXPARRAY: fprintf(stderr, "AST_EXPARRAY, \n"); break;
        case AST_EXPEXP: fprintf(stderr, "AST_EXPEXP, \n"); break;
        case AST_SUB: fprintf(stderr, "AST_SUB, \n"); break;
        case AST_GREATER: fprintf(stderr, "AST_GREATER \n"); break;
        case AST_SMALLER: fprintf(stderr, "AST_SMALLER, \n"); break;
        case AST_OR: fprintf(stderr, "AST_OR, \n"); break;
        case AST_AND: fprintf(stderr, "AST_AND, \n"); break;
        case AST_NOT: fprintf(stderr, "AST_NOT, \n"); break;
        case AST_LE: fprintf(stderr, "AST_LE, \n"); break;
        case AST_GE: fprintf(stderr, "AST_GE, \n"); break;
        case AST_EQ: fprintf(stderr, "AST_EQ, \n"); break;
        case AST_DIF: fprintf(stderr, "AST_DIF, \n"); break;
        case AST_EXPPRINT: fprintf(stderr, "AST_EXPPRINT, \n"); break;
        case AST_RESTO: fprintf(stderr, "AST_EXPPRINT, \n"); break;
        case AST_LDECL: fprintf(stderr, "AST_LDECL, \n"); break;
        default: break;
    }

    if(node->symbol)
        fprintf(stderr, " %s )\n", node->symbol->text);
    else
        fprintf(stderr, " )\n");

    for(int i = 0; i < MAX_SONS; i++){
        astreePrint(node->son[i], level+1);
    }
}

