CFLAGS = -Wall
LDFLAGS = -lm

algo: algo.c
	gcc $(CFLAGS) algo.c -o algo $(LDFLAGS)

clean:
	rm algo
