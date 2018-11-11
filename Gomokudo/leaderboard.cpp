#include "leaderboard.h"

#pragma region Leaderboard PvP
void leaderboard_pvp_save(Object player1, Object player2, int size, vector<vector<string>> board) {

	Color color;
	getColor(color);

	gotoXY((size * 2 + 2) * 2, 3);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	int exist = 0;

	while (!leaderboard_name_read.eof())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{

			exist = 1;

			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;

				break;
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				leaderboard_name_read.close();


				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exist == 0)
	{
		leaderboard_name_read.close();


		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;
		leaderboard_name_write << 0 << endl;

		leaderboard_name_write.close();
	}


	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_pvp/" + name + ".txt");


	if (player1.win == 1)
	{
		leaderboard_write << "winner" << " " << player1.icon + "_Player1" << endl;
		leaderboard_write << "looser" << " " << player2.icon + "_Player2" << endl;
	}
	if (player2.win == 1)
	{
		leaderboard_write << "winner" << " " << player2.icon + "_Player2" << endl;
		leaderboard_write << "looser" << " " << player1.icon + "_Player1" << endl;
	}
	if (player1.win == 0 && player2.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_pvp/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move_write << x << " " << y << endl;
			}
		}
	}


	p1move_write.close();

	ofstream p2move_write;

	p2move_write.open("leaderboard_pvp/" + name + "p2.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}
	p2move_write.close();

	ofstream figure;
	figure.open("leaderboard_pvp/" + name + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;

	figure.close();

}

void leaderboard_pvp_load(string filename)
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Set figure
	ifstream figure;
	figure.open("leaderboard_pvp/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_pvp/" + filename + "p1.txt");
	int p1X;
	int p1Y;
	while (!p1move.eof())
	{
		p1move >> p1X;
		p1move >> p1Y;
		board[p1X][p1Y] = p1.icon;
	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_pvp/" + filename + "p2.txt");
	int p2X;
	int p2Y;
	while (!p2move.eof())
	{
		p2move >> p2X;
		p2move >> p2Y;
		board[p2X][p2Y] = p2.icon;
	}

	p2move.close();

	drawBoard(size, board, p1, p2,pvpConfig.boardColor);
}

void leaderboard_rule1_save(Object player1, Object player2, Object rock, int size, vector<vector<string>> board) {

	Color color;
	getColor(color);

	gotoXY((size * 2 + 2) * 2, 4);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	int exist = 0;

	while (!leaderboard_name_read.eof())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{

			exist = 1;

			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;

				break;
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				leaderboard_name_read.close();


				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exist == 0)
	{
		leaderboard_name_read.close();


		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;
		leaderboard_name_write << 1 << endl;

		leaderboard_name_write.close();
	}


	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_rule1/" + name + ".txt");


	if (player1.win == 1)
	{
		leaderboard_write << "winner" << " " << player1.icon + "_Player1" << endl;
		leaderboard_write << "looser" << " " << player2.icon + "_Player2" << endl;
	}
	if (player2.win == 1)
	{
		leaderboard_write << "winner" << " " << player2.icon + "_Player2" << endl;
		leaderboard_write << "looser" << " " << player1.icon + "_Player1" << endl;
	}
	if (player1.win == 0 && player2.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_rule1/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move_write << x << " " << y << endl;
			}
		}
	}


	p1move_write.close();

	ofstream p2move_write;

	p2move_write.open("leaderboard_rule1/" + name + "p2.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}
	p2move_write.close();

	ofstream rockmove_write;
	rockmove_write.open("leaderboard_rule1/" + name + "rock.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == rock.icon)
			{
				rockmove_write << x << " " << y << endl;
			}
		}
	}
	rockmove_write.close();

	ofstream figure;
	figure.open("leaderboard_rule1/" + name + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << rock.icon << " " << rock.color << endl;

	figure.close();

}

