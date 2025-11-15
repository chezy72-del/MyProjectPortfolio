#include <iostream>
#include <vector>
#include "ttt.hpp"

// Introduction
void introduction() {
    std::cout << "\n  Welcome to Tic Tac Toe!\n";
    std::cout << "____________________________\n\n";
    std::cout << "Player 1 is X and Player 2 is O\n";
    std::cout << "The board positions are numbered as follows:\n\n";
    draw();
    std::cout << "Let the game begin!\n";
}

// Create board to play Tic Tac Toe
void draw() {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    std::cout << "___________\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    std::cout << "___________\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n\n";
}

// Function to check for a win
bool is_winner() {
    // Check rows, columns, and diagonals
    if ((board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
        (board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
        (board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
        (board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
        (board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
        (board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
        (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
        ;
    }
    return false;
}

// Function to check if board is filled up
bool filled_up() {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }
    return true;
}

// Function for player to take turn
void take_turn() {
    int position;
    std::cout << "Player " << current_player << " enter your move (0-8): ";
    std::cin >> position;
        for(int i = 0; i < move.size(); i++) {
        if(position == move[i]) {
            std::cout << "Position already taken. Choose another position: ";
            std::cin >> position;
            i = -1; // Reset loop to check again
        }
    }
    move.push_back(position);
}

// Function to set position on board
void set_position() {
    int pos = move.back();
    char symbol = (current_player == 1) ? 'X' : 'O';
    board[pos / 3][pos % 3] = symbol;
}

// Function to update board after each turn
void update_board() {
    draw();
}

// Function to change player
void change_player() {
    if(current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

// Function to end game
void end_game() {
    if(is_winner()) {
        std::cout << "Player " << current_player << " wins!\n";
    } else if(filled_up()) {
        std::cout << "The game is a draw!\n";
    }
}

