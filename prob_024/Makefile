prob_024 : prob_024.o list.o
	gcc -Wall -ansi -pedantic-errors prob_024.o list.o -o prob_024

prob_024.o : prob_024.c list.h
	gcc -Wall -ansi -pedantic-errors -c prob_024.c -o prob_024.o

list.o: list.c list.h
	gcc -Wall -ansi -pedantic-errors -c list.c -o list.o

clean:
	rm -f *.o prob_024
