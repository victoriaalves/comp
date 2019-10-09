#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

HASH_NODE*Table[HASH_SIZE];

void hashInit(void)
{
	for (int i=0; i<HASH_SIZE; i++)
		Table[i]=0;
}

int hashAdress(char *text)
{
	int adress = 1;
	for(int i=0; i<strlen(text); i++)
		adress = (adress * text[i]) % HASH_SIZE + 1;
	return adress-1;
}

HASH_NODE *hashFind(char *text)
{
	return 0;
}

HASH_NODE *hashInsert(char *text, int type)
{
	HASH_NODE *newnode;
	int adress = hashAdress(text);
	newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
	newnode-> type = type;
	newnode-> text = (char*) calloc(strlen(text)+1, sizeof(char));
	strcpy(newnode->text, text);
	newnode-> next = Table[adress];
	Table[adress] = newnode;

	return newnode;
}

void hashPrint(void)
{
	HASH_NODE *node;
	for(int i=0; i<HASH_SIZE; i++)
		for(node=Table[i]; node; node = node->next)
			printf("[Table %d] has %s\n", i, node->text);
}

//END
