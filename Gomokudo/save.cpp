#include "save.h"

void savePvP(vector<vector<string>> Board, int size, Object p1, Object p2) {

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
		cout << filename + "exsit. Do you want to overwrite it" << endl;
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
		savelist.open("text/pvp_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_pvp/" + filename + "p1.txt");

	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (Board[x][y] == p1.icon)
			{
				p1move << x << " " << y << endl;
			}
		}
	}

	p1move.close();

	// Save p2 location

	ofstream p2move;
	p2move.open("save_pvp/" + filename + "p2.txt");

	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (Board[x][y] == p2.icon)
			{
				p2move << x << " " << y << endl;
			}
		}
	}

	p2move.close();

	// Save the figure of the board

	ofstream figure;
	figure.open("save_pvp/" + filename + "figure.txt");

	figure << size << endl;
	figure << p1.icon << " " << p1.color << endl;
	figure << p2.icon << " " << p2.color << endl;

	figure.close();

}


void savePvC(vector<vector<string>> Board, int size, Object p, Object b, int mode) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
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
		cout << filename + "exsit. Do you want to overwrite it" << endl;
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


	// Save p location
	ofstream pmove;

	pmove.open("save_pvc/" + filename + "p.txt");

	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (Board[x][y] == p.icon)
			{
				pmove << x << " " << y << endl;
			}
		}
	}

	pmove.close();

	// Save bot location

	ofstream bmove;
	bmove.open("save_pvc/" + filename + "b.txt");

	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (Board[x][y] == b.icon)
			{
				bmove << x << " " << y << endl;
			}
		}
	}

	bmove.close();

	// Save the figure of the board

	ofstream figure;
	figure.open("save_pvc/" + filename + "figure.txt");

	figure << size << endl;
	figure << p.icon << " " << p.color << endl;
	figure << b.icon << " " << b.color << endl;
	figure << mode << endl;

	figure.close();

}