/****************************************************************
 *	
 *	revenue
 *
 *		This program is	calculate tax incomes in baht and also get a tax payer id
 *		and then printed collected tax and in this program will use function as well
 *			
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		23 September 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*	This function has 1 arguments that get an array of char and then check if that whole array is digit or not
 *	if yes, return 1. if not, return 0
 */
int checkAllDigits(char stringToCheck[]);


/*	This function has no argument but will get a tax payer id as string and then check if it right lenght
 *	and all digits,if the value entered is not valid then it will ask repeatedly until valid,
 *	this program return tax payer id as an integer
 */
int getTaxID();


/*	This function has no arguments but will get a tax payer income as string and then check if it 
 * 	all digits,if the value entered is not valid then it will ask repeatedly until valid 
 *	this program return tax payer income as a double
*/
double getIncome();


int main(int argc,char* argv[])
{
	double recievedIncome;	/* a variable that will store a income of tax payer */
	double totalTax;/* a variable that will collect sum of totla tax that all tax payer has to pay */
	int idChecker;	/* a variable that that will store a id of tax payer */
	int catagoryTaxCount[4]={0,0,0,0};	/* a array that will store a sum of each tax catagories that had calculate */
	totalTax=0;
	idChecker=0;

	while(1)
	{
		idChecker=getTaxID();
		if(idChecker==0)
		{
			break;
		}
		else
		{
			recievedIncome=getIncome();
			if (recievedIncome<=50000)
			{
				totalTax += 0;
				catagoryTaxCount[0]++;
			}
			else if ((recievedIncome>50000) && (recievedIncome<=200000))
			{
				totalTax += recievedIncome*0.1;
				catagoryTaxCount[1]++;
			}
			else if ((recievedIncome>200000) && (recievedIncome<=1000000))
			{
				totalTax += recievedIncome*0.2;
				catagoryTaxCount[2]++;
			}
			else
			{
				totalTax += recievedIncome*0.3;
				catagoryTaxCount[3]++;
			}				
		}
	}
	printf("Total tax revenue collected: %.1lf\n", totalTax);
	for (int i = 0; i < 4; ++i)
	{
		printf("Tax category %d count: %d\n", i+1,catagoryTaxCount[i]);
	}
}

int checkAllDigits(char stringToCheck[])
{
	int checker;	/* a variable that will be a checker wheter whole string is all digits or not */
	checker=1;
	for (int i = 0; i < strlen(stringToCheck)-1; ++i)
	{
		if(!isdigit(stringToCheck[i]))
		{
			checker=0;
			break;
		}
	}

	return checker;
}

int getTaxID()
{
	char terminalInput[32]=""; /* a variable to get a input from terminal that user input */
	int getTaxID;	/* a variable that will store a tax payer id that will be get from terminal */
	int getTaxIDChecker;	/* a variable that will be a checker for that tax payer id is valid or not */
	getTaxID=0;	
	getTaxIDChecker=0;
	while(1)
	{
		printf("Enter your tax ID (4 digits, 0000 to end): ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		if(strlen(terminalInput)-1==4)
		{
			getTaxIDChecker=checkAllDigits(terminalInput);
			if(getTaxIDChecker==0)
			{
				printf("-- Invalid tax ID, must be all digits\n");
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("-- Invalid tax ID, must be 4 characters long\n");
		}
	}
	sscanf(terminalInput,"%d",&getTaxID);

	return getTaxID;
}

double getIncome()
{
	char terminalInput[32]=""; /* a variable to get a input from terminal that user input */
	double getIncome;	/* a variable that will store a tax payer income that will be get from terminal */
	int getIncomeChecker;	/* a variable that will be a checker for that tax payer income is valid or not */
	getIncome=0;
	getIncomeChecker=0;

	while(1)
	{
		printf("What is your yearly income in baht? ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		getIncomeChecker=checkAllDigits(terminalInput);
		if(getIncomeChecker==0)
		{
			printf("-- Invalid income, must be all digits\n");
		}
		else
		{
			break;
		}
	}
	sscanf(terminalInput,"%lf",&getIncome);

	return getIncome;
} 



/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/