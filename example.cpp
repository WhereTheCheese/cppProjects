#include <iostream>
#include <random>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
//NO GLOBAL VARIABLES
//NO STRINGS
//YOU SHOULD USE <iostream>

int NumGuess()
{
  srand(time(0));
  int randomNum = rand() % 101;
  std::cout << randomNum;
  

  return randomNum;
}


int main() {
  int running = 1;
  do {
  cout << "Welcome to guessing game!" << endl;
  int num = NumGuess();
  int input;
  int guesses = 0;
  do {
    cin >> input;
    guesses++;
    if (num < input) {
      cout << "Your guess is to big" << endl;
    } else if (num > input) {
      cout << "Your guess is to low" << endl;
    }
  } while (input != num);
  cout << "it took you " << guesses << " guesses!" << endl;
  cout << "would you like to play again? y/n" << endl;
  char yorn;
  cin >> yorn;
  char test = 'y';
  if (yorn == test) {
  } else {
    cout << "Thanks for Playing!!!" << endl;
    running = 0;
  }
  } while (running == 1);
  exit(0);
}

