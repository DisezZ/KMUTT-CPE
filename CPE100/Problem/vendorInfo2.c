/*
 *
 *
 *
 *
 ********************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
	char name[32];
	char sell[32];
	int income;
} VENDOR_T;

int allAlpha(char string[])
{
	int checker = 0;
	for (int i = 0; i < strlen(string); ++i)
	{
		if (!isalpha(string[i]))
		{
			checker = -1;
		}
	}
	return checker;
}

int main(int argc, char* argv[])
{
	FILE* pFileIn = NULL;
	VENDOR_T* vendor = NULL ;
	VENDOR_T vendorTemp;
	char terminalInput[33];
	char fileInput[128];
	char fileNameIn[32];
	char searchNameInput[32];
	int count = 0;
	int allLine = 0;
	int totalIncome = 0;
	int searchChecker = -1;

	if (argc < 2)
	{
		printf("Error - Expected 2 arguments\n");
		exit(0);
	}
	sscanf(argv[1],"%s",fileNameIn);
	pFileIn = fopen(fileNameIn,"r");
	if (pFileIn == NULL)
	{
		printf("Error - While opening file\n");
		exit(1);
	}
	while(fgets(fileInput, sizeof(fileInput), pFileIn) != NULL)
	{  ++allLine;  }

	rewind(pFileIn);
	vendor = calloc(sizeof(VENDOR_T), allLine);
	while(fgets(fileInput, sizeof(fileInput), pFileIn) != NULL)
	{
		if (sscanf(fileInput, "%s %s %d", vendorTemp.name, vendorTemp.sell, &vendorTemp.income) == 3)
		{
			if (allAlpha(vendorTemp.name) == 0)
			{
				if (allAlpha(vendorTemp.sell) == 0)
				{
					if (vendorTemp.income > 0)
					{
						strcpy(vendor[count].name,vendorTemp.name);
						strcpy(vendor[count].sell,vendorTemp.sell);
						vendor[count].income = vendorTemp.income;
						//printf("%s %s %d\n", vendor[count].name, vendor[count].sell, vendor[count].income);
						totalIncome += vendor[count].income;
						++count;
					}
					else
					{
						printf("Error - income must be only positive integer, Skip line!\n");
					}
				}
				else
				{
					printf("Error - name must be only alphabet, Skip line!\n");
				}
			}
			else
			{
				printf("Error - name must be only alphabet, Skip line!\n");
			}
		}
		else
		{
			printf("Error - Argument not right in this line, Skip now!\n");
		}
	}
	printf("\nRead %d vendors from file %s\n", count, fileNameIn);
	printf("Average daily income was %.2lf baht\n\n", count > 0?(double)totalIncome/count:0);

	while(1)
	{
		printf("Search for what vendor? (DONE to end) ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%s",searchNameInput);
		if (strcasecmp(searchNameInput,"DONE") == 0)
		{
			printf("\nThank you for studying C programming!\n");
			break;
		}
		searchChecker = -1;
		for (int i = 0; i < count; ++i)
		{
			if (strcasecmp(searchNameInput,vendor[i].name) == 0)
			{
				searchChecker = i;
				break;
			}
		}
		if (searchChecker != -1)
		{
			printf("%s sells %s and made %d baht last week\n", vendor[searchChecker].name, vendor[searchChecker].sell, vendor[searchChecker].income);
			break;
		}
		else
		{
			printf("No vendor found with the name \'%s\'\n", searchNameInput);			
		}
	}
}
