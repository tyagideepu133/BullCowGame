#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame();

	int getMaxTries() const;
	int getCurrentTries() const;
	bool isGameWon() const;

	void reset();
	bool CheckGuessValidity(std::string);


private:
	int MyMaxTries;
	int MyCurrentTry;

};
