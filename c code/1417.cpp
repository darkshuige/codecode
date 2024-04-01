#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long ksm(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
		 ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
int main()
{
	long long n,m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
		 break;
		if(n==0 || m==0)
		 cout<<0<<endl;
		else
		 cout<<ksm(2,n*m)%mod<<endl;
	}
	return 0;
} 
