run: compile
	./avltree.o

compile:
	clang++ -o avltree.o main.cpp

clear:
	rm avltree.o
