#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
const int mod=1000000007;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
signed main()
{
	jiasu;
	int n,k;
	cin>>n>>k;
	int sum=1;
	if(k>=n-k)//2放中间 
	{
		sum=(sum*ksm(3,k-1))%mod;
		sum=(sum*ksm(4,n-k))%mod;
		int num1=(k-1)*(k-2)/2;//2 2 2
		int num2=(n-k)*(n-k-1)/2;//3 3 2
		int num3=(n-k)*(k-1);//3 2 2
		sum=(sum*ksm(4,num1))%mod;
		sum=(sum*ksm(6,num2))%mod;
		sum=(sum*ksm(6,num3))%mod;
	}
	else//3放中间 
	{
		sum=(sum*ksm(3,n-k-1))%mod;
		sum=(sum*ksm(4,k))%mod;
		int num1=(n-k-1)*(n-k-2)/2;//3 3 3
		int num2=(k)*(k-1)/2;//2 2 3
		int num3=(k)*(n-k-1);//2 3 3 
		sum=(sum*ksm(4,num1))%mod;
		sum=(sum*ksm(6,num2))%mod;
		sum=(sum*ksm(6,num3))%mod;	
	} 
	cout<<sum<<endl;
	return 0;
}
 
