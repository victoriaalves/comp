#include "tac.h"

TAC* makeBinOperation(int type, TAC* code0, TAC* code1);
TAC* makeIfThen(TAC* code0, TAC* code1);
TAC* makeIfThenElse(TAC* code0, TAC* code1, TAC* code2);
TAC* makeWhile(TAC* code0, TAC* code1, HASH_NODE* newlabel1, HASH_NODE* newlabel2);
TAC* makeFunc(TAC* code0, TAC* code1, TAC* code2);
TAC* makeFor(TAC* code0, TAC* code1, TAC* code2, TAC* code3, TAC* code4, HASH_NODE* forLabel, HASH_NODE* jumpLabel);
TAC* makeExp(TAC* code);
TAC* makeReturn(TAC* code0);

TAC* tacCreate(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2){
  TAC* newTac;
  newTac = (TAC*) calloc(1, sizeof(TAC));
  newTac->type = type;
  newTac->res = res;
  newTac->op1 = op1;
  newTac->op2 = op2;
  newTac->prev = 0;
  newTac->next = 0;

  return newTac;
}

TAC* generateCode(AST *ast, HASH_NODE* label, HASH_NODE* labelJump){
  if(!ast) return 0;

  TAC* code[MAX_SONS];

  if(ast->type == AST_WHILE || ast->type == AST_FOR
      || ast->type == AST_IF || ast->type == AST_IFELSE) {
    label = makeLabel();
    labelJump = makeLabel();
  }

  // generateCode for children first
  for(int i = 0; i < MAX_SONS; i++)
    code[i] = generateCode(ast->son[i], label, labelJump);

  // then itself
  switch(ast->type){
    case AST_SYMBOL: return tacCreate(TAC_SYMBOL, ast->symbol, 0, 0);
    case AST_ASS: return tacJoin(code[0],tacCreate(TAC_MOVE,ast->symbol,code[0]?code[0]->res:0,0));
    case AST_ADD: return makeBinOperation(TAC_ADD, code[0], code[1]);
    case AST_SUB: return makeBinOperation(TAC_SUB, code[0], code[1]);
    case AST_MUL: return makeBinOperation(TAC_MUL, code[0], code[1]);
    case AST_DIV: return makeBinOperation(TAC_DIV, code[0], code[1]);
    case AST_GREATER: return makeBinOperation(TAC_GREATER, code[0], code[1]);
    case AST_SMALLER: return makeBinOperation(TAC_SMALLER, code[0], code[1]);
    case AST_AND: return makeBinOperation(TAC_AND, code[0], code[1]);
    case AST_OR: return makeBinOperation(TAC_OR, code[0], code[1]);
    case AST_NOT: return makeBinOperation(TAC_NOT, code[0], code[1]);
    case AST_GE: return makeBinOperation(TAC_GE, code[0], code[1]);
    case AST_LE: return makeBinOperation(TAC_LE, code[0], code[1]);
    case AST_EQ: return makeBinOperation(TAC_EQ, code[0], code[1]);
    case AST_DIF: return makeBinOperation(TAC_DIF, code[0], code[1]);
    case AST_IF: return makeIfThen(code[0], code[1]);
    case AST_IFELSE: return makeIfThenElse(code[0], code[1], code[2]);
    case AST_WHILE: return makeWhile(code[0], code[1], label, labelJump);
    case AST_LPRINT:
    case AST_EXPPRINT: return tacJoin(tacJoin(code[0], tacCreate(TAC_PRINT,ast->symbol, code[0]?code[0]->res:0,0)), code[1]);
    case AST_READID:
    case AST_READINIT: return tacCreate(TAC_READ, ast->son[0]->symbol,0,0);
    case AST_VECEXP: return tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_VECEXP, ast->symbol, code[0]?code[0]->res:0, code[1]?code[1]->res:0)));
    case AST_EXPARRAY: return tacJoin(code[0], tacCreate(TAC_VEC, makeTemp(), ast->symbol, code[0]?code[0]->res:0));
    case AST_FUNCALL: return tacJoin(code[0], tacCreate(TAC_FUNCCALL, makeTemp(), ast->symbol, 0));
    case AST_RESTO: return code[0];
    case AST_FUNC:return makeFunc(tacCreate(TAC_SYMBOL, ast->symbol, 0, 0), code[1], code[2]);
    case AST_FOR: return makeFor(tacCreate(TAC_SYMBOL, ast->symbol, 0, 0), code[0], code[1], code[2], code[3], label, labelJump);
    case AST_RET: return makeReturn(code[0]);
    case AST_BREAK: return tacCreate(TAC_BREAK, labelJump, 0, 0);

    default: return tacJoin(tacJoin(tacJoin(code[0], code[1]), code[2]), code[3]);
  }
}

