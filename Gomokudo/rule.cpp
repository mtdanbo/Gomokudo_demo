#include "rule.h"

int rule1()
{

	#pragma region Initial Start
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	// Initialize player properties

	Object player1;
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
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
#pragma endregion

	// Draw the board
	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };

	#pragma region Initial Num Rock

	int numRock = size * size / 8;

	for (int i = 0; i < numRock; i++)
	{
		int randomX = rand() % size;
		int randomY = rand() % size;

		board[randomX][randomY] = obstacle.icon;
	}

	#pragma endregion

	board = drawBoardRule1(size, board, player1, player2, obstacle, pvpConfig.boardColor, numRock);

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

			if (player1.undo != 1 && player1.save != 1 && player1.quit != 1)
			{
				board[(player1.x - 2) / 4][(player1.y - 1) / 2] = player1.icon;
				player1.historyMove.push_back(make_pair((player1.x - 2) / 4, (player1.y - 1) / 2));

				// Compute p1 win or loose

				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}
				
			}

			player1.turn = 0;
			player2.turn = 1;


			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_rule1_save(player1, player2,obstacle, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop1Rule1(player1, player2, obstacle, board, size, goFirst, numRock);
			}

			if (player1.save == 1 || player2.save == 1)
			{
				saveRule1(board, size, player1, player2,obstacle);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule1_save(player1, player2, obstacle, size, board);
				break;
			}


		}

		if (player2.turn == 1 && player1.turn == 0)
		{
			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1 && player2.save != 1 && player2.quit != 1)
			{
				board[(player2.x - 2) / 4][(player2.y - 1) / 2] = player2.icon;
				player2.historyMove.push_back(make_pair((player2.x - 2) / 4, (player2.y - 1) / 2));

				// Compute p2 win or loose
				

				if (size > 4)
				{
					player2.win = ComputeN(player2, size, board);
				}
				if (size == 4)
				{
					player2.win = Compute4(player2, size, board);
				}
				if (size == 3)
				{
					player2.win = Compute3(player2, size, board);
				}
			}

			player1.turn = 1;
			player2.turn = 0;

			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_rule1_save(player1, player2, obstacle, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop2Rule1(player1, player2, obstacle, board, size, goFirst, numRock);

			}


			if (player1.save == 1 || player2.save == 1)
			{
				saveRule1(board, size, player1, player2,obstacle);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule1_save(player1, player2, obstacle, size, board);
				break;
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
	player1.icon = pvpConfig.mainIcon;
	player1.color = pvpConfig.mainColor;

	Object player2;
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


	drawBoardRule2(size, board, player1, player2,obstacle, pvpConfig.boardColor);

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

			if (player1.undo != 1 && player1.save != 1 && player1.quit != 1)
			{
				board[(player1.x - 2) / 4][(player1.y - 1) / 2] = player1.icon;
				player1.historyMove.push_back(make_pair((player1.x - 2) / 4, (player1.y - 1) / 2));

				// Compute p1 win or loose

				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}

			}

			player1.turn = 0;
			player2.turn = 1;


			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_rule2_save(player1, player2, obstacle, size, board);

				break;
			}



			if (player1.save == 1 || player2.save == 1)
			{
				saveRule2(board, size, player1, player2,obstacle);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule2_save(player1, player2, obstacle, size, board);
				break;
			}

			if (player1.undo != 1 && player2.undo != 1)
			{
				int randomX = rand() % size;
				int randomY = rand() % size;

				while (board[randomX][randomY] != "_")
				{
					randomX = rand() % size;
					randomY = rand() % size;
				}

				gotoXY(randomX * 4 + 2, randomY * 2 + 1);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), purple);

				cout << obstacle.icon;
				board[randomX][randomY] = obstacle.icon;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop1Rule2(player1, player2, obstacle, board, size, goFirst);
			}

		}

		if (player2.turn == 1 && player1.turn == 0)
		{
			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1 && player2.save != 1 && player2.quit != 1)
			{
				board[(player2.x - 2) / 4][(player2.y - 1) / 2] = player2.icon;
				player2.historyMove.push_back(make_pair((player2.x - 2) / 4, (player2.y - 1) / 2));

				// Compute p2 win or loose


				if (size > 4)
				{
					player2.win = ComputeN(player2, size, board);
				}
				if (size == 4)
				{
					player2.win = Compute4(player2, size, board);
				}
				if (size == 3)
				{
					player2.win = Compute3(player2, size, board);
				}
			}

			player1.turn = 1;
			player2.turn = 0;

			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_rule2_save(player1, player2, obstacle, size, board);

				break;
			}


			if (player1.save == 1 || player2.save == 1)
			{
				saveRule2(board, size, player1, player2,obstacle);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule2_save(player1, player2, obstacle, size, board);
				break;
			}

			if (player2.undo != 1 && player1.undo != 1)
			{
				int randomX = rand() % size;

				int randomY = rand() % size;

				while (board[randomX][randomY] != "_")
				{
					randomX = rand() % size;
					randomY = rand() % size;
				}

				gotoXY(randomX * 4 + 2, randomY * 2 + 1);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), purple);

				cout << obstacle.icon;
				board[randomX][randomY] = obstacle.icon;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop2Rule2(player1, player2, obstacle, board, size, goFirst);
			}

		}
	}
}

