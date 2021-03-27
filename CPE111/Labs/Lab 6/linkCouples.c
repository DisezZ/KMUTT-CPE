/*********************************************************************
 *  LinkCouples.c
 *      This program takes information from input file and ask for a couple 
 *      then display all corrent cuoples to the terminal
 * 
 *      Created by Lutfee Deemae    ID 63070503448
 *      23 February 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person
{
    char name[32];              /* person's name */
    char gender[2];             /* person's gender */
    struct _person *pPartner;   /* pointer to another PERSON_T 
                                      who is this person's partner.*/
    struct _person *pLeftChild; /* pointer to another PERSON_T who is next one */
    struct _person *pRightChild;

} PERSON_T;

/*  This function will do the read files, create linked list node for each data and
 *  linked them together
 *  Argument :
 *      - pFileIn pointer for read files
 *      - pHead pointer to pointer for store the head address for linked list
 *      - pTail pointer to pointer for store the tail address for linked list
 *  Return : integer for number of size that read in
 * */
int readFiles(FILE *pFileIn, PERSON_T **pRoot);

/*  This function will do the find person task and return the pointer of struct
 *  Argument :
 *      - pHead pointer to pointer for replicate the head address of linked list
 *      - personName string that we will find in linked list
 *  Return : pointer to struct for address for node that match the name or null if any doesn't match
 * */
PERSON_T *findPerson(PERSON_T *pCurrent, char *pFindNode);

/*  This function will do the find person task and return the pointer of struct
 *  Argument :
 *      - pHead pointer to pointer for replicate the head address of linked list
 *      - personName string that we will find in linked list
 *  Return : pointer to struct for address for node that match the name or null if any doesn't match
 * */
void insertNode(PERSON_T *pCurrentNode, PERSON_T *pNewNode);

/*  This function will do the find person task and return the pointer of struct
 *  Argument :
 *      - pHead pointer to pointer for replicate the head address of linked list
 *      - personName string that we will find in linked list
 *  Return : pointer to struct for address for node that match the name or null if any doesn't match
 * */
void traverseInOrder(PERSON_T *pCurrentNode, void (*nodeFunction)(PERSON_T *pNode));

/*  This function will do the find person task and return the pointer of struct
 *  Argument :
 *      - pHead pointer to pointer for replicate the head address of linked list
 *      - personName string that we will find in linked list
 *  Return : pointer to struct for address for node that match the name or null if any doesn't match
 * */
void traversePostOrder(PERSON_T *pCurrentNode, void (*nodeFunction)(PERSON_T *pC));

/*  This function will do the find person task and return the pointer of struct
 *  Argument :
 *      - pHead pointer to pointer for replicate the head address of linked list
 *      - personName string that we will find in linked list
 *  Return : pointer to struct for address for node that match the name or null if any doesn't match
 * */
void printAll(PERSON_T *pCurrentNode);

/*  This function will do the find person task and return the pointer of struct
 *  Argument :
 *      - pHead pointer to pointer for replicate the head address of linked list
 *      - personName string that we will find in linked list
 *  Return : pointer to struct for address for node that match the name or null if any doesn't match
 * */
void displayCouples(PERSON_T *pCurrentNode);

/*  This function will do the find person task and return the pointer of struct
 *  Argument :
 *      - pHead pointer to pointer for replicate the head address of linked list
 *      - personName string that we will find in linked list
 *  Return : pointer to struct for address for node that match the name or null if any doesn't match
 * */
void freeTree(PERSON_T *pCurrentNode);

