
#include <cs50.h>
#include <ctype.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// duration of a game in seconds
#define DURATION 30

// grid's dimensions
#define DIMENSION 4

// maximum number of words in any dictionary
#define WORDS 172806

// maximum number of letters in any word
#define LETTERS 29

// default dictionary
// http://www.becomeawordgameexpert.com/wordlists.htm
#define DICTIONARY "words"

// for logging
FILE* lo;

// grid
char grid[DIMENSION][DIMENSION];

// flags with which we can mark grid's letters while searching for words
bool marks[DIMENSION][DIMENSION];

// defines a word as having an array of letters plus a flag
// indicating whether word has been found on grid
typedef struct
{
   bool found;
   char letters[LETTERS + 1];
}
word;

// defines a dictionary as having a size and an array of words
struct
{
   int size;
   word words[WORDS];
}
dictionary;


	int main ()
	{
		// http://en.wikipedia.org/wiki/Letter_frequency
   float frequencies[] = {
    8.167,  // a
    1.492,  // b
    2.782,  // c
    4.253,  // d
    12.702, // e
    2.228,  // f
    2.015,  // g
    6.094,  // h
    6.966,  // i
    0.153,  // j
    0.747,  // k
    4.025,  // l
    2.406,  // m
    6.749,  // n
    7.507,  // o
    1.929,  // p
    0.095,  // q
    5.987,  // r
    6.327,  // s
    9.056,  // t
    2.758,  // u
    1.037,  // v
    2.365,  // w
    0.150,  // x
    1.974,  // y
    0.074   // z
   };
   int n = sizeof(frequencies) / sizeof(float);
   printf("%d \n", n);
	int row, col, k;
   // iterate over grid
   for (row = 0; row < DIMENSION; row++)
   {
       for (col = 0; col < DIMENSION; col++)
       {   
           // generate pseudorandom double in [0, 1]
           double d = rand() / (double) RAND_MAX;

           // map d onto range of frequencies
           for (k = 0; k < n; k++)
           {
               d -= frequencies[k] / 100;
               if (d < 0.0 || k == n - 1)
               {
                   grid[row][col] = 'A' + k;
                   break;
               }
           }
       }
   }
	return 0;
}