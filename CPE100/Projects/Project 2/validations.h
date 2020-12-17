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

#define LEN(arr) ((int)(sizeof(arr) / sizeof(arr)[0]))

void handleGetDateNow(int *day, int *month, int *year);

int handlePassportNumberValidation(char passportNumber[]);

int handleNameValidation(char name[]);

int handleBirthDateValidation(char birthDate[]);

int handleDateFormatValidation(char date[]);

int handleDateValueValidation(int day, int month, int year);

int handleDateIsInPastValidation(int day, int month, int year);

int handleInternationalPhoneValidation(char internationalPhone[]);

int checkAllNumberDashPlus(char stringToCheck[]);

int checkPhoneNumberCodeBySection(char stringToCheck[], int startPosition, int minSizeOfSection, int maxSizeOfSection, char expectedEndingCharacter);

int handleGenderValidation(char gender[]);