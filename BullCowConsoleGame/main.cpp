#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void printIntro();
std::string getGuess();
bool askToPlayAgain();
void playGame();

FBullCowGame fBullCowGame; // Inisating new game

int main() {
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
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulding cows Game" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	 return;
}


std::string getGuess() {
	std::string guess = "";
	int currentTry = fBullCowGame.getCurrentTries();
	std::cout << "Try " << currentTry <<" Enter your Guess : ";
	std::getline(std::cin, guess);
	return guess;
}

bool askToPlayAgain() {
	std::cout << "Do you want to play again(Y/N)? ";
	std::string response = "";
	std::getline(std::cin, response);
	return ((response[0] == 'Y') || (response[0] == 'y'));
}

void playGame() {
	fBullCowGame.reset();
	int maxTries = fBullCowGame.getMaxTries();
	std::cout << maxTries << std::endl;
	for (int i = 0; i < maxTries; i++)
	{
		std::string guess = getGuess();
		std::cout << "Your guess is : " << guess << std::endl;
		std::cout << std::endl;
	}
}