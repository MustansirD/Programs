all:
	gcc -c lib_myex01.c -Wall -Wunused -o lib_myex01.o
	ar rcs lib_myex01.a lib_myex01.o
	gcc -c ex01.c -Wall -Wunused -o ex01.o
	gcc -o ex01 ex01.o -L. -l_myex01

clean:
	rm -rf lib_myex01.a ex01.o ex01 lib_myex01.o
