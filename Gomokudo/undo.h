#pragma once
#include "base.h"
#include "draw.h"

void undop1(Object &p1, Object &p2, vector<pair<int, int>> &p1undo, vector<pair<int, int>> &p2undo, vector<vector<string>> &Board, int size, vector<string> &temp, int &go_first);

void undop2(Object &p1, Object &p2, vector<pair<int, int>> &p1undo, vector<pair<int, int>> &p2undo, vector<vector<string>> &Board, int size, vector<string> &temp, int &go_first);