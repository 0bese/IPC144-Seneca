/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>
#include <ctype.h>
#include "core.h"


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// -- TEST 01 -- User input an integer

int inputInt(void)
{
    char character = ' ';
    int value;

    do
    {
        scanf("%d%c", &value, &character);

        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (character != '\n');

    // If the character after the integer is a new line character that means an appropriate value was entered
    return value;
}

// -- TEST 02 -- User input a positive integer

int inputIntPositive(void)
{
    char character = ' ';
    int value;

    do
    {
        scanf("%d%c", &value, &character);

        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }

    } while (character != '\n' || value <= 0);


    return value;

}


// -- TEST 03 & 04 -- User input a integer that is between two numbers
int inputIntRange(int lowerBound, int upperBound)
{
    int value;

    do
    {
        value = inputInt();

        if (value < lowerBound || value >  upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }

    } while (value < lowerBound || value >  upperBound);

    return value;
}

// -- Test 05 -- User input a character
char inputCharOption(const char str[])
{
    
    char option[100];
    int i, validateChar = 0;

    do
    {
        // get character / characters

        fgets(option, 100, stdin);
        if (strlen(option) == 2)
        {
            // Verify each possible option
            for (i = 0; str[i] != '\0' && validateChar == 0; i++)
            {

                // if letter is equal to one of them means that the input is correct
                if (option[0] == str[i])
                {
                    validateChar++;
                }
            }
        }

        // no char match with the letter ingresed
        if (validateChar == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", str);
        }

    } while (validateChar == 0);

 

    return option[0];
}

// -- TEST 06 & 07 & 08 -- User input a string in a range of length
void inputCString(char* cStr, int min_char, int max_char)
{
    // flag
    int done = 1;
    // get char
    char ch = 'x';

    do
    {
        int len = 0;

        // while the char is not a new line AND length is not more that the max length...
        while (ch != '\n' && len <= max_char)
        {
            ch = getchar();
            cStr[len] = ch;
            len++;
        }


        // We need to add '\0' in the array, so we need to add it OR REPLACE the last char if it is full 
        // check if there is space 
        if (ch == '\n' && len <= (max_char + 1))
        {
            len--;
            cStr[len] = '\0';
        }
        else
        {
            // if not, replace the last char to '\0' and we remove the extra char clearing the buffer 
            cStr[max_char] = '\0';
            clearInputBuffer();
        }



        /*
        with the above logic we get:
        -The lenght of the string ingresed: len;
        -The string to return it;

        NOW VALIDATE
        */


        // check if is exactly
        if (min_char == max_char && len != min_char)
        {
            printf("Invalid 10-digit number! Number: ");
            ch = 'x';

        }
        // check if is more than max_char
        else if (len > max_char)
        {
            printf("ERROR: String length must be no more than %d chars: ", max_char);
            ch = 'x';
        }
        // check if is between the range
        else if (len < min_char || len > max_char)
        {
            printf("ERROR: String length must be between %d and %d chars: ", min_char, max_char);
            ch = 'x';
        }
        else
        {
            done = 0;
        }


    } while (done);
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////


// -- TEST 09 -- Function displayFormattedPhone
void displayFormattedPhone(const char* phoneNum)
{
    int i, numbers = 0, isNotNumber = 0;

    if (phoneNum != NULL)
    {
        // Get every char and indentify if is number
        for (i = 0; phoneNum[i] != '\0'; i++)
        {

            if (phoneNum[i] >= '0' && phoneNum[i] <= '9')
            {
                numbers++;
            }
            else
            {
                isNotNumber++;
            }
        }
        if (numbers == 10 && isNotNumber == 0)
        {
            printf("(");
            for (i = 0; i < 3; i++)
            {
                printf("%c", phoneNum[i]);
            }
            printf(")");
            for (i = 3; i < 6; i++)
            {
                printf("%c", phoneNum[i]);
            }
            printf("-");
            for (i = 6; i < 10; i++)
            {
                printf("%c", phoneNum[i]);
            }
        }
        else
        {
            printf("(___)___-____");

        }

    }
    else
    {
        printf("(___)___-____");

    }

}