#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
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
	for(int i=x;i<=n;i+=lowbit(i))
	{
		c[i]+=t;
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
	int m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		a[op]++;
	}
	for(int i=1;i<=n;i++)
	{
		c[i]+=a[i];
		if(i+lowbit(i)<=n)
		{
			c[i+lowbit(i)]+=c[i];
		}
	}
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			update(x,1);
		}
		else if(op==2)
		{
			if(n<k)
			 cout<<-1<<endl;
			else
			{
				int l=0,r=1e9;
				int ans=-1;
				while(l<=r)
				{
					int mid=(l+r)/2;
					if(query(mid)>=k)
					{
						if(query(mid-1)<k || query(mid)==k)
						 ans=mid;
						r=mid-1;
					}
					else if(query(mid)<k)
					{
						l=mid+1;
					}
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
} 
