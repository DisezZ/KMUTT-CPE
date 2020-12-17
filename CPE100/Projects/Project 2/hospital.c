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
#include <ctype.h>
#include "hospital.h"
#include "validations.h"
#include "writeFile.h"
#include "readFile.h"

char databaseFileName[] = "database.dat";

int main(int argc, char *argv[])
{
	char terminalInput[64]; /* a variable to get a input from terminal that user input */
	char choice[64];

	while (1)
	{
		handleDisplayMenus();
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%s", choice);
		handleMenuSelection(choice);
	}
}

void handleDisplayMenus()
{
	printf("\n***********************************************************************************\n");
	printf("\nWelcome to Hospital Database Applications\n");
	printf("\"%s\" is current database file name \n\n", databaseFileName);

	printf("Options List: \n");
	printf("\t1) Display All Records in Database (Type: \"Display\"):\n");
	printf("\t2) Add Record to the Database (Type: \"Add\"):\n");
	printf("\t3) Search for Record in Database (Type: \"Search\"):\n");
	printf("\t4) Change File Name for Database (Type: \"Change\"):\n");
	printf("\n***********************************************************************************\n");
	printf("Enter your Option: ");
}

void handleMenuSelection(char choice[])
{
	int status;
	if (!strcasecmp(choice, "Display"))
	{
		handleDisplayAllDataBase();
	}
	else if (!strcasecmp(choice, "Add"))
	{
		handleGetAddInformation();
	}
	else if (!strcasecmp(choice, "Search"))
	{
		handleGetSearchInformation();
	}
	else if (!strcasecmp(choice, "Exit"))
	{
		printf("Exit now!");
		exit(0);
	}
	else if (!strcasecmp(choice, "Change"))
	{
		handleChangeDatabaseFileName();
	}
	else
	{
		printf("Error - Type again!");
	}
}

void handleDisplayAllDataBase()
{
	FILE *pFileIn = NULL;
	HOSPITAL_T record;
	int size = 0;
	pFileIn = fopen("database.dat", "rb");
	if (pFileIn != NULL)
	{
		while (fread(&record, sizeof(HOSPITAL_T), 1, pFileIn) == 1)
		{
			printf("Passport: %s-%s\n", record.passportCountryCode, record.passportNumberCode);
			printf("Name: %s\n", record.name);
			printf("Birth Date: %d/%d/%d\n", record.day, record.month, record.year);
			printf("Birth Date: %d/%d/%d\n", record.day, record.month, record.year);
			printf("Phone: %s\n", record.internationalPhone);
			printf("Gender: %c\n", record.gender);
		}
	}
	else
	{
		printf("Error - Can't open file to display\n")
	}
}

void handleGetAddInformation()
{
	int status;
	HOSPITAL_T *all_record = NULL;
	HOSPITAL_T **all_record_t = &all_record;
	HOSPITAL_T record_t;
	char terminalInput[64]; /* a variable to get a input from terminal that user input */
	char passportNumber[64];
	char name[64];
	char birthDate[64];
	char internationalPhone[64];
	char genders[16];
	char gender;
	int size;

	printf("\n******6 Steps to Add Information to the Database*******\n");
	while (1)
	{
		printf("1) Please Enter Passport Number: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%[^\n]s", passportNumber);
		if (handlePassportNumberValidation(passportNumber) == 0)
		{
			break;
		}
	}

	while (1)
	{
		printf("2) Please Enter Name: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%[^\n]s", name);
		if (handleNameValidation(name) == 0)
		{
			break;
		}
	}

	while (1)
	{
		printf("3) Please Enter Birth Date: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%[^\n]s", birthDate);
		if (handleBirthDateValidation(birthDate) == 0)
		{
			break;
		}
	}

	while (1)
	{
		printf("4) Please Enter International Phone: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%[^\n]s", internationalPhone);
		if (handleInternationalPhoneValidation(internationalPhone) == 0)
		{
			break;
		}
	}

	while (1)
	{
		printf("5) Please Enter Gender: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%[^\n]s", genders);
		if (handleGenderValidation(genders) == 0)
		{
			sscanf(terminalInput, "%c", &gender);
			break;
		}
	}

	sscanf(passportNumber, "%2s-%s", record_t.passportCountryCode, record_t.passportNumberCode);
	sscanf(name, "%[^\n]s", record_t.name);
	sscanf(birthDate, "%d/%d/%d", &record_t.day, &record_t.month, &record_t.year);
	handleGetDateNow(&record_t.dayNow, &record_t.monthNow, &record_t.yearNow);
	sscanf(internationalPhone, "%s", record_t.internationalPhone);
	sscanf(&gender, "%c", &record_t.gender);

	status = handleAddOneRecord(record_t);
}

void handleGetSearchInformation()
{
	printf("get search information\n");
}

void handleGetModifyInformation()
{
	printf("get modify information\n");
}

void handleDisplayErrormessage()
{
	printf("display error message\n");
}

void handleChangeDatabaseFileName()
{
	char terminalInput[64];
	printf("Enter your new database file name: ");
	fgets(terminalInput, sizeof(terminalInput), stdin);
	sscanf(terminalInput, "%s", terminalInput);
	strcpy(databaseFileName, terminalInput);
}

/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/