/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : KOJO ANYANE OBESE
Student ID#: 137653226
Email      : kaobese@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    const int prod1_ID = 111;
    const int prod2_ID = 222;
    const int prod3_ID = 111;

    const double prod1_price = 111.49;
    const double prod2_price = 222.99;
    const double prod3_price = 334.49;

    const char prod1_taxed = 'Y';
    const char prod2_taxed = 'N';
    const char prod3_taxed = 'N';

    double avgOfprices = (prod1_price + prod2_price + prod3_price) / 3;

    //OUTPUT
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", prod1_ID);
    printf("  Taxed: %c\n", prod1_taxed);
    printf("  Price: $%.4lf\n\n", prod1_price);

    printf("Product-2 (ID:%d)\n", prod2_ID);
    printf("  Taxed: %c\n", prod2_taxed);
    printf("  Price: $%.4lf\n\n", prod2_price);

    printf("Product-3 (ID:%d)\n", prod3_ID);
    printf("  Taxed: %c\n", prod3_taxed);
    printf("  Price: $%.4lf\n\n", prod3_price);

    

    printf("The average of all prices is: $%.4lf\n\n", avgOfprices);
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", prod1_taxed == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", prod2_taxed && prod3_taxed != 'Y');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, prod3_price < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", prod3_price > prod1_price + prod2_price);
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", prod1_price >= prod3_price - prod2_price, prod3_price - prod2_price);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", prod2_price >= avgOfprices);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", (prod2_ID != prod1_ID) && (prod3_ID != prod1_ID));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", (prod1_ID != prod2_ID) && (prod3_ID != prod2_ID));
    printf("9. Based on product ID, product 3 is unique -> %d\n", (prod1_ID != prod3_ID) && (prod2_ID != prod3_ID));




    return 0;
}