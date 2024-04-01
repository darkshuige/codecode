#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
int g[50];
int w[1<<25];
int m,n,cnt,ans;
int cmp(int a,int b)
{
	return a<b;
}
void dfs1(int p,int now)
{
	if(p==n/2)
	{
		w[cnt++]=now;
		return ;
	}
	dfs1(p+1,now);
	if(g[p]+now<=n)
	 dfs1(p+1,now+g[p]);
}
void dfs2(int p,int now)
{
	if(p==n)
	{
		ans=max(ans,*(upper_bound(w,w+cnt,n-now)-1)+now);
		return ;
	}
	dfs2(p+1,now);
	if(g[p]+now<=n)
	 dfs2(p+1,now+g[p]);
}
signed main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	 cin>>g[i];
	cnt=0;
	dfs1(0,0);
	sort(w,w+cnt,cmp);
	cnt=unique(w,w+cnt)-w;
	ans=0;
	dfs2(n/2,0);
	cout<<ans<<endl;
	return 0;
} 
