#include <stdio.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
	int i;	
	printf("\n");
	for(i = 0; i < argc; i++)
		printf("%s \n", argv[i]);
	printf("\n");
} 