void leaderboard_rule1_load(string filename)
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Set figure
	ifstream figure;
	figure.open("leaderboard_rule1/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;
	Object rock;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;
	figure >> rock.icon;
	figure >> rock.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_rule1/" + filename + "p1.txt");
	int p1X;
	int p1Y;
	while (!p1move.eof())
	{
		p1move >> p1X;
		p1move >> p1Y;
		board[p1X][p1Y] = p1.icon;
	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_rule1/" + filename + "p2.txt");
	int p2X;
	int p2Y;
	while (!p2move.eof())
	{
		p2move >> p2X;
		p2move >> p2Y;
		board[p2X][p2Y] = p2.icon;
	}

	p2move.close();

	ifstream rockmove;
	rockmove.open("leaderboard_rule1/" + filename + "rock.txt");
	int rockX;
	int rockY;
	int numRock = 0;
	while (!rockmove.eof())
	{
		rockmove >> rockX;
		rockmove >> rockY;
		board[rockX][rockY] = rock.icon;
		numRock++;
	}

	numRock--;

	rockmove.close();

	drawBoardRule1(size, board, p1, p2, rock, pvpConfig.boardColor, numRock);
}

void leaderboard_rule2_save(Object player1, Object player2, Object rock, int size, vector<vector<string>> board) {

	Color color;
	getColor(color);

	gotoXY((size * 2 + 2) * 2, 4);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	int exist = 0;

	while (!leaderboard_name_read.eof())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{

			exist = 1;

			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;

				break;
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				leaderboard_name_read.close();


				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exist == 0)
	{
		leaderboard_name_read.close();


		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;
		leaderboard_name_write << 2 << endl;

		leaderboard_name_write.close();
	}


	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_rule2/" + name + ".txt");


	if (player1.win == 1)
	{
		leaderboard_write << "winner" << " " << player1.icon + "_Player1" << endl;
		leaderboard_write << "looser" << " " << player2.icon + "_Player2" << endl;
	}
	if (player2.win == 1)
	{
		leaderboard_write << "winner" << " " << player2.icon + "_Player2" << endl;
		leaderboard_write << "looser" << " " << player1.icon + "_Player1" << endl;
	}
	if (player1.win == 0 && player2.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_rule2/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move_write << x << " " << y << endl;
			}
		}
	}


	p1move_write.close();

	ofstream p2move_write;

	p2move_write.open("leaderboard_rule2/" + name + "p2.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}
	p2move_write.close();

	ofstream rockmove_write;
	rockmove_write.open("leaderboard_rule2/" + name + "rock.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == rock.icon)
			{
				rockmove_write << x << " " << y << endl;
			}
		}
	}
	rockmove_write.close();

	ofstream figure;
	figure.open("leaderboard_rule2/" + name + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << rock.icon << " " << rock.color << endl;

	figure.close();

}

