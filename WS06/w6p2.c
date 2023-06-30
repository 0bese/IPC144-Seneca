/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
double netMonthly_inc, totalCost = 0;
int num_wishlistItems, i, j, selection, iterate = 1;
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

    for (j = 1; j<= num_wishlistItems; j++)
    {
        printf("  %d      %d        %c     %10.2lf\n", j, priority[j - 1], financeOptions[j - 1], cost[j - 1]);
        totalCost += cost[j - 1];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $ %10.2lf\n\n", totalCost);

    
    //displaying menu with three options
    

    do
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");

        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");

    //declaring variables
    int priority_filter, k, item, note = 0;
    double priorityItemCost = 0, months, years, remainMonths; 
    
        if (selection == 0)
        {
            iterate = 0;
        }

        else if (selection == 1)
        {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost);

            //calculating the months and years
            months = (totalCost / netMonthly_inc) + 0.5; // to round it up
            years = ((int)months) / 12;
            remainMonths = (months - (years * 12)) + 0.5; // to round it up

            printf("Forecast: %d years, %d months\n", (int)years, (int)remainMonths);

            //checking if 'y' exists in financeOptions array 
            note = 0;
            for (item = 0; item < num_wishlistItems; item++)
            {
                if (financeOptions[item] == 'y') 
                {
                    note += 1;
                }
            }

            if (note != 0)
            {
                printf("NOTE: Financing options are available on some items.\n");    
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");
        }

        else if ( selection == 2)
        {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &priority_filter);
            printf("\n");

            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priority_filter);
            for (k = 0; k < num_wishlistItems; k++)
            {
                if (priority[k] == priority_filter) 
                {
                    priorityItemCost += cost[k];
                }
            }

            //calculating the months and years
            months = (priorityItemCost / netMonthly_inc) + 0.5; //to round it up
            years = ((int)months) / 12;
            remainMonths = (months - (years * 12)) + 0.5; // to round it up

            printf("Amount:   $%.2lf\n", priorityItemCost);
            printf("Forecast: %d years, %d months\n", (int)years, (int)remainMonths);

            //checking if 'y' exists in financeOptions array
            note = 0;
            for (item = 0; item < num_wishlistItems; item++)
            {
                if (financeOptions[item] == 'y' && priority[item] == priority_filter) 
                {
                    note += 1;
                }
            }

            if (note != 0)
            {
                printf("NOTE: Financing options are available on some items.\n");    
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");
        }   

        else if (selection < 0 || selection > 2) 
        {
            printf("ERROR: Invalid menu selection.\n\n");
        }
    }
    while (iterate == 1);

    //displaying ending note
    printf("Best of luck in all your future endeavours!\n");

    
    return 0;
}