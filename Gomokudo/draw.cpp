#include "draw.h"
vector<vector<string>> drawBoard(int size, vector<vector<string>> Board, vector<string> temp, Object p1, Object p2) {
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (Board[x][y] == p1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
			}
			if (Board[x][y] == p2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
			}
			if (Board[x][y] == "_")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
			}
			cout << Board[x][y] << " ";
		}
		cout << endl;
	}
	return Board;
}
