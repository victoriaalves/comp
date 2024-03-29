#include "tac.h"

int BL = 0;

TAC* makeBinOperation(int type, TAC* code0, TAC* code1);
TAC* makeIfThen(TAC* code0, TAC* code1);
TAC* makeIfThenElse(TAC* code0, TAC* code1, TAC* code2);
TAC* makeWhile(TAC* code0, TAC* code1, HASH_NODE* newlabel1, HASH_NODE* newlabel2);
TAC* makeFunc(TAC* code0, TAC* code1, TAC* code2);
TAC* makeFor(TAC* code0, TAC* code1, TAC* code2, TAC* code3, TAC* code4, HASH_NODE* forLabel, HASH_NODE* jumpLabel);
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
  TAC* forTac = tacJoin(tacJoin(tacJoin(tacCreate(TAC_FOR, jumpLabel, symbol? symbol->res : 0, 0),exp1),exp2),exp3);

  TAC* forTacLabel = tacCreate(TAC_LABEL, forLabel, 0, 0);

  TAC* jumpTac = tacCreate(TAC_JUMP, forLabel, 0, 0);
  TAC* jumpTacLabel = tacCreate(TAC_LABEL, jumpLabel, 0, 0);

  return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(forTacLabel, forTac),symbol),cmd),jumpTac),jumpTacLabel);
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

void createASM(AST *ast, TAC *firstTac) {
  FILE *out = fopen("asm.s", "w");

  if (!firstTac) return;


  fprintf(out, "\t.data\n");
  // primeira parte do assembly possui as variáveis
  addData(ast, out);


  // voltando ao root da tac pra avaliar de cima pra baixo
  TAC *tac = firstTac;
  while(tac->prev != NULL) {
    tac = tac->prev;
  }
  // e variáveis temporárias
  for (; tac; tac = tac->next) {
    addTemp(tac, out);
  }


  fprintf(out, ".section .rodata\n"
      ".LC0:\n\t.string \"%%d\\n\"\n"
      "\t.text\n");

  tac = firstTac;
  while(tac->prev != NULL) {
    tac = tac->prev;
  }
  int numBytes = 0;
  for (; tac; tac = tac->next) {
    //printf("tac->type: %d\n", tac->type);
    switch(tac->type){
      case TAC_ADD: // sub, mul e div são semelhantes
        fprintf(out, "\tmovl %s(%%rip), %%edx\n"
            "\tmovl %s(%%rip), %%eax\n"
            "\taddl %%edx, %%eax\n"
            "\tmovl %%eax, %s(%%rip)\n",
            tac->op1->text, tac->op2->text, tac->res->text);
        break;
      case TAC_MOVE:
        fprintf(out, "\tmovl $%s, %s(%%rip)\n",
            tac->op1->text, tac->res->text);
        break;
      case TAC_IFZ:
        fprintf(out, "\tmovl $1, %%eax\n"
            "\tandl %%eax, %%edx\n"
            "\tjz .%s\n",
            tac->res->text);
        break;
      case TAC_GREATER: break;
      case TAC_SMALLER: break;
      case TAC_AND: break;
      case TAC_OR: break;
      case TAC_NOT: break;
      case TAC_GE:  break;
      case TAC_LE:  break;
      case TAC_EQ:
                    fprintf(out, "\tmovl %s(%%rip), %%eax\n"
                        "\tmovl %s(%%rip), %%edx\n"
                        "\tcmpl %%eax, %%edx\n"
                        "\tjne .BL%d\n"
                        "\tmovl $1, %%edx\n"
                        "\tjmp .BL%d\n"
                        ".BL%d:\n"
                        "\tmovl $0, %%edx\n"
                        ".BL%d:\n",
                        tac->op2->text, tac->op1->text, BL, BL+1, BL, BL+1);
                    BL+=2;
                    break;
      case TAC_DIF: break;
      case TAC_JUMP:
                    fprintf(out, "\tjmp .%s\n",
                        tac->res->text);
                    break;
      case TAC_PRINT:
                    if (tac->res) {
                      fprintf(out, "\tmovl $.%s, %%edi\n"
                        "\tcall puts\n", tac->res->text);
                    }
                    else if (tac->op1) {
                      fprintf(out, "\tmovl %s(%%rip), %%eax\n"
                          "\tmovl %%eax, %%esi\n"
                          "\tmovl $.LC0, %%edi\n"
                          "\tmovl $0, %%eax\n"
                          "\tcall printf\n",
                          tac->op1->text);
                    }
                     break;
      case TAC_READ:  break;
      case TAC_VEC: break;
      case TAC_VECEXP:
                    numBytes = atoi(tac->op1->text) * 4;
                    fprintf(out, "\tmovl $%s, %s+%d(%%rip)\n",
                        tac->op2->text, tac->res->text, numBytes);
                      break;
      case TAC_BEGINFUN:
                        fprintf(out, "\t.globl %s\n"
                            "\t.type %s, @function\n"
                            "%s:\n"
                            ".B%s:\n"
                            "\t.cfi_startproc\n\tpushq %rbp\n\t.cfi_def_cfa_offset 16\n"
                            "\t.cfi_offset 6, -16\n\tmovq %rsp, %rbp\n\t.cfi_def_cfa_register 6\n",
                            tac->res->text, tac->res->text, tac->res->text, tac->res->text);
                        break;
      case TAC_ENDFUN:
                        fprintf(out, "\tpopq %%rbp\n"
                            "\t.cfi_def_cfa 7, 8\n\tret\n\t.cfi_endproc\n"
                            ".E%s:\n"
                            "\t.size %s, .-%s\n",
                            tac->res->text, tac->res->text, tac->res->text);
                        break;
      case TAC_FUNCCALL:
                        // verificar se há parâmetros sendo passados?
                        // se sim, mover eles? pq na real a gente não passa os
                        // params pelas TACs, então não sei o que fazer
                        // chamar função
                        fprintf(out, "\tcall %s\n", tac->op1->text);
                        break;
      case TAC_FOR:  break;
      case TAC_BREAK: break;
      case TAC_JUMPFOR: break;
      case TAC_RETURN:  break;
      case TAC_LABEL:
                        fprintf(out, ".%s:\n", tac->res->text);

    }
  }
  fclose(out);

}

