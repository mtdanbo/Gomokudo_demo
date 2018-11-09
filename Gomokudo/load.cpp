#include "load.h"

#pragma region Load game PvP mode
int loadSaveFile_PvP()
{
	#pragma region Initial Start

	system("cls");

	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/pvp_savelist.txt");
	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;
		fileName.push_back(temp);
	}

	savelistRead.close();

	fileName.pop_back();
	int choice = controlMenuByArrow(fileName);
	string filename = fileName[choice];

	#pragma endregion

	#pragma region Set Property

	// Set figure
	ifstream figure;
	figure.open("save_pvp/" + filename + "figure.txt");

	int size;
	Object player1;
	Object player2;

	figure >> size;
	figure >> player1.icon;
	figure >> player1.color;
	figure >> player2.icon;
	figure >> player2.color;
	figure >> player1.turn;
	figure >> player2.turn;

	//Set property of the board
	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> board{ 100,temp };

	ifstream player1Move;
	player1Move.open("save_pvp/" + filename + "p1.txt");
	int player1X;
	int player1Y;
	while (!player1Move.eof())
	{
		player1Move >> player1X;
		player1Move >> player1Y;

		if (player1X >= 0 && player1Y >= 0)
		{
			board[player1X][player1Y] = player1.icon;
		}
		
	}
	player1Move.close();

	ifstream player2Move;
	player2Move.open("save_pvp/" + filename + "p2.txt");
	int player2X;
	int player2Y;
	while (!player2Move.eof())
	{
		player2Move >> player2X;
		player2Move >> player2Y;
		if (player2X >= 0 && player2Y >= 0)
		{
			board[player2X][player2Y] = player2.icon;
		}
		
	}
	player2Move.close();

	board = drawBoard(size, board, player1, player2, pvpConfig.boardColor);

	int goFirst = 0;

	if (player1.turn == 1 && player2.turn == 0)
	{
		goFirst = 1;
	}
	if (player1.turn == 0 && player2.turn == 1)
	{
		goFirst = 2;
	}

	#pragma endregion

	while (1)
	{
		if (player1.turn == 1 && player2.turn == 0)
		{
			#pragma region Player 1 Zone

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
				if (size == 3)
				{
					player1.win = Compute3(player1, size, board);
				}
				if (size == 4)
				{
					player1.win = Compute4(player1, size, board);
				}
				
			}

			//Change turn
			player1.turn = 0;
			player2.turn = 1;

			// Win algorithm
			if (player1.win == 1)
			{
				animateP1Win(size);

				leaderboard_pvp_save(player1, player2, size, board);

				break;
			}

			// Undo algorithm
			if (player1.undo == 1 || player2.undo == 1)
			{
				undop1(player1, player2, board, size, goFirst);
			}

			// Save algorithm
			if (player1.save == 1 || player2.save == 1)
			{
				savePvP(board, size, player1, player2);
				break;
			}

			// Quit algorithm
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
				leaderboard_pvp_save(player1, player2, size, board);
				break;
			}

			#pragma endregion
		}

		if (player2.turn == 1 && player1.turn == 0)
		{
			#pragma region Player 2 Zone

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
				if (size == 3)
				{
					player2.win = Compute3(player2, size, board);
				}
				if (size == 4)
				{
					player2.win = Compute4(player2, size, board);
				}
				
			}

			player1.turn = 1;
			player2.turn = 0;

			// Win algorithm
			if (player2.win == 1)
			{
				animateP2Win(size);
				leaderboard_pvp_save(player1, player2, size, board);

				break;
			}

			// Undo algorithm
			if (player1.undo == 1 || player2.undo == 1)
			{
				undop2(player1, player2, board, size, goFirst);

			}

			// Save algoritm
			if (player1.save == 1 || player2.save == 1)
			{
				savePvP(board, size, player1, player2);
				break;
			}

			// Quit algorithm
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
				leaderboard_pvp_save(player1, player2, size, board);
				break;
			}

			#pragma endregion
		}
	}
	
}

void deleteSavedFile_PvP()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/pvp_savelist.txt");

	int width = getConsoleWidth();
	int height = getConsoleHeight();

	gotoXY(width / 2, height / 2);

	int index = 0;

	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;

		cout << temp;

		fileName.push_back(temp);

		index++;

		gotoXY(width / 2, height / 2 + index);

	}

	savelistRead.close();
	fileName.pop_back();

	int choice = controlMenuByArrow(fileName);


	string filename = fileName[choice];


	for (int i = 0; i < fileName.size(); i++)
	{

		if (filename == fileName[i])
		{
			fileName.erase(fileName.begin() + i);
			break;
		}

	}

	ofstream savelistWrite;
	savelistWrite.open("text/pvp_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerOneFile = "save_pvp/" + filename + "p1.txt";
	string playerTwoFile = "save_pvp/" + filename + "p2.txt";
	string figureFile = "save_pvp/" + filename + "figure.txt";

	const char* playerOneFile1 = playerOneFile.c_str();
	const char* playerTwoFile1 = playerTwoFile.c_str();
	const char* figureFile1 = figureFile.c_str();

	remove(playerOneFile1);
	remove(playerTwoFile1);
	remove(figureFile1);


}

void loadPvP() {

	vector<string> task = { "Load saved file", "Delete saved file" };

	int choice = controlMenuByArrow(task);

	if (choice == 0)
	{
		loadSaveFile_PvP();
	}

	if (choice == 1)
	{
		deleteSavedFile_PvP();
	}
}
#pragma endregion


