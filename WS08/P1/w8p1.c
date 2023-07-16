/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : KOJO ANYANE OBESE
Student ID#: 137653226
Email      : KAOBESE@MYSENECA.CA
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* int_pntr) 
{
	int input;
	int i = 1;

    do {
		scanf("%d", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			i = 0;
		}
	} while (i);

	if (int_pntr != NULL)
	{
		*int_pntr = input;
	}
	return input;
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* double_pntr)
{
	double input;
	int i = 1;

	do {
		scanf("%lf", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			i = 0;
		}
	} while (i);

	if (double_pntr != NULL)
	{
		*double_pntr = input;
	}
	return input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int seqNumber) 
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n\n", GRAMS_NUMBER);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqNumber)
{
	struct CatFoodInfo cfi;
	int i;
	printf("Cat Food Product #%d\n", seqNumber + 1);
	printf("--------------------\n");
	i = 1;

	// SKU
	printf("SKU           : ");
	i = 1;
	do {
		scanf("%d", &cfi.skuNumber);
		if (cfi.skuNumber <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			i = 0;
		} 
	} while (i);

    //price
    printf("PRICE         : $");
	i = 1;
	do {
		scanf("%lf", &cfi.product_price);
		if (cfi.product_price <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			i = 0;
		} 
	} while (i);

    //weight
    printf("WEIGHT (LBS)  : ");
	i = 1;
	do {
		scanf("%lf", &cfi.product_weight);
		if (cfi.product_weight <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			i = 0;
		} 
	} while (i);

    //calories
    printf("CALORIES/SERV.: ");
	i = 1;
	do {
		scanf("%d", &cfi.calories);
		if (cfi.calories <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			i = 0;
		} 
	} while (i);

	printf("\n");

	// returning the struct
	return cfi;

}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku_Number, double* product_Price, int calorie_perserving, double* product_weightlbs) 
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_Number, *product_Price, *product_weightlbs, calorie_perserving);
}

// 7. Logic entry point
void start(void)
{
	int j;
	struct CatFoodInfo cfi[MAX_PRODUCTS] = { {0} };
	openingMessage(MAX_PRODUCTS);

	for (j = 0; j < MAX_PRODUCTS; j++)
    {
		cfi[j] = getCatFoodInfo(j);
	}

	displayCatFoodHeader();

	for (j = 0; j < MAX_PRODUCTS; j++)
    {
		displayCatFoodData(cfi[j].skuNumber, &cfi[j].product_price, cfi[j].calories, &cfi[j].product_weight); 
	}

}