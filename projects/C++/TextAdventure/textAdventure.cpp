#include <iostream>

int main(){
//This is a program for a text adventure. It will use user input to give different stories.

//Collecting variables from user
std::cout << "Before we begin our story please enter an answer for each of the following things. This will help build your unique story.\n";
std::cout << "Throughout the story, you will be asked to make choices which will affect the way the story progresses.\n";
//colour
std::string colour;
std::cout << "Input a colour: ";
std::getline(std::cin, colour);
//weather
std::string weather;
std::cout << "Input a description of a day (cold, windy, etc.): ";
std::getline(std::cin, weather);
//animals and names
std::string animal1;
std::cout << "Input your first animal: ";
std::getline(std::cin, animal1);
std::string name1;
std::cout << "Name your first animal: ";
std::getline(std::cin, name1);  
std::string animal2;
std::cout << "Input your second animal: ";
std::getline(std::cin, animal2);
std::string name2;
std::cout << "Name your second animal: ";
std::getline(std::cin, name2);
//misc variables
std::string food;
std::cout << "Input a type of food: ";
std::getline(std::cin, food);
std::string item;
std::cout << "Input a miscellaneous item: ";
std::getline(std::cin, item);
std::string size;
std::cout << "Input an adjective describing size: ";
std::getline(std::cin, size);
std::string greeting;
std::cout << "Input an action you do when you meet someone (ending in s: nods, waves, etc.): ";
std::getline(std::cin, greeting);
std::string desc;
std::cout << "Input a description on a person (wrinkly, happy, young, etc): ";
std::getline(std::cin, desc);

//Title
std::cout << "\nYour adventure starts below.\n";
std::cout << "==========================================\n";
std::cout << "The " << animal1 << " and the " << animal2 << "\n";
std::cout << "==========================================\n";
//Introduction
std::cout << "The day started like every other, " << name1 << " the " << animal1 << " woke up, pulled back their " << colour << " curtains and looked outside at the " << weather << " day.\n";
std::cout << name1 << " has a dilemma, do they go back to bed (1) or do they go outside (2)?\n";
//First fork in the story
int option1;
std::cout << "What does " << name1 << " decide to do? ";
std::cin >> option1;
//check for valid response
  while(option1 != 1 && option1 !=2){
    std::cout << "Invalid response. Try again: ";
    std::cin >> option1;
  }

  if (option1 == 1) { //bed
      std::cout << "\n"<< name1 << " decided to go back to bed. \n";
      std::cout << "While " << name1 << " slept, they had the most unusual dream. They were in a world where everything was made out of " << food << ".\n";
      std::cout << "The first thing " << name1 << " did was take a massive bite out of the " << item << ".\n"; 
      std::cout << name1 << " hears footsteps coming from behind. " << name1 << " turns around and screams as a " << size << " " << animal2 << " is running towards them trying to escape from the " << food << " monster! \n";
      std::cout << "They both hide under a bridge and hear the monster stomp away.\n";
      std::cout << name1 << " turns to the " << animal2 << " and introduces themself, the " << animal2 << " then introduces themself as " << name2 << ".\n";
      std::cout << "Suddenly, " << name1 << "jolts awake and smile while thinking about their new friend " << name2 << " the " << animal2 <<".\nThe End.\n";
      return 0;
  } else { //outside
      std::cout << "\n" << name1 << " puts on their favourite " << colour << " coat and visits a nature park.\n";
      std::cout << "The nature park is very busy today and " << name1 << " doesn't like crowds so decided to go find a quiet place to read.\n";
      std::cout << name1 << " sees two possible locations, the treehouse (1) or rent a boat and go on the lake (2).\n";
      //fork number two in story
      int option2;
      std::cout << "Where does " << name1 << " decide to go? ";
      std::cin >> option2;
      //check if valid response
      while(option2 != 1 && option2 !=2){
        std::cout << "Invalid response. Try again: ";
        std::cin >> option2;
      }
      //treehouse
      if (option2 == 1) { 
        std::cout << "\n" << name1 << " starts the climb up the treehouse, upon entering they notice a " << size << " " << animal2 << " in the corner reading a book.\n";
        std::cout << "The " << animal2 << " " << greeting << " to " << name1 << " and says their name is " << name2 << ".\n";
        std::cout << name2 << " asks " << name1 << " if they would like to play a game.\n";
        //fork 3
        int option3;
        std::cout << "Would " << name1 << " like to play a game? Yes (1) or No (2): ";
        std::cin >> option3;
        //check for valid response
        while (option3 != 1 && option3 !=2){
          std::cout << "Invalid response. Try again: ";
          std::cin >> option3;
        }
        if (option3 == 1) { //play game
          std::cout << "\n" << name2 << " says \"I am thinking of a number between 1-10. \nIn order to win the game, you have to guess the correct number. You have 3 guesses.\n";
            int correct = 7;
            int guess;
            std::cout << "What number does " << name1 << " guess? ";
            std::cin >> guess;
            //guesses in game
          for (int i = 3; i > 0; i--) {
          if (guess == correct) {
            std::cout << "\nVicory! The correct number was " << correct << ".\nThe End.\n";
            i = 0 ;
            return 0;
          } else if (i > 1) { 
            std::cout << "\nIncorrect guess, " << name1 << " has " << i-1 << " guesses left. Try again.\n";
            std::cin >> guess; 
          } else if (i == 1) {
            std::cout << "\n" << name1 << " has failed the game. " << name2 << " pushes " << name1 << " out of the treehouse. \nThe End.\n";
            return 0;
          } 
          }
          } else { //don't play game
            std::cout << "\n" << name2 << " says \"that is alright\" and goes back to reading their book.\n";
            std::cout << name1 << " sits down in the treehouse with " << name2 << " and they both read their books in silence.\nThe End.\n";
            return 0;
          }
        }
        //boat
        else { 
          std::cout << "\n" << name1 << " walks over to the boat hire outhouse. Inside there is a " << desc << " sales assistant, who says \"Welcome! To hire a boat for 1 hour it is $50\".\n";
          std::cout << "\"Do you want to hire one?\" Yes (1) or No (2)\n";
          //fork 4
          int option4;
          std::cout << "Does " << name1 << " want to hire a boat? ";
          std::cin >> option4;
          //check for valid response
          while(option4 != 1 && option4 !=2){
            std::cout << "Invalid response. Try again: ";
            std::cin >> option4;
          }
          if (option4 == 1) { //hire a boat
            std::cout << "\n" << name1 << " hands over the $50 and makes their way to the " << colour << " boat.\n";
            std::cout << "Once " << name1 << " is floating in the middle of the lake, they pull out the book appreciating the silence on the water.\n";
            std::cout << "Until they hear a splashing getting closer. " << name1 << " looks left and right, but sees no one. " << name1 << " is starting to get scared, the splashing is getting louder and louder, but still there is noone around. \n";
            std::cout << "Suddenly a " << size << " " << animal2 << " breaks the surface of the water and climbs onto the boat. \n";
            std::cout << "The " << animal2 << " quickly looks around and spots " << name1 << " and " << greeting << " to them.\n";
            std::cout << "A wicked smile creeps onto their face as they shout \"My name is " << name2 << " and I am commandeering this boat\"\n";
            std::cout << name2 << " throws " << name1 << " overboard and sails away taking " << name1 << "'s book with them.\nThe End.\n";
            return 0;
          } else {//doesn't hire a boat
            std::cout << "\n" << name1 << " decides not to hire the boat, and instead goes home to read their book \"" << name2 << "'s battle over the " << size << " " << colour << " " << food << " monster\" snuggled under a blanket in front of the fire eating " << food << ".\nThe End.\n";
            return 0;
          }
      }
      } 
    
//ending
std::cout << "============================================== \n";
std::cout << "I hope you enjoyed the story we wrote together.\n";
std::cout << "Thank you and goodbye!\n";
} 
