/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3

const int JAN = 1, DEC = 12;
int MM, YYYY, i = 1, j;
float morningrate, eveningrate, morningrateSUM = 0, eveningrateSUM = 0;

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
           

            
            for (j = 1; j <= LOG_DAYS; j++)
            {
                switch (MM)
                {
                case 1 : 
                    printf("%d-JAN-0%d\n", YYYY, j);
                    break;
                case 2 : 
                    printf("%d-FEB-0%d\n", YYYY, j);
                    break;
                case 3 : 
                    printf("%d-MAR-0%d\n", YYYY, j);
                    break;
                case 4 : 
                    printf("%d-APR-0%d\n", YYYY, j);
                    break;
                case 5 : 
                    printf("%d-MAY-0%d\n", YYYY, j);
                    break;
                case 6 : 
                    printf("%d-JUN-0%d\n", YYYY, j);
                    break;
                case 7 : 
                    printf("%d-JUL-0%d\n", YYYY, j);
                    break;
                case 8 : 
                    printf("%d-AUG-0%d\n", YYYY, j);
                    break;
                case 9 : 
                    printf("%d-SEP-0%d\n", YYYY, j);
                    break;
                case 10 : 
                    printf("%d-OCT-0%d\n", YYYY, j);
                    break;
                case 11 : 
                    printf("%d-NOV-0%d\n", YYYY, j);
                    break;
                case 12 : 
                    printf("%d-DEC-0%d\n", YYYY, j);
                    break;
        
                }
        
                printf("   Morning rating (0.0-5.0): ");
                scanf("%f", &morningrate);

                while ((morningrate < 0.0) || (morningrate > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%f", &morningrate);
                }

                printf("   Evening rating (0.0-5.0): ");
                scanf("%f", &eveningrate);

                while ((eveningrate < 0.0) || (eveningrate > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &eveningrate);
                }
                morningrateSUM += morningrate;
                eveningrateSUM += eveningrate;
                printf("\n");
            }
         i = 0;
        }   
    } 

    printf("Summary\n");
    printf("=======\n");

    printf("Morning total rating: %.3f\n", morningrateSUM);
    printf("Evening total rating:  %.3f\n", eveningrateSUM);
    printf("----------------------------\n");
    printf("Overall total rating: %.3f\n\n", morningrateSUM + eveningrateSUM);

    printf("Average morning rating:  %.1f\n", morningrateSUM / LOG_DAYS);
    printf("Average evening rating:  %.1f\n", eveningrateSUM / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1f\n", ((morningrateSUM / LOG_DAYS) + (eveningrateSUM / LOG_DAYS)) / 2);
    

    return 0;


}