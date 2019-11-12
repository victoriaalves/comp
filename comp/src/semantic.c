#include "semantic.h"
#include "hash.h"
#include "astree.h"

#include <string.h>

extern AST*getAST();

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

void checkFunctions(AST*node){
  AST* declaration = findFunctionDeclaration(node->symbol->text, getAST());
  if(declaration == NULL){
    fprintf(stderr, "Semantic ERROR in line %d: Only functions can be called.\n", node->line);
    semanticErrors++;
  }

  int numberOfArgumentsCalled= getNumberOfArguments(node->son[1]);
  int numberOfArgumentsDeclared = getNumberOfArguments(declaration->son[1]);
  if(numberOfArgumentsCalled != numberOfArgumentsDeclared){
    fprintf(stderr, "Semantic ERROR in line %d: Incompatible number of arguments.\n", node->line);
    semanticErrors++;
  }
  else {
    //compareArguments(node->son[1], declaration->son[1]);
    fprintf(stderr, "fine\n");
  }
}

AST* findFunctionDeclaration(char * name, AST * node){
  if(node->symbol != NULL && node->type == AST_FUNC && strcmp(node->symbol->text, name) == 0)
    return node;

  for(int i = 0; i < MAX_SONS; i++){
    if (node->son[i] == NULL)
      return NULL;
    AST * finding = findFunctionDeclaration(name, node->son[i]) ;
    if(finding != NULL)
      return finding;
  }
  return NULL;
}

int getNumberOfArguments(AST * node){
  if(node == NULL) return 0;
  if(node->son[1] != NULL)
    return 1 + getNumberOfArguments(node->son[1]);
  else
    return 0;
}

void compareArguments(AST *node, AST *declaration){
  if(node->son[0] != NULL){
    if(node->son[0]->type != declaration->son[0]->symbol->datatype) {
      fprintf(stderr, "Semantic ERROR: Incompatible argument types at line %d\n", node->line);
      semanticErrors++;
    }
    if(node->son[1] != NULL)
      compareArguments(node->son[1], declaration->son[1]);
  }
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

      if(node->type == AST_PARAM)
        node->symbol->type = SYMBOL_PARAM;

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
      node->type = AST_BOOL;
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
      node->type = AST_BOOL;
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
       if (node->son[0]->type == AST_SYMBOL ||
           node->son[0]->type == AST_EXP ||
           node->son[0]->type == AST_EXPARRAY ||
           node->son[0]->type == AST_FUNCALL ||
           node->son[0]->type == AST_ADD ||
           node->son[0]->type == AST_SUB ||
           node->son[0]->type == AST_MUL ||
           node->son[0]->type == AST_DIV ||
           node->son[0]->type == AST_GREATER ||
           node->son[0]->type == AST_SMALLER ||
           node->son[0]->type == AST_OR ||
           node->son[0]->type == AST_AND ||
           node->son[0]->type == AST_NOT ||
           node->son[0]->type == AST_LE ||
           node->son[0]->type == AST_GE ||
           node->son[0]->type == AST_EQ ||
           node->son[0]->type == AST_DIF
           ) {
         // tudo certo
      }
      else {
        fprintf(stderr, "Semantic ERROR in %d: operands not compatible, error at line %d.\n", node->son[0]->type, node->line);
        semanticErrors++;
        node->type = AST_ERROR;
      }
      break;

    case AST_AND:
    case AST_OR:
      node->type = AST_BOOL;
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
      if (node->son[0]->type == AST_LPRINT) {
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

    case AST_FUNC:
      if (node->son[0]->type == AST_INT ||
          node->son[0]->type == AST_LONG ||
          node->son[0]->type == AST_FLOAT ||
          node->son[0]->type == AST_BYTE) {
        if (node->son[1] != NULL) {
          AST* parlista = node->son[1];
          while (parlista != NULL) {
            if (parlista->son[0]->type == AST_VEC) {
              // se o primeiro argumento é vetor, dá erro
              fprintf(stderr, "Semantic ERROR: Functions cannot have arrays as arguments, error at line %d.\n", node->line);
              semanticErrors++;
              node->type = AST_ERROR;
              break;
            }
            else {
              // se não for vetor, vai para o próximo argumento
              if (parlista->son[1] != NULL){
                parlista = parlista->son[1]->son[0];
              }
              else parlista = NULL;
            }
          }
        }
      }
      else {
        fprintf(stderr, "Semantic ERROR: Invalid function type, error at line %d.\n", node->line);
        semanticErrors++;
        node->type = AST_ERROR;
      }
      break;


    case AST_FUNCALL:
      //checkFunctions(node);
      break;

    case AST_VEC:
      if ((node->son[0]->type == AST_BOOL ||
            node->son[0]->type == AST_BYTE ||
            node->son[0]->type == AST_FLOAT ||
            node->son[0]->type == AST_INT ||
            node->son[0]->type == AST_LONG) ) {
        // TODO arrumar pq int vec[3] : 3 4 5; não funciona

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
