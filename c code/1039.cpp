#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int ss(int a)
{
	int i;
	if(a<2)
	 return 0;
	if(a==2)
	 return 1;
	for(i=2;i<=sqrt(a)+1;i++)
	{
		if(a%i==0)
		 return 0;
	}
	return 1;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	while(n!=0)
	{
		if(n%2==1)
		{
			printf("Goldbach's conjecture is wrong.\n");
		}
		else
		{
			for(i=n-1;i>=3;i=i-2)
			{
				if(ss(i) && ss(n-i))
				{
					printf("%d = %d + %d\n",n,n-i,i);
					break;
				}
			}
		}
		cin>>n;
	}
	return 0;
}
