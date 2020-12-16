#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long validateMoney(char money[])
{
	int checker = 0;
	long temp;
	for (int i = 0; i < strlen(money); ++i)
	{
		if (!isdigit(money[i]))
		{
			checker = -1;
			break;
		}
	}
	if (checker == 0)
	{
		sscanf(money,"%ld",&temp);
		if (temp > 10000000)
		{
			return -1;
		}
		else
		{
			return temp;
		}
	}
	else
	{
		return -1;
	}

}

int main(int argc, char* argv[])
{
	FILE* pOut = NULL;
	char terminalInput[64];
	long startingBalance;
	int money;
	long balance;
	int totalDeposit = 0;
	int totalwithdraw = 0;
	int timeDeposit = 0;
	int timewithdraw = 0;
	char type[32];

	if (argc < 2)
	{
		printf("Error - Must have 1 argument\n");
		exit(0);
	}
	sscanf(argv[1],"%s",argv[1]);
	if (validateMoney(argv[1]) == -1)
	{
		printf("Error\n");
		exit(0);
	}
	startingBalance = validateMoney(argv[1]);
	pOut = fopen("transactions.dat","w");
	if (pOut == NULL)
	{
		printf("Error - ca't open file\n");
		exit(0);
	}
	printf("Welcome to Prosperity Bank!\n\n");
	fprintf(pOut, "INITIAL BALANCE\t\t%.2lf\n", (double)startingBalance);
	balance = startingBalance;


	while(1)
	{
		printf("What do you want to do (DEPOSIT, WITHDRAW, DISPLAY or DONE)? ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%s",type);
		if (strcasecmp(type,"DONE") == 0)
		{
			break;
		}
		else if(strcasecmp(type,"DEPOSIT") == 0)
		{
			printf("\tDeposit amount: ");
			fgets(terminalInput,sizeof(terminalInput),stdin);
			sscanf(terminalInput, "%s", terminalInput);
			if (validateMoney(terminalInput) != -1)
			{
				money = validateMoney(terminalInput);
				balance+=money;
				totalDeposit+=money;
				timeDeposit++;
				fprintf(pOut, "DEP\t%.2lf\tBAL\t%.2lf\n", (double)money, (double)balance);
			}
			else
			{
				printf("Error\n");
			}
		}
		else if(strcasecmp(type,"WITHDRAW") == 0)
		{
			printf("\tWithdrawal amount: ");
			fgets(terminalInput,sizeof(terminalInput),stdin);
			sscanf(terminalInput, "%s", terminalInput);
			if (validateMoney(terminalInput) != -1)
			{
				money = validateMoney(terminalInput);
				if (balance < money)
				{
					printf("\tSorry, you do not have enough in your account\n");
				}
				else
				{
					balance-=money;
					totalwithdraw+=money;
					timewithdraw++;
					fprintf(pOut, "WD\t%.2lf\tBAL\t%.2lf\n", (double)money, (double)balance);
				}
			}
			else
			{
				printf("Error\n");
			}
		}
		else if(strcasecmp(type,"DISPLAY") == 0)
		{
			printf("\tYour currentBalance is now %ld baht\n", balance);
		}
		else
		{
			printf("Error - What you type is wrong!\n");
		}
	}

	printf("Transaction summary:\n");
	printf("Initial balance:\t\t%.2f\n",(double) startingBalance);
	printf(" %d deposits, total:\t\t%.2f\n",timeDeposit,(double) totalDeposit);
	printf(" %d withdrawals, total:\t\t%.2f\n",timewithdraw,(double) totalwithdraw);
	printf("Final balance:\t\t\t%.2f\n",(double) balance);

	fclose(pOut);
}