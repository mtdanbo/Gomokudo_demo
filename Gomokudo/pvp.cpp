#include "pvp.h"

int PvP_mode() {
	system("cls");
	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	int width = getConsoleWidth();
	int height = getConsoleHeight();

	gotoXY(width / 2 - 15, height/2 - 1);
	ifstream pvp;
	pvp.open("text/pvp.txt");
	animateText(pvp);

	gotoXY(width / 2, height / 2);
	system("pause");

	system("cls");

	vector<string> type = { "3 x 3","4 x 4","N x N (N > 4)" };

	int choice = controlMenuByArrow(type);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	if (choice == 2)
	{
		// Initialize player properties

		Object player1;
		player1.turn = 0;


		Object player2;
		player2.turn = 0;


		// Require user choose the size of the board

		system("cls");
		int size;
		cout << "Plz choose your board size: ";
		cin >> size;

		// Require user choose icon
		system("cls");
		cout << "Plz choose icon for each player" << endl;
		cout << "Player 1: ";
		cin >> player1.icon;
		cout << "Player 2: ";
		cin >> player2.icon;

		// Require user choose icon color

		system("cls");
		cout << "Our default color is red for p1 and green for p2. Do you want to convert it ???" << endl;
		cout << "(Y/N): ";
		char change;
		cin >> change;
		if (change == 'Y' || change == 'y')
		{
			player1.color = green;
			player2.color = red;
		}
		if (change == 'N' || change == 'n')
		{
			player1.color = red;
			player2.color = green;
		}


		//Who go first
		system("cls");
		cout << "Who will go first p1 or p2" << endl;
		cout << "Press 1 if you want p1 go first" << endl;
		cout << "Press 2 if you want p2 go first" << endl;
		cout << "Your choice is: ";
		int goFirst;
		cin >> goFirst;
		while (goFirst != 1 && goFirst != 2)
		{
			cout << "Wrong please choose again" << endl;
			cout << "Your choice is: ";
			cin >> goFirst;
		}

		if (goFirst == 1)
		{
			player1.turn = 1;
			player2.turn = 0;

		}
		if (goFirst == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		// Draw the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };
		board = drawBoard(size, board, player1, player2);

		// Gameplay
		while (1)
		{
			if (player1.turn == 1 && player2.turn == 0)
			{
				// P1 Zone
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
				gotoXY(player1.x, player1.y);
				// Require the use control p1
				player1 = pControl_char(player1, size, board);

				if (player1.undo != 1)
				{
					board[player1.x / 2][player1.y] = player1.icon;
					player1.historyMove.push_back(make_pair(player1.x / 2, player1.y));


					// Compute p1 win or loose
					player1.win = Compute(player1, size, board);
				}

				player1.turn = 0;
				player2.turn = 1;


				if (player1.win == 1)
				{
					animateP1Win(size);

					leaderboard_pvp_save(player1, player2, size, board);

					break;
				}

				if (player1.undo == 1 || player2.undo == 1)
				{
					undop1(player1, player2, board, size, goFirst);
				}

				if (player1.save == 1 || player2.save == 1)
				{
					savePvP(board, size, player1, player2);
					break;
				}

				if (player1.quit == 1 || player2.quit == 1)
				{
					return 0;
				}
			}

			if (player2.turn == 1 && player1.turn == 0)
			{
				//P2 Zone
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
				gotoXY(player2.x, player2.y);
				// Require the use control p2
				player2 = pControl_num(player2, size, board);

				if (player2.undo != 1)
				{
					board[player2.x / 2][player2.y] = player2.icon;
					player2.historyMove.push_back(make_pair(player2.x / 2, player2.y));

					// Compute p2 win or loose
					player2.win = Compute(player2, size, board);
				}

				player1.turn = 1;
				player2.turn = 0;

				if (player2.win == 1)
				{
					animateP2Win(size);
					leaderboard_pvp_save(player1, player2, size, board);

					break;
				}

				if (player1.undo == 1 || player2.undo == 1)
				{
					undop2(player1, player2, board, size, goFirst);

				}


				if (player1.save == 1 || player2.save == 1)
				{
					savePvP(board, size, player1, player2);
					break;
				}

				if (player1.quit == 1 || player2.quit == 1)
				{
					return 0;
				}
			}
		}


	}



}