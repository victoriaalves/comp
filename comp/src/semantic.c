#include "semantic.h"
#include "hash.h"
#include "astree.h"

int semanticErrors = 0;

int getSemanticErrors(){
    return semanticErrors;
}

void checkUsage(AST*node){
  if(node == NULL)
    return;

    switch (node->type){
      case AST_VARDEC:
        if(node->symbol->type != SYMBOL_VAR){
          fprintf(stderr, "Semantic ERROR: Attribution must be to a scalar variable, error at line %d.\n", node->line);
          semanticErrors++;
        }
        break;

      case AST_VECEXP:
			  if(node->son[0]->type == AST_DIV) {
          fprintf(stderr, "Semantic ERROR: Index of vector must be integer, error at line %d.\n", node->line);
          semanticErrors++;
			  } else if(node->symbol->type != SYMBOL_VEC){
          fprintf(stderr, "Semantic ERROR: Expression of vector attribution is invalid, error at line %d.\n", node->line);
          semanticErrors++;
			  }
			  break;

      case AST_VEC:
        if(node->symbol->type != SYMBOL_VEC){
          fprintf(stderr, "Semantic ERROR: Indexing only allowed for vectors, error at line %d.\n", node->line);
          semanticErrors++;
        }
        break;

      case AST_EXPARRAY:
			  if(node->son[0]->type == AST_DIV) {
          fprintf(stderr, "Semantic ERROR: Index of vector must be integer, error at line %d.\n", node->line);
          semanticErrors++;
			  }else if(node->symbol->type != SYMBOL_VEC){
          fprintf(stderr, "Semantic ERROR: Expression of access to vector is invalid, error at line %d.\n", node->line);
          semanticErrors++;
			  }
			  break;

		  case AST_EXPEXP:
			  if(node->symbol->type != SYMBOL_FUNC){
          fprintf(stderr, "Semantic ERROR: Expression of function calling is invalid, error at line %d.\n", node->line);
          semanticErrors++;
			  }
			  break;

		  case AST_READID:
			  if(node->symbol->type != SYMBOL_VAR){
          fprintf(stderr, "Semantic ERROR: Read command is invalid, only scalar values allowed, error at line %d.\n", node->line);
          semanticErrors++;
			  }
			  break;

      default:
        break;
    }

    for(int i = 0; i < MAX_SONS; i++)
		checkUsage(node->son[i]);
}

void checkAndSetTypes(AST*node){
  if(!node) return;

  if(node->type == AST_VARDEC || node->type == AST_FUNC || node->type == AST_VEC){
    if(node->symbol){
      if(node->symbol->type != SYMBOL_IDENTIFIER){
        fprintf(stderr, "Semantic ERROR: Symbol %s already declared, error at line %d.\n", node->symbol->text, node->line);
        semanticErrors++;
      }

      if(node->type == AST_VARDEC)
        node->symbol->type = SYMBOL_VAR;
      if(node->type == AST_FUNC)
        node->symbol->type = SYMBOL_FUNC;
      if(node->type == AST_VEC)
        node->symbol->type = SYMBOL_VEC;
      if(node->son[0]->type == AST_INT)
        node->symbol->datatype = DATATYPE_INT;
      if(node->son[0]->type == AST_FLOAT)
        node->symbol->datatype = DATATYPE_FLOAT;
      }
    }

  for(int i = 0; i < MAX_SONS; i++){
    checkAndSetTypes(node->son[i]);
  }
}

void checkUndeclared(){
    semanticErrors += hashCheckUndeclared();
}

