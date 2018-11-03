#include "pvp.h"

void PvP_mode() {
	ifstream pvp;
	pvp.open("text/pvp.txt");
	animateText(pvp);
	char key = _getch();
	while (key != '1' && key != '2' && key != '3')
	{
		key = _getch();
	}

	if (key == '3')
	{
		// Initialize player properties

		Object p1;
		p1.x = 0;
		p1.y = 0;
		p1.turn = 0;
		p1.undo = 0;

		vector <pair<int, int>> p1undo;

		Object p2;
		p2.x = 0;
		p2.y = 0;
		p2.turn = 0;
		p2.undo = 0;

		vector <pair<int, int>> p2undo;

		// Require user choose the size of the board

		system("cls");
		int size;
		cout << "Plz choose your board size: ";
		cin >> size;

		// Require user choose icon
		system("cls");
		cout << "Plz choose icon for each player" << endl;
		cout << "Player 1: ";
		cin >> p1.icon;
		cout << "Player 2: ";
		cin >> p2.icon;

		// Require user choose icon color

		system("cls");
		cout << "Our default color is red for p1 and green for p2. Do you want to convert it ???" << endl;
		cout << "(Y/N): ";
		char change;
		cin >> change;
		if (change == 'Y' || change == 'y')
		{
			p1.color = green;
			p2.color = red;
		}
		if (change == 'N' || change == 'n')
		{
			p1.color = red;
			p2.color = green;
		}


		//Who go first
		system("cls");
		cout << "Who will go first p1 or p2" << endl;
		cout << "Press 1 if you want p1 go first" << endl;
		cout << "Press 2 if you want p2 go first" << endl;
		cout << "Your choice is: ";
		int go_first;
		cin >> go_first;
		while (go_first != 1 && go_first != 2)
		{
			cout << "Wrong please choose again" << endl;
			cout << "Your choice is: ";
			cin >> go_first;
		}

		if (go_first == 1)
		{
			p1.turn = 1;
			p2.turn = 0;

		}
		if (go_first == 2)
		{
			p1.turn = 0;
			p2.turn = 1;
		}

		// Draw the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> Board{ 100,temp };
		Board = drawBoard(size, Board, temp, p1, p2);

		gotoXY((size + 5) * 2, 0);
		cout << "Press L if you want to save the game";
		gotoXY((size + 5) * 2, 1);
		cout << "Press U if you want to undo the game";

		// Gameplay
		while (1)
		{
			if (p1.turn == 1 && p2.turn == 0)
			{
				// P1 Zone
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
				gotoXY(p1.x, p1.y);
				// Require the use control p1
				p1 = pControl_char(p1, size, Board);

				if (p1.undo != 1)
				{
					Board[p1.x / 2][p1.y] = p1.icon;
					p1undo.push_back(make_pair(p1.x / 2, p1.y));


					// Compute p1 win or loose
					p1.win = Compute(p1, size, Board);
				}

				p1.turn = 0;
				p2.turn = 1;


				if (p1.win == 1)
				{
					animateP1Win(size);

					leaderboard_pvp(p1, p2, size, Board);

					break;
				}

				if (p1.undo == 1 || p2.undo == 1)
				{
					undop1(p1, p2, p1undo, p2undo, Board, size, temp, go_first);
				}




				if (p1.save == 1 || p2.save == 1)
				{
					savePvP(Board, size, p1, p2);
					break;
				}
			}

			if (p2.turn == 1 && p1.turn == 0)
			{
				//P2 Zone
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
				gotoXY(p2.x, p2.y);
				// Require the use control p2
				p2 = pControl_num(p2, size, Board);

				if (p2.undo != 1)
				{
					Board[p2.x / 2][p2.y] = p2.icon;
					p2undo.push_back(make_pair(p2.x / 2, p2.y));

					// Compute p2 win or loose
					p2.win = Compute(p2, size, Board);
				}



				p1.turn = 1;
				p2.turn = 0;





				if (p2.win == 1)
				{
					animateP2Win(size);
					leaderboard_pvp(p1, p2, size, Board);

					break;
				}

				if (p1.undo == 1 || p2.undo == 1)
				{
					undop2(p1, p2, p1undo, p2undo, Board, size, temp, go_first);

				}


				if (p1.save == 1 || p2.save == 1)
				{
					savePvP(Board, size, p1, p2);
					break;
				}
			}
		}


	}



}