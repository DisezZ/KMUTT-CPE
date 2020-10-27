/*
 *
 *	movieticket2
 *
 *		this program calculated expected price of a movie ticket
 *		from a input of a user by using a switch in C
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

	switch(in) /* to check input is conncet to which case */
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			output=100;
			break;

		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			output=150;
			break;
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
			output=200;
			break;

		default:
			output=-1;
			break;
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