void leaderboard_rule2_load(string filename)
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Set figure
	ifstream figure;
	figure.open("leaderboard_rule2/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;
	Object rock;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;
	figure >> rock.icon;
	figure >> rock.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_rule2/" + filename + "p1.txt");
	int p1X;
	int p1Y;
	while (!p1move.eof())
	{
		p1move >> p1X;
		p1move >> p1Y;
		if (p1X >= 0 && p1Y >= 0)
		{
			board[p1X][p1Y] = p1.icon;
		}
		
	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_rule2/" + filename + "p2.txt");
	int p2X;
	int p2Y;
	while (!p2move.eof())
	{
		p2move >> p2X;
		p2move >> p2Y;

		if (p2X >= 0 && p2Y >= 0)
		{
			board[p2X][p2Y] = p2.icon;
		}
		
	}

	p2move.close();

	ifstream rockmove;
	rockmove.open("leaderboard_rule2/" + filename + "rock.txt");
	int rockX;
	int rockY;
	int numRock = 0;
	while (!rockmove.eof())
	{
		rockmove >> rockX;
		rockmove >> rockY;

		if (rockX >= 0 && rockY >= 0)
		{
			board[rockX][rockY] = rock.icon;
		}
		
	}
	rockmove.close();

	drawBoardRule2(size, board, p1, p2, rock, pvpConfig.boardColor);
}

void leaderboard_rule3_save(Object player1, Object player2, int size, vector<vector<string>> board) {

	Color color;
	getColor(color);

	gotoXY((size * 2 + 2) * 2, 4);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	int exist = 0;

	while (!leaderboard_name_read.eof())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{

			exist = 1;

			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;

				break;
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				leaderboard_name_read.close();


				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exist == 0)
	{
		leaderboard_name_read.close();


		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;
		leaderboard_name_write << 3 << endl;

		leaderboard_name_write.close();
	}


	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_rule3/" + name + ".txt");


	if (player1.win == 1)
	{
		leaderboard_write << "winner" << " " << player1.icon + "_Player1" << endl;
		leaderboard_write << "looser" << " " << player2.icon + "_Player2" << endl;
	}
	if (player2.win == 1)
	{
		leaderboard_write << "winner" << " " << player2.icon + "_Player2" << endl;
		leaderboard_write << "looser" << " " << player1.icon + "_Player1" << endl;
	}
	if (player1.win == 0 && player2.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_rule3/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move_write << x << " " << y << endl;
			}
		}
	}


	p1move_write.close();

	ofstream p2move_write;

	p2move_write.open("leaderboard_rule3/" + name + "p2.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}
	p2move_write.close();

	ofstream figure;
	figure.open("leaderboard_rule3/" + name + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;

	figure.close();

}

void leaderboard_rule3_load(string filename)
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Set figure
	ifstream figure;
	figure.open("leaderboard_rule3/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_rule3/" + filename + "p1.txt");
	int p1X;
	int p1Y;
	while (!p1move.eof())
	{
		p1move >> p1X;
		p1move >> p1Y;
		if (p1X >= 0 && p1Y >= 0)
		{
			board[p1X][p1Y] = p1.icon;
		}
		
	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_rule3/" + filename + "p2.txt");
	int p2X;
	int p2Y;
	while (!p2move.eof())
	{
		p2move >> p2X;
		p2move >> p2Y;

		if (p2X >= 0 && p2Y >= 0)
		{
			board[p2X][p2Y] = p2.icon;
		}
		
	}

	p2move.close();

	drawBoard(size, board, p1, p2, pvpConfig.boardColor);
}

void leaderboard_rule4_save(Object player1, Object player2, int size, vector<vector<string>> board) {

	Color color;
	getColor(color);

	gotoXY((size * 2 + 2) * 2, 4);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	int exist = 0;

	while (!leaderboard_name_read.eof())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{

			exist = 1;

			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;

				break;
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				leaderboard_name_read.close();


				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exist == 0)
	{
		leaderboard_name_read.close();


		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;
		leaderboard_name_write << 4 << endl;

		leaderboard_name_write.close();
	}


	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_rule4/" + name + ".txt");


	if (player1.win == 1)
	{
		leaderboard_write << "winner" << " " << player1.icon + "_Player1" << endl;
		leaderboard_write << "looser" << " " << player2.icon + "_Player2" << endl;
	}
	if (player2.win == 1)
	{
		leaderboard_write << "winner" << " " << player2.icon + "_Player2" << endl;
		leaderboard_write << "looser" << " " << player1.icon + "_Player1" << endl;
	}
	if (player1.win == 0 && player2.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_rule4/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move_write << x << " " << y << endl;
			}
		}
	}

	p1move_write.close();

	ofstream p2move_write;

	p2move_write.open("leaderboard_rule4/" + name + "p2.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}


	p2move_write.close();

	ofstream figure;
	figure.open("leaderboard_rule4/" + name + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;

	figure.close();

}

void leaderboard_rule4_load(string filename)
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Set figure
	ifstream figure;
	figure.open("leaderboard_rule4/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_rule4/" + filename + "p1.txt");
	int p1X;
	int p1Y;
	while (!p1move.eof())
	{
		p1move >> p1X;
		p1move >> p1Y;
		if (p1X >= 0 && p1Y >= 0)
		{
			board[p1X][p1Y] = p1.icon;
		}
		
	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_rule4/" + filename + "p2.txt");
	int p2X;
	int p2Y;
	while (!p2move.eof())
	{
		p2move >> p2X;
		p2move >> p2Y;

		if (p2X >= 0 && p2Y >= 0)
		{
			board[p2X][p2Y] = p2.icon;
		}
		
	}

	p2move.close();

	drawBoard(size, board, p1, p2, pvpConfig.boardColor);
}

void leaderboard_rule5_save(Object player1, Object player2, int size, vector<vector<string>> board) {

	Color color;
	getColor(color);

	gotoXY((size * 2 + 2) * 2, 4);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	int exist = 0;

	while (!leaderboard_name_read.eof())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{

			exist = 1;

			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;

				break;
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				leaderboard_name_read.close();


				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exist == 0)
	{
		leaderboard_name_read.close();


		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;
		leaderboard_name_write << 5 << endl;

		leaderboard_name_write.close();
	}


	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_rule5/" + name + ".txt");


	if (player1.win == 1)
	{
		leaderboard_write << "winner" << " " << player1.icon + "_Player1" << endl;
		leaderboard_write << "looser" << " " << player2.icon + "_Player2" << endl;
	}
	if (player2.win == 1)
	{
		leaderboard_write << "winner" << " " << player2.icon + "_Player2" << endl;
		leaderboard_write << "looser" << " " << player1.icon + "_Player1" << endl;
	}
	if (player1.win == 0 && player2.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_rule5/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move_write << x << " " << y << endl;
			}
		}
	}


	p1move_write.close();

	ofstream p2move_write;

	p2move_write.open("leaderboard_rule5/" + name + "p2.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}
	p2move_write.close();

	ofstream figure;
	figure.open("leaderboard_rule5/" + name + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;

	figure.close();

}

void leaderboard_rule5_load(string filename)
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Set figure
	ifstream figure;
	figure.open("leaderboard_rule5/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_rule5/" + filename + "p1.txt");
	int p1X;
	int p1Y;
	while (!p1move.eof())
	{
		p1move >> p1X;
		p1move >> p1Y;
		if (p1X >= 0 && p1Y >= 0)
		{
			board[p1X][p1Y] = p1.icon;
		}
		
	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_rule5/" + filename + "p2.txt");
	int p2X;
	int p2Y;
	while (!p2move.eof())
	{
		p2move >> p2X;
		p2move >> p2Y;

		if (p2X >= 0 && p2Y >= 0)
		{
			board[p2X][p2Y] = p2.icon;
		}
		
	}

	p2move.close();

	drawBoard(size, board, p1, p2, pvpConfig.boardColor);
}

void leaderboard_rule6_save(Object player1, Object player2, int size, vector<vector<string>> board) {

	Color color;
	getColor(color);

	gotoXY((size * 2 + 2) * 2, 3);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	int exist = 0;

	while (!leaderboard_name_read.eof())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{

			exist = 1;

			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;

				break;
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				leaderboard_name_read.close();


				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exist == 0)
	{
		leaderboard_name_read.close();


		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;
		leaderboard_name_write << 6 << endl;

		leaderboard_name_write.close();
	}


	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_rule6/" + name + ".txt");


	if (player1.win == 1)
	{
		leaderboard_write << "winner" << " " << player1.icon + "_Player1" << endl;
		leaderboard_write << "looser" << " " << player2.icon + "_Player2" << endl;
	}
	if (player2.win == 1)
	{
		leaderboard_write << "winner" << " " << player2.icon + "_Player2" << endl;
		leaderboard_write << "looser" << " " << player1.icon + "_Player1" << endl;
	}
	if (player1.win == 0 && player2.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_rule6/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move_write << x << " " << y << endl;
			}
		}
	}


	p1move_write.close();

	ofstream p2move_write;

	p2move_write.open("leaderboard_rule6/" + name + "p2.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}
	p2move_write.close();

	ofstream figure;
	figure.open("leaderboard_rule6/" + name + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;

	figure.close();

}

void leaderboard_rule6_load(string filename)
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Set figure
	ifstream figure;
	figure.open("leaderboard_rule6/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_rule6/" + filename + "p1.txt");
	int p1X;
	int p1Y;
	while (!p1move.eof())
	{
		p1move >> p1X;
		p1move >> p1Y;
		if (p1X >= 0 && p1Y >= 0)
		{
			board[p1X][p1Y] = p1.icon;
		}

	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_rule6/" + filename + "p2.txt");
	int p2X;
	int p2Y;
	while (!p2move.eof())
	{
		p2move >> p2X;
		p2move >> p2Y;

		if (p2X >= 0 && p2Y >= 0)
		{
			board[p2X][p2Y] = p2.icon;
		}

	}

	p2move.close();

	drawBoard(size, board, p1, p2, pvpConfig.boardColor);
}

void leaderboard_rule7_save(Object player1, Object player2, int size, vector<vector<string>> board) {

	Color color;
	getColor(color);

	gotoXY((size * 2 + 2) * 2, 4);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	int exist = 0;

	while (!leaderboard_name_read.eof())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{

			exist = 1;

			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;

				break;
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				leaderboard_name_read.close();


				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exist == 0)
	{
		leaderboard_name_read.close();


		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;
		leaderboard_name_write << 7 << endl;

		leaderboard_name_write.close();
	}


	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_rule7/" + name + ".txt");


	if (player1.win == 1)
	{
		leaderboard_write << "winner" << " " << player1.icon + "_Player1" << endl;
		leaderboard_write << "looser" << " " << player2.icon + "_Player2" << endl;
	}
	if (player2.win == 1)
	{
		leaderboard_write << "winner" << " " << player2.icon + "_Player2" << endl;
		leaderboard_write << "looser" << " " << player1.icon + "_Player1" << endl;
	}
	if (player1.win == 0 && player2.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_rule7/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move_write << x << " " << y << endl;
			}
		}
	}


	p1move_write.close();

	ofstream p2move_write;

	p2move_write.open("leaderboard_rule7/" + name + "p2.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}
	p2move_write.close();

	ofstream figure;
	figure.open("leaderboard_rule7/" + name + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;

	figure.close();

}

void leaderboard_rule7_load(string filename)
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Set figure
	ifstream figure;
	figure.open("leaderboard_rule7/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_rule7/" + filename + "p1.txt");
	int p1X;
	int p1Y;
	while (!p1move.eof())
	{
		p1move >> p1X;
		p1move >> p1Y;
		if (p1X >= 0 && p1Y >= 0)
		{
			board[p1X][p1Y] = p1.icon;
		}

	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_rule7/" + filename + "p2.txt");
	int p2X;
	int p2Y;
	while (!p2move.eof())
	{
		p2move >> p2X;
		p2move >> p2Y;

		if (p2X >= 0 && p2Y >= 0)
		{
			board[p2X][p2Y] = p2.icon;
		}

	}

	p2move.close();

	drawBoard(size, board, p1, p2, pvpConfig.boardColor);
}

void leaderboard_rule8_save(Object player1, Object player2, int size, vector<vector<string>> board) {

	Color color;
	getColor(color);

	gotoXY((size * 2 + 2) * 2, 4);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	int exist = 0;

	while (!leaderboard_name_read.eof())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{

			exist = 1;

			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;

				break;
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				leaderboard_name_read.close();


				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exist == 0)
	{
		leaderboard_name_read.close();


		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;
		leaderboard_name_write << 8 << endl;

		leaderboard_name_write.close();
	}


	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_rule8/" + name + ".txt");


	if (player1.win == 1)
	{
		leaderboard_write << "winner" << " " << player1.icon + "_Player1" << endl;
		leaderboard_write << "looser" << " " << player2.icon + "_Player2" << endl;
	}
	if (player2.win == 1)
	{
		leaderboard_write << "winner" << " " << player2.icon + "_Player2" << endl;
		leaderboard_write << "looser" << " " << player1.icon + "_Player1" << endl;
	}
	if (player1.win == 0 && player2.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_rule8/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player1.icon)
			{
				p1move_write << x << " " << y << endl;
			}
		}
	}


	p1move_write.close();

	ofstream p2move_write;

	p2move_write.open("leaderboard_rule8/" + name + "p2.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}
	p2move_write.close();

	ofstream figure;
	figure.open("leaderboard_rule8/" + name + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;

	figure.close();

}

void leaderboard_rule8_load(string filename)
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Set figure
	ifstream figure;
	figure.open("leaderboard_rule8/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_rule8/" + filename + "p1.txt");
	int p1X;
	int p1Y;
	while (!p1move.eof())
	{
		p1move >> p1X;
		p1move >> p1Y;
		if (p1X >= 0 && p1Y >= 0)
		{
			board[p1X][p1Y] = p1.icon;
		}

	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_rule8/" + filename + "p2.txt");
	int p2X;
	int p2Y;
	while (!p2move.eof())
	{
		p2move >> p2X;
		p2move >> p2Y;

		if (p2X >= 0 && p2Y >= 0)
		{
			board[p2X][p2Y] = p2.icon;
		}

	}

	p2move.close();

	drawBoard(size, board, p1, p2, pvpConfig.boardColor);
}

void leaderboard_pvp_show()
{
	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
	system("cls");

	ifstream pvp_leaderboard;
	pvp_leaderboard.open("text/pvp_leaderboard.txt");

	gotoXY(0, 0);
	cout << "Name" << endl;
	gotoXY(20, 0);
	cout << "Winner" << endl;
	gotoXY(40, 0);
	cout << "Looser" << endl;
	gotoXY(60, 0);
	cout << "Rule" << endl;
	gotoXY(80, 0);
	cout << "Detail" << endl;

	int index = 1;
	vector<pair<string, int>> data_name;

	//Name zone
	while (!pvp_leaderboard.eof())
	{
		string filename;
		int rule;
		pvp_leaderboard >> filename;
		pvp_leaderboard >> rule;

		data_name.push_back(make_pair(filename,rule));
	}

	data_name.pop_back();

	for (int i = 0; i < data_name.size(); i++)
	{
		string filename = data_name[i].first;

		if (data_name[i].second == 0)
		{
			gotoXY(0, index);
			cout << index << "." << filename;

			ifstream status;
			status.open("leaderboard_pvp/" + filename + ".txt");

			string temp;

			string winner;
			status >> temp;
			status >> winner;

			string loser;
			status >> temp;
			status >> loser;

			gotoXY(20, index);
			cout << winner;

			gotoXY(40, index);
			cout << loser;

			status.close();

			gotoXY(60, index);

			cout << data_name[i].second;

			gotoXY(80, index);
			cout << "More detail" << endl;
		}
		if (data_name[i].second == 1)
		{
			gotoXY(0, index);
			cout << index << "." << filename;

			ifstream status;
			status.open("leaderboard_rule1/" + filename + ".txt");

			string temp;

			string winner;
			status >> temp;
			status >> winner;

			string loser;
			status >> temp;
			status >> loser;

			gotoXY(20, index);
			cout << winner;

			gotoXY(40, index);
			cout << loser;

			status.close();

			gotoXY(60, index);

			cout << data_name[i].second;

			gotoXY(80, index);
			cout << "More detail" << endl;
		}
		if (data_name[i].second == 2)
		{
			gotoXY(0, index);
			cout << index << "." << filename;

			ifstream status;
			status.open("leaderboard_rule2/" + filename + ".txt");

			string temp;

			string winner;
			status >> temp;
			status >> winner;

			string loser;
			status >> temp;
			status >> loser;

			gotoXY(20, index);
			cout << winner;

			gotoXY(40, index);
			cout << loser;

			status.close();

			gotoXY(60, index);

			cout << data_name[i].second;

			gotoXY(80, index);
			cout << "More detail" << endl;
		}
		if (data_name[i].second == 3)
		{
			gotoXY(0, index);
			cout << index << "." << filename;

			ifstream status;
			status.open("leaderboard_rule3/" + filename + ".txt");

			string temp;

			string winner;
			status >> temp;
			status >> winner;

			string loser;
			status >> temp;
			status >> loser;

			gotoXY(20, index);
			cout << winner;

			gotoXY(40, index);
			cout << loser;

			status.close();

			gotoXY(60, index);

			cout << data_name[i].second;

			gotoXY(80, index);
			cout << "More detail" << endl;
		}
		if (data_name[i].second == 4)
		{
			gotoXY(0, index);
			cout << index << "." << filename;

			ifstream status;
			status.open("leaderboard_rule4/" + filename + ".txt");

			string temp;

			string winner;
			status >> temp;
			status >> winner;

			string loser;
			status >> temp;
			status >> loser;

			gotoXY(20, index);
			cout << winner;

			gotoXY(40, index);
			cout << loser;

			status.close();

			gotoXY(60, index);

			cout << data_name[i].second;

			gotoXY(80, index);
			cout << "More detail" << endl;
		}
		if (data_name[i].second == 5)
		{
			gotoXY(0, index);
			cout << index << "." << filename;

			ifstream status;
			status.open("leaderboard_rule5/" + filename + ".txt");

			string temp;

			string winner;
			status >> temp;
			status >> winner;

			string loser;
			status >> temp;
			status >> loser;

			gotoXY(20, index);
			cout << winner;

			gotoXY(40, index);
			cout << loser;

			status.close();

			gotoXY(60, index);

			cout << data_name[i].second;

			gotoXY(80, index);
			cout << "More detail" << endl;
		}
		if (data_name[i].second == 6)
		{
			gotoXY(0, index);
			cout << index << "." << filename;

			ifstream status;
			status.open("leaderboard_rule6/" + filename + ".txt");

			string temp;

			string winner;
			status >> temp;
			status >> winner;

			string loser;
			status >> temp;
			status >> loser;

			gotoXY(20, index);
			cout << winner;

			gotoXY(40, index);
			cout << loser;

			status.close();

			gotoXY(60, index);

			cout << data_name[i].second;

			gotoXY(80, index);
			cout << "More detail" << endl;
		}
		if (data_name[i].second == 7)
		{
			gotoXY(0, index);
			cout << index << "." << filename;

			ifstream status;
			status.open("leaderboard_rule7/" + filename + ".txt");

			string temp;

			string winner;
			status >> temp;
			status >> winner;

			string loser;
			status >> temp;
			status >> loser;

			gotoXY(20, index);
			cout << winner;

			gotoXY(40, index);
			cout << loser;

			status.close();

			gotoXY(60, index);

			cout << data_name[i].second;

			gotoXY(80, index);
			cout << "More detail" << endl;
		}
		if (data_name[i].second == 8)
		{
			gotoXY(0, index);
			cout << index << "." << filename;

			ifstream status;
			status.open("leaderboard_rule8/" + filename + ".txt");

			string temp;

			string winner;
			status >> temp;
			status >> winner;

			string loser;
			status >> temp;
			status >> loser;

			gotoXY(20, index);
			cout << winner;

			gotoXY(40, index);
			cout << loser;

			status.close();

			gotoXY(60, index);

			cout << data_name[i].second;

			gotoXY(80, index);
			cout << "More detail" << endl;
		}
		index++;
	}

	pvp_leaderboard.close();

	gotoXY(0, 1);

	int cursor_x = 0;
	int cursor_y = 1;

	while (1)
	{
		char key = _getch();

		if (key == arrowLeft)
		{
			if (cursor_x == 0)
			{
				cursor_x = cursor_x;
			}
			else
			{
				cursor_x = cursor_x - 20;
			}

		}
		if (key == arrowRight)
		{
			if (cursor_x == 80)
			{
				cursor_x = cursor_x;
			}
			else
			{
				cursor_x = cursor_x + 20;
			}

		}
		if (key == arrowUp)
		{
			if (cursor_y == 1)
			{
				cursor_y = cursor_y;
			}
			else
			{
				cursor_y = cursor_y - 1;
			}


		}
		if (key == arrowDown)
		{
			if (cursor_y == index - 1)
			{
				cursor_y = cursor_y;
			}
			else
			{
				cursor_y = cursor_y + 1;
			}
		}

		gotoXY(cursor_x, cursor_y);

		if (key == 13 && cursor_x == 80)
		{
			system("cls");

			if (data_name[cursor_y - 1].second == 0)
			{
				leaderboard_pvp_load(data_name[cursor_y - 1].first);
			}
			if (data_name[cursor_y - 1].second == 1)
			{
				leaderboard_rule1_load(data_name[cursor_y - 1].first);
			}
			if (data_name[cursor_y - 1].second == 2)
			{
				leaderboard_rule2_load(data_name[cursor_y - 1].first);
			}
			if (data_name[cursor_y - 1].second == 3)
			{
				leaderboard_rule3_load(data_name[cursor_y - 1].first);
			}
			if (data_name[cursor_y - 1].second == 4)
			{
				leaderboard_rule4_load(data_name[cursor_y - 1].first);
			}
			if (data_name[cursor_y - 1].second == 5)
			{
				leaderboard_rule5_load(data_name[cursor_y - 1].first);
			}
			if (data_name[cursor_y - 1].second == 6)
			{
				leaderboard_rule6_load(data_name[cursor_y - 1].first);
			}
			if (data_name[cursor_y - 1].second == 7)
			{
				leaderboard_rule7_load(data_name[cursor_y - 1].first);
			}
			if (data_name[cursor_y - 1].second == 8)
			{
				leaderboard_rule8_load(data_name[cursor_y - 1].first);
			}
			break;
		}

	}


	system("pause");

}
#pragma endregion

#pragma region Leaderboard PvC
void leaderboard_pvc_save(Object player, Object bot, int size, vector<vector<string>> board)
{
	gotoXY((size * 2 + 2) * 2, 3);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvc_leaderboard.txt", ios_base::app);

	int exsit = 0;

	while (!leaderboard_name_read.eof())
	{
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{
			exsit = 1;
			system("cls");
			cout << "Your name you have type exist" << endl;
			cout << "Do you want to overwrite it " << endl;
			cout << "(Y/N): ";
			char key = _getch();

			while (key != 'Y' && key != 'y' && key != 'N' && key != 'n')
			{
				key = _getch();
			}

			if (key == 'Y' || key == 'y')
			{
				cout << "OK" << endl;
				system("pause");
			}
			if (key == 'N' || key == 'n')
			{
				system("cls");
				cout << "Please enter your new name";
				cin >> name;

				ofstream leaderboard_name_write;
				leaderboard_name_write.open("text/pvc_leaderboard.txt", ios_base::app);

				leaderboard_name_write << name << endl;

				leaderboard_name_write.close();

				break;
			}
		}

	}

	if (exsit == 0)
	{
		ofstream leaderboard_name_write;
		leaderboard_name_write.open("text/pvc_leaderboard.txt", ios_base::app);

		leaderboard_name_write << name << endl;

		leaderboard_name_write.close();
	}



	leaderboard_name_read.close();

	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_pvc/" + name + ".txt");


	if (player.win == 1)
	{
		leaderboard_write << "winner" << " " << player.icon + "_Player" << endl;
		leaderboard_write << "loser" << " " << bot.icon + "_Bot" << endl;
	}
	if (bot.win == 1)
	{
		leaderboard_write << "winner" << " " << bot.icon + "_Bot" << endl;
		leaderboard_write << "loser" << " " << player.icon + "_Player" << endl;
	}

	if (player.win == 0 && bot.win == 0)
	{
		leaderboard_write << "winner" << " " << "Draw" << endl;
		leaderboard_write << "loser" << " " << "Draw" << endl;
	}


	leaderboard_write.close();


	ofstream playerMove_Write;

	playerMove_Write.open("leaderboard_pvc/" + name + "p.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == player.icon)
			{
				playerMove_Write << x << " " << y << endl;
			}
		}
	}


	playerMove_Write.close();

	ofstream botMove_Write;

	botMove_Write.open("leaderboard_pvc/" + name + "b.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (board[x][y] == bot.icon)
			{
				botMove_Write << x << " " << y << endl;
			}
		}
	}


	botMove_Write.close();

	ofstream figure;
	figure.open("leaderboard_pvc/" + name + "figure.txt");

	figure << size << endl;
	figure << player.icon << " " << player.color << endl;
	figure << bot.icon << " " << bot.color << endl;
	figure.close();
}

