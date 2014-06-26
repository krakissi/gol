#ifndef BOARD_BOARD_H
#define BOARD_BOARD_H

#include <iostream>
#include <vector>
#include <ctime>

#include "cell.h"
using namespace std;

class Board {
	private:
		vector<vector<Cell>> data;
		int w, h;

		void createBoard();
		bool checkNeighbors(int x, int y, Cell cell);

	public:
		Board(int w, int h);
		void printBoard();
		Cell *getXY(int x, int y);
		vector<vector<Cell>> getData();
		bool updateBoard();
};

#endif
