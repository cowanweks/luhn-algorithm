#ifndef __MAIN__H
#define __MAIN__H

/* This is an implementation of the Luhn Algorithm used for the validation
   of the credit and debit cards.
   It's able to validate the whole digits by just checking the checking digit.
   The checking digit is the last digit of the credit credit card number.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define constants
#define EXIT_SUCCESS 0;

long card;

void get_card();
void validate_card();
void print_card_no();

#endif // __MAIN__H