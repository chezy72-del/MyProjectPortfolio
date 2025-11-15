#include <iostream>
#include <vector>
#include "tttfunc.cpp"

int main() {

// Introduction to game
    introduction();

// Game loop  
while(!is_winner() && !filled_up()) {
    take_turn();
    set_position();
    update_board();
    if(!is_winner()) {
        change_player();
    } 
}


// End game message
end_game();
}