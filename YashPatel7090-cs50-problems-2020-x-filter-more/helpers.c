#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int b = 0; b < width; b++)
        {
            float num = ((image[i][b].rgbtRed + image[i][b].rgbtGreen + image[i][b].rgbtBlue) / (float)3);
            int n = round(num);
            image[i][b].rgbtRed = n;
            image[i][b].rgbtGreen = n;
            image[i][b].rgbtBlue = n;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int stop;
    if (width % 2 == 0)
    {
        stop = width / 2;
    }
    else
    {
        stop = (width - 1) / 2;
    }
    for (int i = 0; i < height; i++)
    {
        for (int b = 0; b < stop; b++)
        {
            RGBTRIPLE tmp[1];
            tmp[0] = image[i][b];
            image[i][b] = image[i][(width - 1) - b];
            image[i][(width - 1) - b] = tmp[0];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    tmp[0][0].rgbtRed =
        round(((image[0][0].rgbtRed + image[0][1].rgbtRed + image[1][0].rgbtRed + image[1][1].rgbtRed) / (float)4));
    tmp[0][0].rgbtGreen =
        round(((image[0][0].rgbtGreen + image[0][1].rgbtGreen + image[1][0].rgbtGreen + image[1][1].rgbtGreen) / (float)4));
    tmp[0][0].rgbtBlue =
        round(((image[0][0].rgbtBlue + image[0][1].rgbtBlue + image[1][0].rgbtBlue + image[1][1].rgbtBlue) / (float)4));

    tmp[0][width - 1].rgbtRed =
        round(((image[0][width - 2].rgbtRed + image[0][width - 1].rgbtRed + image[1][width - 2].rgbtRed
                + image[1][width - 1].rgbtRed) / (float)4));
    tmp[0][width - 1].rgbtGreen =
        round(((image[0][width - 2].rgbtGreen + image[0][width - 1].rgbtGreen + image[1][width - 2].rgbtGreen
                + image[1][width - 1].rgbtGreen) / (float)4));
    tmp[0][width - 1].rgbtBlue =
        round(((image[0][width - 2].rgbtBlue + image[0][width - 1].rgbtBlue + image[1][width - 2].rgbtBlue
                + image[1][width - 1].rgbtBlue) / (float)4));

    tmp[height - 1][0].rgbtRed =
        round(((image[height - 2][0].rgbtRed + image[height - 2][1].rgbtRed + image[height - 1][0].rgbtRed
                + image[height - 1][1].rgbtRed) / (float)4));
    tmp[height - 1][0].rgbtGreen =
        round(((image[height - 2][0].rgbtGreen + image[height - 2][1].rgbtGreen + image[height - 1][0].rgbtGreen
                + image[height - 1][1].rgbtGreen) / (float)4));
    tmp[height - 1][0].rgbtBlue =
        round(((image[height - 2][0].rgbtBlue + image[height - 2][1].rgbtBlue + image[height - 1][0].rgbtBlue
                + image[height - 1][1].rgbtBlue) / (float)4));

    tmp[height - 1][width - 1].rgbtRed =
        round(((image[height - 2][width - 2].rgbtRed + image[height - 2][width - 1].rgbtRed + image[height - 1][width - 2].rgbtRed
                + image[height - 1][width - 1].rgbtRed) / (float)4));
    tmp[height - 1][width - 1].rgbtGreen =
        round(((image[height - 2][width - 2].rgbtGreen + image[height - 2][width - 1].rgbtGreen + image[height - 1][width - 2].rgbtGreen
                + image[height - 1][width - 1].rgbtGreen) / (float)4));
    tmp[height - 1][width - 1].rgbtBlue =
        round(((image[height - 2][width - 2].rgbtBlue + image[height - 2][width - 1].rgbtBlue + image[height - 1][width - 2].rgbtBlue
                + image[height - 1][width - 1].rgbtBlue) / (float)4));

    for (int l1 = 1; l1 < width - 1; l1++)
    {
        tmp[0][l1].rgbtRed = round(((image[0][l1 - 1].rgbtRed + image[0][l1].rgbtRed + image[0][l1 + 1].rgbtRed + image[1][l1 - 1].rgbtRed
                                     + image[1][l1].rgbtRed + image[1][l1 + 1].rgbtRed) / (float)6));
        tmp[0][l1].rgbtGreen = round(((image[0][l1 - 1].rgbtGreen + image[0][l1].rgbtGreen + image[0][l1 + 1].rgbtGreen
                                       + image[1][l1 - 1].rgbtGreen + image[1][l1].rgbtGreen + image[1][l1 + 1].rgbtGreen) / (float)6));
        tmp[0][l1].rgbtBlue = round(((image[0][l1 - 1].rgbtBlue + image[0][l1].rgbtBlue + image[0][l1 + 1].rgbtBlue
                                      + image[1][l1 - 1].rgbtBlue
                                      + image[1][l1].rgbtBlue + image[1][l1 + 1].rgbtBlue) / (float)6));

        tmp[height - 1][l1].rgbtRed = round(((image[height - 2][l1 - 1].rgbtRed + image[height - 2][l1].rgbtRed
                                              + image[height - 2][l1 + 1].rgbtRed
                                              + image[height - 1][l1 - 1].rgbtRed + image[height - 1][l1].rgbtRed
                                              + image[height - 1][l1 + 1].rgbtRed) / (float)6));
        tmp[height - 1][l1].rgbtGreen = round(((image[height - 2][l1 - 1].rgbtGreen + image[height - 2][l1].rgbtGreen
                                                + image[height - 2][l1 + 1].rgbtGreen + image[height - 1][l1 - 1].rgbtGreen
                                                + image[height - 1][l1].rgbtGreen + image[height - 1][l1 + 1].rgbtGreen) / (float)6));
        tmp[height - 1][l1].rgbtBlue = round(((image[height - 2][l1 - 1].rgbtBlue + image[height - 2][l1].rgbtBlue
                                               + image[height - 2][l1 + 1].rgbtBlue + image[height - 1][l1 - 1].rgbtBlue
                                               + image[height - 1][l1].rgbtBlue + image[height - 1][l1 + 1].rgbtBlue) / (float)6));
    }
    for (int l2 = 1; l2 < height - 1; l2++)
    {
        tmp[l2][0].rgbtRed = round(((image[l2 - 1][0].rgbtRed + image[l2][0].rgbtRed + image[l2 + 1][0].rgbtRed
                                     + image[l2 - 1][1].rgbtRed + image[l2][1].rgbtRed + image[l2 + 1][1].rgbtRed) / (float)6));
        tmp[l2][0].rgbtGreen = round(((image[l2 - 1][0].rgbtGreen + image[l2][0].rgbtGreen + image[l2 + 1][0].rgbtGreen
                                       + image[l2 - 1][1].rgbtGreen + image[l2][1].rgbtGreen + image[l2 + 1][1].rgbtGreen) / (float)6));
        tmp[l2][0].rgbtBlue = round(((image[l2 - 1][0].rgbtBlue + image[l2][0].rgbtBlue + image[l2 + 1][0].rgbtBlue
                                      + image[l2 - 1][1].rgbtBlue + image[l2][1].rgbtBlue + image[l2 + 1][1].rgbtBlue) / (float)6));

        tmp[l2][width - 1].rgbtRed = round(((image[l2 - 1][width - 2].rgbtRed + image[l2][width - 2].rgbtRed
                                             + image[l2 + 1][width - 2].rgbtRed + image[l2 - 1][width - 1].rgbtRed
                                             + image[l2][width - 1].rgbtRed + image[l2 + 1][width - 1].rgbtRed) / (float)6));
        tmp[l2][width - 1].rgbtGreen = round(((image[l2 - 1][width - 2].rgbtGreen + image[l2][width - 2].rgbtGreen
                                               + image[l2 + 1][width - 2].rgbtGreen + image[l2 - 1][width - 1].rgbtGreen
                                               + image[l2][width - 1].rgbtGreen + image[l2 + 1][width - 1].rgbtGreen) / (float)6));
        tmp[l2][width - 1].rgbtBlue = round(((image[l2 - 1][width - 2].rgbtBlue + image[l2][width - 2].rgbtBlue
                                              + image[l2 + 1][width - 2].rgbtBlue + image[l2 - 1][width - 1].rgbtBlue
                                              + image[l2][width - 1].rgbtBlue + image[l2 + 1][width - 1].rgbtBlue) / (float)6));
    }
    for (int j = 1; j < height - 1; j++)
    {
        for (int k = 1; k < width - 1; k++)
        {
            tmp[j][k].rgbtRed = round(((image[j - 1][k - 1].rgbtRed + image[j - 1][k].rgbtRed + image[j - 1][k + 1].rgbtRed
                                        + image[j][k - 1].rgbtRed + image[j][k].rgbtRed + image[j][k + 1].rgbtRed
                                        + image[j + 1][k - 1].rgbtRed + image[j + 1][k].rgbtRed + image[j + 1][k + 1].rgbtRed) / (float)9));
            tmp[j][k].rgbtGreen = round(((image[j - 1][k - 1].rgbtGreen + image[j - 1][k].rgbtGreen + image[j - 1][k + 1].rgbtGreen
                                          + image[j][k - 1].rgbtGreen + image[j][k].rgbtGreen + image[j][k + 1].rgbtGreen
                                          + image[j + 1][k - 1].rgbtGreen + image[j + 1][k].rgbtGreen
                                          + image[j + 1][k + 1].rgbtGreen) / (float)9));
            tmp[j][k].rgbtBlue = round(((image[j - 1][k - 1].rgbtBlue + image[j - 1][k].rgbtBlue + image[j - 1][k + 1].rgbtBlue
                                         + image[j][k - 1].rgbtBlue + image[j][k].rgbtBlue + image[j][k + 1].rgbtBlue
                                         + image[j + 1][k - 1].rgbtBlue + image[j + 1][k].rgbtBlue
                                         + image[j + 1][k + 1].rgbtBlue) / (float)9));
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int p = 0; p < width; p++)
        {
            image[i][p] = tmp[i][p];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // corners - r - xy g - xy b - xy
    RGBTRIPLE tmp[height][width];
    int x1, y1, ans1, x2, y2, ans2, x3, y3, ans3, x4, y4, ans4;

    x1 = (image[0][1].rgbtRed * 2) + (image[1][1].rgbtRed);
    y1 = (image[1][0].rgbtRed * 2) + (image[1][1].rgbtRed);
    ans1 = round(sqrt((float)pow(x1, 2) + (float)pow(y1, 2)));
    if (ans1 > 255)
    {
        tmp[0][0].rgbtRed = 255;
    }
    else
    {
        tmp[0][0].rgbtRed = ans1;
    }
    x1 = (image[0][1].rgbtGreen * 2) + (image[1][1].rgbtGreen);
    y1 = (image[1][0].rgbtGreen * 2) + (image[1][1].rgbtGreen);
    ans1 = round(sqrt((float)pow(x1, 2) + (float)pow(y1, 2)));
    if (ans1 > 255)
    {
        tmp[0][0].rgbtGreen = 255;
    }
    else
    {
        tmp[0][0].rgbtGreen = ans1;
    }
    x1 = (image[0][1].rgbtBlue * 2) + (image[1][1].rgbtBlue);
    y1 = (image[1][0].rgbtBlue * 2) + (image[1][1].rgbtBlue);
    ans1 = round(sqrt((float)pow(x1, 2) + (float)pow(y1, 2)));
    if (ans1 > 255)
    {
        tmp[0][0].rgbtBlue = 255;
    }
    else
    {
        tmp[0][0].rgbtBlue = ans1;
    }

    x2 = (image[0][width - 2].rgbtRed * (-2)) + (image[1][width - 2].rgbtRed * (-1));
    y2 = (image[1][width - 2].rgbtRed) + (image[1][width - 1].rgbtRed * 2);
    ans2 = round(sqrt((float)pow(x2, 2) + (float)pow(y2, 2)));
    if (ans2 > 255)
    {
        tmp[0][width - 1].rgbtRed = 255;
    }
    else
    {
        tmp[0][width - 1].rgbtRed = ans2;
    }
    x2 = (image[0][width - 2].rgbtGreen * (-2)) + (image[1][width - 2].rgbtGreen * (-1));
    y2 = (image[1][width - 2].rgbtGreen) + (image[1][width - 1].rgbtGreen * 2);
    ans2 = round(sqrt((float)pow(x2, 2) + (float)pow(y2, 2)));
    if (ans2 > 255)
    {
        tmp[0][width - 1].rgbtGreen = 255;
    }
    else
    {
        tmp[0][width - 1].rgbtGreen = ans2;
    }
    x2 = (image[0][width - 2].rgbtBlue * (-2)) + (image[1][width - 2].rgbtBlue * (-1));
    y2 = (image[1][width - 2].rgbtBlue) + (image[1][width - 1].rgbtBlue * 2);
    ans2 = round(sqrt((float)pow(x2, 2) + (float)pow(y2, 2)));
    if (ans2 > 255)
    {
        tmp[0][width - 1].rgbtBlue = 255;
    }
    else
    {
        tmp[0][width - 1].rgbtBlue = ans2;
    }

    x3 = (image[height - 1][1].rgbtRed * 2) + (image[height - 2][1].rgbtRed);
    y3 = (image[height - 2][0].rgbtRed * (-2)) + (image[height - 2][1].rgbtRed * (-1));
    ans3 = round(sqrt((float)pow(x3, 2) + (float)pow(y3, 2)));
    if (ans3 > 255)
    {
        tmp[height - 1][0].rgbtRed = 255;
    }
    else
    {
        tmp[height - 1][0].rgbtRed = ans3;
    }
    x3 = (image[height - 1][1].rgbtGreen * 2) + (image[height - 2][1].rgbtGreen);
    y3 = (image[height - 2][0].rgbtGreen * (-2)) + (image[height - 2][1].rgbtGreen * (-1));
    ans3 = round(sqrt((float)pow(x3, 2) + (float)pow(y3, 2)));
    if (ans3 > 255)
    {
        tmp[height - 1][0].rgbtGreen = 255;
    }
    else
    {
        tmp[height - 1][0].rgbtGreen = ans3;
    }
    x3 = (image[height - 1][1].rgbtBlue * 2) + (image[height - 2][1].rgbtBlue);
    y3 = (image[height - 2][0].rgbtBlue * (-2)) + (image[height - 2][1].rgbtBlue * (-1));
    ans3 = round(sqrt((float)pow(x3, 2) + (float)pow(y3, 2)));
    if (ans3 > 255)
    {
        tmp[height - 1][0].rgbtBlue = 255;
    }
    else
    {
        tmp[height - 1][0].rgbtBlue = ans3;
    }

    x4 = (image[height - 2][width - 2].rgbtRed * (-1)) + (image[height - 1][width - 2].rgbtRed * (-2));
    y4 = (image[height - 2][width - 2].rgbtRed * (-1)) + (image[height - 2][width - 1].rgbtRed * (-2));
    ans4 = round(sqrt((float)pow(x4, 2) + (float)pow(y4, 2)));
    if (ans4 > 255)
    {
        tmp[height - 1][width - 1].rgbtRed = 255;
    }
    else
    {
        tmp[height - 1][width - 1].rgbtRed = ans4;
    }
    x4 = (image[height - 2][width - 2].rgbtGreen * (-1)) + (image[height - 1][width - 2].rgbtGreen * (-2));
    y4 = (image[height - 2][width - 2].rgbtGreen * (-1)) + (image[height - 2][width - 1].rgbtGreen * (-2));
    ans4 = round(sqrt((float)pow(x4, 2) + (float)pow(y4, 2)));
    if (ans4 > 255)
    {
        tmp[height - 1][width - 1].rgbtGreen = 255;
    }
    else
    {
        tmp[height - 1][width - 1].rgbtGreen = ans4;
    }
    x4 = (image[height - 2][width - 2].rgbtBlue * (-1)) + (image[height - 1][width - 2].rgbtBlue * (-2));
    y4 = (image[height - 2][width - 2].rgbtBlue * (-1)) + (image[height - 2][width - 1].rgbtBlue * (-2));
    ans4 = round(sqrt((float)pow(x4, 2) + (float)pow(y4, 2)));
    if (ans4 > 255)
    {
        tmp[height - 1][width - 1].rgbtBlue = 255;
    }
    else
    {
        tmp[height - 1][width - 1].rgbtBlue = ans4;
    }

    int c1, m1, p1, c2, m2, p2;
    for (int v = 1; v < width - 1; v++)
    {
        c1 = (image[0][v - 1].rgbtRed * (-2)) + (image[0][v + 1].rgbtRed * 2)
             + (image[1][v - 1].rgbtRed * (-1)) + (image[1][v + 1].rgbtRed);
        m1 = (image[1][v - 1].rgbtRed) + (image[1][v].rgbtRed * 2) + (image[1][v + 1].rgbtRed);
        p1 = round(sqrt((float)pow(c1, 2) + (float)pow(m1, 2)));
        if (p1 > 255)
        {
            tmp[0][v].rgbtRed = 255;
        }
        else
        {
            tmp[0][v].rgbtRed = p1;
        }
        c1 = (image[0][v - 1].rgbtGreen * (-2)) + (image[0][v + 1].rgbtGreen * 2)
             + (image[1][v - 1].rgbtGreen * (-1)) + (image[1][v + 1].rgbtGreen);
        m1 = (image[1][v - 1].rgbtGreen) + (image[1][v].rgbtGreen * 2) + (image[1][v + 1].rgbtGreen);
        p1 = round(sqrt((float)pow(c1, 2) + (float)pow(m1, 2)));
        if (p1 > 255)
        {
            tmp[0][v].rgbtGreen = 255;
        }
        else
        {
            tmp[0][v].rgbtGreen = p1;
        }
        c1 = (image[0][v - 1].rgbtBlue * (-2)) + (image[0][v + 1].rgbtBlue * 2)
             + (image[1][v - 1].rgbtBlue * (-1)) + (image[1][v + 1].rgbtBlue);
        m1 = (image[1][v - 1].rgbtBlue) + (image[1][v].rgbtBlue * 2) + (image[1][v + 1].rgbtBlue);
        p1 = round(sqrt((float)pow(c1, 2) + (float)pow(m1, 2)));
        if (p1 > 255)
        {
            tmp[0][v].rgbtBlue = 255;
        }
        else
        {
            tmp[0][v].rgbtBlue = p1;
        }

        c2 = (image[height - 2][v - 1].rgbtRed * (-1)) + (image[height - 2][v + 1].rgbtRed)
             + (image[height - 1][v - 1].rgbtRed * (-2)) + (image[height - 1][v + 1].rgbtRed * 2);
        m2 = (image[height - 2][v - 1].rgbtRed * (-1)) + (image[height - 2][v].rgbtRed * (-2))
             + (image[height - 2][v + 1].rgbtRed * (-1));
        p2 = round(sqrt((float)pow(c2, 2) + (float)pow(m2, 2)));
        if (p2 > 255)
        {
            tmp[height - 1][v].rgbtRed = 255;
        }
        else
        {
            tmp[height - 1][v].rgbtRed = p2;
        }
        c2 = (image[height - 2][v - 1].rgbtGreen * (-1)) + (image[height - 2][v + 1].rgbtGreen)
             + (image[height - 1][v - 1].rgbtGreen * (-2)) + (image[height - 1][v + 1].rgbtGreen * 2);
        m2 = (image[height - 2][v - 1].rgbtGreen * (-1)) + (image[height - 2][v].rgbtGreen * (-2))
             + (image[height - 2][v + 1].rgbtGreen * (-1));
        p2 = round(sqrt((float)pow(c2, 2) + (float)pow(m2, 2)));
        if (p2 > 255)
        {
            tmp[height - 1][v].rgbtGreen = 255;
        }
        else
        {
            tmp[height - 1][v].rgbtGreen = p2;
        }
        c2 = (image[height - 2][v - 1].rgbtBlue * (-1)) + (image[height - 2][v + 1].rgbtBlue)
             + (image[height - 1][v - 1].rgbtBlue * (-2)) + (image[height - 1][v + 1].rgbtBlue * 2);
        m2 = (image[height - 2][v - 1].rgbtBlue * (-1)) + (image[height - 2][v].rgbtBlue * (-2))
             + (image[height - 2][v + 1].rgbtBlue * (-1));
        p2 = round(sqrt((float)pow(c2, 2) + (float)pow(m2, 2)));
        if (p2 > 255)
        {
            tmp[height - 1][v].rgbtBlue = 255;
        }
        else
        {
            tmp[height - 1][v].rgbtBlue = p2;
        }
    }

    int b1, l1, o1, b2, l2, o2;
    for (int s = 1; s < height - 1; s++)
    {
        b1 = (image[s - 1][1].rgbtRed) + (image[s][1].rgbtRed * 2) + (image[s + 1][1].rgbtRed);
        l1 = (image[s - 1][0].rgbtRed * (-2)) + (image[s - 1][1].rgbtRed * (-1))
             + (image[s + 1][0].rgbtRed * 2) + (image[s + 1][1].rgbtRed);
        o1 = round(sqrt((float)pow(b1, 2) + (float)pow(l1, 2)));
        if (o1 > 255)
        {
            tmp[s][0].rgbtRed = 255;
        }
        else
        {
            tmp[s][0].rgbtRed = o1;
        }
        b1 = (image[s - 1][1].rgbtGreen) + (image[s][1].rgbtGreen * 2) + (image[s + 1][1].rgbtGreen);
        l1 = (image[s - 1][0].rgbtGreen * (-2)) + (image[s - 1][1].rgbtGreen * (-1))
             + (image[s + 1][0].rgbtGreen * 2) + (image[s + 1][1].rgbtGreen);
        o1 = round(sqrt((float)pow(b1, 2) + (float)pow(l1, 2)));
        if (o1 > 255)
        {
            tmp[s][0].rgbtGreen = 255;
        }
        else
        {
            tmp[s][0].rgbtGreen = o1;
        }
        b1 = (image[s - 1][1].rgbtBlue) + (image[s][1].rgbtBlue * 2) + (image[s + 1][1].rgbtBlue);
        l1 = (image[s - 1][0].rgbtBlue * (-2)) + (image[s - 1][1].rgbtBlue * (-1))
             + (image[s + 1][0].rgbtBlue * 2) + (image[s + 1][1].rgbtBlue);
        o1 = round(sqrt((float)pow(b1, 2) + (float)pow(l1, 2)));
        if (o1 > 255)
        {
            tmp[s][0].rgbtBlue = 255;
        }
        else
        {
            tmp[s][0].rgbtBlue = o1;
        }

        b2 = (image[s - 1][width - 2].rgbtRed * (-1)) + (image[s][width - 2].rgbtRed * (-2))
             + (image[s + 1][width - 2].rgbtRed * (-1));
        l2 = (image[s - 1][width - 2].rgbtRed * (-1)) + (image[s - 1][width - 1].rgbtRed * (-2))
             + (image[s + 1][width - 2].rgbtRed) + (image[s + 1][width - 1].rgbtRed * 2);
        o2 = round(sqrt((float)pow(b2, 2) + (float)pow(l2, 2)));
        if (o2 > 255)
        {
            tmp[s][width - 1].rgbtRed = 255;
        }
        else
        {
            tmp[s][width - 1].rgbtRed = o2;
        }
        b2 = (image[s - 1][width - 2].rgbtGreen * (-1)) + (image[s][width - 2].rgbtGreen * (-2))
             + (image[s + 1][width - 2].rgbtGreen * (-1));
        l2 = (image[s - 1][width - 2].rgbtGreen * (-1)) + (image[s - 1][width - 1].rgbtGreen * (-2))
             + (image[s + 1][width - 2].rgbtGreen) + (image[s + 1][width - 1].rgbtGreen * 2);
        o2 = round(sqrt((float)pow(b2, 2) + (float)pow(l2, 2)));
        if (o2 > 255)
        {
            tmp[s][width - 1].rgbtGreen = 255;
        }
        else
        {
            tmp[s][width - 1].rgbtGreen = o2;
        }
        b2 = (image[s - 1][width - 2].rgbtBlue * (-1)) + (image[s][width - 2].rgbtBlue * (-2))
             + (image[s + 1][width - 2].rgbtBlue * (-1));
        l2 = (image[s - 1][width - 2].rgbtBlue * (-1)) + (image[s - 1][width - 1].rgbtBlue * (-2))
             + (image[s + 1][width - 2].rgbtBlue) + (image[s + 1][width - 1].rgbtBlue * 2);
        o2 = round(sqrt((float)pow(b2, 2) + (float)pow(l2, 2)));
        if (o2 > 255)
        {
            tmp[s][width - 1].rgbtBlue = 255;
        }
        else
        {
            tmp[s][width - 1].rgbtBlue = o2;
        }
    }

    int Gx, Gy, Gans;
    for (int u = 1; u < height - 1; u++)
    {
        for (int z = 1; z < width - 1; z++)
        {
            Gx = (image[u - 1][z - 1].rgbtRed * (-1)) + (image[u][z - 1].rgbtRed * (-2)) + (image[u + 1][z - 1].rgbtRed * (-1))
                 + (image[u - 1][z + 1].rgbtRed) + (image[u][z + 1].rgbtRed * 2) + (image[u + 1][z + 1].rgbtRed);
            Gy = (image[u - 1][z - 1].rgbtRed * (-1)) + (image[u - 1][z].rgbtRed * (-2)) + (image[u - 1][z + 1].rgbtRed * (-1))
                 + (image[u + 1][z - 1].rgbtRed) + (image[u + 1][z].rgbtRed * 2) + (image[u + 1][z + 1].rgbtRed);
            Gans = round(sqrt((float)pow(Gx, 2) + (float)pow(Gy, 2)));
            if (Gans > 255)
            {
                tmp[u][z].rgbtRed = 255;
            }
            else
            {
                tmp[u][z].rgbtRed = Gans;
            }
            Gx = (image[u - 1][z - 1].rgbtGreen * (-1)) + (image[u][z - 1].rgbtGreen * (-2)) + (image[u + 1][z - 1].rgbtGreen * (-1))
                 + (image[u - 1][z + 1].rgbtGreen) + (image[u][z + 1].rgbtGreen * 2) + (image[u + 1][z + 1].rgbtGreen);
            Gy = (image[u - 1][z - 1].rgbtGreen * (-1)) + (image[u - 1][z].rgbtGreen * (-2)) + (image[u - 1][z + 1].rgbtGreen * (-1))
                 + (image[u + 1][z - 1].rgbtGreen) + (image[u + 1][z].rgbtGreen * 2) + (image[u + 1][z + 1].rgbtGreen);
            Gans = round(sqrt((float)pow(Gx, 2) + (float)pow(Gy, 2)));
            if (Gans > 255)
            {
                tmp[u][z].rgbtGreen = 255;
            }
            else
            {
                tmp[u][z].rgbtGreen = Gans;
            }
            Gx = (image[u - 1][z - 1].rgbtBlue * (-1)) + (image[u][z - 1].rgbtBlue * (-2)) + (image[u + 1][z - 1].rgbtBlue * (-1))
                 + (image[u - 1][z + 1].rgbtBlue) + (image[u][z + 1].rgbtBlue * 2) + (image[u + 1][z + 1].rgbtBlue);
            Gy = (image[u - 1][z - 1].rgbtBlue * (-1)) + (image[u - 1][z].rgbtBlue * (-2)) + (image[u - 1][z + 1].rgbtBlue * (-1))
                 + (image[u + 1][z - 1].rgbtBlue) + (image[u + 1][z].rgbtBlue * 2) + (image[u + 1][z + 1].rgbtBlue);
            Gans = round(sqrt((float)pow(Gx, 2) + (float)pow(Gy, 2)));
            if (Gans > 255)
            {
                tmp[u][z].rgbtBlue = 255;
            }
            else
            {
                tmp[u][z].rgbtBlue = Gans;
            }
        }
    }

    for (int oo = 0; oo < height; oo++)
    {
        for (int ii = 0; ii < width; ii++)
        {
            image[oo][ii] = tmp[oo][ii];
        }
    }
    return;
}

