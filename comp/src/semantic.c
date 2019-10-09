#include "semantic.h"
#include "hash.h"
#include "astree.h"

void checkAndSetTypes(AST*node){
  if(!node) return;
  // será substituido por um switch com todos os casos
  if(node->type == AST_LDECL)
  {
    if(node->symbol->type != SYMBOL_IDENTIFIER)
    {
      fprintf(stderr, "Semantic ERROR: Symbol %s already declared.\n", node->symbol->text);
    }
    node->symbol->type = SYMBOL_VAR;
  }

  if(node->type == AST_FUNC)
  {
    if(node->symbol->type != SYMBOL_IDENTIFIER)
    {
      fprintf(stderr, "Semantic ERROR: Symbol %s already declared.\n", node->symbol->text);
    }
    node->symbol->type = SYMBOL_FUNC;
    if(node->son[0]->type == AST_INT)
      node->symbol->datatype = DATATYPE_INT;
  }

  for(int i=0; i < MAX_SONS; i++)
    checkAndSetTypes(node->son[i]);
}

void CheckUndeclared(void){
  hashCheckUndeclared();
}
