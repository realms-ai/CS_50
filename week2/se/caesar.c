#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int 
main(int argc, char *argv[])
{
	if(argc == 1 || argc > 2)
	{
		printf("Sorry Wrong Secret Key \n");
		return 1;
	}
	int i, j , k, secret_key, z;
	string s;
	printf("Please Enter a phrase: ");
	s = GetString();
	secret_key = atoi(argv[1]);
	if(secret_key <= 0)
	{
		printf("ERROR: ");
		return 1;
	}	
	if(secret_key > 26)
		secret_key = secret_key % 26;	
	for(i = 0; i < strlen(s); i++)
	{		
		if(s[i] >= 65 && s[i] <= 90)
		{
			s[i] = (int)s[i] + secret_key ;
			if(s[i] > 90)
			s[i] = (s[i] - 91) + 65;
		}
		if(s[i] >= 97 && s[i] <= 122)
		{
			z = (int)s[i] + secret_key ;
			if(z > 122)
				z = (z - 123) + 97;
			s[i] = z;
		}
		printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}
