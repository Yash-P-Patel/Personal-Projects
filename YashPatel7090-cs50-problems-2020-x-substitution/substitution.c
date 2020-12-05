#include <stdio.h>
#include <math.h>

// declaring arrays
char plaintext[5000];
char ciphertext[5000];

// main function
int main(int v, char **key)
{
    // checks for only 1 command-line argument
    if (v == 2)
    {
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // checks if the "key" is made of alphabetic characters
    for (int i = 0; key[1][i] != '\0'; i++)
    {
        if ((key[1][i] > 64 && key[1][i] < 91) || (key[1][i] > 96 && key[1][i] < 123))
        {
        }
        else
        {
            printf("Alphabetic Characters Only\n");
            return 1;
        }
    }

    // checks if command-line argument is 26 characters long
    if (key[1][26] == '\0')
    {
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // checks if each letter occurs exactly once
    for (int j = 65; j < 91; j++)
    {
        int repeated = 0;
        for (int k = 0; key[1][k] != '\0'; k++)
        {
            if (key[1][k] == j || key[1][k] == j + 32)
            {
                repeated++;
            }
            else
            {
            }
        }
        if (repeated == 1)
        {
        }
        else
        {
            printf("No repeats.\n");
            return 1;
        }
    }

    // Prompt user for plaintext
    printf("plaintext:  ");
    scanf("%[^\n]s*c", plaintext);

    // calculates ciphertext
    int p = 0;
    for (int l = 65; l < 91; l++)
    {
        for (int m = 0; plaintext[m] != '\0'; m++)
        {
            if (plaintext[m] == l)
            {
                if (key[1][p] > 64 && key[1][p] < 91)
                {
                    ciphertext[m] = key[1][p];
                }
                else
                {
                    ciphertext[m] = key[1][p] - 32;
                }
            }
            else if (plaintext[m] == l + 32)
            {
                if (key[1][p] > 96 && key[1][p] < 123)
                {
                    ciphertext[m] = key[1][p];
                }
                else
                {
                    ciphertext[m] = key[1][p] + 32;
                }
            }
            else if ((plaintext[m] > 64 && plaintext[m] < 91) || (plaintext[m] > 96 && plaintext[m] < 123))
            {
            }
            else
            {
                ciphertext[m] = plaintext[m];
            }
        }
        p++;
    }

    // prints the ciphertext
    printf("ciphertext: %s\n", ciphertext);
}






