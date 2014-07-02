CC=g++ -std=c++0x -s

# Main source file and all the objects get combined here to produce the final binary.
board: main.cc board.o cell.o
	$(CC) -o board main.cc board.o cell.o

# Board includes Cell, so we should put that header in these dependencies.
board.o: board.cc board.h cell.h
	$(CC) -c board.cc

# Cell depends upon nothing else in the project.
cell.o: cell.cc cell.h
	$(CC) -c cell.cc

clean:
	rm -f board *.o
