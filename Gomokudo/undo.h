#pragma once
#include "base.h"
#include "draw.h"

void undop1(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first);

void undop2(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first);

void undop1Rule1(Object &player1, Object &player2, Object &obstacle, vector<vector<string>> &board, int size, int &go_first, int numRock);

void undop2Rule1(Object &player1, Object &player2, Object &obstacle, vector<vector<string>> &board, int size, int &go_first, int numRock);

void undop1Rule2(Object &player1, Object &player2, Object &obstacle, vector<vector<string>> &board, int size, int &go_first);

void undop2Rule2(Object &player1, Object &player2, Object &obstacle, vector<vector<string>> &board, int size, int &go_first);

void undop1Rule3(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentTime);

void undop2Rule3(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentTime);

void undop1Rule5(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentBoom);

void undop2Rule5(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentBoom);

void undoPvC(Object &player, Object &bot, vector<vector<string>> &board, int size);

void undop1Rule8(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentChangedItem);

void undop2Rule8(Object &player1, Object &player2, vector<vector<string>> &board, int size, int &go_first, int currentChangedItem);