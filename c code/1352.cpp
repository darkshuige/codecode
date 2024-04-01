#include<bits/stdc++.h>
using namespace std;
int fib[2000];
void init()
{
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<30;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
}
int main()
{
	init();
	int t;
	int i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int l,r;
		cin>>l>>r;
		int count=0;
		for(int j=0;j<30;j++)
		{
			
			if(fib[j]>=l && fib[j]<=r)
			{
				if(count!=0) cout<<" ";
				cout<<fib[j];
				count++;	
			} 
		}
		cout<<endl;
	}
	return 0;
}
