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

int hashAddress(char *text)
{
	int address = 1;
	for(int i=0; i<strlen(text); i++)
		address = (address * text[i]) % HASH_SIZE + 1;
	return address-1;
}

HASH_NODE *hashFind(char *text)
{
	int address = hashAddress(text);
	HASH_NODE* node;
	for(node=Table[address]; node; node = node->next)
		if(!strcmp(text,node->text))
			return node;

	return 0;
}

HASH_NODE *hashInsert(char *text, int type)
{
	HASH_NODE *newnode;
	if((newnode = hashFind(text))!=0)
		return newnode;

	int address = hashAddress(text);
	newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
	newnode-> type = type;
	newnode-> text = (char*) calloc(strlen(text)+1, sizeof(char));
	strcpy(newnode->text, text);
	newnode-> next = Table[address];
	Table[address] = newnode;

	return newnode;
}

void hashPrint(void)
{
	HASH_NODE *node;
	for(int i=0; i<HASH_SIZE; i++)
		for(node=Table[i]; node; node = node->next)
			printf("[Table %d] has %s\n", i, Table[i]->text);
}

int hashCheckUndeclared(void){
  HASH_NODE *node;
  int error = 0;
  for(int i=0; i<HASH_SIZE; i++) {
    for(node=Table[i]; node; node = node->next)
      if(node->type == SYMBOL_IDENTIFIER){
        fprintf(stderr,"Undeclared identifier %s\n", Table[i]->text);
        error++;
      }
  }
  return error;
}

HASH_NODE * makeTemp(void){
	static int serialNumber = 0;
	static char name[100];

	sprintf(name, "temp%d", serialNumber++);
	return hashInsert(name,0);
}

//END
