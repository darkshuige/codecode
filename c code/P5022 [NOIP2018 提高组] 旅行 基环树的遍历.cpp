#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=5100;
vector<int>e[maxn];
pair<int,int>edge[maxn];
int du,dv,vis[maxn];
vector<int>path(maxn,maxn);//n个数，都初始化为n
int cnt,better;
int n,m;
int dfs(int u)
{
	if(better==0)
	{
		//序号变大则回退，序号变小就走完
		if(u>path[cnt]) return 1;//变大
		if(u<path[cnt]) better=-1;
	}
	vis[u]=1;
	path[cnt++]=u;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(vis[v]==1) continue;
		if(v==du && u==dv || v==dv && u==du) continue;
		if(dfs(v)) return 1;//如果序号变大就一直回
	}
	return 0;
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b; cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
		edge[i]={a,b};
	}
	for(int i=1;i<=n;i++)
	 sort(e[i].begin(),e[i].end());
	if(n==m+1) dfs(1);//不存在环，直接遍历
	else
	{
		for(int i=1;i<=m;i++)//枚举断边
		{
			du=edge[i].first;
			dv=edge[i].second;
			memset(vis,0,sizeof vis);
			cnt=better=0;
			dfs(1);
		}
	}
	for(int i=0;i<n;i++)
	 cout<<path[i]<<" ";
	cout<<endl;
	return 0;
}