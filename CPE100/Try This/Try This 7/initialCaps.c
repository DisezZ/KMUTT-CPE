/****************************************************************
 *	
 *	initialCaps
 *
 *		This program is	taking a string from command line and 
 *		turn first letter of that string to uppercase and after that is
 *		lowercase  by using function called capitalizeWord
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		22 September 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* make a word be "initial caps".
 *   word is the word to change
 * Returns the number of characters whose case has changed.
 */
int capitalizeWord(char word[]);

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	int charactersChanged;	/* a variable to get a return from capitalizeWord */
	char stringInput[64]="";	/* a variable to store argv[1] string */
	char stringOutput[64]="";	/* a variable to store stringInput after capitalizeWord() function done */

	if(argc>=2)
	{	
		strcpy(stringInput,argv[1]);
		charactersChanged= capitalizeWord(stringInput);
		strcpy(stringOutput,stringInput);
		
		printf("Characters changed: %d\n",charactersChanged );
		printf("Result: %s\n", stringInput);
	}
	else
	{
		printf("Error! You must provide a word on the command line.ss\n");
	}

}

int capitalizeWord(char word[])
{
	int totalChanged;
	totalChanged=0;
	
	for (int i = 0; i < strlen(word); ++i)
	{
		if((i == 0) && (islower(word[i])))
		{
			word[i] = toupper(word[i]);
			++totalChanged;
		}
		else if((i > 0) && (isupper(word[i])))
		{
			word[i] = tolower(word[i]);
			++totalChanged;
		}
	}

	return totalChanged;
}




/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/