#pragma once
#include "base.h"

void savePvP(vector<vector<string>> Board, int size, Object p1, Object p2);

void savePvC(vector<vector<string>> Board, int size, Object p, Object b, int mode);

void saveRule1(vector<vector<string>> board, int size, Object player1, Object player2, Object obstacle);

void saveRule2(vector<vector<string>> board, int size, Object player1, Object player2, Object obstacle);
