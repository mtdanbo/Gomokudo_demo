#include "compute.h"

#pragma region Compute NxN
int computeVerticalN(vector<vector<string>>Board, int size, Object p) {
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
int computeHorizontalN(vector<vector<string>>Board, int size, Object p) {
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
int computeDiagonalDownN(vector<vector<string>>Board, int size, Object p) {
	for (int y = 0; y <= size; y++)
	{
		for (int x = 0; x <= size; x++)
		{
			if (Board[x][y] == p.icon &&  Board[x + 1][y + 1] == p.icon && Board[x + 2][y + 2] == p.icon && Board[x + 3][y + 3] == p.icon && Board[x + 4][y + 4] == p.icon)
			{
				return 1;
			}
		}
	}
	return 0;

}
int computeDiagonalUpN(vector<vector<string>>Board, int size, Object p) {

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

int ComputeN(Object p, int size, vector<vector<string>> Board) {
	int max = computeVerticalN(Board, size, p);
	if (computeHorizontalN(Board, size, p) > max)
	{
		max = computeHorizontalN(Board, size, p);
	}
	if (computeDiagonalUpN(Board, size, p) > max)
	{
		max = computeDiagonalUpN(Board, size, p);
	}
	if (computeDiagonalDownN(Board, size, p) > max)
	{
		max = computeDiagonalDownN(Board, size, p);
	}
	return max;
}
#pragma endregion

#pragma region Compute 3x3
int computeVertical3(vector<vector<string>>Board, int size, Object p) {
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
			if (count == 3)
			{
				return 1;
			}
		}
	}
	return 0;

}
int computeHorizontal3(vector<vector<string>>Board, int size, Object p) {
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
			if (count == 3)
			{
				return 1;
			}
		}
	}
	return 0;

}
int computeDiagonalDown3(vector<vector<string>>Board, int size, Object p) {
	for (int y = 0; y <= size; y++)
	{
		for (int x = 0; x <= size; x++)
		{
			if (Board[x][y] == p.icon &&  Board[x + 1][y + 1] == p.icon && Board[x + 2][y + 2] == p.icon)
			{
				return 1;
			}
		}
	}
	return 0;

}
int computeDiagonalUp3(vector<vector<string>>Board, int size, Object p) {

	for (int y = size; y >= 0; y--)
	{
		for (int x = 0; x <= size; x++)
		{
			if (y >= 2) {
				if (Board[x][y] == p.icon &&  Board[x + 1][y - 1] == p.icon && Board[x + 2][y - 2] == p.icon)
				{
					return 1;
				}
			}
		}
	}
	return 0;

}

int Compute3(Object p, int size, vector<vector<string>> Board) {
	int max = computeVertical3(Board, size, p);
	if (computeHorizontal3(Board, size, p) > max)
	{
		max = computeHorizontal3(Board, size, p);
	}
	if (computeDiagonalUp3(Board, size, p) > max)
	{
		max = computeDiagonalUp3(Board, size, p);
	}
	if (computeDiagonalDown3(Board, size, p) > max)
	{
		max = computeDiagonalDown3(Board, size, p);
	}
	return max;
}
#pragma endregion

#pragma region Compute 4x4
int computeVertical4(vector<vector<string>>Board, int size, Object p) {
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
			if (count == 4)
			{
				return 1;
			}
		}
	}
	return 0;

}
int computeHorizontal4(vector<vector<string>>Board, int size, Object p) {
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
			if (count == 4)
			{
				return 1;
			}
		}
	}
	return 0;

}
int computeDiagonalDown4(vector<vector<string>>Board, int size, Object p) {
	for (int y = 0; y <= size; y++)
	{
		for (int x = 0; x <= size; x++)
		{
			if (Board[x][y] == p.icon &&  Board[x + 1][y + 1] == p.icon && Board[x + 2][y + 2] == p.icon && Board[x + 3][y + 3] == p.icon)
			{
				return 1;
			}
		}
	}
	return 0;

}
int computeDiagonalUp4(vector<vector<string>>Board, int size, Object p) {

	for (int y = size; y >= 0; y--)
	{
		for (int x = 0; x <= size; x++)
		{
			if (y >= 3) {
				if (Board[x][y] == p.icon &&  Board[x + 1][y - 1] == p.icon && Board[x + 2][y - 2] == p.icon && Board[x + 3][y - 3] == p.icon)
				{
					return 1;
				}
			}
		}
	}
	return 0;

}

int Compute4(Object p, int size, vector<vector<string>> Board) {
	int max = computeVertical4(Board, size, p);
	if (computeHorizontal4(Board, size, p) > max)
	{
		max = computeHorizontal4(Board, size, p);
	}
	if (computeDiagonalUp4(Board, size, p) > max)
	{
		max = computeDiagonalUp4(Board, size, p);
	}
	if (computeDiagonalDown4(Board, size, p) > max)
	{
		max = computeDiagonalDown4(Board, size, p);
	}
	return max;
}
#pragma endregion





