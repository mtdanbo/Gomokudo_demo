#include "draw.h"
vector<vector<string>> drawBoard(int size, vector<vector<string>> board, Object object1, Object object2, int boardColor) {

	ControlGame controlGame;
	PlayerKey mainPlayer;
	PlayerKey secondPlayer;


	getKey(mainPlayer, secondPlayer, controlGame);

	system("cls");

	#pragma region Draw The Board

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardColor);
	gotoXY(0, 0);
	cout << char(218);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(194);
	}
	cout << char(196) << char(196) << char(196) << char(191) << endl;

	int index = 0;

	for (int j = 1; j < size; j++)
	{
		gotoXY(0, 1 + index);
		cout << char(179);
		for (int i = 1; i < size; i++)
		{
			cout << " " << " " << " " << char(179);
		}
		cout << " " << " " << " " << char(179) << endl;

		gotoXY(0, 2 + index);
		cout << char(195);
		for (int i = 1; i < size; i++)
		{
			cout << char(196) << char(196) << char(196) << char(197);
		}
		cout << char(196) << char(196) << char(196) << char(180) << endl;

		index = index + 2;
	}

	gotoXY(0, 1 + index);
	cout << char(179);
	for (int i = 1; i < size; i++)
	{
		cout << " " << " " << " " << char(179);
	}
	cout << " " << " " << " " << char(179) << endl;


	gotoXY(0, 2 + index);
	cout << char(192);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(193);
	}
	cout << char(196) << char(196) << char(196) << char(217) << endl;

	#pragma endregion

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == object1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object1.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object1.icon;
			}
			if (board[x][y] == object2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object2.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object2.icon;
			}
		}
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

	gotoXY((size*2 + 2) * 2, 0);
	cout << saveCommandLine;
	gotoXY((size*2 + 2) * 2, 1);
	cout << undoCommandLine;
	gotoXY((size*2 + 2) * 2, 2);
	cout << backCommandLine;
	return board;
}

vector<vector<string>> drawBoardRule1(int size, vector<vector<string>> board, Object object1, Object object2, Object obstacle, int boardColor, int numRock) {

	ControlGame controlGame;
	PlayerKey mainPlayer;
	PlayerKey secondPlayer;

	getKey(mainPlayer, secondPlayer, controlGame);

	system("cls");

	#pragma region Draw The Board

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardColor);
	gotoXY(0, 0);
	cout << char(201);
	for (int i = 1; i < size; i++)
	{
		cout << char(205) << char(205) << char(205) << char(203);
	}
	cout << char(205) << char(205) << char(205) << char(187) << endl;

	int index = 0;

	for (int j = 1; j < size; j++)
	{
		gotoXY(0, 1 + index);
		cout << char(186);
		for (int i = 1; i < size; i++)
		{
			cout << " " << " " << " " << char(186);
		}
		cout << " " << " " << " " << char(186) << endl;

		gotoXY(0, 2 + index);
		cout << char(204);
		for (int i = 1; i < size; i++)
		{
			cout << char(205) << char(205) << char(205) << char(206);
		}
		cout << char(205) << char(205) << char(205) << char(185) << endl;

		index = index + 2;
	}

	gotoXY(0, 1 + index);
	cout << char(186);
	for (int i = 1; i < size; i++)
	{
		cout << " " << " " << " " << char(186);
	}
	cout << " " << " " << " " << char(186) << endl;


	gotoXY(0, 2 + index);
	cout << char(200);
	for (int i = 1; i < size; i++)
	{
		cout << char(205) << char(205) << char(205) << char(202);
	}
	cout << char(205) << char(205) << char(205) << char(188) << endl;

	#pragma endregion

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == object1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object1.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object1.icon;
			}
			if (board[x][y] == object2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object2.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object2.icon;
			}
			if (board[x][y] == obstacle.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), obstacle.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << obstacle.icon;
			}
		}
	}


	string saveCommandLine = "Press L to save your game";
	string undoCommandLine = "Press U to undo your game";
	string backCommandLine = "Press Q to back to main menu";
	string numRockCommandLine = "Number of rock: " + to_string(numRock);

	saveCommandLine[6] = controlGame.save;
	undoCommandLine[6] = controlGame.undo;
	backCommandLine[6] = controlGame.back;

	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	gotoXY((size*2 + 2) * 2, 0);
	cout << saveCommandLine;
	gotoXY((size*2 + 2) * 2, 1);
	cout << undoCommandLine;
	gotoXY((size*2 + 2) * 2, 2);
	cout << backCommandLine;
	gotoXY((size * 2 + 2) * 2, 3);
	cout << numRockCommandLine;
	return board;
}

