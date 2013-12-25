#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int 
upper(int a, int b);

int
lower(int a, int b);



int 
main(int argc, char *argv[])
{
	if(argc == 1 || argc > 2)
	{
		printf("No code to decipher \n");
		return 1;
	}
	int a, i, j , k, z, l, l1;


//GETTING A CODE
	printf("Please Enter a code: ");
	string code, secret_key;
	code = GetString();
	secret_key = argv[1];
	l = strlen(secret_key);
	//printf("%d \n", l);
	l1 = 0;
	for(i = 0; i < strlen(code); i++)
	{		
		if(code[i] >= 65 && code[i] <= 90)
		{
			if(l1 >= l)
			l1 = l1 % l;
			code[i] = upper((int)code[i], (int)secret_key[l1]);
			l1++;
		}
		if(code[i] >= 97 && code[i] <= 122)
		{
			if(l1 >= l)
			l1 = l1 % l;
			code[i] = lower((int)code[i], (int)secret_key[l1]);
			l1++;
		}
		printf("%c", code[i]);
		
	}
	printf("\n");
	return 0;
}

int 
upper(int a, int b)
{
	if(b > 64 && b < 91)
		b = b - 65;
	if(b > 96 && b < 123)
		b = b - 97;
		
	int c ;
	c = a + b;
	if(c > 90)
		c = c - 26;
	return c;
}

int 
lower(int a, int b)
{
	if(b > 64 && b < 91)
		b = b - 65;
	if(b > 96 && b < 123)
		b = b - 97;
		
	int c ;
	c = a + b ;
	if(c > 122)
		c = c - 26;
	return c;
}
