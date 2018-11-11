#include "console.h"
void escape() {
	char key = _getch();
	while (key != 27)
	{
		key = _getch();
	}
}
void animateText(ifstream& text) {
	while (!text.eof())
	{
		char word;
		text.get(word);
		cout << word;
		Sleep(50);
	}


}

void animateP1Win(int size) {

	ConsoleConfig config;
	getConfig(config);

	if (config.winAnimate == 1)
	{
		for (int k = 0; k < 50; k++)
		{
			for (int i = 10; i < 15; i++)
			{

				ifstream p1win;
				p1win.open("text/p1win.txt");
				gotoXY(0, size * 2 + 2);
				while (!p1win.eof())
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
					char ascii;
					p1win.get(ascii);
					cout << ascii;
				}

			}
		}
		gotoXY(0, size * 2 + 2);
		ifstream p1win;
		p1win.open("text/p1win.txt");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
		while (!p1win.eof())
		{
			char word;
			p1win.get(word);
			cout << word;
		}
	}
	else
	{
		gotoXY(0, size * 2 + 2);
		ifstream p1win;
		p1win.open("text/p1win.txt");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
		while (!p1win.eof())
		{
			char word;
			p1win.get(word);
			cout << word;
		}
	}


}
void animateP2Win(int size) {

	ConsoleConfig config;
	getConfig(config);

	if (config.winAnimate == 1)
	{
		for (int k = 0; k < 50; k++)
		{
			for (int i = 10; i < 15; i++)
			{

				ifstream p2win;
				p2win.open("text/p2win.txt");
				gotoXY(0, size * 2 + 2);
				while (!p2win.eof())
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
					char ascii;
					p2win.get(ascii);
					cout << ascii;
				}

			}
		}
		gotoXY(0, size * 2 + 2);
		ifstream p2win;
		p2win.open("text/p2win.txt");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green);
		while (!p2win.eof())
		{
			char word;
			p2win.get(word);
			cout << word;
		}
	}
	else
	{
		gotoXY(0, size * 2 + 2);
		ifstream p2win;
		p2win.open("text/p2win.txt");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green);
		while (!p2win.eof())
		{
			char word;
			p2win.get(word);
			cout << word;
		}
	}



}

void animateBotWin(int size) {

	ConsoleConfig config;
	getConfig(config);

	if (config.winAnimate == 1)
	{
		for (int k = 0; k < 50; k++)
		{
			for (int i = 10; i < 15; i++)
			{

				ifstream botwin;
				botwin.open("text/botwin.txt");
				gotoXY(0, size * 2 + 2);
				while (!botwin.eof())
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
					char ascii;
					botwin.get(ascii);
					cout << ascii;
				}

			}
		}
		gotoXY(0, size * 2 + 2);
		ifstream botwin;
		botwin.open("text/botwin.txt");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green);
		while (!botwin.eof())
		{
			char word;
			botwin.get(word);
			cout << word;
		}
	}
	else
	{
		gotoXY(0, size * 2 + 2);
		ifstream botwin;
		botwin.open("text/botwin.txt");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green);
		while (!botwin.eof())
		{
			char word;
			botwin.get(word);
			cout << word;
		}
	}



}

void animateDraw(int size) {

	ConsoleConfig config;
	getConfig(config);

	if (config.winAnimate == 1)
	{
		for (int k = 0; k < 50; k++)
		{
			for (int i = 10; i < 15; i++)
			{

				ifstream p1win;
				p1win.open("text/draw.txt");
				gotoXY(0, size * 2 + 2);
				while (!p1win.eof())
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
					char ascii;
					p1win.get(ascii);
					cout << ascii;
				}

			}
		}
		gotoXY(0, size * 2 + 2);
		ifstream p1win;
		p1win.open("text/draw.txt");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
		while (!p1win.eof())
		{
			char word;
			p1win.get(word);
			cout << word;
		}
	}
	else
	{
		gotoXY(0, size * 2 + 2);
		ifstream p1win;
		p1win.open("text/draw.txt");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), red);
		while (!p1win.eof())
		{
			char word;
			p1win.get(word);
			cout << word;
		}
	}



}

int controlMenuByArrow(vector<string> data)
{
	system("cls");
	Color color;
	getColor(color);

	int width = getConsoleWidth();
	int height = getConsoleHeight();

	gotoXY(width / 2, height / 2);

	int currentX = width / 2;
	int currentY = height / 2;
	int currentIndex = 0;

	
	while (1)
	{
		char key = _getch();

		if (key == 80)
		{

			if (currentIndex == data.size() - 1)
			{
				currentY = currentY;
				currentIndex = currentIndex;
			}
			else
			{
				currentY++;
				currentIndex++;
			}


		}

		if (key == 72)
		{
			if (currentIndex == 0)
			{
				currentY = currentY;
				currentIndex = currentIndex;
			}
			else
			{
				currentY--;
				currentIndex--;
			}
		}

		if (key == 13)
		{
			return currentIndex;
		}



		for (int i = 0; i < data.size(); i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
			gotoXY(width / 2, height / 2 + i);
			cout << data[i];
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.hightLightColor);
		gotoXY(currentX, currentY);
		cout << data[currentIndex];
		
	}




}
