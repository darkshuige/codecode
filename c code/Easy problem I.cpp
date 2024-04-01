#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
int a[maxn];
int c[maxn];
int n;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int t)
{
	int change=abs(a[x]-t)-a[x];
	a[x]=abs(a[x]-t);
	t=change;
	for(int i=x;i<=n;i+=lowbit(i))
	{
		c[i]+=change;
	}
}
int query(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		ans+=c[i];
	}
	return ans;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int m;
		cin>>n>>m;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			c[j]+=a[j];
			if(j+lowbit(j)<=n)
			{
				c[j+lowbit(j)]+=c[j];
			}
		}
		for(int j=0;j<m;j++)
		{
			int op;
			cin>>op;
			if(op==1)
			{
				int l,r,x;
				cin>>l>>r>>x;
				for(int k=l;k<=r;k++)
				{
					update(k,x);
				}
			}
			else if(op==2)
			{
				int l,r;
				cin>>l>>r;
				cout<<query(r)-query(l-1)<<endl;
			}
		}
	}
	return 0;
} 
