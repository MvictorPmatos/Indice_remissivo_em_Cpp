.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	main

main:  main.o cNode.o cRedBlackTree.o cLinhas.o cNoSimpEnc.o
	g++ -o $@ $^

clean:
	rm *.o main