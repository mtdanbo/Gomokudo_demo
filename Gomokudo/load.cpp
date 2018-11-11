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
	int rule;
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

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_PvP();
		}

		if (choice == 1)
		{
			deleteSavedFile_PvP();
		}
		if (choice == 2)
		{
			break;
		}
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

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_PvC();
		}

		if (choice == 1)
		{
			deleteSavedFile_PvC();
		}
		if (choice == 2)
		{
			break;
		}
	}

}
#pragma endregion


#pragma region Load rule mode

#pragma region Load game Rule 1
int loadSaveFile_Rule1()
{
#pragma region Initial Start

	system("cls");

	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule1_savelist.txt");
	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;
		fileName.push_back(temp);
	}

	savelistRead.close();

	fileName.pop_back();
#pragma endregion

	if (fileName.size() > 0)
	{
		int choice = controlMenuByArrow(fileName);
		string filename = fileName[choice];



#pragma region Set Property

		// Set figure
		ifstream figure;
		figure.open("save_rule1/" + filename + "figure.txt");

		int size;
		int rule;
		Object player1;
		Object player2;
		Object obstacle;

		figure >> size;
		figure >> player1.icon;
		figure >> player1.color;
		figure >> player2.icon;
		figure >> player2.color;
		figure >> obstacle.icon;
		figure >> obstacle.color;
		figure >> player1.turn;
		figure >> player2.turn;


		//Set property of the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };

		ifstream player1Move;
		player1Move.open("save_rule1/" + filename + "p1.txt");
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
		player2Move.open("save_rule1/" + filename + "p2.txt");
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

		ifstream obstacleMove;
		obstacleMove.open("save_rule1/" + filename + "o.txt");
		int obstacleX;
		int obstacleY;
		while (!obstacleMove.eof())
		{
			obstacleMove >> obstacleX;
			obstacleMove >> obstacleY;
			if (obstacleX >= 0 && obstacleY >= 0)
			{
				board[obstacleX][obstacleY] = obstacle.icon;
			}

		}
		obstacleMove.close();

		board = drawBoardRule1(size, board, player1, player2, obstacle, pvpConfig.boardColor, size*size / 8);

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

					leaderboard_rule1_save(player1, player2, obstacle, size, board);

					break;
				}

				// Undo algorithm
				if (player1.undo == 1 || player2.undo == 1)
				{
					undop1Rule1(player1, player2, obstacle, board, size, goFirst, size*size / 8);
				}

				// Save algorithm
				if (player1.save == 1 || player2.save == 1)
				{
					saveRule1(board, size, player1, player2, obstacle);
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
					leaderboard_rule1_save(player1, player2, obstacle, size, board);
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
					leaderboard_rule1_save(player1, player2, obstacle, size, board);

					break;
				}

				// Undo algorithm
				if (player1.undo == 1 || player2.undo == 1)
				{
					undop2Rule1(player1, player2, obstacle, board, size, goFirst, size*size / 8);

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
					leaderboard_rule1_save(player1, player2, obstacle, size, board);
					break;
				}

#pragma endregion
			}
		}

	}
	else
	{

	system("cls");
	cout << "Error no file to load";
	system("pause");

	}

}

void deleteSavedFile_Rule1()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule1_savelist.txt");
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


	for (int i = 0; i < fileName.size(); i++)
	{

		if (filename == fileName[i])
		{
			fileName.erase(fileName.begin() + i);
			break;
		}

	}

	ofstream savelistWrite;
	savelistWrite.open("text/rule1_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerOneFile = "save_rule1/" + filename + "p1.txt";
	string playerTwoFile = "save_rule1/" + filename + "p2.txt";
	string figureFile = "save_rule1/" + filename + "figure.txt";
	string obstacleFile = "save_rule1/" + filename + "o.txt";

	const char* playerOneFile1 = playerOneFile.c_str();
	const char* playerTwoFile1 = playerTwoFile.c_str();
	const char* figureFile1 = figureFile.c_str();
	const char* obstacleFile1 = obstacleFile.c_str();

	remove(playerOneFile1);
	remove(playerTwoFile1);
	remove(figureFile1);
	remove(obstacleFile1);


}

void loadRule1() {

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_Rule1();
		}

		if (choice == 1)
		{
			deleteSavedFile_Rule1();
		}
		if (choice == 2)
		{
			break;
		}
	}
}
#pragma endregion