TAC* makeBinOperation(int type, TAC* code0, TAC* code1){
  return tacJoin(
      tacJoin(code0,
        code1),
      tacCreate(type,
        makeTemp(),
        code0? code0->res : 0,
        code1? code1->res : 0));
}

TAC* makeIfThen(TAC* code0, TAC* code1){
  HASH_NODE *label = 0;
  TAC *tacif = 0;
  TAC *taclabel = 0;

  label = makeLabel();
  tacif = tacCreate(TAC_IFZ, label, code0?code0->res:0,0);
  taclabel = tacCreate(TAC_LABEL, label, 0, 0);

  return tacJoin(tacJoin(tacJoin(code0, tacif), code1), taclabel);
}

TAC* makeIfThenElse(TAC* code0, TAC* code1, TAC* code2){
  TAC* iftac = 0;
  TAC* labeltac1 = 0;
  TAC* labeltac2 = 0;
  TAC* jump = 0;

  HASH_NODE* newlabel1 = 0;
  HASH_NODE* newlabel2 = 0;

  newlabel1 = makeLabel();
  newlabel2 = makeLabel();

  iftac = tacCreate(TAC_IFZ,newlabel1,code0?code0->res:0,0);
  labeltac1 = tacCreate(TAC_LABEL,newlabel1,0,0);
  labeltac2 = tacCreate(TAC_LABEL,newlabel2,0,0);

  jump = tacCreate(TAC_JUMP,newlabel2,0,0);

  return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(code0,iftac),code1),jump),labeltac1),code2),labeltac2);
}

TAC* makeWhile(TAC* code0, TAC* code1, HASH_NODE* newlabel1, HASH_NODE* newlabel2){
  TAC* iftac = 0;
  TAC* labeltac1 = 0;
  TAC* labeltac2 = 0;
  TAC* jump = 0;

  iftac = tacCreate(TAC_IFZ,newlabel2,code0?code0->res:0,0);
  labeltac1 = tacCreate(TAC_LABEL,newlabel1,0,0);
  labeltac2 = tacCreate(TAC_LABEL,newlabel2,0,0);
  jump = tacCreate(TAC_JUMP,newlabel1,0,0);

  return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(labeltac1,code0),iftac),code1),jump),labeltac2);
}

TAC* makeFunc(TAC* symbol, TAC* params, TAC* code){
  return tacJoin
    (tacJoin
     (tacJoin
      (tacCreate
       (TAC_BEGINFUN, symbol->res, 0, 0), params), code),
     tacCreate(TAC_ENDFUN, symbol->res, 0, 0));
}

TAC* makeFor(TAC* symbol, TAC* exp1, TAC* exp2, TAC* exp3, TAC* cmd, HASH_NODE* forLabel, HASH_NODE* jumpLabel){
  TAC* forTac = tacJoin(tacJoin(tacJoin(tacCreate(TAC_IFZ, jumpLabel, symbol? symbol->res : 0, 0),exp1),exp2),exp3);

  TAC* forTacLabel = tacCreate(TAC_LABEL, forLabel, 0, 0);

  TAC* jumpTac = tacCreate(TAC_JUMP, forLabel, 0, 0);
  TAC* jumpTacLabel = tacCreate(TAC_LABEL, jumpLabel, 0, 0);

  return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(forTacLabel, forTac),symbol),cmd),jumpTac),jumpTacLabel);
}

TAC* makeExp(TAC* code){
  return tacCreate(TAC_EXP, code?code->res:0, 0, 0);
}

TAC* makeReturn(TAC* code0){
  TAC* ret = 0;
  ret = tacCreate(TAC_RETURN,code0?code0->res:0,0,0);
  return tacJoin(code0,ret);
}

TAC* tacJoin(TAC* l1, TAC* l2){
  TAC* t;
  if(!l1) return l2;
  if(!l2) return l1;
  t = l2;
  while(t->prev){
    t = t->prev;
  }
  t->prev = l1;
  l1->next = t;
  return l2;
}

