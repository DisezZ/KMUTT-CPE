/*
 *   trythis4.c 
 *
 *   Linked List PARTIAL implementation of an abstract queue
 *
 *   Created by Sally Goldin, 31 Jan 2020, for CPE 111
 *  Name: Lutfee Deemae   ID: 63070503448
 */

#include <stdlib.h>
#include <stdio.h>
#include "abstractQueue.h"

/* our queue will be a linked list of these structures */
typedef struct _queueItem
{
   void *data;               /* data that will be stored on the queue */
   struct _queueItem *pNext; /* next item in the list */
} Q_ITEM_T;

Q_ITEM_T *pHead = NULL; /* first item on the queue */
Q_ITEM_T *pTail = NULL; /* laast item on the queue */
int count = 0;          /* number of items in the queue *

/**
 * Add a data item to the queue (end of the list)
 * Arguments:
 *   data      -   Pointer to generic data we want to add to queue   
 * Returns 1 if successful, 0 if failure
 */
int enqueue(void *data)
{
   int bOk = 1; /* set to 0 if an error occurs */
   /* ADD CODE TO ENQUEUE AN ITEM AND INCREMENT COUNT*/
   Q_ITEM_T *tempt;
   tempt = calloc(sizeof(Q_ITEM_T), 1);
   if (tempt == NULL)
   {
      bOk = 0;
   }
   else
   {
      tempt->data = data;
      if (pHead == NULL)
      {
         pHead = pTail = tempt;
      }
      else
      {
         pTail->pNext = tempt;
         pTail = tempt;
      }
      pTail->data = data;
      ++count;
   }

   return bOk;
}

/* Get the next item in the queue. This is the element 
 * at the front of the queue.
 * Returns the data stored at the front of the queue.
 * Also removes that item from the queue.
 * Returns NULL if the queue is empty.
 */
void *dequeue()
{
   Q_ITEM_T *removedItem = NULL;
   void *returnData = NULL;
   if (pHead != NULL) /* something on the queue */
   {
      /* remove the first item */
      removedItem = pHead;
      /* second item is now the head */
      pHead = pHead->pNext;
      /* if we just removed the last item, set the tail to NULL */
      if (pHead == NULL)
         pTail = NULL;
      returnData = removedItem->data;
      free(removedItem);
      count--;
   }
   return returnData;
}

/* Find out how many items are currently in the queue.
 * Return number of items in the queue (could be zero)
 */
int queueSize()
{

   return count;
}

/* Clear so we can reuse 
 */
void queueClear()
{
   /* ADD CODE TO CLEAR AND FREE THE ENTIRE QUEUE */
   Q_ITEM_T *pCurrent = pHead;
   Q_ITEM_T *tempt = NULL;
   while (pCurrent != NULL)
   {
      tempt = pCurrent;
      pCurrent = pCurrent->pNext;
      free(tempt);
   }
   pHead = pTail = NULL; /* do this last */
   count = 0;
}

/** DEBUGGING FUNCTION PRINTS SOME INFO ABOUT THE QUEUE **/
void printDebug()
{
   int i, j;
   Q_ITEM_T *pCurrent = pHead;
   printf("linkedListQueue\n");
   printf("current count = %d\n", count);
   if (count > 0)
   {
      printf("Contents: \n");
      /* ADD CODE TO SHOW THE CURRENT CONTENTS */
      /* YOU WILL NEED TO TRAVERSE THE LIST */
      i = 0;
      while (pCurrent != NULL)
      {
         printf("%d) %s\n", i + 1, pCurrent->data);
         pCurrent = pCurrent->pNext;
      }
   }
}
