/*
	Conway's Game of Life (as implemented by Mike Perron, 2014)

	Requires C++11
		Compile with -std=c++11 or -std=c++0x if 11 is unavailable.
*/
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <sys/ioctl.h>

#include "board.h"
#include "cell.h"

using namespace std;

int main(int argc, char **argv){
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

	int h = ws.ws_row - 3;
	int w = ws.ws_col / 2;
	useconds_t delay = 1000000;

	if(argc >= 2)
		delay = atoi(argv[1]) * 1000;
	if(argc >= 4){
		w = atoi(argv[2]);
		h = atoi(argv[3]);
	}

	srand(time(NULL));
	Board b(w, h);

	int generation = 0;

	system("clear");
	cout << "The initial state of the game world:" << endl;
	b.printBoard();
	sleep(1);

	string buffer;
	bool final = false;
	while(!final){
		// This is a gross trick, and I feel dirty for doing it.
		cout << "\033[H                                          \033[H";

		cout << "Generation: " << ++generation << endl;

		final = b.updateBoard();
		b.printBoard();
		usleep(delay);
	}
	cout << "The world is now in equilibrium." << endl;

	return 0;
}
