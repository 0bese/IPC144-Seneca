/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : KOJO ANYANE OBESE
Student ID#: 137653226
Email      : KAOBESE@MYSENECA.CA
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

//Macros declared
#define MAXIMUM_PATH_LENGTH 70
#define MINIMUM_PATH_LENGTH 10
#define MAXIMUM_LIVES 10
#define MINIMUM_LIVES 1
#define MULTPLES 5

#include <stdio.h>

//Creating user defined data type for player info
struct playerinfo
{
    int lives;
    char playersymbol;
    int numTreasure;
    int positionhist[MAXIMUM_PATH_LENGTH];
};

struct gameinfo
{
    int max_moves;
    int pathLength;
    int bombSpot[MAXIMUM_PATH_LENGTH];
    int treasureSpot[MAXIMUM_PATH_LENGTH]; 
};

int main(void)
{
    //declaring variables for loops
    int i, j, k;
    int remaniningMoves, remainingLives, movePosition = MAXIMUM_PATH_LENGTH + 1;

    //allocating memory for player and game
    struct playerinfo player;
    struct gameinfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    //player configuration
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playersymbol);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        if (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }

    } while (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES);

    printf("Player configuration set-up is complete\n\n");

    // game configuration
    printf("GAME Configuration\n");
    printf("------------------\n");
    
    //path length
    do 
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);

        if ((game.pathLength < MINIMUM_PATH_LENGTH || game.pathLength > MAXIMUM_PATH_LENGTH) || (game.pathLength % MULTPLES != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }

    } while ((game.pathLength < MINIMUM_PATH_LENGTH || game.pathLength > MAXIMUM_PATH_LENGTH) || (game.pathLength % MULTPLES != 0));

    //number of moves
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.max_moves);

        if (game.max_moves < player.lives || game.max_moves > (int)(0.75 * game.pathLength))
        {
            printf("    Value must be between %d and %d\n", player.lives, (int)(0.75 * game.pathLength));
        }
    } while(game.max_moves < player.lives || game.max_moves > (int)(0.75 * game.pathLength));

    printf("\n");

    // bomb placement in array
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    // prompt for bomb placement
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombSpot[i], &game.bombSpot[i + 1], &game.bombSpot[i +2], &game.bombSpot[i + 3], &game.bombSpot[i + 4]);
    }
    printf("BOMB placement set\n\n");


    // treasure placement in array
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    //prompt for treasure placement
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i +5);
        scanf("%d %d %d %d %d", &game.treasureSpot[i], &game.treasureSpot[i + 1], &game.treasureSpot[i +2], &game.treasureSpot[i +3], &game.treasureSpot[i + 4]);
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    // player details
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.playersymbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    // game details
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    // displaying from bomb array
    for (j = 0; j < game.pathLength; j++)
    {
        printf("%d", game.bombSpot[j]);
    }
    printf("\n");

    printf("   Treasure   : ");
    // displaying from treasure array
    for (k = 0; k < game.pathLength; k++)
    {
        printf("%d", game.treasureSpot[k]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    //Assigning values
    remainingLives = player.lives;
    remaniningMoves = game.max_moves;
    player.numTreasure = 0;
    int vCount = 0;

    char currentSpot[MAXIMUM_PATH_LENGTH];
    char spotItem[MAXIMUM_PATH_LENGTH];

    for (j = 0; j < game.pathLength; j++)
    {
        player.positionhist[j] = 0;
    }

    for (k = 0; k < game.pathLength; k++)
    {
        spotItem[k] = '-';
    }

    for (k = 0; k < game.pathLength; k++)
    {
        currentSpot[k] = ' ';
    }

    //Printing the table
    do
    {
        //for the first line 
        for (k = 0; k < game.pathLength; k++)
        {
            if (currentSpot[k] == 'V')
            {
                vCount++;
            }
        }
        if (vCount == 0)
        {
            printf("\n");
        }
        else
        {
            printf("  ");
            for (k = 0; k < game.pathLength; k++)
            {
                if (currentSpot[k] == 'V')
                {
                    printf("%c\n", currentSpot[k]);
                    break;
                }
                else
                {
                    printf("%c", currentSpot[k]);
                }

            }

        }

        //Tracking current positions demands that previous pointer disappears
        for (k = 0; k < game.pathLength; k++)
        {
            currentSpot[k] = ' ';
        }

            //for second line
        printf("  ");
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%c", spotItem[k]);
        }
        printf("\n");

        //for third line
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (int)i / 10);
            }
            else
            {
                printf("|");
            }
        
        }
        printf("\n");

        //for fourth line
        printf("  ");
        for(i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");

        //Displaying Player statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", remainingLives, player.numTreasure, remaniningMoves);
        printf("+---------------------------------------------------+\n");

        //to quit loop if the remaining lives = 0
        if (remainingLives == 0)
        {
            break;
        }

        //to quit loop if the remaining moves = 0
        if (remaniningMoves == 0)
        {
            break;
        }

        //Determining the next move
        do
        {
            printf("Next Move [1-20]: ");
            scanf("%d", &movePosition);
            
            if (movePosition < 1 || movePosition > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }

        } while (movePosition < 1 || movePosition > game.pathLength);
        printf("\n");

        if (player.positionhist[movePosition - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n\n");
            currentSpot[movePosition - 1] = 'V';
            remaniningMoves++;
        }

        else if (game.bombSpot[movePosition - 1] == 1 && game.treasureSpot[movePosition - 1] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            spotItem[movePosition - 1] = '&';
            currentSpot[movePosition - 1] = 'V';
            remainingLives--;
            player.numTreasure++;
        }

        else if (game.bombSpot[movePosition - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            spotItem[movePosition - 1] = '!';
            currentSpot[movePosition - 1] = 'V';
            remainingLives--;
        }

        else if (game.treasureSpot[movePosition - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            spotItem[movePosition - 1] = '$';
            currentSpot[movePosition - 1] = 'V';
            player.numTreasure++;
        }

        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            spotItem[movePosition - 1] = '.';
            currentSpot[movePosition - 1] = 'V';
        }

        //storing position in history array
        player.positionhist[movePosition - 1] = 1;

        //Decrementing the number of moves left
        remaniningMoves--;

        if (remainingLives == 0)
        {
            printf("No more LIVES remaining!\n\n");
        }
        if (remaniningMoves == 0)
        {
            printf("No more MOVES remaining!\n\n");
        }

    } while (remaniningMoves >= 0 && remainingLives >= 0);
    printf("\n");

    //Printing final table

    //End
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n\n");

    return 0;
}