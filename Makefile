etapa2: lex.yy.c y.tab.c y.tab.h
	gcc -o etapa2 lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l
y.tab.c:
y.tab.h:
	yacc parser.y -d

clean:
	rm lex.yy.c y.tab.c y.tab.h etapa2
