.PHONY: all
all :semaphore

semaphore : semaphore.o
	g++ -pthread semaphore.o -o sema4
semaphore.o: semaphore.cpp
	g++ -std=c++17 -c -pthread semaphore.cpp
