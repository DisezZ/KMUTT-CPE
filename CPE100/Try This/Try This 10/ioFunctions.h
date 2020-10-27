/*  
 * ioFunctions.h
 *
 * Declarations for the functions in ioFunctions.c
 *
 * Created by Sally Goldin, 31 August 2010 for CPE 100 demonstration
 * Updated 18 Oct 2014
 */

#define CHARMAX 32


/*  Check that a string contains only digits.
 *  testString  - String to be checked
 *  Returns 1 if all digits, 0 if not
 */
int isDigitString(char* testString);

/*  Check that a string contains only alphabetic characters.
 *  (No punctuation, digits or white space allowed)
 *  testString  - String to be checked
 *  Returns 1 if all alpha chars, 0 if not
 */
int isAlphaString(char* testString);

/* Get an integer value from the user that is between
 * a specified min and max value. Keeps asking until 
 * the user enters a valid value.
 * prompt - Message to print to ask the user for the value
 * min    - Smallest acceptable value for the integer
 * max    - Largest acceptable value for the integer
 * Returns the final, correct integer entered by the user.
 */
int getLimitedInteger(char* prompt, int min, int max);

/* Get a string no longer than a specified length, which 
 * must be all alphabetic characters. Note that the maximum
 * length that this function can handle is 255 characters.
 * prompt - Message to print to ask the user for the value
 * maxlength - Maximum length of the string
 * outputString - Array for returning the entered string.
 * Returns 1 if all is okay, 0 if the maxlength is too large.
 */
int getLimitedString(char* prompt, int maxlength, char * outputString);

/* Get any string - does not have to be  all alphabetic characters,
 * but cannot be empty.
 * prompt - Message to print to ask the user for the value
 * maxlength - Maximum length of the string
 * outputString - Array for returning the entered string.
 */
void getString(char* prompt, int maxlength, char * outputString);

