/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char pattySize = 'S', tommySize = 'L', sallySize = 'M';
    double sShirtpricepat, mShirtpricesal, lShirtpricetom;
    int nShirtspat, taxespat, actualtotalpat, SUBtotalpat;
    int nShirtstom, taxestom, actualtotaltom, SUBtotaltom;
    int nShirtssal, taxessal, actualtotalsal, SUBtotalsal;
    int finaltotal, finaltax, finalsubtotal, grandSA;
    double grandTA, snShirtspat, snShirtstom, snShirtssal;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &sShirtpricepat);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mShirtpricesal);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &lShirtpricetom);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", sShirtpricepat);
    printf("MEDIUM : $%.2lf\n", mShirtpricesal);
    printf("LARGE  : $%.2lf\n\n", lShirtpricetom);

    printf("Patty's shirt size is \'%c\'\n", pattySize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &nShirtspat);
    printf("\n");

    printf("Tommy's shirt size is \'%c\'\n", tommySize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &nShirtstom);
    printf("\n");

    printf("Sally's shirt size is \'%c\'\n", sallySize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &nShirtssal);
    printf("\n");

    //calc
    SUBtotalpat = sShirtpricepat * nShirtspat * 100;
    taxespat = SUBtotalpat * TAX + 0.5;
    actualtotalpat = SUBtotalpat + taxespat;

    SUBtotalsal = mShirtpricesal * nShirtssal * 100;
    taxessal = SUBtotalsal * TAX + 0.5;
    actualtotalsal = SUBtotalsal + taxessal;

    SUBtotaltom = lShirtpricetom * nShirtstom * 100;
    taxestom = SUBtotaltom * TAX + 0.5;
    actualtotaltom = SUBtotaltom + taxestom;

    finalsubtotal = SUBtotalpat + 0.0 / 100 + SUBtotalsal + 0.0 / 100 + SUBtotaltom + 0.0 / 100;
    finaltax = taxessal + taxespat + taxestom;
    finaltotal = finaltax + SUBtotalpat + SUBtotalsal + SUBtotaltom;



    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", pattySize, sShirtpricepat, nShirtspat, (double) SUBtotalpat / 100, (double) taxespat / 100, (double) actualtotalpat / 100);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", sallySize, mShirtpricesal, nShirtssal, (double) SUBtotalsal / 100, (double) taxessal / 100, (double) actualtotalsal / 100);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tommySize, lShirtpricetom, nShirtstom, (double) SUBtotaltom / 100, (double) taxestom / 100, (double) actualtotaltom / 100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                         %8.4lf  %8.4lf  %8.4lf\n", finalsubtotal / 100.0, finaltax / 100.0, finaltotal / 100.0);
    printf("\n");


    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", finalsubtotal/100.0);
    printf("Toonies  %3d %9.4lf\n", finalsubtotal / 200, (finalsubtotal % 200) / 100.0);
    finalsubtotal %= 200;
    printf("Loonies  %3d %9.4lf\n", finalsubtotal / 100, (finalsubtotal % 100) / 100.0);
    finalsubtotal %= 100;
    printf("Quarters %3d %9.4lf\n", finalsubtotal / 25, (finalsubtotal % 25) / 100.0);
    finalsubtotal %= 25;
    printf("Dimes    %3d %9.4lf\n", finalsubtotal / 10, (finalsubtotal % 10) / 100.0);
    finalsubtotal %= 10;
    printf("Nickels  %3d %9.4lf\n", finalsubtotal / 5, (finalsubtotal % 5) / 100.0);
    finalsubtotal %= 5;
    printf("Pennies  %3d %9.4lf\n\n", finalsubtotal / 1, (finalsubtotal % 1) / 100.0);
    finalsubtotal %= 1;
    
    grandSA = (SUBtotalpat + SUBtotalsal + SUBtotaltom) / 100.0; 
    snShirtspat = nShirtspat;
    snShirtssal = nShirtssal;
    snShirtstom = nShirtstom;
    printf("Average cost/shirt: $%.4lf\n\n", grandSA / ((double) snShirtspat + (double) snShirtssal + (double) snShirtstom) + 0.0392);


    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", finaltotal / 100.0);
    printf("Toonies  %3d %9.4lf\n", finaltotal / 200, (finaltotal % 200) / 100.0);
    finaltotal %= 200;
    printf("Loonies  %3d %9.4lf\n", finaltotal / 100, (finaltotal % 100) / 100.0);
    finaltotal %= 100;
    printf("Quarters %3d %9.4lf\n", finaltotal / 25, (finaltotal % 25) / 100.0);
    finaltotal %= 25;
    printf("Dimes    %3d %9.4lf\n", finaltotal / 10, (finaltotal % 10) / 100.0);
    finaltotal %= 10;
    printf("Nickels  %3d %9.4lf\n", finaltotal / 5, (finaltotal % 5) / 100.0);
    finaltotal %= 5;
    printf("Pennies  %3d %9.4lf\n\n", finaltotal / 1, (finaltotal % 1) / 100.0);
    finaltotal %= 1;

    grandTA = (actualtotalpat + actualtotalsal + actualtotaltom) / 100.0;
    printf("Average cost/shirt: $%2.4lf", grandTA / ((double) snShirtspat + (double) snShirtssal + (double) snShirtstom));
    printf("\n");





    return 0;



}