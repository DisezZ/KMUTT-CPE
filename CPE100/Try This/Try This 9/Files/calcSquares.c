/*
 *  calcSquares
 *
 *  Very simple program to illustrate input and output redirection.
 *
 *  Created by Sally Goldin, 12 October 2014 for CPE100
 *  Updated 13 Oct 2015
 */
#include <stdio.h>
#include <stdlib.h>

/* print a table of squares from 1 to the maxval 
 */
int main()
   {
   char input[32];
   int maxval = 0;  /* limit for squares table */
   int num = 0;     /* loop variable */
   printf("What is the maximum value you want to use? ");
   fgets(input,sizeof(input),stdin);
   sscanf(input,"%d",&maxval);
   if (maxval <= 0)
      {
      fprintf(stderr,"Maxvalue must be a positive integer\n\n");
      exit(1);
      }
   if (maxval > 1000)
      {
      fprintf(stdout,"Maximum value is too big. Reduce to 1000? (Y/N) ");
      fgets(input,sizeof(input),stdin);
      if ((input[0] == 'Y') || (input[0] == 'y'))  
          maxval = 1000;
      else
	  exit(2);
      }
   printf("%10s %10s\n","Number","Square");
   printf("%10s %10s\n","======","======");
   for (num = 1; num <= maxval; num++)
      {
      printf("%10d %10d\n",num,num*num);
      }  
   }
 
