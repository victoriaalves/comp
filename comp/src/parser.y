%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "lex.yy.h"
  #include "hash.h"
  #include "astree.h"
  #include "semantic.h"

  int yylex();
  int yyerror(char *message);
  extern int getLineNumber();

  AST *root;

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
%token<symbol> LIT_TRUE
%token<symbol> LIT_FALSE
%token<symbol> LIT_CHAR
%token<symbol> LIT_STRING

%type<ast> exp
%type<ast> programa
%type<ast> decl
%type<ast> fundec
%type<ast> global
%type<ast> tipo
%type<ast> initWithBool
%type<ast> init
%type<ast> arrayInit
%type<ast> listaLit
%type<ast> parLista
%type<ast> par
%type<ast> block
%type<ast> resto
%type<ast> printLista
%type<ast> cmdSimples
%type<ast> fluxo
%type<ast> cmd
%type<ast> lcmd
%type<ast> cmdresto
%type<ast> expParam
%type<ast> expParamResto
%type<ast> ldecl

%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left 'v' '.' '~'
%left '+' '-'
%left '*' '/'

%start programa

%%

programa: ldecl                                                 {root = $1;
                                                                astreePrint($1, 0);
                                                                }
  ;

ldecl: decl ldecl                                               {$$=astreeCreate(AST_LDECL, 0, $1, $2, 0, 0, getLineNumber());}
  |                                                             {$$=0;}
  ;

decl: fundec
  | global
  ;

tipo: KW_BOOL                                                   {$$=astreeCreate(AST_BOOL, 0, 0, 0, 0, 0, getLineNumber());}
  | KW_BYTE                                                     {$$=astreeCreate(AST_BYTE, 0, 0, 0, 0, 0, getLineNumber());}
  | KW_INT                                                      {$$=astreeCreate(AST_INT, 0, 0, 0, 0, 0, getLineNumber());}
  | KW_LONG                                                     {$$=astreeCreate(AST_LONG, 0, 0, 0, 0, 0, getLineNumber());}
  | KW_FLOAT                                                    {$$=astreeCreate(AST_FLOAT, 0, 0, 0, 0, 0, getLineNumber());}
  ;

