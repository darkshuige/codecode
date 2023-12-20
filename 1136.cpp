#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n%2==0 || n==1)
		{
			printf("2^? mod %d = 1\n",n);
		}
		else
		{
			int i,flag=0,a=2;
			for(i=1;;i++)
			{
				a*=2;
				if(a%n==1)
				{
					printf("2^%d mod %d = 1\n",i+1,n);
					break;
				} 
				a=a%n;
			}
		}
	}
	return 0;
} 
