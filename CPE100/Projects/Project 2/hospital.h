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

#ifndef HOSPITAL_H
#define HOSPITAL_H

void handleDisplayMenus();

void handleMenuSelection(char choice[]);

void handleDisplayAllDataBase();

void handleGetAddInformation();

void handleGetSearchInformation();

void handleGetModifyInformation();

void handleDisplatErrorMessage();

void handleChangeDatabaseFileName();

typedef struct
{
    char passportCountryCode[3];
    char passportNumberCode[15];
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

#endif