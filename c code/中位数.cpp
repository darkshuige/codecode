#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int maxn=1e6;
int a[maxn+5],tr[maxn+5];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int t)
{
	for(int i=x;i<=maxn;i+=lowbit(i))
	 tr[i]+=t;
}
int sum(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))
	 ans+=tr[i];
	return ans;
}
signed main()
{
	jiasu;
	int n,m;
	memset(tr,0,sizeof tr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		add(a[i],1);
	}
	for(int i=0;i<m;i++)
	{
		int p,v;
		cin>>p>>v;
		add(a[p],-1);
		add(v,1);
		a[p]=v;
		int l=1,r=1e6;
		int ans=-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(sum(mid)<(n+1)/2)
			{
				l=mid+1;
			}
			else
			{
				ans=mid;
				r=mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
