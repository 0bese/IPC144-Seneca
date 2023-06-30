/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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
int iterate_no, n = 1;
char looptype;
int main(void)
{
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do {

        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &looptype, &iterate_no);
            if ((looptype == 'D' || looptype == 'W' || looptype == 'F') && (iterate_no >2 && iterate_no <21))
            {
                switch (looptype)
                {
                    case 'D' : printf("DO-WHILE: ");
                        do {
                            iterate_no--;
                            printf("D");
                        } while (iterate_no > 0);
                         printf("\n\n");
                        break;
                       
                    case 'W' : printf("WHILE   : ");
                        do{
                            iterate_no--;
                            printf("W");
                        }while (iterate_no > 0);
                         printf("\n\n");
                        break;
                    case 'F' : printf("FOR     : ");
                        do {
                            iterate_no--;
                            printf("F");
                        } while (iterate_no > 0);
                         printf("\n\n");
                        break;
                        

                }
                
            }
            else if (looptype == 'Q')
                {
                    if (iterate_no == 0)
                    {
                    n = iterate_no;
                    printf("\n");
                    printf("+--------------------+\n");
                    printf("Loop application ENDED\n");
                    printf("+--------------------+\n\n");
                    }
                    else
                    {
                        printf("ERROR: To quit, the number of iterations should be 0!\n\n");
                    }
                }
            else if ((looptype != 'D' && looptype != 'W' && looptype != 'F' && looptype != 'Q') || (iterate_no < 3 || iterate_no > 20))
                {
                        if ((looptype != 'D' && looptype != 'W' && looptype != 'F' && looptype != 'Q') && (iterate_no < 3 || iterate_no > 20))
                        { 
                        printf("ERROR: Invalid entered value(s)!\n\n");
                        }
                        else if (iterate_no < 3 || iterate_no > 20)
                        {
                            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
                        }
                        else 
                        {
                            printf("ERROR: Invalid entered value(s)!\n\n");
                        }
                }
                
                
    }while (n);
    

    return 0;
}