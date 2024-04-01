#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000;
struct node
{
	int w,v;
	int id;
}a[maxn];
int p[maxn],dp[maxn];
int cmp(node a,node b)
{
	if(a.w==b.w) return a.v>b.v;
	else return a.w<b.w;
}
signed main()
{
	jiasu;
	int n=0;
	int ww,vv;
	while(cin>>ww)
	{
		cin>>vv;
		dp[n]=1; p[n]=n;
		cout<<n<<endl;
		a[n++]={ww,vv,n};
	}
	sort(a,a+n,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j].w<a[i].w && a[j].v>a[i].v)
			{
				if(dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
					p[i]=j;
				}
			}
		}
	}
	int pp=0,ma=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]>ma)
		{
			ma=dp[i];
			pp=i;
		}
	}
	cout<<ma<<endl;
	stack<int>v;
	while(p[pp]!=pp)
	{
		v.push(a[pp].id);
		pp=p[pp];
	}
	cout<<a[pp].id<<endl;
	while(!v.empty())
	{
		cout<<v.top()<<endl;
		v.pop();
	}
	return 0;
}