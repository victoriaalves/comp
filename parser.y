%{
  #include <stdio.h>
  #include <stdlib.h>

  #define SYMBOL_LIT_INT              1
  #define SYMBOL_LIT_REAL             2
  #define SYMBOL_LIT_TRUE             3
  #define SYMBOL_LIT_FALSE            4
  #define SYMBOL_LIT_CHAR             5
  #define SYMBOL_LIT_STRING           6
  #define SYMBOL_IDENTIFIER           7
%}

%token KW_BYTE
%token KW_INT
%token KW_LONG
%token KW_FLOAT
%token KW_BOOL

%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_READ
%token KW_PRINT
%token KW_RETURN
%token KW_BREAK

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_DIF

%token TK_IDENTIFIER

%token LIT_INTEGER
%token LIT_FLOAT
%token LIT_TRUE
%token LIT_FALSE
%token LIT_CHAR
%token LIT_STRING

%%

programa: programa decl
  |
  ;

decl: vardec | fundec
  ;

vardec: KW_INT TK_IDENTIFIER '=' init ';'
  ;

init: LIT_INTEGER
  ;

fundec: KW_INT TK_IDENTIFIER '(' parlist ')' cmd
  ;

parlist: par resto
  |
  ;

resto: ',' par resto
  |
  ;

par: KW_INT
  ;

block: '{' lcmd '}'
  ;

cmd: TK_IDENTIFIER '=' LIT_FLOAT
  | block
  |
  ;

lcmd: cmd cmdrest
  ;

cmdrest: ';' cmd cmdrest
  |
  ;

%%

int yyerror(const char *msg){
  fprintf(stderr, "Deu error de sintaxe!\n");
  printf("Linha %d [erro de sintaxe]: %s.\n", getLineNumber(), msg);
  exit(3);
}
