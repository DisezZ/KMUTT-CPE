#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hospital.h"
#include "validations.h"
#include "filehandling.h"

void handleDisplayAll()
{
    FILE *pFileIn = NULL;
    HOSPITAL_T record;
    int size = 0;
    pFileIn = fopen("database.dat", "ab+");
    if (pFileIn != NULL)
    {
        while (fread(&record, sizeof(HOSPITAL_T), 1, pFileIn) == 1)
        {
            ++size;
            printf("\nRecord Number #%d\n", size);
            printf("\tPassport: %s\n", record.passportNumber);
            printf("\tName: %s\n", record.name);
            printf("\tBirth Date: %s\n", record.birthDate);
            printf("\tNow Date: %s\n", record.nowDate);
            printf("\tPhone: %s\n", record.internationalPhone);
            printf("\tGender: %c\n", record.gender);
        }
        printf("### %d Record Found ###", size);
    }
    else
    {
        printf("Error - Can't open file to display\n");
    }
}

int handleAddOneRecord(HOSPITAL_T record)
{
    /*printf("Passport: %s-%s\n", record.passportCountryCode, record.passportNumberCode);
    printf("Name: %s\n", record.name);
    printf("Birth date: %d/%d/%d\n", record.day, record.month, record.year);
    printf("Now Date: %d/%d/%d\n", record.dayNow, record.monthNow, record.yearNow);
    printf("Phone: %s\n", record.internationalPhone);
    printf("Gender: %c\n", record.gender);*/

    FILE *pFileIn = NULL;
    FILE *pFileOut = NULL;
    HOSPITAL_T *records = NULL;
    HOSPITAL_T recordToCheck;
    HOSPITAL_T **p_records = &records;
    int size = 0;
    int status = 0;
    pFileIn = fopen("database.dat", "ab+");
    if (pFileIn != NULL)
    {
        while (fread(&recordToCheck, sizeof(HOSPITAL_T), 1, pFileIn) == 1)
        {
            if (strcmp(recordToCheck.passportNumber, record.passportNumber) == 0)
            {
                printf("Error - This passport is already exits!\n");
                status = -1;
            }
        }
        if (status == 0)
        {
            if (fwrite(&record, sizeof(HOSPITAL_T), 1, pFileIn) != 1)
            {
                printf("Error - While add new file to database\n");
            }
        }
    }
    else
    {
        printf("Error - Can't open the database file\n");
    }
    fclose(pFileIn);
}

int handleSearchByPassPortNumber(char searched[])
{
    FILE *pFileIn = NULL;
    HOSPITAL_T record;
    int size = 0;
    pFileIn = fopen("database.dat", "ab+");
    if (pFileIn != NULL)
    {
        while (fread(&record, sizeof(HOSPITAL_T), 1, pFileIn) == 1)
        {
            if (strncmp(record.passportNumber, searched, strlen(searched)) == 0)
            {
                ++size;
                printf("\nRecord Number #%d\n", size);
                printf("\tPassport: %s\n", record.passportNumber);
                printf("\tName: %s\n", record.name);
                printf("\tBirth Date: %s\n", record.birthDate);
                printf("\tNow Date: %s\n", record.nowDate);
                printf("\tPhone: %s\n", record.internationalPhone);
                printf("\tGender: %c\n", record.gender);
            }
        }
        printf("### %d Record Found ###\n", size);
    }
    else
    {
        printf("Error - Can't open file to display\n");
    }
    return size;
}

int handleSearchByName(char searched[])
{
    FILE *pFileIn = NULL;
    HOSPITAL_T record;
    int size = 0;
    pFileIn = fopen("database.dat", "ab+");
    if (pFileIn != NULL)
    {
        while (fread(&record, sizeof(HOSPITAL_T), 1, pFileIn) == 1)
        {
            if (strncmp(record.name, searched, strlen(searched)) == 0)
            {
                ++size;
                printf("\nRecord Number #%d\n", size);
                printf("\tPassport: %s\n", record.passportNumber);
                printf("\tName: %s\n", record.name);
                printf("\tBirth Date: %s\n", record.birthDate);
                printf("\tNow Date: %s\n", record.nowDate);
                printf("\tPhone: %s\n", record.internationalPhone);
                printf("\tGender: %c\n", record.gender);
            }
        }
        printf("### %d Record Found ###\n", size);
    }
    else
    {
        printf("Error - Can't open file to display\n");
    }
    return size;
}

