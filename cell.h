#ifndef BOARD_CELL_H
#define BOARD_CELL_H

class Cell {
	private:
		bool state;

	public:
		Cell(bool state);

		bool getState();
		void setState(bool state);
};

#endif
