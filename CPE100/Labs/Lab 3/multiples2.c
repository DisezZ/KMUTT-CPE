/***************************************************************
 *
 *	multiples2
 *	
 *		This program  asks the user at the beginning how many values they want to check. 
 *		Then ask forexactly this number of values
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
	int maxloop; 	/* how many times does program will lop */
	int checker;
	
	checker=1;
	do
	{
		printf("Check for multiples of what number (greater than 0 and less than 10)? ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&divider);
		if(( divider > 0 ) && ( divider < 10))
		{
			checker=0;
		}
		else
		{
			printf("Illegal value!\n");
		}
	}while(checker);

	printf("Check how many values? ");
	fgets(terminalInput,sizeof(terminalInput),stdin);
	sscanf(terminalInput,"%d",&maxloop);

	counter = 0;
	for (int i = 0; i < maxloop; ++i)
	{
		printf("Value to check: ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&divided);

		if(divided%divider==0)
		{
			printf("%d  is evenly divisible by %d\n",divided,divider);
			++counter;
		}
		else
		{
			printf("%d  is NOT evenly divisible by  %d\n",divided,divider);
		}
	}
	

	printf("You entered %d values that were multiples of %d.\nGoodbye!",counter,divider);
}