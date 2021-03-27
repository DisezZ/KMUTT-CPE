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

/*  This function will do all the check if string is valid then it will 
 *  do the boolean calculation and then it will print the calculation 
 *  result 
 *  Argument :
 *      - string to process logic expressions
 * 
 * */
void validLogicString(char *logicString);

int main(int argc, char *argv[])
{
    char terminalInput[64]; /* variable ti use as terminal buffer */
    char logicString[64];   /* variable to hold logic string that user enter */

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
        sscanf(terminalInput, "%[^\n]s", logicString);
        stackClearInt();
        validLogicString(logicString);
    }
    printf("Bye\n");
}

void validLogicString(char *string)
{
    int underflow = 0;          /* variable to check underflow condition */
    int result;                 /* variable to hold result of the boolean calculation */
    int operator;               /* variable to hold operator 2 is &&, 3 is || */
    int operand[2];             /* variable to hold operand */
    int truthVal;               /* variable to hold the truth value of character */
    int status = 0;             /* variable to hold status of the string is valid or not */
    int size = 0;               /* variable to hold size of a new string that alreay parse */
    char wrongChar;             /* variable to hold wrong character that found in expression  */
    char logicString[64] = {0}; /* string to hold parsed string */

    for (int i = 0; i < strlen(string); i++)
    {
        if (!isupper(string[i]) && string[i] != ' ' && string[i] != '(' && string[i] != ')' && string[i] != '&' && string[i] != '|')
        {
            wrongChar = string[i];
            status = -1;
            break;
        }
        else
        {
            if (string[i] != ' ')
            {
                logicString[size] = string[i];
                ++size;
            }
        }
    }
    if (status == -1)
    {
        printf("\tInvalid character in expression: %c\n", wrongChar);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (logicString[i] == '(')
            {
                continue;
            }
            else if (logicString[i] != ')')
            {
                if (logicString[i] == '&')
                {
                    truthVal = 2;
                }
                else if (logicString[i] == '|')
                {
                    truthVal = 3;
                }
                else
                {
                    truthVal = (logicString[i] - 65) % 2;
                }

                if (pushInt(truthVal) == 0)
                {
                    printf("\tError - Stack Overflow\n");
                }
            }
            else
            {
                operand[1] = popInt();
                operator= popInt();
                operand[0] = popInt();
                if (operand[0] == UNDERFLOW || operand[0] == UNDERFLOW || operator== UNDERFLOW)
                {
                    underflow = 1;
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
                    printf("\tError - Stack Overflow\n");
                }
            }
        }
        //printDebugInt();

        result = popInt();
        if (stackSizeInt() != 0)
        {
            printf("\tInvalid expression syntax\n");
        }
        else if (underflow != 0)
        {
            printf("\tError - The stack is underflow\n");
        }
        else
        {
            printf("\t%s truth value is %s\n", logicString, result ? "TRUE" : "FALSE");
        }
    }
}
