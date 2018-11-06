#include "undo.h"

void undop1(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first) {
	if (player1.historyMove.size() != 0 || player2.historyMove.size() != 0)
	{
		player1.turn = 0;
		player2.turn = 1;

		board[player2.historyMove[player2.historyMove.size() - 1].first][player2.historyMove[player2.historyMove.size() - 1].second] = "_";

		player2.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;


		system("cls");
		board = drawBoard(size, board, player1, player2);
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
	if (player1.historyMove.size() != 0 || player1.historyMove.size() != 0)
	{
		player1.turn = 1;
		player2.turn = 0;

		board[player1.historyMove[player1.historyMove.size() - 1].first][player1.historyMove[player1.historyMove.size() - 1].second] = "_";

		player1.historyMove.pop_back();

		player1.undo = 0;
		player2.undo = 0;

		system("cls");
		board = drawBoard(size, board, player1, player2);
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
	if (player.historyMove.size() > 0 && bot.historyMove.size() > 0)
	{
		board[player.historyMove[player.historyMove.size() - 1].first][player.historyMove[player.historyMove.size() - 1].second] = "_";
		player.historyMove.pop_back();

		board[bot.historyMove[bot.historyMove.size() - 1].first][bot.historyMove[bot.historyMove.size() - 1].second] = "_";
		bot.historyMove.pop_back();

		drawBoard(size, board, player, bot);

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