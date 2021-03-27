/*********************************************************************
 *  LinkCouples.c
 *      This program takes information from input file and ask for a couple 
 *      then display all corrent cuoples to the terminal
 * 
 *      Created by Lutfee Deemae    ID 63070503448
 *      2 Febuary 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person
{
    char name[32];            /* person's name */
    char gender[2];           /* person's gender */
    struct _person *pPartner; /* pointer to another PERSON_T 
                                      who is this person's partner.*/
    struct _person *pNext;

} PERSON_T;

int main(int argc, char *argv[])
{
    FILE *pFileIn = NULL;   /* file variable for input file pointer */
    PERSON_T *tempt = NULL; /* pointer to hold struct */
    PERSON_T *pHead = NULL;
    PERSON_T *pTail = NULL;
    PERSON_T *pCurrent = NULL;
    PERSON_T *pDelete = NULL;
    PERSON_T *findStatus[2]; /* a vaiable to check that if that user enter is exist or not */
    int count;               /* a variable to hold total number of people */
    int j;
    int status;
    char terminalInput[64]; /* a variable to get a terminal input from user */
    char fileName[64];      /* a variable to hold name of input file */
    char inputLine[64];     /* a variable to use as a buffer of a file input line */
    char nameInput[2][32];  /* a variable to hold a name of couple that user type */

    if (argc < 2)
    {
        printf("\tError - Need atleast 2 arguments\n");
        exit(0);
    }

    sscanf(argv[1], "%s", fileName);
    pFileIn = fopen(fileName, "r");
    if (pFileIn == NULL)
    {
        printf("\tError - Can't open file name \"%s\"\n", fileName);
        exit(0);
    }

    count = 0;
    while (fgets(inputLine, sizeof(inputLine), pFileIn) != NULL)
    {
        tempt = calloc(1, sizeof(PERSON_T));
        if (tempt == NULL)
        {
            printf("\tError - While allocating for new data at record %d\n", count + 1);
            exit(0);
        }
        if (sscanf(inputLine, "%s%s", tempt->name, tempt->gender) != 2)
        {
            printf("\tError - While reading data at record %d\n", count + 1);
            exit(0);
        }
        if (pHead == NULL)
        {
            pHead = pTail = tempt;
        }
        pTail->pNext = tempt;
        pTail = tempt;
        ++count;
    }

    printf("Welcome to couples program.\n");
    printf("Read %d people:\n", count);
    pCurrent = pHead;
    while (pCurrent != NULL)
    {
        printf("\t%s %s\n", pCurrent->name, pCurrent->gender);
        pCurrent = pCurrent->pNext;
    }
    printf("\n");

    while (1)
    {
        printf("Enter couple: ");
        fgets(terminalInput, sizeof(terminalInput), stdin);
        if (strcasecmp(terminalInput, "DONE\n") == 0)
        {
            break;
        }

        if (sscanf(terminalInput, "%s%s", nameInput[0], nameInput[1]) != 2)
        {
            printf("\tError: you must enter two names\n");
            continue;
        }

        findStatus[0] = NULL;
        findStatus[1] = NULL;
        for (int i = 0; i < 2; i++)
        {
            pCurrent = pHead;
            while (pCurrent != NULL)
            {
                if (strcasecmp(nameInput[i], pCurrent->name) == 0)
                {
                    findStatus[i] = pCurrent;
                    break;
                }
                pCurrent = pCurrent->pNext;
            }
        }
        if (findStatus[0] == NULL || findStatus[1] == NULL)
        {
            if (findStatus[0] == NULL)
            {
                printf("\tError: person %s does not exist\n", findStatus[0]->name);
                continue;
            }
            else
            {
                printf("\tError: person %s does not exist\n", findStatus[1]->name);
                continue;
            }
        }

        if (strcasecmp(findStatus[0]->gender, findStatus[1]->gender) == 0)
        {
            printf("\tError - Couple can't be the same gender\n");
            continue;
        }

        if (strcasecmp(nameInput[0], findStatus[0]->name) == 0)
        {
            if (findStatus[0]->pPartner != NULL)
            {
                printf("\t%s is breaking up with %s and is now a couple with %s\n", nameInput[0], findStatus[0]->pPartner->name, nameInput[1]);
                findStatus[0]->pPartner->pPartner = NULL;
            }
            findStatus[0]->pPartner = findStatus[1];
        }
        if (strcasecmp(nameInput[1], findStatus[1]->name) == 0)
        {
            if (findStatus[1]->pPartner != NULL)
            {
                printf("\t%s is breaking up with %s and is now a couple with %s\n", nameInput[1], findStatus[1]->pPartner->name, nameInput[0]);
                findStatus[1]->pPartner->pPartner = NULL;
            }
            findStatus[1]->pPartner = findStatus[0];
        }
    }
    //printf("Exit\n");
    printf("\nCouples:\n");
    pCurrent = pHead;
    while (pCurrent != NULL)
    {
        if (pCurrent->pPartner != NULL)
        {
            printf("\t%s is coupled with %s\n", pCurrent->name, pCurrent->pPartner->name);
        }
        pCurrent = pCurrent->pNext;
    }

    printf("Bye!\n");

    fclose(pFileIn);

    pDelete = NULL;
    pCurrent = pHead;
    while (pCurrent != NULL)
    {
        pDelete = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pDelete);
    }
}
