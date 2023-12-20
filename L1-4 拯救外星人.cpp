#include<bits/stdc++.h>
using namespace std;
long long f(long long n)
{
	long long i;
	long long sum=1;
	for(i=1;i<=n;i++)
	{
		sum*=i;
	}
	return sum;
}
int main()
{
	long long a,b;
	cin>>a>>b;
	cout<<f(a+b)<<endl;
	return 0;	
}
