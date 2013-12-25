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

typedef uint8_t  BYTE;
#define bytes 512


int main(void)
{
   // open input file 
    FILE* inptr = fopen("card.raw", "r");
    FILE* outptr;
    outptr = NULL;
    
    if (inptr == NULL)
    {
        printf("Could not open infile.\n");
        return 2;
    }   
   	int i, j = 0;
	while(1)	
	{
		BYTE ch[bytes] = {};
			if(feof(inptr))
			{
				fclose(inptr);
				if(outptr != NULL)
					fclose(outptr);
				return 0;
			}
			fread(&ch[i], sizeof(BYTE), bytes, inptr);
					
		if(ch[0] == 0xff && ch[1] == 0xd8 && ch[2] == 0xff && (ch[3] == 0xe0 ||ch[3] == 0xe1 ))
		{
			//printf("%x%x%x%x \n", ch[0], ch[1], ch[2], ch[3]);
			char ch1[10] = {};
			if(outptr != NULL)
				fclose(outptr);
			sprintf(ch1,"%03d.jpg", j);
			j++;
			if((outptr = fopen(ch1, "w")) == NULL)
			{
				printf("Couldn't write the image \n");
				return 1;
			}
			//printf("%x%x%x%x \n", ch[0], ch[1], ch[2], ch[3]);
			fwrite(&ch, (bytes * sizeof(BYTE)), 1, outptr);
			//printf("%x%x%x%x \n", ch[0], ch[1], ch[2], ch[3]);
		}
		else if (outptr != NULL) 
                    fwrite(&ch[0], bytes * sizeof (BYTE), 1, outptr);
        }
	
    // close infile
    fclose(inptr);

    // that's all folks
    return 0;
}

