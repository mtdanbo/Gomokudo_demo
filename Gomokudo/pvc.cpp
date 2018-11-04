#include "pvc.h"

void gameMode(int maxDepth, int maxMove)
{
	system("cls");

	//Require the user choose the size of the board
	int size;
	cout << "Please choose the size of your board: ";
	cin >> size;

	//Set up two object player vs bot
	Object p;
	p.x = 0;
	p.y = 0;
	p.icon = "X";
	p.color = red;
	p.Score.resize(100, vector<int>(100, 0));

	Object b;
	b.x = 0;
	b.y = 0;
	b.icon = "O";
	b.color = green;
	b.Score.resize(100, vector<int>(100, 0));

	//Set up the board
	vector<string> temp{ 100,"_" };
	vector<vector<string>> Board{ 100,temp };

	// Draw board
	system("cls");
	Board = drawBoard(size, Board, temp, p, b);
	gotoXY((size + 5) * 2, 0);
	cout << "Press L to save your game";

	//Main game
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p.color);
		gotoXY(p.x, p.y);
		// Require the use control p1
		p = pControl_char(p, size, Board);
		Board[p.x / 2][p.y] = p.icon;
		// Compute p1 win or loose
		p.win = Compute(p, size, Board);

		if (p.win == 1)
		{
			animateP1Win(size);
			escape();
			break;
		}

		if (p.save == 1)
		{
			savePvC(Board, size, p, b, 2);
			break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), b.color);

		int depth = 0;
		int miniMax = 0;

		Point point;

		findMove(maxDepth, maxMove, depth, Board, p, b, size, miniMax, point);

		Board[point.x][point.y] = b.icon;

		b.win = Compute(b, size, Board);

		if (b.win == 1)
		{
			animateBotWin(size);
		}

	}
}

void PvC_mode() {
	ifstream pvc;
	pvc.open("text/pvc.txt");
	animateText(pvc);
	char key = _getch();
	while (key != '1' && key != '2' && key != '3')
	{
		key = _getch();
	}
	if (key == '1')
	{
		gameMode(maxDepthEasy, maxMoveEasy);
	}
	if (key == '2')
	{
		gameMode(maxDepthMed, maxMoveMed);
	}
	if (key == '3')
	{
		gameMode(maxDepthHard, maxMoveHard);
	}
}