/* 
 *	evenodd
 *		This is a program to find the input are inter or odd
 *		
 *		Created by Lutfee Deemae (Lut) ID 63070503448
 *      25 August 2020   
 */
#include <stdio.h>
int main(int argc, char const *argv[])
{
	char input[30]; /* input from user*/
	int in; /* int for using as input */
	int checker=2; /* checker to check if input is odd or even */

	printf("Pleasetype an integer:");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%d",&in);

	if (in % checker == 0)
	{
		printf("The number %d is even\n",in);
	}
	else
	{
		printf("The number %d is odd\n",in);
	}
	return 0;
}