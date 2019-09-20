%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "lex.yy.h"
  #include "hash.h"
  #include "astree.h"

  int yylex();
	int yyerror(char *message);
	extern int getLineNumber();

  #define SYMBOL_LIT_INT              1
  #define SYMBOL_LIT_REAL             2
  #define SYMBOL_LIT_TRUE             3
  #define SYMBOL_LIT_FALSE            4
  #define SYMBOL_LIT_CHAR             5
  #define SYMBOL_LIT_STRING           6
  #define SYMBOL_IDENTIFIER           7
%}

%union
{
  HASH_NODE *symbol;
  AST *ast;
}

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

%token<symbol> TK_IDENTIFIER

%token<symbol> LIT_INTEGER
%token<symbol> LIT_FLOAT
%token LIT_TRUE
%token LIT_FALSE
%token LIT_CHAR
%token LIT_STRING

%type<ast> exp

%%

programa: programa decl
  |
  ;

decl: fundec
  | global
  ;

tipo: KW_BOOL
  | KW_BYTE
  | KW_INT
  | KW_LONG
  | KW_FLOAT
  ;

initWithBool: LIT_INTEGER
  | LIT_TRUE
  | LIT_FALSE
  | LIT_FLOAT
  | LIT_CHAR
  ;

init: LIT_INTEGER
  | LIT_FLOAT
  | LIT_CHAR
  ;


global: tipo TK_IDENTIFIER '=' initWithBool ';'
  | tipo TK_IDENTIFIER '[' LIT_INTEGER ']' arrayInit ';'
  ;

arrayInit: ':' init listaLit
  |
  ;

listaLit: init listaLit
  |
  ;

fundec: tipo TK_IDENTIFIER '(' parLista ')' block
  ;

par: tipo TK_IDENTIFIER
  ;

parLista: par resto
  |
  ;

resto: ',' parLista
  |
  ;

block: '{' lcmd '}'
  ;

printLista: LIT_STRING printLista
  | exp printLista
  |
  ;

cmdSimples: TK_IDENTIFIER '=' exp {astreePrint($3, 0);}
  | TK_IDENTIFIER '[' exp ']' '=' exp
  | KW_READ TK_IDENTIFIER
  | KW_READ init
  | KW_PRINT printLista
  | KW_RETURN exp
  ;

fluxo: KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd
  | KW_IF '(' exp ')' KW_THEN cmd
  | KW_WHILE '(' exp ')' cmd
  | KW_FOR '(' TK_IDENTIFIER ':' exp ',' exp ',' exp ')' cmd
  | KW_BREAK
  ;

cmd: cmdSimples
  | fluxo
  | block
  |
  ;

lcmd: cmd cmdresto
  ;

cmdresto: ';' cmd cmdresto
  |
  ;

expParam: exp expParamResto
  ;

expParamResto: ',' expParam
  |
  ;

exp: TK_IDENTIFIER {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
  | LIT_INTEGER {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
  | LIT_TRUE
  | LIT_FALSE
  | LIT_FLOAT {$$=0;}
  | LIT_CHAR
  | '(' exp ')'
  | TK_IDENTIFIER '[' exp ']'
  | TK_IDENTIFIER '(' expParam ')'
  | exp '+' exp {$$=astreeCreate(AST_ADD, 0, $1, $3, 0, 0);}
  | exp '-' exp
  | exp '*' exp {$$=astreeCreate(AST_MUL, 0, $1, $3, 0, 0);}
  | exp '/' exp
  | exp '>' exp
  | exp '<' exp
  | exp 'v' exp
  | exp '.' exp
  | exp '~' exp
  | exp  OPERATOR_LE exp
  | exp  OPERATOR_GE exp
  | exp  OPERATOR_EQ exp
  | exp  OPERATOR_DIF exp
  ;

%%

int yyerror(char *msg){
  fprintf(stderr, "Deu error de sintaxe!\n");
  printf("Linha %d [erro de sintaxe]: %s.\n", getLineNumber(), msg);
  exit(3);
}
