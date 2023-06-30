/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : KOJO ANYANE OBESE
Student ID#: 137653226
Email      : kaobese@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int numApples, numOranges, numPears, numTomatoes, numCabbages, contShopping = 1;
int applesPicked, orangesPicked, pearsPicked, tomatoesPicked, cabbagesPicked;
int applesLeft, orangesLeft, pearsLeft, tomatoesLeft, cabbagesLeft;

int main(void)
{   while (contShopping == 1)
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        //For Apples
        printf("How many APPLES do you need? : ");
        scanf("%d", &numApples);

        while (numApples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &numApples);
        }
            printf("\n");

        //For Oranges
        printf("How many ORANGES do you need? : ");
        scanf("%d", &numOranges);

        while (numOranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");
            scanf("%d", &numOranges);
        }
            printf("\n");

        //For Pears
        printf("How many PEARS do you need? : ");
        scanf("%d", &numPears);

        while (numPears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");
            scanf("%d", &numPears);
        }
            printf("\n");


        //For Tomatoes
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &numTomatoes);

        while (numTomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &numTomatoes);
        }
            printf("\n");

        //For Cabbages
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &numCabbages);

        while (numCabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &numCabbages);
        }
            printf("\n");


        //Picking the groceries
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        applesLeft = numApples, orangesLeft = numOranges, pearsLeft = numPears, tomatoesLeft = numTomatoes, cabbagesLeft = numCabbages;
            //Apples
        while (numApples > 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &applesPicked);

            if (applesPicked > applesLeft)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", applesLeft);
            }
            else if (applesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((applesPicked > 0) && (applesPicked < applesLeft))
            {
                printf("Looks like we still need some APPLES...\n");
                applesLeft = applesLeft - applesPicked;
            }
            else if (applesPicked == applesLeft)
            {
                printf("Great, that's the apples done!\n\n");
                break;
            }
        }

                //Oranges
        while (numOranges > 0)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &orangesPicked);

            if (orangesPicked > orangesLeft)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", orangesLeft);
            }
            else if (orangesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((orangesPicked > 0) && (orangesPicked < orangesLeft))
            {
                printf("Looks like we still need some ORANGES...\n");
                orangesLeft = orangesLeft - orangesPicked;
            }
            else if (orangesPicked == orangesLeft)
            {
                printf("Great, that's the oranges done!\n\n");
                break;
            }
        }
                //Pears
        while (numPears > 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pearsPicked);

            if (pearsPicked > numPears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pearsLeft);
            }
            else if (pearsPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((pearsPicked > 0) && (pearsPicked < pearsLeft))
            {
                printf("Looks like we still need some PEARS...\n");
                pearsLeft = pearsLeft - pearsPicked;
            }
            else if (pearsPicked == pearsLeft)
            {
                printf("Great, that's the pears done!\n\n");
                break;
            }
        }
                //Tomatoes
        while (numTomatoes > 0)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomatoesPicked);

            if (tomatoesPicked > numTomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoesLeft);
            }
            else if (tomatoesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((tomatoesPicked > 0) && (tomatoesPicked < tomatoesLeft))
            {
                printf("Looks like we still need some TOMATOES...\n");
                tomatoesLeft = tomatoesLeft - tomatoesPicked;
            }
            else if (tomatoesPicked == tomatoesLeft)
            {
                printf("Great, that's the tomatoes done!\n\n");
                break;
            }
        }

                //Cabbages
        while (numCabbages > 0)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &cabbagesPicked);

            if (cabbagesPicked > cabbagesLeft)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbagesLeft);
            }
            else if (cabbagesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((cabbagesPicked > 0) && (cabbagesPicked < cabbagesLeft))
            {
                printf("Looks like we still need some CABBAGES...\n");
                cabbagesLeft = cabbagesLeft - cabbagesPicked;
            }
            else if (cabbagesPicked == cabbagesLeft)
            {
                printf("Great, that's the cabbages done!\n\n");
                break;
            }

        }

        printf("All the items are picked!\n\n");

        printf("Do another shopping? (0=NO): ");
        scanf("%d", &contShopping);
        printf("\n");    

    }

    printf("Your tasks are done for today - enjoy your free time!\n");
    
    return 0;
}