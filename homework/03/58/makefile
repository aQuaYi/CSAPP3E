all:
	gcc -c -m64 3.58.o.s -o 3.58.o.o
	gcc -m64 main.c 3.58.c 3.58.o.o -o main

test:
	./main

.PHONY: clean
clean:
	rm main