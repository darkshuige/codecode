#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int n; 
struct node
{
	int v,w;
}a[maxn];
int cmp(node a,node b)
{
	return a.v>b.v;
}
priority_queue<int>ma,mi;
int check(int m)
{
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i].v>=m)
		 ma.push(a[i].v+a[i].w-m);
		else
		 mi.push(a[i].w);
	}
	while(!ma.empty() && !mi.empty())
	{
		if(ma.top()>=mi.top())
		 ma.pop(),mi.pop();
		else
		{
			flag=0;
			break;
		}
	}
	while(!ma.empty()) ma.pop();
	while(!mi.empty()) mi.pop();
	return flag;
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		 cin>>a[i].v>>a[i].w;
		sort(a+1,a+1+n,cmp);
		int ans,l=0,r=a[1+n>>1].v;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}