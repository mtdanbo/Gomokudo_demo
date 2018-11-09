#include "start.h"

void start() {

	int width = getConsoleWidth();
	int height = getConsoleHeight();

	gotoXY(width / 2 - 15, height / 2 - 1);

	//ifstream start_intro;
	//start_intro.open("text/start.txt", ios_base::app);

	//animateText(start_intro);

	vector<string> type = { "Player vs Player", "Player vs Computer" , "Back" };

	while (1)
	{
		int choice = controlMenuByArrow(type);

		if (choice == 0)
		{
			PvP_mode();
		}
		if (choice == 1)
		{
			PvC_mode();
		}
		if (choice == 2)
		{
			break;
		}
	}

}