void tacPrintSingle(TAC *tac){
  if(!tac) return;
  if(tac->type == TAC_SYMBOL) return; // not interested

  fprintf(stderr, "TAC(");
  switch(tac->type){
    case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL"); break;
    case TAC_ADD: fprintf(stderr, "TAC_ADD"); break;
    case TAC_SUB: fprintf(stderr, "TAC_SUB"); break;
    case TAC_MUL: fprintf(stderr, "TAC_MUL"); break;
    case TAC_DIV: fprintf(stderr, "TAC_DIV"); break;
    case TAC_MOVE: fprintf(stderr, "TAC_MOVE"); break;
    case TAC_IFZ: fprintf(stderr, "TAC_IFZ"); break;
    case TAC_LABEL: fprintf(stderr, "TAC_LABEL"); break;
    case TAC_GREATER: fprintf(stderr, "TAC_GREATER"); break;
    case TAC_SMALLER: fprintf(stderr, "TAC_SMALLER"); break;
    case TAC_AND: fprintf(stderr, "TAC_AND"); break;
    case TAC_OR: fprintf(stderr, "TAC_OR"); break;
    case TAC_NOT: fprintf(stderr, "TAC_NOT"); break;
    case TAC_GE: fprintf(stderr, "TAC_GE"); break;
    case TAC_LE: fprintf(stderr, "TAC_LE"); break;
    case TAC_EQ: fprintf(stderr, "TAC_EQ"); break;
    case TAC_DIF: fprintf(stderr, "TAC_DIF"); break;
    case TAC_JUMP: fprintf(stderr, "TAC_JUMP"); break;
    case TAC_PRINT: fprintf(stderr, "TAC_PRINT"); break;
    case TAC_READ: fprintf(stderr, "TAC_READ"); break;
    case TAC_VEC: fprintf(stderr, "TAC_VEC"); break;
    case TAC_VECEXP: fprintf(stderr, "TAC_VECEXP"); break;
    case TAC_BEGINFUN: fprintf(stderr, "TAC_BEGINFUN"); break;
    case TAC_ENDFUN: fprintf(stderr, "TAC_ENDFUN"); break;
    case TAC_FUNCCALL: fprintf(stderr, "TAC_FUNCCALL"); break;
    case TAC_FOR: fprintf(stderr, "TAC_FOR"); break;
    case TAC_BREAK: fprintf(stderr, "TAC_BREAK"); break;
    case TAC_JUMPFOR: fprintf(stderr, "TAC_JUMPFOR"); break;
    case TAC_EXP: fprintf(stderr, "TAC_EXP"); break;
    case TAC_RETURN: fprintf(stderr, "TAC_RETURN"); break;
    default: fprintf(stderr, "UNKNOWN TAC TYPE"); break;
  }

if (tac->type == TAC_READ) {
  //fprintf(stderr, "teste, %s: ", tac->res->symbol->text);
}
  if(tac->res) fprintf(stderr, ", %s", tac->res->text);
  else fprintf(stderr, ", 0");
  if(tac->op1) fprintf(stderr, ", %s", tac->op1->text);
  else fprintf(stderr, ", 0");
  if(tac->op2) fprintf(stderr, ", %s", tac->op2->text);
  else fprintf(stderr, ", 0");

  fprintf(stderr, ");\n");
}

void tacPrintBackwards(TAC *tac){
  while(tac->prev != NULL) {
    tac = tac->prev;
  }

  for(;tac; tac = tac->next)
    tacPrintSingle(tac);
}

void createASM(AST *ast, TAC *tac) {
  FILE *out = fopen("asm.s", "w");

  if (!tac) return;

  if (tac->prev)
    createASM(ast, tac->prev);

  // primeira parte do assembly possui as variáveis
  addData(ast, out);
  fprintf(out, ".section\t.rodata\n");

  switch(tac->type) {
    case TAC_ADD:

    break;

  }

  fclose(out);

}


void addData(AST *ast, FILE *out) {
  // nos interessa: AST_VARDEC, AST_SYMBOL (só quando), AST_VEC
  // no nosso caso, parâmetros não são considerados variáveis globais, então a
  // gente não precisa considerar elas aqui

  if(!ast) return;
  if(ast->type == AST_VARDEC) {
    // teoricamente haveria um .data logo após a o primeiro .globl, porém
    // tirando ele não dá erro então nem vou booltar kk
    fprintf(out, ".globl  %s\n"
      ".align 4\n"
      ".type   %s, @object\n"
      ".size   %s, 4\n"
      "%s:\n"
      ".long   %s\n",
      ast->symbol->text, ast->symbol->text, ast->symbol->text, ast->symbol->text, ast->son[1]->symbol->text);
  }
  else if (ast->type == AST_SYMBOL) {
  }
  else if (ast->type == AST_VEC) {
    // o vetor bota como segundo argumento o tamanho em bytes.
    // Por ex: int vec[10]
    // vai ter como segundo argumento 40, que são 10 * 4 (bytes to int)
    int numBytes = atoi(ast->son[1]->symbol->text);
    if (ast->son[0]->type == AST_INT || ast->son[0]->type == AST_FLOAT)
      numBytes = numBytes * 4;
    if (ast->son[0]->type == AST_LONG)
      numBytes = numBytes * 8;

    fprintf(out, ".comm %s,%d,32\n",
        ast->symbol->text, numBytes);

  }

  for(int i = 0; i < MAX_SONS; i++){
    addData(ast->son[i], out);
  }

}
