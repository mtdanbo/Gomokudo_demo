#include "library.h"



int main() {
	ConsoleConfig config;
	getConfig(config);

	if (config.introMusic == 1)
	{
		PlaySound("sound.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	else
	{
		PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	}
	
	intro();
	COORD size;
	size.X = 114;
	size.Y = 1174;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);

	setCursorSize(smallCursor);



	int quitGame = 0;

	while (quitGame == 0)	
	{
		
		getConfig(config);

		system("cls");
		if (config.bgMusic == 1)
		{
			
			PlaySound("menu_sound.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		else
		{
			PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
		}
		int state = menu();
		system("cls");
		PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
		switch (state)
		{
		case 0:
			start();
			break;
		case 1:
			load();
			break;
		case 2:
			option();
			break;
		case 3:
			about();
			escape();
			break;
		case 4:
			leaderboard();
			break;
		case 5:
			quitGame = 1;
			break;
		case 6:
			rule8();
		}

	}
}