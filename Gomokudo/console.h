#pragma once
#include "base.h"
#include "draw.h"

void escape();
void animateText(ifstream& text);
void animateP1Win(int size);
void animateP2Win(int size);

void animateDraw(int size);

void animateBotWin(int size);

int controlMenuByArrow(vector<string> data);