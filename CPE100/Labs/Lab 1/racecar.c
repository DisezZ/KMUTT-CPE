/*  racecar on Lab1
 *	This is a program that calculate how far a racing car will travel in a given time
 *	assuming that it is going at a specific, constant speed. The speed will be specified in meters per second. 
 *	The distance should be displayed in kilometers
 *	Created by Lutfee Deemae (Lut) ID 63070503448
 * 	19 August 2020
 */

#include<stdio.h>

int main()
{
	char stringEntered[100]; /* String for user input */
	double speed; /*user input for a speed*/
	double time; /* user input for a time */	
	double distanced; /* final answer of distanced for a car can go*/

	/* get a speed of a car */
	printf("How fast is the car traveling (m/sec)?");
	fgets(stringEntered,sizeof(stringEntered),stdin);
	sscanf(stringEntered,"%lf",&speed);

	/* get a time that spent */
	printf("How many seconds does the car travel?");
	fgets(stringEntered,sizeof(stringEntered),stdin);
	sscanf(stringEntered,"%lf",&time);

	distanced = speed * time / 1000;
	printf("In %.0lf seconds, the racecar will travel %.4lf kilometers.",time,distanced);
}