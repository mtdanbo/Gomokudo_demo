#include "save.h"

void savePvP(vector<vector<string>> board, int size, Object player1, Object player2) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;


	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/pvp_savelist.txt", ios_base::app);
	while (!savelist_check.eof())
	{
		string temp;
		savelist_check >> temp;
		if (filename == temp)
		{
			exist = 1;
		}
	}
	savelist_check.close();

	// If exist, Ask user about overwriting
	if (exist == 1)
	{
		cout << filename + " is exsit. Do you want to overwrite it" << endl;
		cout << "Yes or No (Y/N). Your choice is: ";
		char key = _getch();
		while (key != 'y' && key != 'Y' && key != 'n' && key != 'N') {
			key = _getch();
		}

		if (key == 'y' || key == 'Y')
		{
			system("cls");
			cout << "OK" << endl;
			system("pause");
		}
		if (key == 'n' || key == 'N')
		{
			system("cls");
			cout << "Plz enter your new file name: ";
			cin >> filename;
			exist = 0;
		}
	}

	if (exist == 0) {
		ofstream savelist;
		savelist.open("text/pvp_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_pvp/" + filename + "p1.txt");

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move << x << " " << y << endl;
			}
		}
	}

	p1move << "-1 -1" << endl;

	p1move.close();

	// Save p2 location

	ofstream p2move;
	p2move.open("save_pvp/" + filename + "p2.txt");

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move << x << " " << y << endl;
			}
		}
	}

	p2move << "-1 -1" << endl;

	p2move.close();

	// Save the figure of the board

	ofstream figure;
	figure.open("save_pvp/" + filename + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << 1 - player1.turn << " " << 1 - player2.turn << endl;

	figure.close();

}

void savePvC(vector<vector<string>> board, int size, Object player, Object bot, int mode) {

	Color color;
	getColor(color);

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;

	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/pvc_savelist.txt", ios_base::app);
	while (!savelist_check.eof())
	{
		string temp;
		savelist_check >> temp;
		if (filename == temp)
		{
			exist = 1;
		}
	}
	savelist_check.close();

	// If exist, Ask user about overwriting
	if (exist == 1)
	{
		cout << filename + " exsit. Do you want to overwrite it" << endl;
		cout << "Yes or No (Y/N). Your choice is: ";
		char key = _getch();
		while (key != 'y' && key != 'Y' && key != 'n' && key != 'N') {
			key = _getch();
		}

		if (key == 'y' || key == 'Y')
		{
			system("cls");
			cout << "OK";
			system("pause");
		}
		if (key == 'n' || key == 'N')
		{
			system("cls");
			cout << "Plz enter your new file name: ";
			cin >> filename;
			exist = 0;
		}
	}

	if (exist == 0) {
		ofstream savelist;
		savelist.open("text/pvc_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save player location
	ofstream playerMove;

	playerMove.open("save_pvc/" + filename + "p.txt");

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == player.icon)
			{
				playerMove << x << " " << y << endl;
			}
		}
	}
	playerMove << "-1 -1" << endl;

	playerMove.close();

	// Save bot location

	ofstream botMove;
	botMove.open("save_pvc/" + filename + "b.txt");

	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (board[x][y] == bot.icon)
			{
				botMove << x << " " << y << endl;
			}
		}
	}
	botMove << "-1 -1" << endl;

	botMove.close();

	// Save the figure of the board

	ofstream figure;
	figure.open("save_pvc/" + filename + "figure.txt");

	figure << size << endl;
	figure << player.icon << " " << player.color << endl;
	figure << bot.icon << " " << bot.color << endl;
	figure << mode << endl;
	figure << 1 - player.turn << " " << 1 - bot.turn << endl;

	figure.close();

}
