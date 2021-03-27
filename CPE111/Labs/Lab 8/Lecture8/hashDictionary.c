/*  hashDictionary.c
 *      Challenge #1 and #2 completed!
 *      This program will create dictionary that contain an word and definition
 *      from an input file then will let user ask for specific deinition and 
 *      then print out to terminal
 * 
 *      Created By Lutfee Deemae     ID: 63070503448
 *      Created 23 March 2021
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abstractHashTable.h"
#include "timeFunctions.h"

#define BUCKET_COUNT 53

/*  This struct will hold dicitonary information such
 *  as word and definition
 * */
typedef struct
{
    char word[64];
    char definition[3][128];

} DIC_ENTRY_T;

/* Robust hash function that uses bitwise operations to
 * modify string values. Adapted from Kyle Loudon,
 * "Mastering Algorithms with C"
 */
unsigned int bitwiseOpHash(char *key);

/*  This function will create dicitonary from an input file
 *  
 *  Argument: array of dicitonary 
 * */
void *buildDictionary();

/*  This function will print all definition that match the keyword
 *
 *  Argument: - array of dicitonary
 *            - string of keyword
 * */
void prinDefinitions(char *word);

int main(int argc, char *argv[])
{
    char terminalInput[64]; /* an string for terminal input buffer */
    char word[64];          /* an string for word that user want to find definition */
    int returnStatus;       /* an variable to temporary store return status code from functions */

    returnStatus = hashTableInit(BUCKET_COUNT, &bitwiseOpHash);
    if (returnStatus == 0)
    {
        printf("\tError - While initializing hash table\n");
        exit(0);
    }

    buildDictionary();
    while (1)
    {
        printf("Enter word to find the definition: ");
        fgets(terminalInput, sizeof(terminalInput), stdin);
        if (strcmp(terminalInput, "\n") == 0)
        {
            printf("Bye!\n");
            exit(0);
        }
        sscanf(terminalInput, "%s", word);
        prinDefinitions(word);
    }

    hashTableFree();
}

void *buildDictionary()
{
    FILE *pFileIn = NULL;       /* file pointer to a input file */
    DIC_ENTRY_T *pEntry = NULL; /* struct pointer that will hold each dictionary information */
    DIC_ENTRY_T *pTempt = NULL; /* struct pointer that will use for lookup in hash */
    char inputLine[256];        /* an input buffer for file reading */
    char word[64];              /* an string buffer for word */
    char definition[128];       /* an string buffer for definition */
    int index = 0;              /* integer that will hold index of dictionary */
    int lineCount = 0;          /* integer for hold number of line */
    int dummyCollision;         /* an integer to hold collision value */
    int collisionCount = 0;     /* an integer to hold total collision */
    int wordCount = 0;          /* an integer to hold total word that succesfully read */
    int returnStatus;           /* an variable to temporary store return status code from functions */

    pFileIn = fopen("wordlist.txt", "r");
    if (pFileIn == NULL)
    {
        printf("\tError - While open the file name wordlist.txt\n");
        exit(0);
    }

    while (fgets(inputLine, sizeof(inputLine), pFileIn) != NULL)
    {
        if (inputLine[0] == '\n' && strlen(inputLine) == 1)
        {
            ++lineCount;
            continue;
        }

        if (sscanf(inputLine, "%[^|]|%[^\n]", word, definition) != 2)
        {
            printf("Error - While read file from wordlist.txt at %d line\n", lineCount + 1);
            ++lineCount;
            continue;
        }
        ++lineCount;
        pTempt = hashTableLookup(word);
        if (pTempt == NULL)
        {
            pEntry = calloc(1, sizeof(DIC_ENTRY_T));
            if (pEntry == NULL)
            {
                printf("Error - While allocate the memory");
                exit(0);
            }
            strcpy(pEntry->word, word);
            strcpy(pEntry->definition[0], definition);

            returnStatus = hashTableInsert(pEntry->word, pEntry, &dummyCollision);
            if (returnStatus == 0)
            {
                printf("\tError - While insert %s at line %d to the hash table\n", pEntry->word, lineCount);
            }
            else
            {
                ++wordCount;
                if (dummyCollision == 1)
                {
                    ++collisionCount;
                }
            }
        }
        else
        {
            pEntry = pTempt;
            if (strlen(pEntry->definition[1]) == 0)
            {
                strcpy(pEntry->definition[1], definition);
            }
            else if (strlen(pEntry->definition[2]) == 0)
            {
                strcpy(pEntry->definition[2], definition);
            }
            else
            {
                printf("\tError - Exceed maximum definition for \"%s\" at line %d\n", pEntry->word, lineCount);
            }
        }
    }
    printf("Word: %d\n", wordCount);
    printf("Collision: %d\n", collisionCount);
    printf("Collision percentage is: %.2f%%\n\n", (double)collisionCount * 100.0 / (double)wordCount);
    fclose(pFileIn);
}

void prinDefinitions(char *word)
{
    DIC_ENTRY_T *pDictData; /* struct pointer that will hold each dictionary information */
    long time;              /* a integer that will hold time use in milli second */

    recordTime(1);
    pDictData = hashTableLookup(word);
    time = recordTime(0);
    printf("\tLookup required %ld ms\n", time);
    if (pDictData == NULL)
    {
        printf("\t%s is not in this dictionary\n\n", word);
    }
    else
    {
        printf("\tFound definition for %s\n", word);
        for (int i = 0; i < 3; i++)
        {
            if (strlen(pDictData->definition[i]) == 0)
            {
                break;
            }
            printf("\t%d)%s\n", i + 1, pDictData->definition[i]);
        }
    }
}

unsigned int bitwiseOpHash(char *key)
{
    unsigned int result = 0;
    unsigned int tmp = 0;
    int size = hashTableSize();
    int i = 0;
    for (i = 0; i < strlen(key); i++)
    {
        /* shift up four bits then add in next char */
        result = (result << 4) + key[i];
        if (tmp = (result & 0xf0000000)) /* if high bit is set */
        {
            /* XOR result with down shifted tmp */
            result = result ^ (tmp >> 24);
            /* then XOR with tmp itself */
            result = result ^ tmp;
        }
    }
    result = result % size; /* make it fit in the table size */
    return result;
}