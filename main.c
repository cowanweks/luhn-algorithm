#include "include/main.h"
/*
    To find the first digit and second digit
    In this case let's say 12

    1. To get the 1
        12 / 10 = 1

    2. To get the 2
        12 % 10 = 2
*/

void get_card()
{
    do
    {
        printf("Please input your credit-card/debit-card number\n");
        scanf("%ld", &card);

    } while (card <= 0);
}

void print_card_no()
{
    long *card_ptr = &card;
    printf("%ld\n", *card_ptr);
}

void validate_card()
{
    int count = 0;
    int sum_digits;
    long divisor;
    char *card_name;
    long *card_ptr = &card;
    long current_CC = *card_ptr;

    long working_CC = current_CC / 10;
    while (working_CC > 0)
    {
        // Perform the modulo
        int last_digit = working_CC % 10; // This is the last digit
        int times_two = last_digit * 2;
        sum_digits = sum_digits + (times_two % 10) + (times_two / 10);
        working_CC = working_CC / 100;
    }

    working_CC = current_CC;
    while (working_CC != 0)
    {
        working_CC = working_CC / 10;
        count++;
    }

    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    int first_digit = current_CC / divisor;
    int first_two_digits = current_CC / (divisor / 10);

    printf("%i", sum_digits);
    if (sum_digits % 10 == 0)
    {
        if (first_digit == 4 && (count == 13 || 16))
        {
            strcpy(card_name, "VISA");
        }
        else if ((first_two_digits == 34 || first_two_digits == 37) && count == 15)
        {
            strcpy(card_name, "AMERICAN EXPRESS");
        }
        else if ((first_two_digits > 50 && first_two_digits < 56) && count == 16)
        {
            strcpy(card_name, "MASTERCARD");
        }
        else
        {
            printf("Card is invalid !!\n");
        }
    }
    printf("%s\n", card_name);
}

int main()
{
    get_card();
    validate_card();
    return EXIT_SUCCESS;
}