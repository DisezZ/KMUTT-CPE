/****************************************************************
 *	
 *	readwrite2.c
 *
 *		This program will get a database from binary file name students.dat 
 *		and print and create a new binary file name newstudents.dat and store that 
 *		value into new file.	
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		18 November 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void displayStudent(STUDENT_T studentInfo);

int main(int argc,char* argv[])
{
	int count;	/* a variable for store how many data have come */
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	char fileInputName[64]; /* a variable to store a file name of input file */
	char fileOutputName[64];	/* a variable to store a file name of output file */
	FILE *fileInput = NULL;	/* a file pointer to hold file pointer for read */
	FILE *fileOutput = NULL;	/* a file to hold file pointer for write */
	STUDENT_T* studentInfo = NULL;	/* a pointer variable for dynamic memory allocation of input */

	if (argc < 2)
	{
		printf("Error, Please enter file input name!\n");
		exit(0);
	}

	strcpy(fileInputName,argv[1]);
	fileInput = fopen(fileInputName,"rb");
	if (fileInput == NULL)
	{
		printf("Error - Can't open students.dat file\n");
		exit(0);
	}

	if (fread(&count, sizeof(int), 1, fileInput) == 0)
	{
		printf("Error - Can't read count from file\nExit now!\n");
		exit(0);
	}

	studentInfo = calloc(count, sizeof(STUDENT_T));
	if (studentInfo == NULL)
	{
		printf("Error - Can't allocate memory\nExit now!\n");
		exit(0);
	}

	if (fread(studentInfo, sizeof(STUDENT_T), count, fileInput) != count)
	{
		printf("Error - Can't read data from file\nExit now!\n");
		exit(0);
	}

	for (int i = 0; i < count; ++i)
	{
		printf("#Number %d\n", i+1);
		displayStudent(studentInfo[i]);
	}

	strcpy(fileOutputName,"new");
	strcat(fileOutputName,fileInputName);
	fileOutput = fopen(fileOutputName,"wb");
	if (fileOutput == NULL)
	{
		printf("Error - Can't open %s properly\n", fileOutputName);
		exit(0);
	}

	if (fwrite(&count, sizeof(int), 1, fileOutput) == 0)
	{
		printf("Error - Can't write file size of data properly\nExit now!\n");
		exit(0);
	}

	if (fwrite(studentInfo,sizeof(STUDENT_T),count,fileOutput) != count)
	{
		printf("Error - Couldn't write file data properly\nExit now!\n");
		exit(0);
	}

	free(studentInfo);
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