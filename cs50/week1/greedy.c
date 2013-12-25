
#include <stdio.h>
#include <cs50.h>



int
main(void)
{
	string array1[4] = {"penny", "nickel", "dime", "quarter"};	
	int array[4] = {1, 5, 10, 25};
	int i, k;
    	/*for( i = 0; i < 14; i++)
    	{
        	printf("%d \n", array[i]);
	}*/
	float amount_paid, total_amount, amount_owed;
	printf("Please enter the amount paid: ");				
	amount_paid = GetFloat();
	//printf("%.2f \n", amount_paid);
	printf("Please enter the Total amount: ");				
	total_amount = GetFloat();
	//printf("%.2f \n", total_amount);
	amount_owed = amount_paid - total_amount;
	printf("Amount Owed: %.2f \n", amount_owed);
	if(amount_owed > 0)
	{
		k = (amount_owed * 1000);
		if((k % 10) >= 5)
			k = (amount_owed * 100) + 1;
		else
			k = amount_owed * 100;
		//printf("%d, \n", k);
		int n;	
		for(i = 3; i >= 0; i--)
		{
			n = k / array[i];		
			k = k % array[i];
			if(n > 1)
				printf("%d coins of %s(%d¢) \n", n, array1[i], array[i]);
			if (n == 1)
				printf("%d coin of %s(%d¢) \n", n, array1[i], array[i]);
			if(k == 0)
				break;
		}
	}
	else if(amount_owed == 0)
		printf("No penny to give \n");
	else
		printf("You owe to customer!!! \n");
	return 0;
	    
}
