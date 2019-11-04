etapa5: y.tab.o lex.yy.o main.o hash.o astree.o semantic.o
	gcc -ggdb -o etapa5 lex.yy.o main.o hash.o astree.o semantic.o -Wall

lex.yy.o: lex.yy.c y.tab.c
	gcc -ggdb -c lex.yy.c

y.tab.o: y.tab.c
	gcc -ggdb -c y.tab.c -Wall

hash.o: hash.c
	gcc -ggdb -c hash.c -Wall

main.o: main.c
	gcc -ggdb -c main.c -Wall

astree.o: astree.c
	gcc -ggdb -c astree.c -Wall

tacs.o: tacs.c
	gcc -c tacs.c

lex.yy.c: scanner.l
	lex --header-file=lex.yy.h scanner.l

y.tab.c: parser.y
	yacc -d parser.y

semantic.o: semantic.c
	gcc -ggdb -c semantic.c -Wall

clean:
	rm lex.yy.c y.tab.c y.tab.h etapa5 *.o *~