vector<vector<string>> drawBoardRule2(int size, vector<vector<string>> board, Object object1, Object object2, Object obstacle, int boardColor) {

	ControlGame controlGame;
	PlayerKey mainPlayer;
	PlayerKey secondPlayer;

	getKey(mainPlayer, secondPlayer, controlGame);

	system("cls");

#pragma region Draw The Board

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardColor);
	gotoXY(0, 0);
	cout << char(201);
	for (int i = 1; i < size; i++)
	{
		cout << char(205) << char(205) << char(205) << char(203);
	}
	cout << char(205) << char(205) << char(205) << char(187) << endl;

	int index = 0;

	for (int j = 1; j < size; j++)
	{
		gotoXY(0, 1 + index);
		cout << char(186);
		for (int i = 1; i < size; i++)
		{
			cout << " " << " " << " " << char(186);
		}
		cout << " " << " " << " " << char(186) << endl;

		gotoXY(0, 2 + index);
		cout << char(204);
		for (int i = 1; i < size; i++)
		{
			cout << char(205) << char(205) << char(205) << char(206);
		}
		cout << char(205) << char(205) << char(205) << char(185) << endl;

		index = index + 2;
	}

	gotoXY(0, 1 + index);
	cout << char(186);
	for (int i = 1; i < size; i++)
	{
		cout << " " << " " << " " << char(186);
	}
	cout << " " << " " << " " << char(186) << endl;


	gotoXY(0, 2 + index);
	cout << char(200);
	for (int i = 1; i < size; i++)
	{
		cout << char(205) << char(205) << char(205) << char(202);
	}
	cout << char(205) << char(205) << char(205) << char(188) << endl;

#pragma endregion

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == object1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object1.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object1.icon;
			}
			if (board[x][y] == object2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object2.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object2.icon;
			}
			if (board[x][y] == obstacle.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), obstacle.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << obstacle.icon;
			}
		}
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

	gotoXY((size * 2 + 2) * 2, 0);
	cout << saveCommandLine;
	gotoXY((size * 2 + 2) * 2, 1);
	cout << undoCommandLine;
	gotoXY((size * 2 + 2) * 2, 2);
	cout << backCommandLine;
	return board;
}

vector<vector<string>> drawBoardRule3(int size, vector<vector<string>> board, Object object1, Object object2, int boardColor, int currentTime) {

	ControlGame controlGame;
	PlayerKey mainPlayer;
	PlayerKey secondPlayer;


	getKey(mainPlayer, secondPlayer, controlGame);

	system("cls");

#pragma region Draw The Board

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardColor);
	gotoXY(0, 0);
	cout << char(218);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(194);
	}
	cout << char(196) << char(196) << char(196) << char(191) << endl;

	int index = 0;

	for (int j = 1; j < size; j++)
	{
		gotoXY(0, 1 + index);
		cout << char(179);
		for (int i = 1; i < size; i++)
		{
			cout << " " << " " << " " << char(179);
		}
		cout << " " << " " << " " << char(179) << endl;

		gotoXY(0, 2 + index);
		cout << char(195);
		for (int i = 1; i < size; i++)
		{
			cout << char(196) << char(196) << char(196) << char(197);
		}
		cout << char(196) << char(196) << char(196) << char(180) << endl;

		index = index + 2;
	}

	gotoXY(0, 1 + index);
	cout << char(179);
	for (int i = 1; i < size; i++)
	{
		cout << " " << " " << " " << char(179);
	}
	cout << " " << " " << " " << char(179) << endl;


	gotoXY(0, 2 + index);
	cout << char(192);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(193);
	}
	cout << char(196) << char(196) << char(196) << char(217) << endl;

#pragma endregion

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == object1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object1.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object1.icon;
			}
			if (board[x][y] == object2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object2.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object2.icon;
			}
		}
	}


	string saveCommandLine = "Press L to save your game";
	string undoCommandLine = "Press U to undo your game";
	string backCommandLine = "Press Q to back to main menu";
	string currentTimeCommand = "You need " + to_string(currentTime) + " to change";

	saveCommandLine[6] = controlGame.save;
	undoCommandLine[6] = controlGame.undo;
	backCommandLine[6] = controlGame.back;

	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	gotoXY((size * 2 + 2) * 2, 0);
	cout << saveCommandLine;
	gotoXY((size * 2 + 2) * 2, 1);
	cout << undoCommandLine;
	gotoXY((size * 2 + 2) * 2, 2);
	cout << backCommandLine;
	gotoXY((size * 2 + 2) * 2, 3);
	cout << currentTimeCommand;
	return board;
}

