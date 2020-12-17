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
#include "hospital.h"
#include "writeFile.h"
#include "readFile.h"

int handleAddOneRecord(HOSPITAL_T record)
{
    printf("Passport: %s-%s\n", record.passportCountryCode, record.passportNumberCode);
    printf("Name: %s\n", record.name);
    printf("Birth date: %d/%d/%d\n", record.day, record.month, record.year);
    printf("Now Date: %d/%d/%d\n", record.dayNow, record.monthNow, record.yearNow);
    printf("Phone: %s\n", record.internationalPhone);
    printf("Gender: %c\n", record.gender);

    FILE *pFileIn = NULL;
    FILE *pFileOut = NULL;
    HOSPITAL_T *records = NULL;
    HOSPITAL_T **p_records = &records;
    int size;
    pFileIn = fopen("database.dat", "ab+");
    if (pFileIn != NULL)
    {
        if (fwrite(&record, sizeof(HOSPITAL_T), 1, pFileIn) != 1)
        {
            printf("Error - can't write the file to the database\n");
        }
    }
    else
    {
        printf("Error - Can't open the database file\n");
    }
    fclose(pFileIn);
}
