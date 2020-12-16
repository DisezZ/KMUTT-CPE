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

int main(int argc, char *argv[])
{
	char terminalInput[64]; /* a variable to get a input from terminal that user input */
	char choice[64];
	char databaseFileName = "database.dat";

	printf("\"%d\" is default database, would you like to change? (y / n): ");s
	fgets("")
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
	printf("\tWelcome to Hospital Database Applications\n");

	printf("\tThis is an options that you can do\n\n");
	printf("\t\t1) Display All Records in Database (Type: \"Display\"):\n");
	printf("\t\t1) Add Record to the Database (Type: \"Add\"):\n");
	printf("\t\t1) Search for Record in Database (Type: \"Search\"):\n");
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
	else
	{
		printf("Error - Type again!");
	}
}

void handleDisplayAllDataBase()
{
	printf("display all database here\n");
}

void handleGetAddInformation()
{
	char terminalInput[64]; /* a variable to get a input from terminal that user input */
	char passportNumber[64];
	char name[64];
	char birthDate[64];
	char internationalPhone[64];
	char genders[16];
	char gender;
	printf("\n******6 Steps to Add Information to the Database*******\n");

	while (1)
	{
		printf("1) Please Enter Passport Number: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%s", passportNumber);
		if (handlePassportNumberValidation(passportNumber) == 0)
		{
			break;
		}
	}

	while (1)
	{
		printf("2) Please Enter Name: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%s", name);
		if (handleNameValidation(name) == 0)
		{
			break;
		}
	}

	while (1)
	{
		printf("3) Please Enter Birth Date: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%s", birthDate);
		if (handleBirthDateValidation(birthDate) == 0)
		{
			break;
		}
	}

	while (1)
	{
		printf("4) Please Enter International Phone: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%s", internationalPhone);
		if (handleInternationalPhoneValidation(internationalPhone) == 0)
		{
			break;
		}
	}

	while (1)
	{
		printf("5) Please Enter Gender: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%s", genders);
		if (handleGenderValidation(genders) == 0)
		{
			sscanf(terminalInput, "%c", &gender);
			break;
		}
	}
	
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

/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/