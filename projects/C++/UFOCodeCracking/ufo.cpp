#include <iostream>
#include "ufo_functions.hpp"

int main() {
// Greet the user
  greet();

// Declare variables
std::string codeword = "abduction";
std::string answer = "__________";
int misses = 0;

// Vector and bool for incorrect/correct guesses
std::vector <char> incorrect = {};
bool guess = false;

// Player Input Variable
char letter;

// While loop to continue until guessed correctly or less than 7 misses
while (misses <= 6 && answer != codeword){
  display_misses(misses);
  display_status(incorrect, answer);
  std::cout << "Please enter your guess: ";
  std::cin >> letter;
  std::cout << "\n";
  // Loop through codeword to see if correct.
  for(int i = 0; i < codeword.length(); i++){
    if (letter == codeword[i]){
      answer[i] = letter;
      guess = true;
    } 
  }
  if (guess) {
    std::cout << "Correct!\n";
  } else {
    std::cout << "Incorrect! The tractor beam pulls the person in further.\n";
    incorrect.push_back(letter);
    // Increase miss counter
    misses++;
  }
  guess = false;
}
// End of game function
end_game(answer, codeword);

}
