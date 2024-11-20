#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int game(int, int);

char *choiceToGameMove(int);

int main()
{
    srand(time(NULL));

    int computerChoice, playerChoice;
    computerChoice = (rand() % 3) + 1;

    printf("Choose: 1 - %s | 2 - %s | 3 - %s: ", choiceToGameMove(ROCK), choiceToGameMove(PAPER), choiceToGameMove(SCISSORS));

    int scanStatusResult = scanf("%d", &playerChoice);
    if (scanStatusResult != 1 || playerChoice < ROCK || playerChoice > SCISSORS)
    {
        fprintf(stderr, "\nWrong Input: Usage: 1, 2 or 3\n\n");
        return 1;
    }

    printf("Battle: (player - %s) VS (computer - %s)\n", choiceToGameMove(playerChoice), choiceToGameMove(computerChoice));

    int winState = game(playerChoice, computerChoice); // -1 tie, 0 computer win, 1 player
    printf("\n");
    if (winState == 0)
    {
        printf("A Tie!");
    }
    else if (winState == 1)
    {
        printf("You Win!");
    }
    else
    {
        printf("Ohhhh You Lose.... Try again!");
    }

    printf("\n\n");

    return 0;
}

int game(int player, int computer)
{
    if (player == computer) {
        return 0;
    } else if ((player - computer + 3) % 3 == 1) {
        // player wins
        return 1;
    } else {
        // computer wins
        return 2;
    }
}

char *choiceToGameMove(int choice)
{
    switch (choice)
    {
    case 1:
        return "Rock";
    case 2:
        return "Paper";
    case 3:
        return "Scissors";
    }
}