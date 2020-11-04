/****************************************************************
 *	
 *	checkFuture.c
 *
 *		This program is	check the date get from user and then compare to today wheter
 *		it in the past or future
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		28 October 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dateFunctions.h"


int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	int dateGet[3];	/* an array to collect input date index 0 is day, index 1 is month, index 2 is year */
	int dateNow[3];	/* an array to collect today date index 0 is day, index 1 is month, index 2 is year */
	int dateCheck;	/* a variable to check wheter it in the past or future or today */

	while(1)
	{
		printf("Enter date to check (dd/mm/yyyy): ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		terminalInput[strlen(terminalInput)-1]=0;
		if(strcmp("BYE",terminalInput) == 0)
		{
			exit(0);
		}
		if(checkDate(terminalInput,&dateGet[0],&dateGet[1],&dateGet[2]) == 0)
		{
			dateToday(&dateNow[0],&dateNow[1],&dateNow[2]);
			dateCheck = dateCompare(dateNow[0],dateNow[1],dateNow[2],
									dateGet[0],dateGet[1],dateGet[2]);

			if (dateCheck == 1)
			{
				printf("%s is in the past\n", terminalInput);
			}
			else if (dateCheck == -1)
			{
				printf("%s is in the future\n", terminalInput);
			}
			else if (dateCheck == 0)
			{
				printf("%s is today\n", terminalInput);
			}
		}
		else
		{
			printf("%s is not a valid date\n", terminalInput);
		}

	}


}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/