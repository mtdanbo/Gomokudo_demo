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

	for (int k = 0; k < 50; k++)
	{
		for (int i = 10; i < 15; i++)
		{

			ifstream p1win;
			p1win.open("text/p1win.txt");
			gotoXY(0, size + 5);
			while (!p1win.eof())
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
				char ascii;
				p1win.get(ascii);
				cout << ascii;
			}

		}
	}
	gotoXY(0, size + 5);
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
void animateP2Win(int size) {

	for (int k = 0; k < 50; k++)
	{
		for (int i = 10; i < 15; i++)
		{

			ifstream p2win;
			p2win.open("text/p2win.txt");
			gotoXY(0, size + 5);
			while (!p2win.eof())
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
				char ascii;
				p2win.get(ascii);
				cout << ascii;
			}

		}
	}
	gotoXY(0, size + 5);
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

void animateBotWin(int size) {

	for (int k = 0; k < 50; k++)
	{
		for (int i = 10; i < 15; i++)
		{

			ifstream botwin;
			botwin.open("text/botwin.txt");
			gotoXY(0, size + 5);
			while (!botwin.eof())
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
				char ascii;
				botwin.get(ascii);
				cout << ascii;
			}

		}
	}
	gotoXY(0, size + 5);
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
