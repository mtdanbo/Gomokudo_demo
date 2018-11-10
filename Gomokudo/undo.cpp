#include "undo.h"

void undop1(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first) {
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	if (player2.historyMove.size() > 0)
	{
		player1.turn = 0;
		player2.turn = 1;

		board[player2.historyMove[player2.historyMove.size() - 1].first][player2.historyMove[player2.historyMove.size() - 1].second] = "_";

		player2.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;


		system("cls");
		
		board = drawBoard(size, board, player1, player2,pvpConfig.boardColor);

	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undop2(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first) {
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	if (player1.historyMove.size() > 0)
	{
		player1.turn = 1;
		player2.turn = 0;

		board[player1.historyMove[player1.historyMove.size() - 1].first][player1.historyMove[player1.historyMove.size() - 1].second] = "_";

		player1.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;

		system("cls");
		board = drawBoard(size, board, player1, player2,pvpConfig.boardColor);
	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undop1Rule1(Object &player1, Object &player2, Object &obstacle, vector<vector<string>> &board, int size, int &go_first, int numRock) {
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	if (player2.historyMove.size() > 0)
	{
		player1.turn = 0;
		player2.turn = 1;

		board[player2.historyMove[player2.historyMove.size() - 1].first][player2.historyMove[player2.historyMove.size() - 1].second] = "_";

		player2.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;


		system("cls");

		board = drawBoardRule1(size, board, player1, player2,obstacle, pvpConfig.boardColor,numRock);

	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undop2Rule1(Object &player1, Object &player2, Object &obstacle, vector<vector<string>> &board, int size, int &go_first, int numRock) {
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	if (player1.historyMove.size() > 0)
	{
		player1.turn = 1;
		player2.turn = 0;

		board[player1.historyMove[player1.historyMove.size() - 1].first][player1.historyMove[player1.historyMove.size() - 1].second] = "_";

		player1.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;

		system("cls");
		board = drawBoardRule1(size, board, player1, player2, obstacle, pvpConfig.boardColor, numRock);
	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undop1Rule2(Object &player1, Object &player2, Object &obstacle, vector<vector<string>> &board, int size, int &go_first) {
	PvPConfig pvpConfig;
	getPvPConfig(pvpConfig);

	if (player2.historyMove.size() > 0)
	{
		player1.turn = 0;
		player2.turn = 1;

		board[player2.historyMove[player2.historyMove.size() - 1].first][player2.historyMove[player2.historyMove.size() - 1].second] = "_";

		player2.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;


		system("cls");

		board = drawBoardRule2(size, board, player1, player2, obstacle, pvpConfig.boardColor);

	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undop2Rule2(Object &player1, Object &player2, Object &obstacle, vector<vector<string>> &board, int size, int &go_first) {
	PvPConfig pvpConfig;

	getPvPConfig(pvpConfig);

	if (player1.historyMove.size() > 0)
	{
		player1.turn = 1;
		player2.turn = 0;

		board[player1.historyMove[player1.historyMove.size() - 1].first][player1.historyMove[player1.historyMove.size() - 1].second] = "_";

		player1.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;

		system("cls");
		board = drawBoardRule2(size, board, player1, player2, obstacle, pvpConfig.boardColor);
	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undop1Rule5(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentBoom) {
	if (player1.historyMove.size() != 0 && player2.historyMove.size() != 0)
	{
		player1.turn = 0;
		player2.turn = 1;

		board[player2.historyMove[player2.historyMove.size() - 1].first][player2.historyMove[player2.historyMove.size() - 1].second] = "_";

		player2.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;


		system("cls");

		board = drawBoardRule5(size, board, player1, player2,currentBoom);

	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undop2Rule5(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentBoom) {
	if (player1.historyMove.size() != 0 && player1.historyMove.size() != 0)
	{
		player1.turn = 1;
		player2.turn = 0;

		board[player1.historyMove[player1.historyMove.size() - 1].first][player1.historyMove[player1.historyMove.size() - 1].second] = "_";

		player1.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;

		system("cls");
		board = drawBoardRule5(size, board, player1, player2,currentBoom);
	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undop1Rule8(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentChangedItem) {
	if (player1.historyMove.size() != 0 && player2.historyMove.size() != 0)
	{
		player1.turn = 0;
		player2.turn = 1;

		board[player2.historyMove[player2.historyMove.size() - 1].first][player2.historyMove[player2.historyMove.size() - 1].second] = "_";

		player2.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;


		system("cls");

		board = drawBoardRule8(size, board, player1, player2, currentChangedItem);

	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undop2Rule8(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentChangedItem) {
	if (player1.historyMove.size() != 0 && player1.historyMove.size() != 0)
	{
		player1.turn = 1;
		player2.turn = 0;

		board[player1.historyMove[player1.historyMove.size() - 1].first][player1.historyMove[player1.historyMove.size() - 1].second] = "_";

		player1.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;

		system("cls");
		board = drawBoardRule8(size, board, player1, player2, currentChangedItem);
	}
	else
	{
		if (go_first == 1)
		{
			player1.turn = 1;
			player2.turn = 0;
		}
		if (go_first == 2)
		{
			player1.turn = 0;
			player2.turn = 1;
		}

		player1.undo = 0;
		player2.undo = 0;

	}
}

void undoPvC(Object &player,Object &bot, vector<vector<string>> &board,int size)
{
	PvCConfig pvcConfig;
	getPvCConfig(pvcConfig);

	if (player.historyMove.size() > 0 && bot.historyMove.size() > 0)
	{
		board[player.historyMove[player.historyMove.size() - 1].first][player.historyMove[player.historyMove.size() - 1].second] = "_";
		player.historyMove.pop_back();

		board[bot.historyMove[bot.historyMove.size() - 1].first][bot.historyMove[bot.historyMove.size() - 1].second] = "_";
		bot.historyMove.pop_back();

		drawBoard(size, board, player, bot,pvcConfig.boardColor);

		player.undo = 0;

		player.turn = 1;
		bot.turn = 0;

	}

	if (player.historyMove.size() == 0 && bot.historyMove.size() == 0)
	{
		player.undo = 0;
		player.turn = 1;
		bot.turn = 0;
	}
}