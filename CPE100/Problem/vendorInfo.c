#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_COUNT 30

typedef struct
{
	char name[32];
	char sell[32];
	int income;
}VENDOR_T;

int main()
{
	FILE* pFileIn = NULL;
	VENDOR_T vendor[MAX_COUNT];
	char terminalInput[33];
	char fileInput[128];
	char fileNameIn[32];
	char searchNameInput[32];
	int searchChecker;
	int count = 0;
	int totalIncome = 0;

	printf("Enter name of input file: ");
	fgets(terminalInput,sizeof(terminalInput),stdin);
	sscanf(terminalInput,"%s",fileNameIn);

	pFileIn = fopen(fileNameIn,"r");
	if (pFileIn == NULL)
	{
		printf("Error - While opening file\n");
	}

	while(1)
	{
		if (fgets(fileInput,sizeof(fileInput),pFileIn) == NULL || count == MAX_COUNT)
		{
			break;
		}
		sscanf(fileInput,"%s %s %d", vendor[count].name, vendor[count].sell, &vendor[count].income);
		totalIncome+=vendor[count].income;
		++count;
	}
	printf("\nRead %d vendors from file %s\n", count, fileNameIn);
	printf("Average daily income was %.2lf baht\n\n", (double)totalIncome/count);

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
			}
		}

		if (searchChecker >= 0)
		{
			printf("%s sells %s and made %d baht last week\n", vendor[searchChecker].name, vendor[searchChecker].sell, vendor[searchChecker].income);
		}
		else
		{
			printf("No vendor found with the name \'%s\'\n", searchNameInput);
		}
	}
}