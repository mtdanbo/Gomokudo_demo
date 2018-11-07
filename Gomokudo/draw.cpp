#include "draw.h"
vector<vector<string>> drawBoard(int size, vector<vector<string>> board, Object o1, Object o2) {

	ControlGame controlGame;
	PlayerKey mainPlayer;
	PlayerKey secondPlayer;

	getKey(mainPlayer, secondPlayer, controlGame);

	system("cls");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == o1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), o1.color);
			}
			if (board[x][y] == o2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), o2.color);
			}
			if (board[x][y] == "_")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
			}
			cout << board[x][y] << " ";
		}
		cout << endl;
	}

	string saveCommandLine = "Press L to save your game";
	string undoCommandLine = "Press U to undo your game";
	string backCommandLine = "Press Q to back to main menu";

	saveCommandLine[6] = controlGame.save;
	undoCommandLine[6] = controlGame.undo;
	backCommandLine[6] = controlGame.back;

	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	gotoXY((size + 5) * 2, 0);
	cout << saveCommandLine;
	gotoXY((size + 5) * 2, 1);
	cout << undoCommandLine;
	gotoXY((size + 5) * 2, 2);
	cout << backCommandLine;
	return board;
}
