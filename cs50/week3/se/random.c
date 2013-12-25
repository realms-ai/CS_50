#include <cs50.h>
#include <ctype.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


int main(void)
{
	int i = GetInt();
	if (i == 2)
	   {
	       int seed = i;
	       if (seed <= 0)
	       {
		   printf("Invalid grid.\n");
		   return 1;
	       }
	      srand(seed);
	   }
	   else
	       srand(time(NULL));
	   printf("%d \n", rand());
	return 0;
}
