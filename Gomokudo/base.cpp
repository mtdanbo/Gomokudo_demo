#include "base.h"

void gotoXY(int x_pos, int y_pos) {
	COORD coord;
	coord.X = x_pos;
	coord.Y = y_pos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	int columns;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	return columns;
}

int getConsoleHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	int rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return rows;
}

void getColor(Color &color)
{
	ifstream loadSetting;
	loadSetting.open("text/console_setting.txt", ios_base::app);

	while (!loadSetting.eof())
	{
		string temp;
		loadSetting >> temp;

		if (temp == "textColor:")
		{
			loadSetting >> color.textColor;
		}
		if (temp == "highlightedColor:")
		{
			loadSetting >> color.hightLightColor;
		}
		if (temp == "activeColor:")
		{
			loadSetting >> color.activeColor;
		}
	}

}

