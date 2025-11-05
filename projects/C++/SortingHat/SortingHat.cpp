#include <iostream>

int main() {

  // Declare houses
  int gryffindor=0;
  int hufflepuff=0;
  int ravenclaw=0;
  int slytherin=0;
  //Declare answers
  int answer1;
  int answer2;
  int answer3;
  int answer4;

  //User interaction
  std::cout << "The Sorting Hat Quiz!\n";
  //Question 1
  std::cout << "Q1) When I'm dead, I want people to remember me as:\n1) The Good\n2) The Great\n3) The Wise\n4) The Bold\nYour answer: ";
  std::cin >> answer1;
  //House score update
  if (answer1 == 1) {
    hufflepuff++;
  } else if (answer1 == 2) {
    slytherin++;
  } else if (answer1 == 3) {
    ravenclaw++;
  } else if (answer1 == 4) {
    gryffindor++;
  } else {
    std::cout << "Invalid input.\nYour answer: ";
    std::cin >> answer1;
  }

  //Question 2
  std::cout << "Q2) Dawn or Dusk?\n1) Dawn\n2) Dusk\nYour answer:";
  std::cin >> answer2;
  ////House score update
  if (answer2 == 1) {
    gryffindor++;
    ravenclaw++;
  } else if (answer2 == 2) {
    slytherin++;
    hufflepuff++;
  } else {
    std::cout << "Invalid input.\nYour answer: ";
    std::cin >> answer2;
  }

  //Question 3
  std::cout << "Q3) Which kind of instrument most pleases your ear?\n1) The violin\n2) The trumpet\n3) The piano\n4) The drum\nYour answer: ";
  std::cin >> answer3;
  //House score update
  if (answer3 == 1) {
    slytherin++;
  } else if (answer3 == 2) {
    hufflepuff++;
  } else if (answer3 == 3) {
    ravenclaw++;
  } else if (answer3 == 4) {
    gryffindor++;
  } else {
    std::cout << "Invalid input.\nYour answer: ";
    std::cin >> answer3;
  }

  //Question 4
  std::cout << "Q4) Which road tempts you most?\n1) The wide, sunny grassy lane\n2) The narrow, dark, lantern-lit alley\n3) The twisting, leaf-strewn path through woods\n4) The cobbled street lined (ancient buildings)\nYour answer: ";
  std::cin >> answer4;
  //House score update
  if (answer4 == 1) {
    hufflepuff++;
  } else if (answer4 == 2) {
    slytherin++;
  } else if (answer4 == 3) {
    gryffindor++;
  } else if (answer4 == 4) {
    ravenclaw++;
  } else {
    std::cout << "Invalid input.\nYour answer: ";
    std::cin >> answer4;
  }

    //House reveal
    int max=0;
    std::string house;

    if (gryffindor > max) {  
        max = gryffindor;
        house = "Gryffindor"; 
    }

    if (hufflepuff > max) {
        max = hufflepuff;
        house = "Hufflepuff";
    }

    if (ravenclaw > max) {
        max = ravenclaw;
        house = "Ravenclaw";
    }

    if (slytherin > max) {
        max = slytherin;
        house = "Slytherin";
    }

    std::cout << house << "!\n";

}
