#include "menu.h"

int menu() {
	Sleep(1500);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
	ifstream menu;
	menu.open("text/intro.txt");
	while (!menu.eof())
	{
		char ascii;
		menu.get(ascii);
		cout << ascii;
		Sleep(3);
	}
	int state = 0;
	int cursor_x = 80 / 2 + 10;
	int cursor_y = 15;
	string menuContent[] = { "Start game", "Load game","About game", "Leaderboard", "Quit game" };
	int menuLength = sizeof(menuContent) / sizeof(menuContent[0]);
	for (int i = 0; i < menuLength; i++)
	{
		gotoXY(cursor_x, 15 + i);
		cout << menuContent[i];
	}

	gotoXY(cursor_x, cursor_y);
	while (true)
	{
		gotoXY(cursor_x, cursor_y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
		char key = _getch();
		if (key == 72)
		{
			if (state == 0)
			{
				state = state;
			}
			else
			{
				cursor_y -= 1;
				state = state - 1;
			}
		}
		if (key == 80)
		{
			if (state == menuLength - 1)
			{
				state = state;
			}
			else
			{
				cursor_y += 1;
				state = state + 1;
			}
			
		}
		if (key == 13)
		{
			break;
		}
		for (int i = 0; i < menuLength; i++)
		{
			gotoXY(cursor_x, 15 + i);
			cout << menuContent[i];
		}
		gotoXY(cursor_x, cursor_y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
		cout << menuContent[state];

	}

	return state;
}