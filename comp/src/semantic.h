#include "astree.h"
#include "hash.h"
#include <stdio.h>

void checkAndSetTypes(AST*node);
void checkOperands(AST *node);
void checkUndeclared();
int getSemanticErrors();
void checkUsage(AST *node);
void compareArguments(AST *node, AST *declaration);
int getNumberOfArguments(AST * node);
AST* findFunctionDeclaration(char * name, AST * node);
void checkFunctions(AST*node);
