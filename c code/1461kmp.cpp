#include<bits/stdc++.h>
using namespace std;
int fib[105]={0};
void init()
{
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<=45;i++)
	 fib[i]=fib[i-1]+fib[i-2];
}
int main()
{
	init();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int count=0;
		int k=0;
		while(n>0)
		{
			if(n-fib[k]>=0)
			{
				count++;
				n-=fib[k++];
			}
			else
			 break;
		}
		cout<<count<<endl;
	}
	return 0;
}
