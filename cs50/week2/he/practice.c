#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int
main(int argc, char *argv[])
{
	if(argc > 2)
	{
		printf("Error %s[#] \n",argv[0]);
		return 1;
	}
	FILE *fp;
	string str1;
	char str[50];
	argv[1] = strcat(argv[1], "\n");
	/* opening file for reading */
	fp = fopen("/usr/share/dict/words" , "r");
	int x = strlen(argv[1]);
	printf("%d %s \n",x, argv[1]);
	if(fp == NULL)
	{
		perror("Error opening file");
		return(-1);
	}

	int i , j, k;
	bool l = true;
	
	for(i = 0; i < 15; i++)
	{
		if(fgets(str, 50, fp) != NULL)
		{
			//printf("%d %s \n",x, argv[1]);		
			k = strlen(str);		
			printf("%d %s", k, str);
			//for( j = 0; j < k - 1; j++)
				//str1[j] = str[j];		
			//printf("Great %c \n",str[k-1]);
				
			if(strcmp(argv[1],str) == 0)
			{
				printf("YES \n");
				l = false;
				break;
			}			
		}
		
	}
	
	if( l == true)
		printf("No");	
	printf("\n");
	fclose(fp);
	return(0);
}
