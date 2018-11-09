#include "bot.h"

#pragma region For 3x3

	#pragma region setScoreBoard3

	void setScoreVertical3(int size, vector<vector<string>> board, int turn, Object &o)
	{
		int numPlayer = 0;
		int numBot = 0;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				numPlayer = 0;
				numBot = 0;
				if (y > size - 3)
				{
					break;
				}
				for (int temp = 0; temp < 3; temp++)
				{
					if (board[x][y + temp] == "X")
					{
						numPlayer++;

					}
					if (board[x][y + temp] == "O")
					{
						numBot++;

					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 3; temp++)
					{
						if (board[x][y + temp] == "_")
						{
							if (numBot == 0)
							{
								if (turn == 2)
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(defPoint, numPlayer);
								}
								else
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(atkPoint, numPlayer);
								}


							}
							if (numPlayer == 0)
							{
								if (turn == 1)
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(defPoint, numBot);
								}
								else
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(atkPoint, numBot);
								}
							}

							if (numPlayer == 2 || numBot == 2)
							{
								o.Score[x][y + temp] = o.Score[x][y + temp] * 2;
							}
						}
					}
				}
			}
		}
	}

	void setScoreHorizontal3(int size, vector<vector<string>> Board, int turn, Object &o) {
		int numPlayer = 0;
		int numBot = 0;
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				numPlayer = 0;
				numBot = 0;
				for (int temp = 0; temp < 3; temp++)
				{
					if (Board[x + temp][y] == "X")
					{
						numPlayer++;
					}
					if (Board[x + temp][y] == "O")
					{
						numBot++;
					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 3; temp++)
					{
						if (Board[x + temp][y] == "_")
						{
							if (numBot == 0)
							{
								if (turn == 2)
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(defPoint, numPlayer);
								}
								else
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(atkPoint, numPlayer);
								}


							}
							if (numPlayer == 0)
							{
								if (turn == 1)
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(defPoint, numBot);
								}
								else
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(atkPoint, numBot);
								}
							}

							if (numPlayer == 2 || numBot == 2)
							{
								o.Score[x + temp][y] = o.Score[x + temp][y] * 2;
							}
						}
					}
				}
			}
		}
	}

	void setScoreDiagonalDown3(int size, vector<vector<string>> Board, int turn, Object &o)
	{
		int numPlayer = 0;
		int numBot = 0;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				numPlayer = 0;
				numBot = 0;
				for (int temp = 0; temp < 3; temp++)
				{
					if (Board[x + temp][y + temp] == "X")
					{
						numPlayer++;
					}
					if (Board[x + temp][y + temp] == "O")
					{
						numBot++;
					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 3; temp++)
					{
						if (Board[x + temp][y + temp] == "_")
						{
							if (numBot == 0)
							{
								if (turn == 2)
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(defPoint, numPlayer);
								}
								else
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(atkPoint, numPlayer);
								}


							}
							if (numPlayer == 0)
							{
								if (turn == 1)
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(defPoint, numBot);
								}
								else
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(atkPoint, numBot);
								}
							}

							if (numPlayer == 2 || numBot == 2)
							{
								o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] * 2;
							}
						}
					}
				}
			}
		}
	}

	void setScoreDiagonalUp3(int size, vector<vector<string>> Board, int turn, Object &o)
	{
		int numPlayer = 0;
		int numBot = 0;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				numPlayer = 0;
				numBot = 0;
				for (int temp = 0; temp < 3; temp++)
				{
					if (y >= 2)
					{
						if (Board[x + temp][y - temp] == "X")
						{
							numPlayer++;
						}
						if (Board[x + temp][y - temp] == "O")
						{
							numBot++;
						}
					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 3; temp++)
					{
						if (y >= 2)
						{
							if (Board[x + temp][y - temp] == "_")
							{
								if (numBot == 0)
								{
									if (turn == 2)
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(defPoint, numPlayer);
									}
									else
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(atkPoint, numPlayer);
									}
								}
								if (numPlayer == 0)
								{
									if (turn == 1)
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(defPoint, numBot);
									}
									else
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(atkPoint, numBot);
									}
								}

								if (numPlayer == 2 || numBot == 2)
								{
									o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] * 2;
								}
							}
						}
					}
				}
			}
		}
	}

	void setScore3(int size, vector<vector<string>> Board, int turn, Object &o)
	{
		setScoreVertical3(size, Board, turn, o);
		setScoreHorizontal3(size, Board, turn, o);
		setScoreDiagonalUp3(size, Board, turn, o);
		setScoreDiagonalDown3(size, Board, turn, o);

	}

	#pragma endregion

	#pragma region fundamentalAction3

	void resetScore3(int size, Object &o)
	{

		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				o.Score[x][y] = 0;
			}
		}

		o.max_score = 0;

	}

	void findMaxScore3(int size, Object &o)
	{
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{

				if (o.Score[x][y] > o.max_score)
				{
					o.max_score = o.Score[x][y];
				}


			}
		}


	}

	void findMaxPoints3(int maxMove, int size, Object &o, vector<pair<int, int>> &maxScorePoint, vector<vector<string>> board)
	{
		int count = 0;

		for (int x = 0; x < size; x++)
		{

			for (int y = 0; y < size; y++)
			{

				if (o.Score[x][y] == o.max_score && board[x][y] == "_")
				{
					maxScorePoint.push_back(make_pair(x, y));
					count++;
				}

				if (count == maxMove)
				{
					break;
				}

			}

		}

	}

	#pragma endregion

	#pragma region findMove

	int findMove3(int maxDepth, int maxMove, int depth, vector<vector<string>> board, Object p, Object b, int size, int &miniMax, Point &point)
	{
		if (miniMax == 10)
		{
			return 0;
		}

		if (miniMax == -10)
		{
			miniMax = 0;
		}

		if (depth >= maxDepth)
		{

			return 0;

		}
		else
		{

			if (depth % 2 == 0)
			{
				int turn = 2;

				resetScore3(size, b);

				setScore3(size, board, turn, b);

				findMaxScore3(size, b);

				vector<pair<int, int>> maxScorePoint;

				findMaxPoints3(maxMove, size, b, maxScorePoint,board);

				for (int i = 0; i < maxScorePoint.size(); i++)
				{

					board[maxScorePoint[i].first][maxScorePoint[i].second] = b.icon;

					b.win = Compute3(b, size, board);

					if (b.win == 1)
					{
						miniMax = 10;
					}


					findMove3(maxDepth, maxMove, depth + 1, board, p, b, size, miniMax, point);

					if (miniMax == 10 && depth != 0)
					{
						return 0;
					}

					if (miniMax == 10 && depth == 0)
					{
						gotoXY(maxScorePoint[i].first * 4 + 2, maxScorePoint[i].second * 2 + 1);
						cout << b.icon;
						point.x = maxScorePoint[i].first;
						point.y = maxScorePoint[i].second;

						return 0;
					}


					board[maxScorePoint[i].first][maxScorePoint[i].second] = "_";

					if (miniMax == 0 && depth == 0 && i == maxScorePoint.size() - 1)
					{

						int random = rand() % maxScorePoint.size();

						gotoXY(maxScorePoint[random].first * 4 + 2, maxScorePoint[random].second * 2 + 1);
						cout << b.icon;
						point.x = maxScorePoint[random].first;
						point.y = maxScorePoint[random].second;

						return 0;
					}


				}

			}
			else
			{
				int turn = 1;

				resetScore3(size, p);

				setScore3(size, board, turn, p);

				findMaxScore3(size, p);

				vector<pair<int, int>> maxScorePoint;

				findMaxPoints3(maxMove, size, p, maxScorePoint,board);

				for (int i = 0; i < maxScorePoint.size(); i++)
				{

					board[maxScorePoint[i].first][maxScorePoint[i].second] = p.icon;

					p.win = Compute3(p, size, board);

					if (p.win == 1)
					{
						miniMax = -10;
					}

					findMove3(maxDepth, maxMove, depth + 1, board, p, b, size, miniMax, point);

					if (miniMax == 10 && depth != 0)
					{
						return 0;
					}


					board[maxScorePoint[i].first][maxScorePoint[i].second] = "_";

				}


			}


		}


	}

	#pragma endregion

