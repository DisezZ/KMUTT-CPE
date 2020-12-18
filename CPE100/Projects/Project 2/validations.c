/****************************************************************
 *	
 *	Template
 *
 *		This program is	
 *			
 *
 * 		Created by Lutfee Deemae (Lut) ID 63070503448
 *		x November 2020
 *
 ****************************************************************
 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "validations.h"

char passportCountryCodeList[][3] = {"AE", "AF", "AG", "AL", "AM", "AO", "AQ", "AR", "AS", "AT", "AU", "AW", "AX", "AZ", "BA", "BB", "BD", "BE",
                                     "BF", "BG", "BH", "BI", "BJ", "BL", "BM", "BN", "BO", "BQ", "BR", "BS", "BT", "BV", "BW", "BY", "BZ", "CA",
                                     "CC", "CD", "CF", "CG", "CH", "CI", "CK", "CL", "CM", "CN", "CO", "CR", "CU", "CV", "CW", "CX", "CY", "CZ",
                                     "DE", "DJ", "DK", "DM", "DO", "DZ", "EC", "EE", "EG", "EH", "ER", "ES", "ET", "FI", "FJ", "FK", "FM", "FO",
                                     "FR", "GA", "GB", "GD", "GE", "GF", "GG", "GH", "GI", "GL", "GM", "GN", "GP", "GQ", "GR", "GS", "GT", "GU",
                                     "GW", "GY", "HK", "HM", "HN", "HR", "HT", "HU", "ID", "IE", "IL", "IM", "IN", "IO", "IQ", "IR", "IS", "IT",
                                     "JE", "JM", "JO", "JP", "KE", "KG", "KH", "KI", "KM", "KN", "KP", "KR", "KW", "KY", "KZ", "LA", "LB", "LC",
                                     "LI", "LK", "LR", "LS", "LT", "LU", "LV", "LY", "MA", "MC", "MD", "ME", "MF", "MG", "MH", "MK", "ML", "MM",
                                     "MN", "MO", "MP", "MQ", "MR", "MS", "MT", "MU", "MV", "MW", "MX", "MY", "MZ", "NA", "NC", "NE", "NF", "NG",
                                     "NI", "NL", "NO", "NP", "NR", "NU", "NZ", "OM", "PA", "PE", "PF", "PG", "PH", "PK", "PL", "PM", "PN", "PR",
                                     "PS", "PT", "PW", "PY", "QA", "RE", "RO", "RS", "RU", "RW", "SA", "SB", "SC", "SD", "SE", "SG", "SH", "SI",
                                     "SJ", "SK", "SL", "SM", "SN", "SO", "SR", "SS", "ST", "SV", "SX", "SY", "SZ", "TC", "TD", "TF", "TG", "TH",
                                     "TJ", "TK", "TL", "TM", "TN", "TO", "TR", "TT", "TV", "TW", "TZ", "UA", "UG", "UM", "US", "UY", "UZ", "VA",
                                     "VC", "VE", "VG", "VI", "VN", "VU", "WF", "WS", "YE", "YT", "ZA", "ZM", "ZW"};

void handleGetDateNow(int *day, int *month, int *year)
{
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    *day = local->tm_mday;         // get day of month (1 to 31)
    *month = local->tm_mon + 1;    // get month of year (1 to 12)
    *year = local->tm_year + 2443; // get year since 2443 of Buddhist year
}

int handlePassportNumberValidation(char passportNumber[])
{
    int passportNumberFormatStatus = 0;
    int countryCodeStatus = -1;
    int numberStatus = 0;
    char countryCode[3];

    if (!isalpha(passportNumber[0]) || !isalpha(passportNumber[1]))
    {
        printf("\tNot Valid - Country code must be alphabet\n");
        return -1;
    }
    if (passportNumber[2] != '-')
    {
        printf("\tNot Valid - After country code must be dash\n");
        return -1;
    }
    if (strlen(passportNumber) < 11 || strlen(passportNumber) > 17)
    {
        printf("\tNot Valid - After dash must be alphanumeric 8-14 characters\n");
        return -1;
    }

    for (int i = 3; i < strlen(passportNumber); i++)
    {
        if (!isdigit(passportNumber[i]) && !isalpha(passportNumber[i]))
        {
            passportNumberFormatStatus = -1;
        }
    }
    if (passportNumberFormatStatus == -1)
    {
        printf("\tNot Valid - After dash must be only alphanumeric character\n");
        return -1;
    }

    if (passportNumberFormatStatus == 0)
    {
        sscanf(&passportNumber[0], "%c", &countryCode[0]);
        sscanf(&passportNumber[1], "%c", &countryCode[1]);
        countryCode[2] = 0;
        for (int i = 0; i < LEN(passportCountryCodeList); i++)
        {
            if (strcmp(passportCountryCodeList[i], countryCode) == 0)
            {
                countryCodeStatus = 0;
            }
        }
        if (countryCodeStatus == 0)
        {
            return 0;
        }
        else
        {
            printf("\tNot Valid - Country code is not valid\n");
            return -1;
        }
    }
}

int handleNameValidation(char name[])
{
    int nameStatus = 0;

    for (int i = 0; i < strlen(name); i++)
    {
        if (!isalpha(name[i]) && !isdigit(name[i]) && name[i] != ' ')
        {
            nameStatus = -1;
            printf("\tNot Valid - Name can contains with only alphabet, letter or space\n");
        }
    }
    return nameStatus;
}

int handleBirthDateValidation(char birthDate[])
{
    int day;
    int month;
    int year;

    if (handleDateFormatValidation(birthDate) != 0)
    {
        return -1;
    }

    sscanf(birthDate, "%d/%d/%d", &day, &month, &year);
    if (handleDateValueValidation(day, month, year) != 0)
    {
        return -1;
    }

    if (handleDateIsInPastValidation(day, month, year) != 0)
    {
        return -1;
    }

    return 0;
}

int handleDateFormatValidation(char date[])
{
    int dateFormatStatus = 0;
    for (int i = 0; i < strlen(date); i++)
    {
        if (i == 2 || i == 5 || i == 10)
        {
            if (i == 2 && date[i] != '/')
            {
                dateFormatStatus = -1;
                printf("\tNot Valid - After date (dd) must be slash\n");
                break;
            }
            else if (i == 5 && date[i] != '/')
            {
                dateFormatStatus = -1;
                printf("\tNot Valid - After month (mm) must be slash\n");
                break;
            }
            else if (i == 10 && date[i] != 0)
            {
                dateFormatStatus = -1;
                printf("\tNot Valid - After year (yyyy) must be and end\n");
                break;
            }
        }
        else
        {
            if (i < 2 && !isdigit(date[i]))
            {
                dateFormatStatus = -1;
                printf("\tNot Valid - Date (dd) must contains with only digit charaters\n");
                break;
            }
            else if (i < 5 && !isdigit(date[i]))
            {
                dateFormatStatus = -1;
                printf("\tNot Valid - Month (mm) must contains with only digit charaters\n");
                break;
            }
            else if (i < 10 && !isdigit(date[i]))
            {
                dateFormatStatus = -1;
                printf("\tNot Valid - Year (yyyy) must contains with only digit charaters\n");
                break;
            }
        }
    }

    return dateFormatStatus;
}

int handleDateValueValidation(int day, int month, int year)
{
    int dateValueStatus = 0;

    if (month >= 1 && month <= 12)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (day > 31 || day < 1)
            {
                dateValueStatus = -1;
                printf("\tNot Valid - Day of this month must be in range of 1-31\n");
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day > 30 || day < 1)
            {
                dateValueStatus = -1;
                printf("\tNot Valid - Day of this month must be in range of 1-30\n");
            }
        }
        else
        {
            if (day > 29)
            {
                dateValueStatus = -1;
                printf("\tNot Valid - Day of this month must be in range of 1-29\n");
            }
            else if (day == 29 && (year % 4 != 0 || year % 400 != 0 && year % 100 == 0))
            {
                dateValueStatus = -1;
                printf("\tNot Valid - Day of this year and month must be in range of 1-28\n");
            }
        }
    }
    else
    {
        dateValueStatus = -1;
        printf("\tNot Valid - Month must be in range of 1-12\n");
    }

    return dateValueStatus;
}

int handleDateIsInPastValidation(int day, int month, int year)
{
    int dateIsInPastStatus = 0;
    int dayNow;
    int monthNow;
    int yearNow;

    handleGetDateNow(&dayNow, &monthNow, &yearNow);
    if (year > yearNow)
    {
        dateIsInPastStatus = -1;
        printf("\tNot Valid - Birth Date must be in the past (year invalid)\n");
    }
    else if (year == yearNow)
    {
        if (month > monthNow)
        {
            dateIsInPastStatus = -1;
            printf("\tNot Valid - Birth Date must be in the past (month invalid)\n");
        }
        else if (month == monthNow)
        {
            if (day >= dayNow)
            {
                dateIsInPastStatus = -1;
                printf("\tNot Valid - Birth Date must be in the past (day invalid)\n");
            }
            else
            {
                if (yearNow - year > 100)
                {
                    dateIsInPastStatus = -1;
                    printf("\tNot Valid - Year of Birth Date must be no more 100 year in the past\n");
                }
            }
        }
    }
    return dateIsInPastStatus;
}

int handleInternationalPhoneValidation(char internationalPhone[])
{
    int currentPositionChecking; /* a variable that will hold a position that now checking */
    int checkPlusCode;           /* a variable that will hold a status that is plus exist or not */
    int checkCountryCode;        /* a variable that will hold a status that country code is valid or not */
    int checkCityCode;           /* a variable that will hold a status that city code is valid or not */
    int checkLastCode;           /* a variable that will hold a status that the last code is valid or not */

    currentPositionChecking = 0;
    checkCountryCode = 0;
    checkCityCode = 0;
    checkLastCode = 0;
    checkPlusCode = 1;

    if (internationalPhone[0] != '+')
    {
        printf("\tNot valid - Must start with plus\n");
        return -1;
    }
    else if (checkAllNumberDashPlus(internationalPhone) == 0)
    {
        printf("\tNot valid - Must contain with only digit number, 2 dash and 1 plus\n");
        return -1;
    }
    else
    {
        if (checkPlusCode == 1)
        {
            ++currentPositionChecking;
            checkCountryCode = checkPhoneNumberCodeBySection(internationalPhone, currentPositionChecking, 1, 3, '-');
            currentPositionChecking += checkCountryCode;
        }
        if (checkPlusCode == 1 && checkCountryCode > 0)
        {
            ++currentPositionChecking;
            checkCityCode = checkPhoneNumberCodeBySection(internationalPhone, currentPositionChecking, 1, 3, '-');
            currentPositionChecking += checkCityCode;
        }
        if (checkPlusCode == 1 && checkCountryCode > 0 && checkCityCode > 0)
        {
            ++currentPositionChecking;
            checkLastCode = checkPhoneNumberCodeBySection(internationalPhone, currentPositionChecking, 6, 10, '\0');
            currentPositionChecking += checkLastCode;
        }
        //printf("checkCountryCode is %d\nCheckCityCode is %d\nCheckLastCode is %d\n", checkCountryCode,checkCityCode,checkLastCode);
        if (checkCountryCode == -1 || checkCountryCode == -2)
        {
            printf("\tNot valid - the Country Code must be between 1 to 3 digit\n");
            return -1;
        }
        else if (checkCityCode == -1 || checkCityCode == -2)
        {
            printf("\tNot valid - the City Code must be between 1 to 3 digit\n");
            return -1;
        }
        else if (checkLastCode == -1 || checkLastCode == -2)
        {
            printf("\tNot valid - the Last Code must be between 6 to 10 digit\n");
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int checkAllNumberDashPlus(char stringToCheck[])
{
    int checker;   /* a variable that will hold status that string is contain only number,dash and plus or not */
    int plusQuota; /* a variable that will be quota for plus sign in that string */
    int dashQuota; /* a variable that will be quota for dash sign in that string */

    checker = 1;
    plusQuota = 1;
    dashQuota = 2;

    for (int i = 0; i < strlen(stringToCheck); ++i)
    {
        if (stringToCheck[i] == '-')
        {
            --dashQuota;
        }
        else if (stringToCheck[i] == '+')
        {
            --plusQuota;
        }
        if (!isdigit(stringToCheck[i]) && stringToCheck[i] != '-' && stringToCheck[i] != '+')
        {
            checker = 0;
        }
    }

    if (dashQuota != 0 || plusQuota != 0)
    {
        checker = 0;
    }

    return checker;
}

int checkPhoneNumberCodeBySection(char stringToCheck[], int startPosition, int minSizeOfSection, int maxSizeOfSection, char expectedEndingCharacter)
{
    int returnCodeStatus;  /* a variable that hold a status of that string is valid or not */
    int actualSectionSize; /* a variable that will count a size of string section that currently check */

    returnCodeStatus = 0;
    actualSectionSize = 0;

    for (int i = startPosition; i < startPosition + maxSizeOfSection; ++i)
    {
        if (!isdigit(stringToCheck[i]) && actualSectionSize < minSizeOfSection)
        {
            returnCodeStatus = -1;
            break;
        }
        else if (stringToCheck[i] == expectedEndingCharacter)
        {
            break;
        }
        else if (isdigit(stringToCheck[i]))
        {
            ++actualSectionSize;
        }
    }
    if (stringToCheck[startPosition + actualSectionSize] != expectedEndingCharacter && actualSectionSize >= maxSizeOfSection)
    {
        returnCodeStatus = -2;
    }
    if (actualSectionSize > 0 && !(returnCodeStatus == -1 || returnCodeStatus == -2))
    {
        returnCodeStatus = actualSectionSize;
    }

    return returnCodeStatus;
}

int handleGenderValidation(char gender[])
{
    if (strlen(gender) != 1)
    {
        printf("Not Valid - Gender must be only 1 character");
        return -1;
    }
    else
    {
        if (gender[0] == 'M' || gender[0] == 'F' || gender[0] == 'O')
        {
            return 0;
        }
        else
        {
            printf("Not Valid - Gender must be only 'M', 'F' or 'O'");
            return -1;
        }
    }
}