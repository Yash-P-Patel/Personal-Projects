#include <stdio.h>
#include <cs50.h>
#include <math.h>
// this is the main function which is going to run checksum, then number of digits, then finally starting values
int main(void)
{



// prompts user for credit card number
    long num = get_long("Number: ");
    long number = num, number2 = num, number3 = num;

// counts number of digits
    int digits = 0;
    do
    {
        num = num / 10;
        digits++;
    }
    while (num >= 1);

// declaring variables for checksum
    long r, y, u, sum = 0, sum2 = 0, j, totalsum, last0;

// Checksum
    number = number / 10;
    do
    {
        r = number % 10;
        r = r * 2;
        y = r % 10;
        u = r / 10;
        sum = sum + y + u;
        number = number / 100;
    }
    while (number > 0);
    do
    {
        j = number2 % 10;
        sum2 = sum2 + j;
        number2 = number2 / 100;
    }
    while (number2 > 0);
    totalsum = sum + sum2;
    last0 = totalsum % 10;
    if (last0 == 0)
    {
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

// declaring variables for extracting first digits
    long a, b, z, h, g;

// first two-digits of the credit card number
    h = pow(10, digits - 2);
    z = number3 % h;
    z = number3 - z;
    a = z / h;

// first digit of the credit card number
    g = pow(10, digits - 1);
    z = number3 % g;
    z = number3 - z;
    b = z / g;

// identify card-type by number of digits and values of first couple digits
    switch (digits)
    {
        case 15:
            if (a == 34 || a == 37)
            {
                printf("AMEX\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        case 13:
            if (b == 4)
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        case 16:
            if (a == 51 || a == 52 || a == 53 || a == 54 || a == 55)
            {
                printf("MASTERCARD\n");
                return 0;
            }
            else if (b == 4)
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        default:
            printf("INVALID\n");
            return 0;
    }



}

// this code has been tested multiple times and it has not yet failed.


