
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
        case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL,"); break;
        case AST_ADD: fprintf(stderr, "AST_ADD,"); break;
        case AST_MUL: fprintf(stderr, "AST_MUL,"); break;
        case AST_DIV: fprintf(stderr, "AST_DIV,"); break;
        case AST_BOOL: fprintf(stderr, "AST_BOOL,"); break;
        case AST_BYTE: fprintf(stderr, "AST_BYTE,"); break;
        case AST_INT: fprintf(stderr, "AST_INT,"); break;
        case AST_LONG: fprintf(stderr, "AST_LONG,"); break;
        case AST_FLOAT: fprintf(stderr, "AST_FLOAT,"); break;
        case AST_FUNC: fprintf(stderr, "AST_FUNC,"); break;
        case AST_PARAM: fprintf(stderr, "AST_PARAM,"); break;
        case AST_ATRIB: fprintf(stderr, "AST_ATRIB,"); break;
        case AST_VEC: fprintf(stderr, "AST_VEC,"); break;
        case AST_LIT: fprintf(stderr, "AST_LIT,"); break;
        case AST_LLIT: fprintf(stderr, "AST_LLIT,"); break;
        case AST_LPARAM: fprintf(stderr, "AST_LPARAM,"); break;
        case AST_BLOCK: fprintf(stderr, "AST_BLOCK,"); break;
        case AST_LPRINT: fprintf(stderr, "AST_LPRINT,"); break;
        case AST_ID: fprintf(stderr, "AST_ID,"); break;
        case AST_VECEXP: fprintf(stderr, "AST_VECEXP,"); break;
        case AST_READID: fprintf(stderr, "AST_READID,"); break;
        case AST_READINIT: fprintf(stderr, "AST_READINIT,"); break;
        case AST_PRINT: fprintf(stderr, "AST_PRINT,"); break;
        case AST_RET: fprintf(stderr, "AST_RET,"); break;
        case AST_IFELSE: fprintf(stderr, "AST_IFELSE,"); break;
        case AST_IF: fprintf(stderr, "AST_IF,"); break;
        case AST_WHILE: fprintf(stderr, "AST_WHILE,"); break;
        case AST_FOR: fprintf(stderr, "AST_FOR,"); break;
        case AST_BREAK: fprintf(stderr, "AST_BREAK,"); break;
        case AST_CMDS: fprintf(stderr, "AST_CMDS,"); break;
        case AST_CFLUXO: fprintf(stderr, "AST_CFLUXO,"); break;
        case AST_CBLOCK: fprintf(stderr, "AST_CBLOCK,"); break;
        case AST_LCMD: fprintf(stderr, "AST_LCMD,"); break;
        case AST_CRESTO: fprintf(stderr, "AST_CRESTO,"); break;
        case AST_LEXPPARAM: fprintf(stderr, "AST_LEXPPARAM,"); break;
        case AST_EXPPARAM: fprintf(stderr, "AST_EXPPARAM,"); break;
        case AST_EXP: fprintf(stderr, "AST_EXP,"); break;
        case AST_EXPARRAY: fprintf(stderr, "AST_EXPARRAY,"); break;
        case AST_EXPEXP: fprintf(stderr, "AST_EXPEXP,"); break;
        case AST_SUB: fprintf(stderr, "AST_SUB,"); break;
        case AST_GREATER: fprintf(stderr, "AST_GREATER,"); break;
        case AST_SMALLER: fprintf(stderr, "AST_SMALLER,"); break;
        case AST_OR: fprintf(stderr, "AST_OR,"); break;
        case AST_AND: fprintf(stderr, "AST_AND,"); break;
        case AST_NOT: fprintf(stderr, "AST_NOT,"); break;
        case AST_LE: fprintf(stderr, "AST_LE,"); break;
        case AST_GE: fprintf(stderr, "AST_GE,"); break;
        case AST_EQ: fprintf(stderr, "AST_EQ,"); break;
        case AST_DIF: fprintf(stderr, "AST_DIF,"); break;
        case AST_EXPPRINT: fprintf(stderr, "AST_EXPPRINT,"); break;
        case AST_RESTO: fprintf(stderr, "AST_EXPPRINT,"); break;
        case AST_LDECL: fprintf(stderr, "AST_LDECL,"); break;
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

