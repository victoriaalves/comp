#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "hash.h"

// Necessário declarar como extern as funções do scanner,
// que são compiladas em lex.yy.c
extern char *yytext;
extern FILE *yyin;
extern void initMe();
extern int yylex();
extern int isRunning();
extern int getLineNumber();

int main(int argc, char **argv)
{
  int tok, ans;
  FILE *out = NULL;


  if (argc < 3) {
    printf("Execute: ./etapa1 input.txt output.txt\n");
    exit(1);
  }

  yyin = fopen(argv[1], "r");
  if (yyin == NULL) {
    printf("Could not open file %s.\n", argv[1]);
    exit(1);
  }

  out = fopen(argv[2], "r");
  if (out == NULL) {
    printf("Could not open file %s.\n", argv[2]);
    exit(1);
  }

  
  initMe();
  
  while(isRunning())
  {
    tok = yylex();

    if (!isRunning())
      break;

    fscanf(out, "%d", &ans);
    
    switch(tok)
    {
      case KW_BYTE:
        fprintf(stderr, "Line %d: BYTE\n", getLineNumber()); break;
      case KW_INT:
        fprintf(stderr, "Line %d: INT\n", getLineNumber()); break;
      case KW_LONG:
        fprintf(stderr, "Line %d: LONG\n", getLineNumber()); break;
      case KW_FLOAT:
        fprintf(stderr, "Line %d: FLOAT\n", getLineNumber()); break;
      case KW_BOOL:
        fprintf(stderr, "Line %d: BOOL\n", getLineNumber()); break;
      case KW_IF:
        fprintf(stderr, "Line %d: IF\n", getLineNumber()); break;
      case KW_THEN:
        fprintf(stderr, "Line %d: THEN\n", getLineNumber()); break;
      case KW_ELSE:
        fprintf(stderr, "Line %d: ELSE\n", getLineNumber()); break;
      case KW_WHILE:
        fprintf(stderr, "Line %d: WHILE\n", getLineNumber()); break;
      case KW_FOR:
        fprintf(stderr, "Line %d: FOR\n", getLineNumber()); break;
      case KW_READ:
        fprintf(stderr, "Line %d: READ\n", getLineNumber()); break;
      case KW_PRINT:
        fprintf(stderr, "Line %d: PRINT\n", getLineNumber()); break;
      case KW_RETURN:
        fprintf(stderr, "Line %d: RETURN\n", getLineNumber()); break;
      case KW_BREAK:
        fprintf(stderr, "Line %d: BREAK\n", getLineNumber()); break;

      case OPERATOR_LE:
        fprintf(stderr, "Line %d: <=\n", getLineNumber()); break;
      case OPERATOR_GE:
        fprintf(stderr, "Line %d: >=\n", getLineNumber()); break;
      case OPERATOR_EQ:
        fprintf(stderr, "Line %d: ==\n", getLineNumber()); break;
      case OPERATOR_DIF:
        fprintf(stderr, "Line %d: !=\n", getLineNumber()); break;

      case LIT_TRUE:
        fprintf(stderr, "Line %d: TRUE\n", getLineNumber()); break;
      case LIT_FALSE:
        fprintf(stderr, "Line %d: FALSE\n", getLineNumber()); break;
      case TK_IDENTIFIER:
        fprintf(stderr, "Line %d: IDENTIFIER %d\n", getLineNumber(), tok); break;
      case LIT_INTEGER:
        fprintf(stderr, "Line %d: LITERAL INTEGER\n", getLineNumber()); break;
      case LIT_FLOAT:
        fprintf(stderr, "Line %d: LITERAL FLOAT\n", getLineNumber()); break;

      case LIT_CHAR:
        fprintf(stderr, "Line %d: LITERAL CHAR %d\n", getLineNumber(), tok); break;
      case LIT_STRING:
        fprintf(stderr, "Line %d: LITERAL STRING %d\n", getLineNumber(), tok); break;
      case TOKEN_ERROR:
        fprintf(stderr, "Line %d: ERROR %d\n", getLineNumber(), tok); break;

      default:
        fprintf(stderr, "Line %d: TOKEN ASCII %d\n", getLineNumber(), tok); break;
    }

    if (tok == ans) {
      fprintf(stderr, "Line %d: Ok\n", getLineNumber());
    }
    else {
      fprintf(stderr, "**** Line %d: %d\n", getLineNumber(), *yytext);
    }

  }
  hashPrint();
}
