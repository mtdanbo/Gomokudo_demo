#include "hard.h"

#pragma region setScoreBoard

void setScoreVertical(int size, vector<vector<string>> Board, int turn, Object &o)
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
				if (Board[x][y + temp] == "X")
				{
					numPlayer++;

				}
				if (Board[x][y + temp] == "O")
				{
					numBot++;

				}
			}
			if (numPlayer*numBot == 0 && numBot != numPlayer)
			{
				for (int temp = 0; temp < 5; temp++)
				{
					if (Board[x][y + temp] == "_")
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

void findMaxPoints(int maxMove, int size, Object &o, vector<pair<int, int>> &maxScorePoint)
{
	int count = 0;

	for (int x = 0; x < size; x++)
	{

		for (int y = 0; y < size; y++)
		{

			if (o.Score[x][y] == o.max_score)
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

int findMove(int maxDepth, int maxMove, int depth, vector<vector<string>> Board, Object p, Object b, int size, int &miniMax, Point &point)
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

			setScore(size, Board, turn, b);

			findMaxScore(size, b);

			vector<pair<int, int>> maxScorePoint;

			findMaxPoints(maxMove, size, b, maxScorePoint);

			for (int i = 0; i < maxScorePoint.size(); i++)
			{

				Board[maxScorePoint[i].first][maxScorePoint[i].second] = b.icon;

				b.win = Compute(b, size, Board);

				if (b.win == 1)
				{
					miniMax = 10;
				}


				findMove(maxDepth, maxMove, depth + 1, Board, p, b, size, miniMax, point);

				if (miniMax == 10 && depth != 0)
				{
					return 0;
				}

				if (miniMax == 10 && depth == 0)
				{
					gotoXY(maxScorePoint[i].first * 2, maxScorePoint[i].second);
					cout << b.icon;
					point.x = maxScorePoint[i].first;
					point.y = maxScorePoint[i].second;


					return 0;
				}


				Board[maxScorePoint[i].first][maxScorePoint[i].second] = "_";

				if (miniMax == 0 && depth == 0 && i == maxScorePoint.size() - 1)
				{

					int random = rand() % maxScorePoint.size();

					gotoXY(maxScorePoint[random].first * 2, maxScorePoint[random].second);
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

			setScore(size, Board, turn, p);

			findMaxScore(size, p);

			vector<pair<int, int>> maxScorePoint;

			findMaxPoints(maxMove, size, p, maxScorePoint);

			for (int i = 0; i < maxScorePoint.size(); i++)
			{

				Board[maxScorePoint[i].first][maxScorePoint[i].second] = p.icon;

				p.win = Compute(p, size, Board);

				if (p.win == 1)
				{
					miniMax = -10;
				}

				findMove(maxDepth, maxMove, depth + 1, Board, p, b, size, miniMax, point);

				if (miniMax == 10 && depth != 0)
				{
					return 0;
				}


				Board[maxScorePoint[i].first][maxScorePoint[i].second] = "_";

			}


		}


	}


}

#pragma endregion




