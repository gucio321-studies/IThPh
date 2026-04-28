all:
	gcc -pedantic -Wall -c -std=c23 -fPIC solver.c -o solver.o
	gcc -pedantic -Wall -c -std=c23 -fPIC l_autogen.c -o l_autogen.o
	gcc -std=c23 -shared -Wl,-soname,libsolver.so -o libsolver.so solver.o l_autogen.o

