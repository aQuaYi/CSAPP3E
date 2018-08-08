all:
	gcc -c -m64 3.60.o.s -o 3.60.o.o
	gcc 3.60.o.o 3.60.c main.c -o main

test:
	./main

.PHONY: clean
clean:
	rm main