#include <stdio.h>
#include <cs50.h>

int
main(void)
{
	int x, y, z;
	printf("Please Enter 1st no. for swap: ");
	x = GetInt();
	printf("Please Enter 2nd no. for swap: ");
	y = GetInt();
	printf("X: %d \nY: %d", x, y);
	printf("\nSWAPPING.....");
	z = x;
	x = y;
	y = z;
	printf("\nSWAPPED.....");
	printf("\nX: %d \nY: %d \n", x, y);
	return 0;
}
	
	

