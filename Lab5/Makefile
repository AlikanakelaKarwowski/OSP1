.PHONY: all
all : Shell

Shell : Shell.o
	g++ shell.o -o Shell

Shell.o : Shell.cpp
	g++ -std=c++17 -c Shell.cpp

.PHONY: clean
clean :
	@rm -f Shell.o Shell
