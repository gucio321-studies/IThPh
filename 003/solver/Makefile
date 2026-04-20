all:
	gcc -pedantic -Wall -c -std=c23 -fPIC solver.c -o solver.o
	gcc -std=c23 -shared -Wl,-soname,libsolver.so -o libsolver.so solver.o

