//Keywords II
//CSC215
//Samael Newgate


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>


using namespace std;


int main()
{
	char playAgain;
	int Num = 0;
	const int MAX_WRONG = 10;

	//Display Title of program to user
	cout << "Welcome to Keywords" << endl;
	//Ask the recruit to login using thier name
	//Hold the recruit's name in a var, and address them by it throughout the simulation.
	cout << "Enter your Name: " << endl;
	string login; //This string stores the users name
	cin >> login;
	//Display an overview of what Keywords II is to the recruit 
	cout << "Hello recruit " << login << endl;
	cout << "Keywords is a code breaker training simulation program!\n";
	//Display an directions to the recruit on how to use Keywords
	cout << "\n\nThe way Keywords works is simple.";
	cout << " You will have 10 attempts to guess 3 words.";
	cout << " Good luck recruit!\n";

	//Create a collection of 10 words you had wrote down manually
	vector <string> words;
	words.push_back("ASSET");
	words.push_back("BIRDWATCHER");
	words.push_back("BLOWBACK");
	words.push_back("BURNED");
	words.push_back("CIPHER");
	words.push_back("CLEAN");
	words.push_back("COMPROMISED");
	words.push_back("CONTROLLED");
	words.push_back("COVER");
	words.push_back("EXPATS");

	do
	{
		//Increment the number of simiulations ran counter
		Num++;
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		//Pick 3 new random words from your collection as the secret code word the recruit has to guess. 
		//The list was already shuffled with the vector function random_shuffle, so we just choose the first 3 words from that list instead of creating a list to hold the 3 words randomly selected.
		for (int i = 0; i < 3; ++i)
		{	//Word to guess
			const string WORD = words[i];
			//Number of incorrect guesses
			int wrong = 0;
			//Word guessed so far
			string soFar(WORD.size(), '-');
			//Letters already guessed
			string used = "";

			//Recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while ((wrong < MAX_WRONG) && (soFar != WORD))
			{
				//Display the simulation # is staring to the recruit. 
				cout << "\n\n-------------------------------" << endl;
				cout << "This is simulation #" << Num << endl;
				cout << "-------------------------------" << endl;
				//Tell recruit how many incorrect guesses he or she has left
				cout << "-------------------------------" << endl;
				cout << "You have " << (MAX_WRONG - wrong) << " tries remaining.\n";
				cout << "-------------------------------" << endl;
				//Show recruit the letters he or she has guessed
				cout << "\nYou've used the following letters:\n" << used << endl;
				//Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;
				//Get recruit's next guess

				char guess;
				cout << "\n\nEnter your guess: ";
				cin >> guess;
				//Make uppercase since our secret words in uppercase
				guess = toupper(guess);

				//While recruit has entered a letter that he or she has already guessed
				while (used.find(guess) != string::npos)
				{
					//Get recruit ’s guess
					cout << "\nYou've already guessed " << guess << endl;
					cout << "Enter your guess: ";
					cin >> guess;
					guess = toupper(guess);
				}
				//Add the new guess to the group of used letters
				used += guess;
				//If the guess is in the secret word
				if (WORD.find(guess) != string::npos)
				{
					//Tell the recruit the guess is correct
					cout << "That's correct recruit " << login << " " << guess << " is in the word.\n";

					//Update soFar to include newly guessed letter
					for (unsigned int i = 0; i < WORD.length(); ++i)
					{
						if (WORD[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				//Otherwise
				else
				{
					//Tell the recruit the guess is incorrect
					cout << "Wrong, " << login << " " << guess << " isn't in the word.\n";
					//Increment the number of incorrect guesses the recruit has made
					++wrong;
				}
			}

			//If the recruit has made too many incorrect guesses
			if (wrong == MAX_WRONG)
				//Tell the recruit that he or she has failed the Keywords II course.
				cout << login << "\nYou've failed the simulation!";
			//Otherwise
			else
				//Congratulate the recruit on guessing the secret words
				cout << "\nCongratulations recruit " << login << ", you have guessed the correct word!";

			cout << "\nThe word was " << WORD << endl;
		}
		//Ask the recruit if they would like to run the simulation again
		cout << login << "Would you like to run the simulation again? Y/N";
		cin >> playAgain;
		playAgain = toupper(playAgain);
		//If the recruit wants to run the simulation again
		//Move program execution back up to 
		//Display the simulation # is staring to the recruit. 
		//Otherwise 
		//Display End of Simulations to the recruit
		//The above 4 comments are all taken care of with this one Do While loop.
	} while (playAgain == 'Y');

	//Pauses the code at the end to see results instead of instantly closing
	system("pause");

	return 0;
}