#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long i,j,count=0,n,max,k;
	while(scanf("%lld %lld",&i,&j)!=EOF)
	{
		max=0;
		if(i>j)
		{
			for(k=j;k<=i;k++)
			{
				count=0;
				n=k;
				while(n!=1)
				{
					if(n%2==0)
					{
						n=n/2;
						count++;
					}
					else
					{
						n=n*3+1;
						count++;
					}
				}
				if(count>max)
				 max=count;
			}
		}
		else
		{
			for(k=i;k<=j;k++)
			{
				count=0;
				n=k;
				while(n!=1)
				{
					if(n%2==0)
					{
						n=n/2;
						count++;
					}
					else
					{
						n=n*3+1;
						count++;
					}
				}
				if(count>max)
				 max=count;
			}	
		}
		cout<<i<<" "<<j<<" "<<max+1<<endl;
	}
	return 0;
}