vector<vector<string>> drawBoardRule4(int size, vector<vector<string>> board, Object object1, Object object2, int boardColor, int currentTime) {

	ControlGame controlGame;
	PlayerKey mainPlayer;
	PlayerKey secondPlayer;


	getKey(mainPlayer, secondPlayer, controlGame);

	system("cls");

#pragma region Draw The Board

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardColor);
	gotoXY(0, 0);
	cout << char(218);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(194);
	}
	cout << char(196) << char(196) << char(196) << char(191) << endl;

	int index = 0;

	for (int j = 1; j < size; j++)
	{
		gotoXY(0, 1 + index);
		cout << char(179);
		for (int i = 1; i < size; i++)
		{
			cout << " " << " " << " " << char(179);
		}
		cout << " " << " " << " " << char(179) << endl;

		gotoXY(0, 2 + index);
		cout << char(195);
		for (int i = 1; i < size; i++)
		{
			cout << char(196) << char(196) << char(196) << char(197);
		}
		cout << char(196) << char(196) << char(196) << char(180) << endl;

		index = index + 2;
	}

	gotoXY(0, 1 + index);
	cout << char(179);
	for (int i = 1; i < size; i++)
	{
		cout << " " << " " << " " << char(179);
	}
	cout << " " << " " << " " << char(179) << endl;


	gotoXY(0, 2 + index);
	cout << char(192);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(193);
	}
	cout << char(196) << char(196) << char(196) << char(217) << endl;

#pragma endregion

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == object1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object1.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object1.icon;
			}
			if (board[x][y] == object2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object2.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object2.icon;
			}
		}
	}


	string saveCommandLine = "Press L to save your game";
	string undoCommandLine = "Press U to undo your game";
	string backCommandLine = "Press Q to back to main menu";
	string changeCommandLine = "You need " + to_string(currentTime) + " to change";

	saveCommandLine[6] = controlGame.save;
	undoCommandLine[6] = controlGame.undo;
	backCommandLine[6] = controlGame.back;

	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	gotoXY((size * 2 + 2) * 2, 0);
	cout << saveCommandLine;
	gotoXY((size * 2 + 2) * 2, 1);
	cout << undoCommandLine;
	gotoXY((size * 2 + 2) * 2, 2);
	cout << backCommandLine;
	gotoXY((size * 2 + 2) * 2, 3);
	cout << changeCommandLine;
	return board;
}

vector<vector<string>> drawBoardRule5(int size, vector<vector<string>> board, Object object1, Object object2, int boardColor, int currentBoom) {

	ControlGame controlGame;
	PlayerKey mainPlayer;
	PlayerKey secondPlayer;

	getKey(mainPlayer, secondPlayer, controlGame);

	system("cls");

#pragma region Draw The Board

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardColor);
	gotoXY(0, 0);
	cout << char(218);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(194);
	}
	cout << char(196) << char(196) << char(196) << char(191) << endl;

	int index = 0;

	for (int j = 1; j < size; j++)
	{
		gotoXY(0, 1 + index);
		cout << char(179);
		for (int i = 1; i < size; i++)
		{
			cout << " " << " " << " " << char(179);
		}
		cout << " " << " " << " " << char(179) << endl;

		gotoXY(0, 2 + index);
		cout << char(195);
		for (int i = 1; i < size; i++)
		{
			cout << char(196) << char(196) << char(196) << char(197);
		}
		cout << char(196) << char(196) << char(196) << char(180) << endl;

		index = index + 2;
	}

	gotoXY(0, 1 + index);
	cout << char(179);
	for (int i = 1; i < size; i++)
	{
		cout << " " << " " << " " << char(179);
	}
	cout << " " << " " << " " << char(179) << endl;


	gotoXY(0, 2 + index);
	cout << char(192);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(193);
	}
	cout << char(196) << char(196) << char(196) << char(217) << endl;

#pragma endregion

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == object1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object1.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object1.icon;
			}
			if (board[x][y] == object2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object2.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object2.icon;
			}
		}
	}

	string saveCommandLine = "Press L to save your game";
	string undoCommandLine = "Press U to undo your game";
	string backCommandLine = "Press Q to back to main menu";
	string boomCommandLine = "Your current boom in the board: " + to_string(currentBoom);

	saveCommandLine[6] = controlGame.save;
	undoCommandLine[6] = controlGame.undo;
	backCommandLine[6] = controlGame.back;

	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	gotoXY((size*2 + 2) * 2, 0);
	cout << saveCommandLine;
	gotoXY((size*2 + 2) * 2, 1);
	cout << undoCommandLine;
	gotoXY((size*2 + 2) * 2, 2);
	cout << backCommandLine;
	gotoXY((size*2 + 2) * 2, 3);
	cout << boomCommandLine;
	return board;
}

