#include "option.h"

OnState introMusic;
OnState bgMusic;
OnState introAnimate;
OnState winAnimate;

ColorState curTextColor;
ColorState curHightlightColor;
ColorState curActiveColor;

ColorState nextTextColor;
ColorState nextHighlightColor;
ColorState nextActiveColor;

void drawOnState(int width, int height, int currentIndex, vector<pair<string,string>> configuration, OnState onState)
{
	gotoXY(width / 4 + 40, height / 4 + currentIndex * 2);

	string onString = configuration[currentIndex].second.substr(0, 2);
	if (onState.on == true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
	}
	cout << onString;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
	cout << "/";

	string offString = configuration[currentIndex].second.substr(3, 3);
	if (onState.on == false)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
	}
	cout << offString;
}

void drawColorState(int width, int height, int currentIndex, vector<pair<string, string>> configuration, ColorState currentColor, ColorState &nextColor)
{
	gotoXY(width / 4 + 40, height / 4 + currentIndex * 2);
	string redState = configuration[currentIndex].second.substr(0, 3);
	if (nextColor.color == red)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
	}
	cout << redState;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
	cout << "/";

	string yellowState = configuration[currentIndex].second.substr(4, 6);
	if (nextColor.color == yellow)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
	}
	cout << yellowState;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
	cout << "/";

	string greenState = configuration[currentIndex].second.substr(11, 5);
	if (nextColor.color == green)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
	}
	cout << greenState;
}

void drawConsoleSetting(int width, int height, vector<pair<string,string>> configuration)
{

	for (int i = 0; i < configuration.size(); i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
		gotoXY(width / 4, height / 4 + i * 2);
		cout << configuration[i].first;

		if (i == 0)
		{
			drawOnState(width, height, i, configuration, introMusic);
		}
		if (i == 1)
		{
			drawOnState(width, height, i, configuration, bgMusic);
		}
		if (i == 2)
		{
			drawOnState(width, height, i, configuration, introAnimate);
		}
		if (i == 3)
		{
			drawOnState(width, height, i, configuration, winAnimate);
		}
		if (i == 4)
		{
			drawColorState(width, height, i, configuration, curTextColor,nextTextColor);
		}
		if (i == 5)
		{
			drawColorState(width, height, i, configuration, curHightlightColor,nextHighlightColor);
		}
		if (i == 6)
		{
			drawColorState(width, height, i, configuration, curActiveColor,nextActiveColor);
		}
	}
}

