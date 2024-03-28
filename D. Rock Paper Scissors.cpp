#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=20;
set<int>st;
int a[maxn],b[maxn];
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		cin>>a[1]>>a[2]>>a[3];
		cin>>b[1]>>b[2]>>b[3];
		int ans=0;
		if(a[1])
		{
			int k=min(a[1],b[2]);
			ans+=k;
			a[1]-=k,b[2]-=k;
		}
		if(a[2])
		{
			int k=min(a[2],b[3]);
			ans+=k;
			a[2]-=k,b[3]-=k;
		}
		if(a[3])
		{
			int k=min(a[3],b[1]);
			ans+=k;
			a[3]-=k,b[1]-=k;
		}
		
		if(a[1])
		{
			int k=min(a[1],b[1]);
			a[1]-=k,b[1]-=k;
		}
		if(a[2])
		{
			int k=min(a[2],b[2]);
			a[2]-=k,b[2]-=k;
		}
		if(a[3])
		{
			int k=min(a[3],b[3]);
			a[3]-=k,b[3]-=k;
		}
		
		if(a[1])
		{
			int k=min(a[1],b[3]);
			a[1]-=k,b[3]-=k;
			ans-=k;
		}
		if(a[2])
		{
			int k=min(a[2],b[1]);
			a[2]-=k,b[1]-=k;
			ans-=k;
		}
		if(a[3])
		{
			int k=min(a[3],b[2]);
			a[3]-=k,b[2]-=k;
			ans-=k;
		}
		cout<<ans<<endl;
	}
	return 0;
}