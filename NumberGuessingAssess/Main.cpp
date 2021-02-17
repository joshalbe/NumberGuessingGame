#include <iostream>

//Declare the initial variables
bool guessedIt = false;
int maxGuess = 100;
int minGuess = 0;
int previousGuess;

//function which does the calculations to determine the system's next guess
int guessingCalculation(int prevGuess)
{
	//if it's the first turn and there are no previous guesses
	if (!prevGuess) {
		//guess 50 and record 50 as the previous guess
		previousGuess = 50;
		return 50;
	}
	else {
		//otherwise, do the calculation as normal
		int calc = minGuess + ((maxGuess - minGuess) / 2);
		//and return the result as the guess
		return calc;
	}
}

//function checking whether the player is lying
bool checkLiar()
{
	//if the minimum guess is equal to or greater than the max guess
	if (minGuess >= maxGuess)
	{
		//return that the player's lying about their number
		return true;
	}
	else
	{
		//otherwise, return that they're not lying
		return false;
	}
}

//function which holds all the menial tasks around guessing numbers
void guess(int guessNum)
{
	//give the top text, to remind the player of the commands utilized during play
	std::cout << "If the number guessed is correct, type 'Y'" << std::endl;
	std::cout << "If the number is incorrect, then type 'L' for the bot to guess lower, or 'H' for it to guess higher." << std::endl;
	//as well as give the current guess from the system
	std::cout << "Is your number " << guessNum << "?" << std::endl;

	bool correctInput = false;
	//while the correct input has not been used
	while (!correctInput)
	{
		char input;
		//retrieve the command input from the player
		std::cin >> input;
		switch (input)
		{
			//when the player says that "yes" the guess is correct
		case 'Y':
			//mark the guess and the input as correct
			guessedIt = true;
			correctInput = true;
			break;
			//When the player says the system needs to guess "lower"
		case 'L':
			//first check if the player is lying
			switch (checkLiar())
			{
				//if they are indeed lying
			case true:
				system("cls");
				//tell them they've been detected to be lying
				std::cout << "I see through the lies of the Jedi!" << std::endl;
				std::cin;
				//mark the guess and the input as correct
				guessedIt = true;
				correctInput = true;
				break;
				//if they aren't lying
			case false:
				//adjust the field from which the system is guessing by lowering the maximum
				maxGuess = guessNum - 1;
				//mark the input as correct
				correctInput = true;
				break;
			}
			break;
			//when the player says the system needs to guess "higher"
		case 'H':
			//first check if the player is lying
			switch (checkLiar())
			{
				//if they are indeed lying
			case true:
				system("cls");
				//tell them they've been detected to be lying
				std::cout << "I see through the lies of the Jedi!" << std::endl;
				std::cin;
				//mark the guess and the input as correct
				guessedIt = true;
				correctInput = true;
				break;
				//if they aren't lying
			case false:
				//adjust the field from which the system is guessing by lowering the maximum
				minGuess = guessNum + 1;
				//mark the input as correct
				correctInput = true;
				break;
			}
			break;
		}
	}
}

//the game's skeleton
int main()
{
	//Introductory text
	std::cout << "Think of a number between 1 and 100." << std::endl;
	std::cout << "If the number guessed is correct, type 'Y'" << std::endl;
	std::cout << "If the number is incorrect, then type 'L' for the bot to guess lower, or 'H' for it to guess higher." << std::endl;
	system("pause");

	//main game loop
	//while the system hasn't guessed the number, continue the game
	while (!guessedIt)
	{
		//clear the game screen each round to reduce clutter
		system("cls");
		//the function initiating the guesses
		guess(guessingCalculation(previousGuess));
	}

	//Upon the end of the program, let the user know
	std::cout << "Game Over" << std::endl;
	system("pause");
}