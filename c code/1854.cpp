#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k;
	while(cin>>n>>k)//4»»1 
	{
		long long sum=0;
		if(n>=5)
		{
			n-=5;
			sum+=k*4;
		}
		else
		{
			sum+=k*n;
			n=0;
		}
		if(n)
		{
			sum+=(k*3)*(n/4);
			sum+=(n%4)*k;
		}
		cout<<sum<<endl;
	}
	return 0;
}
