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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define GRAMS_NUMBER 64
#define POUNDSTOKG 2.20462


// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int skuNumber;
    double product_price;
    int calories;
    double product_weight;
};

struct ReportData
{
    int skuNumber;
    double product_price;
    int calories;
    double prodWghtlbs;
    double prodWghtKg;
    int prodWghtG;
    double servings;
    double costPerServ;
    double costcaloriesPerServ;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int*);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double*);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int, double*, int, double*);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* pounds, double* convertResultToKg);

// 9. convert lbs: g
int convertLbsG(const double* pounds, int* convertResultToG);

// 10. convert lbs: kg / g
void convertLbs(const double* pounds, double* convertResultToKg, int* convertResultToG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalG, double* numberOfservings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* numberOfservings, double* result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double* result);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cfi);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rd, const int cheapestProductCheck);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cfi);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start (void);
