#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
struct HeadNode//头结点 
{
    int d,u;//d表示距离，u表示哪个点 
    bool operator < (const HeadNode& rhs) const//小的在前呗 
	{
        return d>rhs.d;
    }
}; 
struct edge//边 
{
    int to;
    int cost;
};
vector<edge>g[10005];//表示一个点所有的邻接边 
bool vis[10005];
int n,m,x,s,t;
int d[10005];
void djst()
{
    fill(d+1,d+n+1,M);
    d[s]=0;//s为0 
    priority_queue<HeadNode>q;
    q.push((HeadNode){0,s});//一开始距离为0，点为s 
    while(!q.empty())
	{
        HeadNode x=q.top();q.pop();
        int u=x.u;
        if(vis[u])
		 continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++)
		{
            edge e=g[u][i];//邻接边 
            if(d[e.to]>d[u]+e.cost)
			{
                d[e.to]=d[u]+e.cost;
                q.push((HeadNode){d[e.to],e.to});
            }
        }
    }
}
signed main()
{
	jiasu;
    cin>>n>>m>>s>>t;//n表示点的个数，m为边的个数，s是起始点，t为终点 
    for(int i=1;i<=m;i++)
	{
        edge e;
        cin>>x>>e.to>>e.cost;//x是起始边 
        g[x].push_back(e);
    }
    djst();
    if(d[t]==M)
	 cout<<-1<<endl;
    else
	 cout<<d[t]<<endl;
    return 0;
} 