#pragma region Load game PvC mode
int loadSaveFile_PvC()
{
	system("cls");

	Color color;
	getColor(color);

	PvCConfig pvcConfig;
	getPvCConfig(pvcConfig);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/pvc_savelist.txt");

	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;

		fileName.push_back(temp);

	}

	fileName.pop_back();

	savelistRead.close();

	if (fileName.size() > 0)
	{
		#pragma region Initial State

		int choice = controlMenuByArrow(fileName);

		string filename = fileName[choice];

		// Set figure
		ifstream figure;
		figure.open("save_pvc/" + filename + "figure.txt");
		int size;
		int mode;

		Object player;
		player.Score.resize(100, vector<int>(100, 0));


		Object bot;
		bot.Score.resize(100, vector<int>(100, 0));

		figure >> size;
		figure >> player.icon;
		figure >> player.color;
		figure >> bot.icon;
		figure >> bot.color;
		figure >> mode;
		figure >> player.turn;
		figure >> bot.turn;

		//Set property of the board

		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };


		ifstream playerMove;
		playerMove.open("save_pvc/" + filename + "p.txt");
		int playerX;
		int playerY;


		while (!playerMove.eof())
		{
			playerMove >> playerX;
			playerMove >> playerY;

			if (playerX >= 0 && playerY >= 0)
			{
				board[playerX][playerY] = player.icon;
			}
		}

		playerMove.close();

		ifstream botMove;
		botMove.open("save_pvc/" + filename + "b.txt");
		int botX;
		int botY;
		while (!botMove.eof())
		{
			botMove >> botX;
			botMove >> botY;

			if (botX >= 0 && botY >= 0)
			{
				board[botX][botY] = bot.icon;
			}


		}

		botMove.close();

		#pragma endregion

		drawBoard(size, board, player, bot, pvcConfig.boardColor);

		//Continue the game

		gotoXY(0, 0);

		if (mode == 1)
		{
			int maxDepth = maxDepthEasy;
			int maxMove = maxMoveEasy;

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
					#pragma region Computer zone

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bot.color);

					int depth = 0;
					int miniMax = 0;

					Point point;

					if (size > 4)
					{
						findMove(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);
					}
					if (size == 3)
					{
						findMove3(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);
					}
					if (size == 4)
					{
						findMove4(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);
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

		if (mode == 2)
		{
			int maxDepth = maxDepthMed;
			int maxMove = maxMoveMed;

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
					#pragma region Computer zone

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bot.color);

					int depth = 0;
					int miniMax = 0;

					Point point;

					if (size > 4)
					{
						findMove(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);
					}
					if (size == 3)
					{
						findMove3(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);
					}
					if (size == 4)
					{
						findMove4(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);
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

		if (mode == 3)
		{
			int maxDepth = maxDepthHard;
			int maxMove = maxMoveHard;

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
					#pragma region Computer zone

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bot.color);

					int depth = 0;
					int miniMax = 0;

					Point point;

					if (size > 4)
					{
						findMove(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);
					}
					if (size == 3)
					{
						findMove3(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);
					}
					if (size == 4)
					{
						findMove4(maxDepth, maxMove, depth, board, player, bot, size, miniMax, point);
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
	}
	else
	{
		int width = getConsoleWidth();
		int height = getConsoleHeight();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

		gotoXY(width / 2, height / 2);
		cout << "No file to load";

		gotoXY(width / 2, height / 2 + 1);
		system("pause");
	}

}

void deleteSavedFile_PvC()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/pvc_savelist.txt");

	int width = getConsoleWidth();
	int height = getConsoleHeight();

	gotoXY(width / 2, height / 2);

	int index = 0;

	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;

		cout << temp;

		fileName.push_back(temp);

		index++;

		gotoXY(width / 2, height / 2 + index);

	}

	savelistRead.close();
	fileName.pop_back();

	int choice = controlMenuByArrow(fileName);


	string filename = fileName[choice];


	for (int i = 0; i < fileName.size(); i++)
	{

		if (filename == fileName[i])
		{
			fileName.erase(fileName.begin() + i);
			break;
		}

	}

	ofstream savelistWrite;
	savelistWrite.open("text/pvc_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerFile = "save_pvc/" + filename + "p.txt";
	string botFile = "save_pvc/" + filename + "b.txt";
	string figureFile = "save_pvc/" + filename + "figure.txt";

	const char* playerFile1 = playerFile.c_str();
	const char* botFile1 = botFile.c_str();
	const char* figureFile1 = figureFile.c_str();

	remove(playerFile1);
	remove(botFile1);
	remove(figureFile1);
}

void loadPvC() {

	vector<string> task = { "Load saved file", "Delete saved file" };

	int choice = controlMenuByArrow(task);

	if (choice == 0)
	{
		loadSaveFile_PvC();
	}

	if (choice == 1)
	{
		deleteSavedFile_PvC();
	}

}
#pragma endregion

void load() {
	int width = getConsoleWidth();
	int height = getConsoleHeight();
	//ifstream loadIntro;
	//loadIntro.open("text/loadmode.txt");

	//gotoXY(width / 2 - 30, height / 2 - 1);
	//animateText(loadIntro);
	//loadIntro.close();

	vector<string> type = { "PvP mode", "PvC mode" };

	int choice = controlMenuByArrow(type);

	if (choice == 0)
	{
		system("cls");
		loadPvP();
	}
	if (choice == 1)
	{
		system("cls");
		loadPvC();
	}
}

