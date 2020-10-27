/****************************************************************
 *	
 *	shopping2
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
	double vat; /* a variable to hold VAT percentage */

	sumPrice=0; /* set a variable to zero */ 
	sumVat=0;	/* set a variable to zero */ 
	sumTotal=0;	/* set a variable to zero */ 


	if(argc < 3)
	{
		printf("This program cannot run without provide both the item count and the VAT percentage\n");
		exit(0);
	}
	else
	{
		sscanf(argv[1],"%d",&input);
		sscanf(argv[2],"%lf",&vat);
		if(input > 20)
		{
			printf("This program  cannot handle this many items\n");
			exit(0);
		}
		else if(input < 0)
		{
			printf("the items must be positive not negative number\n");
			exit(0);
		}
		else if((vat < 0) || (vat > 10))
		{
			printf("This program cannot handle  VAT that less than 0 or greater than 10\n");
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
					printf("\t%.2f\t%.2f\t%.2f\n",priceInput[i],priceInput[i]*vat*0.01,priceInput[i]+priceInput[i]*vat*0.01);
					sumVat+=priceInput[i]*vat*0.01;
					sumTotal+=priceInput[i]*vat*0.01+priceInput[i];
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
}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%d",&input);

**********************************************
*/