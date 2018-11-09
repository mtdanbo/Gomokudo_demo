#pragma once
#include "base.h"
#include "compute.h"

int findMove(int maxDepth, int maxMove, int depth, vector<vector<string>> Board, Object p, Object b, int size, int &miniMax, Point &point);

int findMove3(int maxDepth, int maxMove, int depth, vector<vector<string>> board, Object p, Object b, int size, int &miniMax, Point &point);

int findMove4(int maxDepth, int maxMove, int depth, vector<vector<string>> board, Object p, Object b, int size, int &miniMax, Point &point);

