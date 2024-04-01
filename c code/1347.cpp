#include<bits/stdc++.h>
using namespace std;
int fib[100];
int fib3[100];
void init()
{
	fib[0]=1;
	fib[1]=1;
	int i;
	for(i=2;i<100;i++)
	 fib[i]=fib[i-1]+fib[i-2];
	fib3[0]=1;
	fib3[1]=1;
	for(i=2;i<100;i++)
	{
		fib3[i]=fib[i-2]+fib[i-1];
	}
}
int main()
{
	init();
	int i,j,g;	
	while(cin>>i>>g>>j)
	{
		if(g<=0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		int fib2[25];
		fib2[0]=1;
		if(i==1)
		{
			fib2[1]=g;
			for(int i=2;i<=j;i++)
			{
				fib2[i]=fib2[i-1]+fib2[i-2];
			}
			cout<<fib2[j]<<endl;
		}
		else
		{
			if(g<fib3[i])
			{
				cout<<"-1"<<endl;
			}
			else
			{
				int x=g-fib[i-2];
				if(x%fib[i-1]!=0)
				{
					cout<<"-1"<<endl;
				}
				else
				{
					int t=x/fib[i-1];
					fib2[1]=t;
					for(int i=2;i<=j;i++)
					{
						fib2[i]=fib2[i-1]+fib2[i-2];
					}
					cout<<fib2[j]<<endl;
				}
			}
		}
	}
	return 0;
} 

