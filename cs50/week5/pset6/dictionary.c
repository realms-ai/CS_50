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
#include <math.h>

#include "dictionary.h"

#define SZ 1000000

typedef struct node
{
	char word[LENGTH + 1];
	struct node* next;
}node;

node* hashtable[SZ] = {NULL};

unsigned int 
hash(const char *word)
{
	unsigned int h = 0, i;
	//printf("Great");
	if(strlen(word) < 4)
	{
		for(i = 0; i < strlen(word); i++)
		{
			if(isalpha(word[i]))
				h = (h + ((tolower(word[i]) - 'a') * 2)) ;
			else
				h = h + 35;
			h = h % SZ;
		}
	}
	else
	{
		for(i = 0; i < 4; i++)
		{
			if(isalpha(word[i]))
				h = (h + (((tolower(word[i]) - 'a') * 2)) * (((tolower(word[strlen(word) - 1 - i])) - 'a') * 3));
			else
				h = h + 35;
			h = h % SZ;
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
   char w[LENGTH + 1];
   int a = strlen(word), i;
   for(i = 0; i < a; i++)
   		w[i] = tolower(word[i]);
   w[a] = '\0';
   int ha = hash(w);
   //printf(" check: %s %d", w, ha);
   
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
		int index = hash(n->word);
	   	//printf("n->word is %s %d",n->word, index);
	   	//strcpy(n->word, w);

	   	if(hashtable[index] == NULL)
	   	{
		   	 hashtable[index] = n;
		   	 n->next = NULL;
	   	}
	   	else
	   	{
		   	 n->next = hashtable[index];
		   	 hashtable[index] = n;
		   	 //n->next = NULL;
	   	}
	   	//free(n);
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