#pragma region Load game Rule 2
int loadSaveFile_Rule2()
{
#pragma region Initial Start

	system("cls");

	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule2_savelist.txt");
	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;
		fileName.push_back(temp);
	}

	savelistRead.close();

	fileName.pop_back();
#pragma endregion

	if (fileName.size() > 0)
	{
		int choice = controlMenuByArrow(fileName);
		string filename = fileName[choice];

#pragma region Set Property

		// Set figure
		ifstream figure;
		figure.open("save_rule2/" + filename + "figure.txt");

		int size;
		int rule;
		Object player1;
		Object player2;
		Object obstacle;

		figure >> size;
		figure >> player1.icon;
		figure >> player1.color;
		figure >> player2.icon;
		figure >> player2.color;
		figure >> obstacle.icon;
		figure >> obstacle.color;
		figure >> player1.turn;
		figure >> player2.turn;


		//Set property of the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };

		ifstream player1Move;
		player1Move.open("save_rule2/" + filename + "p1.txt");
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
		player2Move.open("save_rule2/" + filename + "p2.txt");
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

		ifstream obstacleMove;
		obstacleMove.open("save_rule2/" + filename + "o.txt");
		int obstacleX;
		int obstacleY;
		while (!obstacleMove.eof())
		{
			obstacleMove >> obstacleX;
			obstacleMove >> obstacleY;
			if (obstacleX >= 0 && obstacleY >= 0)
			{
				board[obstacleX][obstacleY] = obstacle.icon;
			}

		}
		obstacleMove.close();

		board = drawBoardRule2(size, board, player1, player2, obstacle, pvpConfig.boardColor);

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

				if (player1.win == 1)
				{
					animateP1Win(size);

					leaderboard_rule2_save(player1, player2, obstacle, size, board);

					break;
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



				if (player2.win == 1)
				{
					animateP2Win(size);
					leaderboard_rule2_save(player1, player2, obstacle, size, board);

					break;
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

#pragma endregion
			}
		}

	}
	else
	{

		system("cls");
		cout << "Error no file to load";
		system("pause");

	}

}

void deleteSavedFile_Rule2()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule1_savelist.txt");
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


	for (int i = 0; i < fileName.size(); i++)
	{

		if (filename == fileName[i])
		{
			fileName.erase(fileName.begin() + i);
			break;
		}

	}

	ofstream savelistWrite;
	savelistWrite.open("text/rule1_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerOneFile = "save_rule1/" + filename + "p1.txt";
	string playerTwoFile = "save_rule1/" + filename + "p2.txt";
	string figureFile = "save_rule1/" + filename + "figure.txt";
	string obstacleFile = "save_rule1/" + filename + "o.txt";

	const char* playerOneFile1 = playerOneFile.c_str();
	const char* playerTwoFile1 = playerTwoFile.c_str();
	const char* figureFile1 = figureFile.c_str();
	const char* obstacleFile1 = obstacleFile.c_str();

	remove(playerOneFile1);
	remove(playerTwoFile1);
	remove(figureFile1);
	remove(obstacleFile1);


}

void loadRule2() {

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_Rule2();
		}

		if (choice == 1)
		{
			deleteSavedFile_Rule2();
		}
		if (choice == 2)
		{
			break;
		}
	}
}
#pragma endregion

#pragma region Load game Rule 3
int loadSaveFile_Rule3()
{
#pragma region Initial Start

	system("cls");

	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule3_savelist.txt");
	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;
		fileName.push_back(temp);
	}

	savelistRead.close();

	fileName.pop_back();

