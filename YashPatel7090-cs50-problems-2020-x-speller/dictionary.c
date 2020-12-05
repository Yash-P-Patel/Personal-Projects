// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// count number of loaded words
unsigned int counter = 0;

// Hash table
node *table[N];

// free memory
bool fre(node *tmpptr);

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] > 64 && word[i] < 91)
        {
            sum = sum + word[i];
        }
        else if (word[i] > 96 && word[i] < 123)
        {
            int tmp = word[i] - 32;
            sum = sum + tmp;
        }
        else if (word[i] == 39)
        {
            sum = sum + word[i];
        }
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *ptr = fopen(dictionary, "r");
    if (ptr == NULL)
    {
        return false;
    }
    char *eoof = NULL;
    char tmpword[46];
    while (true)
    {
        eoof = fgets(tmpword, 46, ptr);
        if (eoof == NULL)
        {
            break;
        }
        node *ptrnode = calloc(1, sizeof(node));
        if (ptrnode == NULL)
        {
            return false;
        }
        strcpy((*ptrnode).word, tmpword);
        unsigned int hash2 = hash(tmpword);
        if (hash2 == 0)
        {
            continue;
        }
        if (table[hash2] == NULL)
        {
            (*ptrnode).next = NULL;
            table[hash2] = ptrnode;
            counter++;
        }
        else
        {
            (*ptrnode).next = table[hash2];
            table[hash2] = ptrnode;
            counter++;
        }
    }
    fclose(ptr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node *tmpptr = table[hash(word)];
    while (tmpptr != NULL)
    {
        if (hash(word) == hash((*tmpptr).word))
        {
            return true;
        }
        else
        {
            if ((*tmpptr).next != NULL)
            {
                tmpptr = (*tmpptr).next;
            }
            else
            {
                break;
            }
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < 10000; i++)
    {
        if (table[i] != NULL)
        {
            fre(table[i]);
        }
    }
    return true;
}

bool fre(node *tmpptr)
{
    if ((*tmpptr).next == NULL)
    {
        free(tmpptr);
        return true;
    }
    else
    {
        if (fre((*tmpptr).next) == true)
        {
            free(tmpptr);
            return true;
        }
        else
        {
            return false;
        }
    }
}



