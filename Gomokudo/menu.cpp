#include "menu.h"

int menu() {
	Color color;
	getColor(color);


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
	string menuContent[] = { "Start game", "Load game","Option","About game", "Leaderboard", "Quit game","Rule demo" };
	int menuLength = sizeof(menuContent) / sizeof(menuContent[0]);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	for (int i = 0; i < menuLength; i++)
	{
		gotoXY(cursor_x, 15 + i);
		cout << menuContent[i];
	}

	gotoXY(cursor_x, cursor_y);
	while (true)
	{
		gotoXY(cursor_x, cursor_y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.hightLightColor);
		cout << menuContent[state];

	}

	return state;
}