#pragma endregion


#pragma region For 4x4

	#pragma region setScoreBoard4

	void setScoreVertical4(int size, vector<vector<string>> board, int turn, Object &o)
	{
		int numPlayer = 0;
		int numBot = 0;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				numPlayer = 0;
				numBot = 0;
				if (y > size - 4)
				{
					break;
				}
				for (int temp = 0; temp < 4; temp++)
				{
					if (board[x][y + temp] == "X")
					{
						numPlayer++;

					}
					if (board[x][y + temp] == "O")
					{
						numBot++;

					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 4; temp++)
					{
						if (board[x][y + temp] == "_")
						{
							if (numBot == 0)
							{
								if (turn == 2)
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(defPoint, numPlayer);
								}
								else
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(atkPoint, numPlayer);
								}


							}
							if (numPlayer == 0)
							{
								if (turn == 1)
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(defPoint, numBot);
								}
								else
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(atkPoint, numBot);
								}
							}

							if (numPlayer == 3 || numBot == 3)
							{
								o.Score[x][y + temp] = o.Score[x][y + temp] * 2;
							}
						}
					}
				}
			}
		}
	}

	void setScoreHorizontal4(int size, vector<vector<string>> Board, int turn, Object &o) {
		int numPlayer = 0;
		int numBot = 0;
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				numPlayer = 0;
				numBot = 0;
				for (int temp = 0; temp < 4; temp++)
				{
					if (Board[x + temp][y] == "X")
					{
						numPlayer++;
					}
					if (Board[x + temp][y] == "O")
					{
						numBot++;
					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 4; temp++)
					{
						if (Board[x + temp][y] == "_")
						{
							if (numBot == 0)
							{
								if (turn == 2)
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(defPoint, numPlayer);
								}
								else
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(atkPoint, numPlayer);
								}


							}
							if (numPlayer == 0)
							{
								if (turn == 1)
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(defPoint, numBot);
								}
								else
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(atkPoint, numBot);
								}
							}

							if (numPlayer == 3 || numBot == 3)
							{
								o.Score[x + temp][y] = o.Score[x + temp][y] * 2;
							}
						}
					}
				}
			}
		}
	}

	void setScoreDiagonalDown4(int size, vector<vector<string>> Board, int turn, Object &o)
	{
		int numPlayer = 0;
		int numBot = 0;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				numPlayer = 0;
				numBot = 0;
				for (int temp = 0; temp < 4; temp++)
				{
					if (Board[x + temp][y + temp] == "X")
					{
						numPlayer++;
					}
					if (Board[x + temp][y + temp] == "O")
					{
						numBot++;
					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 4; temp++)
					{
						if (Board[x + temp][y + temp] == "_")
						{
							if (numBot == 0)
							{
								if (turn == 2)
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(defPoint, numPlayer);
								}
								else
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(atkPoint, numPlayer);
								}


							}
							if (numPlayer == 0)
							{
								if (turn == 1)
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(defPoint, numBot);
								}
								else
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(atkPoint, numBot);
								}
							}

							if (numPlayer == 3 || numBot == 3)
							{
								o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] * 2;
							}
						}
					}
				}
			}
		}
	}

	void setScoreDiagonalUp4(int size, vector<vector<string>> Board, int turn, Object &o)
	{
		int numPlayer = 0;
		int numBot = 0;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				numPlayer = 0;
				numBot = 0;
				for (int temp = 0; temp < 4; temp++)
				{
					if (y >= 3)
					{
						if (Board[x + temp][y - temp] == "X")
						{
							numPlayer++;
						}
						if (Board[x + temp][y - temp] == "O")
						{
							numBot++;
						}
					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 4; temp++)
					{
						if (y >= 3)
						{
							if (Board[x + temp][y - temp] == "_")
							{
								if (numBot == 0)
								{
									if (turn == 2)
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(defPoint, numPlayer);
									}
									else
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(atkPoint, numPlayer);
									}
								}
								if (numPlayer == 0)
								{
									if (turn == 1)
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(defPoint, numBot);
									}
									else
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(atkPoint, numBot);
									}
								}

								if (numPlayer == 3 || numBot == 3)
								{
									o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] * 2;
								}
							}
						}
					}
				}
			}
		}
	}

	void setScore4(int size, vector<vector<string>> Board, int turn, Object &o)
	{
		setScoreVertical4(size, Board, turn, o);
		setScoreHorizontal4(size, Board, turn, o);
		setScoreDiagonalUp4(size, Board, turn, o);
		setScoreDiagonalDown4(size, Board, turn, o);

	}

	#pragma endregion

	#pragma region fundamentalAction

	void resetScore4(int size, Object &o)
	{

		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				o.Score[x][y] = 0;
			}
		}

		o.max_score = 0;

	}

	void findMaxScore4(int size, Object &o)
	{
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{

				if (o.Score[x][y] > o.max_score)
				{
					o.max_score = o.Score[x][y];
				}


			}
		}


	}

	void findMaxPoints4(int maxMove, int size, Object &o, vector<pair<int, int>> &maxScorePoint, vector<vector<string>> board)
	{
		int count = 0;

		for (int x = 0; x < size; x++)
		{

			for (int y = 0; y < size; y++)
			{

				if (o.Score[x][y] == o.max_score && board[x][y] == "_")
				{
					maxScorePoint.push_back(make_pair(x, y));
					count++;
				}

				if (count == maxMove)
				{
					break;
				}

			}

		}

	}

	#pragma endregion

	#pragma region findMove

	int findMove4(int maxDepth, int maxMove, int depth, vector<vector<string>> board, Object p, Object b, int size, int &miniMax, Point &point)
	{
		if (miniMax == 10)
		{
			return 0;

		}

		if (miniMax == -10)
		{
			miniMax = 0;
		}

		if (depth >= maxDepth)
		{

			return 0;

		}
		else
		{

			if (depth % 2 == 0)
			{
				int turn = 2;

				resetScore4(size, b);

				setScore4(size, board, turn, b);

				findMaxScore4(size, b);

				vector<pair<int, int>> maxScorePoint;

				findMaxPoints4(maxMove, size, b, maxScorePoint,board);

				for (int i = 0; i < maxScorePoint.size(); i++)
				{

					board[maxScorePoint[i].first][maxScorePoint[i].second] = b.icon;

					b.win = Compute4(b, size, board);

					if (b.win == 1)
					{
						miniMax = 10;
					}


					findMove4(maxDepth, maxMove, depth + 1, board, p, b, size, miniMax, point);

					if (miniMax == 10 && depth != 0)
					{
						return 0;
					}

					if (miniMax == 10 && depth == 0)
					{
						gotoXY(maxScorePoint[i].first * 4 + 2, maxScorePoint[i].second * 2 + 1);
						cout << b.icon;
						point.x = maxScorePoint[i].first;
						point.y = maxScorePoint[i].second;

						return 0;
					}


					board[maxScorePoint[i].first][maxScorePoint[i].second] = "_";

					if (miniMax == 0 && depth == 0 && i == maxScorePoint.size() - 1)
					{

						int random = rand() % maxScorePoint.size();

						gotoXY(maxScorePoint[random].first * 4 + 2, maxScorePoint[random].second * 2 + 1);
						cout << b.icon;
						point.x = maxScorePoint[random].first;
						point.y = maxScorePoint[random].second;

						return 0;
					}


				}

			}
			else
			{
				int turn = 1;

				resetScore4(size, p);

				setScore4(size, board, turn, p);

				findMaxScore4(size, p);

				vector<pair<int, int>> maxScorePoint;

				findMaxPoints4(maxMove, size, p, maxScorePoint,board);

				for (int i = 0; i < maxScorePoint.size(); i++)
				{

					board[maxScorePoint[i].first][maxScorePoint[i].second] = p.icon;

					p.win = Compute4(p, size, board);

					if (p.win == 1)
					{
						miniMax = -10;
					}

					findMove4(maxDepth, maxMove, depth + 1, board, p, b, size, miniMax, point);

					if (miniMax == 10 && depth != 0)
					{
						return 0;
					}


					board[maxScorePoint[i].first][maxScorePoint[i].second] = "_";

				}


			}


		}


	}

	#pragma endregion

