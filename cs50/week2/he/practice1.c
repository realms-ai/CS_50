#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>

	int main ()
	{
		printf ("Our first number: %d\n", rand() % 100);
		srand ( time(NULL) );

		printf ("Some random number: %d\n", rand() % 100);
		srand ( 1 );

		printf ("The first number again: %d\n", rand() %100);

		return 0;
	}
