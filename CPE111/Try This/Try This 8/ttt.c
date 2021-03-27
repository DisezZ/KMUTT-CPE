/*  TryThis8
 *
 *  Implementing direct addressing
 *  This program reads data about students from a text file,
 *  creates a struct for each student, then stores the struct
 *  using direct addressing based on the student ID
 *
 *  Created by Sally Goldin, 20 March 2020
 *
 *  Name: Lutfee  Deemae  ID: 63070503448
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* value we must subtract to find the correct index */
#define BASEID 62070503400

typedef struct
{
    long studentID;     /* unique student ID */
    char firstname[64]; /* first name */
    char nickname[32];  /* nickname */
    char section[2];    /* section - C or D */
} STUDENT_T;

/* Main function reads the input file, creates a structure
 * for each student, and stores it in the allstudents[] array
 * using direct addressing to find the index.
 */

int hashID(long studentID);

int main()
{
    char inputline[128];           /* for reading the file or terminal*/
    STUDENT_T *thisStudent = NULL; /* used for dynamic allocation of structs*/
    STUDENT_T *allStudents[100];   /* table for direct address lookup */
    long searchID;                 /* holds the ID we are looking for */
    FILE *pFile = NULL;            /* for reading the input file */
    int index = -1;                /* index for storing or looking up in the array */
    int i = 0;                     /* for freeing memory at the end */

    /* set array to all NULLs so we can detect duplicates */
    for (i = 0; i < 100; i++)
        allStudents[i] = NULL;

    pFile = fopen("students.txt", "r");
    if (pFile == NULL)
    {
        printf("Cannot open the input file 'students.txt' - exiting\n");
        exit(1);
    }

    while (fgets(inputline, sizeof(inputline), pFile) != NULL)
    {
        thisStudent = calloc(1, sizeof(STUDENT_T));
        if (thisStudent == NULL)
        {
            printf("Allocation error - exiting\n");
            exit(2);
        }
        sscanf(inputline, "%ld %s %s %s", &thisStudent->studentID,
               thisStudent->firstname,
               thisStudent->nickname, thisStudent->section);
        /* Now calculate the index and store the structure in the array */

        searchID = thisStudent->studentID;
        index = (int)(thisStudent->studentID - 62070503400);
        if (index < 0 || index >= 100)
        {
            printf("Invalid student ID found - %ld\n", searchID);
        }
        else if (allStudents[index] != NULL)
        {
            printf("Duplicate student ID found - %ld\n", searchID);
        }
        else
        {
            allStudents[index] = thisStudent;
        }
        /** WRITE YOUR CODE HERE **/
        /** DON'T FORGET TO CHECK FOR INVALID ID VALUES AND DUPLICATES **/
    }

    fclose(pFile); /* done reading */

    while (1) /* loop, looking up students by direct addressing */
    {
        printf("Display information for what student ID? (-1 to exit) ");
        fgets(inputline, sizeof(inputline), stdin);
        sscanf(inputline, "%ld", &searchID);
        if (searchID < 0)
            break;
        /* Lookup the student using direct addressing */

        index = (int)(thisStudent->studentID - 62070503400);
        if (index < 0 || index >= 100)
        {
            printf("\tInvalid ID number!\n");
        }
        else if (allStudents[index] == NULL)
        {
            printf("\tNo student found with ID %ld\n", searchID);
        }
        else
        {
            printf("\tID: %ld\n", allStudents[index]->studentID);
            printf("\tFIRSTNAME: %s    NICKNAME: %s   SECTION: %s\n", allStudents[index]->firstname, allStudents[index]->nickname, allStudents[index]->section);
        }
        /** WRITE YOUR CODE HERE **/
        /** DON'T FORGET TO CHECK FOR INVALID ID VALUE **/
        /** REMEMBER STUDENT MIGHT NOT EXIST **/
    }

    for (i = 0; i < 100; i++)
    {
        if (allStudents[i] != NULL)
        {
            free(allStudents[i]);
        }
    }
    /** Don't free the array itself! It wasn't dynamically allocated! */
}

int hashID(long studentID)
{
    if (studentID < BASEID || studentID > BASEID + 99)
    {
        return -1;
    }
    else
    {
        return studentID - BASEID;
    }
}