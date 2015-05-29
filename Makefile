CFLAGS = -Wall
LDFLAGS = -lm

algo: algo.c tree_of_strings.c line.c word.c meaning.c
	gcc $(CFLAGS) algo.c tree_of_strings.c line.c word.c meaning.c -o algo $(LDFLAGS)

clean:
	rm algo
