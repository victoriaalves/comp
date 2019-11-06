#ifndef HASH_HEADER
#define HASH_HEADER
#include <stdio.h>

#define HASH_SIZE 997

#define SYMBOL_IDENTIFIER 1
#define SYMBOL_LIT_INT 2
#define SYMBOL_LIT_FLOAT 3
#define SYMBOL_LIT_CHAR 4
#define SYMBOL_LIT_STRING 5
#define SYMBOL_LIT_BOOL 6
#define SYMBOL_LIT_BYTE 7

#define SYMBOL_VAR 100
#define SYMBOL_VEC 101
#define SYMBOL_FUNC 102
#define SYMBOL_PARAM 103
#define SYMBOL_LABEL 104

#define DATATYPE_BYTE 500
#define DATATYPE_INT 501
#define DATATYPE_FLOAT 502
#define DATATYPE_BOOL 503
#define DATATYPE_LONG 505
#define DATATYPE_STRING 506
#define DATATYPE_CHAR 507
#define DATATYPE_IDENTIFIER 508
//#define DATATYPE_ERROR 509

typedef struct hash_node
{
	int type;
	int datatype;
	char *text;
	struct hash_node * next;
} HASH_NODE;

void hashInit(void);

int hashAddress(char *text);
HASH_NODE *hashFind(char *text);
HASH_NODE *hashInsert(char *text, int type);
void hashPrint(void);

int hashCheckUndeclared(void);

HASH_NODE * makeTemp(void);
HASH_NODE * makeLabel(void);

#endif
//END

