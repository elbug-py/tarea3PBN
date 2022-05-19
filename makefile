CC=g++
flags=#-std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self


mocha: arena.o peleador.o objeto.o main.o
	$(CC) $(flags) main.o arena.o peleador.o objeto.o -o mocha

arena.o: arena.cpp arena.h
	$(CC) $(flags) -c arena.cpp -o arena.o

objeto.o: objeto.cpp objeto.h
	$(CC) $(flags) -c objeto.cpp -o objeto.o

peleador.o: peleador.cpp peleador.h
	$(CC) $(flags) -c peleador.cpp -o peleador.o

main.o: main.cpp
	$(CC) $(flags) -c main.cpp -o main.o

run: mocha.exe
	.\mocha

clean:
	rm mocha.exe *.o