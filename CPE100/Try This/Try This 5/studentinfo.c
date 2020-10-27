/***************************************************************
 *
 *	studentinfo
 *	
 *		This program is ask for user to input a student ID to
 *		check GPA of that student ID.
 *
 *		Created by Lutfee Deemae (Lut) ID 63070503448
 *		8 September 2020
 *		
 ***************************************************************
 */
#define MAXSIZE 10
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int studentId[MAXSIZE]={3440,3441,3442,3443,3444,3445,3446,3447,3448,3449}; /* a student ID of each student */
	double gpa[MAXSIZE]={2.0,2.15,3.8,3.5,1.5,1.8,3.25,2.8,1.95,1.4}; /* a gpa of each student */
	char terminalInput[32];
	int input;
	int checker;

	checker=1;
	do
	{
		printf("View which student (1-10)? ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&input);
		if(input==-1)
		{
			checker=0;
			printf("Goodbye!\n");
			exit(-1);
		}
		else if((input>=1)&&(input<=10))
		{
			printf("Student %d has GPA %.2lf\n",studentId[input-1],gpa[input-1]);
		}
	}while(checker==1);
}