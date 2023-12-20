#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define rep(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
const int N = 110,M=2e4+10,INF=1e8;
int n,m,r;
int d[N][N],bd[N][N],g[N][N];
int pre[N],bpre[N];
int dfn[N],low[N],timestamp,stk[N],top;
int id[N],scc_cnt;
bool st[N],ins[N];
void dfs(int u)
{
	st[u]=true;
	for(int i=1;i<=n;++i) 
		if(d[u][i]<INF&&!st[i])
			dfs(i); 
}
bool check_con()
{
	memset(st,0,sizeof st);
	dfs(r);
	rep(i,1,n) 
		if(!st[i]) 
			return false;
	return true;
}
void tarjan(int u)
{
	dfn[u]=low[u]=++timestamp;
	stk[++top]=u;ins[u]=true;
	
	int j=pre[u];
	if(!dfn[j])
	{
		tarjan(j);
		low[u]=min(low[u],low[j]);
	}
	else if(ins[j]) low[u]=min(low[u],dfn[j]);
	if(low[u]==dfn[u])
	{
		int y;
		scc_cnt ++;
		do
		{
			y=stk[top --];
			ins[y]=false;
			id[y]=scc_cnt;
		}while(y!=u);
	}
}
int zhuliu()
{
	int ans = 0; 
	while(true)
	{
		for(int i=1;i<=n;++i)
		{
			pre[i]=i;
			for(int j=1;j<=n;++j)
				if(d[pre[i]][i] > d[j][i])
					pre[i]=j;
		}
		memset(dfn,0,sizeof dfn);
		timestamp=scc_cnt=0;
		for(int i=1;i<=n;++i) 
			if(!dfn[i])
				tarjan(i);
		if(scc_cnt == n)
		{
			for(int i=1;i<=n;++i) 
			{
				if(i==r) continue;
				ans += d[pre[i]][i];
			}
			break ;
		}
		for(int i=1;i<=n;++i)
		{
			if(i==r) continue;
			if(id[pre[i]] == id[i])
			{ 
				ans += d[pre[i]][i];
			}
		}
		for(int i=1;i<=scc_cnt;++i)
			for(int j=1;j<=scc_cnt;++j)
				bd[i][j]=INF;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(d[i][j] < INF && id[i]!=id[j])
				{
					int a=id[i],b=id[j];
					if(id[pre[j]]==id[j])
						bd[a][b]=min(bd[a][b],d[i][j]-d[pre[j]][j]);
					else bd[a][b]=min(bd[a][b],d[i][j]);
				}
			}
		}
		r=id[r];
		n = scc_cnt;
		memcpy(d,bd,sizeof d);	
	}
	return ans;
}
signed main()
{
	cin>>n>>m>>r;
	rep(i,1,m) 
	{
		int u,v,w;
		cin>>u>>v>>w;
		d[u][v]=min(d[u][v],w);
	}
	if(!check_con()) puts("-1");
	else cout<<zhuliu()<<endl;
	return 0;
}
//朱刘算法
//有向图的类Prim算法，找有向图的最小生成树
//
//最小树形图
//树形图：
//
//无有向环
//除了根节点外，每个点入度为1
//以某个点为根的一棵有向树，其边权之和为图中所有树形图中是最小的称为最小树形图。
//
//朱刘算法 O ( n m ) O(nm)O(nm)
//(1) 除了根节点外对每个点选取一条边权最小的入边
//
//(2)判断当前(选出的边)组成的图中有无环
//
//? 1.若无环：则说明当前图已经为构造好的最小生成树，算法结束
//
//? 2.若有环：进行第(3)步
//
//(3)将构造的图进行强连通分量缩点，得到新图G ′ G'G 
//′
// ,对于G ′ G'G 
//′
// 中的所有边
//
//? 1.如果是环中的边：直接删去
//
//? 2.如果终点在环内(即新缩的点)：更新此边权权值为W ? W 环 内 W-W_{环内}W?W 
//环内
//?
// 
//
//? 3.其他边：不变
//
//然后继续从(1)开始迭代