void leaderboard_pvc_load(string filename)
{
	PvCConfig pvcConfig;
	getPvCConfig(pvcConfig);

	ifstream figure;
	figure.open("leaderboard_pvc/" + filename + "figure.txt", ios_base::app);

	int size;
	figure >> size;

	Object player;
	Object bot;

	figure >> player.icon >> player.color;
	figure >> bot.icon >> bot.color;

	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };

	figure.close();

	ifstream playerMove;
	playerMove.open("leaderboard_pvc/" + filename + "p.txt", ios_base::app);

	while (!playerMove.eof())
	{
		int x_temp, y_temp;

		playerMove >> x_temp >> y_temp;

		board[x_temp][y_temp] = player.icon;

	}

	playerMove.close();


	ifstream botMove;
	botMove.open("leaderboard_pvc/" + filename + "b.txt", ios_base::app);

	while (!botMove.eof())
	{
		int x_temp, y_temp;

		botMove >> x_temp >> y_temp;

		board[x_temp][y_temp] = bot.icon;

	}

	botMove.close();


	drawBoard(size, board, player, bot,pvcConfig.boardColor);

}

void leaderboard_pvc_show()
{
	system("cls");
	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	ifstream pvc_leaderboard;
	pvc_leaderboard.open("text/pvc_leaderboard.txt", ios_base::app);

	gotoXY(0, 0);
	cout << "Name" << endl;
	gotoXY(20, 0);
	cout << "Winner" << endl;
	gotoXY(40, 0);
	cout << "Looser" << endl;
	gotoXY(60, 0);
	cout << "Detail" << endl;

	int index = 1;
	vector<string> data_name;

	//Name zone
	while (!pvc_leaderboard.eof())
	{
		string filename;
		pvc_leaderboard >> filename;

		data_name.push_back(filename);
	}

	data_name.pop_back();

	for (int i = 0; i < data_name.size(); i++)
	{
		string filename = data_name[i];

		gotoXY(0, index);
		cout << index << "." << filename;

		ifstream status;
		status.open("leaderboard_pvc/" + filename + ".txt");

		string temp;

		string winner;
		status >> temp;
		status >> winner;

		string loser;
		status >> temp;
		status >> loser;

		gotoXY(20, index);
		cout << winner;

		gotoXY(40, index);
		cout << loser;

		status.close();

		gotoXY(60, index);
		cout << "More detail" << endl;

		index++;
	}

	pvc_leaderboard.close();

	gotoXY(0, 1);

	int cursor_x = 0;
	int cursor_y = 1;

	while (1)
	{
		char key = _getch();

		if (key == 'A' || key == 'a')
		{
			if (cursor_x == 0)
			{
				cursor_x = cursor_x;
			}
			else
			{
				cursor_x = cursor_x - 20;
			}

		}
		if (key == 'D' || key == 'd')
		{
			if (cursor_x == 60)
			{
				cursor_x = cursor_x;
			}
			else
			{
				cursor_x = cursor_x + 20;
			}

		}
		if (key == 'W' || key == 'w')
		{
			if (cursor_y == 1)
			{
				cursor_y = cursor_y;
			}
			else
			{
				cursor_y = cursor_y - 1;
			}


		}
		if (key == 'S' || key == 's')
		{
			if (cursor_y == index - 1)
			{
				cursor_y = cursor_y;
			}
			else
			{
				cursor_y = cursor_y + 1;
			}
		}

		gotoXY(cursor_x, cursor_y);

		if (key == 13 && cursor_x == 60)
		{
			system("cls");

			leaderboard_pvc_load(data_name[cursor_y - 1]);

			break;
		}

	}


	system("pause");

}
#pragma endregion



void leaderboard()
{
	int width = getConsoleWidth();
	int height = getConsoleHeight();

	gotoXY(width / 2 - 15, height / 2 - 1);

	ifstream leaderboardIntro;
	leaderboardIntro.open("text/leaderboard_intro.txt");
	animateText(leaderboardIntro);
	leaderboardIntro.close();
	Sleep(2000);
	vector<string> type = { "PvP","PvC" , "Rule", "Back" };
	while (1)
	{
		int choice = controlMenuByArrow(type);

		if (choice == 0)
		{
			leaderboard_pvp_show();
		}

		if (choice == 1)
		{
			leaderboard_pvc_show();
		}
		if (choice == 2)
		{

		}
		if (choice == 3)
		{
			break;
		}
	}




}





