/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* int_pntr) 
{
	int input;
	int i = 1;

	do 
	{
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

	do 
	{
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
	do
	{
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
	do 
	{
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
	do
	{
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
	do 
	{
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

	//returning the struct
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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* convertResultToKg)
{
	double lbsToKg = (*pounds) / POUNDSTOKG;

	if (convertResultToKg != NULL)
	{
		*convertResultToKg = lbsToKg;
	}

	return lbsToKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* convertResultToG)
{
	int lbsToG = ((*pounds) / POUNDSTOKG) * 1000;

	if (convertResultToG != NULL)
	{
		*convertResultToG = lbsToG;
	}

	return lbsToG;
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* convertResultToKg, int* convertResultToG)
{
	double lbsToKg = (*pounds) / POUNDSTOKG;
	int lbsToG = ((*pounds) / POUNDSTOKG) * 1000;

	if (convertResultToG != NULL && convertResultToKg != NULL)
	{
		*convertResultToG = lbsToG;
		*convertResultToKg = lbsToKg;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalG, double* numberOfservings)
{
	double servings = ((double) totalG) / servingSizeG;

	if (numberOfservings != NULL)
	{
		*numberOfservings = servings;
	}

	return servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* numberOfservings, double* result)
{
	double costPerServ = (*price) / (*numberOfservings);

	if (result != NULL)
	{
		*result = costPerServ;
	}

	return costPerServ;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCalories, double* result)
{
	double costPerCal = (*price) / (*totalCalories);

	if (result != NULL)
	{
		*result = costPerCal;
	}

	return costPerCal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cfi)
{
	struct ReportData rd;

	//assigning Values
	rd.skuNumber = cfi.skuNumber;
	rd.product_price = cfi.product_price;
	rd.prodWghtlbs = cfi.product_weight;
	rd.calories = cfi.calories;
	
	//assigning calculated values
	rd.prodWghtKg = convertLbsKg(&rd.prodWghtlbs, &rd.prodWghtKg);
	rd.prodWghtG = convertLbsG(&rd.prodWghtlbs, &rd.prodWghtG);
	rd.servings = calculateServings(GRAMS_NUMBER, rd.prodWghtG, &rd.servings);

	//total calories
	double totalCalories = rd.calories * rd.servings;

	rd.costPerServ = calculateCostPerServing(&rd.product_price, &rd.servings, &rd.costPerServ);
	rd.costcaloriesPerServ = calculateCostPerCal(&rd.product_price, &totalCalories, &rd.costcaloriesPerServ);
	

	//returning the struct
	return rd;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_NUMBER);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rd, const int cheapestProductCheck)
{	
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rd.skuNumber, rd.product_price, rd.prodWghtlbs, rd.prodWghtKg, rd.prodWghtG, rd.calories, rd.servings, rd.costPerServ, rd.costcaloriesPerServ);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cfi)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n\n", cfi.skuNumber, cfi.product_price);

	// Ending line
	printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start (void)
{
	// Struct Arrays
	struct ReportData rd[MAX_PRODUCTS] = { {0} };
	struct CatFoodInfo cfi[MAX_PRODUCTS] = { {0} };

	// Declaring variables
	int i, cheapestIndex = 0;

	// Printing the opening message
	openingMessage(MAX_PRODUCTS);
 
	// Filling the cfi array
	for (i = 0; i < MAX_PRODUCTS; i++) {
		cfi[i] = getCatFoodInfo(i);
		rd[i] = calculateReportData(cfi[i]);
	}

	// Dsiplaying cat food header
	displayCatFoodHeader();

	// Displaying cat food data
	for (i = 0; i < MAX_PRODUCTS; i++) {
		displayCatFoodData(cfi[i].skuNumber, &cfi[i].product_price, cfi[i].calories, &cfi[i].product_weight); 
	}

	// Determining the cheapest product's sku and price
	double cheapestProdPrice = rd[0].costPerServ;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (rd[i].costPerServ <= cheapestProdPrice)
		{
			cheapestProdPrice = rd[i].costPerServ;
			cheapestIndex = i;
		}
	}
	printf("\n");

	// Displaying the report header
	displayReportHeader();

	// Displaying the report data
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayReportData(rd[i], cheapestIndex);

		if (cheapestIndex == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	// Displaying final analysis
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (i == cheapestIndex)
		{
			displayFinalAnalysis(cfi[i]);
		}
	}

}
