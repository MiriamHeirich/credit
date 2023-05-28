#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    long long cardNumber;
    printf("Enter your card number: ");
    scanf("%lld", &cardNumber);

    // Convert the card number to a string
    char cardString[17];
    sprintf(cardString, "%lld", cardNumber);

    int size = strlen(cardString);

    // Check if the card number has a valid number of digits
    if (size < 13 || size > 16 || size == 14)
    {
        printf("INVALID\n");
        return 0;
    }

    // Variables for future calculations
    int sum = 0;
    bool multiply = false;

    // Traverse the card digits from right to left
    for (int i = size - 1; i >= 0; i--)
    {
        int digit = cardString[i] - '0';

        if (multiply)
        {
            digit *= 2;

            // If the multiplied digit is greater than 9, sum the individual digits
            if (digit > 9)
            {
                digit = digit % 10 + digit / 10;
            }
        }

        sum += digit;
        multiply = !multiply;
    }

    // Check if the card number is valid based on the sum of digits
    if (sum % 10 == 0)
    {
        // Check the card brand based on the first digits
        int firstDigit = cardString[0] - '0';
        int secondDigit = cardString[1] - '0';

        if (size == 15 && firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
        {
            printf("AMEX\n");
        }
        else if (size == 16 && firstDigit == 5 && secondDigit >= 1 && secondDigit <= 5)
        {
            printf("MASTERCARD\n");
        }
        else if ((size == 13 || size == 16) && firstDigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
