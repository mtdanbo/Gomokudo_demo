#pragma once
#include "base.h"
#include "draw.h"
#include "console.h"

void leaderboard_pvp_save(Object p1, Object p2, int size, vector<vector<string>> Board);

void leaderboard_pvp_load(string filename);

void leaderboard_pvp_show();

void leaderboard_pvc_save(Object player, Object bot, int size, vector<vector<string>> board);

void leaderboard_rule1_save(Object player1, Object player2, Object rock, int size, vector<vector<string>> board);

void leaderboard_rule2_save(Object player1, Object player2, Object rock, int size, vector<vector<string>> board);

void leaderboard_rule3_save(Object player1, Object player2, int size, vector<vector<string>> board);

void leaderboard_rule4_save(Object player1, Object player2, int size, vector<vector<string>> board);

void leaderboard_rule5_save(Object player1, Object player2, int size, vector<vector<string>> board);

void leaderboard_rule6_save(Object player1, Object player2, int size, vector<vector<string>> board);

void leaderboard_rule7_save(Object player1, Object player2, int size, vector<vector<string>> board);

void leaderboard_rule8_save(Object player1, Object player2, int size, vector<vector<string>> board);

void leaderboard();

