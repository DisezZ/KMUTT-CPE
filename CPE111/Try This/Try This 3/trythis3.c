/*  trythis3.c
 *
 *  Extremely simple demo using list nodes that include the 
 *  node data as well as the link. The program reads a set
 *  of product names and prices from a file, then lets the
 *  user search for an item by name and prints the price.
 *
 *  Created by Sally Goldin, 16 January 2015 for CPE113
 *  Name: Lutfee Deemae   ID: 63070503448
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* structure to represent a list item */
typedef struct _item
{
   char product[64];    /* product name */
   double price;        /* unit price for the product */
   struct _item *pNext; /* link to the next product */
} ITEM_T;

/* declarations for functions defined after main */
void printAllProducts(ITEM_T *pListHead);
void findPrintProduct(ITEM_T *pListHead, char *productname);
void freeList(ITEM_T *pListHead);

/* print how to use */
void usage()
{
   printf("Usage:   simpleLinkedList [inputfile]\n\n");
   exit(0);
}

int main(int argc, char *argv[])
{
   char input[128];      /* for reading from file and terminal */
   char filename[128];   /* name of data file */
   ITEM_T *pHead = NULL; /* head (start) of linked list */
   ITEM_T *pTail = NULL; /* tail (end) of linked list */
   ITEM_T *pItem = NULL; /* use for allocating new items */
   FILE *pFp = NULL;     /* file pointer for reading data */
   char tempname[64];    /* for parsing name from the file */
   double tempprice = 0; /* for parsing the price */
   int productcount = 0; /* tell the user how many products in the file */
   int bDone = 0;

   if (argc < 2)
      usage();
   strcpy(filename, argv[1]);
   pFp = fopen(filename, "r");
   if (pFp == NULL)
   {
      printf("Error opening input file '%s'\n", filename);
      exit(1);
   }
   /* read and parse file. Create a new ITEM_T for each line and
    * add it to the end of the linked list 
    */
   while (fgets(input, sizeof(input), pFp) != NULL)
   {
      memset(tempname, 0, sizeof(tempname));
      /* by setting to all zeros each time, we can detect a blank line */
      tempprice = 0.0;
      sscanf(input, "%s %lf", tempname, &tempprice);
      if ((strlen(tempname) == 0) || (tempprice == 0.0))
         continue; /* skip the blank line */
      pItem = (ITEM_T *)calloc(1, sizeof(ITEM_T));
      if (pItem == NULL)
      {
         printf("Memory allocation error - exiting\n");
         exit(2);
      }
      /* copy data to our new item */
      strncpy(pItem->product, tempname, sizeof(pItem->product) - 1);
      pItem->price = tempprice;
      /* Now add to the end of the linked list */
      if (pHead == NULL) /* if this is the first item */
      {
         pHead = pTail = pItem; /* it becomes the first item - AND the last! */
      }
      else
      {
         pTail->pNext = pItem; /* point the current end to our new item */
         pTail = pItem;        /* our new item is now the end of the list */
      }
      productcount++;
   }
   printf("Read %d products from '%s'\n", productcount, filename);
   fclose(pFp);

   /* THIS FUNCTION NEEDS TO BE IMPLEMENTED */
   printAllProducts(pHead);

   /* Now enter a search loop */
   memset(tempname, 0, sizeof(tempname));
   while (!bDone)
   {
      printf("Enter product to search for (DONE to end): ");
      fgets(input, sizeof(input), stdin);
      sscanf(input, "%s", tempname);
      if (strcmp(tempname, "DONE") == 0)
         bDone = 1;
      else
         findPrintProduct(pHead, tempname);
   }
   freeList(pHead);
   return 0;
}

/* start at the head of the list and
 * print the product name and price for every
 * product read from the file
 * Arguments:
 *   pListHead    First item in the list 
 */
void printAllProducts(ITEM_T *pListHead)
{
   /** ADD YOUR CODE HERE */
   int i = 0;
   ITEM_T *pListCurrent = pListHead;
   printf("Available prodocts:\n");
   while (pListCurrent != NULL)
   {
      printf("%2d) %-20s Price: %.2f\n", i + 1, pListCurrent->product, pListCurrent->price);
      ++i;
      pListCurrent = pListCurrent->pNext;
   }
}

/* Search the linked list for a product with a name that
 * matches 'productname'. If found, print the price. Otherwise
 * print a message saying the product does not exist
 */
void findPrintProduct(ITEM_T *pListHead, char *productname)
{
   ITEM_T *pCurrent = pListHead;
   while (pCurrent != NULL)
   {
      if (strcasecmp(pCurrent->product, productname) == 0)
      {
         printf(" >> The unit price for '%s' is %0.2lf baht\n",
                pCurrent->product, pCurrent->price);
         break; /* we don't need to look further since we have found it */
      }
      pCurrent = pCurrent->pNext; /* otherwise, go to the next item */
   }
   if (pCurrent == NULL) /* we got to the end without finding it */
   {
      printf(" >> Product '%s' does not exist in this file\n", productname);
   }
}

/* Go through the list, freeing each item. 
 * We need to be careful to keep a pointer to the next
 * item before we free the current item.
 * pListHead -- first item in the list 
 */
void freeList(ITEM_T *pListHead)
{
   ITEM_T *pCurrent = pListHead;
   ITEM_T *pFreeMe = NULL;
   while (pCurrent != NULL)
   {
      pFreeMe = pCurrent;
      pCurrent = pCurrent->pNext;
      free(pFreeMe);
   }
}
