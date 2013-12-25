
#include <stdio.h>
#include <cs50.h>

int
main(void)
{
	int i, j, k, l;
	printf("Please Enter a heigth of pyramid less than 24: ");
	l = GetInt();
	while((l >= 24) || (l < 1))
	{
		printf("Retry: ");
		l = GetInt();
	}
	for(i = 1; i < l+2; i++)
	{
		for(j = l+1; j > i; j--)
			printf(" ");
		for(k = 1; k <= i; k++)
			printf("*");
		printf("  ");
		for(k = 1; k <= i; k++)
			printf("*");
		printf("\n");
	}
	return 0;	    
}
