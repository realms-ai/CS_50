/****************************************************************************
* recover.c
*
* Computer Science 50
* Problem Set 4
*
* Recovers JPEGs from a forensic image.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// create a type of unsigned integers of length of 8 bits (1 byte)
typedef uint8_t BYTE;

// define blocksize to avoid magic number
#define BLOCKSIZE 512

int main (void)
{
    // open memory card
	FILE* fp = fopen("IMG0096A.jpg", "r");

	// if fp is NULL (non-existent file), return 1
    if (fp == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    
    
    // forever loop that will end when the file has been read
    while (1)
    {
        // create an array called block that's the size of BLOCKSIZE
        BYTE block[BLOCKSIZE] = {};
        int i;
        // iterate over each byte in each block until you reach the end of the file
        for ( i = 0; i < BLOCKSIZE; i++)
        {
            // if you reach the end of file, close the file
            if (feof(fp))
            {
                printf("Great \n");
                fclose(fp);
                
                // close previously opened output file pointer if necessary
               
                return 0;
            }
            
            // read one byte at a time
            fread(&block[i], sizeof (BYTE), 1, fp);
            
        }
        printf("%x%x%x%x \n", block[0], block[1], block[2], block[3]);
        // if block's first 4 bytes match those of a jpg (start of new jpg)      
        
    }
 
    // close file
    fclose(fp);
 
    // return 0 to exit program 
    return 0;
}
