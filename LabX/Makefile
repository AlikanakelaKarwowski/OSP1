.PHONY: all
all : Shell

Shell : myshell.o
	g++ myshell.o -o myshell

Shell.o : myshell.cpp
	g++ -std=c++17 -c myshell.cpp

.PHONY: clean
clean :
	@rm -f myshell.o myshell