int rule3()
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	Color color;
	getColor(color);

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

	system("cls");
	int changeTime;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
	cout << "Please enter period of the game: ";
	cin >> changeTime;

	int currentTime = changeTime;
	board = drawBoardRule3(size, board, player1, player2,pvpConfig.boardColor,currentTime);



	// Gameplay
	while (1)
	{
		if (currentTime == 0)
		{

			for (int i = 0; i < player1.historyMove.size(); i++)
			{
				board[player1.historyMove[i].first][player1.historyMove[i].second] = player2.icon;
			}

			for (int i = 0; i < player2.historyMove.size(); i++)
			{
				board[player2.historyMove[i].first][player2.historyMove[i].second] = player1.icon;
			}

			swap(player1.historyMove, player2.historyMove);

			currentTime = changeTime;
			
			drawBoardRule3(size, board, player1, player2, pvpConfig.boardColor, currentTime);
			

		}

		if (player1.turn == 1 && player2.turn == 0)
		{
#pragma region P1 ZONE
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1 && player1.save != 1 && player1.quit != 1)
			{
				board[(player1.x - 2) / 4][(player1.y - 1) / 2] = player1.icon;
				player1.historyMove.push_back(make_pair((player1.x - 2) / 4, (player1.y - 1) / 2));

				// Compute p1 win or loose

				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}
				currentTime--;
			}

			player1.turn = 0;
			player2.turn = 1;


			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_rule3_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{

				if (currentTime == changeTime)
				{
					for (int i = 0; i < player1.historyMove.size(); i++)
					{
						board[player1.historyMove[i].first][player1.historyMove[i].second] = player2.icon;
					}

					for (int i = 0; i < player2.historyMove.size(); i++)
					{
						board[player2.historyMove[i].first][player2.historyMove[i].second] = player1.icon;
					}

					swap(player1.historyMove, player2.historyMove);

					board = drawBoardRule3(size, board, player1, player2, pvpConfig.boardColor, currentTime);
					currentTime = 1;
				}
				else
				{
					currentTime++;
				}

				undop1Rule3(player1, player2, board, size, goFirst,currentTime);
			}

			if (player1.save == 1 || player2.save == 1)
			{
				saveRule3(board, size, player1, player2, currentTime, changeTime);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
			{
				return 0;
			}

			

			drawBoardRule3(size, board, player1, player2, pvpConfig.boardColor, currentTime);

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
				leaderboard_rule3_save(player1, player2, size, board);
				break;
			}
