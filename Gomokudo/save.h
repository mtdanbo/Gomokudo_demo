#pragma once
#include "base.h"

void savePvP(vector<vector<string>> Board, int size, Object p1, Object p2);

void savePvC(vector<vector<string>> Board, int size, Object p, Object b, int mode);

void saveRule1(vector<vector<string>> board, int size, Object player1, Object player2, Object obstacle);

void saveRule2(vector<vector<string>> board, int size, Object player1, Object player2, Object obstacle);

void saveRule3(vector<vector<string>> board, int size, Object player1, Object player2, int currentTime, int changeTime);

void saveRule4(vector<vector<string>> board, int size, Object player1, Object player2, int currentTime, int changeTime, int changeSize);

void saveRule5(vector<vector<string>> board, int size, Object player1, Object player2, Object boom, vector<pair<int, int>> boomPos);

void saveRule6(vector<vector<string>> board, int size, Object player1, Object player2, int restrictMove);

void saveRule7(vector<vector<string>> board, int size, Object player1, Object player2, int range);

void saveRule8(vector<vector<string>> board, int size, Object player1, Object player2, Object changed, vector<pair<int, int>> changedPos);
