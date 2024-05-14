main: main.o message.o
	gcc main.o message.o -o main

main.o: main.cpp
	gcc -c main.cpp

message.o: message.cpp message.h
	gcc -c mesasge.cpp

clean:
	rm *.o output

target: dependencies
	action