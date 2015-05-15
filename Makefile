CFLAGS = -Wall
LDFLAGS = -lm

algo: algo.c line.c word.c
	gcc $(CFLAGS) algo.c line.c word.c -o algo $(LDFLAGS)

clean:
	rm algo
