/***************************************************************
 *
 *	classnumber
 *	
 *		This program asks the user for a number, then determines
 *	 	which of the following categories it belongs to 0,5,-7 or other
 *
 *
 *		Created by Lutfee Deemae (Lut) ID 63070503448
 *		1 September 2020
 *		
 ***************************************************************
 */

#include<stdio.h>
#include <string.h>
int main()
{
	char input[32]; 	/* variable for terminal input */
	int in; 	/* for contained user input */
	char output[32];

	fgets(input,sizeof(input),stdin);
	sscanf(input,"%d",&in);

	/* the following if determine what categories of input are belongs to */
	if(in == 0)
	{
		/*printf("%d belongs to class Zero\n",in);*/
		strcpy(output,"belongs to class Zero");
	}
	else if((in % 5 == 0) && (in > 0))
	{
		//printf("%d is a positive multiple of 5\n",in);
		strcpy(output,"is a positive multiple of 5");
	}
	else if((in % -7 ==0) && (in < 0))
	{
		//printf("%d is a negative multiple of 7\n",in);
		strcpy(output,"is a negative multiple of 7");
	}
	else
	{
		//printf("%d belongs to class Other\n",in);
		strcpy(output,"belongs to class Other");
	}
	printf("%d %s\n", in, output);
}