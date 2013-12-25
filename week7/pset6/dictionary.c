/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "dictionary.h"

#define SZ 1000000

typedef struct node
{
	char word[LENGTH + 1];
	struct node* next;
}node;

node* hashtable[SZ] = {NULL};

int 
hash(const char *word)
{
	int h = 1, i;
	if(strlen(word) < 4)
	{
		for(i = 0; i < strlen(word); i++)
		{
			if(isalpha(word[i]))
				h = (h + ((tolower(word[i]) - 'a') * 2)) % SZ;
			else
				h = h + 35;
		}
	}
	else
	{
		for(i = 0; i < 4; i++)
		{
			if(isalpha(word[i]))
				h = (h + (((tolower(word[i]) - 'a') * 2) * (((tolower(word[strlen(word)]) - 1 - i) - 'a') * 3))) % SZ;
			else
				h = h + 35;
		}
			
	}
	return h;
} 
	 

/*
 * Returns true if word is in dictionary else false.
 */

bool
check(const char *word)
{
    // TODO
    char *w = malloc(sizeof(char));
    int a = strlen(word), i;
    for(i = 0; i < a; i++)
    	w[i] = tolower(word[i]);
    
    int ha = hash(w);
    
    if(hashtable[ha] == NULL)
        return false;
    
    node* nn = hashtable[ha];
    
    while(nn != NULL)
    {
    	//char *ww = nn->word;
    	if(strcmp(w, nn->word) == 0)
    		return true;
    	nn = nn -> next;
    }
    return false;
}


/*
 * Loads dictionary into memory.  Returns true if successful else false.
 */
int sized = 0;
bool
load(const char *dictionary)
{
    // TODO
    FILE *fp = fopen(dictionary, "r");
    if(fp == NULL)
    	return false;
    
    while(!feof(fp))
    {
    	node* n = malloc(sizeof(node));
    	fscanf(fp,"%s", n->word);
    	sized++;
    	//strcpy(n->word, w);
    	
    	int index = hash(n->word);
    	
    	if(hashtable[index] == NULL)
    	{
    		hashtable[index] = n;
    		n->next = NULL;
    	}
    	else
    	{
    		n->next = hashtable[index];
    		hashtable[index] = n;
    		n->next = NULL;
    	}
    }
    fclose(fp);
    
    return true;
}


/*
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

unsigned int
size(void)
{
    // TODO
    if(sized>0)
    	return sized;
    else
    	return 0;
}


/*
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool
unload(void)
{
    // TODO
    int in = 0;
    while(in < sized)
    {
    	if(hashtable[in] == NULL)
    		in++;
    	else
    	{
    		while(hashtable[in] != NULL)
    		{
    			node *n = hashtable[in];
    			hashtable[in] = n->next;
    			free(n);
    		}
    		in++;
    	}
    	
    }
    return true;
}
