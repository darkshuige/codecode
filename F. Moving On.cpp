#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=300;
struct HeadNode
{
    int d,u;
    bool operator < (const HeadNode& rhs) const
	{
        return d>rhs.d;
    }
}; 
struct edge
{
    int to;
    int cost;
};
vector<edge>g[maxn];
bool vis[maxn];
int n,q,x,s,t,fu;
int d[maxn];
int w[maxn];
void djst()
{
	memset(vis,0,sizeof vis);
    fill(d+1,d+n+1,M);
    d[s]=0;
    priority_queue<HeadNode>q;
    q.push((HeadNode){0,s});
    while(!q.empty())
	{
        HeadNode x=q.top();q.pop();
        int u=x.u;
        if(vis[u])
		 continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++)
		{
            edge e=g[u][i];
            if(w[e.to]>fu) continue;
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
	int cc;
	cin>>cc;
	int cnt=1;
	while(cc--)
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>w[i],g[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x; cin>>x;
				if(i==j) continue;
				g[i].push_back({j,x});
			}
		}
		cout<<"Case #"<<cnt<<":"<<endl;
		cnt++;
		while(q--)
		{
			cin>>s>>t>>fu;
			if(s==t)
			{
				cout<<0<<endl;
				continue;
			}
			int temp=w[t]; w[t]=0;
			djst();
			w[t]=temp;
			cout<<d[t]<<endl;
		}
	}
    
    return 0;
} 
