#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
map<string,int>mp;
vector<int>g[maxn];
int root=-1;
int vis[maxn];
void dfs1(int now)
{
	vis[now]=1;
	for(auto k:g[now])
	 dfs1(k);
}
void dfs2(int now)
{
	if(vis[now]==1)
	{
		root=now;
		return ;
	}
	for(auto k:g[now])
	 dfs2(k);
}
signed main()
{
	int ct=0;
	string a,b; int n;
	cin>>a>>b>>n;
	mp[a]=ct++; mp[b]=ct++;
	for(int i=0;i<n;i++)
	{
		string a,b,c; cin>>a>>b>>c;
		if(!mp.count(a))
		 mp[a]=ct++;
		if(!mp.count(c) && c!="-1")
		 mp[c]=ct++;
		if(c!="-1")
		 g[mp[a]].push_back(mp[c]);
	}
	memset(vis,0,sizeof vis);
	dfs1(mp[a]);
	dfs2(mp[b]);
	if(root==-1)
	{
		cout<<-1<<endl;
	}
	else
	{
		if(g[root].size()!=0)
		{
			for(auto k:mp)
			{
				if(k.second==root)
				{
					cout<<k.first<<endl;
					break;
				}
			}
		}
		else
		 cout<<-1<<endl;
	}
	return 0;
} 