initWithBool: LIT_INTEGER                                       {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_TRUE                                                    {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_FALSE                                                   {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_FLOAT                                                   {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_CHAR                                                    {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  ;

init: LIT_INTEGER                                               {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_FLOAT                                                   {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_CHAR                                                    {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  ;


global: tipo TK_IDENTIFIER '=' initWithBool ';'                 {$$=astreeCreate(AST_VARDEC, $2, $1, $4, 0, 0, getLineNumber());}
  | tipo TK_IDENTIFIER '[' LIT_INTEGER ']' arrayInit ';'        {$$=astreeCreate(AST_VEC, $2, $1, astreeCreate(AST_SYMBOL, $4, 0, 0, 0, 0, getLineNumber()), $6, 0, getLineNumber());}
  ;

arrayInit: ':' init listaLit                                    {$$=astreeCreate(AST_LIT, 0, $2, $3, 0, 0, getLineNumber());}
  |                                                             {$$=0;}
  ;

listaLit: init listaLit                                         {$$=astreeCreate(AST_LLIT, 0, $1, $2, 0, 0, getLineNumber());}
  |                                                             {$$=0;}
  ;

fundec: tipo TK_IDENTIFIER '(' parLista ')' block               {$$=astreeCreate(AST_FUNC, $2, $1, $4, $6, 0, getLineNumber());}
  ;

par: tipo TK_IDENTIFIER                                         {$$=astreeCreate(AST_PARAM, $2, $1, 0, 0, 0, getLineNumber());}
  ;

parLista: par resto                                             {$$=astreeCreate(AST_LPARAM, 0, $1, $2, 0, 0, getLineNumber());}
  |                                                             {$$=0;}
  ;

resto: ',' parLista                                             {$$=astreeCreate(AST_RESTO, 0, $2, 0, 0, 0, getLineNumber());}
  |                                                             {$$=0;}
  ;

block: '{' lcmd '}'                                             {$$=astreeCreate(AST_BLOCK, 0, $2, 0, 0, 0, getLineNumber());}
  ;

printLista: LIT_STRING printLista                               {$$=astreeCreate(AST_LPRINT, 0, astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber()), $2, 0, 0, getLineNumber());}
  | exp printLista                                              {$$=astreeCreate(AST_EXPPRINT, 0, $1, $2, 0, 0, getLineNumber());}
  |                                                             {$$=0;}
  ;

cmdSimples: TK_IDENTIFIER '=' exp                               {$$=astreeCreate(AST_ID, $1, $3, 0, 0, 0, getLineNumber());}
  | TK_IDENTIFIER '[' exp ']' '=' exp                           {$$=astreeCreate(AST_VECEXP, $1, $3, $6, 0, 0, getLineNumber());}
  | KW_READ TK_IDENTIFIER                                       {$$=astreeCreate(AST_READID, 0, astreeCreate(AST_SYMBOL, $2, 0, 0, 0, 0, getLineNumber()), 0, 0, 0, getLineNumber());}
  | KW_READ init                                                {$$=astreeCreate(AST_READINIT, 0, $2, 0, 0, 0, getLineNumber());}
  | KW_PRINT printLista                                         {$$=astreeCreate(AST_PRINT, 0, $2, 0, 0, 0, getLineNumber());}
  | KW_RETURN exp                                               {$$=astreeCreate(AST_RET, 0, $2, 0, 0, 0, getLineNumber());}
  ;

fluxo: KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd                {$$=astreeCreate(AST_IFELSE, 0, $3, $6, $8, 0, getLineNumber());}
  | KW_IF '(' exp ')' KW_THEN cmd                               {$$=astreeCreate(AST_IF, 0, $3, $6, 0, 0, getLineNumber());}
  | KW_WHILE '(' exp ')' cmd                                    {$$=astreeCreate(AST_WHILE, 0, $3, $5, 0, 0, getLineNumber());}
  | KW_FOR '(' TK_IDENTIFIER '=' exp ',' exp ',' exp ')' cmd    {$$=astreeCreate(AST_FOR, $3, $5, $7, $9, $11, getLineNumber());}
  | KW_BREAK                                                    {$$=astreeCreate(AST_BREAK, 0, 0, 0, 0, 0, getLineNumber());}
  ;

cmd: cmdSimples                                                 {$$=astreeCreate(AST_CMDS, 0, $1, 0, 0, 0, getLineNumber());}
  | fluxo                                                       {$$=astreeCreate(AST_CFLUXO, 0, $1, 0, 0, 0, getLineNumber());}
  | block                                                       {$$=astreeCreate(AST_CBLOCK, 0, $1, 0, 0, 0, getLineNumber());}
  |                                                             {$$=0;}
  ;

lcmd: cmd cmdresto                                              {$$=astreeCreate(AST_LCMD, 0, $1, $2, 0, 0, getLineNumber());}
  ;

cmdresto: ';' cmd cmdresto                                      {$$=astreeCreate(AST_CRESTO, 0, $2, $3, 0, 0, getLineNumber());}
  |                                                             {$$=0;}
  ;

expParam: exp expParamResto                                     {$$=astreeCreate(AST_LEXPPARAM, 0, $1, $2, 0, 0, getLineNumber());}
  ;

expParamResto: ',' expParam                                     {$$=astreeCreate(AST_EXPPARAM, 0, $2, 0, 0, 0, getLineNumber());}
  |                                                             {$$=0;}
  ;

exp: TK_IDENTIFIER                                              {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_INTEGER                                                 {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_TRUE                                                    {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_FALSE                                                   {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_FLOAT                                                   {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | LIT_CHAR                                                    {$$=astreeCreate(AST_SYMBOL, $1, 0, 0, 0, 0, getLineNumber());}
  | '(' exp ')'                                                 {$$=astreeCreate(AST_EXP, 0, $2, 0, 0, 0, getLineNumber());}
  | TK_IDENTIFIER '[' exp ']'                                   {$$=astreeCreate(AST_EXPARRAY, $1, $3, 0, 0, 0, getLineNumber());}
  | TK_IDENTIFIER '(' expParam ')'                              {$$=astreeCreate(AST_EXPEXP, $1, $3, 0, 0, 0, getLineNumber());}
  | exp '+' exp                                                 {$$=astreeCreate(AST_ADD, 0, $1, $3, 0, 0, getLineNumber());}
  | exp '-' exp                                                 {$$=astreeCreate(AST_SUB, 0, $1, $3, 0, 0, getLineNumber());}
  | exp '*' exp                                                 {$$=astreeCreate(AST_MUL, 0, $1, $3, 0, 0, getLineNumber());}
  | exp '/' exp                                                 {$$=astreeCreate(AST_DIV, 0, $1, $3, 0, 0, getLineNumber());}
  | exp '>' exp                                                 {$$=astreeCreate(AST_GREATER, 0, $1, $3, 0, 0, getLineNumber());}
  | exp '<' exp                                                 {$$=astreeCreate(AST_SMALLER, 0, $1, $3, 0, 0, getLineNumber());}
  | exp 'v' exp                                                 {$$=astreeCreate(AST_OR, 0, $1, $3, 0, 0, getLineNumber());}
  | exp '.' exp                                                 {$$=astreeCreate(AST_AND, 0, $1, $3, 0, 0, getLineNumber());}
  | exp '~' exp                                                 {$$=astreeCreate(AST_NOT, 0, $1, $3, 0, 0, getLineNumber());}
  | exp  OPERATOR_LE exp                                        {$$=astreeCreate(AST_LE, 0, $1, $3, 0, 0, getLineNumber());}
  | exp  OPERATOR_GE exp                                        {$$=astreeCreate(AST_GE, 0, $1, $3, 0, 0, getLineNumber());}
  | exp  OPERATOR_EQ exp                                        {$$=astreeCreate(AST_EQ, 0, $1, $3, 0, 0, getLineNumber());}
  | exp  OPERATOR_DIF exp                                       {$$=astreeCreate(AST_DIF, 0, $1, $3, 0, 0, getLineNumber());}
  ;

%%

int yyerror(char *msg){
  fprintf(stderr, "Deu error de sintaxe!\n");
  printf("Linha %d [erro de sintaxe]: %s.\n", getLineNumber(), msg);
  exit(3);
}

int checkSemantic() {
  fprintf(stderr, "Checking semantic.\n");
  
  checkAndSetTypes(root);
  hashCheckUndeclared();
  checkOperands(root);
  
  fprintf(stderr, "%d semantic errors.\n", getSemanticErrors());
  if (getSemanticErrors() != 0) {
    exit(4);
  }
  return 0;
}


AST* getAST(){
	return root;
}