#pragma endregion


		}


		if (currentTime == 0)
		{

			for (int i = 0; i < player1.historyMove.size(); i++)
			{
				board[player1.historyMove[i].first][player1.historyMove[i].second] = player2.icon;
			}

			for (int i = 0; i < player2.historyMove.size(); i++)
			{
				board[player2.historyMove[i].first][player2.historyMove[i].second] = player1.icon;
			}

			currentTime = changeTime;
			drawBoardRule3(size, board, player1, player2, pvpConfig.boardColor,currentTime);

			swap(player1.historyMove, player2.historyMove);

		}


		if (player2.turn == 1 && player1.turn == 0)
		{

#pragma region P2 ZONE
			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1 && player2.save != 1 && player2.quit != 1)
			{
				board[(player2.x - 2) / 4][(player2.y - 1) / 2] = player2.icon;
				player2.historyMove.push_back(make_pair((player2.x - 2) / 4, (player2.y - 1) / 2));

				// Compute p2 win or loose


				if (size > 4)
				{
					player2.win = ComputeN(player2, size, board);
				}
				if (size == 4)
				{
					player2.win = Compute4(player2, size, board);
				}
				if (size == 3)
				{
					player2.win = Compute3(player2, size, board);
				}

				currentTime--;
			}

			player1.turn = 1;
			player2.turn = 0;

			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_rule3_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				if (currentTime == changeTime)
				{
					for (int i = 0; i < player1.historyMove.size(); i++)
					{
						board[player1.historyMove[i].first][player1.historyMove[i].second] = player2.icon;
					}

					for (int i = 0; i < player2.historyMove.size(); i++)
					{
						board[player2.historyMove[i].first][player2.historyMove[i].second] = player1.icon;
					}


					swap(player1.historyMove, player2.historyMove);

					board = drawBoardRule3(size, board, player1, player2, pvpConfig.boardColor, currentTime);

					currentTime = 1;
				}
				else
				{
					currentTime++;
				}

				
				undop2Rule3(player1, player2, board, size, goFirst,currentTime);

				
			}


			if (player1.save == 1 || player2.save == 1)
			{
				saveRule3(board, size, player1, player2, currentTime, changeTime);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
			{
				return 0;
			}

			

			drawBoardRule3(size, board, player1, player2, pvpConfig.boardColor, currentTime);

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
				leaderboard_rule3_save(player1, player2, size, board);
				break;
			}
#pragma endregion


		}
	}
}

int rule4()
{
	Color color;
	getColor(color);

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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	int changeTime;
	int changeSize;
	cout << "Please enter perioid of change: ";
	cin >> changeTime;
	cout << "Please enter change size: ";
	cin >> changeSize;

	int currentTime = changeTime;

	board = drawBoardRule4(size, board, player1, player2,pvpConfig.boardColor,currentTime);

	


	// Gameplay
	while (1)
	{
		if (currentTime == 0)
		{
			for (int x = 0; x < size; x++)
			{
				board[x][size - 1] = "_";
			}

			for (int y = 0; y < size; y++)
			{
				board[size - 1][y] = "_";
			}
			size = size - changeSize;


			currentTime = changeTime;
			drawBoardRule4(size, board, player1, player2, pvpConfig.boardColor, currentTime);
		}

		if (player1.turn == 1 && player2.turn == 0)
		{
#pragma region P1 ZONE
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1 && player1.save != 1 && player1.quit != 1)
			{
				board[(player1.x - 2) / 4][(player1.y - 1) / 2] = player1.icon;
				player1.historyMove.push_back(make_pair((player1.x - 2) / 4, (player1.y - 1) / 2));

				// Compute p1 win or loose

				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}
				currentTime--;
				
			}

			player1.turn = 0;
			player2.turn = 1;


			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_rule4_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				if (currentTime == changeTime)
				{
					for (int x = 0; x < size; x++)
					{
						board[x][size - 1] = "_";
					}

					for (int y = 0; y < size; y++)
					{
						board[size - 1][y] = "_";
					}
					size = size + changeSize;

					currentTime = 1;
					drawBoardRule4(size, board, player1, player2, pvpConfig.boardColor, currentTime);
				}
				else
				{
					currentTime++;
				}


				undop1(player1, player2, board, size, goFirst);
			}

			if (player1.save == 1 || player2.save == 1)
			{
				saveRule4(board, size, player1, player2, currentTime, changeTime, changeSize);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
			{
				return 0;
			}

			drawBoardRule4(size, board, player1, player2, pvpConfig.boardColor, currentTime);

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
				leaderboard_rule4_save(player1, player2, size, board);
				break;
			}


