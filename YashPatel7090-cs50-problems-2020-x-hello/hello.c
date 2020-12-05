#include <cs50.h>
#include <stdio.h>

// above are 2 libraries for get_string() and printf()

int main(void)
{
    string name = get_string("What is your name:\n"); // user input their name
    printf("hello, %s\n", name); // prints hello, their name
}

