#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(fasle),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
int a[maxn],n,ans,cnt;
vector<int>g[maxn];
int gcd(int aa,int b)
{
	if(aa<b) swap(aa,b);
	int t=aa%b;
	while(t)
	{
		aa=b;
		b=t;
		t=aa%b;
	}
	return b;
}
int check(int kk,int op)
{
	for(int i=0;i<g[kk].size();i++)
	{
		if(gcd(g[kk][i],op)!=1)
		 return 0;
	}
	return 1;
}
void dfs(int p)
{
	if(p>=n)
	{
		ans=min(ans,cnt);
		return ;
	} 
	if(cnt>ans) return ;
	for(int i=0;i<cnt;i++)
	{
		if(check(i,a[p]))
		{
			g[i].push_back(a[p]);
			dfs(p+1);
			g[i].pop_back();
		}
	}
	g[cnt++].push_back(a[p]);
	dfs(p+1);
	g[--cnt].pop_back();
}
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	ans=INT_MAX;
	cnt=0;
	dfs(0);
	cout<<ans<<endl;
	return 0;
} 
