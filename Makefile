TRGDIR=./
OBJ=./obj
CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc

__start__: tictactoe.out
	./tictactoe.out

tictactoe.out: ${OBJ} ${OBJ}/main.o ${OBJ}/tictactoe.o ${OBJ}/game.o
	g++ -o tictactoe.out ${OBJ}/main.o ${OBJ}/tictactoe.o ${OBJ}/game.o -lpthread

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/tictactoe.hh inc/game.hh
	g++ ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/tictactoe.o: src/tictactoe.cpp inc/tictactoe.hh 
	g++ ${CPPFLAGS} -o ${OBJ}/tictactoe.o src/tictactoe.cpp

${OBJ}/game.o: src/game.cpp inc/tictactoe.hh inc/game.hh 
	g++ ${CPPFLAGS} -o ${OBJ}/game.o src/game.cpp

clear:
	rm -f tictactoe.out ${OBJ}/*