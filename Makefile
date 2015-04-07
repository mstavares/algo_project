CFLAGS = -Wall
LDFLAGS = -lm

computer: algo.c
	gcc $(CFLAGS) algo.c -o algo $(LDFLAGS)

clean:
	rm algo
