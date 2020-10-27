/****************************************************************
 *	
 *	Template
 *
 *		This program is	
 *			
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		x October 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ioFunctions.h"

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	
	while(1)
	{
		printf("What is your first name? ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		terminalInput[strlen(terminalInput)-1]=0;
		if(isAlphaString(terminalInput))
		{
			printf("Hi, %s!\n", terminalInput);
			break;
		}
		printf("\tSorry, invalid name; please try again!\n");
	}

}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/