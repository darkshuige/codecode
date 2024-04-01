#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
	if(n>100)
	{
		return n-10;
	}
	else
	{
		return f(f(n+11));
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		printf("f91(%d) = %d\n",n,f(n));
	}
	return 0;
}
