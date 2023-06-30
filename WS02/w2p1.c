/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
int main(void)
{
    const double TAX = 0.13;
    const char pattySize = 'S';
    double sShirtprice, mShirtprice, lShirtprice;
    int nShirts, taxes, actualtotal, SUBtotal;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &sShirtprice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mShirtprice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &lShirtprice);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", sShirtprice);
    printf("MEDIUM : $%.2lf\n", mShirtprice);
    printf("LARGE  : $%.2lf\n\n", lShirtprice);

    printf("Patty's shirt size is \'%c\'\n", pattySize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &nShirts);
    printf("\n");

    //calc
    SUBtotal = sShirtprice * nShirts * 100;
    taxes = SUBtotal * TAX + 0.5;
    actualtotal = SUBtotal + taxes;

    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", nShirts);
    printf("Sub-total: $%8.4lf\n", (double) SUBtotal / 100);
    printf("Taxes    : $%8.4lf\n", (double) taxes / 100);
    printf("Total    : $%8.4lf\n", (double) actualtotal / 100);


    return 0;
}