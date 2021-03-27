/* Trythis1.c
 * Quick exercise for pointer review - created by S.Goldin 4 Jan 2019
 * Name: Lutfee Deemae   ID: 63070503448
 */
#include <stdio.h>
int main()
{
  int value1 = 35;
  int value2 = -16;
  double value3 = 202.14;
  int * pInteger = NULL;
  double * pDouble = NULL;

  /* Task 1:  Set pInteger to the address of value1 */
  pInteger = &value1;


  /* Task 2:  Set pDouble to the address of value3 */
  pDouble = &value3;


  /* Task 3:  Use pDouble plus the derefencing operator 
   * to add 20.5 to the contents of pDouble */
  *pDouble += 20.5;


  /* Task 4:  Use pInteger plus the dereferencing operator
   * to set the contents of pInteger to the value stored in value2 */
  *pInteger = value2;


  /* Task 5:  Print the current contents of value1,value2 and value 3*/
  printf("value1 is %d\nvalue2 is %d\nvalue3 is %f\n", value1, value2, value3);


}