/****************************************************************
 *	
 *	shopping
 *
 *		This program is	ask user for a item left in basket and then get price of each
 *		item, then calculate the actual price included VAT and print out
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		9 September 2020
 *
 ****************************************************************
 */

#include<stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	char terminalInput[32];	/* a variable to get a input from terminal that user input */
	int input; 	/* a variable for collect a integer input from user */
	double priceInput[20]={0}; 	/* a array of to collect each price of item that user input */
	double sumPrice; 	/* a variable to calculate sum of priceInput array */
	double sumVat; 	/* a variable to calculate sum of priceVat array */
	double sumTotal; 	/* a variable to calculate sum of priceTotal array */
	int loops; 	/* a variable to collect a first input to use as a loops round */

	sumPrice=0; /* set a variable to zero */ 
	sumVat=0;	/* set a variable to zero */ 
	sumTotal=0;	/* set a variable to zero */ 

	printf("How many items in your basket? ");
	fgets(terminalInput,sizeof(terminalInput),stdin);
	sscanf(terminalInput,"%d",&input);

	if((input > 20)||(input <= 0))
	{
		printf("This program  cannot handle this many items\n");
		exit(0);
	}
	else
	{
		/* part that user will input each item price */
		loops=input;
		for (int i = 0; i < loops; ++i)
		{
			printf("Price for item %d? ",i+1);
			fgets(terminalInput,sizeof(terminalInput),stdin);
			sscanf(terminalInput,"%lf",&priceInput[i]);
		}

		/* part that program will print a receipt */

		printf("Here is your receipt:\n");
		printf("\tPrice\tVAT\tItem Total\n\t-------\t-------\t-------\n");
		
		for (int i = 0; i < loops; ++i)
		{
			sumPrice+=priceInput[i];

			if (priceInput[i] >= 100)
			{
				printf("\t%.2f\t%.2f\t%.2f\n",priceInput[i],priceInput[i]*0.07,priceInput[i]+priceInput[i]*0.07);
				sumVat+=priceInput[i]*0.07;
				sumTotal+=priceInput[i]*0.07+priceInput[i];
			}
			else
			{
				printf("\t%.2f\t%.2f\t%.2f\n",priceInput[i],0.00,priceInput[i]);
				sumTotal+=priceInput[i];
			}
		}

		printf("\t-------\t-------\t-------\n");
		printf("\t%.2f\t%.2f\t%.2f\n",sumPrice,sumVat,sumTotal);
	}
}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%d",&input);

**********************************************
*/