void checkOperands(AST *node){
  if(!node) return;

  switch(node->type){
    case AST_ADD:
    case AST_SUB:
    case AST_MUL:
    case AST_DIV:
      // CHECK CORRECTNESS OF TWO OPERANDS
      for(int operand = 0; operand < 2; operand++) {
        if(node->son[operand]->type == AST_ADD ||
            node->son[operand]->type == AST_SUB ||
            node->son[operand]->type == AST_MUL ||
            node->son[operand]->type == AST_DIV ||
            (
              node->son[operand]->type == AST_SYMBOL &&
              node->son[operand]->symbol->type == SYMBOL_VAR &&
              node->son[operand]->symbol->datatype != DATATYPE_BOOL
            ) ||
            (
              node->son[operand]->type == AST_SYMBOL &&
              node->son[operand]->symbol->type == SYMBOL_LIT_INT
            ) ||
            (
              node->son[operand]->type == AST_SYMBOL &&
              node->son[operand]->symbol->type == SYMBOL_LIT_INT
            )
            ){
          // tudo certo
        } else {
            fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
            semanticErrors++;
            node->type = AST_ERROR;
          }
      }
    break;

    case AST_GREATER:
    case AST_SMALLER:
    case AST_LE:
    case AST_GE:
      for(int operand = 0; operand < 2; operand++) {
        if(node->son[operand]->type == AST_INT ||
            node->son[operand]->type == AST_FLOAT ||
            node->son[operand]->type == AST_BYTE ||
            node->son[operand]->type == AST_LONG ) {
          // tudo certo
        } else {
            fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
            semanticErrors++;
            node->type = AST_ERROR;
          }
      }
    break;

    case AST_DIF:
    case AST_EQ:
      for(int operand = 0; operand < 2; operand++) {
        if(node->son[operand]->symbol->datatype == AST_BOOL &&
            (node->son[operand]->type == AST_INT ||
             node->son[operand]->type == AST_FLOAT ||
             node->son[operand]->type == AST_BYTE ||
             node->son[operand]->type == AST_LONG ) ) {
          // tudo certo
        } else {
            fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
            semanticErrors++;
            node->type = AST_ERROR;
          }
      }
    break;

    case AST_WHILE:
    case AST_IFELSE:
    case AST_IF:
    case AST_NOT:
        if(node->son[0]->symbol->datatype == AST_BOOL) {
          // tudo certo
        }
        else {
            fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
            semanticErrors++;
            node->type = AST_ERROR;
        }
    break;

    case AST_AND:
    case AST_OR:
      for(int operand = 0; operand < 2; operand++) {
        if(node->son[operand]->symbol->datatype == AST_BOOL) {
          // tudo certo
        }
        else {
            fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
            semanticErrors++;
            node->type = AST_ERROR;
        }
      }
    break;

    case AST_PRINT:
      if (node->son[0]->symbol->type == AST_SYMBOL) {
        // tudo certo
      }
      else {
        fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
        semanticErrors++;
        node->type = AST_ERROR;
      }
    break;

    case AST_READID:
      if (node->son[0]->symbol->type == SYMBOL_VAR) {
        // tudo certo
      }
      else {
        fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
        semanticErrors++;
        node->type = AST_ERROR;
      }
    break;

    case AST_READINIT:
      if (node->son[0]->symbol->type == AST_INT ||
          node->son[0]->symbol->type == AST_LONG ||
          node->son[0]->symbol->type == AST_FLOAT ||
          node->son[0]->symbol->type == AST_BYTE) {
        // tudo certo
      }
      else {
        fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
        semanticErrors++;
        node->type = AST_ERROR;
      }
    break;


    case AST_VEC:
      if ((node->son[0]->type == AST_BOOL ||
          node->son[0]->type == AST_BYTE ||
          node->son[0]->type == AST_FLOAT ||
          node->son[0]->type == AST_INT ||
          node->son[0]->type == AST_LONG) &&
         (node->son[1]->symbol->type == AST_SYMBOL) ) {

      }
      else {
        fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
        semanticErrors++;
        node->type = AST_ERROR;
      }
  break;

    case AST_VECEXP:
      for(int operand = 0; operand < 2; operand++) {
        if(node->son[operand]->symbol->datatype == AST_SYMBOL) {
          // tudo certo
        }
        else {
            fprintf(stderr, "Semantic ERROR: Operands not compatible, error at line %d.\n", node->line);
            semanticErrors++;
            node->type = AST_ERROR;
        }
      }
    break;

    case AST_SYMBOL:
      node->type = node->symbol->datatype;
    break;
  }

    for(int i = 0; i < MAX_SONS; i++){
        checkOperands(node->son[i]);
    }
}
