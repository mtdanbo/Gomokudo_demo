#include "leaderboard.h"

void leaderboard_pvp(Object p1, Object p2, int size, vector<vector<string>> Board) {

	gotoXY((size + 5) * 2, 2);
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	ifstream leaderboard_name_read;
	leaderboard_name_read.open("text/pvp_leaderboard.txt", ios_base::app);

	while (!leaderboard_name_read.eof())
	{
		string temp_name;
		leaderboard_name_read >> temp_name;

		if (temp_name == name)
		{
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
			}
			if (key == 'N' || key == 'n')
			{
				cout << "Please enter your new name";
				cin >> name;
			}
		}

	}

	leaderboard_name_read.close();


	ofstream leaderboard_name_write;
	leaderboard_name_write.open("text/pvp_leaderboard.txt", ios_base::app);

	leaderboard_name_write << name << endl;

	leaderboard_name_write.close();





	ofstream leaderboard_write;

	leaderboard_write.open("leaderboard_pvp/" + name + ".txt");
	

	if (p1.win == 1)
	{
		leaderboard_write << "winner" << " " << p1.icon << endl;
		leaderboard_write << "looser" << " " << p2.icon << endl;
	}
	else
	{
		leaderboard_write << "winner" << " " << p2.icon << endl;
		leaderboard_write << "looser" << " " << p1.icon << endl;
	}


	leaderboard_write.close();


	ofstream p1move_write;

	p1move_write.open("leaderboard_pvp/" + name + "p1.txt");

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (Board[x][y] == p1.icon)
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
			if (Board[x][y] == p2.icon)
			{
				p2move_write << x << " " << y << endl;
			}
		}
	}


	p2move_write.close();

}

void leaderboard_pvp_load(string filename)
{
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
	vector<vector<string>> Board{ 100,temp };


	ifstream p1move;
	p1move.open("leaderboard_pvp/" + filename + "p1.txt");
	int p1_x;
	int p1_y;
	while (!p1move.eof())
	{
		p1move >> p1_x;
		p1move >> p1_y;
		Board[p1_x][p1_y] = p1.icon;
	}

	p1move.close();

	ifstream p2move;
	p2move.open("leaderboard_pvp/" + filename + "p2.txt");
	int p2_x;
	int p2_y;
	while (!p2move.eof())
	{
		p2move >> p2_x;
		p2move >> p2_y;
		Board[p2_x][p2_y] = p2.icon;
	}

	p2move.close();

	Board = drawBoard(size, Board, temp, p1, p2);
}

void leaderboard_show()
{
	ifstream leaderboard_intro;
	leaderboard_intro.open("text/leaderboard_intro.txt");

	animateText(leaderboard_intro);

	leaderboard_intro.close();

	char key = _getch();

	while (key != '1' && key != '2')
	{
		key = _getch();
	}

	if (key == '1')
	{
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
		cout << "Detail" << endl;

		int index = 1;
		vector<string> data_name;

		//Name zone
		while (!pvp_leaderboard.eof())
		{
			string filename;
			pvp_leaderboard >> filename;

			data_name.push_back(filename);

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
			cout << "More detail" << endl;

			index++;

		}

		pvp_leaderboard.close();

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

				leaderboard_pvp_load(data_name[cursor_y - 1]);

				break;
			}

		}


		system("pause");

	}


}

