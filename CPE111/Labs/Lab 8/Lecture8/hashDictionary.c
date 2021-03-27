/*  hashDictionary.c
 *
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

#define BUCKET_COUNT 5003

/*  This struct will hold dicitonary information such
 *  as word and definition
 * */
typedef struct
{
    char word[64];
    char definition[128];

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
    int returnStatus;

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
    char inputLine[256];        /* an input buffer for file reading */
    char word[64];              /* an string buffer for word */
    char definition[128];       /* an string buffer for definition */
    int count = 0;              /* integer for hold number of line */
    int index = 0;              /* integer that will hold index of dictionary */
    int dummyCollision;
    int returnStatus;

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
            ++count;
            continue;
        }

        if (sscanf(inputLine, "%[^|]|%[^\n]", word, definition) != 2)
        {
            printf("Error - While read file from wordlist.txt at %d line\n", count + 1);
            ++count;
            continue;
        }
        ++count;
        pEntry = calloc(1, sizeof(DIC_ENTRY_T));
        if (pEntry == NULL)
        {
            printf("Error - While allocate the memory");
            exit(0);
        }
        strcpy(pEntry->word, word);
        strcpy(pEntry->definition, definition);

        returnStatus = hashTableInsert(pEntry->word, pEntry, &dummyCollision);
        if (returnStatus == 0)
        {
            printf("\tError - While insert %s at line %d to the hash table\n", pEntry->word, count);
        }
        else
        {
            
        }
    }
    fclose(pFileIn);
}

void prinDefinitions(char *word)
{
    DIC_ENTRY_T *pDictData; /* struct pointer that will hold each dictionary information */
    long time;

    recordTime(1);
    pDictData = hashTableLookup(word);
    time = recordTime(0);
    if (pDictData == NULL)
    {
        printf("\tLookup required %ld\n", time);
        printf("\t%s is not in this dictionary\n\n", word);
    }
    else
    {
        printf("Found definition for %s, Lookup required %ld ms\n", word, time);
        printf("\t%s\n", pDictData->definition);
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