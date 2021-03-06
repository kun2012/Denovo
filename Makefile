ESSENTIAL = include/tree.o include/semantic.o include/ir.o include/mips.o

dnv: main.c syntax.tab.c lex.yy.c $(ESSENTIAL)
	gcc main.c syntax.tab.c $(ESSENTIAL) -lfl -ly -o dnv
	
include/tree.o: include/tree.c include/tree.h
	gcc -c include/tree.c -o include/tree.o
	
include/semantic.o: include/semantic.c include/semantic.h
	gcc -c include/semantic.c -o include/semantic.o

include/ir.o: include/ir.c include/ir.h
	gcc -c include/ir.c -o include/ir.o
	
include/mips.o: include/mips.c include/mips.h
	gcc -c include/mips.c -o include/mips.o
	
syntax.tab.c: syntax.y
	bison -v -d syntax.y

lex.yy.c: lexical.l
	flex lexical.l
clear:
	rm -f lex.yy.c dnv syntax.tab.c syntax.tab.h $(ESSENTIAL)
