#include "load.h"
void loadPvP() {

	// Show saved file
	ifstream savelist;
	savelist.open("text/pvp_savelist.txt");
	animateText(savelist);

	// Require the user choose file
	cout << "What file do you want to load: ";
	string filename;
	cin >> filename;

	// Set figure
	ifstream figure;
	figure.open("save_pvp/" + filename + "figure.txt");
	int size;

	Object p1;
	Object p2;

	figure >> size;
	figure >> p1.icon;
	figure >> p1.color;
	figure >> p2.icon;
	figure >> p2.color;


	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> Board{ 100,temp };


	ifstream p1move;
	p1move.open("save_pvp/" + filename + "p1.txt");
	int p1_x;
	int p1_y;
	int p1_step = 0;
	int p2_step = 0;
	while (!p1move.eof())
	{
		p1move >> p1_x;
		p1move >> p1_y;
		Board[p1_x][p1_y] = p1.icon;
		p1_step++;
	}

	p1move.close();

	ifstream p2move;
	p2move.open("save_pvp/" + filename + "p2.txt");
	int p2_x;
	int p2_y;
	while (!p2move.eof())
	{
		p2move >> p2_x;
		p2move >> p2_y;
		Board[p2_x][p2_y] = p2.icon;
		p2_step++;
	}

	p2move.close();

	Board = drawBoard(size, Board, temp, p1, p2);

	gotoXY((size + 5) * 2, 0);
	cout << "Press L if you want to save the game";

	//Continue the game

	p1.x = 0;
	p1.y = 0;
	p2.x = 0;
	p2.y = 0;

	//Define P1 or P2 go after saving

	if(p1_step == p2_step)
	{
		// Gameplay
		while (1)
		{
			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
			gotoXY(p1.x, p1.y);
			// Require the use control p1
			p1 = pControl_char(p1, size, Board);
			Board[p1.x / 2][p1.y] = p1.icon;
			// Compute p1 win or loose
			p1.win = Compute(p1, size, Board);

			if (p1.win == 1)
			{
				animateP1Win(size);
				escape();
				break;
			}

			if (p1.save == 1 || p2.save == 1)
			{
				savePvP(Board, size, p1, p2);
				break;
			}

			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
			gotoXY(p2.x, p2.y);
			// Require the use control p2
			p2 = pControl_num(p2, size, Board);
			Board[p2.x / 2][p2.y] = p2.icon;
			// Compute p2 win or loose
			p2.win = Compute(p2, size, Board);

			if (p2.win == 1)
			{
				animateP2Win(size);
				escape();
				break;
			}


			if (p1.save == 1 || p2.save == 1)
			{
				savePvP(Board, size, p1, p2);
				break;
			}
		}
	}


	if (p1_step > p2_step)
	{
		// Gameplay
		while (1)
		{
			//P2 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2.color);
			gotoXY(p2.x, p2.y);
			// Require the use control p2
			p2 = pControl_num(p2, size, Board);
			Board[p2.x / 2][p2.y] = p2.icon;
			// Compute p2 win or loose
			p2.win = Compute(p2, size, Board);

			if (p2.win == 1)
			{
				animateP2Win(size);
				escape();
				break;
			}


			if (p1.save == 1 || p2.save == 1)
			{
				savePvP(Board, size, p1, p2);
				break;
			}

			// P1 Zone
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1.color);
			gotoXY(p1.x, p1.y);
			// Require the use control p1
			p1 = pControl_char(p1, size, Board);
			Board[p1.x / 2][p1.y] = p1.icon;
			// Compute p1 win or loose
			p1.win = Compute(p1, size, Board);

			if (p1.win == 1)
			{
				animateP1Win(size);
				escape();
				break;
			}

			if (p1.save == 1 || p2.save == 1)
			{
				savePvP(Board, size, p1, p2);
				break;
			}

		}
	}


}


void loadPvC() {

	// Show saved file
	ifstream savelist;
	savelist.open("text/pvc_savelist.txt");
	animateText(savelist);

	// Require the user choose file
	cout << "What file do you want to load: ";
	string filename;
	cin >> filename;

	// Set figure
	ifstream figure;
	figure.open("save_pvc/" + filename + "figure.txt");
	int size;
	int mode;

	Object p;
	Object b;

	figure >> size;
	figure >> p.icon;
	figure >> p.color;
	figure >> b.icon;
	figure >> b.color;
	figure >> mode;

	//Set property of the board

	system("cls");
	vector<string> temp = { 100,"_" };
	vector<vector<string>> Board{ 100,temp };


	ifstream pmove;
	pmove.open("save_pvc/" + filename + "p.txt");
	int p_x;
	int p_y;

	while (!pmove.eof())
	{
		pmove >> p_x;
		pmove >> p_y;
		Board[p_x][p_y] = p.icon;
	}

	pmove.close();

	ifstream bmove;
	bmove.open("save_pvc/" + filename + "b.txt");
	int b_x;
	int b_y;
	while (!bmove.eof())
	{
		bmove >> b_x;
		bmove >> b_y;
		Board[b_x][b_y] = b.icon;
	}

	bmove.close();

	Board = drawBoard(size, Board, temp, p, b);
	gotoXY((size + 5) * 2, 0);
	cout << "Press L if you want to save the game";

	if (mode == 1)
	{
		p.x = 0;
		p.y = 0;
		b.x = 0;
		b.y = 0;

		while (1)
		{
			p.x = p.x * 2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p.color);
			gotoXY(p.x, p.y);
			// Require the use control p1
			p = pControl_char(p, size, Board);
			Board[p.x / 2][p.y] = p.icon;
			// Compute p1 win or loose
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

	if (mode == 2)
	{
		p.x = 0;
		p.y = 0;

		b.x = 0;
		b.y = 0;

		Data d;
		d.Atk.resize(100, vector<int>(100, 0));
		d.Def.resize(100, vector<int>(100, 0));
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

}

void load() {
	ifstream loadmode;
	loadmode.open("text/loadmode.txt");
	animateText(loadmode);
	char key = _getch();


	while (key != '1' && key != '2')
	{
		key = _getch();
	}

	if (key == '1')
	{
		system("cls");
		loadPvP();
	}
	if (key == '2')
	{
		system("cls");
		loadPvC();
	}
}