void handleModifyRecord(char searched[], int size, int recordNumber)
{
    char terminalInput[64];
    char choice[64];
    char newData[64];
    FILE *pFileIn = NULL;
    FILE *pFileOut = NULL;
    HOSPITAL_T *recordsFound = NULL;
    HOSPITAL_T record;
    HOSPITAL_T *allRecords = NULL;
    recordsFound = calloc(size, sizeof(HOSPITAL_T));
    pFileIn = fopen("database.dat", "ab+");
    int i = 0;
    int sizeAll = 0;
    int indexToChange;
    int day;
    int month;
    int year;
    if (pFileIn != NULL)
    {
        while (fread(&record, sizeof(HOSPITAL_T), 1, pFileIn) == 1)
        {
            ++sizeAll;
            if (strncmp(record.name, searched, strlen(searched)) == 0)
            {
                recordsFound[i] = record;
                indexToChange = i;
                ++i;
                break;
            }
        }
        rewind(pFileIn);
        allRecords = calloc(sizeAll, sizeof(HOSPITAL_T));
        if (fread(allRecords, sizeof(HOSPITAL_T), sizeAll, pFileIn) != sizeAll)
        {
            printf("Error - While read all file\n");
        }

        printf("\nYour Record to Modify is\n");
        printf("\t1) Passport Number: %s\n", record.passportNumber);
        printf("\t2) Name: %s\n", record.name);
        printf("\t3) Birth Date: %s\n", record.birthDate);
        printf("\t4) Passport Number: %s\n", record.nowDate);
        printf("\t5) Passport Number: %s\n", record.internationalPhone);
        printf("\t6) Passport Number: %c\n", record.gender);

        printf("Do you want to modify Passport Number? (yes to modify): ");
        fgets(terminalInput, sizeof(terminalInput), stdin);
        sscanf(terminalInput, "%s", choice);
        if (strcasecmp(choice, "Yes") == 0)
        {
            while (1)
            {
                printf("\tPlease Enter New Passport Number: ");
                fgets(terminalInput, sizeof(terminalInput), stdin);
                sscanf(terminalInput, "%s", newData);
                if (handlePassportNumberValidation(newData) == 0)
                {
                    break;
                }
            }
            strcpy(record.passportNumber, newData);
        }

        printf("Do you want to modify Name? (yes to modify): ");
        fgets(terminalInput, sizeof(terminalInput), stdin);
        sscanf(terminalInput, "%s", choice);
        if (strcasecmp(choice, "Yes") == 0)
        {
            while (1)
            {
                printf("\tPlease Enter New Name: ");
                fgets(terminalInput, sizeof(terminalInput), stdin);
                sscanf(terminalInput, "%s", newData);
                if (handleNameValidation(newData) == 0)
                {
                    break;
                }
            }
            strcpy(record.name, newData);
        }

        printf("Do you want to modify Birth Date? (yes to modify): ");
        fgets(terminalInput, sizeof(terminalInput), stdin);
        sscanf(terminalInput, "%s", choice);
        if (strcasecmp(choice, "Yes") == 0)
        {
            while (1)
            {
                printf("\tPlease Enter New Birth Date: ");
                fgets(terminalInput, sizeof(terminalInput), stdin);
                sscanf(terminalInput, "%s", newData);
                if (handleDateFormatValidation(newData) == 0)
                {
                    sscanf(newData, "%d/%d/%d", &day, &month, &year);
                    if (handleDateValueValidation(day, month, year) == 0)
                    {
                        break;
                    }
                }
            }
            strcpy(record.birthDate, newData);
        }

        printf("Do you want to modify Now Date? (yes to modify): ");
        fgets(terminalInput, sizeof(terminalInput), stdin);
        sscanf(terminalInput, "%s", choice);
        if (strcasecmp(choice, "Yes") == 0)
        {
            while (1)
            {
                printf("\tPlease Enter New Now Date: ");
                fgets(terminalInput, sizeof(terminalInput), stdin);
                sscanf(terminalInput, "%s", newData);
                if (handleDateFormatValidation(newData) == 0)
                {
                    sscanf(newData, "%d/%d/%d", &day, &month, &year);
                    if (handleDateValueValidation(day, month, year) == 0)
                    {
                        break;
                    }
                }
            }
            strcpy(record.birthDate, newData);
        }

        printf("Do you want to modify International Phone? (yes to modify): ");
        fgets(terminalInput, sizeof(terminalInput), stdin);
        sscanf(terminalInput, "%s", choice);
        if (strcasecmp(choice, "Yes") == 0)
        {
            while (1)
            {
                printf("\tPlease Enter International Phone: ");
                fgets(terminalInput, sizeof(terminalInput), stdin);
                sscanf(terminalInput, "%s", newData);
                if (handleNameValidation(newData) == 0)
                {
                    break;
                }
            }
            strcpy(record.internationalPhone, newData);
        }

        printf("Do you want to modify Passport Number? (yes to modify): ");
        fgets(terminalInput, sizeof(terminalInput), stdin);
        sscanf(terminalInput, "%s", choice);
        if (strcasecmp(choice, "Yes") == 0)
        {
            while (1)
            {
                printf("\tPlease Enter New Name: ");
                fgets(terminalInput, sizeof(terminalInput), stdin);
                sscanf(terminalInput, "%s", newData);
                if (handleNameValidation(newData) == 0)
                {
                    break;
                }
            }
            sscanf(newData, "%c", &record.gender);
        }
        printf("\nRecord Number #%d\n", size);
        printf("\tPassport: %s\n", record.passportNumber);
        printf("\tName: %s\n", record.name);
        printf("\tBirth Date: %s\n", record.birthDate);
        printf("\tNow Date: %s\n", record.nowDate);
        printf("\tPhone: %s\n", record.internationalPhone);
        printf("\tGender: %c\n", record.gender);
        allRecords[indexToChange] = record;
        printf("sdad");
        pFileOut = fopen("database.dat", "wb");
        if (pFileOut != NULL)
        {
            if (fwrite(allRecords, sizeof(HOSPITAL_T), sizeAll, pFileOut) == sizeAll)
            {
                printf("Modify Success\n");
            }
            else
            {
                printf("Error - While writing file\n");
            }
        }
        else
        {
            printf("Error - While open file for writing\n");
        }
    }
    else
    {
        printf("Error - Can't open file to display\n");
    }
}