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
#include <math.h>
#include "bmp.h"


int main(void)
{
    char ch;
    int j;
    // open input file 
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open infile.\n");
        return 2;
    }
	int i;
	for(i = 0; i < 1400; i++)
	{
		RGBTRIPLE triple;
		fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
		//printf("input %x%x%x \n",triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);
			
	}
	
	for(i = 0; i < 500; i++)
	{
		RGBTRIPLE triple;
		fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
		printf("input %x%x%x \n",triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);
	}
    
    // close infile
    fclose(inptr);

    // that's all folks
    return 0;
}
