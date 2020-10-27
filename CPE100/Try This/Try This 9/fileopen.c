/****************************************************************
 *	
 *	fileopen
 *
 *		This program is	practice of using file open function 
 *		and tells that open successfully or not
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		20 October 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	char fileName[32]={0};	/* variable for hold file name */ 
	FILE* fileIn = NULL;

	if (argc < 2)
	{
		printf("Error - No arguments\n");
		exit(0);
	}
	
	strcpy(fileName,argv[1]);

	fileIn = fopen(fileName,"r");

	if (fileIn == NULL)
	{
		printf("Error - Cannot open the file %s\n", argv[1]);
	}
	else
	{
		printf("Successfully open the file %s\n", argv[1]);
	}

}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/