/****************************************************************
 *	
 *	classRank
 *
 *		This program is	get a count of student and then get the name and grade of that student and find a maximum
 *		and minimum grades of students in class	
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		16 September 2020
 *
 ****************************************************************
 */

#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXSTUDENTS 20
#define MAXLEN 32

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	char studentNames[MAXSTUDENTS][MAXLEN];	/* an array for collect each stdudent name in class */
	int studentGrades[MAXSTUDENTS];	/* an array to collect each student grade in class */
	int studentInput;	/* a variable to collect a number of student in class */
	int minindex;	/* a variable to collect a index of minimum grades of student in class */
	int maxindex;	/* a variable to collect a index of maximum grades of student in class */

	maxindex=0;
	minindex=0;

	while(1)
	{
		printf("How many students in the class (max is 20)? ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&studentInput);
		if(studentInput>20)
		{
			printf("Sorry, this program can handle no more than 20 students\n");
		}
		else
		{
			break;
		}
	}
	
	for (int i = 0; i < studentInput; ++i)
	{
		while(1)
		{
			printf("Name for student %d? ",i+1);
			fgets(terminalInput,sizeof(terminalInput),stdin);
			sscanf(terminalInput,"%s",studentNames[i]);
			if(strlen(studentNames[i])>=2)
			{
				break;
			}
			else
			{
				printf("the name given is error. must have atleast two characters\n");
			}
		}
		while(1)
		{
			printf("Grade for student %d? ",i+1);
			fgets(terminalInput,sizeof(terminalInput),stdin);
			sscanf(terminalInput,"%d",&studentGrades[i]);
			if((studentGrades[i]>=0)&&(studentGrades[i]<=100))
			{
				break;
			}
			else
			{
				printf("the grades given is error. must be between 1 and 100\n");
			}
		}

		if(studentGrades[i]<studentGrades[minindex])
		{
			minindex=i;
		}
		if (studentGrades[i]>studentGrades[maxindex])
		{
			maxindex=i;
		}
	}

	printf("%s had the highest grade in the class (%d)\n",studentNames[maxindex],studentGrades[maxindex] );
	printf("%s had the lowest grade in the class (%d)\n",studentNames[minindex],studentGrades[minindex] );

}




/*********************************************

fgets(,sizeof(),stdin);
sscanf(,"%",&);

**********************************************
*/