#pragma endregion

	if (fileName.size() > 0)
	{
#pragma region Set Property
		int choice = controlMenuByArrow(fileName);
		string filename = fileName[choice];

		// Set figure
		ifstream figure;
		figure.open("save_rule3/" + filename + "figure.txt");

		int size;
		int currentTime;
		int changeTime;
		Object player1;
		Object player2;

		figure >> size;
		figure >> player1.icon;
		figure >> player1.color;
		figure >> player2.icon;
		figure >> player2.color;
		figure >> player1.turn;
		figure >> player2.turn;
		figure >> currentTime;
		figure >> changeTime;


		//Set property of the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };

		ifstream player1Move;
		player1Move.open("save_rule3/" + filename + "p1.txt");
		int player1X;
		int player1Y;
		while (!player1Move.eof())
		{
			player1Move >> player1X;
			player1Move >> player1Y;

			if (player1X >= 0 && player1Y >= 0)
			{
				board[player1X][player1Y] = player1.icon;
				player1.historyMove.push_back(make_pair(player1X, player1Y));
			}

		}
		player1Move.close();

		ifstream player2Move;
		player2Move.open("save_rule3/" + filename + "p2.txt");
		int player2X;
		int player2Y;
		while (!player2Move.eof())
		{
			player2Move >> player2X;
			player2Move >> player2Y;
			if (player2X >= 0 && player2Y >= 0)
			{
				board[player2X][player2Y] = player2.icon;
				player2.historyMove.push_back(make_pair(player2X, player2Y));
			}

		}
		player2Move.close();

		board = drawBoardRule3(size, board, player1, player2, pvpConfig.boardColor, currentTime);

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

					undop1Rule3(player1, player2, board, size, goFirst, currentTime);
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
				drawBoardRule3(size, board, player1, player2, pvpConfig.boardColor, currentTime);

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


					undop2Rule3(player1, player2, board, size, goFirst, currentTime);


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




}

void deleteSavedFile_Rule3()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule3_savelist.txt");

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
	savelistWrite.open("text/rule3_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerOneFile = "save_rule3/" + filename + "p1.txt";
	string playerTwoFile = "save_rule3/" + filename + "p2.txt";
	string figureFile = "save_rule3/" + filename + "figure.txt";

	const char* playerOneFile1 = playerOneFile.c_str();
	const char* playerTwoFile1 = playerTwoFile.c_str();
	const char* figureFile1 = figureFile.c_str();

	remove(playerOneFile1);
	remove(playerTwoFile1);
	remove(figureFile1);


}

void loadRule3() {

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_Rule3();
		}

		if (choice == 1)
		{
			deleteSavedFile_Rule3();
		}
		if (choice == 2)
		{
			break;
		}
	}
}
#pragma endregion

#pragma region Load game Rule 4
int loadSaveFile_Rule4()
{
#pragma region Initial Start

	system("cls");

	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule4_savelist.txt");
	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;
		fileName.push_back(temp);
	}

	savelistRead.close();

	fileName.pop_back();


#pragma endregion

	if (fileName.size() > 0)
	{
#pragma region Set Property
		int choice = controlMenuByArrow(fileName);
		string filename = fileName[choice];


		// Set figure
		ifstream figure;
		figure.open("save_rule4/" + filename + "figure.txt");

		int size;
		int currentTime;
		int changeTime;
		int changeSize;
		Object player1;
		Object player2;

		figure >> size;
		figure >> player1.icon;
		figure >> player1.color;
		figure >> player2.icon;
		figure >> player2.color;
		figure >> player1.turn;
		figure >> player2.turn;
		figure >> currentTime;
		figure >> changeTime;
		figure >> changeSize;


		//Set property of the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };

		ifstream player1Move;
		player1Move.open("save_rule4/" + filename + "p1.txt");
		int player1X;
		int player1Y;
		while (!player1Move.eof())
		{
			player1Move >> player1X;
			player1Move >> player1Y;

			if (player1X >= 0 && player1Y >= 0)
			{
				board[player1X][player1Y] = player1.icon;
				player1.historyMove.push_back(make_pair(player1X, player1Y));
			}

		}
		player1Move.close();

		ifstream player2Move;
		player2Move.open("save_rule4/" + filename + "p2.txt");
		int player2X;
		int player2Y;
		while (!player2Move.eof())
		{
			player2Move >> player2X;
			player2Move >> player2Y;
			if (player2X >= 0 && player2Y >= 0)
			{
				board[player2X][player2Y] = player2.icon;
				player2.historyMove.push_back(make_pair(player2X, player2Y));
			}

		}
		player2Move.close();

		board = drawBoardRule4(size, board, player1, player2, pvpConfig.boardColor, currentTime);

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

}

void deleteSavedFile_Rule4()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule4_savelist.txt");

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
	savelistWrite.open("text/rule4_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerOneFile = "save_rule4/" + filename + "p1.txt";
	string playerTwoFile = "save_rule4/" + filename + "p2.txt";
	string figureFile = "save_rule4/" + filename + "figure.txt";

	const char* playerOneFile1 = playerOneFile.c_str();
	const char* playerTwoFile1 = playerTwoFile.c_str();
	const char* figureFile1 = figureFile.c_str();

	remove(playerOneFile1);
	remove(playerTwoFile1);
	remove(figureFile1);


}

