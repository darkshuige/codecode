#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,sum=0,i;
	while(scanf("%d",&n)!=EOF)
	{
		sum=1;
		if(n<2)
		{
			printf("0\n");
			continue;
		}
		if(n==2)
		{
			printf("1\n");
			continue;
		}
		 
		else
		{
			for(i=3;i<=n;i++)
			{
				if(i%3==0)
				{
					sum++;
				}
			}
		}
		printf("%d\n",sum);
	}
	
	return 0;
} 
