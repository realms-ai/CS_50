#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<cs50.h>
int main()
{
	string key = "cs50";
	string salt = "55";
	string result = crypt(key,salt);
	printf("the encrypted password is %s\n",result); 
}
