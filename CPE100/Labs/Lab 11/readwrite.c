/****************************************************************
 *	
 *	readwrite.c
 *
 *		This program will get a database from binary file name students.dat 
 *		and print and create a new binary file name newstudents.dat and store that 
 *		value into new file.	
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		11 November 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void displayStudent(STUDENT_T studentInfo);

int main(int argc,char* argv[])
{
	int counter;	/* a variable for counting how many data have come */
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	FILE *fileInput = NULL;	/* a file pointer to hold file pointer for read */
	FILE *fileOutput = NULL;	/* a file to hold file pointer for write */
	STUDENT_T studentInfo[MAXCOUNT];

	fileInput = fopen("students.dat","rb");
	if (fileInput == NULL)
	{
		printf("Error - Can't open students.dat file\n");
		exit(0);
	}
	
	counter=0;
	while(1)
	{
		if (fread(&studentInfo[counter],sizeof(STUDENT_T),1,fileInput) == 0)
		{
			break;
		}
		if (counter == MAXCOUNT)
		{
			break;
		}
		++counter;
	}

	for (int i = 0; i < counter; ++i)
	{
		printf("#Number %d\n", i+1);
		displayStudent(studentInfo[i]);
	}

	fileOutput = fopen("newstudents.dat","wb");
	if (fileOutput == NULL)
	{
		printf("Error - Can't open newstudents.dat properly\n");
	}
	if (fwrite(studentInfo,sizeof(STUDENT_T),counter,fileOutput) != counter)
	{
		printf("Error - Couldn't write file properly\n");
	}

	fclose(fileInput);
	fclose(fileOutput);

}

void displayStudent(STUDENT_T studentInfo)
{
	printf("Name: %s\n", studentInfo.name);
	printf("Age: %d\n", studentInfo.age);
	printf("Gender: %c\n", studentInfo.gender);
	printf("Quiz Grade:\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("\t%d) %d\n", i+1, studentInfo.quizGrades[i]);
	}
	printf("GPA: %lf\n\n", studentInfo.gpa);
}


/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/