#include <stdio.h>
#include <math.h>
// declaring functions and arrays
char text[5000];
void gettext();
int rounding(double x);

// main function
int main()
{
    // prompts user for text input
    gettext();

    // counts number of letters and spaces and sentences
    int letters = 0;
    int spaces = 0;
    int sentences = 0;
    for (int i = 0; i < 5000; i++)
    {
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
        {
            letters++;
        }
        else if (text[i] == 32)
        {
            spaces++;
        }
        else if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }

    // calculates value for L
    int words = spaces + 1;
    double L = ((double)letters / (double)words) * 100;

    // calculates value for S
    double S = ((double)sentences / (double)words) * 100;

    // calculates index (grade level)
    double grade = 0.0588 * L - 0.296 * S - 15.8;
    int newgrade = rounding(grade);

    // prints the grade level
    if (newgrade > 0 && newgrade < 16)
    {
        printf("Grade %i\n", newgrade);
        return 0;
    }
    else if (newgrade >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Before Grade 1\n");
        return 0;
    }
}

// Custom Function: User input is placed in text[array]
void gettext()
{
    printf("Text: ");
    scanf("%[^\n]s*c", text);
}

// Custom Function: Rounding a number to nearest whole integer
int rounding(double x)
{
    double c = x * 10;
    int b = (int)c % 10;
    int d;
    if (b < 5)
    {
        d = (int)x;
    }
    else
    {
        d = (int)x + 1;
    }
    return d;
}




