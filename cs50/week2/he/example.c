#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int
main(int argc, string argv[])
{
	if(argc > 2)
	{
		printf("Error \n");
		return 1;
	}
	string a = "Hello";
	string b = "Hello ";
	string c;
	if(strcmp(b, argv[1]) == 0)
		c = a;
	printf("%s \n", c);
	return 0;
}
