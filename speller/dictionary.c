// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int key = hash(word);
    node *cursor = table[key];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int key = 0;
    int value = 0;

    // TODO: Improve this hash function
    //put words into the right n  eg.)apple is A node
    for (int i = 0; i < strlen(word); i++)
    {
        value += toupper(word[i]);
    }
    return value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionery files
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    char scanword[LENGTH + 1];
    while (fscanf(file, "%s", scanword) != EOF) //to the end of the file
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, scanword);
        n->next = NULL;

        int key = hash(scanword);

        if (table[key] == NULL)
        {
            table[key] = n;
        }
        else
        {
            n->next = table[key];
            table[key] = n;
        }
        counter++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *n = cursor;
            cursor = cursor->next;
            free(n);
        }
        table[i] = NULL;
    }
    return true;
}