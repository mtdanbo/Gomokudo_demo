#include "pvc.h"

int gameMode(int maxDepth, int maxMove, int mode)
{
	#pragma region Initial Start
	PvCConfig pvcConfig;
	getPvCConfig(pvcConfig);

	Color color;
	getColor(color);
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	int size = pvcConfig.sizeBoard;

	//Set up two object player vs bot
	Object player;
	player.icon = pvcConfig.playerIcon;
	player.color = pvcConfig.playerColor;
	player.Score.resize(100, vector<int>(100, 0));

	Object bot;
	bot.icon = pvcConfig.botIcon;
	bot.color = pvcConfig.botColor;
	bot.Score.resize(100, vector<int>(100, 0));

	//Set up the board
	vector<string> temp{ 100,"_" };
	vector<vector<string>> board{ 100,temp };

	if (pvcConfig.goFirst == "player")
	{
		player.turn = 1;
		bot.turn = 0;
	}
	if (pvcConfig.goFirst == "bot")
	{
		player.turn = 0;
		bot.turn = 1;
	}
#pragma endregion

	// Draw board
	system("cls");
	board = drawBoard(size, board, player, bot,pvcConfig.boardColor);

	//Main game
	while (1)
	{

		if (player.turn == 1 && bot.turn == 0)
		{
			#pragma region Player zone

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player.color);
			gotoXY(player.x, player.y);

			// Require the use control p1

			player = mainControl(player, size, board);

			if (player.undo != 1 && player.save != 1 && player.quit != 1)
			{
				board[(player.x - 2) / 4][(player.y - 1) / 2] = player.icon;
				player.historyMove.push_back(make_pair((player.x - 2) / 4, (player.y - 1) / 2));
				if (size > 4)
				{
					player.win = ComputeN(player, size, board);
				}
				if (size == 3)
				{
					player.win = Compute3(player, size, board);
				}
				if (size == 4)
				{
					player.win = Compute4(player, size, board);
				}
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

			int checkDraw = 1;

			for (int x = 0; x < size; x++)
			{
				for (int y = 0; y < size; y++)
				{

					if (board[x][y] == "_")
					{
						checkDraw = 0;
					}

				}
			}

			if (checkDraw == 1)
			{
				animateDraw(size);
				leaderboard_pvc_save(player, bot, size, board);
				break;
			}

			#pragma endregion	

		}

		if (player.turn == 0 && bot.turn == 1)
		{
			#pragma region Compute Zone

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bot.color);

			int depth = 0;
			int miniMax = 0;

			Point point;

			if (size > 4)
			{
				findMove(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point,player,bot);
			}
			if (size == 3)
			{
				findMove3(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point,player,bot);
			}
			if (size == 4)
			{
				findMove4(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point,player,bot);
			}

			board[point.x][point.y] = bot.icon;

			player.turn = 1;
			bot.turn = 0;

			bot.historyMove.push_back(make_pair(point.x, point.y));

			//Compute bot win or loose
			if (size > 4)
			{
				bot.win = ComputeN(bot, size, board);
			}
			if (size == 3)
			{
				bot.win = Compute3(bot, size, board);
			}
			if (size == 4)
			{
				bot.win = Compute4(bot, size, board);
			}


			if (bot.win == 1)
			{
				animateBotWin(size);

				leaderboard_pvc_save(player, bot, size, board);

				break;
			}

			int checkDraw = 1;

			for (int x = 0; x < size; x++)
			{
				for (int y = 0; y < size; y++)
				{

					if (board[x][y] == "_")
					{
						checkDraw = 0;
					}

				}
			}

			if (checkDraw == 1)
			{
				animateDraw(size);
				leaderboard_pvc_save(player, bot, size, board);
				break;
			}

			#pragma endregion
		}
	}
}

void PvC_mode() {

	system("cls");

	vector<string> mode = { "Easy mode", "Normal mode", "Hard mode","Back" };
	while (1)
	{
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
		if (choice == 3)
		{
			break;
		}
	}


}