/* Implementation of vowelCountHash function
 *
 *    Created by Sally Goldin, 1 April 2019 for CPE111
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* hash value is count of vowels in the key, mod with table size */
int vowelCountHash(char * keyval, int tableSize)
{
   char * vowels = "aeiouAEIOU";
   int i = 0;                /* loop counter */
   int hashval = 0;          /* for accumulating result */         	
   for (i = 0; i < strlen(keyval); i++)
      {
      if (strchr(vowels,keyval[i]) != NULL)
          hashval++;
      }
   return hashval % tableSize;
}

/* calculate and return the hash value 
 *  argv[1] is string to hash in quotes, argv[2] is table size
 */
int main(int argc, char* argv[])
{

  int result;
  int tablesize;
  char keyval[128];
  if (argc < 3)
    {
    printf("./applyHash [key in quotes] [tablesize]\n\n");
    exit(1);
    }
  strncpy(keyval,argv[1],sizeof(keyval));
  tablesize = atoi(argv[2]);
  result = vowelCountHash(keyval,tablesize);
  printf("Hash value for |%s| is %d\n",
	 keyval,result);
}

 
