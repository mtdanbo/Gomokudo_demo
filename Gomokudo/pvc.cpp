#include "pvc.h"

int gameMode(int maxDepth, int maxMove, int mode)
{
	Color color;
	getColor(color);
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	//Require the user choose the size of the board
	int size;
	cout << "Please choose the size of your board: ";
	cin >> size;

	//Set up two object player vs bot
	Object player;
	player.x = 0;
	player.y = 0;
	player.icon = "X";
	player.color = red;
	player.Score.resize(100, vector<int>(100, 0));
	player.turn = 1;
	player.undo = 0;

	Object bot;
	bot.x = 0;
	bot.y = 0;
	bot.icon = "O";
	bot.color = green;
	bot.Score.resize(100, vector<int>(100, 0));
	bot.turn = 0;
	bot.undo = 0;

	//Set up the board
	vector<string> temp{ 100,"_" };
	vector<vector<string>> board{ 100,temp };

	// Draw board
	system("cls");
	board = drawBoard(size, board, player, bot);

	//Main game
	while (1)
	{

		if (player.turn == 1 && bot.turn == 0)
		{
			/*-------------------- Player zone--------------------------*/

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player.color);
			gotoXY(player.x, player.y);

			// Require the use control p1

			player = pControl_char(player, size, board);

			if (player.undo == 0)
			{
				board[player.x / 2][player.y] = player.icon;
				player.historyMove.push_back(make_pair(player.x / 2, player.y));
				player.win = Compute(player, size, board);
			}

			player.turn = 0;
			bot.turn = 1;

			// Compute player win or loose

			if (player.win == 1)
			{
				animateP1Win(size);

				leaderboard_pvc_save(player, bot, size, board);
				break;
			}

			// Save game

			if (player.save == 1)
			{
				savePvC(board, size, player, bot, mode);
				break;
			}

			// Undo

			if (player.undo == 1)
			{
				undoPvC(player, bot, board, size);
			}

			if (player.quit == 1)
			{
				return 0;
			}


		}

		if (player.turn == 0 && bot.turn == 1)
		{
			/*------------------Computer zone-------------------*/

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bot.color);

			int depth = 0;
			int miniMax = 0;

			Point point;

			findMove(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);

			board[point.x][point.y] = bot.icon;

			player.turn = 1;
			bot.turn = 0;

			bot.historyMove.push_back(make_pair(point.x, point.y));

			//Compute bot win or loose

			bot.win = Compute(bot, size, board);
			if (bot.win == 1)
			{
				animateBotWin(size);

				leaderboard_pvc_save(player, bot, size, board);

				break;
			}
		}


	}
}

void PvC_mode() {

	system("cls");

	vector<string> mode = { "Easy mode", "Normal mode", "Hard mode" };

	int choice = controlMenuByArrow(mode);

	if (choice == 0)
	{
		gameMode(maxDepthEasy, maxMoveEasy, choice + 1);
	}

	if (choice == 1)
	{
		gameMode(maxDepthMed, maxMoveMed, choice + 1);
	}
	if (choice == 2)
	{
		gameMode(maxDepthHard, maxMoveHard, choice + 1);
	}


}