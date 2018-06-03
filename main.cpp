#include <iostream>
#include <string>
#include "main.h"
#include "FBullCowGame.h"

int main()
{
	printIntro();

	bool playAgain = false;

	do {
		PlayGame();
		playAgain = AskToPlayAgain();
	} 
	while (playAgain);

	return 0;
}

void PlayGame()
{
	FBullCowGame BCGame;
	// loop for the number of turns asking guesses
	constexpr int NUMBER_OF_TURNS = 2;
	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		std::string Guess = getGuess();
		std::cout << Guess << std::endl;
	}
}

std::string getGuess()
{
	// get a guess from the player
	std::string Guess = "";
	std::cout << "\nEnter your guess: ";
	std::getline(std::cin, Guess);

	// print Guess
	std::cout << "\nYour guess was: " << Guess << std::endl;

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	std::string Response = "";
	std::getline(std::cin, Response);

	std::cout << " Is it y?" << (Response[0] == 'Y' || Response[0] == 'y');

	return (Response[0] == 'Y' || Response[0] == 'y');
}
void printIntro()
{
	// introduce the game
	constexpr int WORLD_LENGTH = 5;// constant expression
	std::cout << "\n\nWelcome to Bull and Cows!" << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";

	return;
}