#pragma endregion



		}

		if (currentTime == 0)
		{
			for (int x = 0; x < size; x++)
			{
				board[x][size - 1] = "_";
			}

			for (int y = 0; y < size; y++)
			{
				board[size - 1][y] = "_";
			}
			size = size - changeSize;


			currentTime = changeTime;
			drawBoardRule4(size, board, player1, player2, pvpConfig.boardColor, currentTime);
		}

		if (player2.turn == 1 && player1.turn == 0)
		{
#pragma region P2 ZONE
			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1 && player2.save != 1 && player2.quit != 1)
			{
				board[(player2.x - 2) / 4][(player2.y - 1) / 2] = player2.icon;
				player2.historyMove.push_back(make_pair((player2.x - 2) / 4, (player2.y - 1) / 2));

				// Compute p2 win or loose


				if (size > 4)
				{
					player2.win = ComputeN(player2, size, board);
				}
				if (size == 4)
				{
					player2.win = Compute4(player2, size, board);
				}
				if (size == 3)
				{
					player2.win = Compute3(player2, size, board);
				}

				currentTime--;
				drawBoardRule4(size, board, player1, player2, pvpConfig.boardColor, currentTime);
			}

			player1.turn = 1;
			player2.turn = 0;

			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_rule4_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				if (currentTime == changeTime)
				{
					for (int x = 0; x < size; x++)
					{
						board[x][size - 1] = "_";
					}

					for (int y = 0; y < size; y++)
					{
						board[size - 1][y] = "_";
					}
					size = size + changeSize;

					currentTime = 1;
					drawBoardRule4(size, board, player1, player2, pvpConfig.boardColor, currentTime);
				}
				else
				{
					currentTime++;
				}


				undop2(player1, player2, board, size, goFirst);

			}


			if (player1.save == 1 || player2.save == 1)
			{
				saveRule4(board, size, player1, player2, currentTime, changeTime, changeSize);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
			{
				return 0;
			}

			drawBoardRule4(size, board, player1, player2, pvpConfig.boardColor, currentTime);

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
				leaderboard_rule4_save(player1, player2, size, board);
				break;
			}
#pragma endregion



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


	int boomNum = (size * size) / 5;

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


	board = drawBoardRule5(size, board, player1, player2, pvpConfig.boardColor,currentBoom);

	// Gameplay
	while (1)
	{


		if (player1.turn == 1 && player2.turn == 0)
		{
#pragma region P1 ZONE
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1 && player1.save != 1 && player1.quit != 1)
			{
#pragma region Boom Compute P1

				if (board[(player1.x - 2) / 4][(player1.y - 1) / 2] == "B")
				{
					int boomX = (player1.x - 2) / 4;
					int boomY = (player1.y - 1) / 2;

					if (boomX > 0 && boomY > 0)
					{
						if (board[boomX - 1][boomY - 1] == "B")
						{
							currentBoom--;

						}

						board[boomX - 1][boomY - 1] = "_";
					}
					if (boomX > 0)
					{
						if (board[boomX - 1][boomY] == "B")
						{
							currentBoom--;
						}

						board[boomX - 1][boomY] = "_";
						
					}
					if (boomX > 0 && boomY < size - 1)
					{
						if (board[boomX - 1][boomY + 1] == "B")
						{
							currentBoom--;
						}

						board[boomX - 1][boomY + 1] = "_";
					}
					if (boomY > 0)
					{
						if (board[boomX][boomY - 1] == "B")
						{
							currentBoom--;
						}

						board[boomX][boomY - 1] = "_";
						
					}
					if (boomY > 0 && boomX < size - 1)
					{
						if (board[boomX + 1][boomY - 1] == "B")
						{
							currentBoom--;
						}

						board[boomX + 1][boomY - 1] = "_";
					}
					if (boomY < size - 1)
					{
						if (board[boomX][boomY + 1] == "B")
						{
							currentBoom--;
						}

						board[boomX][boomY + 1] = "_";
					}
					if (boomX < size - 1)
					{
						if (board[boomX + 1][boomY] == "B")
						{
							currentBoom--;
						}

						board[boomX + 1][boomY] = "_";
					}
					if (boomX < size - 1 && boomY < size - 1)
					{
						if (board[boomX + 1][boomY + 1] == "B")
						{
							currentBoom--;
						}

						board[boomX + 1][boomY + 1] = "_";
					}
					

					
					board[boomX][boomY] = "_";
					
					currentBoom--;

					drawBoardRule5(size, board, player1, player2, pvpConfig.boardColor, currentBoom);

					player1.historyMove.clear();
					player2.historyMove.clear();

				}
				else
				{
					board[(player1.x - 2) / 4][(player1.y - 1) / 2] = player1.icon;
					player1.historyMove.push_back(make_pair((player1.x - 2) / 4, (player1.y - 1) / 2));
				}
#pragma endregion
				// Compute p1 win or loose
				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}
			}

			player1.turn = 0;
			player2.turn = 1;


			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_rule5_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop1Rule5(player1, player2, board, size, goFirst, currentBoom);
			}

			if (player1.save == 1 || player2.save == 1)
			{
				saveRule5(board, size, player1, player2, boom, boomPos);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule5_save(player1, player2, size, board);
				break;
			}

