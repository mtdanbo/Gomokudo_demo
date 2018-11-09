#include "pvp.h"

int PvP_mode() {

	while (1)
	{
		#pragma region Instruction PvP

		system("cls");

		Color color;
		getColor(color);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

		PvPConfig pvpConfig;
		getPvPConfig(pvpConfig);

		// Instruction PvP to Players
		int width = getConsoleWidth();
		int height = getConsoleHeight();
		gotoXY(width / 2 - 15, height / 2 - 1);
		//ifstream pvp;
		//pvp.open("text/pvp.txt");
		//animateText(pvp);

		// Choose original mode or rule mode
		gotoXY(width / 2, height / 2);
		vector<string> style = { "Orginal Style", "Rule Style" , "Back" };
		int styleChoice = controlMenuByArrow(style);

		system("cls");

		#pragma endregion

		/*----------------Original Mode---------------*/
		if (styleChoice == 0)
		{
			while (1)
			{
				vector<string> type = { "3 x 3","4 x 4","N x N (N > 4)" , "Back" };
				int choice = controlMenuByArrow(type);

				//------------3x3-----------//
				if (choice == 0)
				{
#pragma region Initial Start

					// Initialize player properties
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

					Object player1;
					player1.icon = pvpConfig.mainIcon;
					player1.color = pvpConfig.mainColor;

					Object player2;
					player2.icon = pvpConfig.secondIcon;
					player2.color = pvpConfig.secondColor;

					int size = 3;

					// Identify who go first
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
					drawBoard(size, board, player1, player2, pvpConfig.boardColor);

					// Gameplay
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
								player1.win = Compute3(player1, size, board);
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
								player2.win = Compute3(player2, size, board);
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

				//----------4x4----------//
				if (choice == 1)
				{
#pragma region Initial Start

					// Initialize player properties
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

					Object player1;
					player1.icon = pvpConfig.mainIcon;
					player1.color = pvpConfig.mainColor;

					Object player2;
					player2.icon = pvpConfig.secondIcon;
					player2.color = pvpConfig.secondColor;

					int size = 4;

					// Identify who go first
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
					drawBoard(size, board, player1, player2, pvpConfig.boardColor);

					// Gameplay
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
								player1.win = Compute4(player1, size, board);
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
								player2.win = Compute4(player2, size, board);
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

				//--------------NxN-----------//
				if (choice == 2)
				{
#pragma region Initial Start
					// Initialize player properties
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

					Object player1;
					player1.icon = pvpConfig.mainIcon;
					player1.color = pvpConfig.mainColor;

					Object player2;
					player2.icon = pvpConfig.secondIcon;
					player2.color = pvpConfig.secondColor;

					int size = pvpConfig.sizeBoard;

					// Identify who go first
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
					drawBoard(size, board, player1, player2, pvpConfig.boardColor);

					// Gameplay
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
								player1.win = ComputeN(player1, size, board);
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
								player2.win = ComputeN(player2, size, board);
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

				if (choice == 3)
				{
					break;
				}
			}
		}

		if (styleChoice == 1)
		{
			vector<string> rule = { "The story of the rock", "Another enenemy","Turn the tables","Decreasing Size","Take care hidden boom","Restriction","Shooter","Powerful of change" ,"Back"};
			int choice = controlMenuByArrow(rule);

			switch (choice)
			{
			case 0:
				rule1();
				break;
			case 1:
				rule2();
				break;
			case 2:
				rule3();
				break;
			case 3:
				rule4();
				break;
			case 4:
				rule5();
				break;
			case 5:
				rule6();
				break;
			case 6:
				rule7();
				break;
			case 7:
				rule8();
				break;
			case 8:
				break;
			}

		}

		if (styleChoice == 2)
		{
			break;
		}
	}

}