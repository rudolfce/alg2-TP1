CC=gcc
flags=-Wall -O0 -g

teste: TVetor.h TVetor.o TConj.o main.o
	$(CC) $(flags) TVetor.o TConj.o main.o -o teste

TVetor.o: TVetor.h TVetor.c
	$(CC) $(flags) -c TVetor.c

TConj.o: TVetor.h TConj.h TConj.c
	$(CC) $(flags) -c TConj.c

main.o: TVetor.h TConj.h main.c
	$(CC) $(flags) -c main.c

clean:
	rm TVetor.o TConj.o main.o teste
