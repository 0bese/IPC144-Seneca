/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022

const int JAN = 1, DEC = 12;
int MM, YYYY, i = 1;

int main(void)
{
    printf("General Well-being Log\n");
    printf("======================\n");
    
    while (i == 1)
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &YYYY, &MM );

        if((YYYY < MIN_YEAR) || (YYYY > MAX_YEAR))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (MM < JAN || MM > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        if ((YYYY >= MIN_YEAR && YYYY <= MAX_YEAR) && (MM >= JAN && MM <= DEC))
        {
            printf("\n*** Log date set! ***\n\n");
            printf("Log starting date: ");

            switch (MM)
            {
            case 1 : 
                printf("%d-JAN-01\n", YYYY);
                break;
            case 2 : 
                printf("%d-FEB-01\n", YYYY);
                break;
            case 3 : 
                printf("%d-MAR-01\n", YYYY);
                break;
            case 4 : 
                printf("%d-APR-01\n", YYYY);
                break;
            case 5 : 
                printf("%d-MAY-01\n", YYYY);
                break;
            case 6 : 
                printf("%d-JUN-01\n", YYYY);
                break;
            case 7 : 
                printf("%d-JUL-01\n", YYYY);
                break;
            case 8 : 
                printf("%d-AUG-01\n", YYYY);
                break;
            case 9 : 
                printf("%d-SEP-01\n", YYYY);
                break;
            case 10 : 
                printf("%d-OCT-01\n", YYYY);
                break;
            case 11 : 
                printf("%d-NOV-01\n", YYYY);
                break;
            case 12 : 
                printf("%d-DEC-01\n", YYYY);
                break;
            }
         i = 0;
        }   
       
    } 

    return 0;
}