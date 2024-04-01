#include<bits/stdc++.h>
using namespace std;
int fib[1000005];
void init()
{
	fib[1]=1;
	fib[2]=1;
	for(int i=3;i<1000005;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]%=10007;
	}
}
int main()
{
	init();
	int n;
	while(cin>>n)
	{
		cout<<fib[n]<<endl;
	}
	return 0;
}
