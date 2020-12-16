/***********************************************
 *	mobileshop2.c
 *		This is final exam problem 2
 *
 *	Created By Lutfee Deemae ID 63070503448
 *	25 November 2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_TRANSACTIONS 10000

typedef struct
{
	char name[64];
	double price;
	int quantity;
} ITEM;

int main(int argc, char* argv[])
{
	char terminalInput[64];
	char fileInput[64];
	char userChoice[64];
	char fileNameIn[64];
	int choiceCheck;
	int userQuantity;
	int i;
	int totalTransactions = 0;
	int totalStock = 0;
	double totalRevenue = 0;
	ITEM stock[5];
	ITEM stockTemp;
	ITEM transaction[MAX_TRANSACTIONS];
	FILE* pFileIn = NULL;
	
	if(argc < 2)
	{
		printf("Error - missing arguments\n");
		exit(0);	
	}
	
	sscanf(argv[1], "%s", fileNameIn);
	pFileIn = fopen(fileNameIn, "r");
	if(pFileIn == NULL)
	{
		printf("Error - can't open file name %s\n", fileNameIn);
		exit(1);
	}
	while(fgets(fileInput, sizeof(fileInput), pFileIn) != NULL)
	{
		if(sscanf(fileInput, "%s %lf %d", stockTemp.name, &stockTemp.price, &stockTemp.quantity) == 3)
		{
			sscanf(fileInput, "%s %lf %d", stock[totalStock].name, &stock[totalStock].price, &stock[totalStock].quantity);
			++totalStock;
		}
	}	

	printf("Welcome to Mama's Mobile Supplies!\n");
	printf("The following products are available:\n");
	for(i = 0; i < totalStock; ++i)
	{
			printf("%20s%20.2lf baht%20d available\n", stock[i].name, stock[i].price, stock[i].quantity);
	}
	
	printf("\n");
	while(1)
	{
		printf("What do you want to buy? ");
		fgets(terminalInput, sizeof(terminalInput), stdin);
		sscanf(terminalInput, "%s", userChoice);

		if(strcasecmp(userChoice,"DONE") == 0 || totalTransactions >= MAX_TRANSACTIONS)
		{
			break;	
		}
		
		choiceCheck = -1;
		for(i = 0; i < totalStock; ++i)
		{
			if(strcasecmp(stock[i].name, userChoice) == 0)
			{
				choiceCheck = i;
				break;
			}
		}

		if(choiceCheck != -1)
		{
			printf("How many do you want? ");
			fgets(terminalInput, sizeof(terminalInput), stdin);
			sscanf(terminalInput, "%d", &userQuantity);
			
			if(userQuantity <= 0)
			{
				printf("\tError - quantity must be positive numbers\n");
			}
			else if(userQuantity <= stock[choiceCheck].quantity)
			{
				printf("\tPlease pay %.2lf baht\n", (double)userQuantity*stock[choiceCheck].price);
				stock[choiceCheck].quantity -= userQuantity;
				totalRevenue += (userQuantity*stock[choiceCheck].price);

				strcpy(transaction[totalTransactions].name, stock[choiceCheck].name);
				transaction[totalTransactions].price = (userQuantity*stock[choiceCheck].price);
				transaction[totalTransactions].quantity = userQuantity;
				++totalTransactions;
			}
			else
			{
				printf("\tSorry, we can't fill your order\n");
				printf("\tWe only have %d in stock\n", stock[choiceCheck].quantity);
			}
		}
		else
		{
			printf("\tInvalid product name - try again\n");
		}				
	}

	if(totalTransactions > 0)
	{
		printf("\n");	
	}	
	for(i = 0; i< totalTransactions; ++i)
	{
		printf("%d. %-10s %d %10.2lf baht\n", i+1, transaction[i].name, transaction[i].quantity, transaction[i].price);
	}
	printf("\nAt the end of the day, here is the available stock\n");
	for(i = 0; i < totalStock; ++i)
	{
		printf("%20s%20d items available\n", stock[i].name, stock[i].quantity);
	}
	printf("\nTotal revenue today was %.2lf\n",totalRevenue);
}
