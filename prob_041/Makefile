prob_041: prob_041.o primes.o
	gcc -Wall -ansi -pedantic-errors *.o -o prob_041 -lm -O3

primes.o: primes.c primes.h
	gcc -Wall -ansi -pedantic-errors primes.c -c -O3

prob_041.o: prob_041.c
	gcc -Wall -ansi -pedantic-errors prob_041.c -c -O3

clean:
	rm -f *.o prob_041