int main(int argc, char *argv[])
{
    FILE *pFileIn = NULL;    /* file variable for input file pointer */
    PERSON_T *pTempt = NULL; /* pointer to hold struct */
    PERSON_T *pRoot = NULL;
    PERSON_T *pCurrent = NULL; /* pointer to current position of the linked list */
    PERSON_T *pFree = NULL;    /* pointer that we want to free from the linked list */
    PERSON_T *findStatus[2];   /* a vaiable to check that if that user enter is exist or not */
    int count;                 /* a variable to hold total number of people */
    int deleteStatus;          /* a variable to  hold deleting status */
    int printTempt;            /* a variable to check if that person already printed or not */
    char terminalInput[64];    /* a variable to get a terminal input from user */
    char fileName[64];         /* a variable to hold name of input file */
    char inputLine[64];        /* a variable to use as a buffer of a file input line */
    char nameInput[2][32];     /* a variable to hold a name of couple that user type */
    char deleteCommand = 'S';  /* a variable to hold delete command that user type */
    char deleteName[64];       /* a variable to hold delete name that user type */

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

    count = readFiles(pFileIn, &pRoot);

    printf("Welcome to couples program.\n");
    printf("Read %d people:\n", count);
    printf("\nDo you want to print all the peoples (\"Yes\" or else)?: ");
    fgets(terminalInput, sizeof(terminalInput), stdin);
    if (strcasecmp(terminalInput, "yes\n") == 0)
    {
        traverseInOrder(pRoot, &printAll);
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
        findStatus[0] = findPerson(pRoot, nameInput[0]);
        findStatus[1] = findPerson(pRoot, nameInput[1]);

        if (findStatus[0] == NULL || findStatus[1] == NULL)
        {
            //printf("%s\b%s\n", findStatus[0]->name, findStatus[1]->name);
            if (findStatus[1] == NULL)
            {
                printf("\tError: person %s does not exist\n", nameInput[1]);
                continue;
            }
            else if (findStatus[0] == NULL)
            {
                printf("\tError: person %s does not exist\n", nameInput[0]);
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
    printf("\nCouples:\n");
    pCurrent = pRoot;
    traverseInOrder(pRoot, &displayCouples);

    printf("Bye!\n");

    fclose(pFileIn);

    pFree = NULL;
    traversePostOrder(pRoot, &freeTree);
}

int readFiles(FILE *pFileIn, PERSON_T **pRoot)
{
    PERSON_T *pTempt = NULL; /* pointer to hold struct */
    PERSON_T *pFindByName = NULL;
    int count = 0;
    char inputLine[64];
    while (fgets(inputLine, sizeof(inputLine), pFileIn) != NULL)
    {
        pTempt = calloc(1, sizeof(PERSON_T));
        if (pTempt == NULL)
        {
            printf("\tError - While allocating for new data at record %d\n", count + 1);
            exit(0);
        }
        if (sscanf(inputLine, "%s%s", pTempt->name, pTempt->gender) != 2)
        {
            printf("\tError - While reading data at record %d\n", count + 1);
            exit(0);
        }
        if (*pRoot == NULL)
        {
            *pRoot = pTempt;
            ++count;
        }
        else
        {
            pFindByName = NULL;
            pFindByName = findPerson(*pRoot, pTempt->name);
            if (pFindByName == NULL)
            {
                insertNode(*pRoot, pTempt);
                ++count;
            }
        }
    }
    return count;
}

void insertNode(PERSON_T *pCurrentNode, PERSON_T *pNewNode)
{
    if (strcmp(pNewNode->name, pCurrentNode->name) <= 0)
    {
        if (pCurrentNode->pLeftChild == NULL)
        {
            pCurrentNode->pLeftChild = pNewNode;
        }
        else
        {
            insertNode(pCurrentNode->pLeftChild, pNewNode);
        }
    }
    else
    {
        if (pCurrentNode->pRightChild == NULL)
        {
            pCurrentNode->pRightChild = pNewNode;
        }
        else
        {
            insertNode(pCurrentNode->pRightChild, pNewNode);
        }
    }
}

PERSON_T *findPerson(PERSON_T *pCurrentNode, char *findName)
{
    PERSON_T *findStatus = NULL;
    if (pCurrentNode != NULL)
    {
        if (strcmp(pCurrentNode->name, findName) == 0)
        {
            findStatus = pCurrentNode;
        }
        else if (strcasecmp(findName, pCurrentNode->name) < 0)
        {
            findStatus = findPerson(pCurrentNode->pLeftChild, findName);
        }
        else
        {
            findStatus = findPerson(pCurrentNode->pRightChild, findName);
        }
    }
    return findStatus;
}

void traverseInOrder(PERSON_T *pCurrentNode, void (*nodeFunction)(PERSON_T *pC))
{
    if (pCurrentNode->pLeftChild != NULL)
    {
        traverseInOrder(pCurrentNode->pLeftChild, nodeFunction);
    }
    (*nodeFunction)(pCurrentNode);
    if (pCurrentNode->pRightChild != NULL)
    {
        traverseInOrder(pCurrentNode->pRightChild, nodeFunction);
    }
}

void traversePostOrder(PERSON_T *pCurrentNode, void (*nodeFunction)(PERSON_T *pC))
{
    if (pCurrentNode->pLeftChild != NULL)
    {
        traverseInOrder(pCurrentNode->pLeftChild, nodeFunction);
    }
    if (pCurrentNode->pRightChild != NULL)
    {
        traverseInOrder(pCurrentNode->pRightChild, nodeFunction);
    }
    (*nodeFunction)(pCurrentNode);
}

void printAll(PERSON_T *pCurrentNode)
{
    printf("\t%s %s\n", pCurrentNode->name, pCurrentNode->gender);
}

void displayCouples(PERSON_T *pCurrentNode)
{
    if (pCurrentNode->pPartner != NULL)
    {
        printf("\t%s is coupled with %s\n", pCurrentNode->name, pCurrentNode->pPartner->name);
    }
}

void freeTree(PERSON_T *pCurrentNode)
{
    free(pCurrentNode);
}
