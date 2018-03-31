CC=gcc
CXX=g++

CXXFLAGS=-Wall -Wextra -O2 -mtune=native -flto -std=c++2a
LDFLAGS=-flto -lstdc++ -std=c++2a
ALL=GM

all:${ALL}
clean:
	rm *.o ${ALL}

GM:GM.o GameCore.o
GM.o:GM.h
GameCore.o:GameCore.h
