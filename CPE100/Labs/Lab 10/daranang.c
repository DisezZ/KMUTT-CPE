/****************************************************************
 *	
 *	daranang.c
 *
 *		This program is	
 *			
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		4 November 2020
 *
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
     char firstname[32];
     char lastname[32];
     char gender;
     int movieCount;
     int rating;
} MOVIESTAR_T; 

/* Initialize one movie star in the array (‘which’) based on line read 
 * from the file (‘inputline’)*/
void parseStar(char inputLine[], MOVIESTAR_T movieStar[], int which);

/* Print information for one movie star in the array (‘which’) into the file 
* which is already open with file handle ‘pOutput’ */
void printStar(FILE* pFileOutput, MOVIESTAR_T movieStar[], int which);

int main(int argc,char* argv[])
{
	char terminalInput[32]; /* a variable to get a input from terminal that user input */
	char inputLine[128];
	int i;
	FILE *pFileInput = NULL;
	FILE *pFileOutput = NULL;
	MOVIESTAR_T movieStar[10];

	if(argc < 3)
	{
		printf("Error - Command line must include input and output files\n");
		exit(0);
	}
	else
	{
		pFileInput = fopen(argv[1],"r");
		if (pFileInput == NULL)
		{
			printf("Error - Can't open %s\n", argv[1]);
			exit(0);
		}
		i=0;
		while (fgets(inputLine,sizeof(inputLine),pFileInput) != NULL && i<10)
		{
			//printf("%s\n", inputLine);
			parseStar(inputLine,movieStar,i);
			//printf("%s %s %c %d %d\n", movieStar[i].firstname, movieStar[i].lastname, movieStar[i].gender, movieStar[i].movieCount, movieStar[i].rating);
			i++;
		}
		fclose(pFileInput);

		pFileOutput = fopen(argv[2],"w");
		if (pFileOutput == NULL)
		{
			printf("Error - Can't open %s\n", argv[2]);
			exit(0);
		}
		for (int j = 0; j < i; ++j)
		{
			printStar(pFileOutput,movieStar,j);
		}
		fclose(pFileOutput);
		printf("Hello\n");
	}
}

void parseStar(char inputLine[], MOVIESTAR_T movieStar[], int which)
{
	int i = which;
	sscanf(inputLine,"%s %s %c %d %d", movieStar[i].firstname, movieStar[i].lastname, &movieStar[i].gender, &movieStar[i].movieCount, & movieStar[i].rating);
}

void printStar(FILE* pFileOutput, MOVIESTAR_T movieStar[], int which)
{
	int j = which;
	fprintf(pFileOutput, "Movie star #%d\nName: %s %s\nGender: %c\nNumber of movies: %d\nPopular rating: %d\n\n", j+1, movieStar[j].firstname, movieStar[j].lastname, movieStar[j].gender, movieStar[j].movieCount, movieStar[j].rating);
}



/*********************************************

fgets(terminalInput,sizeof(terminalInput),stdin);
sscanf(terminalInput,"%",&);

**********************************************
*/