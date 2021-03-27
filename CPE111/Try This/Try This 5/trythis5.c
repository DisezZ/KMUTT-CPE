/*  Trythuis5.c
 *      This program is will get user Nth of fibonacci  
 *      then it will give the user all the fibonacci number 
 *      before till the number that user enter
 * 
 *      Created by: Lutfee  Deemae  ID: 63070503448
 *      Created: 15 February 2021
 * */

#include <stdio.h>
#include <stdlib.h>

/*  This function will get the Nth of fibonacci number 
 *  then will return fibonacci value of that index
 *  Argument: - index of the fibonacci that are going to calculate
 *  Return: value of fibonacci on that index
 * */
int calculateFibonacci(int index);

int main()
{
    char terminalInput[64];   /* variable to hold input buffer */
    unsigned long result = 0; /* variable to hold result of the fibonacci */
    unsigned long count;      /* variable to hold number of index of fibonaccis */

    printf("Enter N (will print N+1 values)? ");
    fgets(terminalInput, sizeof(terminalInput), stdin);
    sscanf(terminalInput, "%ld", &count);
    printf("Here is your series:\n\n");
    for (int i = 0; i <= count; i++)
    {
        result = calculateFibonacci(i);
        printf("%ld ", result);
    }
    printf("\n");
}

int calculateFibonacci(int index)
{
    if (index == 0 || index == 1)
    {
        return index;
    }
    else
    {
        return calculateFibonacci(index - 1) + calculateFibonacci(index - 2);
    }
}