void loadRule4() {

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_Rule4();
		}

		if (choice == 1)
		{
			deleteSavedFile_Rule4();
		}
		if (choice == 2)
		{
			break;
		}
	}
}
#pragma endregion

#pragma region Load game Rule 5
int loadSaveFile_Rule5()
{
#pragma region Initial Start

	system("cls");

	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule5_savelist.txt");
	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;
		fileName.push_back(temp);
	}

	savelistRead.close();

	fileName.pop_back();


#pragma endregion

	if (fileName.size() > 0)
	{
#pragma region Set Property
		int choice = controlMenuByArrow(fileName);
		string filename = fileName[choice];

		// Set figure
		ifstream figure;
		figure.open("save_rule5/" + filename + "figure.txt");

		int size;
		int rule;
		Object player1;
		Object player2;
		Object boom;

		figure >> size;
		figure >> player1.icon;
		figure >> player1.color;
		figure >> player2.icon;
		figure >> player2.color;
		figure >> boom.icon;
		figure >> boom.color;
		figure >> player1.turn;
		figure >> player2.turn;


		//Set property of the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };

		ifstream player1Move;
		player1Move.open("save_rule5/" + filename + "p1.txt");
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
		player2Move.open("save_rule5/" + filename + "p2.txt");
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

		vector<pair<int, int>> boomPos;

		ifstream boomMove;
		boomMove.open("save_rule5/" + filename + "boom.txt");
		int boomPosX;
		int boomPosY;

		while (!boomMove.eof())
		{
			boomMove >> boomPosX;
			boomMove >> boomPosY;

			if (boomPosX >= 0 && boomPosY >= 0)
			{
				board[boomPosX][boomPosY] = boom.icon;
				boomPos.push_back(make_pair(boomPosX, boomPosY));
			}
		}
		boomMove.close();

		int currentBoom = boomPos.size();

		board = drawBoardRule5(size, board, player1, player2, pvpConfig.boardColor, currentBoom);

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

						if (board[x][y] == "_" && board[x][y] == "B")
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

						if (board[x][y] == "_" && board[x][y] == "B")
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

}

void deleteSavedFile_Rule5()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule5_savelist.txt");

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
	savelistWrite.open("text/rule5_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerOneFile = "save_rule5/" + filename + "p1.txt";
	string playerTwoFile = "save_rule5/" + filename + "p2.txt";
	string figureFile = "save_rule5/" + filename + "figure.txt";
	string boomFile = "save_rule5/" + filename + "boom.txt";

	const char* playerOneFile1 = playerOneFile.c_str();
	const char* playerTwoFile1 = playerTwoFile.c_str();
	const char* figureFile1 = figureFile.c_str();
	const char* boomFile1 = boomFile.c_str();

	remove(playerOneFile1);
	remove(playerTwoFile1);
	remove(figureFile1);
	remove(boomFile1);

}

void loadRule5() {

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_Rule5();
		}

		if (choice == 1)
		{
			deleteSavedFile_Rule5();
		}
		if (choice == 2)
		{
			break;
		}
	}
}
#pragma endregion

#pragma region Load game Rule 6
int loadSaveFile_Rule6()
{
#pragma region Initial Start

	system("cls");

	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule6_savelist.txt");
	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;
		fileName.push_back(temp);
	}

	savelistRead.close();

	fileName.pop_back();


