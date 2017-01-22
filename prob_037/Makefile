CC = gcc
CFLAGS = -Wall -ansi -pedantic-errors -O3
LDFLAGS = -lm

PROG = prob_037
HDRS = primes.h
SRCS = prob_037.c primes.c
OBJS = $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(PROG)

prob_037.o: prob_037.c primes.h

primes.o: primes.c

clean:
	rm -f $(PROG) $(OBJS)
