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
#include "filehandling.h"

char databaseFileName[] = "database.dat";

int main(int argc, char *argv[])
{
	char terminalInput[64]; /* a variable to get a input from terminal that user input */
	char choice[64];
	//FILE *pFileIn = NULL;
	//pFileIn = fopen(databaseFileName, "rb");

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
	handleDisplayAll();
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
	int day, month, year;
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

	sscanf(passportNumber, "%s", record_t.passportNumber);
	sscanf(name, "%[^\n]s", record_t.name);
	sscanf(birthDate, "%s", record_t.birthDate);
	handleGetDateNow(&day, &month, &year);
	sprintf(record_t.nowDate, "%d/%d/%d", day, month, year);
	sscanf(internationalPhone, "%s", record_t.internationalPhone);
	sscanf(&gender, "%c", &record_t.gender);

	status = handleAddOneRecord(record_t);
}

void handleGetSearchInformation()
{
	int size;
	char terminalInput[64];
	char searched[64];
	char choice[64];

	while (1)
	{
		printf("\n2 choices for searching information\n");
		printf("\t1) Search by Passport Number (type \"1\"):\n");
		printf("\t2) Seach by Name (type \"2\"):\n");
		printf("\t3) Exit (type \"Exit\"):\n");
		printf("Enter your choice: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%s", choice);
		if (strcasecmp(choice, "1") == 0)
		{
			printf("Enter your passport number searching information here: ");
			fgets(terminalInput, sizeof(terminalInput), stdin);
			sscanf(terminalInput, "%s", searched);
			size = handleSearchByPassPortNumber(searched);
			if (size > 0)
			{
				printf("Do you want to modify? (yes to modify):");
				fgets(terminalInput, sizeof(terminalInput), stdin);
				sscanf(terminalInput, "%s", choice);
				if (strcasecmp(choice, "yes") == 0)
				{
					handleGetModifyInformation(searched, size);
				}
			}
		}
		else if (strcasecmp(choice, "2") == 0)
		{
			printf("Enter your name searching information here: ");
			fgets(terminalInput, sizeof(terminalInput), stdin);
			sscanf(terminalInput, "%s", searched);
			size = handleSearchByName(searched);
			if (size > 0)
			{
				printf("Do you want to modify? (yes to modify):");
				fgets(terminalInput, sizeof(terminalInput), stdin);
				sscanf(terminalInput, "%s", choice);
				if (strcasecmp(choice, "yes") == 0)
				{
					handleGetModifyInformation(searched, size);
				}
			}
		}
		else if (strcasecmp(choice, "Exit") == 0)
		{
			break;
		}
		else
		{
			printf("Error try again!\n");
		}
	}
}

void handleGetModifyInformation(char searched[], int size)
{
	char terminalInput[64];
	char choice[64];
	int choiceNumber;
	while (1)
	{
		printf("Enter record number or \"Exit\" to back to search menu (have: %d records): ", size);
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%s", choice);
		sscanf(terminalInput, "%d", &choiceNumber);
		if (strcasecmp(choice, "Exit") == 0)
		{
			break;
		}

		else
		{
			if (choiceNumber <= size && choiceNumber > 0)
			{
				handleModifyRecord(searched, size, choiceNumber);
			}
			else
			{
				printf("Error\n");
			}
		}
	}
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