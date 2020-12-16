/****************************************************************
 *	
 *	binaryWrite.c
 *
 *		This program is	try to use of binary file by get data and write as integer in binary
 *			
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		10 November 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	int number;	/* variable for get number */
	int count;	/* variable for  */
	char fileName[] = "trythis.dat";	/*  */
	FILE *pFileIn;	/*  */

	number = 0;
	count = 0;
	pFileIn = NULL;
	printf("Size of number is %ld bytes\n", sizeof(number));

	pFileIn = fopen(fileName,"wb");
	if (pFileIn == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	while(1)
	{
		printf("Enter an Integer: ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%d", &number);
		if(number < 0)
		{
			fclose(pFileIn);
			printf("Count  is: %d\n", count);
			exit(0);
		}

		if (fwrite(&number, sizeof(int), 1, pFileIn) != 1)
		{
			printf("Error while writing\n");
		}
		++count;
	}
}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/