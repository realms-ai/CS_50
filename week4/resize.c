/****************************************************************************
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: copy infile outfile\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if (n <= 1)
    {
        printf("Invalud Resizing \n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    bf.bfSize = n * bf.bfSize;
        
    bi.biSizeImage = n * bi.biSizeImage;
    bi.biWidth = n * bi.biWidth;
    bi.biHeight = n * bi.biHeight;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - ((bi.biWidth / n) * sizeof(RGBTRIPLE)) % 4) % 4 ;
    //printf("size %d \n", 4 - ((bi.biWidth / n) * sizeof(RGBTRIPLE)) % 4);
    printf("PADDING: %d \n", padding);
    
    int padding1 =  (4 - ((bi.biWidth) * sizeof(RGBTRIPLE)) % 4) % 4 ;
    printf("PADDING1: %d \n", padding1);
    
    int i, j, k, l;
    
    //bi.biWidth = bi.biWidth / n;
    //bi.biHeight = bi.biHeight / n;
    printf("height: %d \n", (bi.biHeight / n));
    printf("width: %d \n", (bi.biWidth / n));
    // iterate over infile's scanlines
    for (i = 0, bi.biHeight = abs(bi.biHeight); i < (bi.biHeight / n); i++)
    {
        l = 0;
        
        // iterate over pixels in scanline
        while(l < n)
        {
        	RGBTRIPLE triple;
		for (j = 0; j < (bi.biWidth / n); j++)
		{
		    // temporary storage
		    

		    // read RGB triple from infile
		    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
		    //printf("input %x%x%x \n",triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);
		    
		    // write RGB triple to outfile
		    for(k =  0; k < n; k++)  
		       	fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr); 
		 }
		
		// skip over padding, if any
		fseek(inptr, padding, SEEK_CUR);
		//printf("input padding %x%x%x \n",triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);
	
		// then add it back (to demonstrate how)
		for (k = 0; k < padding1 ; k++)
			fputc(0x00, outptr);
		
		if(l < n - 1)
		  	fseek(inptr, -((((bi.biWidth / n) * 3) + padding) ), SEEK_CUR);
		 l++;
	  }
	}
	

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
