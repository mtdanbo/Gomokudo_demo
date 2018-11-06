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

PlayerKey mainPlayer;
PlayerKey secondPlayer;
ControlGame controlGame;

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

void drawKeyPadSetting(int width, int height, vector<pair<string, char>> mainKey, vector<pair<string, char>> secondKey, vector<pair<string,char>> controlKey)
{
	Color color;
	getColor(color);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	gotoXY(width / 4 - 20, height / 4 - 1);
	cout << "MAIN PLAYER KEYPAD";

	gotoXY(width / 4 + 20, height / 4 - 1);
	cout << "SECOND PLAYER KEYPAD";

	gotoXY(width / 4 + 60, height / 4 - 1);
	cout << "CONTROL GAME KEYPAD";

	for (int i = 0; i < mainKey.size(); i++)
	{

		if (i < mainKey.size() - 2)
		{
			gotoXY(width / 4 - 20, height / 4 + i*2);
			cout << mainKey[i].first;
			gotoXY(width / 4 - 20 + 10, height / 4 + i*2);
			cout << mainKey[i].second;
		}
		else
		{
			gotoXY(width / 4 - 20, height / 4 + i*2);
			cout << mainKey[i].first;
		}
	}

	for (int i = 0; i < secondKey.size(); i++)
	{
		if (i < secondKey.size() - 2)
		{
			gotoXY(width / 4 + 20, height / 4 + i*2);
			cout << secondKey[i].first;
			gotoXY(width / 4 + 10 + 20, height / 4 + i*2);
			cout << secondKey[i].second;
		}
		else
		{
			gotoXY(width / 4 + 20, height / 4 + i*2);
			cout << secondKey[i].first;
		}
	}

	for (int i = 0; i < controlKey.size(); i++)
	{
		if (i < controlKey.size() - 4)
		{
			gotoXY(width / 4 + 60, height / 4 + i*2);
			cout << controlKey[i].first;
			gotoXY(width / 4 + 10 + 60, height / 4 + i*2);
			cout << controlKey[i].second;
		}
		else
		{
			gotoXY(width / 4 + 60, height / 4 + i*2);
			cout << controlKey[i].first;
		}
	}

}

void confirmKeyPad(vector<pair<string, char>> mainKey, vector<pair<string, char>> secondKey,vector<pair<string, char>> controlKey)
{

	ofstream keypadMain;
	
	keypadMain.open("text/mainplayer_key.txt");

	keypadMain << "up: " << mainKey[0].second << endl;
	keypadMain << "down: " << mainKey[1].second << endl;
	keypadMain << "left: " << mainKey[2].second << endl;
	keypadMain << "right: " << mainKey[3].second << endl;
	keypadMain << "fight: " << mainKey[4].second << endl;

	keypadMain.close();

	ofstream keypadSecond;

	keypadSecond.open("text/secondplayer_key.txt");

	keypadSecond << "up: " << secondKey[0].second << endl;
	keypadSecond << "down: " << secondKey[1].second << endl;
	keypadSecond << "left: " << secondKey[2].second << endl;
	keypadSecond << "right: " << secondKey[3].second << endl;
	keypadSecond << "fight: " << secondKey[4].second << endl;

	keypadSecond.close();

	ofstream keypadControl;

	keypadControl.open("text/control_key.txt");

	keypadControl << "back: " << controlKey[0].second << endl;
	keypadControl << "undo: " << controlKey[1].second << endl;
	keypadControl << "save: " << controlKey[2].second << endl;

	keypadControl.close();

}

