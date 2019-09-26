#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

// Necessário declarar como extern as funções do scanner,
// que são compiladas em lex.yy.c
extern char *yytext;
extern FILE *yyin;
extern void initMe();
extern int yylex();
extern int isRunning();
extern int getLineNumber();
extern AST* getAST();

extern int yyparse();
extern int yyerror();

int main(int argc, char **argv)
{
  FILE *out;

  if (argc < 3) { // < 3
    printf("Execute: ./etapa2 input.txt\n"); //printf("Execute: ./etapa2 input.txt  output.txt\\n");
    exit(1);
  }

  yyin = fopen(argv[1], "r");
  if (yyin == NULL) {
    printf("Could not open file %s.\n", argv[1]);
    exit(1);
  }

  out = fopen(argv[2], "w+");
  if (out == NULL) {
    printf("Could not open file %s.\n", argv[2]);
    exit(1);
  }

  initMe();
  yyparse();
  //hashPrint();

  fprintf(stderr, "Compiled Successfully.\n");

  fprintf(stderr, "Uncompiling!\n");

  uncompileAST(getAST(), out);

  fclose(out);

  exit(0);
}
