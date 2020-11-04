/****************************************************************
 *	
 *	datestruct.c
 *
 *		This program is	make use pf struct and get date and store in structure type data
 *			
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		x October 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
	{
		int day;
		int month;
		int year;
	} DATE_T;

void prinStruct(DATE_T dateInfo)
{
	printf("year is %d\nmonth is %d\nDay is %d\n", dateInfo.year,dateInfo.month,dateInfo.day);
}

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	DATE_T dateInfo;
	
	printf("Enter a date (dd/mm/yyyy): \n");
	fgets(terminalInput,sizeof(terminalInput),stdin);
	sscanf(terminalInput,"%d/%d/%d", &dateInfo.day,&dateInfo.month,&dateInfo.year);
	prinStruct(dateInfo);
}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/