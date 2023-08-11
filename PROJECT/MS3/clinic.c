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

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, record = 0;

    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }
    
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            record = 1;
        }
    }

    if (!record)
    {
        printf("*** No records found ***\n\n");
    }

    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int user_option;

    // Printing menu for user
    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &user_option);
        printf("\n");

        if (user_option == 1)
        {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (user_option == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (user_option != 0);
}


// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i, structSize = 0;
    for (i = 0; i < max; i++)
    {
        //to know number of patients available
        if (patient[i].patientNumber != 0)
        {
            structSize++;
        }
    }
    if (max > structSize)
    {
        patient[structSize].patientNumber = nextPatientNumber(patient, max);
        inputPatient(patient + structSize);
        printf("*** New patient record added ***\n\n");
        clearInputBuffer();
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int patient_number, patientIndex;
    printf("Enter the patient number: ");
    scanf("%d", &patient_number);
    printf("\n");

    if (findPatientIndexByPatientNum(patient_number, patient, max) != -1)
    {
        patientIndex = findPatientIndexByPatientNum(patient_number, patient, max);
        menuPatientEdit(patient + patientIndex);
    }
    else 
    {
        printf("ERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int patient_number, patientIndex;
    char choice;
    printf("Enter the patient number: ");
    scanf("%d", &patient_number);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(patient_number, patient, max) != -1)
    {
        patientIndex = findPatientIndexByPatientNum(patient_number, patient, max);
        printf("Name  : %s\n", patient[patientIndex].name);
        printf("Number: %05d\n", patient[patientIndex].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[patientIndex].phone.number);
        printf(" (%s)\n\n", patient[patientIndex].phone.description);

        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N')
        {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }
        else
        {
            // Assigning patient to safe empty state so that the other function can't access it
            patient[patientIndex].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i, pindex;
    struct Appointment temp[MAX_APPOINTMENTS];
    struct Patient temp2[MAX_PETS];

    sortAllAppointment(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(&temp[0].date, 1);

    for (i = 0; i < MAX_APPOINTMENTS; i++)
    {
        temp[i] = data->appointments[i];
    }

    for (i = 0; i < MAX_PETS; i++)
    {
        temp2[i] = data->patients[i];
    }

    for (i = 0; i < data->maxAppointments && temp[i].patientNumber != 0; i++)
    {
        pindex = findPatientIndexByPatientNum(temp[i].patientNumber, temp2, MAX_PETS);
        displayScheduleData(&temp2[pindex], &temp[i], 1);
    }

    putchar('\n');
}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int i, pindex;
    struct Appointment temp[MAX_APPOINTMENTS];
    struct Patient temp2[MAX_PETS];
    struct Date input;

    for (i = 0; i < MAX_APPOINTMENTS; i++)
    {
        temp[i] = data->appointments[i];
    }

    for (i = 0; i < MAX_PETS; i++)
    {
        temp2[i] = data->patients[i];
    }

    inputDate(&input);

    putchar('\n');

    displayScheduleTableHeader(&input, 0);

    for (i = 0; i < data->maxAppointments && temp[i].patientNumber != 0; i++)
    {
        if (temp[i].date.year == input.year && temp[i].date.month == input.month && temp[i].date.day == input.day)
        {
            pindex = findPatientIndexByPatientNum(temp[i].patientNumber, temp2, MAX_PETS);
            displayScheduleData(&temp2[pindex], &temp[i], 0);
        }
    }

    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointment, const int max_app, struct Patient* patient, const int max_pet)
{
    int i, index, pnumber, pindex = -1, repeat = 0, flag = 0;
    struct Date input_date;
    struct Time input_time;

    index = lastAppointmentIndex(appointment, max_app) + 1;

    if (index != max_app)
    {
        while (pindex == -1)
        {
            printf("Patient Number: ");
            pnumber = inputIntPositive();
            pindex = findPatientIndexByPatientNum(pnumber, patient, max_pet);
            if (pindex == -1) printf("ERROR: Patient record not found!\n");
        }

        while (!flag)
        {
            repeat = 0;
            inputDate(&input_date);
            inputTime(&input_time);
            for (i = 0; i < index; i++)
            {
                if (appointment[i].date.year == input_date.year && appointment[i].date.month == input_date.month && appointment[i].date.day == input_date.day &&
                    appointment[i].time.hour == input_time.hour && appointment[i].time.min == input_time.min) repeat = 1;
            }
            if (repeat) printf("\nERROR: Appointment timeslot is not available!\n\n");
            else flag = 1;
        }

        appointment[index].patientNumber = pnumber;
        appointment[index].date = input_date;
        appointment[index].time = input_time;

        putchar('\n');
        printf("*** Appointment scheduled! ***\n");
        putchar('\n');
    }

    else
    {
        printf("ERROR: Appointment list is FULL!\n\n");
    }
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointment, const int max_app, struct Patient* patient, const int max_pet)
{
    int i, pnumber, pindex = -1, found = 0, selection, lastindex, appindex;
    struct Date input;

    printf("Patient Number: ");
    pnumber = inputIntPositive();
    pindex = findPatientIndexByPatientNum(pnumber, patient, max_pet);

    if (pindex == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    
    else
    {
        inputDate(&input);

        putchar('\n');

        for (i = 0; i < max_app && appointment[i].patientNumber != 0; i++)
        {
            if (appointment[i].patientNumber == pnumber && appointment[i].date.year == input.year && appointment[i].date.month == input.month &&
                appointment[i].date.day == input.day)
            {
                found = 1;
                appindex = i;
            }
        }

        if (!found)
        {
            printf("ERROR: Appointment record not found!\n\n");
        }

        else
        {
            displayPatientData(&patient[pindex], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");
            selection = !(inputCharOption("yn") == 'y');

            if (selection)
            {
                printf("Operation aborted.\n");
            }

            else
            {
                lastindex = lastAppointmentIndex(appointment, max_app);
                appointment[appindex].patientNumber = appointment[lastindex].patientNumber;
                appointment[appindex].date.year = appointment[lastindex].date.year;
                appointment[appindex].date.month = appointment[lastindex].date.month;
                appointment[appindex].date.day = appointment[lastindex].date.day;
                appointment[appindex].time.hour = appointment[lastindex].time.hour;
                appointment[appindex].time.min = appointment[lastindex].time.min;
                appointment[lastindex].patientNumber = 0;
                putchar('\n');
                printf("Appointment record has been removed!\n\n");
            }

        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patient_number, patientIndex;
    printf("Search by patient number: ");
    scanf("%d", &patient_number);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(patient_number, patient, max) != -1)
    {
        patientIndex = findPatientIndexByPatientNum(patient_number, patient, max);
        printf("Name  : %s\n", patient[patientIndex].name);
        printf("Number: %05d\n", patient[patientIndex].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[patientIndex].phone.number);
        printf(" (%s)", patient[patientIndex].phone.description);
        printf("\n\n");
    }

    else
    {
        printf("*** No records found ***\n\n");
    }
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, match = 0;
    char phoneNumber[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    printf("\n");

    displayPatientTableHeader();

    for (i = 0; i < max + 1; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            match++;
        }
    }
    printf("\n");

    if (match == 0) {
        printf("*** No records found ***\n\n");
    }
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int nextNum, maxNum = patient[0].patientNumber, i;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > maxNum)
        {
            maxNum = patient[i].patientNumber;
        }
    }

    nextNum = maxNum + 1;
    return nextNum;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    // Iterate through the array to find the patient number
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }
    // If anything is not found, -1 is returned
    return -1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    int i;
    char name[NAME_LEN];

    // Displaying form to take input
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    fgets(name, sizeof(name), stdin);

    // Storing the name in the struct
    for (i = 0; i < strlen(name) - 1; i++)
    {
        patient->name[i] = name[i];
    }
    
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int choice, i;
    char inputNumber[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {

    case 1:
        // Storing the description in the struct
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);

        // Displaying description
        printf("Contact: %s\n", phone->description);

        // Asking the user for a number as input and storing it in struct
        clearInputBuffer();
        printf("Number : ");
        fgets(inputNumber, sizeof(inputNumber), stdin);

        for (i = 0; i < PHONE_LEN + 1; i++)
        {
            phone->number[i] = inputNumber[i];
        }

        printf("\n");

        break;

    case 2:
        // Storing the description in the struct
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);

        // Displaying description
        printf("Contact: %s\n", phone->description);

        // Asking the user for a number as input and storing it in struct
        clearInputBuffer();
        printf("Number : ");
        fgets(inputNumber, sizeof(inputNumber), stdin);

        for (i = 0; i < PHONE_LEN + 1; i++)
        {
            phone->number[i] = inputNumber[i];
        }

        printf("\n");

        break;

    case 3:
        // Storing the description in the struct
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);

        // Displaying description
        printf("Contact: %s", phone->description);
        printf("\n");

        // Asking the user for a number as input and storing it in struct
        clearInputBuffer();
        printf("Number : ");
        fgets(inputNumber, sizeof(inputNumber), stdin);

        for (i = 0; i < PHONE_LEN + 1; i++)
        {
            phone->number[i] = inputNumber[i];
        }

        printf("\n");

        break;

    case 4:
        // Storing the description in the struct
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);

        *phone->number = 0;

        break;

    default:
        printf("Error:\n");
        break;
    }
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char *datafile, struct Patient patients[], int max)
    {

        FILE *fp = NULL;
        fp = fopen(datafile, "r");
        int read = 0;
        if (fp != NULL)
        {
            while (!feof(fp) && read < max)
            {
                fscanf(fp, "%d|%29[^|]|%4[^|]|", &patients[read].patientNumber, patients[read].name, patients[read].phone.description);

                if (!(strcmp(patients[read].phone.description, "TBD") == 0))
                {
                    fscanf(fp, "%[^\n]%*c", patients[read].phone.number);
                }
                read++;
            }
            fclose(fp);
        }
        return read;
    }

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    FILE* fp = NULL;
    int i, read;

    fp = fopen(datafile, "r");
    read = 0;

    if (fp == NULL)
    {
        printf("Cannot open the file %s\n", datafile);
    }

    else
    {
        i = 0;
        do
        {
            
            fscanf(fp, "%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month,
                &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);

            
            if (appoints[i].patientNumber != 0)
            {
            read++;
            i++;
            }
            
        } while (!feof(fp) && i < max);

        fclose(fp);
    }

    return read;
}