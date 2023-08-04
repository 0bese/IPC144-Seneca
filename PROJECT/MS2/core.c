/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

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

// This function guarantees that an integer value is entered and returned. If an invalid value is entered, an error message would be displayed.
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
    }
    while (character != '\n');

    // If the character after the integer is a new line character that means an appropriate value was entered
    return value;
}

// This function guarantees a positive integer value is entered and returned. If a zero or a negative value in entered, an error message would be displayed.
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
            printf("Error! Input a number: ");
        }

        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    }
    while (value <= 0);

    // After checks are completed we can return the value
    return value;
}

// This function guarantees that an integer value is entered within the range (inclusive) and returned. If a value from outside the range is entered, display an error message and continue to prompt until a value in the given range is entered.
int inputIntRange(int lower_bound, int upper_bound)
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

        else if (!(value <= upper_bound && value >= lower_bound))
        {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
    }
    while (!(value <= upper_bound && value >= lower_bound));

    // After checks are completed we can return the value
    return value;
}

// This function guarantees a single character value is entered within the list of valid characters and returned. If an entered character is not in the list of valid characters, display an error message and prompt again.
char inputCharOption(const char string[])
{
    int i, count = 0;
    char input;

    do
    {
        scanf(" %c", &input);

        for (i = 0; string[i] != '\0'; i++)
        {
            if (input == string[i])
            {
                count++;
            }
        }

        if (count == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
    } while (count == 0);

    // After all checks are passed we will return the input value
    clearInputBuffer();
    return input;
}

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments.
void inputCString(char* string, int min_char, int max_char)
{
    int flag = 1;
    char char_value = 'a';

    while (flag)
    {
        int length = 0;
        // Takes a string as input until it sees a newline character
        while (char_value != '\n' && length <= max_char)
        {
            char_value = getchar();
            string[length] = char_value;
            length++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (char_value == '\n' && length <= (max_char + 1))
        {
            length--;
            string[length] = '\0';
        }
        // If length is more than max_char, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else
        {
            string[max_char] = '\0';
            clearInputBuffer();
        }

        if (min_char == max_char && length != min_char)
        {
            printf("ERROR: String length must be exactly %d chars: ", min_char);
            char_value = 'a';
        }
        else if (length < min_char || length > max_char)
        {
            if (length > max_char)
            {
                printf("ERROR: String length must be no more than %d chars: ", max_char);
                char_value = 'a';
            }
            else if (length < min_char)
            {
                printf("ERROR: String length must be between %d and %d chars: ", min_char, max_char);
                char_value = 'a';
            }
        }
        else 
        {
            flag = 0;
        }
    }
}

// This function is to display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(const char* string)
{
    int length = 0, i;

    while (string != NULL && string[length] && isdigit(string[length]))
    {
        length++;
    }
    if (length == 10)
    {
        i = 0;
        printf("(");
        while (i < 3)
        {
            printf("%c", string[i]);
            i++;
        }
        printf(")");

        while (i < 6)
        {
            printf("%c", string[i]);
            i++;
        }
        printf("-");

        while (i < 10)
        {
            printf("%c", string[i]);
            i++;
        }
    }
    else
    {
        printf("(___)___-____");
    }
    if (string != 0)
    {
        for (i = 0;string[i] != '\0';i++)
            length++;
    }
}