
#ifndef BULL_COW_GAME_F_BULL_COW_GAME_H_
#define BULL_COW_GAME_F_BULL_COW_GAME_H_

#include <string>
#include <iostream>

struct FBullCowCount 
{
	int Bulls = 0;
	int Cows = 0;
};

class FBullCowGame {
 public:
  FBullCowGame();
	virtual ~FBullCowGame();
	void Reset(); // TODO make a more rich return value
	int GetMaxTries() const;
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string PlayerGuess);

	void PrintGameIntro();
	bool AskToPlayAgain();
	void PlayGame();
	std::string getGuess();
	void UpdateBullCowCount(std::string PlayerGuess);

 private:
	int MyCurrentTry;
	int IsogramLength;
	bool IsIsogram(std::string PlayerGuess);
	static const int NUMBER_OF_TURNS = 2;
	std::string HiddenWord;
	FBullCowCount BullCowCount; 

};

#endif // BULL_COW_GAME_F_BULL_COW_GAME_H_
