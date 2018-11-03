#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void gotoXY(int x_pos, int y_pos);


struct Object
{
	int x, y;
	string icon;
	int win;
	int color;
	int save;
	int turn;
	int undo;
	int quit = 0;
	int max_score = 0;

	vector<vector<int>> Score;
};

struct Bot
{
	int x, y;
	string icon;
	int win;
	int color;
};

struct Data
{
	vector<vector<int>> Atk;
	vector<vector<int>> Def;
	int current_x_max;
	int current_y_max;
};

struct Point
{

	int x = 0;
	int y = 0;

};


const int red = 12;
const int yellow = 14;
const int green = 10;

const int  atk_point = 9;
const int def_point = 6;

const int maxDepth = 5;
const int maxMove = 3;


