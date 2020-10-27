/*  racecar2 on Lab1
 *	This is a program that calculate how far a racing car will travel in a given time
 *	assuming that it is going at a specific, constant speed. The speed will be specified in meters per second.
 *	and have a acceleration rate in this as well 
 *	The distance should be displayed in kilometers
 *	Created by Lutfee Deemae (Lut) ID 63070503448
 *	19 August 2020
 */

#include<stdio.h>

int main()
{
	char stringEntered[100]; /* String for user input */
	double startingSpeed; /*user input for a speed*/
	double acceleration; /* user in put for acceleration of a car */
	double time; /* user input for a time */	
	double distanced; /* final answer of distanced for a car can go*/
	double endingSpeed; /* final seed of a car when its reach a time */

	/* get a starting speed of a car */
	printf("How fast is the car traveling (m/sec)?");
	fgets(stringEntered,sizeof(stringEntered),stdin);
	sscanf(stringEntered,"%lf",&startingSpeed);

	/* get a rate of acceleration of a car */
	printf("What is the rate of acceleration (m/sec2)?");
	fgets(stringEntered,sizeof(stringEntered),stdin);
	sscanf(stringEntered,"%lf",&acceleration);

	/* get a time that spent */
	printf("How many seconds does the car travel?");
	fgets(stringEntered,sizeof(stringEntered),stdin);
	sscanf(stringEntered,"%lf",&time);

	/* equation for calculating a distanced of a car */
	endingSpeed = startingSpeed + (acceleration * time);
	distanced = (((endingSpeed + startingSpeed) / 2) * time) / 1000;


	printf("In %.0lf seconds, the racecar will travel %.4lf kilometers.",time,distanced);
}