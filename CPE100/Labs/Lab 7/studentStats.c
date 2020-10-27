/****************************************************************
 *	
 *	studentStats
 *
 *		This program is	a program that will get a student grades and then calculate the average grades
 *		and then calculate the standard derivative and then send back to main with pointer address
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		7 October 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Get 'count' quiz grades for the student with the name 'studentName'
 * and store the results in the 'grades' array.
 */
void getQuizGrades(char studentName[], int grades[], int count);

/* Calculate the mean (average) and standard deviation for a set of 'count' grades
 * stored in the 'grades' array.
 * Return the calculated standard deviation in the address pointed to by 'pSD'.
 * Return the average as the function value.
 */
double calculateGrades(int grades[], int count, double* pSD);


int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	int quizCount;	/* a variable that hold a number of quiz that all student have */
	int quizGrade[10]={0};	/* an array that hold a quiz grades of each student  */
	char studentName[32]={0};	/* an array that will hold a name of that student */
	int counter;	/* a variable that use to tell the user how many time they run repeat task */
	double standardDerivative;	/* a variable that use to hold a standard derivative of student */
	double averageGrade;	/* a variable that use to hold a average grade of student */

	counter = 0;

	while(1)
	{
		printf("How many quizzes in the course (max is 10)? ");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&quizCount);
		if(quizCount >= 2 && quizCount <= 10)
		{
			break;
		}
		printf("Error, the number must be between 2 to 10\n");
	}

	while(1)
	{
		++counter;
		printf("Enter name of student %d: ", counter);
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%s",studentName);
		if(strcmp(studentName,"DONE")==0)
		{
			printf("Goodbye!\n");
			break;
		}

		getQuizGrades(studentName,quizGrade,quizCount);
		averageGrade=calculateGrades(quizGrade,quizCount,&standardDerivative);
		printf("\n%s's average grade is %.2lf\n", studentName, averageGrade);
		printf("The standard deviation is %.4lf\n\n", standardDerivative);
	}
}

void getQuizGrades(char studentName[], int grades[], int count)
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	for (int i = 0; i < count; ++i)
	{
		printf("Quiz grade %d for %s: ", i+1, studentName);
		fgets(terminalInput,sizeof(terminalInput), stdin);
		sscanf(terminalInput,"%d", &grades[i]);
	}
}

double calculateGrades(int grades[], int count, double* pSD)
{
	double averageGrade;	/* a variable that use to hold a average grade of student */
	double gradeSum;	/* a temporary variable to hold summation of student grades */
	double temporarySummation;	/* a temporary variable to hold summation of square of student grade minus wth average grade */
	
	gradeSum = 0;
	temporarySummation = 0;

	for (int i = 0; i < count; ++i)
	{
		gradeSum += grades[i];
	}
	averageGrade = gradeSum/count;

	for (int i = 0; i < count; ++i)
	{
		temporarySummation += pow(grades[i]-averageGrade,2);
	}
	*pSD = sqrt(temporarySummation/(count-1));

	return averageGrade;
}


/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/