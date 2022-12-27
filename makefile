textFind.o: textFind.c
	gcc -Wall -fpic -c textFind.c

insertionSort.o: insertionSort.c
	gcc -Wall -fpic -c insertionSort.c

txtfind: textFind.o
	gcc -Wall -o txtfind textFind.o

isort: insertionSort.o
	gcc -Wall -o isort insertionSort.o

all: txtfind isort

.PHONY: clean all

clean:
	rm -f *.o *.out txtfind isort *.gch *.txt