#pragma once
#include "base.h"
vector<vector<string>> drawBoard(int size, vector<vector<string>> board, Object o1, Object o2, int drawBoard);

vector<vector<string>> drawBoardRule1(int size, vector<vector<string>> board, Object object1, Object object2, Object obstacle, int boardColor, int numRock);

vector<vector<string>> drawBoardRule2(int size, vector<vector<string>> board, Object object1, Object object2, Object obstacle, int boardColor);

vector<vector<string>> drawBoardRule5(int size, vector<vector<string>> board, Object o1, Object o2, int currentBoom);

vector<vector<string>> drawBoardRule8(int size, vector<vector<string>> board, Object o1, Object o2, int currentChangedItem);
