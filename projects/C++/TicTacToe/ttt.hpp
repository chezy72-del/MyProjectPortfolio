#include <iostream>
#include <vector>

// Create vector for board
std::vector<std::vector<char>> board {
    {'0','1','2'}, 
    {'3','4','5'}, 
    {'6','7','8'}};

// Variable to track player moves for each turn
int current_player = 1;
std::vector<int> move;

// Functions to track game status
bool is_winner(); //works
bool filled_up(); //works
void introduction(); //works
void take_turn(); //works
void set_position(); //works
void update_board(); //works
void change_player(); //works
void draw(); //works
void end_game(); //works

