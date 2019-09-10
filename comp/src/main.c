#include <stdio.h>
#include <stdlib.h>

// Necessário declarar como extern as funções do scanner,
// que são compiladas em lex.yy.c
extern char *yytext;
extern FILE *yyin;
extern void initMe();
extern int yylex();
extern int isRunning();
extern int getLineNumber();

extern int yyparse();
extern int yyerror();

int main(int argc, char **argv)
{
  int tok, ans;
  FILE *out = NULL;


  if (argc < 2) {
    printf("Execute: ./etapa2 input.txt\n");
    exit(1);
  }

  yyin = fopen(argv[1], "r");
  if (yyin == NULL) {
    printf("Could not open file %s.\n", argv[1]);
    exit(1);
  }

  initMe();
  yyparse();
  hashPrint();

  fprintf(stderr, "Terrific! Go on!\n");

  exit(0);
}
