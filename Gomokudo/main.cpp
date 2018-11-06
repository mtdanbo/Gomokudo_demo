#include "library.h"



int main() {

	//PlaySound("sound.wav",NULL, SND_FILENAME | SND_ASYNC);
	//intro();
	

	int quitGame = 0;

	while (quitGame == 0)	
	{
		system("cls");
		PlaySound("menu_sound.wav", NULL, SND_FILENAME | SND_ASYNC);
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
		}
	}
}