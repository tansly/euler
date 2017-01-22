prob_027: prob_027.o primes.o
	gcc -Wall -ansi -pedantic-errors *.o -o prob_027 -lm -O3

primes.o: primes.c primes.h
	gcc -Wall -ansi -pedantic-errors primes.c -c -O3

prob_027.o: prob_027.c
	gcc -Wall -ansi -pedantic-errors prob_027.c -c -O3

clean:
	rm -f *.o prob_027
