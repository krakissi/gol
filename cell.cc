#include "cell.h"

Cell::Cell(bool state){
	this->state = state;
}

bool Cell::getState(){
	return state;
}

void Cell::setState(bool state){
	this->state = state;
}
