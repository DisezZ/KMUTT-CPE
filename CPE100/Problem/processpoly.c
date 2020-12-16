#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct
{
	int x;
	int y;
} XY;

double calculatePerimeter(int x1, int x2, int y1, int y2)
{
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int main(int argc, char* argv[])
{
	FILE* pFileIn = NULL;
	XY coordinateInput[8];
	char terminalInput[64];
	char fileInputName[64];
	char fileInput[64];
	int xInput[8];
	int yInput[8];
	int count = 0;
	double perimeter = 0;
	
	if (argc < 2)
	{
		printf("Usage: processpoly [inputfile]\n");
		exit(0);
	}
	sscanf(argv[1], "%s", fileInputName);
	
	pFileIn = fopen(fileInputName, "r");
	if (pFileIn == NULL)
	{
		printf("Error trying to open file '%s'\n", fileInputName);
		exit(1);
	}
	
	while (fgets(fileInput, sizeof(fileInput), pFileIn) != NULL)
	{
		sscanf(fileInput, "%d %d", &coordinateInput[count].x, &coordinateInput[count].y);
		++count;
	}
	
	if (count >= 3 && count <= 8)
	{
		for(int i = 0; i < count; ++i)
		{
			if(i+1 == count)
			{
				perimeter += calculatePerimeter(coordinateInput[i].x, coordinateInput[0].x, coordinateInput[i].y, coordinateInput[0].y);
			}
			else
			{
				perimeter += calculatePerimeter(coordinateInput[i].x, coordinateInput[i+1].x, coordinateInput[i].y, coordinateInput[i+1].y);
			}
		}
		
		printf("Polygon has %d points\n", count);
		printf("Perimeter is %.2lf\n", perimeter);
	}
	else if(count < 3)
	{
		printf("Error - Polygon has fewer than 3 points\n");
	}
	else
	{
		printf("Error - Polygon has more than 8 points\n");		
	}
}

