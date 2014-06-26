#include "board.h"

void Board::createBoard(){
	for(int y = 0; y < h; y++){
		vector<Cell> row;

		for(int x = 0; x < w; x++){
			Cell cell((rand() % 4) == 0);
			row.push_back(cell);
		}

		data.push_back(row);
	}
}

bool Board::checkNeighbors(int x, int y, Cell cell){
	bool living = cell.getState();
	int live = 0;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if((i == 1) && (j == 1))
				continue;

			Cell *c = getXY(x - 1 + i, y - 1 + j);
			if(c && c->getState())
				live++;
		}
	}

	return (living ? !((live < 2) || (live > 3)) : ((live == 3) ? true : living));
}

Board::Board(int w, int h){
	this->w = w;
	this->h = h;

	createBoard();
}

void Board::printBoard(){
	for(auto row : data){
		for(auto cell : row)
			cout << (cell.getState() ? "▆" : " ") << " ";
		cout << endl;
	}
}

Cell *Board::getXY(int x, int y){
	Cell *retval = (Cell*) NULL;

	if(!((x >= 0) && (x < w) && (y >= 0) && (y < h))){
		x = (x + w) % w;
		y = (y + h) % h;
	}

	retval = &data.at(y).at(x);
	
	return retval;
}

vector<vector<Cell>> Board::getData(){
	return data;
}

bool Board::updateBoard(){
	Board temp(w, h);
	int diff = 0;

	for(int y = 0; y < h; y++)
		for(int x = 0; x < w; x++){
			Cell *cell = getXY(x, y);
			Cell *c = temp.getXY(x, y);
			bool state_old = cell->getState();
			bool state_new = checkNeighbors(x, y, *cell);

			if(state_old != state_new)
				diff++;
			
			c->setState(state_new);
		}

	// Replace our data with the data from temp, effectively swapping boards.
	data = temp.getData();
	return (diff == 0);
}
