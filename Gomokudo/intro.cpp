#include "intro.h"

void intro() {
	Sleep(2000);
	ConsoleConfig config;
	getConfig(config);
	if (config.introAnimate == 1)
	{
		ifstream initial;
		initial.open("text/intro.txt");
		while (!initial.eof())
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
			char ascii;
			initial.get(ascii);
			cout << ascii;
			Sleep(5);
		}
		for (int k = 0; k < 30; k++)
		{
			for (int i = 10; i < 15; i++)
			{
				gotoXY(0, 0);
				ifstream animation;
				animation.open("text/intro.txt");
				while (!animation.eof())
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
					char ascii;
					animation.get(ascii);
					cout << ascii;
				}

			}
		}
		gotoXY(0, 15);
		ifstream author;
		author.open("text/author.txt");
		while (!author.eof())
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
			char ascii;
			author.get(ascii);
			cout << ascii;
			Sleep(5);
		}

		gotoXY(80 / 2, 25);
		system("pause");
	}
	else
	{
		ifstream initial;
		initial.open("text/intro.txt");
		while (!initial.eof())
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
			char ascii;
			initial.get(ascii);
			cout << ascii;
		}
		gotoXY(0, 15);
		ifstream author;
		author.open("text/author.txt");
		while (!author.eof())
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), yellow);
			char ascii;
			author.get(ascii);
			cout << ascii;
			Sleep(5);
		}

		gotoXY(80 / 2, 25);
		system("pause");
	}



}