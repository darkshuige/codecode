#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long ksm(int a,int m)
{
	long long ans=1;
	for(int i=0;i<m;i++)
	{
		ans=ans*a;
		ans=ans%mod;
	}
	return ans;
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=ksm(i,m);
			sum%=mod;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
