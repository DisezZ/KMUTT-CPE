/*
Tue. 9 Feb 2021
Created by Vananya Pruksapun (Fern) 63070503449
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "integerStack.h"

int validateSym(char stringToCheck[]);

int validateSym(char stringToCheck[])
{
    int result = 1;
    int countLeftSym = 0;
    int countRightSym = 0;
    int countSym = 0;
    int countOp = 0;
    int i = 0;
    printf("%s\n", stringToCheck);
    for (i = 0; i < strlen(stringToCheck); i++)
    {
        if (stringToCheck[i] == ' ')
        {
            continue;
            printf("%d", result);
        }
        else if (strlen(stringToCheck) == 1)
        {
            if (isupper(stringToCheck[i]) != 0)
            {
                result++;
            }
            else
            {
                result = 0;
            }
            printf("%d", result);
        }
        else
        {
            if (stringToCheck[i] == '(')
            {
                countLeftSym++;
            }
            else if (stringToCheck[i] == ')')
            {
                countRightSym++;
            }
            else if ((stringToCheck[i] == '|') || stringToCheck[i] == '&')
            {
                countOp++;
            }
            else if (isupper(stringToCheck[i]) == 0)
            {
                result = 0;
                //break;
            }
            printf("%d", result);
        }
        //printf("%d\n", result);
    }

    if ((countOp < 1) && (countSym == 0) && (stackSizeInt() != 0))
    {
        result = 0;
    }

    if ((countOp != countLeftSym) || (countOp != countRightSym))
    {
        result = 0;
    }
    return result;
}

int main()
{
    int loop = 0;
    int truthValue = 0;
    int result = 0;
    int v1;
    int v2;
    int op;
    int status;
    char stringInput[64];

    printf("Welcome to LogicEval!");
    printf("A, C, E, etc are false; B, D, F, etc are true\nUse '&' for AND and '|' for OR, '(' and ')' for nesting\n");

    while (1)
    {
        printf("Enter logical expression to evaluate: ");
        fgets(stringInput, sizeof(stringInput), stdin);
        sscanf(stringInput, "%[^\n]s", stringInput);

        if (strcasecmp(stringInput, "done") == 0)
        {
            break;
        }

        result = validateSym(stringInput);
        printf("result = %d\n", result);
        if (result != 0)
        {
            stackClearInt();
            status = 1;
            for (loop = 0; loop < strlen(stringInput); loop++)
            {
                if (stringInput[loop] == '(' || stringInput[loop] == ' ')
                {
                    continue;
                }
                else if (stringInput[loop] == ')')
                {
                    v2 = popInt();
                    op = popInt();
                    v1 = popInt();

                    if ((v1 == UNDERFLOW) || (v2 == UNDERFLOW) || (op == UNDERFLOW))
                    {
                        status = 0;
                        break;
                    }
                    else if (((v1 != 0) && (v1 != 1)) || ((v2 != 0) && (v2 != 1)) || ((op != 38) && (op != 124)))
                    {
                        status = 0;
                        break;
                    }
                    if (op == 38)
                    {
                        result = v1 && v2;
                    }
                    else if (op == 124)
                    {
                        result = v1 || v2;
                    }
                    pushInt(result);
                }
                else
                {
                    if (isalpha(stringInput[loop]))
                    {
                        truthValue = (stringInput[loop] - 65) % 2;
                        pushInt(truthValue);
                    }
                    else
                    {
                        pushInt(stringInput[loop]);
                    }
                }
            }
            result = popInt();
            if (status = 0)
            {
                printf("Invalid expression syntax\n");
            }
            else if (stackSizeInt() != 0)
            {
                printf("Invalid expression syntax\n");
            }
            else
            {
                if (result == 0)
                {
                    printf("%s truth value is %s \n", stringInput, "FALSE");
                }
                else
                {
                    printf("%s truth value is %s \n", stringInput, "TRUE");
                }
            }
        }
        else
        {
            printf("Invalid expression character\n");
        }
    }
}
