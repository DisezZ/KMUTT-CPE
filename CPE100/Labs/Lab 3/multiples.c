/***************************************************************
 *
 *	multiples
 *	
 *		This program  determines whether numbers entered by the user are exact
 *		multiples of another number.
 *
 *		Created by Lutfee Deemae (Lut) ID 63070503448
 *		2 September 2020
 *		
 ***************************************************************
 */

#include <stdio.h>
int main()
{
	char terminalInput[32];
	int divider;	/* a number for divider that will use to check with other number */
	int divided;	/* a number that will be checked that evenly disible by divider or not */
	int counter;	/* a variable that count how many time user input a evenl */

	printf("Check for multiples of what number (greater than 0 and less than 10)? ");
	fgets(terminalInput,sizeof(terminalInput),stdin);
	sscanf(terminalInput,"%d",&divider);

	counter=0;
	do
	{
		printf("Value to check (­-1 to stop): ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&divided);
		
		if(divided==-1)break;

		if(divided%divider==0)
		{
			printf("%d  is evenly divisible by %d\n",divided,divider);
			++counter;
		}
		else
		{
			printf("%d  is NOT evenly divisible by  %d\n",divided,divider);
		}
	}while(1);

	printf("You entered %d values that were multiples of %d.\nGoodbye!",counter,divider);

}