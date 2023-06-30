/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char cof1_type, cof2_type, cof3_type;
    int cbag1_wt, cbag2_wt, cbag3_wt, ndailysvgs;
    char cof1crm_ncrm, cof2crm_ncrm, cof3crm_ncrm;
    double cbag1_lbs, cbag2_lbs, cbag3_lbs;
    char cofstrgth, cofcrm_ncrm;


    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf( " %c", &cof1_type);
    printf("Bag weight (g): ");
    scanf("%d", &cbag1_wt);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf( " %c", &cof1crm_ncrm);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf( " %c", &cof2_type);
    printf("Bag weight (g): ");
    scanf("%d", &cbag2_wt);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cof2crm_ncrm);
    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &cof3_type);
    printf("Bag weight (g): ");
    scanf("%d", &cbag3_wt);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cof3crm_ncrm);
    printf("\n");

    //Converting from grams to lbs
    cbag1_lbs = cbag1_wt / GRAMS_IN_LBS;
    cbag2_lbs = cbag2_wt / GRAMS_IN_LBS;
    cbag3_lbs = cbag3_wt / GRAMS_IN_LBS;


    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (cof1_type == 'L' || cof1_type == 'l'), (cof1_type == 'M' || cof1_type == 'm'), (cof1_type == 'R' || cof1_type == 'r'), (cbag1_wt), (cbag1_lbs), (cof1crm_ncrm == 'Y' || cof1crm_ncrm == 'y')); 
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (cof2_type == 'L' || cof2_type == 'l'), (cof2_type == 'M' || cof2_type == 'm'), (cof2_type == 'R' || cof2_type == 'r'), (cbag2_wt), (cbag2_lbs), (cof2crm_ncrm == 'Y' || cof2crm_ncrm == 'y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (cof3_type == 'L' || cof3_type == 'l'), (cof3_type == 'M' || cof3_type == 'm'), (cof3_type == 'R' || cof3_type == 'r'), (cbag3_wt), (cbag3_lbs), (cof3crm_ncrm == 'Y' || cof3crm_ncrm == 'y'));
    printf("\n");
    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &cofstrgth);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cofcrm_ncrm);
    printf("Typical number of daily servings: ");
    scanf("%d", &ndailysvgs);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (((cof1_type == 'L' || cof1_type == 'l') && (cofstrgth == 'L'|| cofstrgth =='l'))) || (((cof1_type == 'M' || cof1_type == 'm') && (cofstrgth == 'M' || cofstrgth == 'm')) || ((cof1_type == 'R' || cof1_type == 'r') && (cofstrgth == 'R' || cofstrgth == 'r'))), (((ndailysvgs >= 1 && ndailysvgs <= 4) && (cbag1_wt >= 0 && cbag1_wt <= 250)) || ((ndailysvgs > 4 && ndailysvgs < 10) && (cbag1_wt > 250 && cbag1_wt <= 500)) || ((ndailysvgs >= 10) && (cbag1_wt >= 1000))), (((cof1crm_ncrm == 'Y' || cof1crm_ncrm == 'y') && (cofcrm_ncrm == 'Y' || cofcrm_ncrm == 'y'))) || ((cof1crm_ncrm == 'N' || cof1crm_ncrm == 'n') && (cofcrm_ncrm == 'N' || cofcrm_ncrm == 'n')));
    printf(" 2|       %d         |      %d      |   %d   |\n", (((cof2_type == 'L' || cof2_type == 'l') && (cofstrgth == 'L'|| cofstrgth =='l'))) || (((cof2_type == 'M' || cof2_type == 'm') && (cofstrgth == 'M' || cofstrgth == 'm')) || ((cof2_type == 'R' || cof2_type == 'r') && (cofstrgth == 'R' || cofstrgth == 'r'))), (((ndailysvgs >= 1 && ndailysvgs <= 4) && (cbag2_wt >= 0 && cbag2_wt <= 250)) || ((ndailysvgs > 4 && ndailysvgs < 10) && (cbag2_wt > 250 && cbag2_wt <= 500)) || ((ndailysvgs >= 10) && (cbag2_wt >= 1000))), (((cof2crm_ncrm == 'Y' || cof2crm_ncrm == 'y') && (cofcrm_ncrm == 'Y' || cofcrm_ncrm == 'y'))) || ((cof2crm_ncrm == 'N' || cof2crm_ncrm == 'n') && (cofcrm_ncrm == 'N' || cofcrm_ncrm == 'n')));
    printf(" 3|       %d         |      %d      |   %d   |\n", (((cof3_type == 'L' || cof3_type == 'l') && (cofstrgth == 'L'|| cofstrgth =='l'))) || (((cof3_type == 'M' || cof3_type == 'm') && (cofstrgth == 'M' || cofstrgth == 'm')) || ((cof3_type == 'R' || cof3_type == 'r') && (cofstrgth == 'R' || cofstrgth == 'r'))), (((ndailysvgs >= 1 && ndailysvgs <= 4) && (cbag3_wt >= 0 && cbag3_wt <= 250)) || ((ndailysvgs > 4 && ndailysvgs < 10) && (cbag3_wt > 250 && cbag3_wt <= 500)) || ((ndailysvgs >= 10) && (cbag3_wt >= 1000))), (((cof3crm_ncrm == 'Y' || cof3crm_ncrm == 'y') && (cofcrm_ncrm == 'Y' || cofcrm_ncrm == 'y'))) || ((cof3crm_ncrm == 'N' || cof3crm_ncrm == 'n') && (cofcrm_ncrm == 'N' || cofcrm_ncrm == 'n')));
    printf("\n");

    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &cofstrgth);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cofcrm_ncrm);
    printf("Typical number of daily servings: ");
    scanf("%d", &ndailysvgs);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (((cof1_type == 'L' || cof1_type == 'l') && (cofstrgth == 'L'|| cofstrgth =='l'))) || (((cof1_type == 'M' || cof1_type == 'm') && (cofstrgth == 'M' || cofstrgth == 'm')) || ((cof1_type == 'R' || cof1_type == 'r') && (cofstrgth == 'R' || cofstrgth == 'r'))), (((ndailysvgs >= 1 && ndailysvgs <= 4) && (cbag1_wt >= 0 && cbag1_wt <= 250)) || ((ndailysvgs > 4 && ndailysvgs < 10) && (cbag1_wt > 250 && cbag1_wt <= 500)) || ((ndailysvgs >= 10) && (cbag1_wt >= 1000))), (((cof1crm_ncrm == 'Y' || cof1crm_ncrm == 'y') && (cofcrm_ncrm == 'Y' || cofcrm_ncrm == 'y'))) || ((cof1crm_ncrm == 'N' || cof1crm_ncrm == 'n') && (cofcrm_ncrm == 'N' || cofcrm_ncrm == 'n')));
    printf(" 2|       %d         |      %d      |   %d   |\n", (((cof2_type == 'L' || cof2_type == 'l') && (cofstrgth == 'L'|| cofstrgth =='l'))) || (((cof2_type == 'M' || cof2_type == 'm') && (cofstrgth == 'M' || cofstrgth == 'm')) || ((cof2_type == 'R' || cof2_type == 'r') && (cofstrgth == 'R' || cofstrgth == 'r'))), (((ndailysvgs >= 1 && ndailysvgs <= 4) && (cbag2_wt >= 0 && cbag2_wt <= 250)) || ((ndailysvgs > 4 && ndailysvgs < 10) && (cbag2_wt > 250 && cbag2_wt <= 500)) || ((ndailysvgs >= 10) && (cbag2_wt >= 1000))), (((cof2crm_ncrm == 'Y' || cof2crm_ncrm == 'y') && (cofcrm_ncrm == 'Y' || cofcrm_ncrm == 'y'))) || ((cof2crm_ncrm == 'N' || cof2crm_ncrm == 'n') && (cofcrm_ncrm == 'N' || cofcrm_ncrm == 'n')));
    printf(" 3|       %d         |      %d      |   %d   |\n", (((cof3_type == 'L' || cof3_type == 'l') && (cofstrgth == 'L'|| cofstrgth =='l'))) || (((cof3_type == 'M' || cof3_type == 'm') && (cofstrgth == 'M' || cofstrgth == 'm')) || ((cof3_type == 'R' || cof3_type == 'r') && (cofstrgth == 'R' || cofstrgth == 'r'))), (((ndailysvgs >= 1 && ndailysvgs <= 4) && (cbag3_wt >= 0 && cbag3_wt <= 250)) || ((ndailysvgs > 4 && ndailysvgs < 10) && (cbag3_wt > 250 && cbag3_wt <= 500)) || ((ndailysvgs >= 10) && (cbag3_wt >= 1000))), (((cof3crm_ncrm == 'Y' || cof3crm_ncrm == 'y') && (cofcrm_ncrm == 'Y' || cofcrm_ncrm == 'y'))) || ((cof3crm_ncrm == 'N' || cof3crm_ncrm == 'n') && (cofcrm_ncrm == 'N' || cofcrm_ncrm == 'n')));
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");












    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/