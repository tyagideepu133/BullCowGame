#pragma once
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	MyMaxTries = 5;
	MyCurrentTry = 1;
}


int FBullCowGame::getMaxTries() const
{
	return 0;
}

int FBullCowGame::getCurrentTries() const
{
	return 0;
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

void FBullCowGame::reset()
{
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
