#include "bot.h"
Data setScoreVertical(int size, vector<vector<string>> Board, Data d) {
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
				if (Board[x][y+temp] == "X")
				{
					numPlayer++;
					d.Atk[x][y + temp] = 0;
					d.Def[x][y + temp] = 0;
				}
				if (Board[x][y+temp] == "O")
				{
					numBot++;
					d.Atk[x][y + temp] = 0;
					d.Def[x][y + temp] = 0;
				}
			}
			if (numPlayer*numBot == 0 && numBot != numPlayer)
			{
				for (int temp = 0; temp < 5; temp++)
				{
					if (Board[x][y+temp] == "_")
					{
						if (numBot == 0)
						{
							d.Def[x][y + temp] = d.Def[x][y+temp] +  pow(def_point,numPlayer);
						}
						if (numPlayer == 0)
						{
							d.Atk[x][y + temp] = d.Atk[x][y+temp] +  pow(atk_point,numBot);
						}
					}
				}
			}
		}
	}
	return d;
}


Data setScoreHorizontal(int size, vector<vector<string>> Board, Data d) {
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
					d.Atk[x+temp][y] = 0;
					d.Def[x+temp][y] = 0;
				}
				if (Board[x + temp][y] == "O")
				{
					numBot++;
					d.Atk[x+temp][y] = 0;
					d.Def[x+temp][y] = 0;
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
							d.Def[x+temp][y] = d.Def[x+temp][y] + pow(def_point, numPlayer);
						}
						if (numPlayer == 0)
						{
							d.Atk[x+temp][y] = d.Atk[x+temp][y] + pow(atk_point, numBot);
						}
					}
				}
			}
		}
	}
	return d;
}

Data setScoreDiagonalDown(int size, vector<vector<string>> Board, Data d) {
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
				if (Board[x+temp][y + temp] == "X")
				{
					numPlayer++;
					d.Atk[x+temp][y + temp] = 0;
					d.Def[x+temp][y + temp] = 0;
				}
				if (Board[x+temp][y + temp] == "O")
				{
					numBot++;
					d.Atk[x+temp][y + temp] = 0;
					d.Def[x+temp][y + temp] = 0;
				}
			}
			if (numPlayer*numBot == 0 && numBot != numPlayer)
			{
				for (int temp = 0; temp < 5; temp++)
				{
					if (Board[x+temp][y + temp] == "_")
					{
						if (numBot == 0)
						{
							d.Def[x + temp][y + temp] = d.Def[x + temp][y + temp] + pow(def_point, numPlayer);
						}
						if (numPlayer == 0)
						{
							d.Atk[x + temp][y + temp] = d.Atk[x + temp][y + temp] + pow(atk_point, numBot);
						}
					}
				}
			}
		}
	}
	return d;
}

Data setScoreDiagonalUp(int size, vector<vector<string>> Board, Data d) {
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
						d.Atk[x+temp][y - temp] = 0;
						d.Def[x+temp][y - temp] = 0;
					}
					if (Board[x + temp][y - temp] == "O")
					{
						numBot++;
						d.Atk[x+temp][y - temp] = 0;
						d.Def[x+temp][y - temp] = 0;
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
								d.Def[x + temp][y - temp] = d.Def[x + temp][y - temp] + pow(def_point, numPlayer);
							}
							if (numPlayer == 0)
							{
								d.Atk[x + temp][y - temp] = d.Atk[x + temp][y - temp] + pow(atk_point, numBot);
							}
						}
					}
				}
			}
		}
	}
	return d;
}


Data findMove(int size, vector<vector<string>> Board, Data d) {
	int max = 0;
	int x_max = 0;
	int y_max = 0;

	d = setScoreVertical(size, Board, d);
	d = setScoreHorizontal(size, Board, d);
	d = setScoreDiagonalDown(size, Board, d);
	d = setScoreDiagonalUp(size, Board, d);

	for  (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (d.Atk[x][y] + d.Def[x][y] > max && Board[x][y] == "_")
			{
				max = d.Atk[x][y] + d.Def[x][y];
				x_max = x;
				y_max = y;
			}
		}
	}
	//gotoXY(x_max*2, y_max);
	//cout << "0";
	//Board[x_max][y_max] = "0";
	//return Board;

	d.current_x_max = x_max;
	d.current_y_max = y_max;
	return d;
}
