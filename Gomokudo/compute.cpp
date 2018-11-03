#include "compute.h"
int computeVertical(vector<vector<string>>Board, int size, Object p) {
	int count = 0;
	for (int x = 0; x <= size; x++)
	{
		for (int y = 0; y <= size; y++)
		{
			if (Board[x][y] == p.icon)
			{
				count++;
			}
			else
			{
				count = 0;
			}
			if (count == 5)
			{
				return 1;
			}
		}
	}
	return 0;

}

int computeHorizontal(vector<vector<string>>Board, int size, Object p) {
	int count = 0;
	for (int y = 0; y <= size; y++)
	{
		for (int x = 0; x <= size; x++)
		{
			if (Board[x][y] == p.icon)
			{
				count++;
			}
			else
			{
				count = 0;
			}
			if (count == 5)
			{
				return 1;
			}
		}
	}
	return 0;

}
int computeDiagonalDown(vector<vector<string>>Board, int size, Object p) {
	for (int y = 0; y <= size; y++)
	{
		for (int x = 0; x <= size; x++)
		{
			if (Board[x][y] == p.icon &&  Board[x+1][y+1] == p.icon && Board[x+2][y+2] == p.icon && Board[x+3][y+3] == p.icon && Board[x+4][y+4] == p.icon)
			{
				return 1;
			}
		}
	}
	return 0;

}
int computeDiagonalUp(vector<vector<string>>Board, int size, Object p) {

	for (int y = size; y >= 0; y--)
	{
		for (int x = 0; x <= size; x++)
		{
			if (y >= 4) {
				if (Board[x][y] == p.icon &&  Board[x + 1][y - 1] == p.icon && Board[x + 2][y - 2] == p.icon && Board[x + 3][y - 3] == p.icon && Board[x + 4][y - 4] == p.icon)
				{
					return 1;
				}
			}
		}
	}
	return 0;

}




int Compute(Object p, int size, vector<vector<string>> Board) {
	int max = computeVertical(Board, size, p);
	if (computeHorizontal(Board,size,p) > max)
	{
		max = computeHorizontal(Board, size, p);
	}
	if (computeDiagonalUp(Board, size, p) > max)
	{
		max = computeDiagonalUp(Board, size, p);
	}
	if (computeDiagonalDown(Board, size, p) > max)
	{
		max = computeDiagonalDown(Board, size, p);
	}
	return max;
}





