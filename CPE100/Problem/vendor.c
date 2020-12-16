/**********************************************
 * vendorInfo.c
 * Pada Cherdchoothai
 * 63070503439
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXCHAR 32

typedef struct
    {
    char name[MAXCHAR];
    char product[MAXCHAR];
    int income;
    } T_VENDORS;


int allAlpha(char testInput[])
    {
    int bValid = 1;
    for (int i = 0; i < strlen(testInput); ++i)
        {
        if (isalpha(testInput[i]) == 0)
            {
            bValid = 0;
            }
        }
    return bValid;
    }


int main(int argc, char *argv[])
    {
    int matchVendor = -1;
    int count = 0;
    int i = 0;
    double sum = 0;
    char fileName[MAXCHAR] = "\0";
    char inputLine[128] = "\0";
    char searchLine[MAXCHAR] = "\0";
    FILE *pIn = NULL;
    T_VENDORS vendorToCheck = {"\0", "\0", 0};

    T_VENDORS *vendors = NULL;

    if (argc == 2)
        {
        sscanf(argv[1], "%s", fileName);

        pIn = fopen(fileName, "r");
        if (pIn == NULL)
            {
            printf("can't open file\n");
            exit(2);
            }

        while (fgets(inputLine, sizeof(inputLine), pIn) != NULL)
            { count++; }
        rewind(pIn);

        vendors = (T_VENDORS *) calloc(sizeof(T_VENDORS), count);

        if (vendors == NULL)
            {
            printf("fail to allocate memory - exiting\n");
            exit(3);
            }

        while (fgets(inputLine, sizeof(inputLine), pIn) != NULL)
            {
            if (sscanf(inputLine, "%s %s %d", vendorToCheck.name, vendorToCheck.product, &vendorToCheck.income) == 3)
                {
                if (allAlpha(vendorToCheck.name))
                    {
                    if (allAlpha(vendorToCheck.product))
                        {
                        if (vendorToCheck.income >= 0)
                            {
                            strcpy(vendors[i].name, vendorToCheck.name);
                            strcpy(vendors[i].product, vendorToCheck.product);
                            vendors[i].income = vendorToCheck.income;
                            sum += vendors[i].income;
                            i++;
                            }
                        else
                            {
                            printf("income is negative - skipping\n");
                            }
                        }
                    else
                        {
                        printf("product's name not all alphabet - skipping\n");
                        }
                    }
                else
                    {
                    printf("Name not all alphabet - skipping\n");
                    }
                }
            else
                {
                printf("detect bad line - skipping\n");
                }

            }


        printf("Read %d vendors from file %s\n", i, fileName);
        printf("Average weekly income was %.2lf baht\n\n", (double) sum / count);

        while (strcasecmp(searchLine, "DONE") != 0)
            {
            memset(inputLine, 0, sizeof(inputLine));
            printf("Search for what vendor? (DONE to end) ");
            fgets(inputLine, sizeof(inputLine), stdin);
            sscanf(inputLine, "%s", searchLine);
            if (strcasecmp(searchLine, "DONE") == 0)
                { break; }

            matchVendor = -1;
            for (int j = 0; j < count; j++)
                {
                if (strcasecmp(searchLine, vendors[j].name) == 0)
                    {
                    matchVendor = j;
                    break;
                    }
                }
            if (matchVendor != -1)
                {
                printf("%s sells %s and made %d baht last week\n", vendors[matchVendor].name,
                       vendors[matchVendor].product, vendors[matchVendor].income);
                }
            else
                {
                printf("No vendor found with the name '%s'\n", searchLine);
                }
            }
        printf("\nbye\n");
        free(vendors);
        fclose(pIn);
        }

    else
        {
        printf("not enough argument\n");
        exit(1);
        }
    }