#pragma endregion



		}

		if (player2.turn == 1 && player1.turn == 0)
		{
#pragma region P2 ZONE
			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1 && player2.save != 1 && player2.quit != 1)
			{
#pragma region Boom Compute P2



				if (board[(player2.x - 2) / 4][(player2.y - 1) / 2] == "B")
				{
					int boomX = (player2.x - 2) / 4;
					int boomY = (player2.y - 1) / 2;


					if (boomX > 0 && boomY > 0)
					{
						if (board[boomX - 1][boomY - 1] == "B")
						{
							currentBoom--;
						}

						board[boomX - 1][boomY - 1] = "_";
					}
					if (boomX > 0)
					{
						if (board[boomX - 1][boomY] == "B")
						{
							currentBoom--;
						}

						board[boomX - 1][boomY] = "_";

					}
					if (boomX > 0 && boomY < size - 1)
					{
						if (board[boomX - 1][boomY + 1] == "B")
						{
							currentBoom--;
						}

						board[boomX - 1][boomY + 1] = "_";
					}
					if (boomY > 0)
					{
						if (board[boomX][boomY - 1] == "B")
						{
							currentBoom--;
						}

						board[boomX][boomY - 1] = "_";

					}
					if (boomY > 0 && boomX < size - 1)
					{
						if (board[boomX + 1][boomY - 1] == "B")
						{
							currentBoom--;
						}

						board[boomX + 1][boomY - 1] = "_";
					}
					if (boomY < size - 1)
					{
						if (board[boomX][boomY + 1] == "B")
						{
							currentBoom--;
						}

						board[boomX][boomY + 1] = "_";
					}
					if (boomX < size - 1)
					{
						if (board[boomX + 1][boomY] == "B")
						{
							currentBoom--;
						}

						board[boomX + 1][boomY] = "_";
					}
					if (boomX < size - 1 && boomY < size - 1)
					{
						if (board[boomX + 1][boomY + 1] == "B")
						{
							currentBoom--;
						}

						board[boomX + 1][boomY + 1] = "_";
					}

					board[boomX][boomY] = "_";

					currentBoom--;

					drawBoardRule5(size, board, player1, player2, pvpConfig.boardColor, currentBoom);
					player1.historyMove.clear();
					player2.historyMove.clear();
				}
				else
				{
					board[(player2.x - 2) / 4][(player2.y - 1) / 2] = player2.icon;
					player2.historyMove.push_back(make_pair((player2.x - 2) / 4, (player2.y - 1) / 2));
				}

#pragma endregion
				// Compute p2 win or loose
				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}
			}

			player1.turn = 1;
			player2.turn = 0;

			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_rule5_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop2Rule5(player1, player2, board, size, goFirst, currentBoom);

			}


			if (player1.save == 1 || player2.save == 1)
			{
				saveRule5(board, size, player1, player2, boom, boomPos);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule5_save(player1, player2, size, board);
				break;
			}

#pragma endregion


		}
	}
}

int rule6()
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	Color color;
	getColor(color);

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

	int restrictMove;

	// Draw the board
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
	cout << "Please enter restriction move you want: ";
	cin >> restrictMove;

	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };

	board = drawBoard(size, board, player1, player2,pvpConfig.boardColor);

	
	int numMainMove = 0;
	int numSecondMove = 0;

	// Gameplay
	while (1)
	{
		if (player1.turn == 1 && player2.turn == 0)
		{
#pragma region P1 ZONE

			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControlRule6(player1, size, board,numMainMove,restrictMove);

			if (player1.undo != 1 && player1.save != 1 && player1.quit != 1)
			{
				board[(player1.x - 2) / 4][(player1.y - 1) / 2] = player1.icon;
				player1.historyMove.push_back(make_pair((player1.x - 2) / 4, (player1.y - 1) / 2));

				// Compute p1 win or loose

				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}

			}

			player1.turn = 0;
			player2.turn = 1;


			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_rule6_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop1(player1, player2, board, size, goFirst);
			}

			if (player1.save == 1 || player2.save == 1)
			{
				saveRule6(board, size, player1, player2,restrictMove);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule6_save(player1, player2, size, board);
				break;
			}

