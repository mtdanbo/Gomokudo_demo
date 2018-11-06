#pragma once
#include "base.h"
#include "draw.h"
#include "console.h"

void leaderboard_pvp_save(Object p1, Object p2, int size, vector<vector<string>> Board);

void leaderboard_pvp_load(string filename);

void leaderboard_pvp_show();

void leaderboard_pvc_save(Object player, Object bot, int size, vector<vector<string>> board);

void leaderboard();