#pragma endregion


#pragma region For NxN

	#pragma region setScoreBoard

	void setScoreVertical(int size, vector<vector<string>> board, int turn, Object &o)
	{
		int numPlayer = 0;
		int numBot = 0;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				numPlayer = 0;
				numBot = 0;
				if (y > size - 5)
				{
					break;
				}
				for (int temp = 0; temp < 5; temp++)
				{
					if (board[x][y + temp] == "X")
					{
						numPlayer++;

					}
					if (board[x][y + temp] == "O")
					{
						numBot++;

					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 5; temp++)
					{
						if (board[x][y + temp] == "_")
						{
							if (numBot == 0)
							{
								if (turn == 2)
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(defPoint, numPlayer);
								}
								else
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(atkPoint, numPlayer);
								}


							}
							if (numPlayer == 0)
							{
								if (turn == 1)
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(defPoint, numBot);
								}
								else
								{
									o.Score[x][y + temp] = o.Score[x][y + temp] + pow(atkPoint, numBot);
								}
							}

							if (numPlayer == 4 || numBot == 4)
							{
								o.Score[x][y + temp] = o.Score[x][y + temp] * 2;
							}
						}
					}
				}
			}
		}
	}

	void setScoreHorizontal(int size, vector<vector<string>> Board, int turn, Object &o) {
		int numPlayer = 0;
		int numBot = 0;
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				numPlayer = 0;
				numBot = 0;
				for (int temp = 0; temp < 5; temp++)
				{
					if (Board[x + temp][y] == "X")
					{
						numPlayer++;
					}
					if (Board[x + temp][y] == "O")
					{
						numBot++;
					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 5; temp++)
					{
						if (Board[x + temp][y] == "_")
						{
							if (numBot == 0)
							{
								if (turn == 2)
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(defPoint, numPlayer);
								}
								else
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(atkPoint, numPlayer);
								}


							}
							if (numPlayer == 0)
							{
								if (turn == 1)
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(defPoint, numBot);
								}
								else
								{
									o.Score[x + temp][y] = o.Score[x + temp][y] + pow(atkPoint, numBot);
								}
							}

							if (numPlayer == 4 || numBot == 4)
							{
								o.Score[x + temp][y] = o.Score[x + temp][y] * 2;
							}
						}
					}
				}
			}
		}
	}

	void setScoreDiagonalDown(int size, vector<vector<string>> Board, int turn, Object &o)
	{
		int numPlayer = 0;
		int numBot = 0;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				numPlayer = 0;
				numBot = 0;
				for (int temp = 0; temp < 5; temp++)
				{
					if (Board[x + temp][y + temp] == "X")
					{
						numPlayer++;
					}
					if (Board[x + temp][y + temp] == "O")
					{
						numBot++;
					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 5; temp++)
					{
						if (Board[x + temp][y + temp] == "_")
						{
							if (numBot == 0)
							{
								if (turn == 2)
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(defPoint, numPlayer);
								}
								else
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(atkPoint, numPlayer);
								}


							}
							if (numPlayer == 0)
							{
								if (turn == 1)
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(defPoint, numBot);
								}
								else
								{
									o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] + pow(atkPoint, numBot);
								}
							}

							if (numPlayer == 4 || numBot == 4)
							{
								o.Score[x + temp][y + temp] = o.Score[x + temp][y + temp] * 2;
							}
						}
					}
				}
			}
		}
	}

	void setScoreDiagonalUp(int size, vector<vector<string>> Board, int turn, Object &o)
	{
		int numPlayer = 0;
		int numBot = 0;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				numPlayer = 0;
				numBot = 0;
				for (int temp = 0; temp < 5; temp++)
				{
					if (y >= 4)
					{
						if (Board[x + temp][y - temp] == "X")
						{
							numPlayer++;
						}
						if (Board[x + temp][y - temp] == "O")
						{
							numBot++;
						}
					}
				}
				if (numPlayer*numBot == 0 && numBot != numPlayer)
				{
					for (int temp = 0; temp < 5; temp++)
					{
						if (y >= 4)
						{
							if (Board[x + temp][y - temp] == "_")
							{
								if (numBot == 0)
								{
									if (turn == 2)
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(defPoint, numPlayer);
									}
									else
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(atkPoint, numPlayer);
									}
								}
								if (numPlayer == 0)
								{
									if (turn == 1)
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(defPoint, numBot);
									}
									else
									{
										o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] + pow(atkPoint, numBot);
									}
								}

								if (numPlayer == 4 || numBot == 4)
								{
									o.Score[x + temp][y - temp] = o.Score[x + temp][y - temp] * 2;
								}
							}
						}
					}
				}
			}
		}
	}

	void setScore(int size, vector<vector<string>> Board, int turn, Object &o)
	{
		setScoreVertical(size, Board, turn, o);
		setScoreHorizontal(size, Board, turn, o);
		setScoreDiagonalUp(size, Board, turn, o);
		setScoreDiagonalDown(size, Board, turn, o);

	}

	#pragma endregion

	#pragma region fundamentalAction

	void resetScore(int size, Object &o)
	{

		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				o.Score[x][y] = 0;
			}
		}

		o.max_score = 0;

	}

	void findMaxScore(int size, Object &o)
	{
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{

				if (o.Score[x][y] > o.max_score)
				{
					o.max_score = o.Score[x][y];
				}


			}
		}


	}

	void findMaxPoints(int maxMove, int size, Object &o, vector<pair<int, int>> &maxScorePoint, vector<vector<string>> board)
	{
		int count = 0;

		for (int x = 0; x < size; x++)
		{

			for (int y = 0; y < size; y++)
			{

				if (o.Score[x][y] == o.max_score && board[x][y] == "_")
				{
					maxScorePoint.push_back(make_pair(x, y));
					count++;
				}

				if (count == maxMove)
				{
					break;
				}

			}

		}

	}

	#pragma endregion

	#pragma region findMove

	int findMove(int maxDepth, int maxMove, int depth, vector<vector<string>> board, Object p, Object b, int size, int &miniMax, Point &point)
	{
		if (miniMax == 10)
		{
			return 0;


		}

		if (miniMax == -10)
		{
			miniMax = 0;
		}

		if (depth >= maxDepth)
		{

			return 0;

		}
		else
		{

			if (depth % 2 == 0)
			{
				int turn = 2;

				resetScore(size, b);

				setScore(size, board, turn, b);

				findMaxScore(size, b);

				vector<pair<int, int>> maxScorePoint;

				findMaxPoints(maxMove, size, b, maxScorePoint,board);

				for (int i = 0; i < maxScorePoint.size(); i++)
				{

					board[maxScorePoint[i].first][maxScorePoint[i].second] = b.icon;

					b.win = ComputeN(b, size, board);

					if (b.win == 1)
					{
						miniMax = 10;
					}


					findMove(maxDepth, maxMove, depth + 1, board, p, b, size, miniMax, point);

					if (miniMax == 10 && depth != 0)
					{
						return 0;
					}

					if (miniMax == 10 && depth == 0)
					{
						gotoXY(maxScorePoint[i].first * 4 + 2, maxScorePoint[i].second * 2 + 1);
						cout << b.icon;
						point.x = maxScorePoint[i].first;
						point.y = maxScorePoint[i].second;

						return 0;
					}


					board[maxScorePoint[i].first][maxScorePoint[i].second] = "_";

					if (miniMax == 0 && depth == 0 && i == maxScorePoint.size() - 1)
					{

						int random = rand() % maxScorePoint.size();

						gotoXY(maxScorePoint[random].first * 4 + 2, maxScorePoint[random].second * 2 + 1);
						cout << b.icon;
						point.x = maxScorePoint[random].first;
						point.y = maxScorePoint[random].second;

						return 0;
					}


				}

			}
			else
			{
				int turn = 1;

				resetScore(size, p);

				setScore(size, board, turn, p);

				findMaxScore(size, p);

				vector<pair<int, int>> maxScorePoint;

				findMaxPoints(maxMove, size, p, maxScorePoint,board);

				for (int i = 0; i < maxScorePoint.size(); i++)
				{

					board[maxScorePoint[i].first][maxScorePoint[i].second] = p.icon;

					p.win = ComputeN(p, size, board);

					if (p.win == 1)
					{
						miniMax = -10;
					}

					findMove(maxDepth, maxMove, depth + 1, board, p, b, size, miniMax, point);

					if (miniMax == 10 && depth != 0)
					{
						return 0;
					}


					board[maxScorePoint[i].first][maxScorePoint[i].second] = "_";

				}


			}


		}


	}

	#pragma endregion

#pragma endregion







