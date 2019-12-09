 

#include <FBullCowGame.h>

int main() 
{
	FBullCowGame BCGame;
	BCGame.PrintGameIntro();

	bool playAgain = false;

	do {
		BCGame.PlayGame();
		playAgain = BCGame.AskToPlayAgain();
	}
	while(playAgain);

	return 0;
}
