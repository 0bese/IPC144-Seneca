
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : KOJO ANYANE OBESE
Student ID#: 137653226
Email      : kaobese@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ITEMS 10
#include <stdio.h>

//declaring variables
double netMonthly_inc;
int num_wishlistItems;
const double min_cost = 100.00;

int main(void)
{
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    //taking user net income
    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netMonthly_inc);

        if(netMonthly_inc < 500.00)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        } 
        
        if (netMonthly_inc > 400000.00)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }

        printf("\n");

    }while(!(netMonthly_inc >= 500.00 && netMonthly_inc <= 400000.00));
    
    //taking wishlist items quantity to forecast
    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &num_wishlistItems);

        if (num_wishlistItems <= 0 || num_wishlistItems > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        
        printf("\n");
    }
    while(!(num_wishlistItems > 0 && num_wishlistItems <= 10));

    //declaring arrays
    double cost[num_wishlistItems];
    int priority[num_wishlistItems];
    char financeOptions[num_wishlistItems];


    //displaying item details with loop
    int i;
    for (i = 1; i <= num_wishlistItems; i++)
    {
        printf("Item-%d Details:\n", i);

        //for cost
        do 
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i - 1]);

            if (cost[i - 1] < min_cost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } 
        while (cost[i - 1] < min_cost);

        //for priority
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i - 1]);

            if ((priority[i - 1] < 1) || (priority[i - 1] > 3))
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }
        while ((priority[1 - 1] < 1) || (priority[i - 1] > 3));

        //for financing options
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOptions[i - 1]);

            if (!(financeOptions[i - 1] == 'n' || financeOptions[i - 1] == 'y'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }

        }
        while (!(financeOptions[i - 1] == 'n' || financeOptions[i - 1] == 'y'));

        printf("\n");
    }

    //for summary table head
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    //displaying details with iterations
    int j;
    double totalCost = 0;

    for (j = 1; j<= num_wishlistItems; j++)
    {
        printf("  %d      %d        %c     %10.2lf\n", j, priority[j - 1], financeOptions[j - 1], cost[j - 1]);
        totalCost += cost[j - 1];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n\n", totalCost);

    //end text
    printf("Best of luck in all your future endeavours!\n\n");


    return 0;
}