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
const int red = 12;
const int yellow = 14;
const int green = 10;
const int blue = 11;
const int purple = 13;
const int grey = 8;

/*-------Cursor Size-------*/
const int smallCursor = 20;
const int largeCursor = 100;

/*-------Arrow Key-------*/
const int arrowUp = 72;
const int arrowRight = 77;
const int arrowLeft = 75;
const int arrowDown = 80;
const int escKey = 27;

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
void getColor(Color &color);


/*---------------AI feature------------*/
const int atkPoint = 9;
const int defPoint = 6;

const int maxDepthHard = 8;
const int maxMoveHard = 4;

const int maxDepthMed = 3;
const int maxMoveMed = 3;

const int maxDepthEasy = 2;
const int maxMoveEasy = 2;

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

void getKey(PlayerKey &mainPlayer, PlayerKey &secondPlayer, ControlGame &controlGame);

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

void getPvPConfig(PvPConfig &pvpConfig);
void getPvCConfig(PvCConfig &pvcConfig);





