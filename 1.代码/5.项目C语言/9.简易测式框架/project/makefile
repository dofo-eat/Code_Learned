
.PHONY: clean

all: main.o haizei/test.o
	g++  -std=c++11 -o ./bin/haizei main.o haizei/test.o

main.o: main.cpp
	g++ -std=c++11 -I./ -c main.cpp

haizei/test.o: haizei/test.h haizei/test.cc
	g++ -std=c++11 -I./ -o haizei/test.o -c haizei/test.cc

run: all
	./bin/haizei

clean:
	rm -rf ./a.out *.o ./haizei/test.o ./bin/haizei

