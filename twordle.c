//Author: Sarah Schoener
//Date: 4/20/2026
//Purpose: Project 10

#include<stdio.h>

#define CAP 12
#define LENGTH 6
#define COLM 6
#define MYSTERY "mystery.txt"

void getGuessFunction(char word[], int i);
int wordCountFunction(char Gword[], int wordCount);
int checkFunction(int Wordcount, char Gword[], char Rword[], int SIZE, int match);
void capCaratfunction(char word[], char real[], int SIZE, char carot[]);
void enteredFunction(char Gword[], char carot[], int CSIZE, char results[][CSIZE], int guess);
void printEnteredFunction(int CSIZE, char results[][CSIZE], int guess);
void finalGuessFunction(char Gword[]);
void youWONFunction(int SIZE, char Rword[], int guess);

int main()
{
	char Results[CAP][COLM];
	char Rword[LENGTH], Gword[LENGTH], carot[LENGTH];
	int guess = 0;
	int wordcount = 0; 
	int match = 0;
	int i; 
	FILE* fp;
	fp = fopen (MYSTERY, "r");
	if(fp == NULL)
	{
		printf("Could not open file\n");
		return 0;
	}
	fscanf(fp, "%s", Rword);
	fclose(fp);
	for( i = 0; i < LENGTH; i++)
	{
		if(i == 5)
		{
			wordcount = 0;
			finalGuessFunction(Gword);
			wordcount = wordCountFunction(Gword, wordcount);
			match = 0;
			break;
		}
		getGuessFunction(Gword, i);
		wordcount = 0; 
		wordcount = wordCountFunction(Gword, wordcount);
		match = 0;
		match = checkFunction(wordcount, Gword, Rword, LENGTH, match);
		
		
		if(match == 1)
		{	guess = 1 + i; 
			youWONFunction(LENGTH, Rword, guess);
			break;
		}
		capCaratfunction(Gword, Rword, LENGTH, carot);
		
		enteredFunction(Gword, carot, COLM, Results, i);
		printEnteredFunction(COLM, Results, i);
	}
	if(i == 5)
	{
		match = checkFunction(wordcount, Gword, Rword, LENGTH, match);
		if(match == 1)
		{
			guess = 6;
			youWONFunction(LENGTH, Rword, guess);
		}
		else
		{
			guess = 0;
			youWONFunction(LENGTH, Rword, guess);
		}
	}
	return 0;	
}
void getGuessFunction(char word[], int i)
{
	printf("GUESS %d! Enter your guess: ", i+1);
	scanf("%s", word);
}
int wordCountFunction(char Gword[], int wordCount)
{
	for(int i = 0; Gword[i] != '\0'; i++)
	{
		wordCount = wordCount + 1;
	}
	return wordCount;
}
int checkFunction(int Wordcount, char Gword[], char Rword[], int SIZE, int match)
{
	while(Wordcount != 5)
	{
		printf("Your guess must be 5 letters long.\n");
		printf("Please try again: ");
		scanf("%s", Gword);
		Wordcount = 0;
		for(int i = 0; Gword[i] != '\0'; i++)
		{
			Wordcount = Wordcount + 1;
		}	
	}
	for(int i = 0; i < SIZE; i++)
	{
		if(Rword[i] == Gword[i])
		{
			match = 1;
			
		}
		else
		{
			match = 0;
			break;
			
		}
	}
	return match;
}
void capCaratfunction(char word[], char real[], int SIZE, char carot[])
{
	for(int i = 0; i < SIZE-1; i++)
	{
		if (word[i]==real[i])
		{
			word[i] -= 'a' - 'A';
		}	
		for(int j = 0; j < SIZE-1; j++)
		{
			if(word[i] == real[j])
			{
				carot[i] = '^';
			}
			else
			{
				carot[i] = ' ';
			}
		}
		//printf("%s", carot);
	} 
}
void enteredFunction(char Gword[], char carot[], int CSIZE, char results[][CSIZE], int guess)
{
	for(int j = 0; j < CSIZE; j++)
	{
			
		results[guess*2][j] = Gword[j];
		results[(guess*2)+1][j]= carot[j];
	}
		
}
void printEnteredFunction(int CSIZE, char results[][CSIZE], int guess)
{
	for(int i = 0; i < guess*2+2; i++)
	{
		for(int j = 0; j < CSIZE; j++)
		{
			printf("%c", results[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void finalGuessFunction(char Gword[])
{
	printf("FINAL GUESS: ");
	scanf("%s", Gword);
}
void youWONFunction(int SIZE, char Rword[], int guess)
{
	for(int i = 0; i < SIZE; i++)
	{
		Rword[i] -= 'a' - 'A';
	}
	if(guess == 1)
	{
		printf("       %5s\n", Rword);
		printf("You won in 1 guess!\n");
		printf("GOATED");
	}
	else if(guess == 2 || guess == 3)
	{
		printf("        %5s\n", Rword);
		printf("You won in %d guesses!\n", guess);
		printf("Amazing");
	}
	else if(guess == 4 || guess == 5)
	{
		printf("        %5s\n", Rword);
		printf("You won in %d guesses!\n", guess);
		printf("Nice");
	}
	else if(guess == 6)
	{
		printf("        %5s\n", Rword);
		printf("You won in %d guesses!\n", guess);
	}
	else 
	{
		printf("You lost, better luck next time!\n");
	}
}






