void keypadSetting(int width, int height)
{
	system("cls");
	Color color;
	getColor(color);

	getKey(mainPlayer, secondPlayer, controlGame);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	gotoXY(width / 2 - 15, 0);
	cout << "WELCOME TO KEYPAD SECTION";
	gotoXY(width / 2 - 40, 1);
	cout << "Press Enter for button you want to modify and press ESC if you complete";


	vector<pair<string, char>> mainKey;

	mainKey.push_back(make_pair("UP:", mainPlayer.up));
	mainKey.push_back(make_pair("DOWN:", mainPlayer.down));
	mainKey.push_back(make_pair("LEFT:", mainPlayer.left));
	mainKey.push_back(make_pair("RIGHT:", mainPlayer.right));
	mainKey.push_back(make_pair("FIGHT:", mainPlayer.attack));
	mainKey.push_back(make_pair("CONFIRM", 'a'));
	mainKey.push_back(make_pair("BACK", 'a'));



	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

	vector<pair<string, char>> secondKey;

	secondKey.push_back(make_pair("UP:", secondPlayer.up));
	secondKey.push_back(make_pair("DOWN:", secondPlayer.down));
	secondKey.push_back(make_pair("LEFT:", secondPlayer.left));
	secondKey.push_back(make_pair("RIGHT:", secondPlayer.right));
	secondKey.push_back(make_pair("FIGHT:", secondPlayer.attack));
	secondKey.push_back(make_pair("", 'a'));
	secondKey.push_back(make_pair("", 'a'));
	
	vector<pair<string, char>> controlKey;
	controlKey.push_back(make_pair("BACK:",controlGame.back));
	controlKey.push_back(make_pair("UNDO:", controlGame.undo));
	controlKey.push_back(make_pair("SAVE:", controlGame.save));
	controlKey.push_back(make_pair("", 'a'));
	controlKey.push_back(make_pair("", 'a'));
	controlKey.push_back(make_pair("", 'a'));
	controlKey.push_back(make_pair("", 'a'));

	drawKeyPadSetting(width, height, mainKey, secondKey,controlKey);



	int currentX = width / 4 - 20;
	int currentY = height / 4;
	int currentIndex = 0;
	bool back = false;
	bool check = true;

	while (back == false)
	{
		char key = _getch();
		if (key == 75)
		{
			if (currentX == width/4 - 20)
			{
				currentX = currentX;
			}
			else
			{
				currentX = currentX - 40;
			}

			
		}

		if (key == 77)
		{
			if (currentX == width/4 + 60)
			{
				currentX = currentX;
			}
			else
			{
				currentX = currentX + 40;
			}

			
		}

		if (key == 72)
		{
			if (currentY == height/4)
			{
				currentY = currentY;
				currentIndex = currentIndex;
			}
			else
			{
				currentY = currentY - 2;
				currentIndex--;
			}

			
		}

		if (key == 80)
		{
			if (currentIndex == mainKey.size() - 1)
			{
				currentY = currentY;
				currentIndex = currentIndex;
			}
			else
			{
				currentY = currentY + 2;
				currentIndex++;
			}
		}

		drawKeyPadSetting(width, height, mainKey, secondKey,controlKey);

		gotoXY(currentX, currentY);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.hightLightColor);

		if (currentX == width/4 - 20)
		{
			cout << mainKey[currentIndex].first;
		}
		if (currentX == width/4 +20)
		{
			cout << secondKey[currentIndex].first;
		}
		if (currentX == width/4 +60)
		{
			cout << controlKey[currentIndex].first;
		}

		gotoXY(currentX, currentY);

		if (key == 13)
		{
			if (currentIndex < mainKey.size() - 2)
			{
				drawKeyPadSetting(width, height, mainKey, secondKey,controlKey);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.activeColor);

				gotoXY(currentX, currentY);

				if (currentX == width / 4 - 20)
				{
					cout << mainKey[currentIndex].first;
				}
				if (currentX == width / 4 + 20)
				{
					cout << secondKey[currentIndex].first;
				}
				if (currentX == width / 4 + 60)
				{
					cout << controlKey[currentIndex].first;
				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);

				gotoXY(currentX + 10, currentY);
				int temp = 0;

				while (1)
				{
					char temp_key = _getch();

					if (temp_key == 27)
					{
						gotoXY(currentX, currentY);
						break;
					}
					else
					{
						if (temp % 2 != 0)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.textColor);
							gotoXY(currentX + 10, currentY);


							if (temp_key != 'w' && temp_key != 's' && temp_key != 'd' && temp_key != 'a' && temp_key > 90)
							{
								temp_key = temp_key - 32;
							}

							cout << temp_key;

							if (currentX == width / 4-20)
							{
								mainKey[currentIndex].second = temp_key;
							}
							if (currentX == width / 4 + 20)
							{
								secondKey[currentIndex].second = temp_key;
							}
							if (currentX == width/4 +60)
							{
								controlKey[currentIndex].second = temp_key;
							}


						}
					}
					temp++;
				}
			}

			if (currentIndex == mainKey.size() - 2)
			{
				check = true;

				vector<char> keyPad;

				keyPad.push_back(mainKey[0].second);
				keyPad.push_back(mainKey[1].second);
				keyPad.push_back(mainKey[2].second);
				keyPad.push_back(mainKey[3].second);
				keyPad.push_back(mainKey[4].second);

				keyPad.push_back(secondKey[0].second);
				keyPad.push_back(secondKey[1].second);
				keyPad.push_back(secondKey[2].second);
				keyPad.push_back(secondKey[3].second);
				keyPad.push_back(secondKey[4].second);

				keyPad.push_back(controlKey[0].second);
				keyPad.push_back(controlKey[1].second);
				keyPad.push_back(controlKey[2].second);

				sort(keyPad.begin(), keyPad.end());

				for (int i = 0; i < keyPad.size() - 1; i++)
				{

					if (keyPad[i + 1] == keyPad[i])
					{
						check = false;
					}

				}

				if (check == false)
				{
					gotoXY(width / 2 - 30, height - 5);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.hightLightColor);
					cout << "Error !!!!, some keys are in second place. Please modify key again";
				}

				if (check == true)
				{
					confirmKeyPad(mainKey, secondKey, controlKey);
					break;
				}
			}

			if (currentIndex == mainKey.size() - 1)
			{
				backAction(back);
			}

		}

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
			keypadSetting(width, height);
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