void addData(AST *ast, FILE *out) {
  // nos interessa: AST_VARDEC, AST_SYMBOL (só quando prrint), AST_VEC
  // no nosso caso, parâmetros não são considerados variáveis globais, então a
  // gente não precisa considerar elas aqui

  if(!ast) return;
  if(ast->type == AST_VARDEC) {
    int numBytes = 0;
    if (ast->son[0]->type == AST_INT || ast->son[0]->type == AST_FLOAT)
      numBytes = 4;
    if (ast->son[0]->type == AST_LONG)
      numBytes = 8;
    if (ast->son[0]->type == AST_BYTE || ast->son[0]->type == AST_BOOL)
      numBytes = 1;

    // teoricamente haveria um .data logo após a o primeiro .globl, porém
    // tirando ele não dá erro então nem vou booltar kk
    fprintf(out, "\t.globl  %s\n"
      "\t.align %d\n"
      "\t.type   %s, @object\n"
      "\t.size   %s, %d\n"
      "%s:\n"
      "\t.long   %s\n",
      ast->symbol->text, numBytes, ast->symbol->text, ast->symbol->text, numBytes, ast->symbol->text, ast->son[1]->symbol->text);
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

    // caso o array tenha sido inicializado
    if (ast->son[2]) {
      fprintf(out, "\t.globl\t%s\n"
          "\t.align 32\n"
          "\t.type %s, @object\n"
          "\t.size %s, %d\n"
          "%s:\n",
        ast->symbol->text, ast->symbol->text, ast->symbol->text, numBytes, ast->symbol->text);

      // cria a lista de valores do array
      AST *array = ast->son[2];
      while (array) {
        fprintf(out, "\t.quad %s\n",
            array->son[0]->symbol->text);
        array = array->son[1];
      }
    }
    else {
      fprintf(out, "\t.comm %s,%d,32\n",
          ast->symbol->text, numBytes);
    }
  }
  else if (ast->type == AST_LPRINT) {
    char *token = strtok(ast->symbol->text, "\"");
    strncpy(ast->symbol->text, token, sizeof(token));

    fprintf(out, ".%s:\n"
        "\t.string \"%s\"\n",
        ast->symbol->text, ast->symbol->text);
  }

  for(int i = 0; i < MAX_SONS; i++){
    addData(ast->son[i], out);
  }
}

void addTemp(TAC *tac, FILE *out) {
  if(!tac) return;

  if(tac->type == TAC_ADD ||
      tac->type == TAC_SUB ||
      tac->type == TAC_MUL ||
      tac->type == TAC_DIV ||
      tac->type == TAC_GREATER ||
      tac->type == TAC_SMALLER ||
      tac->type == TAC_AND ||
      tac->type == TAC_OR ||
      tac->type == TAC_AND ||
      tac->type == TAC_NOT ||
      tac->type == TAC_GE ||
      tac->type == TAC_LE ||
      tac->type == TAC_EQ ||
      tac->type == TAC_DIF ||
      tac->type == TAC_FUNCCALL
    ) {
    fprintf(out, "\t.globl  %s\n"
        "\t.align  4\n"
        "\t.type   %s, @object\n"
        "\t.size   %s, 4\n"
        "%s:\n"
        "\t.long   %d\n",
        tac->res->text, tac->res->text, tac->res->text, tac->res->text, 0);
  }
}
