/****************************************************************
 *	
 *	addressPrint
 *
 *		This program is	use to print a pointer variable to compare for each type
 *			
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		6 October 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	int count;	/* a variable to hold a count vlaues */
	double distance;	/*  variable to hold a distace value */
	char alpha;	/*  variable to hold a alphabet value */
	char message[10];	/*  variable to hold a string of message */
	int scores[20];		/*  variable to hold a scores in array */

	count = 20;
	distance = 72.4;
	alpha = 'B';
	strcpy(message,"Hello");
	for (int i = 0; i < 20; ++i)
	{
		scores[i] = i;
	}

	printf("count had value %d and its address is %p\n", count,&count);
	printf("distance had value %.3lf and its address is %p\n", distance,&distance);
	printf("alpha had value '%c' and its address is %p\n", alpha,&alpha);
	printf("message had current value: (array)\n");
	printf("score had current value: (array)\n");

	printf("\n\n\n\n");

	printf("Element 0 of message had value '%c' and its address is %p\n", message[0],&message[0]);
	printf("Element 1 of message had value '%c' and its address is %p\n", message[1],&message[1]);
	printf("Element 2 of message had value '%c' and its address is %p\n", message[2],&message[2]);

	printf("Element 0 of message had value %d and its address is %p\n", scores[0],&scores[0]);
	printf("Element 5 of message had value %d and its address is %p\n", scores[5],&scores[5]);
	printf("Element 6 of message had value %d and its address is %p\n", scores[6],&scores[6]);
	printf("Element 7 of message had value %d and its address is %p\n", scores[7],&scores[7]);


}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/