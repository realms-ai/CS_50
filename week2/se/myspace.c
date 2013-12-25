#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int 
main(int argc, char *argv[])
{
	int i, j, k, y, z;
	z = 1;
	//printf("%d \n", argc);
	for(i = 0; i < argc; i++)
	{		
		//printf("%d \n", argc);
		k = strlen(argv[i]);
		//printf("%d \n", k);
		//printf("%d \n", l);
		for(j = 0; j <= k; j++)	
		{
			argv[i][j] = tolower((int) argv[i][j]);
			
			if(z == 1)
			{
				if((j+1) % 2 == 0)
					argv[i][j] = toupper((int) argv[i][j]);	
			}
			else	
			{
				if(j % 2 == 0)
					argv[i][j] = toupper((int) argv[i][j]);	
			}
			printf("%c", argv[i][j]);
		}
		y = (k % 2 == 0) ? 1 : 0;
		z = ((y || z) && (!(y && z))) ? 0 : 1;
		printf("\n");
	}
	printf("\n");
}
