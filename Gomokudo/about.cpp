#include "about.h"
void about() {

	ifstream about;
	about.open("about.txt");
	while (!about.eof())
	{
		char word;
		about.get(word);
		cout << word;
		Sleep(50);
	}

}