/****************************************************************
 *  
 *  Template
 *
 *      This program is 
 *          
 *
 *      Created by Lutfee Deemae (Lut) ID 63070503448
 *      x November 2020
 *
 ****************************************************************
 */

#include "hospital.h"

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

void handleDisplayAll();

int handleAddOneRecord(HOSPITAL_T record);

int handleSearchByPassPortNumber(char searched[]);

int handleSearchByName(char searched[]);

void handleModifyRecord(char searched[], int size, int recordNumber);

#endif