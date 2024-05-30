#include<stdio.h> /*Includes the input and output related functions in the program*/
int main() /*Main function*/
{
	int secretNumber = 123; /*Variable of the secret number which is "123"*/
	int playerNumber; /*Variable of the entered number of the player*/
	int guessCount=5; /*Variable of the number of guesses the player has*/
	int outOfGuesses=0; /*Variable that turns to 1 when the player runs out of guesses*/
	printf("I have a secret number.");
	while(playerNumber != secretNumber && outOfGuesses==0) /*Loop that allows the player to guess the secret number until they run out of guesses.*/
	{
		if(guessCount>0) /*Executes until number of guesses reaches 0.*/
		{
			printf("\n\nGuess the number: "); /*Asks the player to guess the computer's secret number*/
			scanf("%d",&playerNumber); /*Scans the number of the player*/
			guessCount--; /*Deducts the number of guess the player has*/
			if(playerNumber>secretNumber) /*Executes when the player's number is higher than the secret number*/
			{
				printf("You guessed too high.\n"); /*Tells the player their number is too high*/
				printf("You get %d more tries\n",guessCount); /*Tells the player their remaining number of tries*/
			}
			else if(playerNumber<secretNumber) /*Executes when the player's number is lower than the secret number*/
			{
				printf("You guessed too low\n"); /*Tells the player their number is too low*/
				printf("You get %d more tries\n",guessCount); /*Tells the player their remaining number of tries*/
			}
		}
		else /*Executes when the number of guesses reaches 0.*/
		{
			outOfGuesses=1; /*Variable turns to 1.*/
		}
	}
	if(outOfGuesses==1) /*Executes when Variable turns to 1.*/
	{
		printf("Sorry you got no more chances"); /*Tells the player they lost and they have no more chances.*/
	}
	else /*Executes when the player guesses the secret number*/
	{
		printf("You are Correct!"); /*Tells the player they guessed the secret number correctly.*/
	}
	return 0; /*Program is executed successfully and terminates*/
}
