#include "about.h"
void about() {

	Color color;
	getColor(color);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	ifstream about;
	about.open("text/about.txt");
	while (!about.eof())
	{
		char word;
		about.get(word);
		cout << word;
		Sleep(50);
	}

}