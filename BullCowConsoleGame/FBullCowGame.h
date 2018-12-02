#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount {
	int32 bulls = 0;
	int32 cows = 0;
};

enum class WordStatus {
	INVALID_STATE,
	WORD_LENGTH_UNEQUAL,
	NOT_ISOGRAM,
	NOT_LOWERCASE,
	OK
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor 

	int32 getMaxTries() const;
	int32 getCurrentTries() const;
	int32 getWordLength() const;
	bool isGameWon() const;

	void reset(); // TODO make a more rich return value
	WordStatus checkGuessValidity(FString); // TODO make a more rich return value
	
	// for counting bulls & cows, increasing try # assuming valid guess
	BullCowCount submitGuess(FString);

private:
	// see constructor for initialisation
	int32 myMaxTries;
	int32 myCurrentTry;
	FString myHiddenWord;
	bool gameWon;
};