vector<vector<string>> drawBoardRule7(int size, vector<vector<string>> board, Object object1, Object object2, int boardColor, int range) {

	ControlGame controlGame;
	PlayerKey mainPlayer;
	PlayerKey secondPlayer;


	getKey(mainPlayer, secondPlayer, controlGame);

	system("cls");

#pragma region Draw The Board

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardColor);
	gotoXY(0, 0);
	cout << char(218);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(194);
	}
	cout << char(196) << char(196) << char(196) << char(191) << endl;

	int index = 0;

	for (int j = 1; j < size; j++)
	{
		gotoXY(0, 1 + index);
		cout << char(179);
		for (int i = 1; i < size; i++)
		{
			cout << " " << " " << " " << char(179);
		}
		cout << " " << " " << " " << char(179) << endl;

		gotoXY(0, 2 + index);
		cout << char(195);
		for (int i = 1; i < size; i++)
		{
			cout << char(196) << char(196) << char(196) << char(197);
		}
		cout << char(196) << char(196) << char(196) << char(180) << endl;

		index = index + 2;
	}

	gotoXY(0, 1 + index);
	cout << char(179);
	for (int i = 1; i < size; i++)
	{
		cout << " " << " " << " " << char(179);
	}
	cout << " " << " " << " " << char(179) << endl;


	gotoXY(0, 2 + index);
	cout << char(192);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(193);
	}
	cout << char(196) << char(196) << char(196) << char(217) << endl;

#pragma endregion

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == object1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object1.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object1.icon;
			}
			if (board[x][y] == object2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object2.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object2.icon;
			}
		}
	}


	string saveCommandLine = "Press L to save your game";
	string undoCommandLine = "Press U to undo your game";
	string backCommandLine = "Press Q to back to main menu";
	string rangeCommandLine = "Now range is: " + to_string(range);

	saveCommandLine[6] = controlGame.save;
	undoCommandLine[6] = controlGame.undo;
	backCommandLine[6] = controlGame.back;

	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	gotoXY((size * 2 + 2) * 2, 0);
	cout << saveCommandLine;
	gotoXY((size * 2 + 2) * 2, 1);
	cout << undoCommandLine;
	gotoXY((size * 2 + 2) * 2, 2);
	cout << backCommandLine;
	gotoXY((size * 2 + 2) * 2, 3);
	cout << rangeCommandLine;
	return board;
}

vector<vector<string>> drawBoardRule8(int size, vector<vector<string>> board, Object object1, Object object2, int currentChangedItem, int boardColor) {

	ControlGame controlGame;
	PlayerKey mainPlayer;
	PlayerKey secondPlayer;

	getKey(mainPlayer, secondPlayer, controlGame);

	system("cls");

#pragma region Draw The Board

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardColor);
	gotoXY(0, 0);
	cout << char(218);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(194);
	}
	cout << char(196) << char(196) << char(196) << char(191) << endl;

	int index = 0;

	for (int j = 1; j < size; j++)
	{
		gotoXY(0, 1 + index);
		cout << char(179);
		for (int i = 1; i < size; i++)
		{
			cout << " " << " " << " " << char(179);
		}
		cout << " " << " " << " " << char(179) << endl;

		gotoXY(0, 2 + index);
		cout << char(195);
		for (int i = 1; i < size; i++)
		{
			cout << char(196) << char(196) << char(196) << char(197);
		}
		cout << char(196) << char(196) << char(196) << char(180) << endl;

		index = index + 2;
	}

	gotoXY(0, 1 + index);
	cout << char(179);
	for (int i = 1; i < size; i++)
	{
		cout << " " << " " << " " << char(179);
	}
	cout << " " << " " << " " << char(179) << endl;


	gotoXY(0, 2 + index);
	cout << char(192);
	for (int i = 1; i < size; i++)
	{
		cout << char(196) << char(196) << char(196) << char(193);
	}
	cout << char(196) << char(196) << char(196) << char(217) << endl;

#pragma endregion

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == object1.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object1.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object1.icon;
			}
			if (board[x][y] == object2.icon)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), object2.color);
				gotoXY(x * 4 + 2, y * 2 + 1);
				cout << object2.icon;
			}
		}
	}

	string saveCommandLine = "Press L to save your game";
	string undoCommandLine = "Press U to undo your game";
	string backCommandLine = "Press Q to back to main menu";
	string boomCommandLine = "Current changable items : " + to_string(currentChangedItem);

	saveCommandLine[6] = controlGame.save;
	undoCommandLine[6] = controlGame.undo;
	backCommandLine[6] = controlGame.back;

	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	gotoXY((size*2 + 2) * 2, 0);
	cout << saveCommandLine;
	gotoXY((size*2 + 2) * 2, 1);
	cout << undoCommandLine;
	gotoXY((size*2 + 2) * 2, 2);
	cout << backCommandLine;
	gotoXY((size*2 + 2) * 2, 3);
	cout << boomCommandLine;
	return board;
}