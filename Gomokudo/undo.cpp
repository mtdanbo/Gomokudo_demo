#include "undo.h"

void undop1(Object &p1, Object &p2, vector<pair<int,int>> &p1undo, vector<pair<int,int>> &p2undo, vector<vector<string>> &Board, int size, vector<string> &temp, int &go_first) {
	if (p1undo.size() != 0 || p2undo.size() != 0)
	{
		p1.turn = 0;
		p2.turn = 1;

		Board[p2undo[p2undo.size() - 1].first][p2undo[p2undo.size() - 1].second] = "_";

		p2undo.pop_back();

		p1.undo = 0;
		p2.undo = 0;


		system("cls");
		Board = drawBoard(size, Board, temp, p1, p2);

		gotoXY((size + 5) * 2, 0);
		cout << "Press L if you want to save the game";
		gotoXY((size + 5) * 2, 1);
		cout << "Press U if you want to undo the game";
	}
	else
	{
		if (go_first == 1)
		{
			p1.turn = 1;
			p2.turn = 0;
		}
		if (go_first == 2)
		{
			p1.turn = 0;
			p2.turn = 1;
		}

		p1.undo = 0;
		p2.undo = 0;

	}
}

void undop2(Object &p1, Object &p2, vector<pair<int, int>> &p1undo, vector<pair<int, int>> &p2undo, vector<vector<string>> &Board, int size, vector<string> &temp, int &go_first) {
	if (p1undo.size() != 0 || p2undo.size() != 0)
	{
		p1.turn = 1;
		p2.turn = 0;

		Board[p1undo[p1undo.size() - 1].first][p1undo[p1undo.size() - 1].second] = "_";

		p1undo.pop_back();

		p1.undo = 0;
		p2.undo = 0;

		system("cls");
		Board = drawBoard(size, Board, temp, p1, p2);

		gotoXY((size + 5) * 2, 0);
		cout << "Press L if you want to save the game";
		gotoXY((size + 5) * 2, 1);
		cout << "Press U if you want to undo the game";
	}
	else
	{
		if (go_first == 1)
		{
			p1.turn = 1;
			p2.turn = 0;
		}
		if (go_first == 2)
		{
			p1.turn = 0;
			p2.turn = 1;
		}

		p1.undo = 0;
		p2.undo = 0;

	}
}