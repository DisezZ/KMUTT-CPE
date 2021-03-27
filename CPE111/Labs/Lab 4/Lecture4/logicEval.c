/*
 *  logicEval.c
 * 
 *      This program will calculate set of logic string and then will calculate
 *      the boolean value of that logic string
 * 
 *      Created by Lutfee   Deemae ID: 60370503448
 *      Created 9 Febuary 2021
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "integerStack.h"

/*  This function will validate the string if the string is
 *  valid as a logic string or not
 *  Arguement :
 *      - address of string that want to validate
 *      - address of integer that we want to keep the validation status
 *        change to 0 if not valid
 *      - address of character that we will use in report print if string is not valid
 * */
void validString(char *string, int *status, char *reportChar);

/*  This function will parse the string and left all space
 *  Argument :
 *      - address of string that will parsed into
 *      - address of string that will be parsed
 * */
void parseString(char *string, char *buffer);

/*  This function will do evaluate the logic string
 *  Argument :
 *      - address of string that will be evaluate but need to be parsed first
 *      - address of integer that will keep status of the evaluating
 *        change to -1 if error, to 1 or 0 if success
 *      - address of pointer to report string
 *        string will be null if no error, no if have error
 * 
 * */
void evaluateLogic(char *string, int *status, char **reportString);

int main(int argc, char *argv[])
{
    int status1;             /* variable to hold status of validating string */
    int status2;             /* variable to hold status of evaluating string */
    char terminalInput[128]; /* variable to hold user input buffer */
    char logicBuffer[128];   /* variable to hold logic string buffer */
    char logicString[128];   /* variable to hold logic string that will be evaluate */
    char wrongChar;          /* variable to hold wrong character that will use in report to terminal */
    char *reportString;      /* variable to hold report cstring that will use in terminal */

    printf("Welcome to LogicEval!\n\n");
    printf("A,C,E, etc are false; B,D,F, etc are true\n");
    printf("Use '&' for AND and '|' for OR, '(' and ')' for nesting\n\n");
    while (1)
    {
        printf("Enter logical expression to evaluate: ");
        fgets(terminalInput, sizeof(terminalInput), stdin);
        if (strcasecmp(terminalInput, "DONE\n") == 0)
        {
            break;
        }
        sscanf(terminalInput, "%[^\n]s", logicBuffer);

        status1 = 1;
        validString(logicBuffer, &status1, &wrongChar);
        if (status1 == 0)
        {
            printf("\tInvalid character in expression: %c\n", wrongChar);
            continue;
        }

        parseString(logicString, logicBuffer);

        status2 = 2;
        reportString = NULL;
        evaluateLogic(logicString, &status2, &reportString);
        if (status2 != 1 && (status2 == -1))
        {
            printf("%s", reportString);
        }
        else
        {
            printf("\t %s truth value is %s\n", logicString, status2 ? "TRUE" : "FALSE");
        }
        if (reportString != NULL)
        {
            free(reportString);
        }
    }
    printf("Bye\n");
}

void validString(char *string, int *status, char *reportChar)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (!isupper(string[i]) && string[i] != ' ' && string[i] != '(' && string[i] != ')' && string[i] != '&' && string[i] != '|')
        {
            *reportChar = string[i];
            *status = 0;
            break;
        }
    }
}

void parseString(char *string, char *buffer)
{
    int count = 0; /* variable that will keep track of index parsed string */

    for (int i = 0; i < 128; i++)
    {
        string[i] = 0;
    }
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] != ' ')
        {
            string[count] = buffer[i];
            ++count;
        }
    }
}

void evaluateLogic(char *string, int *status, char **reportString)
{
    int underflow = 0; /* a variable to hold underflow status, 1 if underflow, 0 if not  */
    int operand[2];    /* variable to hold overand 1 and 2 */
    int operator;      /* variable to hold overator 2 if and, 3 if or */
    int result = 0;    /* variable to hold hold result of ecaluating logic string */
    int truthVal;      /* varible to hold truth value of the character */
    int parenthesisCount[2] = {0};
    int operatorCount = 0;

    stackClearInt();
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '(')
        {
            ++parenthesisCount[0];
            continue;
        }
        else if (string[i] != ')')
        {

            if (string[i] == '&')
            {
                ++operatorCount;
                truthVal = 2;
            }
            else if (string[i] == '|')
            {
                ++operatorCount;
                truthVal = 3;
            }
            else
            {
                truthVal = (string[i] - 65) % 2;
            }

            if (pushInt(truthVal) == 0)
            {
                *status = -1;
                *reportString = strdup("\tError - Stack Overflow\n");
                break;
            }
        }
        else if (string[i] == ')')
        {
            ++parenthesisCount[1];
            operand[1] = popInt();
            operator= popInt();
            operand[0] = popInt();
            if (operand[0] == UNDERFLOW || operand[0] == UNDERFLOW || operator== UNDERFLOW)
            {
                underflow = 1;
            }
            else if ((operand[0] != 0 && operand[0] != 1) || (operand[1] != 0 && operand[1] != 1) || (operator!= 2 && operator!= 3))
            {
                *status = -1;
                *reportString = strdup("\tInvalid expression syntax\n");
                break;
            }
            else
            {
                if (operator== 2)
                {
                    result = operand[0] && operand[1];
                }
                else if (operator== 3)
                {
                    result = operand[0] || operand[1];
                }
            }
            if (pushInt(result) == 0)
            {
                *status = -1;
                *reportString = strdup("\tError - Stack Overflow\n");
                break;
            }
        }
    }

    result = popInt();
    if (stackSizeInt() != 0)
    {
        *status = -1;
        *reportString = strdup("\tInvalid expression syntax\n");
    }
    else if ((parenthesisCount[0] != parenthesisCount[1]) || (parenthesisCount[0] != operatorCount))
    {
        *status = -1;
        *reportString = strdup("\tInvalid expression syntax\n");
    }
    else if (underflow != 0)
    {
        *status = -1;
        *reportString = strdup("\tError - The stack is underflow\n");
    }
    else if (*status == 2)
    {
        *status = result;
    }
}