#pragma endregion

	if (fileName.size() > 0)
	{
#pragma region Set Property

		int choice = controlMenuByArrow(fileName);
		string filename = fileName[choice];

		// Set figure
		ifstream figure;
		figure.open("save_rule6/" + filename + "figure.txt");

		int size;
		int rule;
		int restrictMove;
		Object player1;
		Object player2;

		figure >> size;
		figure >> player1.icon;
		figure >> player1.color;
		figure >> player2.icon;
		figure >> player2.color;
		figure >> player1.turn;
		figure >> player2.turn;
		figure >> restrictMove;


		//Set property of the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };

		ifstream player1Move;
		player1Move.open("save_rule6/" + filename + "p1.txt");
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
		player2Move.open("save_rule6/" + filename + "p2.txt");
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

		int numMainMove = 0;
		int numSecondMove = 0;

		while (1)
		{
			if (player1.turn == 1 && player2.turn == 0)
			{
#pragma region P1 ZONE

				// P1 Zone
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player1.color);
				gotoXY(player1.x, player1.y);
				// Require the use control p1
				player1 = mainControlRule6(player1, size, board, numMainMove, restrictMove);

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

			if (player2.turn == 1 && player1.turn == 0)
			{
#pragma region P2 ZONE

				//P2 Zone
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player2.color);
				gotoXY(player2.x, player2.y);
				// Require the use control p2
				player2 = secondControlRule6(player2, size, board, numSecondMove, restrictMove);

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

}

void deleteSavedFile_Rule6()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule6_savelist.txt");

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
	savelistWrite.open("text/rule6_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerOneFile = "save_rule6/" + filename + "p1.txt";
	string playerTwoFile = "save_rule6/" + filename + "p2.txt";
	string figureFile = "save_rule6/" + filename + "figure.txt";

	const char* playerOneFile1 = playerOneFile.c_str();
	const char* playerTwoFile1 = playerTwoFile.c_str();
	const char* figureFile1 = figureFile.c_str();

	remove(playerOneFile1);
	remove(playerTwoFile1);
	remove(figureFile1);


}

void loadRule6() {

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_Rule6();
		}

		if (choice == 1)
		{
			deleteSavedFile_Rule6();
		}
		if (choice == 2)
		{
			break;
		}
	}
}
#pragma endregion

#pragma region Load game Rule 7
int loadSaveFile_Rule7()
{
#pragma region Initial Start

	system("cls");

	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	Color color;
	getColor(color);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule7_savelist.txt");
	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;
		fileName.push_back(temp);
	}

	savelistRead.close();

	fileName.pop_back();


#pragma endregion

	if (fileName.size() > 0)
	{
#pragma region Set Property

		int choice = controlMenuByArrow(fileName);
		string filename = fileName[choice];

		// Set figure
		ifstream figure;
		figure.open("save_rule7/" + filename + "figure.txt");

		int size;
		int range;
		Object player1;
		Object player2;

		figure >> size;
		figure >> player1.icon;
		figure >> player1.color;
		figure >> player2.icon;
		figure >> player2.color;
		figure >> player1.turn;
		figure >> player2.turn;
		figure >> range;


		//Set property of the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };

		ifstream player1Move;
		player1Move.open("save_rule7/" + filename + "p1.txt");
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
		player2Move.open("save_rule7/" + filename + "p2.txt");
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

		board = drawBoardRule7(size, board, player1, player2, pvpConfig.boardColor, range);

		int goFirst = 0;

		if (player1.turn == 1 && player2.turn == 0)
		{
			goFirst = 1;
		}
		if (player1.turn == 0 && player2.turn == 1)
		{
			goFirst = 2;
		}

		int lastXPosMain = 1000000;
		int lastYPosMain = 1000000;

		int lastXPosSecond = 1000000;
		int lastYPosSecond = 1000000;
		string rangeCommandLine;

#pragma endregion

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
				player2 = secondControlRule7(player2, size, board, lastXPosSecond, lastYPosSecond, range);



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
		}
	}


}

void deleteSavedFile_Rule7()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule7_savelist.txt");

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
	savelistWrite.open("text/rule7_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerOneFile = "save_rule7/" + filename + "p1.txt";
	string playerTwoFile = "save_rule7/" + filename + "p2.txt";
	string figureFile = "save_rule7/" + filename + "figure.txt";

	const char* playerOneFile1 = playerOneFile.c_str();
	const char* playerTwoFile1 = playerTwoFile.c_str();
	const char* figureFile1 = figureFile.c_str();

	remove(playerOneFile1);
	remove(playerTwoFile1);
	remove(figureFile1);


}

void loadRule7() {

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_Rule7();
		}

		if (choice == 1)
		{
			deleteSavedFile_Rule7();
		}
		if (choice == 2)
		{
			break;
		}
	}
}
#pragma endregion

