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

void setCursorSize(int size)
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = size;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
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

void getMainKey(PlayerKey &mainPlayer)
{
	ifstream loadMainKey;
	loadMainKey.open("text/mainplayer_key.txt");
	while (!loadMainKey.eof())
	{
		string temp;
		loadMainKey >> temp;
		if (temp == "up:")
		{
			loadMainKey >> mainPlayer.up;
		}
		if (temp == "down:")
		{
			loadMainKey >> mainPlayer.down;
		}
		if (temp == "left:")
		{
			loadMainKey >> mainPlayer.left;
		}
		if (temp == "right:")
		{
			loadMainKey >> mainPlayer.right;
		}
		if (temp == "fight:")
		{
			loadMainKey >> mainPlayer.attack;
		}
	}
	loadMainKey.close();

}

void getSecondKey(PlayerKey &secondPlayer)
{
	ifstream loadSecondKey;
	loadSecondKey.open("text/secondplayer_key.txt");
	while (!loadSecondKey.eof())
	{
		string temp;
		loadSecondKey >> temp;
		if (temp == "up:")
		{
			loadSecondKey >> secondPlayer.up;
		}
		if (temp == "down:")
		{
			loadSecondKey >> secondPlayer.down;
		}
		if (temp == "left:")
		{
			loadSecondKey >> secondPlayer.left;
		}
		if (temp == "right:")
		{
			loadSecondKey >> secondPlayer.right;
		}
		if (temp == "fight:")
		{
			loadSecondKey >> secondPlayer.attack;
		}
	}
	loadSecondKey.close();
}

void getControlKey(ControlGame &controlGame)
{
	ifstream loadControlKey;
	loadControlKey.open("text/control_key.txt");
	while (!loadControlKey.eof())
	{
		string temp;
		loadControlKey >> temp;

		if (temp == "back:")
		{
			loadControlKey >> controlGame.back;
		}
		if (temp == "undo:")
		{
			loadControlKey >> controlGame.undo;
		}
		if (temp == "save:")
		{
			loadControlKey >> controlGame.save;
		}

	}
	loadControlKey.close();
}

void getKey(PlayerKey &mainPlayer, PlayerKey &secondPlayer, ControlGame &controlGame)
{
	getControlKey(controlGame);
	getMainKey(mainPlayer);
	getSecondKey(secondPlayer);
}