#pragma endregion
		}

		if (player2.turn == 1 && player1.turn == 0)
		{
#pragma region P2 ZONE

			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControlRule6(player2, size, board,numSecondMove,restrictMove);

			if (player2.undo != 1 && player2.save != 1 && player2.quit != 1)
			{
				board[(player2.x - 2) / 4][(player2.y - 1) / 2] = player2.icon;
				player2.historyMove.push_back(make_pair((player2.x - 2) / 4, (player2.y - 1) / 2));

				// Compute p2 win or loose


				if (size > 4)
				{
					player2.win = ComputeN(player2, size, board);
				}
				if (size == 4)
				{
					player2.win = Compute4(player2, size, board);
				}
				if (size == 3)
				{
					player2.win = Compute3(player2, size, board);
				}
			}

			player1.turn = 1;
			player2.turn = 0;

			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_rule6_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop2(player1, player2, board, size, goFirst);

			}


			if (player1.save == 1 || player2.save == 1)
			{
				saveRule6(board, size, player1, player2, restrictMove);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule6_save(player1, player2, size, board);
				break;
			}
#pragma endregion
		}
	}


}

int rule7()
{
	Color color;
	getColor(color);

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
	int range = rand() % 5 + 1;


	board = drawBoardRule7(size, board, player1, player2,pvpConfig.boardColor,range);

	int lastXPosMain = 1000000;
	int lastYPosMain = 1000000;

	int lastXPosSecond = 1000000;
	int lastYPosSecond = 1000000;

	string rangeCommandLine;

	// Gameplay
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		rangeCommandLine = "Now range is: " + to_string(range);

		gotoXY((size * 2 + 2) * 2, 3);
		cout << rangeCommandLine;

		if (player1.turn == 1 && player2.turn == 0)
		{
#pragma region P1 ZONE

			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControlRule7(player1, size, board, lastXPosMain, lastYPosMain, range);

			

			if (player1.undo != 1 && player1.save != 1 && player1.quit != 1)
			{
				lastXPosMain = (player1.x - 2) / 4;
				lastYPosMain = (player1.y - 1) / 2;

				board[(player1.x - 2) / 4][(player1.y - 1) / 2] = player1.icon;
				player1.historyMove.push_back(make_pair((player1.x - 2) / 4, (player1.y - 1) / 2));

				// Compute p1 win or loose

				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}

			}

			player1.turn = 0;
			player2.turn = 1;


			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_rule7_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop1(player1, player2, board, size, goFirst);
			}

			if (player1.save == 1 || player2.save == 1)
			{
				saveRule7(board, size, player1, player2, range);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule7_save(player1, player2, size, board);
				break;
			}

#pragma endregion
		}

		range = rand() % 5 + 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
		rangeCommandLine = "Now range is: " + to_string(range);

		gotoXY((size * 2 + 2) * 2, 3);
		cout << rangeCommandLine;

		if (player2.turn == 1 && player1.turn == 0)
		{
#pragma region P2 ZONE


			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControlRule7(player2, size, board, lastXPosSecond, lastYPosSecond,range);

			

			if (player2.undo != 1 && player2.save != 1 && player2.quit != 1)
			{
				lastXPosSecond = (player2.x - 2) / 4;
				lastYPosSecond = (player2.y - 1) / 2;

				board[(player2.x - 2) / 4][(player2.y - 1) / 2] = player2.icon;
				player2.historyMove.push_back(make_pair((player2.x - 2) / 4, (player2.y - 1) / 2));

				// Compute p2 win or loose


				if (size > 4)
				{
					player2.win = ComputeN(player2, size, board);
				}
				if (size == 4)
				{
					player2.win = Compute4(player2, size, board);
				}
				if (size == 3)
				{
					player2.win = Compute3(player2, size, board);
				}
			}

			player1.turn = 1;
			player2.turn = 0;

			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_rule7_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop2(player1, player2, board, size, goFirst);

			}


			if (player1.save == 1 || player2.save == 1)
			{
				saveRule7(board, size, player1, player2, range);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
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
				leaderboard_rule7_save(player1, player2, size, board);
				break;
			}

#pragma endregion
		}

		range = rand() % 5 + 1;
	}
}

