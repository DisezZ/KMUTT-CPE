/* Implementation of lowerCountHash function
 *
 *    Created by Sally Goldin, 1 April 2019 for CPE111
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* hash value is count of lower case letters mod with table size. */
int lowerCountHash(char * key, int tablesize)
{
     int hashval = 0;
     int i = 0;
     for (i = 0; i < strlen(key); i++)
         {
         if (islower(key[i]))
             hashval++;
         }
     return (hashval % tablesize);
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
    printf("./applyHash2 [key in quotes] [tablesize]\n\n");
    exit(1);
    }
  strncpy(keyval,argv[1],sizeof(keyval));
  tablesize = atoi(argv[2]);
  result = lowerCountHash(keyval,tablesize);
  printf("Hash value for |%s| is %d\n",
	 keyval,result);
}

 
