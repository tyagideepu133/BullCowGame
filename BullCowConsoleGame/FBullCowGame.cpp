#pragma once
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	myMaxTries = 5;
	myCurrentTry = 1;
	myHiddenWord = "planet";
	gameWon = false;
}


int FBullCowGame::getMaxTries() const
{
	return myMaxTries;
}

int FBullCowGame::getCurrentTries() const
{
	return myCurrentTry;
}

int32 FBullCowGame::getWordLength() const
{
	return myHiddenWord.length();
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	myMaxTries = MAX_TRIES;
	myHiddenWord = HIDDEN_WORD;
	myCurrentTry = 1;

}

WordStatus FBullCowGame::checkGuessValidity(FString)
{
	if (false) // check if guess isn't an isogram
	{
		return WordStatus::NOT_ISOGRAM;
	}
	else if (false) // check if all letter is not lowercase
	{
		return WordStatus::NOT_LOWERCASE;
	}
	else if (false) // check if guess length is wrong
	{
		return WordStatus::WORD_LENGTH_UNEQUAL;
	}
	else
	{
		return WordStatus::OK;
	}
}

// recives a valid guess, increment turn, and returns count
BullCowCount FBullCowGame::submitGuess(FString guess)
{
	// incriment the turn number
	myCurrentTry++;

	// setup a return variable
	BullCowCount bullCowCount;

	int32 wordLength = getWordLength();
	// loop through all letters int the guess
	for (int32 hWord = 0; hWord < wordLength; hWord++)
	{
		for (int32 cWord = 0; cWord < wordLength; cWord++)
		{
			// compare letter against the hidden word
			if (myHiddenWord[hWord] == guess[cWord]){

				if (hWord == cWord) {
					// incriment bulls
					bullCowCount.bulls++;
				}	
				else {
					bullCowCount.cows++;
				}
			}
		}
	}

	if (bullCowCount.bulls == wordLength)
	{
		gameWon = true;
	}
	else {
		gameWon = false;
	}
				
	return bullCowCount;
}
