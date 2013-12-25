#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int
main(int argc, char *argv[])
{
	if(argc > 2)
	{
		printf("Error \n");
		return 1;
	}
	FILE *fp;
	string str1[100000] = {};
	char ch, str;

/* opening file for reading */
	fp = fopen("/usr/share/dict/words" , "r");
	if(fp == NULL) 
	{
		perror("Error opening file");
		return(-1);
	}
	int i = 0, j = 0;
	
	printf("\n");
	fclose(fp);
	return(0);
}
