all : main

main : parser.o solver.o main.o
	g++ parser.o solver.o main.o -o main

main.o: main.cpp parser.h solver.h
	g++ -c main.cpp

parser.o : parser.cpp parser.h
	g++ -c parser.cpp

solver.o : solver.cpp solver.h
	g++ -c solver.cpp

clean:
	@rm -rf main *.o
