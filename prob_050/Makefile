CC = gcc
CFLAGS = -Wall -ansi -pedantic-errors -O3
LDFLAGS = -lm

PROG = prob_050
HDRS = primes.h
SRCS = prob_050.c primes.c
OBJS = $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(PROG)

prob_050.o: prob_050.c primes.h

primes.o: primes.c

clean:
	rm -f $(PROG) $(OBJS)
