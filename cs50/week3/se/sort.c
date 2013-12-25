#include <stdio.h>
#include<math.h>
#define SIZE 8

void sort(int array[], int size)
{
	// TODO: sort array using any algorithm
	int i, j, x;
	j = 1;
	while(j != 0)
	{
		j = 0;
		for(i = 0; i < size - 1; i++)
		{
			if(array[i] > array[i+1])
			{
				x = array[i];
				array[i] = array[i+1];
				array[i+1] = x;
				j++;
			}
		}
	}
	//return array;
	/*int i, j, x, z;
	z = 0;
	
	for(i = 0; i < 20; i++)
	{
		if(pow(2, i) == size)
		{	x = i;
			printf("Power %d \n", x);
			break;
		}	
		if(pow(2, i) > size)
		{
			z = pow(2,i) - size;
			x = i;
			printf("Power %d \n", x);
			for(j = size; j < pow(2,i); j++)
				array[j] = 0;				
			break;
		}	
	}
	for(i = 0; i < size / 2; i+2)
	{
		if(array[i] > array[i+1])
		{
			x = array[i];
			array[i] = array[i+1];
			array[i+1] = x;
		}
	}
	for (i = z; i < pow(2, x); i++)
		printf("ARRAY: %d ", array[i]);*/
	
}

int 
main(void)
{
	int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108};
	int i;
	for (i = 0; i < SIZE; i++)
		printf("%d ", numbers[i]);
	printf("\n");
	sort(numbers, SIZE);
	for ( i = 0; i < SIZE; i++)
	printf("%d ", numbers[i]);
	printf("\n");
	return 0;
}
