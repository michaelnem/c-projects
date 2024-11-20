#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

#define TIE 0
#define PLAYER_WINS 1
#define COMPUTER_WINS 2

int gameV1(int, int);
int gameV2(int, int);

int tests(){
    int tests[9][3] = {
        {1, 1, TIE},             // Rock vs Rock -> Tie
        {1, 2, COMPUTER_WINS},   // Rock vs Paper -> Computer wins
        {1, 3, PLAYER_WINS},     // Rock vs Scissors -> Player wins
        {2, 1, PLAYER_WINS},     // Paper vs Rock -> Player wins
        {2, 2, TIE},             // Paper vs Paper -> Tie
        {2, 3, COMPUTER_WINS},   // Paper vs Scissors -> Computer wins
        {3, 1, COMPUTER_WINS},   // Scissors vs Rock -> Computer wins
        {3, 2, PLAYER_WINS},     // Scissors vs Paper -> Player wins
        {3, 3, TIE}              // Scissors vs Scissors -> Tie
    };

    int failedTests = 0;
    
    printf("** Test using V1, multiple comparisons **\n");
    // Loop through the test table
    for (int i = 0; i < 9; i++) {
        int player = tests[i][0];
        int computer = tests[i][1];
        int expected = tests[i][2];

        // Check if the calculation matches the expected result
        if (gameV1(player, computer) != expected) {
            printf("Test failed for: Player = %d, Computer = %d\n", player, computer);
        } else {
            printf("Test passed for: Player = %d, Computer = %d\n", player, computer);
        }
    }
    if (failedTests > 0){
        printf("\nTotal failed tests: %d, test suite FAILED\n\n", failedTests);
    }
    
    failedTests = 0;
    printf("** Test using V2, modulus **\n");
    // Loop through the test table
    for (int i = 0; i < 9; i++) {
        int player = tests[i][0];
        int computer = tests[i][1];
        int expected = tests[i][2];

        // Check if the calculation matches the expected result
        if (gameV2(player, computer) != expected) {
            printf("Test failed for: Player = %d, Computer = %d\n", player, computer);
        } else {
            printf("Test passed for: Player = %d, Computer = %d\n", player, computer);
        }
    }
    if (failedTests > 0){
        printf("\nTotal failed tests: %d, test suite FAILED\n\n", failedTests);
    }
    
}

int gameV1(int player, int computer)
{
    if (player == computer)
    {
        return 0;
    }
    else if (player == 1 && computer == 3 || player == 2 && computer == 1 || player == 3 && computer == 1)
    {
        return 1; // player win
    }
    return 2;
}

int gameV2(int player, int computer)
{
    if (player == computer) {
        return 0;
    } else if ((player - computer + 3) % 3 == 1) {
        return 1;
    } else {
        return 2;
    }
}
