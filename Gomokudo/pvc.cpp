#include "pvc.h"

void easy_mode() {
	system("cls");
	vector<string> temp{ 100,"_" };
	vector<vector<string>> Board{ 100,temp };

	Object p;
	p.x = 0;
	p.y = 0;
	p.icon = "X";
	p.color = red;
	Object b;
	b.x = 0;
	b.y = 0;
	b.icon = "0";
	b.color = green;

	int size;
	cout << "Plz choose your board size: ";
	cin >> size;

	system("cls");
	Board = drawBoard(size, Board, temp, p, b);
	gotoXY((size + 5) * 2, 0);
	cout << "Press L to save your game";


	while (1)
	{
		p.x = p.x * 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p.color);
		gotoXY(p.x, p.y);
		// Require the use control p1
		p = pControl_char(p, size, Board);
		Board[p.x / 2][p.y] = p.icon;
		// Compute p1 win or lose
		p.win = Compute(p, size, Board);

		p.x = p.x / 2;
		if (p.win == 1)
		{
			animateP1Win(size);
			escape();
			break;
		}

		if (p.save == 1)
		{
			savePvC(Board, size, p, b, 1);
			break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green);
		while (1)
		{
			int random = rand() % 8 + 1;
			switch (random)
			{
			case 1:
				b.x = p.x - 1;
				b.y = p.y - 1;
				break;
			case 2:
				b.y = p.y - 1;
				b.x = p.x;
				break;
			case 3:
				b.x = p.x + 1;
				b.y = p.y - 1;
				break;
			case 4:
				b.x = p.x + 1;
				b.y = p.y;
				break;
			case 5:
				b.x = p.x + 1;
				b.y = p.y + 1;
				break;
			case 6:
				b.y = p.y + 1;
				b.x = p.x;
				break;
			case 7:
				b.x = p.x - 1;
				b.y = p.y + 1;
				break;
			case 8:
				b.x = p.x - 1;
				b.y = p.y;
				break;
			}
			if (Board[b.x][b.y] == "_" && b.x <= size - 1 && b.y <= size - 1)
			{
				gotoXY(b.x * 2, b.y);
				cout << b.icon;
				Board[b.x][b.y] = b.icon;
				break;
			}
		}

		b.win = Compute(b, size, Board);

		if (b.win == 1)
		{
			animateBotWin(size);
			escape();
			break;
		}

	}
}


void normal_mode()
{
	system("cls");


	int size;
	cout << "Please choose the size of your board: ";
	cin >> size;

	vector<string> temp{ 100,"_" };
	vector<vector<string>> Board{ 100,temp };

	Object p;
	p.x = 0;
	p.y = 0;
	p.icon = "X";
	p.color = red;

	Object b;
	b.x = 0;
	b.y = 0;
	b.icon = "O";
	b.color = green;

	system("cls");
	Board = drawBoard(size, Board, temp, p, b);

	Data d;
	d.Atk.resize(100, vector<int>(100, 0));
	d.Def.resize(100, vector<int>(100, 0));

	gotoXY((size + 5) * 2, 0);
	cout << "Press L to save your game";

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
		d = findMove(size, Board, d);
		b.x = d.current_x_max * 2;
		b.y = d.current_y_max;




		gotoXY(b.x, b.y);
		cout << b.icon;
		Board[d.current_x_max][d.current_y_max] = b.icon;

		b.win = Compute(b, size, Board);

		if (b.win == 1)
		{
			animateBotWin(size);
			escape();
			break;
		}




	}
}


void hard_mode()
{
	system("cls");


	int size;
	cout << "Please choose the size of your board: ";
	cin >> size;

	vector<string> temp{ 100,"_" };
	vector<vector<string>> Board{ 100,temp };

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

	system("cls");
	Board = drawBoard(size, Board, temp, p, b);

	gotoXY((size + 5) * 2, 0);
	cout << "Press L to save your game";

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

		point = findMoveHard(depth, Board, p, b, size, miniMax,point);

		Board[point.x][point.y] = b.icon;

		b.win = Compute(b, size, Board);

		if (b.win == 1)
		{
			animateBotWin(size);
		}


	}



}

void PvC_mode() {
	//ifstream pvc;
	//pvc.open("text/pvc.txt");
	//animateText(pvc);
	//char key = _getch();
	//while (key != '1' && key != '2' && key != '3')
	//{
	//	key = _getch();
	//}
	//if (key == '1')
	//{
	//	easy_mode();
	//}
	//if (key == '2')
	//{
	//	normal_mode();
	//}

	hard_mode();
}