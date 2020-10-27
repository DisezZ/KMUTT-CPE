/*
 *
 *	movieticket
 *
 *		this program calculated expected price of a movie ticket
 *		from a input of a user
 *
 *	Created by Lutfe Deemae (Lut) ID 63070503448
 *		26 August 2020
 *
 */

#include <stdio.h>
int main()
{
	char input[32]; /* input variable for terminal input */ 
	int in; /* input of a user that is in a integer type */
	int output;

	fgets(input,sizeof(input),stdin);
	sscanf(input,"%d",&in);

	if((in <= 0) || (in>25))
	{
		output=-1;
	}
	else if((in <= 5) && (in >= 1))
	{
		output=100;
	}
	else if((in <= 15) && (in >= 6))
	{
		output=150;
	}
	else
	{
		output=200;
	}

	if(output==-1)
	{
		printf("Give an error message\n");
	}
	else
	{
		printf("%d",output);
	}
}