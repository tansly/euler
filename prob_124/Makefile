CC = gcc
CFLAGS = -Wall -ansi -pedantic-errors -O3
LDFLAGS = -lm

PROG = prob_124
HDRS = primes.h sort.h
SRCS = prob_124.c primes.c sort.c
OBJS = $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(PROG)

prob_124.o: prob_124.c primes.h sort.h

primes.o: primes.c

sort.o: sort.c

clean:
	rm -f $(PROG) $(OBJS)
