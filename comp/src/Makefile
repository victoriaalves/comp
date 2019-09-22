etapa3: y.tab.o lex.yy.o main.o hash.o astree.o
	gcc -o etapa3 lex.yy.o main.o hash.o astree.o

lex.yy.o: lex.yy.c y.tab.c
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c -Wall

hash.o: hash.c
	gcc -c hash.c -Wall

main.o: main.c
	gcc -c main.c -Wall

astree.o: astree.c
	gcc -c astree.c -Wall

lex.yy.c: scanner.l
	lex --header-file=lex.yy.h scanner.l

y.tab.c: parser.y
	yacc -d parser.y

clean:
	rm lex.yy.c y.tab.c y.tab.h etapa3 *.o *~