int rule8()
{
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	Color color;
	getColor(color);

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


	int changedItem = (size*size) / 5;

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


	board = drawBoardRule8(size, board, player1, player2, currentChangedItem, pvpConfig.boardColor);

	// Gameplay
	while (1)
	{

		if (player1.turn == 1 && player2.turn == 0)
		{
#pragma region P1 ZONE

			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
			gotoXY(player1.x, player1.y);
			// Require the use control p1
			player1 = mainControl(player1, size, board);

			if (player1.undo != 1 && player1.save != 2 && player1.quit != 1)
			{

				if (board[(player1.x - 2) / 4][(player1.y - 1) / 2] == "C")
				{
					board[(player1.x - 2) / 4][(player1.y - 1) / 2] = player2.icon;
					currentChangedItem--;
					drawBoardRule8(size, board, player1, player2, currentChangedItem, pvpConfig.boardColor);


					player1.historyMove.clear();
					player2.historyMove.clear();

				}
				else
				{
					board[(player1.x - 2) / 4][(player1.y - 1) / 2] = player1.icon;
					player1.historyMove.push_back(make_pair((player1.x - 2) / 4, (player1.y - 1) / 2));
				}
				// Compute p1 win or loose

				if (size > 4)
				{
					player2.win = ComputeN(player2, size, board);
				}

				if (size == 4)
				{
					player2.win = Compute4(player2, size, board);
				}

				if (size == 3)
				{
					player2.win = Compute3(player2, size, board);
				}


				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}


			}

			player1.turn = 0;
			player2.turn = 1;


			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_rule8_save(player1, player2, size, board);

				break;
			}

			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_rule8_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop1Rule8(player1, player2, board, size, goFirst, currentChangedItem);
			}

			if (player1.save == 1 || player2.save == 1)
			{
				saveRule8(board, size, player1, player2, changed, changedPos);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
			{
				return 0;
			}

			int checkDraw = 1;

			for (int x = 0; x < size; x++)
			{
				for (int y = 0; y < size; y++)
				{

					if (board[x][y] == "_" || board[x][y] == "C")
					{
						checkDraw = 0;
					}

				}
			}

			if (checkDraw == 1)
			{
				animateDraw(size);
				leaderboard_rule8_save(player1, player2, size, board);
				break;
			}

#pragma endregion

		}

		if (player2.turn == 1 && player1.turn == 0)
		{
#pragma region P2 ZONE

			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
			gotoXY(player2.x, player2.y);
			// Require the use control p2
			player2 = secondControl(player2, size, board);

			if (player2.undo != 1 && player2.save != 1 && player2.quit != 1)
			{
				if (board[(player2.x - 2) / 4][(player2.y - 1) / 2] == "C")
				{
					board[(player2.x - 2) / 4][(player2.y - 1) / 2] = player1.icon;
					currentChangedItem--;
					drawBoardRule8(size, board, player1, player2, currentChangedItem, pvpConfig.boardColor);


					player1.historyMove.clear();
					player2.historyMove.clear();

				}
				else
				{
					board[(player2.x - 2) / 4][(player2.y - 1) / 2] = player2.icon;
					player2.historyMove.push_back(make_pair((player2.x - 2) / 4, (player2.y - 1) / 2));
				}

				// Compute p2 win or loose

				if (size > 4)
				{
					player2.win = ComputeN(player2, size, board);
				}

				if (size == 4)
				{
					player2.win = Compute4(player2, size, board);
				}

				if (size == 3)
				{
					player2.win = Compute3(player2, size, board);
				}

				if (size > 4)
				{
					player1.win = ComputeN(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}

			}

			player1.turn = 1;
			player2.turn = 0;

			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_rule8_save(player1, player2, size, board);

				break;
			}

			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_rule8_save(player1, player2, size, board);

				break;
			}

			if (player1.undo == 1 || player2.undo == 1)
			{
				undop2Rule8(player1, player2, board, size, goFirst, currentChangedItem);

			}


			if (player1.save == 1 || player2.save == 1)
			{
				saveRule8(board, size, player1, player2, changed, changedPos);
				break;
			}

			if (player1.quit == 1 || player2.quit == 1)
			{
				return 0;
			}

			int checkDraw = 1;

			for (int x = 0; x < size; x++)
			{
				for (int y = 0; y < size; y++)
				{

					if (board[x][y] == "_" || board[x][y] == "C")
					{
						checkDraw = 0;
					}

				}
			}

			if (checkDraw == 1)
			{
				animateDraw(size);
				leaderboard_rule8_save(player1, player2, size, board);
				break;
			}

#pragma endregion
		}
	}
}