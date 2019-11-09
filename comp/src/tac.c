#import "tac.h"

TAC* makeBinOperation(int type, TAC* code0, TAC* code1);
TAC* makeIfThen(TAC* code0, TAC* code1);

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

TAC* generateCode(AST *ast){
    if(!ast) return 0;

    TAC* code[MAX_SONS];

    // generateCode for children first
    for(int i = 0; i < MAX_SONS; i++)
        code[i] = generateCode(ast->son[i]);

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

TAC* tacJoin(TAC* l1, TAC* l2){
    TAC* t;
	if(!l1) return l2;
	if(!l2) return l1;
	t = l2;
	while(t->prev){
		t = t->prev;
	}
	t->prev = l1;
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
        case TAC_IFZ: fprintf(stderr, "TAC_MOVE"); break;
        case TAC_LABEL: fprintf(stderr, "TAC_MOVE"); break;
        case TAC_GREATER: fprintf(stderr, "TAC_GREATER"); break;
        case TAC_SMALLER: fprintf(stderr, "TAC_SMALLER"); break;
        case AST_AND: fprintf(stderr, "AST_AND"); break;
        case AST_OR: fprintf(stderr, "AST_OR"); break;
        case AST_NOT: fprintf(stderr, "AST_NOT"); break;
        case AST_GE: fprintf(stderr, "AST_GE"); break;
        case AST_LE: fprintf(stderr, "AST_LE"); break;
        case AST_EQ: fprintf(stderr, "AST_EQ"); break;
        case AST_DIF: fprintf(stderr, "AST_DIF"); break;
        default: fprintf(stderr, "UNKNOWN TAC TYPE"); break;
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
    for(;tac; tac = tac->prev)
        tacPrintSingle(tac);
}
