#ifndef HASH_HEADER
#define HASH_HEADER
#include <stdio.h>

#define HASH_SIZE 997

#define SYMBOL_IDENTIFIER 1
#define SYMBOL_LIT_INT 2
#define SYMBOL_LIT_FLOAT 3
#define SYMBOL_LIT_CHAR 4
#define SYMBOL_LIT_STRING 5

#define SYMBOL_VAR 6
#define SYMBOL_VEC 7
#define SYMBOL_FUNC 8
#define SYMBOL_PARAM 9

#define DATATYPE_BYTE 10
#define DATATYPE_INT 11
#define DATATYPE_FLOAT 12
#define DATATYPE_BOOL 13

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

#endif
//END

