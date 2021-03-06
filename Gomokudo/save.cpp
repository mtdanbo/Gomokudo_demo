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

void saveRule1(vector<vector<string>> board, int size, Object player1, Object player2, Object obstacle) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;


	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/rule1_savelist.txt", ios_base::app);
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
		savelist.open("text/rule1_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_rule1/" + filename + "p1.txt");

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
	p2move.open("save_rule1/" + filename + "p2.txt");

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

	// Save p2 location

	ofstream obstaclemove;
	obstaclemove.open("save_rule1/" + filename + "o.txt");

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == obstacle.icon)
			{
				obstaclemove << x << " " << y << endl;
			}
		}
	}

	obstaclemove << "-1 -1" << endl;

	obstaclemove.close();

	// Save the figure of the board

	ofstream figure;
	figure.open("save_rule1/" + filename + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << obstacle.icon << " " << obstacle.color << endl;
	figure << 1 - player1.turn << " " << 1 - player2.turn << endl;

	figure.close();

}

void saveRule2(vector<vector<string>> board, int size, Object player1, Object player2, Object obstacle) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;


	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/rule2_savelist.txt", ios_base::app);
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
		savelist.open("text/rule2_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_rule2/" + filename + "p1.txt");

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
	p2move.open("save_rule2/" + filename + "p2.txt");

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

	// Save p2 location

	ofstream obstaclemove;
	obstaclemove.open("save_rule2/" + filename + "o.txt");

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (board[x][y] == obstacle.icon)
			{
				obstaclemove << x << " " << y << endl;
			}
		}
	}

	obstaclemove << "-1 -1" << endl;

	obstaclemove.close();

	// Save the figure of the board

	ofstream figure;
	figure.open("save_rule2/" + filename + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << obstacle.icon << " " << obstacle.color << endl;
	figure << 1 - player1.turn << " " << 1 - player2.turn << endl;

	figure.close();

}

void saveRule3(vector<vector<string>> board, int size, Object player1, Object player2, int currentTime, int changeTime) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;


	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/rule3_savelist.txt", ios_base::app);
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
		savelist.open("text/rule3_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_rule3/" + filename + "p1.txt");

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
	p2move.open("save_rule3/" + filename + "p2.txt");

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
	figure.open("save_rule3/" + filename + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << 1 - player1.turn << " " << 1 - player2.turn << endl;
	figure << currentTime << endl;
	figure << changeTime << endl;

	figure.close();

}

void saveRule4(vector<vector<string>> board, int size, Object player1, Object player2, int currentTime, int changeTime, int changeSize) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;


	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/rule4_savelist.txt", ios_base::app);
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
		savelist.open("text/rule4_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_rule4/" + filename + "p1.txt");

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
	p2move.open("save_rule4/" + filename + "p2.txt");

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
	figure.open("save_rule4/" + filename + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << 1 - player1.turn << " " << 1 - player2.turn << endl;
	figure << currentTime << endl;
	figure << changeTime << endl;
	figure << changeSize << endl;

	figure.close();

}

void saveRule5(vector<vector<string>> board, int size, Object player1, Object player2, Object boom, vector<pair<int,int>> boomPos) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;


	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/rule5_savelist.txt", ios_base::app);
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
		savelist.open("text/rule5_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_rule5/" + filename + "p1.txt");

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
	p2move.open("save_rule5/" + filename + "p2.txt");

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

	ofstream boomMove;
	boomMove.open("save_rule5/" + filename + "boom.txt");

	for (int x = 0; x < boomPos.size(); x++)
	{
		for (int y = 0; y < boomPos.size(); y++)
		{
			if (board[x][y] == boom.icon)
			{
				boomMove << x << " " << y << endl;
			}
		}
	}

	boomMove << "-1 -1" << endl;

	boomMove.close();

	// Save the figure of the board

	ofstream figure;
	figure.open("save_rule5/" + filename + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << boom.icon << " " << boom.color << endl;
	figure << 1 - player1.turn << " " << 1 - player2.turn << endl;

	figure.close();

}

void saveRule6(vector<vector<string>> board, int size, Object player1, Object player2, int restrictMove) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;


	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/rule6_savelist.txt", ios_base::app);
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
		savelist.open("text/rule6_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_rule6/" + filename + "p1.txt");

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
	p2move.open("save_rule6/" + filename + "p2.txt");

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
	figure.open("save_rule6/" + filename + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << 1 - player1.turn << " " << 1 - player2.turn << endl;
	figure << restrictMove << endl;
	figure.close();

}

void saveRule7(vector<vector<string>> board, int size, Object player1, Object player2, int range) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;


	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/rule7_savelist.txt", ios_base::app);
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
		savelist.open("text/rule7_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_rule7/" + filename + "p1.txt");

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
	p2move.open("save_rule7/" + filename + "p2.txt");

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
	figure.open("save_rule7/" + filename + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << 1 - player1.turn << " " << 1 - player2.turn << endl;
	figure << range << endl;


	figure.close();

}

void saveRule8(vector<vector<string>> board, int size, Object player1, Object player2, Object changed, vector<pair<int, int>> changedPos) {

	// Require user enter file name
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	cout << "Please enter your name to save file: ";
	string filename;
	cin >> filename;


	// Check file name exist or not
	ifstream savelist_check;
	int exist = 0;
	savelist_check.open("text/rule8_savelist.txt", ios_base::app);
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
		savelist.open("text/rule8_savelist.txt", ios_base::app);

		savelist << filename << endl;

		savelist.close();
	}


	// Save p1 location
	ofstream p1move;

	p1move.open("save_rule8/" + filename + "p1.txt");

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
	p2move.open("save_rule8/" + filename + "p2.txt");

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

	ofstream boomMove;
	boomMove.open("save_rule8/" + filename + "changed.txt");

	for (int x = 0; x < changedPos.size(); x++)
	{
		for (int y = 0; y < changedPos.size(); y++)
		{
			if (board[x][y] == changed.icon)
			{
				boomMove << x << " " << y << endl;
			}
		}
	}

	boomMove << "-1 -1" << endl;

	boomMove.close();

	// Save the figure of the board

	ofstream figure;
	figure.open("save_rule8/" + filename + "figure.txt");

	figure << size << endl;
	figure << player1.icon << " " << player1.color << endl;
	figure << player2.icon << " " << player2.color << endl;
	figure << changed.icon << " " << changed.color << endl;
	figure << 1 - player1.turn << " " << 1 - player2.turn << endl;

	figure.close();

}
