/*  Dictionary.c
 *
 *      This program will create dictionary that contain an word and definition
 *      from an input file then will let user ask for specific deinition and 
 *      then print out to terminal
 * 
 *      Created By Lutfee Deemae     ID: 63070503448
 *      Created 2 March 2021
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedListUtil.h"

/*  This struct will hold dicitonary information such
 *  as word and definition
 * */
typedef struct
{
    char word[64];
    char definition[128];

} DIC_ENTRY_T;

/*  This function will create dicitonary from an input file
 *  
 *  Argument: array of dicitonary 
 * */
void *buildDictionary(LIST_HANDLE *dictionary);

/*  This function will get and word then return index for that word in
 *  the dictionary
 *  
 * Argument: string of word
 * */
int getDictIndex(char *word);

/*  This function will print all the content in the dictionary
 *
 *  Argument: array of dicitonary 
 * */
void printDictionary(LIST_HANDLE *dictionary);

/*  This function will free all the pointer in the dictionary
 *
 *  Argument: array of dicitonary 
 * */
void freeDictionary(LIST_HANDLE *dictionary);

/*  This function will print all definition that match the keyword
 *
 *  Argument: - array of dicitonary
 *            - string of keyword
 * */
void prinDefinitions(LIST_HANDLE *dictionary, char *word);

int main(int argc, char *argv[])
{
    LIST_HANDLE dictionary[26]; /* an array of list that will be use as dictionary */
    char terminalInput[64];     /* an string for terminal input buffer */
    char word[64];              /* an string for word that user want to find definition */

    memset(dictionary, 0, sizeof(dictionary));
    buildDictionary(dictionary);
    printDictionary(dictionary);
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
        prinDefinitions(dictionary, word);
    }
    freeDictionary(dictionary);
}

void *buildDictionary(LIST_HANDLE *dictionary)
{
    FILE *pFileIn = NULL;       /* file pointer to a input file */
    DIC_ENTRY_T *pEntry = NULL; /* struct pointer that will hold each dictionary information */
    LIST_HANDLE *pList = NULL;  /* list pointer that will be use iterating through list */
    char inputLine[256];        /* an input buffer for file reading */
    char word[64];              /* an string buffer for word */
    char definition[128];       /* an string buffer for definition */
    int count = 0;              /* integer for hold number of line */
    int index = 0;              /* integer that will hold index of dictionary */

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

        if (sscanf(inputLine, "%[^:]:%[^\n]", word, definition) != 2)
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

        index = getDictIndex(pEntry->word);
        if (dictionary[index] == NULL)
        {
            dictionary[index] = newList();
        }
        listInsertEnd(dictionary[index], pEntry);
    }
    fclose(pFileIn);
}

int getDictIndex(char *word)
{
    char c = tolower(word[0]); /* tempt varaible for swap from char to int */
    return (c - 'a');
}

void printDictionary(LIST_HANDLE *dictionary)
{
    LIST_HANDLE *pList;     /* list pointer that will be use iterating through list */
    DIC_ENTRY_T *pDictData; /* struct pointer that will hold each dictionary information */
    for (int i = 0; i < 26; i++)
    {
        pList = dictionary[i];
        if (pList == NULL)
        {
            printf("Nu such word with letter %c\n\n", i + 'a');
        }
        else
        {
            listReset(pList);
            pDictData = listGetNext(pList);
            while (pDictData != NULL)
            {
                printf("\tWord:\t%s\n", pDictData->word);
                printf("\tDefinition:\t%s\n", pDictData->definition);
                pDictData = listGetNext(pList);
            }
            printf("\n");
        }
    }
}

void freeDictionary(LIST_HANDLE *dictionary)
{
    LIST_HANDLE *pList;      /* list pointer that will be use iterating through list */
    DIC_ENTRY_T *pDictData;  /* struct pointer that will hold each dictionary information */
    DIC_ENTRY_T *pDictTempt; /* a tempt pointer to use for free operation */
    for (int i = 0; i < 26; i++)
    {
        pList = dictionary[i];
        if (pList != NULL)
        {
            listReset(pList);
            pDictData = listGetNext(pList);
            while (pDictData != NULL)
            {
                pDictTempt = listGetNext(pList);
                free(pDictData);
                pDictData = pDictTempt;
            }
            free(pList);
        }
    }
}

void prinDefinitions(LIST_HANDLE *dictionary, char *word)
{
    LIST_HANDLE *pList;      /* list pointer that will be use iterating through list */
    DIC_ENTRY_T *pDictData;  /* struct pointer that will hold each dictionary information */
    int definitionCount = 0; /* int that hold number of definition of that specific word */
    int i = 0;               /* tempt int for print order of definition */

    pList = dictionary[word[0] - 'a'];
    if (pList == NULL)
    {
        printf("\tNo word start with %c in this dictionaty\n\n", word[0]);
    }
    else
    {
        listReset(pList);
        pDictData = listGetNext(pList);
        while (pDictData != NULL)
        {
            if (strcasecmp(pDictData->word, word) == 0)
            {
                ++definitionCount;
            }
            pDictData = listGetNext(pList);
        }
        if (definitionCount == 0)
        {
            printf("\t%s is not in this dictionary\n\n", word);
        }
        else
        {
            printf("Found %d definition for %s\n", definitionCount, word);
            listReset(pList);
            pDictData = listGetNext(pList);
            while (pDictData != NULL)
            {
                if (strcasecmp(pDictData->word, word) == 0)
                {
                    printf("\t%2d) %s\n", i + 1, pDictData->definition);
                    ++i;
                }
                pDictData = listGetNext(pList);
            }
            printf("\n");
        }
    }
}