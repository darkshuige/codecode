#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1e6+5;
bool S_GND;
int n,m,ans,pos,top;
int d[maxn],b[maxn],f[maxn],g[maxn],id[maxn];//d是入度，id是拓扑序，f是以i为终点最大值
vector<int>q[maxn],p[maxn];
int stk[30],tp;
void solve1()//找以i为终点的最大值
{
	queue<int>que;
	for(int i=1;i<=n;i++)
	 if(!d[i]) que.push(i);
	while(!que.empty())
	{
		int x=que.front(); que.pop();
		id[++top]=x;
		for(auto v:q[x])
		{
			d[v]--,f[v]=max(f[v],f[x]+1);
			if(!d[v]) que.push(v);
		}
	}
}
void solve2()//找以i为起点的最大值
{
	queue<int>que;
	for(int i=1;i<=n;i++) if(!b[i]) que.push(i);
	while(!que.empty())
	{
		int x=que.front(); que.pop();
		for(auto v:p[x])
		{
			b[v]--,g[v]=max(g[v],g[x]+1);
			if(!b[v]) que.push(v);
		}
	}
}
multiset<int>s;
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v; cin>>u>>v;
		q[u].push_back(v),p[v].push_back(u);//反向建图
		d[v]++,b[u]++;	
	}
	solve1(),solve2();
	for(int i=1;i<=n;i++)
	 s.insert(-g[i]);//因为要从大到小排序
	ans=-*s.begin();
	for(int t=1;t<=n;t++)
	{
		int i=id[t];
		s.erase(s.find(-g[i]));//删掉第i个数，就要先删掉以i为起点的最长
		for(auto v:p[i])
		 s.erase(s.find(-f[v]-1-g[i]));//删掉所有原图以v为终点i为起点i-v有边的最长
		auto it=s.begin(); if(-*it<ans) ans=-*it,pos=i;
		s.insert(-f[i]);//重新放回以i为终点的最长
		for(auto v:q[i])
		 s.insert(-f[i]-1-g[v]);//放回以i为终点v为起点i-v有边的最长
	}
	cout<<pos<<" "<<ans<<endl;	
	return 0;
} 	