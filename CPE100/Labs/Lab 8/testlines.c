/****************************************************************
 *	
 *	testlines
 *
 *		This program is	open a file and then exrtact the number upper and lower case
 *		to other file by writing
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		21 October 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char* argv[])
{
	char terminalInput[128]; /* a variable to get a input from terminal that user input */
	char fileName[128];	/* a variable to hold file name */
	char inputLine[128];	/* a variable to hold a temporary stripng that get from reading file */
	FILE* fileOpenRead = NULL;
	FILE* fileOpenWriteNumbers = NULL;
	FILE* fileOpenWriteUpper = NULL;
	FILE* fileOpenWriteLower = NULL;
	
	printf("Enter the file name: ");
	fgets(terminalInput,sizeof(terminalInput),stdin);
	strcpy(fileName,terminalInput);
	fileName[strlen(fileName)-1]=0;

	fileOpenRead = fopen(fileName,"r");
	fileOpenWriteNumbers = fopen("numbers.out","w");
	fileOpenWriteUpper = fopen("upper.out","w");
	fileOpenWriteLower = fopen("lower.out","w");

	if (fileOpenRead == NULL || fileOpenWriteNumbers == NULL || fileOpenWriteUpper == NULL || fileOpenWriteLower == NULL)
	{
		printf("Error occur, Exit now!\n");
		exit(0);
	}

	while(fgets(inputLine,sizeof(inputLine),fileOpenRead) != NULL)
	{
		if (isdigit(inputLine[0]))
		{
			fprintf(fileOpenWriteNumbers, "%s", inputLine);
			/*printf("Numbers is: %s", inputLine);*/
		}
		else if (isupper(inputLine[0]))
		{
			fprintf(fileOpenWriteUpper, "%s", inputLine);
			/*printf("Upper is: %s", inputLine);*/
		}
		else if (islower(inputLine[0]))
		{
			fprintf(fileOpenWriteLower, "%s", inputLine);
			/*printf("Lower is: %s", inputLine);*/
		}
	}	

	fclose(fileOpenWriteNumbers);
	fclose(fileOpenWriteUpper);
	fclose(fileOpenWriteLower);
}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/