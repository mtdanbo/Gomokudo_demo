#pragma once
#include "base.h"
#include "draw.h"

void undop1(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first);

void undop2(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first);

void undoPvC(Object &player, Object &bot, vector<vector<string>> &board, int size);