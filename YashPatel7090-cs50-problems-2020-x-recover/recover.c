#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// declaring data type
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // makes sure argument is good
    if (argc != 2)
    {
        printf("./recover image\n");
        return 1;
    }
    FILE *JPEG = fopen(argv[1], "r");
    if (JPEG == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    // declaring some variables
    int num = 0;
    int a;
    FILE *img;
    FILE *imgappend;
    int n = 1;
    char filename[8] = {"000.jpg"};
    BYTE *tmpstore;

    // writing to img files
    do
    {
        tmpstore = calloc(512, sizeof(BYTE));
        a = fread(tmpstore, sizeof(BYTE), 512, JPEG);
        if (a == 512 && tmpstore[0] == 0xff && tmpstore[1] == 0xd8 && tmpstore[2] == 0xff && (tmpstore[3] & 0xf0) == 0xe0)
        {
            if (num == 0)
            {
                img = fopen(filename, "w");
                fwrite(tmpstore, sizeof(BYTE), 512, img);
                num++;
                fclose(img);
                free(tmpstore);
            }
            else
            {
                sprintf(filename, "%03i.jpg", n);
                n++;
                img = fopen(filename, "w");
                fwrite(tmpstore, sizeof(BYTE), 512, img);
                fclose(img);
                free(tmpstore);
            }
        }
        else if (a == 512 && num == 1)
        {
            imgappend = fopen(filename, "a");
            fwrite(tmpstore, sizeof(BYTE), 512, imgappend);
            fclose(imgappend);
            free(tmpstore);
        }
        else
        {
            free(tmpstore);
        }
    }
    while (a == 512);
    fclose(JPEG);
    return 0;
}


