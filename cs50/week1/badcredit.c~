#include <stdio.h>
#include <cs50.h>

int main(void)
{
	string cards[4] = {"AMEX", "MASTER_CARD", "VISA", "INVALID"};	
	long long  a, z;
	printf("Please Enter a Credit Card No.: ");
	a = GetLongLong();
	//a =   378282246310005;
	z = a;	
	int b, i, sum, sum1;
	int c[16] = {}, d[16] = {};
	sum = 0;
	sum1 =0;
	b = 0;
	for(i = 1; i <= 16; i++)
	{		
		if((a / (10) == 0 ) && (a % (10) == 0 ))
			break;	
		c[i-1] = a % 10;
		a = a/ 10;		
		b = b + 1;
		//printf("%d ", c[i-1]);
		
	}
	printf("\n%d \n", b);
	if((b == 13) || (b == 15) || (b == 16))
		{
		for(i = b - 1; i >= 0; i--)
		{
			d[b-1-i] = c[i];
			//printf("%d ",d[b-1-i]);
		}
		int x;
		//printf("15 digit %d \n",c[15]);	
		for(i = 0; i < b; i++)
		{
			if(((i+1) % 2 == 0) && ((i+1) <= b))	
			{
				x = c[i] * 2;
				//printf("X %d \v", x);
				//printf("NO. %d \n", c[i]);
				//printf("%d ",x);			
				if(x >= 10)
				{
					//printf("\n %d \n", x);
					sum = sum + (x / 10);
					sum = sum + (x % 10);
					//printf("SUM %d \n", sum);
				}
				else
					sum = sum + x;
			}
			else
				sum = sum + c[i];
		}
	}	
	//printf("\n %d %d \n", sum, sum1);
	printf("%lld \n", z);
	if(((sum % 10) == 0) && (sum !=0))
	{
		//printf("Great \n");		
		if((d[0] * 10 + d[1] == 34) || (d[0] * 10 + d[1] == 37) && (b == 15))
			printf("%s \n", cards[0]);
		if((d[0] * 10 + d[1] == 51) || (d[0] * 10 + d[1] == 52) || (d[0] * 10 + d[1] == 53) || (d[0] * 10 + d[1] == 54) || (d[0] * 10 + d[1] ==55) && (b == 16))
			printf(" %s \n", cards[1]); 
		if((d[0] == 4) && ((b == 13) || (b == 16)))
			printf("%s \n", cards[2]); 
	}	
	else
		printf("Invalid \n");
	return 0;			
	
}
