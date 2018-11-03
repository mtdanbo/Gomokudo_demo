#include "base.h"

void gotoXY(int x_pos, int y_pos) {
	COORD coord;
	coord.X = x_pos;
	coord.Y = y_pos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}