/****************************************************************
 *	
 *	Template
 *
 *		This program is	
 *			
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		x November 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataManipulation.h"
#include "hospital.h"
#include "writeFile.h"
#include "readFile.h"

HOSPITAL_T handleSearchByPassPortNumber(char searched[])
{
    FILE *pFileIn = NULL;
    HOSPITAL_T record;
    int size = 0;
    int i = 0;
    printf("read");
    pFileIn = fopen("database.dat", "rb");
    if (pFileIn != NULL)
    {
        while (fread(&record, sizeof(HOSPITAL_T), 1, pFileIn) == 1)
        {
            if (strncmp(record.passportNumber, searched, strlen(searched)) == 0)
            {
                ++i;
                printf("Passport: %s\n", record.passportNumber);
                printf("Name: %s\n", record.name);
                printf("Birth Date: %d/%d/%d\n", record.day, record.month, record.year);
                printf("Birth Date: %d/%d/%d\n", record.day, record.month, record.year);
                printf("Phone: %s\n", record.internationalPhone);
                printf("Gender: %c\n", record.gender);
            }
        }
    }
    else
    {
        printf("Error - Can't open file to display\n");
    }
}

HOSPITAL_T handleSearchByName(char searched[])
{
    FILE *pFileIn = NULL;
    HOSPITAL_T record;
    int size = 0;
    int i = 0;
    pFileIn = fopen("database.dat", "rb");
    if (pFileIn != NULL)
    {
        while (fread(&record, sizeof(HOSPITAL_T), 1, pFileIn) == 1)
        {
            if (strncmp(record.name, searched, strlen(searched)) == 0)
            {
                ++i;
                printf("Number #%d", i);
                printf("Passport: %s\n", record.passportNumber);
                printf("Name: %s\n", record.name);
                printf("Birth Date: %d/%d/%d\n", record.day, record.month, record.year);
                printf("Birth Date: %d/%d/%d\n", record.day, record.month, record.year);
                printf("Phone: %s\n", record.internationalPhone);
                printf("Gender: %c\n", record.gender);
            }
        }
    }
    else
    {
        printf("Error - Can't open file to display\n");
    }
}