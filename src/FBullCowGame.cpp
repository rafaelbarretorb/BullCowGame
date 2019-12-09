
#include <FBullCowGame.h>

FBullCowGame::FBullCowGame() 
{
	MyCurrentTry = 0;
	IsogramLength = 6;
	HiddenWord = "planet"; // TODO make a big set of isograms
}

FBullCowGame::~FBullCowGame() {}

void FBullCowGame::PrintGameIntro()
{
	// introduce the game
	constexpr int WORLD_LENGTH = 5;// constant expression
	std::cout << "\n\nWelcome to Bull and Cows!" << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
}

bool FBullCowGame::AskToPlayAgain()
{
	std::cout << "\nDo you want to play again? ";
	std::string Response = "";
	std::getline(std::cin, Response);
  bool UserAnswer = (Response[0] == 'Y' || Response[0] == 'y');

  if (UserAnswer)
	{
	  std::cout << "Yes. Try again!\n";
	}
	else
	{
		std::cout << "No. End of the game. Bye!\n";
	}
	


	return (Response[0] == 'Y' || Response[0] == 'y');
}

std::string FBullCowGame::getGuess()
{
	// get a guess from the player
	std::string Guess = "";
	std::cout << "\nEnter your guess: ";
	std::getline(std::cin, Guess);

	// print Guess
	std::cout << "\nYour guess was: " << Guess << std::endl;

	return Guess;
}


void FBullCowGame::PlayGame()
{
	// loop for the number of turns asking guesses
	int j = 0;

	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		std::string Guess = getGuess();

		std::cout << "Attempt " << GetCurrentTry() << ": " << Guess << std::endl;
		if (!CheckGuessValidity(Guess) && j < 2)
		{ std::cout << j << std::endl; 
			std::cout << "Please, insert a valid guess!. Try again." << std::endl;
		  i--;
			j++;
			MyCurrentTry--;
		}

		
    if (IsGameWon()) {
			std::cout << "Congratulations! You won the game!" << std::endl;
			return;

		}
	}
}

void FBullCowGame::Reset()
{

}


int FBullCowGame::GetMaxTries() const
{
	return NUMBER_OF_TURNS;
}

int FBullCowGame::GetCurrentTry()
{
  MyCurrentTry++;
	if (MyCurrentTry > GetMaxTries())
	  MyCurrentTry = 1;
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon(){

	if (BullCowCount.Bulls == HiddenWord.length() && BullCowCount.Cows == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void FBullCowGame::UpdateBullCowCount(std::string PlayerGuess) {
	BullCowCount.Bulls = 0;
	BullCowCount.Cows = 0;

  
	for (int i = 0; i < PlayerGuess.length(); i++) {
    if (PlayerGuess[i] == HiddenWord[i]) {
			BullCowCount.Bulls++;
		}
		for (int j = 0; j < PlayerGuess.length(); j++) {
			if (PlayerGuess[j] == HiddenWord[i]) {
				BullCowCount.Cows++;
			}
		}
		BullCowCount.Cows = BullCowCount.Cows - BullCowCount.Bulls;
	}


}

bool FBullCowGame::CheckGuessValidity(std::string PlayerGuess)
{
	// TODO check the length of the string
	if (PlayerGuess.length() != HiddenWord.length())
  {
    return false;
  }

	for (int i = 0; i < PlayerGuess.length(); i++)
  {
		if (PlayerGuess[i] != 'a' || PlayerGuess[i] != 'A' ||
		    PlayerGuess[i] != 'b' || PlayerGuess[i] != 'B' ||
				PlayerGuess[i] != 'c' || PlayerGuess[i] != 'C' ||
				PlayerGuess[i] != 'd' || PlayerGuess[i] != 'D' ||
				PlayerGuess[i] != 'e' || PlayerGuess[i] != 'E' ||
				PlayerGuess[i] != 'f' || PlayerGuess[i] != 'F' ||
				PlayerGuess[i] != 'g' || PlayerGuess[i] != 'G' ||
				PlayerGuess[i] != 'h' || PlayerGuess[i] != 'H' ||
				PlayerGuess[i] != 'i' || PlayerGuess[i] != 'I' ||
				PlayerGuess[i] != 'j' || PlayerGuess[i] != 'J' ||
				PlayerGuess[i] != 'k' || PlayerGuess[i] != 'K' ||
				PlayerGuess[i] != 'l' || PlayerGuess[i] != 'L' ||
				PlayerGuess[i] != 'm' || PlayerGuess[i] != 'M' ||
				PlayerGuess[i] != 'n' || PlayerGuess[i] != 'N' ||
				PlayerGuess[i] != 'o' || PlayerGuess[i] != 'O' ||
				PlayerGuess[i] != 'p' || PlayerGuess[i] != 'P' ||
				PlayerGuess[i] != 'q' || PlayerGuess[i] != 'Q' ||
				PlayerGuess[i] != 'r' || PlayerGuess[i] != 'R' ||
				PlayerGuess[i] != 's' || PlayerGuess[i] != 'S' ||
				PlayerGuess[i] != 't' || PlayerGuess[i] != 'T' ||
				PlayerGuess[i] != 'u' || PlayerGuess[i] != 'U' ||
				PlayerGuess[i] != 'v' || PlayerGuess[i] != 'V' ||
				PlayerGuess[i] != 'w' || PlayerGuess[i] != 'W' ||
				PlayerGuess[i] != 'x' || PlayerGuess[i] != 'X' ||
				PlayerGuess[i] != 'y' || PlayerGuess[i] != 'Y' ||
				PlayerGuess[i] != 'z' || PlayerGuess[i] != 'Z')
		{
			return false;
		}		
	}

	// TODO check if is isogram
	if (!IsIsogram(PlayerGuess)) {
		return false;
	}
  return true; 
}

//int FBullCowGame::MyCurrentTry() { return 0; }

bool FBullCowGame::IsIsogram(std::string PlayerGuess){ return false; }