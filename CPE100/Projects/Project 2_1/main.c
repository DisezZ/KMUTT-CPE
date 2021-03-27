#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char passportNumber[18];
    char name[64];
    char internationalPhone[20];
    char birthDate[11];
    char nowDate[11];
    char gender;
    int day;
    int month;
    int year;
    int dayNow;
    int monthNow;
    int yearNow;
} HOSPITAL_T;

int main(int argc, char *argv[])
{
    printf("H");
    char terminalInput[64]; /* a variable to get a input from terminal that user input */
    char choice[64];
    int temp;
    int size;
    HOSPITAL_T *records = NULL;
    HOSPITAL_T record;
    FILE *pFileIn = NULL;
    FILE *pFileOut = NULL;
    printf("1");
    pFileIn = fopen("database.dat", "rb");
    printf("d");
    if (pFileIn == NULL)
    {
        temp = 0;
        pFileOut = fopen("database.dat", "wb");
        fwrite(&temp, sizeof(int), 1, pFileOut);
        fclose(pFileOut);
        fclose(pFileIn);
    }
}
