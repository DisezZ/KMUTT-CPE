/****************************************************************
 *	
 *	dynamic.c
 *
 *		This program is	using of dynamic memory allocation to store array
 *		of integer and print them back to terminal.
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		17 November 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	int* userValues = NULL;	/* a pointer variable to store array of int */
	int count;	/* a variale to store size of input */

	printf("How many value?: ");
	fgets(terminalInput,sizeof(terminalInput),stdin);
	sscanf(terminalInput,"%d",&count);

	userValues = calloc(count, sizeof(int));

	if (userValues == NULL)
	{
		printf("Memory allocating failed, Exit now!\n");
		exit(0);
	}
	printf("Successfully allocating memory.\n");

	for (int i = 0; i < count; ++i)
	{
		printf("Enter value %d: ", i+1);
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&userValues[i]);
	}

	printf("Content of the array:\n");
	for (int i = 0; i < count; ++i)
	{
		printf("\t%d\n", userValues[i]);
	}
}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/