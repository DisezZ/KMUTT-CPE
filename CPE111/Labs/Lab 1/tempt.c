/*********************************************************************
 *  couples.c
 *      This program takes information from input file and ask for a couple 
 *      then display all corrent cuoples to the terminal
 * 
 *      Created by Lutfee Deemae    ID 63070503448
 *      19 January 2021
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
} PERSON_T;

int main(int argc, char *argv[])
{
    FILE *pFileIn = NULL;     /* file variable for input file pointer */
    PERSON_T **people = NULL; /* pointer to hold a pointer of struct */
    PERSON_T *tempt = NULL;   /* pointer to hold struct */
    int count;                /* a variable to hold total number of people */
    int findStatus[2];        /* a vaiable to check that if that user enter is exist or not */
    char terminalInput[64];   /* a variable to get a terminal input from user */
    char fileName[64];        /* a variable to hold name of input file */
    char inputLine[64];       /* a variable to use as a buffer of a file input line */
    char nameInput[2][32];    /* a variable to hold a name of couple that user type */

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

    if (fgets(inputLine, sizeof(inputLine), pFileIn) == NULL)
    {
        printf("\tError - While reading number of person\n");
        exit(0);
    }
    sscanf(inputLine, "%d", &count);

    people = calloc(count, sizeof(PERSON_T *));
    if (people == NULL)
    {
        printf("\tError- While allocating array of %d people\n", count);
        exit(1);
    }

    for (int i = 0; i < count; i++)
    {
        if (fgets(inputLine, sizeof(inputLine), pFileIn) == NULL)
        {
            printf("\tError - While reading data at record %d\n", i + 1);
            exit(0);
        }
        tempt = calloc(1, sizeof(PERSON_T));
        if (tempt == NULL)
        {
            printf("\tError - While allocating for new data at record %d\n", i + 1);
            exit(0);
        }
        if (sscanf(inputLine, "%s%s", tempt->name, tempt->gender) != 2)
        {
            printf("\tError - While reading data at record %d\n", i + 1);
            exit(0);
        }

        people[i] = tempt;
    }

    printf("Welcome to couples program.\n");
    printf("Read %d people:\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("\t%s %s\n", people[i]->name, people[i]->gender);
    }

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

        findStatus[0] = -1;
        findStatus[1] = -1;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < count; j++)
            {
                if (strcasecmp(nameInput[i], people[j]->name) == 0)
                {
                    findStatus[i] = j;
                }
            }
        }
        if (findStatus[0] == -1 || findStatus[1] == -1)
        {
            if (findStatus[0] == -1)
            {
                printf("\tError: person %s does not exist\n", nameInput[0]);
                continue;
            }
            else
            {
                printf("\tError: person %s does not exist\n", nameInput[1]);
                continue;
            }
        }

        for (int j = 0; j < count; j++)
        {
            if (strcasecmp(nameInput[0], people[j]->name) == 0)
            {
                if (people[findStatus[1]]->pPartner != NULL)
                {
                    printf("\t%s is breaking up with %s and is now a couple with %s\n", nameInput[1], people[findStatus[1]]->pPartner->name, nameInput[0]);
                    people[findStatus[1]]->pPartner->pPartner = NULL;
                }
                people[findStatus[1]]->pPartner = people[j];
            }
            if (strcasecmp(nameInput[1], people[j]->name) == 0)
            {
                if (people[findStatus[0]]->pPartner != NULL)
                {
                    printf("\t%s is breaking up with %s and is now a couple with %s\n", nameInput[0], people[findStatus[0]]->pPartner->name, nameInput[1]);
                    people[findStatus[0]]->pPartner->pPartner = NULL;
                }
                people[findStatus[0]]->pPartner = people[j];
            }
        }
    }
    //printf("Exit\n");
    printf("Couples:\n");
    for (int i = 0; i < count; i++)
    {
        if (people[i]->pPartner != NULL)
        {
            printf("\t%s is coupled with %s\n", people[i]->name, people[i]->pPartner->name);
        }
    }
    printf("Bye!\n");

    fclose(pFileIn);
    for (int i = 0; i < count; i++)
    {
        free(people[i]);
    }
    free(people);
}