#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200;
const int mod=1000000007;
int ksm(int a,int k)
{
	int res=1;
	while(k)
	{
		if(k & 1) res*=a;
		a*=a;
		k>>=1;
	}
	return res;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int l=0,r=50;
	int flag=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		int now=ksm(4,mid);
		if(now==n)
		 flag=1;
		if(now>n)
		 r=mid-1;
		else
		 l=mid+1;
	}
	if(flag) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}