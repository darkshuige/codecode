#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long act(int n)
{
	if(n==0)
	 return 0;
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	long long cs[10]={0};
	int a[5005]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	 	cs[a[i]]++;	
	}
	for(int i=1;i<=9;i++)
	 cs[i]=act(cs[i]);
	long long sum=1;
	for(int i=1;i<=9;i++)
	 if(cs[i]!=0)
	 {
	 	sum*=cs[i];
		sum%=mod;
	 }
	long long ans=0;
	sort(a,a+n);
	do
	{
		long long res=0;
		for(int i=0;i<n;i++)
		 res=res*10+a[i];
		ans=res*sum;
		ans%=mod;
	}
	while(next_permutation(a,a+n));
	printf("%lld\n",ans%mod);
	return 0;
} 
