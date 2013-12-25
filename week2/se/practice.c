#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int 
main(int argc, char *argv[])
{
	string s = GetString();
	int a = strlen(s);
	int i;
	for(i = 0; i <= a; i++)
		printf("%c \n",s[i]);
	printf("\n");
}


