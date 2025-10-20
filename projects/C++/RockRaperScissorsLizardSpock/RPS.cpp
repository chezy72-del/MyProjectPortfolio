#include <iostream>
#include <stdlib.h>

int main(){
//random number generator and user variable
srand(time(NULL));
int computer = rand() % 5 + 1; //random number between 1-5
int user = 0;

//user prompts
std::cout << "=================================\n";
std::cout << "Rock Paper Scissors Lizard Spock!\n";
std::cout << "=================================\n";

std::cout << "1) Rock ✊\n";
std::cout << "2) Paper ✋\n";
std::cout << "3) Scissors ✌️\n";
std::cout << "4) Lizard 🦎\n";
std::cout << "5) Spock 🖖\n";

std::cout << "shoot!: ";
std::cin >> user;

//conditionals about victor
//User = Computer Tie
if (user==computer) {
  std::cout << "It's a tie!\n";
}
//user picks rock
if (user==1) {
  if (computer==3) {
    std::cout << "Rock crushes scissors. You win!\n";
  } else if (computer==4) {
    std::cout << "Rock crushes lizard. You win!\n";
  } else {
    std::cout << "You lose!\n";
  }
}
//user picks paper
if (user==2) {
  if (computer==1) {
    std::cout << "Paper covers rock. You win!\n";
  } else if (computer==5) {
    std::cout << "Paper disproves Spock. You win!\n";
  } else {
    std::cout << "You lose!\n";
  }
}
//user picks scissors
if (user==3) {
  if (computer==2) {
    std::cout << "Scissors cuts paper. You win!\n";
  } else if (computer==4) {
    std::cout << "Scissors decapitates lizard. You win!\n";
  } else {
    std::cout << "You lose!\n";
  }
}
//user picks lizard
if (user==4) {
  if (computer==5) {
    std::cout << "Lizard poisons Spock. You win!\n";
  } else if (computer==2) {
    std::cout << "Lizard eat paper. You win!\n";
  } else {
    std::cout << "You lose!\n";
  }
}
//user picks Spock
if (user==5) {
  if (computer==3) {
    std::cout << "Spock smashes scissors. You win!\n";
  } else if (computer==1) {
    std::cout << "Spock vaporises rock. You win!\n";
  } else {
    std::cout << "You lose!\n";
  }
}

}