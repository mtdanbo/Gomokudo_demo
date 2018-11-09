#pragma once
#include "base.h"
Object mainControl(Object p, int size, vector<vector<string>> Board);
Object secondControl(Object p,int size, vector<vector<string>> Board);

Object mainControlRule6(Object p, int size, vector<vector<string>> Board, int numMove, int maxMove);

Object secondControlRule6(Object p, int size, vector<vector<string>> Board, int numMove, int maxMove);

Object mainControlRule7(Object p, int size, vector<vector<string>> Board, int lastXPos, int lastYPos, int range);

Object secondControlRule7(Object p, int size, vector<vector<string>> Board, int lastXPos, int lastYPos, int range);