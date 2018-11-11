#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

/*-----------Basic function---------*/
void gotoXY(int x_pos, int y_pos);
int getConsoleWidth();
int getConsoleHeight();
void setCursorSize(int size);

/*-----------Color---------*/
#define red 12
#define yellow 14
#define green 10
#define blue 11
#define purple 13
#define grey 8


/*-------Cursor Size-------*/
#define smallCursor 20
#define largeCursor 100

/*-------Arrow Key-------*/
#define arrowUp 72
#define arrowRight 77
#define arrowLeft 75
#define arrowDown 80
#define escKey 27
#define enterKey 13


/*-------------Create object and point--------------*/
struct Object
{
	int x = 2;
	int y = 1;
	string icon;
	int win;
	int color;
	int save;
	int turn;
	int undo = 0;
	int quit = 0;
	int max_score = 0;
	vector<vector<int>> Score;
	vector<pair<int, int>> historyMove;
};
struct Point
{
	int x = 0;
	int y = 0;
};

/*---------------Setting struct------------*/
struct OnState
{
	bool on;
};
struct ColorState
{
	int color;
};

struct Color
{
	int textColor;
	int hightLightColor;
	int activeColor;
};

struct PvPConfig
{
	string mainIcon;
	string secondIcon;
	int mainColor;
	int secondColor;
	int sizeBoard;
	int boardColor;
	string goFirst;
};

struct PvCConfig
{
	string playerIcon;
	string botIcon;
	int playerColor;
	int botColor;
	int sizeBoard;
	int boardColor;
	string goFirst;
};

struct Priority
{
	string prior;
};

struct ConsoleConfig
{
	int introMusic;
	int bgMusic;
	int introAnimate;
	int winAnimate;
};


/*------------Default key-------------*/
struct PlayerKey
{

	char up;
	char down;
	char left;
	char right;
	char attack;

};

struct ControlGame
{
	char back = 'B';
	char undo = 'U';
	char save = 'L';
};

/*---------------AI feature------------*/
#define atkPoint 9
#define defPoint 6


#define maxDepthHard 8
#define maxMoveHard 4


#define maxDepthMed 3
#define maxMoveMed 3

#define maxDepthEasy 2
#define maxMoveEasy 2



/*---------------Get function------------*/

void getKey(PlayerKey &mainPlayer, PlayerKey &secondPlayer, ControlGame &controlGame);
void getPvPConfig(PvPConfig &pvpConfig);
void getPvCConfig(PvCConfig &pvcConfig);
void getConfig(ConsoleConfig &config);
void getColor(Color &color);



