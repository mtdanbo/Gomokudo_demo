#include "rule.h"

int rule1()
{
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	// Initialize player properties

	Object player1;
	player1.turn = 0;
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
	player2.turn = 0;
	player2.icon = pvpConfig.secondIcon;
	player2.color = pvpConfig.secondColor;

	Object obstacle;
	obstacle.icon = "R";
	obstacle.color = purple;

	system("cls");
	int size = pvpConfig.sizeBoard;

	int goFirst;

	if (pvpConfig.goFirst == "main")
	{
		goFirst = 1;
	}

	if (pvpConfig.goFirst == "second")
	{
		goFirst = 2;
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

	int numRock = 15;

	for (int i = 0; i < numRock; i++)
	{
		int randomX = rand() % size;
		int randomY = rand() % size;

		board[randomX][randomY] = obstacle.icon;
	}

	board = drawBoardRule1(size, board, player1, player2, obstacle);

	

	// Gameplay
	while (1)
	{
		if (player1.turn == 1 && player2.turn == 0)
		{
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1)
			{
				board[player1.x / 2][player1.y] = player1.icon;
				player1.historyMove.push_back(make_pair(player1.x / 2, player1.y));


				// Compute p1 win or loose
				player1.win = ComputeN(player1, size, board);
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
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1)
			{
				board[player2.x / 2][player2.y] = player2.icon;
				player2.historyMove.push_back(make_pair(player2.x / 2, player2.y));

				// Compute p2 win or loose
				player2.win = ComputeN(player2, size, board);
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

int rule2()
{
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	// Initialize player properties

	Object player1;
	player1.turn = 0;
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
	player2.turn = 0;
	player2.icon = pvpConfig.secondIcon;
	player2.color = pvpConfig.secondColor;

	Object obstacle;
	obstacle.icon = "R";
	obstacle.color = purple;

	system("cls");
	int size = pvpConfig.sizeBoard;

	int goFirst;

	if (pvpConfig.goFirst == "main")
	{
		goFirst = 1;
	}

	if (pvpConfig.goFirst == "second")
	{
		goFirst = 2;
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

	drawBoard(size, board, player1, player2, pvpConfig.boardColor);

	// Gameplay
	while (1)
	{
		if (player1.turn == 1 && player2.turn == 0)
		{
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1)
			{
				board[player1.x / 2][player1.y] = player1.icon;
				player1.historyMove.push_back(make_pair(player1.x / 2, player1.y));


				// Compute p1 win or loose
				player1.win = ComputeN(player1, size, board);
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

			int randomX = rand() % size;
			int randomY = rand() % size;

			while (board[randomX][randomY] != "_")
			{
				randomX = rand() % size;
				randomY = rand() % size;
			}

			gotoXY(randomX * 2, randomY);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), purple);

			cout << obstacle.icon;
			board[randomX][randomY] = obstacle.icon;
		}

		if (player2.turn == 1 && player1.turn == 0)
		{
			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1)
			{
				board[player2.x / 2][player2.y] = player2.icon;
				player2.historyMove.push_back(make_pair(player2.x / 2, player2.y));

				// Compute p2 win or loose
				player2.win = ComputeN(player2, size, board);
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

			int randomX = rand() % size;

			int randomY = rand() % size;

			while (board[randomX][randomY] != "_")
			{
				randomX = rand() % size;
				randomY = rand() % size;
			}

			gotoXY(randomX * 2, randomY);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), purple);

			cout << obstacle.icon;
			board[randomX][randomY] = obstacle.icon;
		}



	}
}

int rule3()
{
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	// Initialize player properties

	Object player1;
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
	player2.icon = pvpConfig.secondIcon;
	player2.color = pvpConfig.secondColor;

	system("cls");
	int size = pvpConfig.sizeBoard;

	int goFirst;

	if (pvpConfig.goFirst == "main")
	{
		goFirst = 1;

	}

	if (pvpConfig.goFirst == "second")
	{
		goFirst = 2;
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


	board = drawBoard(size, board, player1, player2,pvpConfig.boardColor);

	int changeTime = 0;

	// Gameplay
	while (1)
	{
		if (changeTime == 10)
		{

			for (int i = 0; i < player1.historyMove.size(); i++)
			{
				board[player1.historyMove[i].first][player1.historyMove[i].second] = player2.icon;
			}

			for (int i = 0; i < player2.historyMove.size(); i++)
			{
				board[player2.historyMove[i].first][player2.historyMove[i].second] = player1.icon;
			}

			changeTime = 0;
			drawBoard(size, board, player1, player2,pvpConfig.boardColor);

			swap(player1.icon, player2.icon);
			swap(player1.color, player2.color);

		}





		if (player1.turn == 1 && player2.turn == 0)
		{
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1)
			{
				board[player1.x / 2][player1.y] = player1.icon;
				player1.historyMove.push_back(make_pair(player1.x / 2, player1.y));


				// Compute p1 win or loose
				player1.win = ComputeN(player1, size, board);
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

			changeTime++;
		}

		if (player2.turn == 1 && player1.turn == 0)
		{
			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1)
			{
				board[player2.x / 2][player2.y] = player2.icon;
				player2.historyMove.push_back(make_pair(player2.x / 2, player2.y));

				// Compute p2 win or loose
				player2.win = ComputeN(player2, size, board);
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
			changeTime++;
		}
	}
}

int rule4()
{
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	// Initialize player properties

	Object player1;
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
	player2.icon = pvpConfig.secondIcon;
	player2.color = pvpConfig.secondColor;

	system("cls");
	int size = pvpConfig.sizeBoard;

	int goFirst;

	if (pvpConfig.goFirst == "main")
	{
		goFirst = 1;

	}

	if (pvpConfig.goFirst == "second")
	{
		goFirst = 2;
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


	board = drawBoard(size, board, player1, player2,pvpConfig.boardColor);

	int changeTime = 0;

	int changeSize = 1;


	// Gameplay
	while (1)
	{
		if (changeTime == 5)
		{

			size = size - changeSize;

			for (int x = 0; x < size; x++)
			{
				board[x][size - 1] = "_";
				board[x][0] = "_";
			}

			for (int y = 0; y < size; y++)
			{
				board[0][y] = "_";
				board[size - 1][y] = "_";
			}

			drawBoard(size, board, player1, player2,pvpConfig.boardColor);

			changeTime = 0;
		}

		if (player1.turn == 1 && player2.turn == 0)
		{
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1)
			{
				board[player1.x / 2][player1.y] = player1.icon;
				player1.historyMove.push_back(make_pair(player1.x / 2, player1.y));


				// Compute p1 win or loose
				player1.win = ComputeN(player1, size, board);
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

			changeTime++;
		}

		if (changeTime == 5)
		{

			size = size - changeSize;

			for (int x = 0; x < size; x++)
			{
				board[x][size - 1] = "_";
				board[x][0] = "_";
			}

			for (int y = 0; y < size; y++)
			{
				board[0][y] = "_";
				board[size - 1][y] = "_";
			}

			drawBoard(size, board, player1, player2,pvpConfig.boardColor);

			changeTime = 0;
		}

		if (player2.turn == 1 && player1.turn == 0)
		{
			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1)
			{
				board[player2.x / 2][player2.y] = player2.icon;
				player2.historyMove.push_back(make_pair(player2.x / 2, player2.y));

				// Compute p2 win or loose
				player2.win = ComputeN(player2, size, board);
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
			changeTime++;
		}
	}


}

int rule5()
{
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	// Initialize player properties

	Object player1;
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
	player2.icon = pvpConfig.secondIcon;
	player2.color = pvpConfig.secondColor;

	Object boom;
	boom.icon = "B";
	
	system("cls");
	int size = pvpConfig.sizeBoard;

	int goFirst;

	if (pvpConfig.goFirst == "main")
	{
		goFirst = 1;

	}

	if (pvpConfig.goFirst == "second")
	{
		goFirst = 2;
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


	int boomNum = 8;

	vector<pair<int, int>> boomPos;

	int currentBoom = 0;

	while (currentBoom < boomNum)
	{

		int boomX = rand() % size;
		int boomY = rand() % size;
		int check = 0;

		for (int i = 0; i < boomPos.size(); i++)
		{
			if (boomPos[i].first == boomX && boomPos[i].second == boomY)
			{
				check = 1;
			}
		}

		if (check == 0)
		{
			boomPos.push_back(make_pair(boomX, boomY));
			currentBoom++;
		}
		if (check == 1)
		{
			currentBoom = currentBoom;

		}

	}

	for (int i = 0; i < boomPos.size(); i++)
	{
		board[boomPos[i].first][boomPos[i].second] = boom.icon;
	}


	board = drawBoardRule5(size, board, player1, player2,currentBoom);

	// Gameplay
	while (1)
	{

		if (player1.turn == 1 && player2.turn == 0)
		{
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1)
			{

				if (board[player1.x / 2][player1.y] == "B")
				{
					int boomX = player1.x / 2;
					int boomY = player1.y;

					board[boomX - 1][boomY - 1] = "_";
					board[boomX - 1][boomY] = "_";
					board[boomX - 1][boomY + 1] = "_";
					board[boomX][boomY - 1] = "_";
					board[boomX][boomY] = "_";
					board[boomX][boomY + 1] = "_";
					board[boomX + 1][boomY - 1] = "_";
					board[boomX + 1][boomY] = "_";
					board[boomX + 1][boomY + 1] = "_";

					currentBoom--;

					drawBoardRule5(size, board, player1, player2, currentBoom);

					player1.historyMove.clear();
					player2.historyMove.clear();
				}
				else
				{
					board[player1.x / 2][player1.y] = player1.icon;
					player1.historyMove.push_back(make_pair(player1.x / 2, player1.y));
				}
				// Compute p1 win or loose
				player1.win = ComputeN(player1, size, board);
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
				undop1Rule5(player1, player2, board, size, goFirst,currentBoom);
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
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1)
			{
				if (board[player2.x / 2][player2.y] == "B")
				{
					int boomX = player2.x / 2;
					int boomY = player2.y;


					board[boomX - 1][boomY - 1] = "_";
					board[boomX - 1][boomY] = "_";
					board[boomX - 1][boomY + 1] = "_";
					board[boomX][boomY - 1] = "_";
					board[boomX][boomY] = "_";
					board[boomX][boomY + 1] = "_";
					board[boomX + 1][boomY - 1] = "_";
					board[boomX + 1][boomY] = "_";
					board[boomX + 1][boomY + 1] = "_";

					currentBoom--;

					drawBoardRule5(size, board, player1, player2,currentBoom);
					player1.historyMove.clear();
					player2.historyMove.clear();
				}
				else
				{
					board[player2.x / 2][player2.y] = player2.icon;
					player2.historyMove.push_back(make_pair(player2.x / 2, player2.y));
				}

				// Compute p2 win or loose
				player2.win = ComputeN(player2, size, board);
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
				undop2Rule5(player1, player2, board, size, goFirst,currentBoom);

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

int rule6()
{
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	// Initialize player properties

	Object player1;
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
	player2.icon = pvpConfig.secondIcon;
	player2.color = pvpConfig.secondColor;

	system("cls");
	int size = pvpConfig.sizeBoard;

	int goFirst;

	if (pvpConfig.goFirst == "main")
	{
		goFirst = 1;

	}

	if (pvpConfig.goFirst == "second")
	{
		goFirst = 2;
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


	board = drawBoard(size, board, player1, player2,pvpConfig.boardColor);

	int restrictMove = 3;
	int numMainMove = 0;
	int numSecondMove = 0;

	// Gameplay
	while (1)
	{
		if (player1.turn == 1 && player2.turn == 0)
		{

			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControlRule6(player1, size, board,numMainMove,restrictMove);

			if (player1.undo != 1)
			{
				board[player1.x / 2][player1.y] = player1.icon;
				player1.historyMove.push_back(make_pair(player1.x / 2, player1.y));


				// Compute p1 win or loose
				player1.win = ComputeN(player1, size, board);
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
			player2 = secondControlRule6(player2, size, board,numSecondMove,restrictMove);

			if (player2.undo != 1)
			{
				board[player2.x / 2][player2.y] = player2.icon;
				player2.historyMove.push_back(make_pair(player2.x / 2, player2.y));

				// Compute p2 win or loose
				player2.win = ComputeN(player2, size, board);
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

int rule7()
{
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	// Initialize player properties

	Object player1;
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
	player2.icon = pvpConfig.secondIcon;
	player2.color = pvpConfig.secondColor;

	system("cls");
	int size = pvpConfig.sizeBoard;

	int goFirst;

	if (pvpConfig.goFirst == "main")
	{
		goFirst = 1;

	}

	if (pvpConfig.goFirst == "second")
	{
		goFirst = 2;
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


	board = drawBoard(size, board, player1, player2,pvpConfig.boardColor);

	int lastXPosMain = 1000000;
	int lastYPosMain = 1000000;

	int lastXPosSecond = 1000000;
	int lastYPosSecond = 1000000;

	int range;

	// Gameplay
	while (1)
	{
		range = rand() % 5 + 1;
		if (player1.turn == 1 && player2.turn == 0)
		{

			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControlRule7(player1, size, board, lastXPosMain, lastYPosMain, range);

			lastXPosMain = player1.x / 2;
			lastYPosMain = player1.y;

			if (player1.undo != 1)
			{
				board[player1.x / 2][player1.y] = player1.icon;
				player1.historyMove.push_back(make_pair(player1.x / 2, player1.y));


				// Compute p1 win or loose
				player1.win = ComputeN(player1, size, board);
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

		range = rand() % 5 + 1;

		if (player2.turn == 1 && player1.turn == 0)
		{


			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControlRule7(player2, size, board, lastXPosSecond, lastYPosSecond,range);

			lastXPosSecond = player2.x / 2;
			lastYPosSecond = player2.y;

			if (player2.undo != 1)
			{
				board[player2.x / 2][player2.y] = player2.icon;
				player2.historyMove.push_back(make_pair(player2.x / 2, player2.y));

				// Compute p2 win or loose
				player2.win = ComputeN(player2, size, board);
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

int rule8()
{
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	// Initialize player properties

	Object player1;
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
	player2.icon = pvpConfig.secondIcon;
	player2.color = pvpConfig.secondColor;

	Object changed;
	changed.icon = "C";

	system("cls");
	int size = pvpConfig.sizeBoard;

	int goFirst;

	if (pvpConfig.goFirst == "main")
	{
		goFirst = 1;

	}

	if (pvpConfig.goFirst == "second")
	{
		goFirst = 2;
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


	int changedItem = 8;

	vector<pair<int, int>> changedPos;

	int currentChangedItem = 0;

	while (currentChangedItem < changedItem)
	{

		int changedX = rand() % size;
		int changedY = rand() % size;
		int check = 0;

		for (int i = 0; i < changedPos.size(); i++)
		{
			if (changedPos[i].first == changedX && changedPos[i].second == changedY)
			{
				check = 1;
			}
		}

		if (check == 0)
		{
			changedPos.push_back(make_pair(changedX, changedY));
			currentChangedItem++;
		}
		if (check == 1)
		{
			currentChangedItem = currentChangedItem;

		}

	}

	for (int i = 0; i < changedPos.size(); i++)
	{
		board[changedPos[i].first][changedPos[i].second] = changed.icon;
	}


	board = drawBoardRule8(size, board, player1, player2, currentChangedItem);

	// Gameplay
	while (1)
	{

		if (player1.turn == 1 && player2.turn == 0)
		{
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1)
			{

				if (board[player1.x / 2][player1.y] == "C")
				{
					board[player1.x / 2][player1.y] = player2.icon;
					currentChangedItem--;
					drawBoardRule8(size, board, player1, player2, currentChangedItem);
					

					player1.historyMove.clear();
					player2.historyMove.clear();

				}
				else
				{
					board[player1.x / 2][player1.y] = player1.icon;
					player1.historyMove.push_back(make_pair(player1.x / 2, player1.y));
				}
				// Compute p1 win or loose
				player1.win = ComputeN(player1, size, board);
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
				undop1Rule8(player1, player2, board, size, goFirst, currentChangedItem);
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
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1)
			{
				if (board[player2.x / 2][player2.y] == "C")
				{
					board[player2.x / 2][player2.y] = player1.icon;
					currentChangedItem--;
					drawBoardRule8(size, board, player1, player2, currentChangedItem);
					

					player1.historyMove.clear();
					player2.historyMove.clear();

				}
				else
				{
					board[player2.x / 2][player2.y] = player2.icon;
					player2.historyMove.push_back(make_pair(player2.x / 2, player2.y));
				}

				// Compute p2 win or loose
				player2.win = ComputeN(player2, size, board);
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
				undop2Rule8(player1, player2, board, size, goFirst, currentChangedItem);

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