void modifyConsoleOn(int width, int height, int currentIndex, vector<pair<string,string>> configuration, OnState &onState)
{
	while (1)
	{
		char key = _getch();

		if (key == 77)
		{
			gotoXY(width / 4 + 40, height / 4 + currentIndex * 2);

			string onString = configuration[currentIndex].second.substr(0, 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
			cout << onString;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
			cout << "/";

			string offString = configuration[currentIndex].second.substr(3, 3);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
			cout << offString;

			onState.on = false;

			gotoXY(width / 4 + 40 + 3, height / 4 + currentIndex * 2);
		}

		if (key == 75)
		{
			gotoXY(width / 4 + 40, height / 4 + currentIndex * 2);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
			string onString = configuration[currentIndex].second.substr(0, 2);
			cout << onString;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
			cout << "/";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
			string offString = configuration[currentIndex].second.substr(3, 3);
			cout << offString;

			onState.on = true;

			gotoXY(width / 4 + 40, height / 4 + currentIndex * 2);

		}
		if (key == 'B' || key == 'b')
		{
			break;
		}
	}

	gotoXY(width / 4, height / 4 + currentIndex * 2);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
	cout << configuration[currentIndex].first;
}

void modifyConsoleColor(int width, int height,int currentIndex, vector<pair<string,string>> configuration, ColorState currentColor, ColorState &nextColor)
{
	int colorIndex;

	if (currentColor.color == yellow)
	{
		colorIndex = 0;
	}
	if (currentColor.color == red)
	{
		colorIndex = -1;
	}
	if (currentColor.color == green)
	{
		colorIndex = 1;
	}


	while (1)
	{
		char key = _getch();

		if (key == 75)
		{
			if (colorIndex == -1)
			{
				colorIndex = colorIndex;
			}
			else
			{
				colorIndex--;
			}
		}

		if (key == 77)
		{
			if (colorIndex == 1)
			{
				colorIndex = colorIndex;
			}
			else
			{
				colorIndex++;
			}
		}

		if (key == 'B' || key == 'b')
		{
			if (colorIndex == 1)
			{
				nextColor.color = green;
			}
			if (colorIndex == -1)
			{
				nextColor.color = red;
			}
			if (colorIndex == 0)
			{
				nextColor.color = yellow;
			}

			break;
		}

		string redState = configuration[currentIndex].second.substr(0, 3);
		string yellowState = configuration[currentIndex].second.substr(4, 6);
		string greenState = configuration[currentIndex].second.substr(11, 5);

		if (colorIndex == 1)
		{
			gotoXY(width / 4 + 40, height / 4 + currentIndex*2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
			cout << redState << "/" << yellowState << "/" << greenState;
			
			gotoXY(width / 4 + 40 + 11, height / 4 + currentIndex * 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
			cout << greenState;
			gotoXY(width / 4 + 40 + 11, height / 4 + currentIndex * 2);

		}
		if (colorIndex == -1)
		{
			gotoXY(width / 4 + 40, height / 4 + currentIndex*2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
			cout << redState << "/" << yellowState << "/" << greenState;

			gotoXY(width / 4 + 40, height / 4 + currentIndex * 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
			cout << redState;
			gotoXY(width / 4 + 40, height / 4 + currentIndex * 2);

		}
		if (colorIndex == 0)
		{
			gotoXY(width / 4 + 40, height / 4 + currentIndex*2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
			cout << redState << "/" << yellowState << "/" << greenState;

			gotoXY(width / 4 + 40 + 4, height / 4 + currentIndex * 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
			cout << yellowState;
			gotoXY(width / 4 + 40 + 4, height / 4 + currentIndex * 2);
		}
	}
}

void modifyConsoleSetting(int width, int height, vector<pair<string,string>> configuration, int currentIndex)
{
	if (currentIndex == 0)
	{
		modifyConsoleOn(width, height, currentIndex, configuration, introMusic);
	}

	if (currentIndex == 1)
	{
		modifyConsoleOn(width, height, currentIndex, configuration, bgMusic);
	}

	if (currentIndex == 2)
	{
		modifyConsoleOn(width, height, currentIndex, configuration, introAnimate);
	}

	if (currentIndex == 3)
	{
		modifyConsoleOn(width, height, currentIndex, configuration, winAnimate);
	}

	if (currentIndex == 4)
	{
		modifyConsoleColor(width, height, currentIndex, configuration, curTextColor,nextTextColor);
	}

	if (currentIndex == 5)
	{
		modifyConsoleColor(width, height, currentIndex, configuration, curHightlightColor,nextHighlightColor);
	}

	if (currentIndex == 6)
	{
		modifyConsoleColor(width, height, currentIndex, configuration, curActiveColor,nextActiveColor);
	}

}

void confirmConsoleSetting()
{
	ofstream saveSetting;
	saveSetting.open("text/console_setting.txt");

	saveSetting << "introMusic: " << introMusic.on << endl;
	saveSetting << "bgMusic: " << bgMusic.on << endl;
	saveSetting << "introAnimate: " << introAnimate.on << endl;
	saveSetting << "winAnimate: " << winAnimate.on << endl;

	saveSetting << "textColor: " << nextTextColor.color << endl;
	saveSetting << "highlightedColor: " << nextHighlightColor.color << endl;
	saveSetting << "activeColor: " << nextActiveColor.color << endl;

	saveSetting.close();
}

void backAction(bool &back)
{
	back = true;
}

void consoleSetting(int width, int height)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curTextColor.color);
	system("cls");

	vector<pair<string, string>> configuration;

	configuration.push_back(make_pair("INTRO MUSIC", "ON/OFF"));
	configuration.push_back(make_pair("BACKGROUND MUSIC", "ON/OFF"));
	configuration.push_back(make_pair("INTRO ANIMATION", "ON/OFF"));
	configuration.push_back(make_pair("WIN ANIMATION", "ON/OFF"));
	configuration.push_back(make_pair("TEXT COLOR", "RED/YELLOW/GREEN"));
	configuration.push_back(make_pair("HIGHTLIGHTED COLOR", "RED/YELLOW/GREEN"));
	configuration.push_back(make_pair("ACTIVE COLOR", "RED/YELLOW/GREEN"));
	configuration.push_back(make_pair("CONFIRM", ""));
	configuration.push_back(make_pair("BACK", ""));

	introMusic.on = true;
	bgMusic.on = true;
	introAnimate.on = true;
	winAnimate.on = true;


	string temp;

	ifstream loadSetting;
	loadSetting.open("text/console_setting.txt", ios_base::app);

	loadSetting >> temp >> introMusic.on;
	loadSetting >> temp >> bgMusic.on;
	loadSetting >> temp >> introAnimate.on;
	loadSetting >> temp >> winAnimate.on;
	loadSetting >> temp >> curTextColor.color;
	loadSetting >> temp >> curHightlightColor.color;
	loadSetting >> temp >> curActiveColor.color;


	nextTextColor = curTextColor;
	nextActiveColor = curActiveColor;
	nextHighlightColor = curHightlightColor;

	loadSetting.close();


	drawConsoleSetting(width, height, configuration);

	int currentX = width / 4;
	int currentY = height / 4;
	int currentIndex = 0;
	bool back = false;

	while (back == false)
	{
		char key = _getch();

		if (key == 72)
		{
			if (currentY == height / 4)
			{
				currentY = currentY;
				currentIndex = currentIndex;
			}
			else
			{
				currentY = currentY - 2;
				currentIndex--;
			}

			drawConsoleSetting(width, height, configuration);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
			gotoXY(currentX, currentY);
			cout << configuration[currentIndex].first;

		}
		if (key == 80)
		{
			if (currentIndex == configuration.size() - 1)
			{
				currentY = currentY;
				currentIndex = currentIndex;
			}
			else
			{
				currentY = currentY + 2;
				currentIndex++;
			}

			drawConsoleSetting(width, height, configuration);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
			gotoXY(currentX, currentY);
			cout << configuration[currentIndex].first;

		}

		if (key == 13)
		{
			if (currentIndex < configuration.size() - 2)
			{
				drawConsoleSetting(width, height, configuration);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curActiveColor.color);
				gotoXY(currentX, currentY);
				cout << configuration[currentIndex].first;

				modifyConsoleSetting(width, height, configuration, currentIndex);

				gotoXY(width / 4, height / 4 + currentIndex * 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), curHightlightColor.color);
				cout << configuration[currentIndex].first;
				gotoXY(width / 4, height / 4 + currentIndex * 2);
			}
			if (currentIndex == configuration.size() - 2)
			{
				confirmConsoleSetting();
				backAction(back);
			}
			if (currentIndex == configuration.size() - 1)
			{
				backAction(back);
			}
		}

		gotoXY(currentX, currentY);

	}
}

void option()
{
	int width = getConsoleWidth();
	int height = getConsoleHeight();

	vector<string> component = { "CONSOLE SETTING","KEYPAD","GAMEPLAY CONFIGURATION","BACK" };

	bool back = false;

	while (back == false)
	{
		system("cls");

		int choice = controlMenuByArrow(component);

		if (choice == 0)
		{
			consoleSetting(width, height);
		}
		if (choice == 1)
		{

		}
		if (choice == 2)
		{

		}
		if (choice == 3)
		{
			backAction(back);
		}
	}
}