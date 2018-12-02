/* This is the console executable, that make use of BullCow game
This act as the view in MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/


#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void printIntro();
FText getGuess();
bool askToPlayAgain();
void playGame();
void printGameSummary();

FBullCowGame fBullCowGame; // Inisating new game

// Main Function of start game
int main() {
	// prints intro of game 
	printIntro();
	bool playAgain = false;
	do
	{
		playGame();
		playAgain = askToPlayAgain();
	} while (playAgain);
	return 0;
}

void printIntro() {
	int32 WORD_LENGTH = fBullCowGame.getWordLength();
	std::cout << "Welcome to Bulding cows Game" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;
}


FText getGuess() {
	WordStatus status = WordStatus::INVALID_STATE;
	FText guess = "";
	int32 currentTry = fBullCowGame.getCurrentTries();

	do
	{
		// get a guess from the player
		std::cout << "Try " << currentTry << " Enter your Guess : ";
		std::getline(std::cin, guess);

		status = fBullCowGame.checkGuessValidity(guess);

		switch (status)
		{
		case WordStatus::WORD_LENGTH_UNEQUAL:
			std::cout << "Please enter a " << fBullCowGame.getWordLength() << " letter word." << std::endl;
			break;
		case WordStatus::NOT_ISOGRAM:
			std::cout << "Please enter a word without repating letters." << std::endl;
			break;
		case WordStatus::NOT_LOWERCASE:
			std::cout << "Please enter word in small alphabets." << std::endl;
			break;
		default:
			// Assuming that guess is valid
			break;
		}
		std::cout << std::endl;
	} while (status != WordStatus::OK);

	return guess;
}

bool askToPlayAgain() {
	std::cout << "Do you want to play again(Y/N)? ";
	FText response = "";
	std::getline(std::cin, response);
	return ((response[0] == 'Y') || (response[0] == 'y'));
}

void playGame() {
	fBullCowGame.reset();
	int32 maxTries = fBullCowGame.getMaxTries();
	std::cout << maxTries << std::endl;
	// loop for the number of turns asking for guesses
	// TODO change FOR to WHILE loop once we are validating tries
	while(! fBullCowGame.isGameWon() &&  fBullCowGame.getCurrentTries <= maxTries)
	{
		FText guess = getGuess(); // TODO make loop checking valid guesses
		// submit valid guess to the game
		// print number of bull and cow
		BullCowCount count = fBullCowGame.submitGuess(guess);

		std::cout << "Bulls:  " << count.bulls << "  Cows: " << count.cows << std::endl;
		std::cout << std::endl;
	}

	printGameSummary();
	// TODO summarise game
}

void printGameSummary()
{
	if (fBullCowGame.isGameWon)
	{
		std::cout << "Well Done - You Won" << std::endl;
	}
	else {
		std::cout << "Have a better luck next time" << std::endl;
	}
}
