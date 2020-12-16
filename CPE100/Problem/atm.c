#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char terminalInput[64];
	int startingBalance;
	int money;
	int balance;
	int totalDeposit = 0;
	int totalwithdraw = 0;
	int timeDeposit = 0;
	int timewithdraw = 0;
	char type[32];

	printf("Welcome to Prosperity Bank!\n");
	printf("What is your starting balance in baht? ");
	fgets(terminalInput,sizeof(terminalInput),stdin);
	sscanf(terminalInput,"%d",&startingBalance);
	balance = startingBalance;

	while(1)
	{
		printf("What do you want to do (DEPOSIT, WITHDRAW, DISPLAY or DONE)? ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%s",type);
		if (strcmp(type,"DONE") == 0)
		{
			break;
		}
		else if(strcmp(type,"DEPOSIT") == 0)
		{
			printf("\tDeposit amount: ");
			fgets(terminalInput,sizeof(terminalInput),stdin);
			sscanf(terminalInput, "%d", &money);
			balance+=money;
			totalDeposit+=money;
			timeDeposit++;
		}
		else if(strcmp(type,"WITHDRAW") == 0)
		{
			printf("\tWithdrawal amount: ");
			fgets(terminalInput,sizeof(terminalInput),stdin);
			sscanf(terminalInput, "%d", &money);
			if (balance < money)
			{
				printf("\tSorry, you do not have enough in your account\n");
			}
			else
			{
				balance-=money;
				totalwithdraw+=money;
				timewithdraw++;
			}
		}
		else if(strcmp(type,"DISPLAY") == 0)
		{
			printf("\tYour currentBalance is now %d baht\n", balance);
		}
	}

	printf("Transaction summary:\n");
	printf("Initial balance:\t\t%.2f\n",(double) startingBalance);
	printf(" %d deposits, total:\t\t%.2f\n",timeDeposit,(double) totalDeposit);
	printf(" %d deposits, total:\t\t%.2f\n",timewithdraw,(double) totalwithdraw);
	printf("Final balance:\t\t\t%.2f\n",(double) balance);
}