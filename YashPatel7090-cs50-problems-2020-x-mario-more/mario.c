#include <stdio.h>
#include <cs50.h>

int main(void)
{


// prompt user for height 1-8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);




// 2 pyramids of hashes
    int y = 1;
    int z = 1;
    int u = 1;
    for (int i = 0; i < height; i++)
    {

        for (int a = 0; a < height - z; a++) // this section is for spaces
        {
            printf(" ");
        }
        z++;


        for (int b = 0; b < y; b++) // this section is for left pyramid hashes
        {
            printf("#");
        }
        y++;


        printf("  "); // this section is the constant 2 spaces between the pyramids


        for (int c = 0; c < u; c++) // this section is for right pyramid hashes
        {
            printf("#");
        }
        u++;


        printf("\n");

    }



}



