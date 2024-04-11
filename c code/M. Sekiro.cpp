#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
map<int,int>mp;
const int maxn=100005;
struct node
{
	int l,r;
}a[maxn];
int cmp(node a,node b)
{
	return a.r<b.r;
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		mp.clear();
		int n; cin>>n;
		for(int i=1;i<=n;i++)
		 cin>>a[i].l>>a[i].r;
		sort(a+1,a+1+n,cmp);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=a[i].l;j<=a[i].r;j++)
			{
				if(mp[j]==0)
				{
					mp[j]++;
					sum++;
					break;
				}
			}	
		}	
		cout<<sum<<endl;
	}
	return 0;
} 	