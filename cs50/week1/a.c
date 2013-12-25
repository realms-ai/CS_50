#include <stdio.h>
#include <cs50.h>

int 
main(void)
{
	float a, e; 
	int b, c, d;
	a = 10.54;
	printf("%f \n", a);
	d = (a * 100) + 1;
	printf("d: %d \n", d);
	b = d / 200;
	c = d % 200;
	printf("b: %d \n", b);
	printf("c: %d \n", c);
	e = b;
	e = e / 3;
	printf("%.2f \n", e);
}
