all:
	flex limbaj.l
	bison -d -Wcounterexamples limbaj.y
	g++ lex.yy.c limbaj.tab.c *.cpp
clean:
	rm -f a.out lex.yy.c limbaj.tab.* table.txt