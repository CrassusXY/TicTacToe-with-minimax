TRGDIR=./
OBJ=./obj
CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc

__start__: rank.out
	./rank.out

rank.out: ${OBJ} ${OBJ}/main.o ${OBJ}/movielist.o
	g++ -o rank.out ${OBJ}/main.o ${OBJ}/movielist.o -lpthread

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/movielist.hh inc/sorts.hh
	g++ ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/movielist.o: src/movielist.cpp inc/movielist.hh 
	g++ ${CPPFLAGS} -o ${OBJ}/movielist.o src/movielist.cpp

${OBJ}/sorts.o: src/sorts.cpp inc/sorts.hh 
	g++ ${CPPFLAGS} -o ${OBJ}/sorts.o src/sorts.cpp

clear:
	rm -f rank.out ${OBJ}/*