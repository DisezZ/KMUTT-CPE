/****************************************************************
 *	
 *	weatherReport
 *
 *		This program is	reports the weather for a particular week and day of the week.
 *			
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		15 September 2020
 *
 ****************************************************************
 */

#include<stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	int week;	/* week of user input */
	int day;	/*day of user input */
	/* codes for four weeks of weather, seven days per week */
	/* 1 means sunny, 2 means rainy, 3 means cloudy */
	int weatherCodes[4][7] = 	{{1,2,3,2,2,2,1},{2,2,2,2,3,3,3},
                          		{3,1,1,1,2,3,1},{1,2,3,1,2,2,2}};
	
	printf("Welcome to weather!\n");
	while(1)
	{
		printf("What week do you want? (1-4) ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&week);
		if(week < 0)
		{
			break;
		}

		printf("What day of that week? (1-7) ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&day);

		if((week < 1 || week > 4) || (day < 1 || day >7))
		{
			printf("Invalid week or day\n");
			
		}
		else
		{
			if(weatherCodes[week-1][day-1]==1)
			{
				printf("Weather for week %d, day %d was sunny.\n",week,day);
			}
			else if(weatherCodes[week-1][day-1]==2)
			{
				printf("Weather for week %d, day %d was rainy.\n",week,day);
			}
			else
			{
				printf("Weather for week %d, day %d was cloudy.\n",week,day);
			}	
		}
	}

	printf("Goodbye!\n");
}




/*********************************************

fgets(,sizeof(),stdin);
sscanf(,"%",&);

**********************************************
*/