#pragma region Load game Rule 8
int loadSaveFile_Rule8()
{
#pragma region Initial Start

	system("cls");

	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule8_savelist.txt");
	vector<string> fileName;

	while (!savelistRead.eof())
	{
		string temp;
		savelistRead >> temp;
		fileName.push_back(temp);
	}

	savelistRead.close();

	fileName.pop_back();


#pragma endregion


	if (fileName.size() > 0)
	{
#pragma region Set Property

		int choice = controlMenuByArrow(fileName);
		string filename = fileName[choice];

		// Set figure
		ifstream figure;
		figure.open("save_rule8/" + filename + "figure.txt");

		int size;
		int rule;
		Object player1;
		Object player2;
		Object changed;

		figure >> size;
		figure >> player1.icon;
		figure >> player1.color;
		figure >> player2.icon;
		figure >> player2.color;
		figure >> changed.icon;
		figure >> changed.color;
		figure >> player1.turn;
		figure >> player2.turn;


		//Set property of the board
		system("cls");
		vector<string> temp = { 100,"_" };
		vector<vector<string>> board{ 100,temp };

		ifstream player1Move;
		player1Move.open("save_rule8/" + filename + "p1.txt");
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
		player2Move.open("save_rule8/" + filename + "p2.txt");
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

		vector<pair<int, int>> changedPos;

		ifstream changedMove;
		changedMove.open("save_rule8/" + filename + "changed.txt");
		int changedPosX;
		int changedPosY;

		while (!changedMove.eof())
		{
			changedMove >> changedPosX;
			changedMove >> changedPosY;

			if (changedPosX >= 0 && changedPosY >= 0)
			{
				board[changedPosX][changedPosY] = changed.icon;
				changedPos.push_back(make_pair(changedPosX, changedPosY));
			}
		}
		changedMove.close();

		int currentChangedItem = changedPos.size();

		board = drawBoardRule8(size, board, player1, player2, currentChangedItem, pvpConfig.boardColor);

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

}

void deleteSavedFile_Rule8()
{
	system("cls");

	// Show saved file
	ifstream savelistRead;
	savelistRead.open("text/rule8_savelist.txt");

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
	savelistWrite.open("text/rule8_savelist.txt");

	for (int i = 0; i < fileName.size(); i++)
	{
		savelistWrite << fileName[i] << endl;
	}

	savelistWrite.close();

	string playerOneFile = "save_rule8/" + filename + "p1.txt";
	string playerTwoFile = "save_rule8/" + filename + "p2.txt";
	string figureFile = "save_rule8/" + filename + "figure.txt";
	string boomFile = "save_rule8/" + filename + "changed.txt";

	const char* playerOneFile1 = playerOneFile.c_str();
	const char* playerTwoFile1 = playerTwoFile.c_str();
	const char* figureFile1 = figureFile.c_str();
	const char* boomFile1 = boomFile.c_str();

	remove(playerOneFile1);
	remove(playerTwoFile1);
	remove(figureFile1);
	remove(boomFile1);

}

void loadRule8() {

	vector<string> task = { "Load saved file", "Delete saved file","Back" };
	while (1)
	{
		int choice = controlMenuByArrow(task);

		if (choice == 0)
		{
			loadSaveFile_Rule8();
		}

		if (choice == 1)
		{
			deleteSavedFile_Rule8();
		}
		if (choice == 2)
		{
			break;
		}
	}
}
#pragma endregion

#pragma endregion



void load() {
	int width = getConsoleWidth();
	int height = getConsoleHeight();
	ifstream loadintro;
	loadintro.open("text/loadmode.txt");

	gotoXY(width / 2 - 30, height / 2 - 1);
	animateText(loadintro);
	loadintro.close();
	Sleep(2000);
	vector<string> type = { "PvP mode", "PvC mode" , "Rule mode" };

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
	if (choice == 2)
	{
		system("cls");
		vector<string> rule = { "The story of the rock", "Another enenemy","Turn the tables","Decreasing Size","Take care hidden boom","Restriction","Shooter","Powerful of change" ,"Back" };
		int ruleChoice = controlMenuByArrow(rule);

		if (ruleChoice == 0)
		{
			loadRule1();
		}
		if (ruleChoice == 1)
		{
			loadRule2();
		}
		if (ruleChoice == 2)
		{
			loadRule3();
		}
		if (ruleChoice == 3)
		{
			loadRule4();
		}
		if (ruleChoice == 4)
		{
			loadRule5();
		}
		if (ruleChoice == 5)
		{
			loadRule6();
		}
		if (ruleChoice == 6)
		{
			loadRule7();
		}
		if (ruleChoice == 7)
		{
			loadRule8();
		}
	}
}

